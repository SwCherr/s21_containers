#include "test.h"
// #include <set>
// #include <map>

// using namespace std;
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

TEST(TNode, test_class_binary_tree_1) {
  // std::cout << "MAF-MAF" << std::endl;
  // TNode node_1(5);
  // node_1.PrintTNode();

  TTree binary_tree_1;
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
  // binary_tree_1.Insert(4);
  // binary_tree_1.Insert(5);

  binary_tree_1.TreePrint();
  binary_tree_1.DeleteElement(3);
  binary_tree_1.TreePrint();
  ASSERT_EQ(1, 1);
}
