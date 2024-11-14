#include <gtest/gtest.h>
#include "ut_cake.h"
#include "ut_chocolate_cake.h"
#include "ut_geode_cake.h"
#include "ut_honey_cake.h"
#include "ut_cake_showcase.h"

// int ChocolateCake::_count = 0;
// int GeodeCake::_count = 0;
// int HoneyCake::_count = 0;
// int Cake::_total_cake_count = 0;

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
