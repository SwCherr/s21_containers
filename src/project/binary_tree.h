#ifndef __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
#define __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__

#include <iostream>

namespace s21 {

// Класс вершины бинарного дерева
class TNode {
public:
  int Key;
  TNode* Left;
  TNode* Right;

  TNode(int key);  // constructor
  void PrintTNode();
};

// // Класс бинарного дерева
// class TTree {
// public:
//   TTree(): Root(0) {}
//   ~TTree() {
//     DestroyNode(Root);
//   }
// private:
//   static void DestroyNode(TNode* node) {
//     if (node) {
//       DestroyNode(node->Left);
//       DestroyNode(node->Right);
//       delete node;
//     } 
//   }
// private:
//   TNode* Root;
// };
} // namespace s21



#endif  // __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
