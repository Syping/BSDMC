#include "sys.h"

#include "distroutils.h"

#include <sys/utsname.h>
#include <fstream>

#ifdef Q_OS_FREEBSD
#include <sys/sysctl.h>
#include <sys/types.h>
#include <QSysInfo>
#endif

Sys::KernelInfo Sys::getKernelInfo()
{
    Sys::KernelInfo out;
    struct utsname buf;
    uname(&buf);
    out.kernelName = buf.sysname;
    out.kernelVersion = buf.release;
    return out;
}

uint64_t Sys::getSystemRam()
{
#ifdef Q_OS_FREEBSD
    uint64_t physmem;
    size_t len;
    sysctlbyname("hw.physmem", &physmem, &len, NULL, 0);
    return physmem;
#elif defined Q_OS_LINUX
    std::string token;
    std::ifstream file("/proc/meminfo");
    while(file >> token)
    {
        if(token == "MemTotal:")
        {
            uint64_t mem;
            if(file >> mem)
            {
                return mem * 1024ull;
            }
            else
            {
                return 0;
            }
        }
        // ignore rest of the line
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0; // nothing found
#else
    return 0; // unsupported system
#endif
}

bool Sys::isCPU64bit()
{
    return isSystem64bit();
}

bool Sys::isSystem64bit()
{
    // kernel build arch on linux
    return QSysInfo::currentCpuArchitecture() == "x86_64";
}

Sys::DistributionInfo Sys::getDistributionInfo()
{
#if defined Q_OS_FREEBSD
    DistributionInfo result;
    result.distributionName = "FreeBSD";
    result.distributionVersion = QSysInfo::kernelVersion();
    return result;
#elif defined Q_OS_LINUX
    DistributionInfo systemd_info = read_os_release();
    DistributionInfo lsb_info = read_lsb_release();
    DistributionInfo legacy_info = read_legacy_release();
    DistributionInfo result = systemd_info + lsb_info + legacy_info;
    if(result.distributionName.isNull())
    {
        result.distributionName = "unknown";
    }
    if(result.distributionVersion.isNull())
    {
        if(result.distributionName == "arch")
        {
            result.distributionVersion = "rolling";
        }
        else
        {
            result.distributionVersion = "unknown";
        }
    }
    return result;
#else
    return DistributionInfo();
#endif
}
