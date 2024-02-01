#include <gtest/gtest.h>

#include <vector>

#include "../s21_vector/s21_vector.h"

template <typename T>
bool VectorEqual(s21::vector<T> &s21_Vector, std::vector<T> &Vector) {
  bool result = true;
  size_t size = s21_Vector.size();
  if (size != Vector.size() || s21_Vector.capacity() != Vector.capacity()) {
    result = false;
  } else {
    for (size_t i = 0; i < size; i++) {
      if (s21_Vector[i] != Vector[i]) {
        result = false;
        break;
      }
    }
  }
  return result;
}

TEST(vector, default_constructor) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, size_n_constructor_01) {
  s21::vector<int> s21_Vector(23);
  std::vector<int> Vector(23);
  ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, size_n_constructor_02) {
  s21::vector<int> s21_Vector(10, 123);
  std::vector<int> Vector(10, 123);
  ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

// // TODO repair constructor
// TEST(vector, size_n_constructor_03) {
//   s21::vector<std::string> s21_Vector{"privet", "mir"};
//   std::vector<std::string> Vector{"privet", "mir"};
//   ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
// }

TEST(vector, init_list_constructor_0) {
  s21::vector<int> s21_Vector = {1, 2, 3};
  std::vector<int> Vector = {1, 2, 3};
  ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, init_list_constructor_1) {
  s21::vector<int> s21_Vector = {};
  std::vector<int> Vector = {};
  ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, init_list_constructor_2) {
  s21::vector<int> s21_Vector = {-1};
  std::vector<int> Vector = {-1};
  ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, copy_constructor_0) {
  s21::vector<int> s21_Vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> s21_Vector_2(s21_Vector_1);
  std::vector<int> Vector_1 = {1, 2, 3, 4, 5};
  std::vector<int> Vector_2(Vector_1);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, copy_constructor_1) {
  s21::vector<int> s21_Vector_1 = {-4};
  s21::vector<int> s21_Vector_2(s21_Vector_1);
  std::vector<int> Vector_1 = {-4};
  std::vector<int> Vector_2(Vector_1);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, copy_constructor_2) {
  s21::vector<int> s21_Vector_1 = {};
  s21::vector<int> s21_Vector_2(s21_Vector_1);
  std::vector<int> Vector_1 = {};
  std::vector<int> Vector_2(Vector_1);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, move_constructor_0) {
  s21::vector<int> s21_Vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> s21_Vector_2(std::move(s21_Vector_1));
  std::vector<int> Vector_1 = {1, 2, 3, 4, 5};
  std::vector<int> Vector_2(std::move(Vector_1));
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, move_constructor_1) {
  s21::vector<int> s21_Vector_1 = {-4};
  s21::vector<int> s21_Vector_2(std::move(s21_Vector_1));
  std::vector<int> Vector_1 = {-4};
  std::vector<int> Vector_2(std::move(Vector_1));
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, move_constructor_2) {
  s21::vector<int> s21_Vector_1 = {};
  s21::vector<int> s21_Vector_2(std::move(s21_Vector_1));
  std::vector<int> Vector_1 = {};
  std::vector<int> Vector_2(std::move(Vector_1));
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, operator_copy_0) {
  s21::vector<int> s21_Vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> s21_Vector_2 = s21_Vector_1;
  std::vector<int> Vector_1 = {1, 2, 3, 4, 5};
  std::vector<int> Vector_2 = Vector_1;
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, operator_copy_1) {
  s21::vector<int> s21_Vector_1;
  s21::vector<int> s21_Vector_2 = s21_Vector_1;
  std::vector<int> Vector_1;
  std::vector<int> Vector_2 = Vector_1;
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, operator_move_0) {
  s21::vector<int> s21_Vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> s21_Vector_2 = std::move(s21_Vector_1);
  std::vector<int> Vector_1 = {1, 2, 3, 4, 5};
  std::vector<int> Vector_2 = std::move(Vector_1);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, operator_move_1) {
  s21::vector<int> s21_Vector_1;
  s21::vector<int> s21_Vector_2 = std::move(s21_Vector_1);
  std::vector<int> Vector_1;
  std::vector<int> Vector_2 = std::move(Vector_1);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, at_0) {
  s21::vector<int> s21_Vector = {3, 5, 7, 9};
  std::vector<int> Vector = {3, 5, 7, 9};
  ASSERT_EQ(s21_Vector.at(0), Vector.at(0));
  ASSERT_EQ(s21_Vector.at(3), Vector.at(3));
}

TEST(vector, at_1) {
  s21::vector<int> s21_Vector = {3, 5, 7, 9};
  std::vector<int> Vector = {3, 5, 7, 9};
  EXPECT_THROW(s21_Vector.at(-4), std::out_of_range);
  EXPECT_THROW(s21_Vector.at(-1), std::out_of_range);
  EXPECT_THROW(s21_Vector.at(4), std::out_of_range);
  EXPECT_THROW(s21_Vector.at(6), std::out_of_range);
  EXPECT_THROW(Vector.at(-4), std::out_of_range);
  EXPECT_THROW(Vector.at(-1), std::out_of_range);
  EXPECT_THROW(Vector.at(4), std::out_of_range);
  EXPECT_THROW(Vector.at(6), std::out_of_range);
}

TEST(vector, operator_bracket_0) {
  s21::vector<int> s21_Vector = {3, 5, 7, 9};
  std::vector<int> Vector = {3, 5, 7, 9};
  ASSERT_EQ(s21_Vector[0], Vector[0]);
  ASSERT_EQ(s21_Vector[3], Vector[3]);
}

TEST(vector, operator_bracket_1) {
  s21::vector<int> s21_Vector = {3, 5, 7, 9};
  std::vector<int> Vector = {3, 5, 7, 9};
  EXPECT_NO_THROW(s21_Vector[-4]);
  EXPECT_NO_THROW(s21_Vector[-1]);
  EXPECT_NO_THROW(s21_Vector[4]);
  EXPECT_NO_THROW(s21_Vector[6]);
  EXPECT_NO_THROW(Vector[-4]);
  EXPECT_NO_THROW(Vector[-1]);
  EXPECT_NO_THROW(Vector[4]);
  EXPECT_NO_THROW(Vector[6]);
}

TEST(vector, front_0) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5, 6};
  std::vector<int> Vector = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(s21_Vector.front(), Vector.front());
}

TEST(vector, front_1) {
  s21::vector<int> s21_Vector;
  EXPECT_THROW(s21_Vector.front(), std::out_of_range);
}

TEST(vector, back_0) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5, 6};
  std::vector<int> Vector = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(s21_Vector.back(), Vector.back());
}

TEST(vector, back_1) {
  s21::vector<int> s21_Vector;
  EXPECT_THROW(s21_Vector.back(), std::out_of_range);
}

TEST(vector, data_0) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5, 6};
  std::vector<int> Vector = {1, 2, 3, 4, 5, 6};
  int *s21_data = s21_Vector.data();
  int *data = Vector.data();
  for (size_t i = 0; i < s21_Vector.size(); i++) {
    ASSERT_EQ(s21_data[i], data[i]);
  }
}

TEST(vector, data_1) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  ASSERT_EQ(s21_Vector.data(), Vector.data());
}

TEST(vector, begin) {
  s21::vector<int> s21_Vector = {3, 5, 7, 9};
  std::vector<int> Vector = {3, 5, 7, 9};
  auto s21_iter = s21_Vector.begin();
  auto iter = Vector.begin();
  ASSERT_EQ(*s21_iter, *iter);
}

TEST(vector, end) {
  s21::vector<int> s21_Vector = {3, 5, 7, 9};
  std::vector<int> Vector = {3, 5, 7, 9};
  auto s21_iter = s21_Vector.end();
  auto iter = Vector.end();
  ASSERT_EQ(*(--s21_iter), *(--iter));
}

TEST(vector, empty_0) {
  s21::vector<int> s21_Vector = {1};
  std::vector<int> Vector = {1};
  ASSERT_EQ(s21_Vector.empty(), Vector.empty());
}

TEST(vector, empty_1) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  ASSERT_EQ(s21_Vector.empty(), Vector.empty());
}

TEST(vector, max_size_0) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  ASSERT_EQ(s21_Vector.max_size(), Vector.max_size());
}

TEST(vector, max_size_1) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5, 6};
  std::vector<int> Vector = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(s21_Vector.max_size(), Vector.max_size());
}

TEST(vector, reserve_0) {
  s21::vector<int> s21_Vector{1, 2, 3};
  std::vector<int> Vector{1, 2, 3};
  s21_Vector.reserve(25);
  Vector.reserve(25);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, reserve_1) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  s21_Vector.reserve(25);
  Vector.reserve(25);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, reserve_2) {
  s21::vector<int> s21_Vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> Vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_Vector.reserve(5);
  Vector.reserve(5);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, shrink_to_fit_0) {
  s21::vector<int> s21_Vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> Vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_Vector.push_back(10);
  Vector.push_back(10);
  s21_Vector.shrink_to_fit();
  Vector.shrink_to_fit();
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, shrink_to_fit_1) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  s21_Vector.push_back(1);
  Vector.push_back(1);
  s21_Vector.shrink_to_fit();
  Vector.shrink_to_fit();
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, clear_0) {
  s21::vector<int> s21_Vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> Vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_Vector.clear();
  Vector.clear();
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, clear_1) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  s21_Vector.clear();
  Vector.clear();
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, insert_0) {
  s21::vector<int> s21_Vector = {7, 5, 4, 3, 2, 1};
  std::vector<int> Vector = {7, 5, 4, 3, 2, 1};
  auto s21_iter = s21_Vector.insert(++(s21_Vector.begin()), 6);
  auto iter = Vector.insert(++(Vector.begin()), 6);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
  ASSERT_EQ(*s21_iter, *iter);
  s21_iter = s21_Vector.insert(s21_Vector.end(), 0);
  iter = Vector.insert(Vector.end(), 0);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
  ASSERT_EQ(*s21_iter, *iter);
}

TEST(vector, insert_1) {
  s21::vector<int> s21_Vector = {6, 5, 4, 3, 2, 1};
  auto iter_begin = s21_Vector.begin();
  auto iter_end = s21_Vector.end();
  EXPECT_THROW(s21_Vector.insert(--iter_begin, 0), std::out_of_range);
  EXPECT_THROW(s21_Vector.insert(iter_begin - 2, 0), std::out_of_range);
  EXPECT_THROW(s21_Vector.insert(++iter_end, 0), std::out_of_range);
  EXPECT_THROW(s21_Vector.insert(iter_end + 5, 0), std::out_of_range);
}

TEST(vector, insert_3) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  auto s21_iter = s21_Vector.insert(s21_Vector.begin(), 1);
  auto iter = Vector.insert(Vector.begin(), 1);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
  ASSERT_EQ(*s21_iter, *iter);
  s21_iter = s21_Vector.insert(++s21_Vector.begin(), 2);
  iter = Vector.insert(++Vector.begin(), 2);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
  ASSERT_EQ(*s21_iter, *iter);
}

TEST(vector, erase_0) {
  s21::vector<int> s21_Vector = {6, 5, 4, 3, 2, 1};
  std::vector<int> Vector = {6, 5, 4, 3, 2, 1};
  s21_Vector.erase(++(s21_Vector.begin()));
  Vector.erase(++(Vector.begin()));
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
  s21_Vector.erase(--(s21_Vector.end()));
  Vector.erase(--(Vector.end()));
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, erase_1) {
  s21::vector<int> s21_Vector = {6, 5, 4, 3, 2, 1};
  auto iter_begin = s21_Vector.begin();
  auto iter_end = s21_Vector.end();
  EXPECT_THROW(s21_Vector.erase(--iter_begin), std::out_of_range);
  EXPECT_THROW(s21_Vector.erase(iter_begin - 4), std::out_of_range);
  EXPECT_THROW(s21_Vector.erase(iter_end), std::out_of_range);
  EXPECT_THROW(s21_Vector.erase(iter_end + 4), std::out_of_range);
}

TEST(vector, erase_2) {
  s21::vector<int> s21_Vector;
  EXPECT_THROW(s21_Vector.erase(s21_Vector.begin()), std::out_of_range);
  EXPECT_THROW(s21_Vector.erase(s21_Vector.end()), std::out_of_range);
}

TEST(vector, push_back_0) {
  s21::vector<int> s21_Vector{6, 5, 4, 3, 2};
  std::vector<int> Vector{6, 5, 4, 3, 2};
  s21_Vector.push_back(1);
  Vector.push_back(1);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
  s21_Vector.push_back(0);
  Vector.push_back(0);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, push_back_1) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  s21_Vector.push_back(1);
  Vector.push_back(1);
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, push_back_2) {
  s21::vector<int> s21_Vector;
  std::vector<int> Vector;
  for (int i = 0; i < 105; i++) {
    s21_Vector.push_back(i);
    Vector.push_back(i);
    ASSERT_EQ(s21_Vector.capacity(), Vector.capacity());
  }
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, pop_back_0) {
  s21::vector<int> s21_Vector{6, 5, 4, 3, 2};
  std::vector<int> Vector{6, 5, 4, 3, 2};
  s21_Vector.pop_back();
  Vector.pop_back();
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, pop_back_1) {
  s21::vector<int> s21_Vector{6, 5, 4, 3, 2};
  std::vector<int> Vector{6, 5, 4, 3, 2};
  for (size_t i = 0; i < s21_Vector.size(); i++) {
    s21_Vector.pop_back();
    Vector.pop_back();
  }
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, pop_back_2) {
  s21::vector<int> s21_Vector{6, 5, 4, 3, 2};
  std::vector<int> Vector{6, 5, 4, 3, 2};
  for (size_t i = 0; i < s21_Vector.size() + 5; i++) {
    s21_Vector.pop_back();
    Vector.pop_back();
  }
  ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
}

TEST(vector, swap_0) {
  s21::vector<int> s21_Vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> s21_Vector_2{3, 2, 1};
  std::vector<int> Vector_1 = {1, 2, 3, 4, 5};
  std::vector<int> Vector_2{3, 2, 1};
  s21_Vector_1.swap(s21_Vector_2);
  Vector_1.swap(Vector_2);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, swap_1) {
  s21::vector<int> s21_Vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> s21_Vector_2;
  std::vector<int> Vector_1 = {1, 2, 3, 4, 5};
  std::vector<int> Vector_2;
  s21_Vector_1.swap(s21_Vector_2);
  Vector_1.swap(Vector_2);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, swap_2) {
  s21::vector<int> s21_Vector_1;
  s21::vector<int> s21_Vector_2{3, 2, 1};
  std::vector<int> Vector_1;
  std::vector<int> Vector_2{3, 2, 1};
  s21_Vector_1.swap(s21_Vector_2);
  Vector_1.swap(Vector_2);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, swap_3) {
  s21::vector<int> s21_Vector_1;
  s21::vector<int> s21_Vector_2;
  std::vector<int> Vector_1;
  std::vector<int> Vector_2;
  s21_Vector_1.swap(s21_Vector_2);
  Vector_1.swap(Vector_2);
  ASSERT_EQ(VectorEqual(s21_Vector_1, Vector_1), true);
  ASSERT_EQ(VectorEqual(s21_Vector_2, Vector_2), true);
}

TEST(vector, iterator_0) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  std::vector<int> Vector = {1, 2, 3, 4, 5};
  auto s21_iter = s21_Vector.begin();
  auto iter = Vector.begin();
  ASSERT_EQ(*s21_iter, *iter);
  ASSERT_EQ(*(++s21_iter), *(++iter));
  ASSERT_EQ(*(s21_iter + 2), *(iter + 2));
}

TEST(vector, iterator_1) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  std::vector<int> Vector = {1, 2, 3, 4, 5};
  auto s21_iter = s21_Vector.end();
  auto iter = Vector.end();
  ASSERT_EQ(*(--s21_iter), *(--iter));
  ASSERT_EQ(*(s21_iter - 2), *(iter - 2));
  ASSERT_EQ(*(s21_iter - 4), *(iter - 4));
}

TEST(vector, iterator_throw) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator s21_iter;
  EXPECT_THROW(*s21_iter, std::invalid_argument);
  EXPECT_THROW(++s21_iter, std::invalid_argument);
  EXPECT_THROW(--s21_iter, std::invalid_argument);
  EXPECT_THROW(s21_iter + 2, std::invalid_argument);
  EXPECT_THROW(s21_iter - 5, std::invalid_argument);
}

TEST(vector, iterator_bool) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator s21_iter_1;
  s21::vector<int>::iterator s21_iter_2;
  EXPECT_TRUE(s21_iter_1 == s21_iter_2);
  s21_iter_1 = s21_Vector.begin();
  s21_iter_2 = s21_Vector.begin() + 3;
  EXPECT_TRUE(s21_iter_1 != s21_iter_2);
}

TEST(vector, iterator_ptrdiff) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  auto s21_iter_1 = s21_Vector.begin();
  auto s21_iter_2 = s21_Vector.begin() + 3;
  std::vector<int> Vector = {1, 2, 3, 4, 5};
  auto iter_1 = Vector.begin();
  auto iter_2 = Vector.begin() + 3;
  ASSERT_EQ(s21_iter_2 - s21_iter_1, iter_2 - iter_1);
}

TEST(vector, iterator_increment_inf) {
  std::vector<int> s21_vec = {11, 2, 3};
  auto s21_it = s21_vec.begin();
  ASSERT_EQ(*++s21_it, 2);
  ASSERT_EQ(*s21_it, 2);
}

TEST(vector, iterator_increment_post) {
  std::vector<int> s21_vec = {11, 2, 3};
  auto s21_it = s21_vec.begin();
  ASSERT_EQ(*s21_it++, 11);
  ASSERT_EQ(*s21_it, 2);
}

TEST(vector, const_iterator_0) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  std::vector<int> Vector = {1, 2, 3, 4, 5};
  auto s21_iter = s21_Vector.cbegin();
  auto iter = Vector.cbegin();
  ASSERT_EQ(*s21_iter, *iter);
  ASSERT_EQ(*(++s21_iter), *(++iter));
  ASSERT_EQ(*(s21_iter + 2), *(iter + 2));
}

TEST(vector, const_iterator_1) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  std::vector<int> Vector = {1, 2, 3, 4, 5};
  auto s21_iter = s21_Vector.cend();
  auto iter = Vector.cend();
  ASSERT_EQ(*(--s21_iter), *(--iter));
  ASSERT_EQ(*(s21_iter - 2), *(iter - 2));
  ASSERT_EQ(*(s21_iter - 4), *(iter - 4));
}

TEST(vector, const_iterator_bool) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  s21::vector<int>::const_iterator s21_iter_1;
  s21::vector<int>::const_iterator s21_iter_2;
  EXPECT_TRUE(s21_iter_1 == s21_iter_2);
  s21_iter_1 = s21_Vector.cbegin();
  s21_iter_2 = s21_Vector.cbegin() + 3;
  EXPECT_TRUE(s21_iter_1 != s21_iter_2);
}

TEST(vector, const_iterator_ptrdiff) {
  s21::vector<int> s21_Vector = {1, 2, 3, 4, 5};
  auto s21_iter_1 = s21_Vector.cbegin();
  auto s21_iter_2 = s21_Vector.cbegin() + 3;
  std::vector<int> Vector = {1, 2, 3, 4, 5};
  auto iter_1 = Vector.cbegin();
  auto iter_2 = Vector.cbegin() + 3;
  ASSERT_EQ(s21_iter_2 - s21_iter_1, iter_2 - iter_1);
}

// TEST(vector, insert_many_0) {
//   std::vector<int> Vector = {1, 2, 3};
//   Vector.push_back(4);
//   Vector.push_back(5);
//   Vector.push_back(6);
//   s21::vector<int> s21_Vector = {1, 2, 3};
//   auto iter = s21_Vector.cend();
//   auto iter_res = s21_Vector.insert_many(iter, 4, 5, 6);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
//   ASSERT_EQ(*iter_res, 4);
// }
//
// TEST(vector, insert_many_1) {
//   std::vector<int> Vector = {1, 2, 3, 4, 5, 6};
//   s21::vector<int> s21_Vector = {4, 5, 6};
//   auto iter = s21_Vector.cbegin();
//   auto iter_res = s21_Vector.insert_many(iter, 1, 2, 3);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
//   ASSERT_EQ(*iter_res, 1);
// }
//
// TEST(vector, insert_many_2) {
//   std::vector<int> Vector = {1, 2};
//   s21::vector<int> s21_Vector = {1, 6};
//   Vector.push_back(3);
//   Vector.push_back(4);
//   Vector.push_back(5);
//   Vector.push_back(6);
//   s21::vector<int>::const_iterator iter = s21_Vector.cbegin();
//   auto iter_res = s21_Vector.insert_many(++iter, 2, 3, 4, 5);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
//   ASSERT_EQ(*iter_res, 2);
// }
//
// TEST(vector, insert_many_3) {
//   std::vector<int> Vector;
//   Vector.push_back(1);
//   Vector.push_back(2);
//   Vector.push_back(3);
//   s21::vector<int> s21_Vector;
//   s21::vector<int>::const_iterator iter = s21_Vector.cbegin();
//   auto iter_res = s21_Vector.insert_many(iter, 1, 2, 3);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
//   ASSERT_EQ(*iter_res, 1);
// }
//
// TEST(vector, insert_many_back_0) {
//   std::vector<int> Vector = {1, 2, 3, 4, 5, 6};
//   s21::vector<int> s21_Vector = {1, 2, 3};
//   s21_Vector.insert_many_back(4, 5, 6);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
// }
//
// TEST(vector, insert_many_back_1) {
//   std::vector<int> Vector;
//   Vector.push_back(4);
//   Vector.push_back(5);
//   Vector.push_back(6);
//   s21::vector<int> s21_Vector;
//   s21_Vector.insert_many_back(4, 5, 6);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
// }
//
// TEST(vector, insert_many_back_2) {
//   std::vector<int> Vector = {4};
//   s21::vector<int> s21_Vector;
//   s21_Vector.insert_many_back(4);
//   ASSERT_EQ(VectorEqual(s21_Vector, Vector), true);
// }
