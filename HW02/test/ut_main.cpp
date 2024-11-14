#include <gtest/gtest.h>
#include "ut_cookie.h"

int main(int argc, char *argv[])
{
    testing ::InitGoogleTest(&argc, argv); //找出所有的testcase
    return RUN_ALL_TESTS(); //會run所有的testcase
}
