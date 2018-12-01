#include <gtest/gtest.h>

#include "dmos.h"
#include "dmutil.h"
#include "dmtypes.h"
#include "dmformat.h"
#include "dmtime.h"
#include <algorithm>

#define NOMINMAX

TEST(dmformat, dmformat) {
    char szBuf[5] = "1111";
    szBuf[sizeof(szBuf) - 1] = '1';
    strncpy(szBuf, "1", std::min( strlen("1")+1, sizeof(szBuf)));
    szBuf[sizeof(szBuf) - 1] = '\0';

    std::cout << fmt::format("{0},{1},{2}", "a", "b", "c") << std::endl;
    std::cout << fmt::format("{2},{1},{0}", "a", "b", "c") << std::endl;
    std::cout << fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(time(NULL))) << std::endl;

    std::cout << fmt::format("{}{}{}{}{}{}{}{}{}{}{}{}",
        1, 2, 3, 4, 5, 6, 'a', 'b', 'c', 'd', 'e', 'f') << std::endl;

    std::cout << fmt::format("{_1}/{a_}/{A_}", fmt::arg("a_", 'a'),
        fmt::arg("A_", "A"), fmt::arg("_1", 1)) << std::endl;

    char name[] = "fmt";
    std::string strName = "{}";
    strName = fmt::format(strName, name);
}

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

template<typename T>
T LuaPop()
{
    return LuaRead<T>::Read();
}

TEST(main, main) {

    int i = LuaPop<int64_t>();
    int j = LuaPop<uint64_t>();
}