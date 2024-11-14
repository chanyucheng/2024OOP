source = $(shell find ./src/ -type f \( -iname "*.cpp" \)) #扣掉ut_main.cpp不需要
cflags = -lgtest -lpthread -std=c++11 -Wfatal-errors

.PHONY: directories clean stat

all: directories bin/ut_all #gitut

bin/ut_all: test/ut_main.cpp 
	g++ $(source) test/ut_main.cpp -o bin/ut_all $(cflags)

ut: test/ut_main.cpp
	g++ $(source) test/ut_main.cpp -o bin/ut_all_gcovr $(cflags) --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0
directories:
	mkdir -p bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

stat:
	wc src/* test/*


# bin/ut_all: test/ut_main.cpp 
# 	g++ -std=c++11 test/ut_tequila.h test/ut_sour.h test/ut_alcohol.h src/alcohol.h src/sour.h src/tequila.h src/algorithm.h src/order.h test/ut_order.h test/ut_algorithm.h test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

# ut: test/ut_main.cpp
# 	g++ -std=c++11 test/ut_tequila.h test/ut_sour.h test/ut_alcohol.h src/alcohol.h src/sour.h src/tequila.h src/algorithm.h src/order.h test/ut_order.h test/ut_algorithm.h test/ut_main.cpp -o bin/ut_all_gcovr -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0