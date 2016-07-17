#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>

namespace resource
{

class Manager
{
public:

    Manager();
    ~Manager();

    bool init(const std::string&);

private:


};

} // namespace resource

#endif // RESOURCE_MANAGER_H