#include "binary_tree.h"

using namespace s21;

TNode::TNode(int key) : Key(key), Left(nullptr), Right(nullptr) {};

void TNode::PrintTNode() {
  std::cout << Key << std::endl;
}

// int main() {
//   TNode node_1(5);
//   node_1.PrintTNode();
//   return 0;
// }
























// ******************************
// --------- CLASS TREE ---------
// ******************************

// void TTree::Insert(int x) {
//   TNode** cur = &Root;
//   while (*cur) {
//     TNode& node = **cur;
//     if (x < node.Key) {
//       cur = &node.Left;
//     } else if (x > node.Key) {
//       cur = &node.Right;
//     } else {
//         return;
//     }
//   }
//   *cur = new TNode(x);
// }