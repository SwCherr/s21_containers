#include "test.h"
// #include <set>
// #include <map>

using namespace s21;

// TEST(SetContainer, test_class_set_1_1) {
//   // SetContainer sorted_1;
//   // sorted_1.DataTypeSize();

//   s21::Set <int, int> set_1;
//   set_1.DataTypeSize();
//   std::set <int, int> numbers{1, 2, 3};
//   std::cout << numbers.size() << std::endl;
//   // numbers.key_type

//   // Map map_1;
//   // map_1.PrintSth();
//   ASSERT_EQ(1, 1);
// }

TEST(Node, test_class_node_1) {
  std::cout << "MAF-MAF" << std::endl;
  Node<int, int> node{5, 0};
  node.PrintNode();
  ASSERT_EQ(1, 1);
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

  binary_tree_1.Print();
  binary_tree_1.Erase(3);
  binary_tree_1.Print();
  ASSERT_EQ(1, 1);
}


// TEST(Set, test_class_set_1) {
//   set<int, int> set_1{};
//   set_1.insert(4);
//   set_1.insert(6);
//   set_1.insert(8);
//   set_1.Print();

//   ASSERT_EQ(1, 1);
// }

// TEST(Set, test_class_set_2) {
//   set<double, double> set_1{1.4, 2};
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