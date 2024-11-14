#include "../src/cookie.h"

TEST(COOKIE, MaxDVEven1) { 
    int n = 4;
    int arr[] = {1, 2, 3, 4};
    ASSERT_EQ(max_dv(n, arr), 6);
}
TEST(COOKIE, MaxDVEven2) {
    int n = 4;
    int arr[] = {6, 7, 1, 5};
    ASSERT_EQ(max_dv(n, arr), 12);
}
TEST(COOKIE, MaxDVOdd1) {
    int n = 5;
    int arr[] = {1, 3, 3, 4, 5};
    ASSERT_EQ(max_dv(n, arr), 9);
}
TEST(COOKIE, MaxDVOdd2) {
    int n = 5;
    int arr[] = {2, 7, 4, 3, 10};
    ASSERT_EQ(max_dv(n, arr), 16);
}
TEST(COOKIE, DVNegative1) {
    int n = 4;
    int arr[] = {2, -7, 4, 3};
    ASSERT_EQ(max_dv(n, arr), -1);
}
TEST(COOKIE, DVNegative2) {
    int n = 5;
    int arr[] = {2, 7, -4, 3, 10};
    ASSERT_EQ(max_dv(n, arr), -1);
}
TEST(COOKIE, CookieAmountNegative1) {
    int n = -4;
    int arr[] = {2, 7, -4, 3};
    ASSERT_EQ(max_dv(n, arr), -1);
}
TEST(COOKIE, CookieAmountNegative2) {
    int n = -5;
    int arr[] = {2, 7, 3, 7, 10};
    ASSERT_EQ(max_dv(n, arr), -1);
}