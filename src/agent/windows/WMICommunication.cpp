#include "WMICommunication.h"

#define _WIN32_DCOM
#include <iostream>
#include <comdef.h>


WMICommunication::WMICommunication() : m_smartData(new SmartData())
{
}

WMICommunication::~WMICommunication()
{
    m_initialLocatorToWMI->Release();
    m_services->Release();
    m_pEnumerator->Release();
    CoUninitialize();
}

bool WMICommunication::WMIInit()
{
    try {
        HRESULT hres = CoInitializeEx(0, COINIT_MULTITHREADED);

        if (FAILED(hres))
        {
            throw std::exception("Failed to initialize COM library. Error code = 0x");
        }

        hres = CoInitializeSecurity(
            NULL,
            -1,                          // COM authentication
            NULL,                        // Authentication services
            NULL,                        // Reserved
            RPC_C_AUTHN_LEVEL_PKT,       // Default authentication 
            RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
            NULL,                        // Authentication info
            EOAC_NONE,                   // Additional capabilities 
            NULL                         // Reserved
        );

        if (FAILED(hres))
        {
            throw std::exception("Failed to initialize security. Error code = 0x");
        }

        hres = CoCreateInstance(
            CLSID_WbemLocator,
            0,
            CLSCTX_INPROC_SERVER,
            IID_IWbemLocator, (LPVOID*)&m_initialLocatorToWMI);

        if (FAILED(hres))
        {
            throw std::exception("Failed to create IWbemLocator object. Err code = 0x");
        }

        hres = m_initialLocatorToWMI->ConnectServer(
            _bstr_t(L"ROOT\\WMI"),   // Object path of WMI namespace
            NULL,                    // User name. NULL = current user
            NULL,                    // User password. NULL = current
            0,                       // Locale. NULL indicates current
            NULL,                    // Security flags.
            0,                       // Authority (for example, Kerberos)
            0,                       // Context object 
            &m_services                // pointer to IWbemServices proxy
        );

        if (FAILED(hres))
        {
            throw std::exception("Could not connect. Error code = 0x");
        }

        hres = CoSetProxyBlanket(
            m_services,                    // Indicates the proxy to set
            RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
            RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
            NULL,                        // Server principal name 
            RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
            RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
            NULL,                        // client identity
            EOAC_NONE                    // proxy capabilities 
        );

        if (FAILED(hres))
        {
            throw std::exception("Could not set proxy blanket. Error code = 0x");
        }

        return true;
    }
    catch (const std::exception& e)
    {
        CoUninitialize();
        if (m_initialLocatorToWMI != NULL)
        {
            m_initialLocatorToWMI->Release();
        }

        if (m_services != NULL)
        {
            m_services->Release();
        }

        return false;
    }
}

bool WMICommunication::CollectSMARTDataViaWMI()
{
    try {
        HRESULT hres = m_services->ExecQuery(
            bstr_t("WQL"),
            bstr_t("SELECT * FROM MSStorageDriver_FailurePredictData"),
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            NULL,
            &m_pEnumerator);

        if (FAILED(hres))
        {
            throw std::exception("Query for operating system name failed. Error code = 0x");
        }

        IWbemClassObject* pclsObj = NULL;
        ULONG uReturn = 0;

        while (m_pEnumerator)
        {
            HRESULT hr = m_pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;
            hr = pclsObj->Get(L"VendorSpecific", 0, &vtProp, 0, 0);

            if (V_ISARRAY(&vtProp))
            {
                LPSAFEARRAY pSafeArray = V_ARRAY(&vtProp);

                VARTYPE itemType;
                if (SUCCEEDED(SafeArrayGetVartype(pSafeArray, &itemType)))
                {
                    if (itemType == VT_UI1)
                    {
                        if (SafeArrayGetDim(pSafeArray) == 1)
                        {
                            LONG lBound;
                            LONG uBound;

                            if (SUCCEEDED(SafeArrayGetLBound(pSafeArray, 1, &lBound)) && SUCCEEDED(SafeArrayGetUBound(pSafeArray, 1, &uBound)))
                            {
                                const LONG itemCount = uBound - lBound + 1;

                                std::vector<BYTE> dataFromArray(itemCount);

                                BYTE* safearrayData;
                                hr = SafeArrayAccessData(pSafeArray, reinterpret_cast<LPVOID*>(&safearrayData));
                                if (FAILED(hr))
                                {
                                    dataFromArray.clear();
                                }

                                memcpy(dataFromArray.data(), safearrayData, itemCount);

                                hr = SafeArrayUnaccessData(pSafeArray);
                                if (FAILED(hr))
                                {
                                    dataFromArray.clear();
                                }

                                if (dataFromArray.empty() != true)
                                {
                                    FeedSmartDataStructure(dataFromArray, itemCount);
                                }
                            }
                        }
                    }
                }
            }

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        return true;
    }
    catch (const std::exception& e)
    {
        if (m_services != NULL)
        {
            m_services->Release();
        }

        if (m_initialLocatorToWMI != NULL)
        {
            m_initialLocatorToWMI->Release();
        }

        CoUninitialize();

        return false;
    }
}

std::shared_ptr<SmartData> WMICommunication::GetSMARTData()
{
    return m_smartData;
}

void WMICommunication::FeedSmartDataStructure(const std::vector<BYTE>& data, const LONG& dataSize)
{

    for (int i = 0; data.size() > i; i += 12)
    {
        if (data.size() >= (i + 12))
        {
            SmartData::AttrData attrData;
            attrData.status = data.at(i + 3);
            attrData.value = data.at(i + 5);
            attrData.worst = data.at(i + 6);
            attrData.rawVal = data.at(i + 7);
            attrData.rawVal2 = data.at(i + 8);
            m_smartData->smartData.insert(std::pair<unsigned char, SmartData::AttrData>(data.at(i + 2), attrData));
        }
        
    }
    
}

