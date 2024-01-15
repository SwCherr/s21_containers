#include "test.h"
#include <string>
#include <set>
// #include <map>
using namespace s21;

// *************** ITERATOR ***************
// iterator& operator++()
TEST(BinaryTree, test_class_binary_tree_iterator_1) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(1, 1);
  binary_tree.Insert(2, 2);
  binary_tree.Insert(3, 3);
  binary_tree.Insert(4, 3);
  binary_tree.Insert(5, 3);
  binary_tree.Insert(6, 3);
  binary_tree.Insert(7, 3);
  binary_tree.Insert(8, 3);
  binary_tree.Insert(9, 3);
  binary_tree.Insert(10, 3);
  binary_tree.Insert(11, 3);
  binary_tree.Insert(12, 3);
  // binary_tree.PrintByIterator();
  // binary_tree.Print();
  int check_value = 1;
  auto cur = binary_tree.begin();
  for (size_t i = 0; i < binary_tree.size(); ++i) {
    ASSERT_EQ(*cur, check_value);
    ++check_value;
    if (cur != binary_tree.end()) 
      ++cur;
  }
  const unsigned long size_res = 12;
  ASSERT_EQ(binary_tree.size(), size_res);
}

// iterator& operator--()
TEST(BinaryTree, test_class_binary_tree_iterator_2) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(1, 1);
  binary_tree.Insert(2, 2);
  binary_tree.Insert(3, 3);
  binary_tree.Insert(4, 3);
  binary_tree.Insert(5, 3);
  binary_tree.Insert(6, 3);
  binary_tree.Insert(7, 3);
  binary_tree.Insert(8, 3);
  binary_tree.Insert(9, 3);
  binary_tree.Insert(10, 3);
  binary_tree.Insert(11, 3);
  binary_tree.Insert(12, 3);
  // binary_tree.Print();
  int check_value = 12;
  auto cur = binary_tree.end();
  for (size_t i = 0; i < binary_tree.size(); ++i) {
    ASSERT_EQ(*cur, check_value);
    --check_value;
    --cur;
  }
  const unsigned long size_res = 12;
  ASSERT_EQ(binary_tree.size(), size_res);
}

// *************** BINARY TREE ***************
// --------- Constructor & destructor ---------
// default constructor, creates empty tree
TEST(BinaryTree, test_class_binary_tree_default_constructor_1) {
  BinaryTree<int, int> binary_tree;
  const unsigned long check = 0;
  ASSERT_EQ(check, binary_tree.size());
}

// добавить конструктор листом инициализации как вв сете
// TEST(BinaryTree, test_class_binary_tree_constructor_2)

// copy constructor
TEST(BinaryTree, test_class_binary_tree_copy_constructor_1) {
  BinaryTree<int, int> binary_tree_1;
  binary_tree_1.Insert(15, 1);
  binary_tree_1.Insert(9, 2);
  binary_tree_1.Insert(12, 3);
  binary_tree_1.Insert(11, 3);
  binary_tree_1.Insert(13, 3);
  BinaryTree<int, int> binary_tree_2{binary_tree_1};
  ASSERT_EQ(binary_tree_1.size(), binary_tree_2.size());
  // ASSERT_EQ(CheckEqTreeByKey(binary_tree_1, binary_tree_2), true);
}

// copy constructor
TEST(BinaryTree, test_class_binary_tree_copy_constructor_2) {
  BinaryTree<int, int> binary_tree_1;
  BinaryTree<int, int> binary_tree_2{binary_tree_1};
  ASSERT_EQ(binary_tree_1.size(), binary_tree_2.size());
  // ASSERT_EQ(CheckEqTreeByKey(binary_tree_1, binary_tree_2), true);
}

// move constructor
TEST(BinaryTree, test_class_binary_tree_move_constructor_1) {
  BinaryTree<int, int> binary_tree_1;
  BinaryTree<int, int> binary_tree_2(std::move(binary_tree_1));
  const unsigned long check_size = 0;
  ASSERT_EQ(check_size, binary_tree_1.size());
  // ASSERT_EQ(CheckEqTreeByKey(binary_tree_1, binary_tree_2), true);
}

// move constructor
TEST(BinaryTree, test_class_binary_tree_move_constructor_2) {
  BinaryTree<int, int> binary_tree_1;
  binary_tree_1.Insert(15, 1);
  binary_tree_1.Insert(9, 2);
  binary_tree_1.Insert(12, 3);
  binary_tree_1.Insert(11, 3);
  binary_tree_1.Insert(13, 3);
  BinaryTree<int, int> binary_tree_2(std::move(binary_tree_1));
  const unsigned long check_size = 0;
  ASSERT_EQ(check_size, binary_tree_1.size());
  // ASSERT_EQ(CheckEqTreeByKey(binary_tree_1, binary_tree_2), false);
}

// ---------------- Operator -----------------
// operator=(BinaryTree&& o)
TEST(BinaryTree, test_class_binary_tree_operator_1) {
  BinaryTree<int, int> binary_tree_1;
  BinaryTree<int, int> binary_tree_2 = std::move(binary_tree_1);
  const unsigned long check_size = 0;
  ASSERT_EQ(check_size, binary_tree_1.size());
  // ASSERT_EQ(CheckEqTreeByKey(binary_tree_1, binary_tree_2), true);
}

// operator=(BinaryTree&& o)
TEST(BinaryTree, test_class_binary_tree_operator_2) {
  BinaryTree<int, int> binary_tree_1;
  binary_tree_1.Insert(15, 1);
  binary_tree_1.Insert(9, 2);
  binary_tree_1.Insert(12, 3);
  binary_tree_1.Insert(11, 3);
  binary_tree_1.Insert(13, 3);
  BinaryTree<int, int> binary_tree_2 = std::move(binary_tree_1);
  const unsigned long check_size = 0;
  ASSERT_EQ(check_size, binary_tree_1.size());
  // ASSERT_EQ(CheckEqTreeByKey(binary_tree_1, binary_tree_2), false);
}

// ----------------- Methods -----------------
// Insert() & EraseElement()
TEST(BinaryTree, test_class_binary_tree_insert_1) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(15, 1);
  binary_tree.Insert(9, 2);
  binary_tree.Insert(12, 3);
  binary_tree.Insert(11, 3);
  binary_tree.Insert(13, 3);
  binary_tree.Insert(3, 3);
  binary_tree.Insert(8, 3);
  binary_tree.Insert(1, 3);
  binary_tree.Insert(23, 3);
  binary_tree.Insert(17, 3);
  binary_tree.Insert(28, 3);
  binary_tree.Insert(7, 3);
  // binary_tree.Insert(4, 3);
  // binary_tree.Insert(5, 3);
  // binary_tree.Print();
  binary_tree.EraseElement(3);
  // binary_tree.Print();
  ASSERT_EQ(1, 1);
}

// erase() begin
TEST(BinaryTree, test_class_binary_tree_erase_1) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(15, 1);
  binary_tree.Insert(9, 2);
  binary_tree.Insert(12, 3);
  binary_tree.Insert(11, 3);
  binary_tree.Insert(13, 3);
  binary_tree.erase(binary_tree.begin());
  ASSERT_EQ(1, 1);
}

// erase() end
TEST(BinaryTree, test_class_binary_tree_erase_2) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(15, 1);
  binary_tree.Insert(9, 2);
  auto cur = binary_tree.end();
  binary_tree.erase(cur);
  ASSERT_EQ(1, 1);
}

// ************************************
// ------------ CLASS SET -------------
// ************************************
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
  // добавить проверку на пустой контейнер empty()
  // ASSERT_EQ();
}

// insert()
TEST(Set, test_class_set_insert_1) {
  s21::set<double> set_test{};
  set_test.insert(4);
  set_test.insert(6);
  set_test.insert(8);
  // set_test.Print();
  ASSERT_EQ(1, 1);
}

TEST(Set, test_class_set_insert_2) {
  s21::set<int> set_test{};
  set_test.insert(4);
  set_test.insert(6);
  set_test.insert(8);
  // set_test.Print();
  ASSERT_EQ(1, 1);
}

// erase
TEST(Set, test_class_set_erase_1) {
  s21::set<int> set_test{1, 2, 5, 6, 8};
  // set_test.Print();
  set_test.erase(set_test.begin());
  // set_test.Print();
  ASSERT_EQ(1, 1);
}

// swap()
TEST(Set, test_class_set_swap_1) {
  s21::set<int> set_test_1{1, 2, 5, 6, 8, 7};
  s21::set<int> set_test_2{3, 4, 6, 7, 0};
  s21::set<int> set_test_1_res{3, 4, 6, 7, 0};
  s21::set<int> set_test_2_res{1, 2, 5, 6, 8, 7};
  set_test_1.swap(set_test_2);
  // // set_test_1.Print();
  // // set_test_2.Print();
  size_t size_res_1 = 5;
  size_t size_res_2 = 6;
  ASSERT_EQ(set_test_1.size(), size_res_1);
  ASSERT_EQ(set_test_2.size(), size_res_2);
  // ASSERT_EQ(CheckEqTreeByKey(set_test_1, set_test_1_res), true);
  // ASSERT_EQ(CheckEqTreeByKey(set_test_2, set_test_2_res), true);
}

// merge()
TEST(Set, test_class_set_merge_1) {
  s21::set<int> set_test_1{8, 2, 5, 6, 1, 9};
  s21::set<int> set_test_2{3, 4, 6, 7, 0};
  s21::set<int> set_test_res{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  set_test_1.merge(set_test_2);
  size_t size_res = 10;
  ASSERT_EQ(set_test_1.size(), size_res);
  // // set_test_1.Print();
  // // set_res.Print();
  // ASSERT_EQ(CheckEqTreeByKey(set_test_1, set_res), true);
}

// // copy construct
// TEST(Set, test_class_set_3) {
//   s21::set<int> set_test{1, 2};
//   s21::set<int> set_test_2{set};
  // // set_test.Print();
  // // set_test_2.Print();
//   ASSERT_EQ(1, 1);
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
  std::set<int> orig_set {1, 2, 3, 4, 5, 6};
  auto set_it = set_test.begin();
  auto orig_it = orig_set.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*orig_it == *set_it);
    if (set_it != set_test.end()) 
      ++set_it;
      ++orig_it;
  }
  ASSERT_EQ(set_test.size(), orig_set.size());
}

TEST(Set, test_class_set_float_1) {
  s21::set<float> set_test{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  std::set<float> orig_set {1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  auto set_it = set_test.begin();
  auto orig_it = orig_set.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*orig_it == *set_it);
    if (set_it != set_test.end()) 
      ++set_it;
      ++orig_it;
  }
  ASSERT_EQ(set_test.size(), orig_set.size());
}

TEST(Set, test_class_set_double_1) {
  s21::set<double> set_test{1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  std::set<double> orig_set {1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
  auto set_it = set_test.begin();
  auto orig_it = orig_set.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*orig_it == *set_it);
    if (set_it != set_test.end()) 
      ++set_it;
      ++orig_it;
  }
  ASSERT_EQ(set_test.size(), orig_set.size());
}

TEST(Set, test_class_set_char_1) {
  s21::set<char> set_test{'a', 'b', 'c', 'd', 'e', 'f'};
  std::set<char> orig_set {'a', 'b', 'c', 'd', 'e', 'f'};
  auto set_it = set_test.begin();
  auto orig_it = orig_set.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*orig_it == *set_it);
    if (set_it != set_test.end()) 
      ++set_it;
      ++orig_it;
  }
  ASSERT_EQ(set_test.size(), orig_set.size());
}

TEST(Set, test_class_set_string_1) {
  s21::set<std::string> set_test {"hello", "world"};
  std::set<std::string> orig_set {"hello", "world"};
  ASSERT_EQ(set_test.size(), orig_set.size());
}

TEST(Set, test_class_set_string_2) {
  s21::set<std::string> set_test {"This", "is", "my", "set"};
  std::set<std::string> orig_set {"This", "is", "my", "set"};
  auto set_it = set_test.begin();
  auto orig_it = orig_set.begin();
  for (size_t i = 0; i < set_test.size(); ++i) {
    EXPECT_TRUE(*orig_it == *set_it);
    if (set_it != set_test.end()) 
      ++set_it;
      ++orig_it;
  }
  ASSERT_EQ(set_test.size(), orig_set.size());
}
