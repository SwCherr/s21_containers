#include <gtest/gtest.h>

#include <array>
#include <vector>

#include "../s21_array.h"

// constructors

TEST(experement, max_size) {
  std::array<int, 10> std_arr;
  std::cout << std_arr.max_size();
}

TEST(array_constructor_test, constructor_default_01) {
  s21::array<int, 1>* example_arr = nullptr;
  example_arr = new s21::array<int, 1>;
  EXPECT_NE(example_arr, nullptr);
  delete example_arr;
}

TEST(array_constructor_test, constructor_default_02) {
  s21::array<std::array<int, 10>, 1> s21_array_of_vector;
  ASSERT_EQ(s21_array_of_vector[0].size(), 10);
}

TEST(array_constructor_test, constructor_default_with_amount) {
  s21::array<double, 3> s21_arr;
  ASSERT_EQ(s21_arr.size(), 3);
  std::array<double, 3> std_arr;
  ASSERT_EQ(std_arr.size(), 3);
}

TEST(array_constructor_test, constructor_with_param) {
  s21::array<int, 2> s21_arr({1, 2});
  ASSERT_EQ(s21_arr.front(), 1);
  ASSERT_EQ(s21_arr.back(), 2);
}

TEST(array_constructor_test, constructor_with_param_vector) {
  s21::array<std::vector<int>, 1> s21_array_of_vector;
  s21_array_of_vector[0].push_back(1);
}

TEST(array_constructor_test, constructor_with_invalid_param) {
  bool err = false;
  try {
    s21::array<int, 2> s21_arr({1, 2, 3});
  } catch (const std::exception& e) {
    err = true;
  }
  ASSERT_TRUE(err);
}

TEST(array_constructor_test, constructor_copy) {
  s21::array<int, 2> s21_arr_first({1, 2});
  s21::array<int, 2> s21_arr_second = s21_arr_first;
  std::array<int, 2> std_arr_first({1, 2});
  std::array<int, 2> std_arr_second = std_arr_first;
  ASSERT_EQ(std_arr_second[1], 2);
}

TEST(array_constructor_test, constructor_move) {
  s21::array<int, 3> a = {1, 2, 3};
  s21::array<int, 3> b(std::move(a));
}

// metods

TEST(array_metods_test, metod_front) {
  s21::array<int, 3> s21_arr = {1, 2, 3};
  std::array<int, 3> std_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr.front(), std_arr.front());
}

// TEST(array_metods_test, metod_end) {
//   s21::array<int, 3> arr = {1, 2, 3};
//   int* p_begin = arr.begin();
//   int* p_end = arr.end();
//   std::cout << p_end - p_begin << '\n';
// }

// operators

TEST(array_operators_test, operator_square_brackets) {
  s21::array<int, 3> s21_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr[0], 1);
  s21_arr[0] = 5;
  ASSERT_EQ(s21_arr[0], 5);
  int* p_int = &s21_arr[0];
  ASSERT_EQ(*p_int, 5);
  std::array<int, 3> std_arr = {1, 2, 3};
  std_arr.begin();
}

TEST(array_operators_test, operator_square_brackets_const) {
  const s21::array<int, 3> s21_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr[0], 1);
}
