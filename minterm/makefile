.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp 
	g++ -std=c++11 test/ut_sample.h src/Product.h src/ShoppingCart.h test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

ut: test/ut_main.cpp
	g++ -std=c++11 test/ut_sample.h src/Product.h src/ShoppingCart.h test/ut_main.cpp -o bin/ut_all_gcovr -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0

directories:
	mkdir -p bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

stat:
	wc src/* test/*