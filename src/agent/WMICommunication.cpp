#include "WMICommunication.h"

#define _WIN32_DCOM
#include <iostream>
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")

WMICommunication::WMICommunication()
{
}

bool WMICommunication::WMIInit()
{
    HRESULT hres = CoInitializeEx(0, COINIT_MULTITHREADED);

    if (FAILED(hres))
    {
        throw std::exception("Failed to initialize COM library. Error code = 0x");
        return false;
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
        CoUninitialize();
        throw std::exception("Failed to initialize security. Error code = 0x");
        return false;
    }



    hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID*)&initialLocatorToWMI);

    if (FAILED(hres))
    {
        CoUninitialize();
        throw std::exception("Failed to create IWbemLocator object. Err code = 0x");

        return false;
    }

    //IWbemServices* srv;


    hres = initialLocatorToWMI->ConnectServer(
        _bstr_t(L"ROOT\\WMI"),   // Object path of WMI namespace
        NULL,                    // User name. NULL = current user
        NULL,                    // User password. NULL = current
        0,                       // Locale. NULL indicates current
        NULL,                    // Security flags.
        0,                       // Authority (for example, Kerberos)
        0,                       // Context object 
        &services                // pointer to IWbemServices proxy
    );

    if (FAILED(hres))
    {
        initialLocatorToWMI->Release();
        CoUninitialize();
        throw std::exception("Could not connect. Error code = 0x");
        return false;
    }


    hres = CoSetProxyBlanket(
        services,                        // Indicates the proxy to set
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

        services->Release();
        initialLocatorToWMI->Release();
        CoUninitialize();
        throw std::exception("Could not set proxy blanket. Error code = 0x");
        return false;
    }

	return true;
}
