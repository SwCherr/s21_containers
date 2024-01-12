#include "test.h"
#include <set>
// #include <map>

using namespace s21;

// ************************************
// ------------ CLASS TREE ------------
// ************************************
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

// ====== ITERATOR ======
// iterator& operator++()
TEST(BinaryTree, test_class_binary_tree_iterator_1) {
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
  binary_tree.Print();

  auto tmp = binary_tree.begin();
  for (auto i = binary_tree.begin(); i != binary_tree.end(); ++i) {
    std::cout << *i << " ";
    tmp = i;
  }
  ++tmp;
  std::cout << *tmp << " ";
  std::cout << std::endl;

  ASSERT_EQ(1, 1);
}

// iterator& operator--()
TEST(BinaryTree, test_class_binary_tree_iterator_2) {
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
  binary_tree.Print();

  auto tmp = binary_tree.begin();
  for (auto i = binary_tree.end(); i != binary_tree.begin(); --i) {
    std::cout << *i << " ";
    tmp = i;
  }
  --tmp;
  std::cout << *tmp << " ";
  std::cout << std::endl;

  ASSERT_EQ(1, 1);
}

// Erase() begin
TEST(BinaryTree, test_class_binary_tree_erase_1) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(15, 1);
  binary_tree.Insert(9, 2);
  binary_tree.Insert(12, 3);
  binary_tree.Insert(11, 3);
  binary_tree.Insert(13, 3);
  binary_tree.Erase(binary_tree.begin());
  ASSERT_EQ(1, 1);
}

// Erase() end
TEST(BinaryTree, test_class_binary_tree_erase_2) {
  BinaryTree<int, int> binary_tree;
  binary_tree.Insert(15, 1);
  binary_tree.Insert(9, 2);
  auto cur = binary_tree.end();
  binary_tree.Erase(cur);
  ASSERT_EQ(1, 1);
}

// ************************************
// ------------ CLASS SET -------------
// ************************************
// empty()
TEST(Set, test_class_set_empty_1) {
  set<int, int> set{};
  bool res = set.empty();
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_empty_2) {
  set<int, int> set{1, 2, 2};
  bool res = set.empty();
  bool check = false;
  ASSERT_EQ(res, check);
}

// size()
TEST(Set, test_class_set_size_1) {
  set<int, int> set{1, 2, 3};
  size_t res = set.size();
  size_t check = 3;
  ASSERT_EQ(res, check);
}

// max_size()
TEST(Set, test_class_set_max_size_1) {
  set<int, int> set{1, 2, 3};
  size_t res = set.max_size();
  size_t check = 461168601842738790;
  ASSERT_EQ(res, check);
}

// clear()
TEST(Set, test_class_set_clear_1) {
  set<int, int> set{1, 2, 3, 4, 5, 6};
  set.clear();
  // добавить проверку на пустой контейнер empty()
  // ASSERT_EQ();
}

// insert()
TEST(Set, test_class_set_insert_1) {
  set<double, double> set{};
  set.insert(4);
  set.insert(6);
  set.insert(8);
  // set.Print();
  ASSERT_EQ(1, 1);
}

TEST(Set, test_class_set_insert_2) {
  set<int, int> set{};
  set.insert(4);
  set.insert(6);
  set.insert(8);
  // set.Print();
  ASSERT_EQ(1, 1);
}

// erase
TEST(Set, test_class_set_erase_3) {
  set<int, int> set{1, 2, 5, 6, 8};
  // set.Print();
  set.erase(set.begin());
  // set.Print();
  ASSERT_EQ(1, 1);
}

// // copy construct
// TEST(Set, test_class_set_3) {
//   set<int, int> set{1, 2};
//   set<int, int> set_2{set};
//   set.Print();
//   set_2.Print();
//   ASSERT_EQ(1, 1);
// }


// find()
TEST(Set, test_class_set_find_1) {
  set<int, int> set{1, 2, 3, 4, 5, 6};
  auto res = set.find(1);
  auto check = set.begin();
  ASSERT_EQ(*res, *check);
}

// contains()
TEST(Set, test_class_set_contains_1) {
  set<int, int> set{1, 2, 3, 4, 5, 6};
  bool res = set.contains(1);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_contains_2) {
  set<int, int> set{1, 2, 3, 4, 5, 6};
  bool res = set.contains(4);
  bool check = true;
  ASSERT_EQ(res, check);
}

TEST(Set, test_class_set_contains_3) {
  set<int, int> set{1, 2, 3, 4, 5, 6};
  bool res = set.contains(8);
  bool check = false;
  ASSERT_EQ(res, check);
}