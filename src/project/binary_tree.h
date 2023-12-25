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

// Класс бинарного дерева
class TTree {
public:
  TTree(); // constructor
  ~TTree();
  void Insert(int x);
  void DeleteElement(int x);
  void TreePrint();

private:
  TNode* Root;
  void DestroyNode(TNode* node);
  void TreePrintPrivate(TNode* node);
};
} // namespace s21



#endif  // __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
