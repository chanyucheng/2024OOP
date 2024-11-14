# This is the default target, which will be built when you invoke make
.PHONY: all #忽略這些檔案 直接找下面的target

#Redefine the target all with the requirement of hello & ut_all
all: hello ut #優先找檔名 不然就往下找target

# This rule tells make how to build HelloWorld from HelloWorld.cpp
hello: HelloWorld.cpp	#目標: 目標條件 
	g++ HelloWorld.cpp -o HelloWorld

#This rule tells make how to build ut_all from ut_main.cpp
ut: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread

# This rule tells make to delete hello and hello.o 
.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all

#make 預設all 也可以make hello, make all, make clean
