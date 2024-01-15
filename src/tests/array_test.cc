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

TEST(array_metods_test, metod_end) {
  // s21::array<int, 3> s21_arr = {1, 2, 3};
  std::array<int, 3> std_arr = {1, 2, 3};
  // std_arr.end
  // void *p_end = s21_arr.end();

  for (auto i = std_arr.begin(); i != std_arr.end(); i++) {
    std::cout << "0" << std::endl;
  }
}

// operators

TEST(array_operators_test, operator_square_brackets) {
  s21::array<int, 3> s21_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr[0], 1);
  s21_arr[0] = 5;
  ASSERT_EQ(s21_arr[0], 5);
  int *p_int = &s21_arr[0];
  ASSERT_EQ(*p_int, 5);
  std::array<int, 3> std_arr = {1, 2, 3};
  std_arr.begin();
}

TEST(array_operators_test, operator_square_brackets_const) {
  const s21::array<int, 3> s21_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr[0], 1);
}
