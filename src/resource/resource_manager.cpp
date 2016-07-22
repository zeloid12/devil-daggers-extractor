#include "resource_manager.h"

#include <windows.h>
#include <string>
#include <fstream>
#include "resource_toc.h"

namespace resource
{

Manager::Manager()
: m_toc(nullptr)
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
}

Manager::~Manager()
{

}

bool Manager::init(const std::string& path)
{
    // Check for dd resource file
    std::tr2::sys::path dd = path;
    dd /= "res/dd";
    if (!std::tr2::sys::exists(dd))
    {
        return false;
    }

    {
        std::tr2::sys::path file = path;
        file /= "res/dd";
        loadHxResource(file);
    }

    {
        std::tr2::sys::path file = path;
        file /= "res/audio";
        loadHxResource(file);
    }

    {
        std::tr2::sys::path file = path;
        file /= "core/core";
        loadHxResource(file);
    }

    return true;
}

struct Header
{
    uint32_t m_magicNumber1;
    uint32_t m_magicNumber2;
    uint32_t m_tocSize;
};

#define MAKE_MAGIC(a,b,c,d) (a | b << 8 | c << 16 | d << 24)
#define MAGIC_1     MAKE_MAGIC(0x3AULL,0x68ULL,0x78ULL,0x3AULL)
#define MAGIC_2     MAKE_MAGIC(0x72ULL,0x67ULL,0x3AULL,0x01ULL)

#define CHUNK_TOC_END       0x00
#define CHUNK_MODEL         0x01
#define CHUNK_TEXTURE       0x02
#define CHUNK_SHADER        0x10
#define CHUNK_AUDIO         0x20
#define CHUNK_MODEL_BINDS   0x80 // I'm really (not) good at naming things

bool Manager::loadHxResource(const std::tr2::sys::path& path)
{
    if (!std::tr2::sys::exists(path))
    {
        return false;
    }

    std::ifstream file;
    file.open(path, std::ios_base::binary);

    if (file.is_open())
    {
        struct Header
        {
            uint32_t m_magicNumber1;
            uint32_t m_magicNumber2;
            uint32_t m_tocSize;
        };

        Header header;

        file.read((char*)&header, sizeof(Header));

        if (header.m_magicNumber1 != MAGIC_1 && header.m_magicNumber2 != MAGIC_2)
        {
            return false;
        }

        std::unique_ptr<char[]> tocBuffer(new char[header.m_tocSize]);
        file.read(tocBuffer.get(), header.m_tocSize);

        if ((uint16_t*)tocBuffer[header.m_tocSize - 2] != CHUNK_TOC_END)
        {
            return false;
        }

        size_t length = 0;
        {
            // One quick scan so we can allocate a block of memory big enough for the toc
            char* pos = tocBuffer.get();
            uint32_t count = 0;
            while (*(uint16_t*)pos != CHUNK_TOC_END && (pos - tocBuffer.get() < header.m_tocSize))
            {
                size_t len = strlen((char*)pos + sizeof(uint16_t));
                length += len + 1;
                pos = pos + 14 + len + 1;
                count++;
            }
        }

        char* strings = new char[length];
        memset(strings, 0, length);

        Toc* toc = new Toc();
        const std::string& basename = path.filename().string();
        toc->m_name = new char[basename.size() + 1];
        memcpy(toc->m_name, basename.c_str(), basename.size());
        toc->m_name[basename.size()] = 0;
        toc->m_next = m_toc;
        toc->m_file = nullptr;
        m_toc = toc;

        // Read toc and create chunks
        char* pos = tocBuffer.get();
        size_t strOffset = 0;
        while (*(uint16_t*)pos != CHUNK_TOC_END)
        {
            File* newFile = new File();
            newFile->m_next = toc->m_file;
            toc->m_file = newFile;

            newFile->m_type = *(uint16_t*)pos;
            
            const char* name = (char*)pos + sizeof(uint16_t);
            size_t len = strlen(name);
            memmove(strings + strOffset, (char*)pos + sizeof(uint16_t), len);
            newFile->m_name = strings + strOffset;
            len++;
            strOffset += len;

            newFile->m_offset = *(uint32_t*)(name + len);
            newFile->m_size = *((uint32_t*)(name + len) + 1);
            newFile->m_id = *((uint32_t*)(name + len) + 2);

            pos += 14 + len;
        }
    }

    return true;
}

} // namespace resource
