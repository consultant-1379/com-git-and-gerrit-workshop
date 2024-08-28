#include <stdint.h>
typedef uint32_t u32;

class CRC32
{
public:
    //=========================================
    CRC32()                               { Reset();                  }
    CRC32(const void* buf,u32 siz);


    //=========================================
    // implicit cast, so that you can do something like foo = CRC(dat,siz);
    inline operator u32 () const                    { return Get();             }

    //=========================================
    // getting the crc
    inline u32          Get() const                 { return ~mCrc;             }

    //=========================================
    void        Reset()                             { mCrc = ~0;                }
    void        Hash(const void* buf,u32 siz);

private:
    u32         mCrc;
    static bool mTableBuilt;
    static u32  mTable[0x100];

    static const u32        POLYNOMIAL = 0x04C11DB7;

private:
    //=========================================
    // internal support
    static void         BuildTable();
    static u32          Reflect(u32 v,int bits);
};
