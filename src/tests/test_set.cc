#include <set>
#include <string>
#include <gtest/gtest.h>
#include "../project/s21_set.h"

using namespace s21;

// // *************** BINARY TREE ***************
// // --------- Constructor & destructor ---------
// // default constructor, creates empty tree
// TEST(BTree, test_class_binary_tree_default_constructor_1) {
//   BTree<int, int> binary_tree;
//   const unsigned long check = 0;
//   ASSERT_EQ(check, binary_tree.size());
// }

// // добавить конструктор листом инициализации как вв сете
// // TEST(BTree, test_class_binary_tree_constructor_2)

// // copy constructor
// TEST(BTree, test_class_binary_tree_copy_constructor_1) {
//   BTree<int, int> binary_tree_1;
//   binary_tree_1.Insert(15, 1);
//   binary_tree_1.Insert(9, 2);
//   binary_tree_1.Insert(12, 3);
//   binary_tree_1.Insert(11, 3);
//   binary_tree_1.Insert(13, 3);
//   BTree<int, int> binary_tree_2{binary_tree_1};
//   ASSERT_EQ(binary_tree_1.size(), binary_tree_2.size());
// }

// // copy constructor
// TEST(BTree, test_class_binary_tree_copy_constructor_2) {
//   BTree<int, int> binary_tree_1;
//   BTree<int, int> binary_tree_2{binary_tree_1};
//   ASSERT_EQ(binary_tree_1.size(), binary_tree_2.size());
// }

// // move constructor
// TEST(BTree, test_class_binary_tree_move_constructor_1) {
//   BTree<int, int> binary_tree_1;
//   BTree<int, int> binary_tree_2(std::move(binary_tree_1));
//   ASSERT_TRUE(binary_tree_1.size() == 0);
// }

// // move constructor
// TEST(BTree, test_class_binary_tree_move_constructor_2) {
//   BTree<int, int> binary_tree_1;
//   binary_tree_1.Insert(15, 1);
//   binary_tree_1.Insert(9, 2);
//   binary_tree_1.Insert(12, 3);
//   binary_tree_1.Insert(11, 3);
//   binary_tree_1.Insert(13, 3);
//   BTree<int, int> binary_tree_2(std::move(binary_tree_1));
//   ASSERT_TRUE(binary_tree_1.size() == 0);
// }

// // ---------------- Operator -----------------
// // operator=(BTree&& o)
// TEST(BTree, test_class_binary_tree_operator_1) {
//   BTree<int, int> binary_tree_1;
//   BTree<int, int> binary_tree_2 = std::move(binary_tree_1);
//   ASSERT_TRUE(binary_tree_1.size() == 0);
// }

// // operator=(BTree&& o)
// TEST(BTree, test_class_binary_tree_operator_2) {
//   BTree<int, int> binary_tree_1;
//   binary_tree_1.Insert(15, 1);
//   binary_tree_1.Insert(9, 2);
//   binary_tree_1.Insert(12, 3);
//   binary_tree_1.Insert(11, 3);
//   binary_tree_1.Insert(13, 3);
//   BTree<int, int> binary_tree_2 = std::move(binary_tree_1);
//   ASSERT_TRUE(binary_tree_1.size() == 0);
// }

// ************************************
// ------------ CLASS SET -------------
// ************************************

// // move constructor
// TEST(set, test_class_set) {
//   s21::set<int> *set_test_1 = nullptr;
//   s21::set<int> set_test_2{std::move(set_test_1)};
//   EXPECT_TRUE(set_test_1.size() == 0);
//   EXPECT_TRUE(set_test_2.size() == 0);
// }

// move constructor
TEST(set, test_class_set_move_constructor_1) {
  s21::set<int> set_test_1{};
  s21::set<int> set_test_2{std::move(set_test_1)};
  EXPECT_TRUE(set_test_1.size() == 0);
  EXPECT_TRUE(set_test_2.size() == 0);
}

// move constructor
TEST(set, test_class_set_move_constructor_2) {
  s21::set<int> set_test_1{1, 2, 3};
  s21::set<int> set_test_2{std::move(set_test_1)};
  ASSERT_TRUE(set_test_1.size() == 0);
  EXPECT_TRUE(set_test_2.size() == 3);
}

// empty()
TEST(Set, test_class_set_empty_1) {
  s21::set<int> set_test{};
  bool res = set_test.empty();
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_empty_2) {
  s21::set<int> set_test{1, 2, 2};
  bool res = set_test.empty();
  bool check = false;
  ASSERT_EQ(res, check);
}

// size()
TEST(Set, test_class_set_size_1) {
  s21::set<int> set_test{1, 2, 3};
  size_t res = set_test.size();
  size_t check = 3;
  ASSERT_EQ(res, check);
}

// size()
TEST(Set, test_class_set_size_2) {
  s21::set<int> set_test{1, 2, 3};
  set_test.erase(set_test.begin());
  size_t res = set_test.size();
  size_t check = 2;
  ASSERT_EQ(res, check);
}

// size()
TEST(Set, test_class_set_size_3) {
  s21::set<int> set_test{1, 2, 3};
  set_test.clear();
  size_t res = set_test.size();
  size_t check = 0;
  ASSERT_EQ(res, check);
}

// max_size()
TEST(Set, test_class_set_max_size_1) {
  s21::set<int> set_test{1, 2, 3};
  size_t res = set_test.max_size();
  size_t check = 461168601842738790;
  ASSERT_EQ(res, check);
}

// clear()
TEST(Set, test_class_set_clear_1) {
  s21::set<int> set_test{1, 2, 3, 4, 5, 6};
  set_test.clear();
  ASSERT_TRUE(set_test.empty());
}

// insert()
TEST(Set, test_class_set_insert_1) {
  s21::set<double> set_test{};
  set_test.insert(4);
  set_test.insert(6);
  set_test.insert(8);
  ASSERT_TRUE(set_test.contains(4));
  ASSERT_TRUE(set_test.contains(6));
  ASSERT_TRUE(set_test.contains(8));
}

// erase
TEST(set, test_class_set_erase_1) {
  s21::set<int> set_test {15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto set_it = set_test.begin();
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(1));
}

// erase
TEST(set, test_class_set_erase_2) {
  s21::set<int> set_test {15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto set_it = set_test.begin() + 4;
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(9));
}

// erase
TEST(set, test_class_set_erase_3) {
  s21::set<int> set_test {15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto set_it = set_test.begin() + 3;
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(8));
}

// erase
TEST(set, test_class_set_erase_4) {
  s21::set<int> set_test {15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto set_it = set_test.begin() + 2;
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(7));
}

// erase
TEST(set, test_class_set_erase_5) {
  s21::set<int> set_test {15, 9, 3, 1, 8, 7, 12, 11, 13, 23, 17, 28};
  auto set_it = set_test.begin() + 8;
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(15));
}

// erase
TEST(set, test_class_set_erase_6) {
  s21::set<int> set_test{-8, 7, 6, -1, 0, 0, 4, 5, 8};
  auto set_it = set_test.begin();
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(-8));
}

// erase
TEST(set, test_class_set_erase_7) {
  s21::set<int> set_test{-8, 7, 6, -1, 0, 0, 4, 5, 8};
  auto set_it = set_test.begin() + 1;
  set_test.erase(set_it);
  EXPECT_FALSE(set_test.contains(-1));
}

// erase
TEST(set, test_class_set_erase_8) {
  s21::set<int> set_test{-4, 1, 2, 5, 6, 8, 4, 7};
  set_test.erase(set_test.begin());
  EXPECT_FALSE(set_test.contains(-4));
}

// erase
TEST(set, test_class_set_erase_9) {
  s21::set<int> set_test{2, 9, 5, 6, 8};
  set_test.erase(set_test.begin());
  EXPECT_FALSE(set_test.contains(2));
}

// erase
TEST(set, test_class_set_erase_10) {
  s21::set<int> set_test{2, 1, 2};
  set_test.erase(set_test.begin());
  EXPECT_FALSE(set_test.contains(1));
}

// erase
TEST(set, test_class_set_erase_11) {
  s21::set<int> set_test{1, 1, 2};
  set_test.erase(set_test.begin());
  EXPECT_FALSE(set_test.contains(1));
}

// erase
TEST(set, test_class_set_erase_12) {
  s21::set<int> set_test{1};
  set_test.erase(set_test.begin());
  EXPECT_FALSE(set_test.contains(1));
}

// swap()
TEST(Set, test_class_set_swap_1) {
  s21::set<int> set_test_1{1, 2, 5, 6, 8, 7};
  s21::set<int> set_test_2{3, 4, 6, 7, 0};
  s21::set<int> set_test_1_res{3, 4, 6, 7, 0};
  s21::set<int> set_test_2_res{1, 2, 5, 6, 8, 7};
  set_test_1.swap(set_test_2);
  size_t size_res_1 = 5;
  size_t size_res_2 = 6;
  ASSERT_EQ(set_test_1.size(), size_res_1);
  ASSERT_EQ(set_test_2.size(), size_res_2);
}

// merge()
TEST(Set, test_class_set_merge_1) {
  s21::set<int> set_test_1{8, 2, 5, 6, 1, 9};
  s21::set<int> set_test_2{3, 4, 6, 7, 0};
  s21::set<int> set_test_res{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  set_test_1.merge(set_test_2);
  size_t size_res = 10;
  ASSERT_EQ(set_test_1.size(), size_res);
}

// // copy construct
// TEST(Set, test_class_set_3) {
//   s21::set<int> set_test{1, 2};
//   s21::set<int> set_test_2{set};
  // ASS--------------------------------------    ERT_EQ(1, 1);
// }


// find()
TEST(Set, test_class_set_find_1) {
  s21::set<int> set_test{1, 2, 3, 4, 5, 6};
  auto res = set_test.find(1);
  auto check = set_test.begin();
  ASSERT_EQ(*res, *check);
}

// contains()
TEST(Set, test_class_set_contains_1) {
  s21::set<int> set_test{1, 2, 3, 4, 5, 6};
  bool res = set_test.contains(1);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_contains_2) {
  s21::set<int> set_test{1, 2, 3, 4, 5, 6};
  bool res = set_test.contains(4);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_contains_3) {
  s21::set<int> set_test{1, 2, 3, 4, 5, 6};
  bool res = set_test.contains(8);
  bool check = false;
  ASSERT_EQ(res, check);
}

// ************************************
// --------- DIFFERENT TYPE -----------
// ************************************
TEST(Set, test_class_set_int_1) {
  s21::set<int> set_test{1, 2, 3, 4, 5, 6};
  std::set<int> set_orig {1, 2, 3, 4, 5, 6};
  auto set_test_it = set_test.begin();
  auto set_orig_it = set_orig.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*set_orig_it == *set_test_it);
    if (set_test_it != set_test.end()) 
      ++set_test_it;
      ++set_orig_it;
  }
  ASSERT_EQ(set_test.size(), set_orig.size());
}

TEST(Set, test_class_set_float_1) {
  s21::set<float> set_test{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  std::set<float> set_orig {1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  auto set_test_it = set_test.begin();
  auto set_orig_it = set_orig.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*set_orig_it == *set_test_it);
    if (set_test_it != set_test.end()) 
      ++set_test_it;
      ++set_orig_it;
  }
  ASSERT_EQ(set_test.size(), set_orig.size());
}

TEST(Set, test_class_set_double_1) {
  s21::set<double> set_test{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  std::set<double> set_orig {1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  auto set_test_it = set_test.begin();
  auto set_orig_it = set_orig.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*set_orig_it == *set_test_it);
    if (set_test_it != set_test.end()) 
      ++set_test_it;
      ++set_orig_it;
  }
  ASSERT_EQ(set_test.size(), set_orig.size());
}

TEST(Set, test_class_set_char_1) {
  s21::set<char> set_test{'a', 'b', 'c', 'd', 'e', 'f'};
  std::set<char> set_orig {'a', 'b', 'c', 'd', 'e', 'f'};
  auto set_test_it = set_test.begin();
  auto set_orig_it = set_orig.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*set_orig_it == *set_test_it);
    if (set_test_it != set_test.end()) 
      ++set_test_it;
      ++set_orig_it;
  }
  ASSERT_EQ(set_test.size(), set_orig.size());
}

TEST(Set, test_class_set_string_1) {
  s21::set<std::string> set_test {"hello", "world"};
  std::set<std::string> set_orig {"hello", "world"};
  ASSERT_EQ(set_test.size(), set_orig.size());
}

TEST(Set, test_class_set_string_2) {
  s21::set<std::string> set_test {"This", "is", "my", "set"};
  std::set<std::string> set_orig {"This", "is", "my", "set"};
  auto set_test_it = set_test.begin();
  auto set_orig_it = set_orig.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*set_orig_it == *set_test_it);
    // std::cout << *set_orig_it << " ";
    // std::cout << *set_test_it << std::endl;
    if (set_test_it != set_test.end()) 
      ++set_test_it;
      ++set_orig_it;
  }
  ASSERT_EQ(set_test.size(), set_orig.size());
}
