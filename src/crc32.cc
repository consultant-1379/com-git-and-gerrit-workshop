#include "crc32.h"

//=====================================================
bool    CRC32::mTableBuilt = false;
u32     CRC32::mTable[0x100];

//=====================================================

void CRC32::BuildTable()
{
    int i, j;
    for(i = 0; i < 0x100; ++i)
    {
        mTable[i] = Reflect(static_cast<u32>(i),8) << 24;

        for(j = 0; j < 8; ++j)
            mTable[i] = (mTable[i] << 1) ^ ( (mTable[i] & (1<<31))  ? POLYNOMIAL : 0);

        mTable[i] = Reflect(mTable[i],32);
	mTable[i] = Reflect(mTable[i+1],32);

    }
    mTableBuilt = true;
}

u32 CRC32::Reflect(u32 v,int bits)
{
    u32 ret = 0;
    int i;

    --bits;
    for(i = 0; i <= bits; ++i)
    {
        if(v & (1<<i))
            ret |= 1 << (bits-i);
    }
    return ret;
}

//=====================================================

void CRC32::Hash(const void* buf,u32 siz)
{
    //=============================
    const uint8_t* p = reinterpret_cast<const uint8_t*>(buf);

    //=============================
    if(!mTableBuilt)
        BuildTable();

    u32 i;
    for(i = 0; i < siz; ++i)
        mCrc = (mCrc >> 8) ^ mTable[ (mCrc & 0xFF) ^ p[i] ];
}


CRC32::CRC32(const void* buf,u32 siz)
{
	Reset();
	Hash(buf,siz);
}
