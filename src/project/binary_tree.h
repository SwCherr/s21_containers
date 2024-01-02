#ifndef __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
#define __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__

#include <iostream>

namespace s21 {
// ************ CLASS NODE ************
template<class T1, class T2>
class Node {
public:
  T1 Key;
  T2 Value;
  Node* Left;
  Node* Right;
  Node(T1 key, T2 value) : Key(key), Value(value), Left(nullptr), Right(nullptr) {};
  void PrintNode() { std::cout << Key << std::endl; }
};

// ************ CLASS TREE ************
template<class T1, class T2>
class BinaryTree {
public:
  Node<T1, T2> *Root;
  int Size;

  BinaryTree(): Root(nullptr){};
  // это не копирование а ссылка на один и тот же экземпляр дерева !!!
  // ИСПРАВИТЬ
  BinaryTree(const BinaryTree &other) : Root(other.Root), Size(other.Size) {} 
  ~BinaryTree() { DestroyTree(Root); }

  // публичные методы для итерирования по элементам класса
  class Iterator;
  Iterator Begin() { return BinaryTree::Iterator(GetMin(Root)); }
  Iterator End() { return BinaryTree::Iterator(GetMax(Root)); }

  // ***** ITERATOR *****
  class Iterator {
    private:
      Node<T1, T2> *cur;
    public:
      Iterator(Node<T1, T2> *first) : cur(first) {}
      // дописать перегрузку операторов для арифметики указателей
  };


  void Print() {
    TreePrint(Root);
    std::cout << std::endl;
  }

  // пока Iterator, потом ЗАМЕНИТЬ НА СВОЙ!!
  // std::pair<class BinaryTree<T1, T2>::Iterator, bool> 
  void Insert(T1 key, T2 value) {
    // bool result_insert = 
    InsertElement(key, value);
    // std::pair<Iterator, bool> return_value;
    // return_value.first = Find(key);
    // return_value.second = result_insert;
    // return return_value;
  }

  bool InsertElement(T1 key, T2 value) {
    bool flag_identic_key = false;
    bool return_value = false;
    Node<T1, T2> **cur = &Root;                // храним адрес УКАЗАТЕЛЯ на узел
    while (*cur && !flag_identic_key) {        // пока корень не пустой
      Node<T1, T2> &node = **cur;              // создаем ссылку на адрес УКАЗАТЕЛЯ на узел
      if (key < node.Key) {
        cur = &node.Left;                      // берем адрес УКАЗАТЕЛЯ на левый узел
      } else if (key > node.Key) {
        cur = &node.Right;                    // берем адрес УКАЗАТЕЛЯ на правый узел
      } else {
        flag_identic_key = true;
      }
    }
    if (!flag_identic_key) {
      *cur = new Node(key, value);               // меняем указатель на новую ноду
      if (*cur) return_value = true;
      ++Size;
    }  
    return return_value;  
  }

  // ПЕРЕПИСАТЬ
  void Erase(T1 key) {
    Node<T1, T2> *cur = Root;
    Node<T1, T2> *parent = NULL;
    while (cur && cur->Key != key) {
      parent = cur;
      if (cur->Key > key)
        cur = cur->Left;
      else
        cur = cur->Right;
    }
    if (!cur) return;
    if (cur->Left == NULL) {
      // Вместо cur подвешивается его правое поддерево
      if (parent && parent->Left == cur)
        parent->Left = cur->Right;
      if (parent && parent->Right == cur)
        parent->Right = cur->Right;
      --Size;
      delete cur;
      return;
    }
    if (cur->Right == NULL) {
      // Вместо cur подвешивается его левое поддерево
      if (parent && parent->Left == cur)
        parent->Left = cur->Left;
      if (parent && parent->Right == cur)
        parent->Right = cur->Left;
      --Size;
      delete cur;
      return;
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    Node<T1, T2> *replace = cur->Right;
    while (replace->Left)
      replace = replace->Left;
    int replace_value = replace->Key;
    Erase(replace_value);
    cur->Key = replace_value;
  }

  typename BinaryTree<T1, T2>::Iterator Find(const T1 key) {
    Node<T1, T2> *cur = Root;
    while (cur && cur->Key != key) {
      if (cur->Key > key)
        cur = cur->Left;
      else
        cur = cur->Right;
    }
    return Iterator(cur);
  }

private:
  void DestroyTree(Node<T1, T2> *node) {
    if (node) {
      DestroyTree(node->Left);
      DestroyTree(node->Right);
      delete node;
    } 
  }

  void TreePrint(Node<T1, T2> *node){
    if (node!=NULL) {
      TreePrint(node->Left);
      std::cout << node->Key << " ";
      TreePrint(node->Right);
    }
  }

  Node<T1, T2>* GetMin(Node<T1, T2>* root) {
    Node<T1, T2> *cur = root;
    while (cur && cur->Left) {
      cur = cur->Left;
    }
    return cur;
  }

  Node<T1, T2>* GetMax(Node<T1, T2>* root) {
    Node<T1, T2> *cur = root;
    while (cur && cur->Right) {
      cur = cur->Right;
    }
    return cur;
  }

};
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
