#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <filesystem>

namespace resource
{
    class Resource;
    struct Toc;
}

namespace resource
{

class Manager
{
public:

    Manager();
    ~Manager();

    bool init(const std::string& path);

    Toc* getToc() const { return m_toc; }

    template <typename t_type>
    t_type* getResource(uint32_t id)
    {
        return new t_type(id);
    }

private:

    bool loadHxResource(const std::tr2::sys::path& path);

private:

    Toc* m_toc;
    //std::vector<Resource*> m_resources;
};

} // namespace resource

#endif // RESOURCE_MANAGER_H