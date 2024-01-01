#include "test.h"
// #include <set>
// #include <map>

using namespace s21;

// TEST(SetContainer, test_class_set_container_1) {
//   // SetContainer sorted_1;
//   // sorted_1.DataTypeSize();

//   s21::Set <int> set_1;
//   set_1.DataTypeSize();
//   std::set <int> numbers{1, 2, 3};
//   std::cout << numbers.size() << std::endl;
//   // numbers.key_type

//   // Map map_1;
//   // map_1.PrintSth();
//   ASSERT_EQ(1, 1);
// }

TEST(Node, test_class_node_1) {
  std::cout << "MAF-MAF" << std::endl;
  Node<int> node{5};
  node.PrintNode();
  ASSERT_EQ(1, 1);
}


TEST(BinaryTree, test_class_binary_tree_1) {
  BinaryTree<int> binary_tree_1;
  binary_tree_1.Insert(15);
  binary_tree_1.Insert(9);
  binary_tree_1.Insert(12);
  binary_tree_1.Insert(11);
  binary_tree_1.Insert(13);
  binary_tree_1.Insert(3);
  binary_tree_1.Insert(8);
  binary_tree_1.Insert(1);
  binary_tree_1.Insert(23);
  binary_tree_1.Insert(17);
  binary_tree_1.Insert(28);
  binary_tree_1.Insert(7);
  // binary_tree_1.Insert(4);
  // binary_tree_1.Insert(5);

  binary_tree_1.Print();
  binary_tree_1.Erase(3);
  binary_tree_1.Print();
  ASSERT_EQ(1, 1);
}


// TEST(Set, test_class_set_1) {
//   set set_container();

//   ASSERT_EQ(1, 1);
// }
