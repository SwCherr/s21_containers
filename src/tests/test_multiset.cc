#include <gtest/gtest.h>

#include <set>
#include <string>

#include "../s21_sorted_container/s21_multiset.h"

// --------- Constructor & destructor ---------
// default constructor, creates empty tree
TEST(multiset, test_class_multiset_default_constructor_1) {
  s21::multiset<int> multiset_test;
  ASSERT_TRUE(multiset_test.size() == 0);
}

// copy constructor
TEST(multiset, test_class_multiset_copy_constructor_1) {
  s21::multiset<int> multiset_test_1{1, 2, 3, 3};
  s21::multiset<int> multiset_test_2{multiset_test_1};
  ASSERT_EQ(multiset_test_1.size(), multiset_test_2.size());
}

// copy constructor
TEST(multiset, test_class_multiset_copy_constructor_2) {
  s21::multiset<int> multiset_test_1;
  s21::multiset<int> multiset_test_2{multiset_test_1};
  ASSERT_EQ(multiset_test_1.size(), multiset_test_2.size());
}

// move constructor
TEST(multiset, test_class_multiset_move_constructor_1) {
  s21::multiset<int> multiset_test_1{};
  s21::multiset<int> multiset_test_2{std::move(multiset_test_1)};
  EXPECT_TRUE(multiset_test_1.size() == 0);
  EXPECT_TRUE(multiset_test_2.size() == 0);
}

// move constructor
TEST(multiset, test_class_multiset_move_constructor_2) {
  s21::multiset<int> multiset_test_1{1, 2, 3, 3};
  s21::multiset<int> multiset_test_2{std::move(multiset_test_1)};
  ASSERT_TRUE(multiset_test_1.size() == 0);
  EXPECT_TRUE(multiset_test_2.size() == 4);
}

// ---------------- Operator -----------------
// operator=(multiset&& o)
TEST(multiset, test_class_multiset_operator_1) {
  s21::multiset<int> multiset_test_1;
  s21::multiset<int> multiset_test_2 = std::move(multiset_test_1);
  ASSERT_TRUE(multiset_test_1.size() == 0);
}

// operator=(multiset&& o)
TEST(multiset, test_class_multiset_operator_2) {
  s21::multiset<int> multiset_test_1{1, 2, 3};
  s21::multiset<int> multiset_test_2 = std::move(multiset_test_1);
  ASSERT_TRUE(multiset_test_1.size() == 0);
}

// operator=(set&& o)
TEST(multiset, test_class_multiset_operator_3) {
  s21::multiset<int> multiset_test_1;
  s21::multiset<int> multiset_test_2 = multiset_test_1;
  ASSERT_TRUE(multiset_test_1.size() == 0);
}

// operator=(set&& o)
TEST(set, test_class_multiset_operator_4) {
  s21::multiset<int> multiset_test_1{1, 2, 3};
  s21::multiset<int> multiset_test_2 = multiset_test_1;
  ASSERT_TRUE(multiset_test_1.size() == 3);
  ASSERT_TRUE(multiset_test_2.size() == 3);
}

// ----------------- Methods -----------------
// empty()
TEST(multiset, test_class_multiset_empty_1) {
  s21::multiset<int> multiset_test{};
  bool res = multiset_test.empty();
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(multiset, test_class_multiset_empty_2) {
  s21::multiset<int> multiset_test{1, 2, 2};
  bool res = multiset_test.empty();
  bool check = false;
  EXPECT_TRUE(multiset_test.size() == 3);
  ASSERT_EQ(res, check);
}

// size()
TEST(multiset, test_class_multiset_size_1) {
  s21::multiset<int> multiset_test{1, 2, 3, 3};
  std::multiset<int> multiset_orig{1, 2, 3, 3};
  EXPECT_EQ(multiset_test.size(), multiset_orig.size());
  auto map_it_1 = multiset_test.begin();
  auto map_it_2 = multiset_orig.begin();
  for (; map_it_1 != multiset_test.end(); ++map_it_1, ++map_it_2) {
    EXPECT_TRUE(*map_it_1 == *map_it_2);
  }
}

// size()
TEST(multiset, test_class_multiset_size_2) {
  s21::multiset<int> multiset_test{1, 2, 3, 3};
  multiset_test.clear();
  EXPECT_TRUE(multiset_test.size() == 0);
  ASSERT_TRUE(multiset_test.empty());
}

// max_size()
TEST(multiset, test_class_multiset_max_size_1) {
  s21::multiset<int> multiset_test{1, 2, 3, 3};
  size_t res = multiset_test.max_size();
  size_t check = 1152921504606846975;
  ASSERT_EQ(res, check);
}

// clear()
TEST(multiset, test_class_multiset_clear_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  multiset_test.clear();
  EXPECT_TRUE(multiset_test.size() == 0);
  ASSERT_TRUE(multiset_test.empty());
}

// insert()
TEST(multiset, test_class_multiset_insert_1) {
  s21::multiset<double> multiset_test{};
  multiset_test.insert(4);
  multiset_test.insert(6);
  multiset_test.insert(8);
  ASSERT_TRUE(multiset_test.contains(4));
  ASSERT_TRUE(multiset_test.contains(6));
  ASSERT_TRUE(multiset_test.contains(8));
}

// insert_many()
TEST(multiset, test_class_multiset_insert_many_1) {
  s21::multiset<double> multiset_test{};
  multiset_test.insert_many(6, 6, 6, 8, 8, 9, 9, 9);
  ASSERT_TRUE(multiset_test.contains(6));
  ASSERT_TRUE(multiset_test.contains(8));
  ASSERT_TRUE(multiset_test.contains(9));
}

// erase
TEST(multiset, test_class_multiset_erase_1) {
  s21::multiset<int> multiset_test{15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto multiset_it = multiset_test.begin();
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(1));
}

// erase
TEST(multiset, test_class_multiset_erase_2) {
  s21::multiset<int> multiset_test{15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto multiset_it = multiset_test.begin() + 4;
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(9));
}

// erase
TEST(multiset, test_class_multiset_erase_3) {
  s21::multiset<int> multiset_test{15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto multiset_it = multiset_test.begin() + 3;
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(8));
}

// erase
TEST(multiset, test_class_multiset_erase_4) {
  s21::multiset<int> multiset_test{15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto multiset_it = multiset_test.begin() + 2;
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(7));
}

// erase
TEST(multiset, test_class_multiset_erase_5) {
  s21::multiset<int> multiset_test{15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto multiset_it = multiset_test.begin() + 8;
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(15));
}

// erase
TEST(multiset, test_class_multiset_erase_6) {
  s21::multiset<int> multiset_test{-8, 7, 6, -1, 0, 0, 4, 5, 8};
  auto multiset_it = multiset_test.begin();
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(-8));
}

// erase
TEST(multiset, test_class_multiset_erase_7) {
  s21::multiset<int> multiset_test{-8, 7, 6, -1, 0, 0, 4, 5, 8};
  auto multiset_it = multiset_test.begin() + 1;
  multiset_test.erase(multiset_it);
  EXPECT_FALSE(multiset_test.contains(-1));
}

// erase
TEST(multiset, test_class_multiset_erase_8) {
  s21::multiset<int> multiset_test{-4, 1, 2, 5, 6, 8, 4, 7};
  multiset_test.erase(multiset_test.begin());
  EXPECT_FALSE(multiset_test.contains(-4));
}

// erase
TEST(multiset, test_class_multiset_erase_9) {
  s21::multiset<int> multiset_test{2, 9, 5, 6, 8};
  multiset_test.erase(multiset_test.begin());
  EXPECT_FALSE(multiset_test.contains(2));
}

// erase
TEST(multiset, test_class_multiset_erase_10) {
  s21::multiset<int> multiset_test{2, 1, 2};
  multiset_test.erase(multiset_test.begin());
  EXPECT_FALSE(multiset_test.contains(1));
}

// erase
TEST(multiset, test_class_multiset_erase_11) {
  s21::multiset<int> multiset_test{1, 1, 2};
  multiset_test.erase(multiset_test.begin());
  EXPECT_TRUE(multiset_test.contains(1));
  multiset_test.erase(multiset_test.begin());
  EXPECT_FALSE(multiset_test.contains(1));
}

// erase
TEST(multiset, test_class_multiset_erase_12) {
  s21::multiset<int> multiset_test{1};
  multiset_test.erase(multiset_test.begin());
  EXPECT_FALSE(multiset_test.contains(1));
}

// swap()
TEST(multiset, test_class_multiset_swap_1) {
  s21::multiset<int> multiset_test_1{1, 2, 5, 6, 8, 7};
  s21::multiset<int> multiset_test_2{3, 4, 6, 7, 0};
  s21::multiset<int> multiset_test_1_res{3, 4, 6, 7, 0};
  s21::multiset<int> multiset_test_2_res{1, 2, 5, 6, 8, 7};
  multiset_test_1.swap(multiset_test_2);
  size_t size_res_1 = 5;
  size_t size_res_2 = 6;
  ASSERT_EQ(multiset_test_1.size(), size_res_1);
  ASSERT_EQ(multiset_test_2.size(), size_res_2);
}

// merge()
TEST(multiset, test_class_multiset_merge_1) {
  s21::multiset<int> multiset_test_1{8, 8, 8, 8};
  s21::multiset<int> multiset_test_2{3, 4, 6, 7, 0};
  std::multiset<int> std_test_1{8, 8, 8, 8};
  std::multiset<int> std_test_2{3, 4, 6, 7, 0};
  multiset_test_1.merge(multiset_test_2);
  std_test_1.merge(std_test_2);
  auto map_it_1 = multiset_test_1.begin();
  auto map_it_2 = std_test_1.begin();
  for (; map_it_1 != multiset_test_1.end(); ++map_it_1, ++map_it_2) {
    EXPECT_TRUE(*map_it_1 == *map_it_2);
  }
}

// count()
TEST(multiset, test_class_multiset_count_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  EXPECT_TRUE(multiset_test.count(1) == 1);
  EXPECT_TRUE(multiset_test.count(2) == 3);
  EXPECT_TRUE(multiset_test.count(0) == 2);
}

// find()
TEST(multiset, test_class_multiset_find_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  auto res = multiset_test.find(1);
  EXPECT_TRUE(*res == 1);
}

// contains()
TEST(multiset, test_class_multiset_contains_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  bool res = multiset_test.contains(1);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(multiset, test_class_multiset_contains_2) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  bool res = multiset_test.contains(2);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(multiset, test_class_multiset_contains_3) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  bool res = multiset_test.contains(8);
  bool check = false;
  ASSERT_EQ(res, check);
}

// equal_range()
TEST(multiset, test_class_multiset_equal_range_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  auto begin_it = multiset_test.begin() + 3;
  auto end_it = multiset_test.begin() + 5;
  auto res = multiset_test.equal_range(2);
  EXPECT_TRUE(*(res.first) == *begin_it);
  EXPECT_TRUE(*(res.second) == *end_it);
}

// equal_range()
TEST(multiset, test_class_multiset_equal_range_2) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  auto begin_it = multiset_test.begin();
  auto end_it = multiset_test.begin() + 1;
  auto res = multiset_test.equal_range(0);
  EXPECT_TRUE(*(res.first) == *begin_it);
  EXPECT_TRUE(*(res.second) == *end_it);
}

// equal_range()
TEST(multiset, test_class_multiset_equal_range_3) {
  s21::multiset<int> multiset_test{1, 2, 5, 2, 0, 0};
  auto begin_it = multiset_test.begin() + 5;
  auto end_it = multiset_test.begin() + 5;
  auto res = multiset_test.equal_range(5);
  EXPECT_TRUE(*(res.first) == *begin_it);
  EXPECT_TRUE(*(res.second) == *end_it);
}

// lower_bound()
TEST(multiset, test_class_multiset_lower_bound_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  auto begin_it = multiset_test.begin() + 3;
  auto res = multiset_test.lower_bound(2);
  EXPECT_TRUE(*res == *begin_it);
}

// lower_bound()
TEST(multiset, test_class_multiset_lower_bound_2) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  auto begin_it = multiset_test.begin();
  auto res = multiset_test.lower_bound(0);
  EXPECT_TRUE(*res == *begin_it);
}

// lower_bound()
TEST(multiset, test_class_multiset_lower_bound_3) {
  s21::multiset<int> multiset_test{1, 2, 5, 2, 0, 0};
  auto begin_it = multiset_test.begin() + 5;
  auto res = multiset_test.lower_bound(5);
  EXPECT_TRUE(*res == *begin_it);
}

// upper_bound()
TEST(multiset, test_class_multiset_upper_bound_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 5, 4, 0};
  auto end_it = multiset_test.begin() + 2;
  auto res = multiset_test.upper_bound(1);
  EXPECT_TRUE(*res == *end_it);
}

// upper_bound()
TEST(multiset, test_class_multiset_upper_bound_2) {
  s21::multiset<int> multiset_test{1, 2, 2, 5, 4, 0};
  auto end_it = multiset_test.begin() + 4;
  auto res = multiset_test.upper_bound(2);
  EXPECT_TRUE(*res == *end_it);
}

// upper_bound()
TEST(multiset, test_class_multiset_upper_bound_3) {
  s21::multiset<int> multiset_test{1, 2, 2, 5, 4, 0};
  auto end_it = multiset_test.begin() + 5;
  auto res = multiset_test.upper_bound(4);
  EXPECT_TRUE(*res == *end_it);
}

// ************************************
// --------- DIFFERENT TYPE -----------
// ************************************
TEST(multiset, test_class_multiset_int_1) {
  s21::multiset<int> multiset_test{1, 2, 2, 2, 0, 0};
  std::multiset<int> multiset_orig{1, 2, 2, 2, 0, 0};
  auto multiset_test_it = multiset_test.begin();
  auto multiset_orig_it = multiset_orig.begin();
  for (size_t i = 0; i < multiset_test.size(); ++i)
    EXPECT_TRUE(*multiset_orig_it == *multiset_test_it);
  ASSERT_EQ(multiset_test.size(), multiset_orig.size());
}

TEST(multiset, test_class_multiset_float_1) {
  s21::multiset<float> multiset_test{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  std::multiset<float> multiset_orig{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  auto multiset_test_it = multiset_test.begin();
  auto multiset_orig_it = multiset_orig.begin();
  for (size_t i = 0; i < multiset_test.size(); ++i)
    EXPECT_TRUE(*multiset_orig_it == *multiset_test_it);
  ASSERT_EQ(multiset_test.size(), multiset_orig.size());
}

TEST(multiset, test_class_multiset_double_1) {
  s21::multiset<double> multiset_test{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  std::multiset<double> multiset_orig{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  auto multiset_test_it = multiset_test.begin();
  auto multiset_orig_it = multiset_orig.begin();
  for (size_t i = 0; i < multiset_test.size(); ++i)
    EXPECT_TRUE(*multiset_orig_it == *multiset_test_it);
  ASSERT_EQ(multiset_test.size(), multiset_orig.size());
}

TEST(multiset, test_class_multiset_char_1) {
  s21::multiset<char> multiset_test{'a', 'b', 'c', 'd', 'e', 'f'};
  std::multiset<char> multiset_orig{'a', 'b', 'c', 'd', 'e', 'f'};
  auto multiset_test_it = multiset_test.begin();
  auto multiset_orig_it = multiset_orig.begin();
  for (size_t i = 0; i < multiset_test.size(); ++i)
    EXPECT_TRUE(*multiset_orig_it == *multiset_test_it);
  ASSERT_EQ(multiset_test.size(), multiset_orig.size());
}

TEST(multiset, test_class_multiset_string_1) {
  s21::multiset<std::string> multiset_test{"hello", "world"};
  std::multiset<std::string> multiset_orig{"hello", "world"};
  ASSERT_EQ(multiset_test.size(), multiset_orig.size());
}

TEST(multiset, test_class_multiset_string_2) {
  s21::multiset<std::string> multiset_test{"This", "is", "my", "multiset"};
  std::multiset<std::string> multiset_orig{"This", "is", "my", "multiset"};
  auto multiset_test_it = multiset_test.begin();
  auto multiset_orig_it = multiset_orig.begin();
  for (size_t i = 0; i < multiset_test.size(); ++i)
    EXPECT_TRUE(*multiset_orig_it == *multiset_test_it);
  ASSERT_EQ(multiset_test.size(), multiset_orig.size());
}
