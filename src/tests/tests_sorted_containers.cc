#include "test.h"
// #include <set>
// #include <map>

using namespace s21;

TEST(Node, test_class_node_1) {
  Node<int, int> node{5, 0};
  ASSERT_EQ(1, 1);
}

// empty()
TEST(Set, test_class_set_empty_1) {
  set<int, int> set_1{};
  bool res = set_1.empty();
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_empty_2) {
  set<int, int> set_1{1, 2, 2};
  bool res = set_1.empty();
  bool check = false;
  ASSERT_EQ(res, check);
}

// size()
TEST(Set, test_class_set_size_1) {
  set<int, int> set_1{1, 2, 3};
  size_t res = set_1.size();
  size_t check = 3;
  ASSERT_EQ(res, check);
}

// max_size()
TEST(Set, test_class_set_max_size_1) {
  set<int, int> set_1{1, 2, 3};
  size_t res = set_1.max_size();
  size_t check = 461168601842738790;
  ASSERT_EQ(res, check);
}

// clear()
TEST(Set, test_class_set_clear_1) {
  set<int, int> set_1{1, 2, 3, 4, 5, 6};
  set_1.clear();
  // добавить проверку на пустой контейнер empty()
  // ASSERT_EQ();
}

TEST(BinaryTree, test_class_binary_tree_1) {
  BinaryTree<int, int> binary_tree_1;
  binary_tree_1.Insert(15, 1);
  binary_tree_1.Insert(9, 2);
  binary_tree_1.Insert(12, 3);
  binary_tree_1.Insert(11, 3);
  binary_tree_1.Insert(13, 3);
  binary_tree_1.Insert(3, 3);
  binary_tree_1.Insert(8, 3);
  binary_tree_1.Insert(1, 3);
  binary_tree_1.Insert(23, 3);
  binary_tree_1.Insert(17, 3);
  binary_tree_1.Insert(28, 3);
  binary_tree_1.Insert(7, 3);
  // binary_tree_1.Insert(4, 3);
  // binary_tree_1.Insert(5, 3);
  // binary_tree_1.Print();
  binary_tree_1.EraseElement(3);
  // binary_tree_1.Print();
  ASSERT_EQ(1, 1);
}

// insert()
TEST(Set, test_class_set_insert_1) {
  set<double, double> set_1{};
  set_1.insert(4);
  set_1.insert(6);
  set_1.insert(8);
  // set_1.Print();
  ASSERT_EQ(1, 1);
}

TEST(Set, test_class_set_insert_2) {
  set<int, int> set_1{};
  set_1.insert(4);
  set_1.insert(6);
  set_1.insert(8);
  // set_1.Print();
  ASSERT_EQ(1, 1);
}

TEST(Set, test_class_set_2) {
  set<int, int> set_1{1, 2};
  // set_1.Print();
  ASSERT_EQ(1, 1);
}

// // erase
// TEST(Set, test_class_set_3) {
//   set<int, int> set_1{1, 2, 5, 6, 8};
//   set_1.Print();
//   set_1.erase(set_1.begin());
//   set_1.Print();
//   ASSERT_EQ(1, 1);
// }

// // copy construct
// TEST(Set, test_class_set_3) {
//   set<int, int> set_1{1, 2};
//   set<int, int> set_2{set_1};
//   set_1.Print();
//   set_2.Print();
//   ASSERT_EQ(1, 1);
// }


// find()
TEST(Set, test_class_set_find_1) {
  set<int, int> set_1{1, 2, 3, 4, 5, 6};
  auto res = set_1.find(1);
  auto check = set_1.begin();
  ASSERT_EQ(*res, *check);
}

// contains()
TEST(Set, test_class_set_contains_1) {
  set<int, int> set_1{1, 2, 3, 4, 5, 6};
  bool res = set_1.contains(1);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_contains_2) {
  set<int, int> set_1{1, 2, 3, 4, 5, 6};
  bool res = set_1.contains(4);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_contains_3) {
  set<int, int> set_1{1, 2, 3, 4, 5, 6};
  bool res = set_1.contains(8);
  bool check = false;
  ASSERT_EQ(res, check);
}