#ifndef __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
#define __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__

#include <iostream>
#include <set>

namespace s21 {
// ************************************
// ------------ CLASS NODE ------------
// ************************************
template<class T1, class T2>
class Node {
public:
  T1 Key;
  T2 Value;
  Node<T1, T2> *Left;
  Node<T1, T2> *Right;
  Node(T1 key, T2 value);
  void PrintNode(); // удалить при рефракторинге
};

template<class T1, class T2>
Node<T1, T2>::Node(T1 key, T2 value) : Key(key), Value(value), Left(nullptr), Right(nullptr) {}

template<class T1, class T2>
void Node<T1, T2>::PrintNode() { std::cout << Key << std::endl; }

// ************************************
// ------------ CLASS TREE ------------
// ************************************
template<class T1, class T2>
class BinaryTree {
public:
  using size_type = size_t;
  Node<T1, T2> *Root;
  size_type Size;

  BinaryTree();
  // это не копирование а ссылка на один и тот же экземпляр дерева !!! ИСПРАВИТЬ
  BinaryTree(const BinaryTree &other);
  ~BinaryTree();

  // ====== iTERATOR ======
  class iterator {
  public:
    iterator();
    iterator(Node<T1, T2> *first);
    void PrintKey();
    // дописать перегрузку операторов для арифметики указателей
    T1 operator*(); // возвращает поле Key
  protected:
    Node<T1, T2> *cur;
  };

  // методы для итерирования по элементам класса
  iterator begin();
  iterator end();

  // методы для доступа к информации о наполнении контейнера
  bool empty();
  size_type size();
  size_type max_size();

  // методы для изменения контейнера
  void clear();
  std::pair<iterator, bool> Insert(T1 key, T2 value);
  bool InsertElement(T1 key, T2 value);
  void Erase(iterator pos);
  void EraseElement(T1 key);    // ПЕРЕПИСАТЬ

  // + ready? + публичные методы для просмотра контейнера
  iterator find(const T1 key);
  bool contains(const T1& key); // вынести общий код
  void Print();                 // вспомогательные ф-ии

private:
  void DestroyTree(Node<T1, T2> *node);
  void TreePrint(Node<T1, T2> *node);
  Node<T1, T2>* GetMin(Node<T1, T2>* root);
  Node<T1, T2>* GetMax(Node<T1, T2>* root);
};

// template<class T1, class T2>
// BinaryTree<T1, T2>::

// template<class T1, class T2>
// BinaryTree<T1, T2>::


// ---------------- ITERATOR -----------------
// --------- Constructor & destructor --------
template<class T1, class T2>
BinaryTree<T1, T2>::iterator::iterator() : cur(nullptr) {}

template<class T1, class T2>
BinaryTree<T1, T2>::iterator::iterator(Node<T1, T2> *first) : cur(first) {}

// ----------------- Methods -----------------
template<class T1, class T2>
void BinaryTree<T1, T2>::iterator::PrintKey() { std::cout << cur->Key << std::endl; }

template<class T1, class T2>
T1 BinaryTree<T1, T2>::iterator::operator*() { return cur->Key; }

// --------------- BINARY TREE ----------------
// --------- Constructor & destructor ---------
template<class T1, class T2>
BinaryTree<T1, T2>::BinaryTree(): Root(nullptr), Size(0) {};

template<class T1, class T2>
BinaryTree<T1, T2>::BinaryTree(const BinaryTree &other) : Root(other.Root), Size(other.Size) {} 

template<class T1, class T2>
BinaryTree<T1, T2>::~BinaryTree() { DestroyTree(Root); }

// ----------------- Methods -----------------
template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator BinaryTree<T1, T2>::begin() { return BinaryTree::iterator(GetMin(Root)); }

template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator BinaryTree<T1, T2>::end() { return BinaryTree::iterator(GetMax(Root)); }

template<class T1, class T2>
Node<T1, T2>* BinaryTree<T1, T2>::GetMin(Node<T1, T2>* root) {
  Node<T1, T2> *cur = root;
  while (cur && cur->Left) {
    cur = cur->Left;
  }
  return cur;
}

template<class T1, class T2>
Node<T1, T2>* BinaryTree<T1, T2>::GetMax(Node<T1, T2>* root) {
  Node<T1, T2> *cur = root;
  while (cur && cur->Right) {
    cur = cur->Right;
  }
  return cur;
}

template<class T1, class T2>
bool BinaryTree<T1, T2>::empty() {
  return Root == nullptr;
}

template<class T1, class T2>
typename BinaryTree<T1, T2>::size_type BinaryTree<T1, T2>::size() {
  return Size;
}

template<class T1, class T2>
typename BinaryTree<T1, T2>::size_type BinaryTree<T1, T2>::max_size() {
  return 461168601842738790;
}

template<class T1, class T2>
void BinaryTree<T1, T2>::clear() { 
  DestroyTree(Root);
  Root = nullptr;
}

template<class T1, class T2>
std::pair<typename BinaryTree<T1, T2>::iterator, bool> BinaryTree<T1, T2>::Insert(T1 key, T2 value) {
  bool result_insert = InsertElement(key, value);
  std::pair<iterator, bool> return_value;
  return_value.first = find(key);
  return_value.second = result_insert;
  return return_value;
}

template<class T1, class T2>
bool BinaryTree<T1, T2>::InsertElement(T1 key, T2 value) {
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
    if (*cur) {
      return_value = true;
      ++Size;
    }
  }
  return return_value;  
}

template<class T1, class T2>
void BinaryTree<T1, T2>::Erase(iterator pos) {
  EraseElement(*pos);
}

// переписать
template<class T1, class T2>
void BinaryTree<T1, T2>::EraseElement(T1 key) {
  Node<T1, T2> *cur = Root;
  Node<T1, T2> *parent = NULL;
  bool flag_identic_key = false;
  while (cur && !flag_identic_key) {
    parent = cur;
    if (key < cur->Key)
      cur = cur->Left;
    else if (key > cur->Key)
      cur = cur->Right;
    else flag_identic_key = true;
  }
  
  if (flag_identic_key && !cur) {
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
    EraseElement(replace_value);
    cur->Key = replace_value;
  }
}

template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator BinaryTree<T1, T2>::find(const T1 key) {
  Node<T1, T2> *cur = Root;
  while (cur && cur->Key != key) {
    if (cur->Key > key)
      cur = cur->Left;
    else
      cur = cur->Right;
  }
  // добавить перегрузку равно для класса дерева. раскомментировать строчку
  // if (cur->Key != key) *cur = nullptr;
  return iterator(cur);
}

template<class T1, class T2>
bool BinaryTree<T1, T2>::contains(const T1& key) {
  Node<T1, T2> *cur = Root;
  bool return_res = false;
  while (cur && !return_res) {
    if (cur->Key == key) return_res = true;
    else if (cur->Key > key)
      cur = cur->Left;
    else
      cur = cur->Right;
  }
  return return_res;
}

template<class T1, class T2>
void BinaryTree<T1, T2>::DestroyTree(Node<T1, T2> *node) {
  if (node) {
    DestroyTree(node->Left);
    DestroyTree(node->Right);
    delete node;
  } 
}

template<class T1, class T2>
void BinaryTree<T1, T2>::TreePrint(Node<T1, T2> *node){
  if (node!=NULL) {
    TreePrint(node->Left);
    std::cout << node->Key << " ";
    TreePrint(node->Right);
  }
}

template<class T1, class T2>
void BinaryTree<T1, T2>::Print() {
  TreePrint(Root);
  std::cout << std::endl;
}
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
