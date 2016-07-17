#include "resource_manager.h"

#include <windows.h>
#include <string>

namespace resource
{

Manager::Manager()
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
}

Manager::~Manager()
{

}

bool Manager::init(const std::string& path)
{
    return true;
}

} // namespace resource