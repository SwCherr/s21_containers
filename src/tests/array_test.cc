#include <gtest/gtest.h>

#include <array>
#include <string>
#include <vector>

#include "../s21_array.h"

using std::cout;

// constructors

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
TEST(array_metods_test, metod_back) {
  s21::array<int, 5> s21_arr = {1, 2, 3, 4, 5};
  s21::array<std::string, 2> s21_arr_string = {"hello", "world"};
  ASSERT_EQ(s21_arr.back(), 5);
  ASSERT_EQ(s21_arr_string.back(), "world");
}

TEST(array_metods_test, metod_front) {
  s21::array<int, 3> s21_arr = {1, 2, 3};
  std::array<int, 3> std_arr = {1, 2, 3};
  ASSERT_EQ(s21_arr.front(), std_arr.front());
  s21::array<std::string, 2> s21_arr_string = {"hello", "world"};
  ASSERT_EQ(s21_arr_string.front(), "hello");
}

TEST(array_metods_test, metod_end) {
  s21::array<int, 3> arr = {1, 2, 3};
  auto iter_arr_end = arr.end();
  ASSERT_EQ(*(iter_arr_end - 1), 3);
}

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

// iterators

TEST(array_iterator_test, iterator_begin) {
  std::array<int, 1> std_arr({123});
  s21::array<int, 1> s21_arr({123});
  auto std_iter = std_arr.begin();
  auto s21_iter = s21_arr.begin();
  ASSERT_EQ(*std_iter, *s21_iter);
}

TEST(array_iterator_test, iterator_incrementation) {
  std::array<int, 3> std_arr({123, 22, 55});
  s21::array<int, 3> s21_arr({123, 22, 55});
  auto std_iter = std_arr.begin();
  auto s21_iter = s21_arr.begin();
  std_iter++;
  s21_iter++;
  ASSERT_EQ(*std_iter, *s21_iter);
  ++std_iter;
  ++s21_iter;
  ASSERT_EQ(*std_iter, *s21_iter);
}

TEST(array_iterator_test, iterator_equal_not_equal) {
  /* std::array<int, 3> std_first_arr({123, 22, 55});
  std::array<int, 3> std_second_arr({123, 22, 55});
  auto std_iter1 = std_first_arr.begin();
  auto std_iter2 = std_second_arr.begin();
  auto std_iter3 = std_first_arr.begin();

  ASSERT_TRUE(std_iter1 != std_iter2);
  ASSERT_TRUE(*std_iter1 == *std_iter2);
  ASSERT_TRUE(std_iter1 == std_iter3);
  ASSERT_TRUE(*std_iter1 == *std_iter3);

  ASSERT_FALSE(std_iter1 == std_iter2);
  ASSERT_FALSE(*std_iter1 != *std_iter2);
  ASSERT_FALSE(std_iter1 != std_iter3);
  ASSERT_FALSE(*std_iter1 != *std_iter3); */

  s21::array<int, 3> s21_first_arr({123, 22, 55});
  s21::array<int, 3> s21_second_arr({123, 22, 55});
  auto s21_iter1 = s21_first_arr.begin();
  auto s21_iter2 = s21_second_arr.begin();
  auto s21_iter3 = s21_first_arr.begin();

  ASSERT_TRUE(s21_iter1 != s21_iter2);
  ASSERT_TRUE(*s21_iter1 == *s21_iter2);
  ASSERT_TRUE(s21_iter1 == s21_iter3);
  ASSERT_TRUE(*s21_iter1 == *s21_iter3);

  ASSERT_FALSE(s21_iter1 == s21_iter2);
  ASSERT_FALSE(*s21_iter1 != *s21_iter2);
  ASSERT_FALSE(s21_iter1 != s21_iter3);
  ASSERT_FALSE(*s21_iter1 != *s21_iter3);
}

TEST(array_iterator_test, iterator_plus_minus) {
  s21::array<int, 5> s21_arr({1, 2, 3, 4, 5});
  std::array<int, 5> std_arr({1, 2, 3, 4, 5});

  auto s21_first_iter = s21_arr.begin();
  auto std_first_iter = std_arr.begin();

  auto s21_second_iter = s21_first_iter + 3;
  auto std_second_iter = std_first_iter + 3;
  ASSERT_EQ(*s21_second_iter, *std_second_iter);

  auto s21_third_iter = s21_second_iter - 2;
  auto std_third_iter = std_second_iter - 2;
  ASSERT_EQ(*s21_third_iter, *std_third_iter);
}

TEST(array_iterator_test, iterator_plus_minus_iterator) {
  s21::array<int, 5> s21_arr({1, 2, 3, 4, 5});
  auto s21_begin = s21_arr.begin();
  auto s21_end = s21_arr.end();
  ASSERT_EQ(s21_begin - s21_end, -5);
  ASSERT_EQ(s21_arr.end() - s21_arr.begin(), 5);
}

TEST(array_iterator_test, iterator_end) {
  std::array<int, 2> std_arr({123, 22});
  s21::array<int, 2> s21_arr({123, 22});
  std::array<int, 2>::iterator std_iter = std_arr.end();
  s21::array<int, 2>::iterator s21_iter = s21_arr.end();
  ASSERT_EQ(*(s21_iter - 1), 22);
  ASSERT_EQ(*(std_iter - 1), 22);
}
