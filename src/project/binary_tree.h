#ifndef __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
#define __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__

#include <iostream>

namespace s21 {
// ************ CLASS NODE ************
template<class T>
class Node {
public:
  T Key;
  Node* Left;
  Node* Right;

  Node(T key) : Key(key), Left(nullptr), Right(nullptr) {};
  void PrintNode() { std::cout << Key << std::endl; }
};

// ************ CLASS TREE ************
template<class T>
class BinaryTree {
public:
  BinaryTree(): Root(nullptr) {};
  ~BinaryTree() { DestroyTree(Root); }

  void Print() {
    TreePrint(Root);
    std::cout << std::endl;
  }

  void Insert(T key) {
    bool flag_identic_key = false;
    Node<T> **cur = &Root;                // храним адрес УКАЗАТЕЛЯ на узел
    while (*cur && !flag_identic_key) {   // пока корень не пустой
      Node<T> &node = **cur;              // создаем ссылку на адрес УКАЗАТЕЛЯ на узел
      if (key < node.Key) {
        cur = &node.Left;                 // берем адрес УКАЗАТЕЛЯ на левый узел
      } else if (key > node.Key) {
        cur = &node.Right;                // берем адрес УКАЗАТЕЛЯ на правый узел
      } else {
        flag_identic_key = true;
      }
    }
    if (!flag_identic_key) {
      *cur = new Node(key);               // меняем указатель на новую ноду
      ++Size;
    }
  }

  // удаление узла
  void Erase(T key) {
    Node<T> *curr = Root;
    Node<T> *parent = NULL;
    while (curr && curr->Key != key) {
      parent = curr;
      if (curr->Key > key)
        curr = curr->Left;
      else
        curr = curr->Right;
    }
    if (!curr) return;
    if (curr->Left == NULL) {
      // Вместо curr подвешивается его правое поддерево
      if (parent && parent->Left == curr)
        parent->Left = curr->Right;
      if (parent && parent->Right == curr)
        parent->Right = curr->Right;
      --Size;
      delete curr;
      return;
    }
    if (curr->Right == NULL) {
      // Вместо curr подвешивается его левое поддерево
      if (parent && parent->Left == curr)
        parent->Left = curr->Left;
      if (parent && parent->Right == curr)
        parent->Right = curr->Left;
      --Size;
      delete curr;
      return;
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    Node<T> *replace = curr->Right;
    while (replace->Left)
      replace = replace->Left;
    int replace_value = replace->Key;
    Erase(replace_value);
    curr->Key = replace_value;
  }

private:
  Node<T> *Root;
  int Size;

  void DestroyTree(Node<T> *node) {
    if (node) {
      DestroyTree(node->Left);
      DestroyTree(node->Right);
      delete node;
    } 
  }

  void TreePrint(Node<T> *node){
    if (node!=NULL) {                      //Пока не встретится пустой узел
      TreePrint(node->Left);        //Рекурсивная функция для левого поддерева
      std::cout << node->Key << " ";       //Отображаем корень дерева
      TreePrint(node->Right);       //Рекурсивная функция для правого поддерева
    }
  }

};
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
