#include <windows.h>
#include <iostream>

struct RamInfo {
    DWORD dwMemoryLoad;
    ULONGLONG ullTotalPhys;
    ULONGLONG ullAvailPhys;
};

bool get_ram_info(RamInfo& info) {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);

    if (GlobalMemoryStatusEx(&statex)) {
        info.dwMemoryLoad = statex.dwMemoryLoad;
        info.ullTotalPhys = statex.ullTotalPhys;
        info.ullAvailPhys = statex.ullAvailPhys;
        return true;
    } else {
        std::cerr << "Error: Failed to get memory status." << std::endl;
        return false;
    }
}