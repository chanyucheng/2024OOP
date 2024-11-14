#include <gtest/gtest.h> 
#include "HelloWorld.h"

TEST(HELLOWORLD, PrintHelloWorld) { //屬於哪個大包的testcase的一部分, 測試的目標
    string compare = "Hello World! \n";//心中的正確輸出 
    string output = PrintHelloWorld(); //呼叫function() 需要把function的所在地用標頭檔(.h檔)include
    ASSERT_EQ(compare, output); //google test 提供的方法來檢驗
}

int main(int argc, char **argv)
{ //不用再改了 debug流程
    testing ::InitGoogleTest(&argc, argv); //找出所有的testcase
    return RUN_ALL_TESTS(); //會run所有的testcase
}

//for commit 