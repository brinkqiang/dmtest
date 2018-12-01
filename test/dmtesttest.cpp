#include <gtest/gtest.h>

#include "dmos.h"
#include "dmutil.h"
#include "dmtypes.h"
#include "dmformat.h"
#include "dmtime.h"

template<typename T>
struct LuaRead
{
    static T Read()
    {
        return T();
    }
};

template<>
struct LuaRead<uint64_t>
{
    static uint64_t Read()
    {
        return 1;
    }
};

template<>
struct LuaRead<int64_t>
{
    static int64_t Read()
    {
        return 2;
    }
};

TEST(dmformat, dmformat) {

    int i = LuaRead<uint64_t>::Read();
    int j = LuaRead<uint64_t>::Read();

}
