#include <gtest/gtest.h>

#include <array>

#include "../s21_array.h"

// constructors

TEST(array_constructor_test, constructor_default) {
  s21::array<int, 1> *example_arr = nullptr;
  example_arr = new s21::array<int, 1>;
  EXPECT_NE(example_arr, nullptr);
  delete example_arr;
}

TEST(array_constructor_test, constructor_with_param) {
  s21::array<int, 2> s21_arr({1, 2});
  ASSERT_EQ(s21_arr.front(), 1);
  ASSERT_EQ(s21_arr.back(), 2);
}

// metods

TEST(array_metods_test, metod_front) {
  s21::array<int, 3> s21_arr = {1, 2, 3};
  std::array<int, 3> std_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr.front(), std_arr.front());
}
