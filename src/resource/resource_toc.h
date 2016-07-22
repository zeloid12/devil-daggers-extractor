#ifndef RESOURCE_TOC_H
#define RESOURCE_TOC_H

namespace resource
{

struct File
{
    File* m_next;
    char* m_name;
    uint32_t m_id;
    uint32_t m_offset;
    uint32_t m_size;
    uint16_t m_type;
};

struct Toc
{
    Toc* m_next;
    char* m_name;
    File* m_file;
};

}

#endif // RESOURCE_TOC_H
