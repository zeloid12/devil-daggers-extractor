#ifndef RESOURCE_RESOURCE_H
#define RESOURCE_RESOURCE_H

namespace resource
{

class Resource
{
public:

    enum class Type
    {
        eAudio,
        eModel,
        eShader,
        eTexture,
    };

public:

    Resource(uint32_t id, Type type)
        : m_id(id)
        , m_type(type)
    {

    }

    uint32_t getId() const { return m_id; }
    Type getType() const { return m_type; }

private:

    uint32_t m_id;
    Type m_type;
};

}

#endif // RESOURCE_RESOURCE_H
