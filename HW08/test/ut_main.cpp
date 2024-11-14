#include <gtest/gtest.h>
#include "ut_beef_sandwich.h"
#include "ut_sandwich.h"
#include "ut_sweet_sandwich.h"
#include "ut_sandwich_factory.h"


// std::set<int> Sandwich::_container;
// std::set<int> BeefSandwich::_container;
// std::set<int> SweetSandwich::_container;


int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
