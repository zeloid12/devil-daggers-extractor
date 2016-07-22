#ifndef RESOURCE_TEXTURE_H
#define RESOURCE_TEXTURE_H

#include "resource_resource.h"

namespace resource
{

class Texture : public Resource
{
public:

    Texture(uint32_t id) : Resource(id, Type::eTexture) {}

private:
};

}

#endif // RESOURCE_TEXTURE_H
