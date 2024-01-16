#ifndef __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
#define __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__

#include <iostream>
#include <set>

namespace s21 {
template<class T1, class T2>
class BinaryTree {
private:
  struct Node;
  struct Iterator;
  struct ConstIterator;

public:
  using key_type = T1;
  using value_type = T2;
  using reference = value_type&;
  using const_reference = const value_type&;           // тип ссылки на константу
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;

  BinaryTree();
  BinaryTree(const BinaryTree &o);
  BinaryTree(BinaryTree &&o);
  ~BinaryTree();
  BinaryTree& operator=(BinaryTree&& o);

  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> Insert(T1 key, T2 value);
  bool InsertElement(T1 key, T2 value);
  void erase(iterator pos);
  void EraseElement(T1 key);    // ПЕРЕПИСАТЬ
  void swap(BinaryTree& o);
  void merge(BinaryTree& o);
  iterator find(const T1 key); // подумать над переносом в дочерний класс сет 
  bool contains(const T1& key); // вынести общий код

  // вспомогательные ф-ии
  void Print();
  void PrintByIterator();
  Node* CopyTree(Node *root, Node *parent);

private:
  Node *Root;
  size_type Size;
  void DestroyTree(Node *node);
  void TreePrint(Node *node);
  Node* GetMin(Node* root);
  Node* GetMax(Node* root);

  // ====== NODE ======
  struct Node {
    T1 Key;
    T2 Value;
    Node *Left;
    Node *Right;
    Node *Parent;
    Node(T1 key, T2 value);
    Node(T1 key, T2 value, Node* parent);
    void PrintNode();             // удалить при рефакторинге
    void PrintNodeParent();       // удалить при рефакторинге
  };

  // ====== ITERATOR ======
  struct Iterator {
    Node *cur;
    Iterator();
    Iterator(Node *first);
    Iterator& operator++();
    Iterator& operator--();
    bool operator!=(const Iterator& o);
    T1 operator*(); // возвращает поле Key
    T2 operator~(); // возвращает поле Value
  };

  struct ConstIterator : Iterator {
    ConstIterator() : Iterator(){};
    const_reference operator*() const { return Iterator::operator*(); };
  };
};

// ------------------ NODE -------------------
// --------- Constructor & destructor --------
template<class T1, class T2>
BinaryTree<T1, T2>::Node::Node(T1 key, T2 value) : Key(key), Value(value), Left(nullptr), Right(nullptr), Parent(nullptr) {}

template<class T1, class T2>
BinaryTree<T1, T2>::Node::Node(T1 key, T2 value, Node* parent) : Key(key), Value(value), Left(nullptr), Right(nullptr), Parent(parent) {}

// ----------------- Methods -----------------
template<class T1, class T2>
void BinaryTree<T1, T2>::Node::PrintNode() { std::cout << Key << std::endl; }

template<class T1, class T2>
void BinaryTree<T1, T2>::Node::PrintNodeParent() {
  if (Parent == nullptr) std::cout << "nullptr" << std::endl;
  else std::cout << Parent->Key << std::endl;
}

// ---------------- ITERATOR -----------------
// --------- Constructor & destructor --------
template<class T1, class T2>
BinaryTree<T1, T2>::iterator::Iterator() : cur(nullptr) {}

template<class T1, class T2>
BinaryTree<T1, T2>::iterator::Iterator(Node *first) : cur(first) {}

// ----------------- Methods -----------------
template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator& BinaryTree<T1, T2>::iterator::operator++() {
  if (cur) {
    if (cur->Right) {
      cur = cur->Right;           // найти минимальное значение в правой подветке cur
      while (cur && cur->Left)
        cur = cur->Left;
    } else if (cur->Parent) {
      if (cur->Key < cur->Parent->Key)
        cur = cur->Parent;
      else {
        T1 tmp_key = cur->Key;
        while (tmp_key >= cur->Key)
          cur = cur->Parent;
      }
    }
  }
  return *this;
}

template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator& BinaryTree<T1, T2>::iterator::operator--() {
  if (cur) {
    if (cur->Left) {
      cur = cur->Left;           // найти минимальное значение в правой подветке cur
      while (cur && cur->Right)
        cur = cur->Right;
    } else if (cur->Parent) {
      if (cur->Key > cur->Parent->Key)
        cur = cur->Parent;
      else {
        T1 tmp_key = cur->Key;
        while (tmp_key <= cur->Key)
          cur = cur->Parent;
      }
    }
  }
  return *this;
}

template<class T1, class T2>
bool BinaryTree<T1, T2>::iterator::operator!=(const iterator& o) {
  return cur != o.cur;
}

template<class T1, class T2>
T1 BinaryTree<T1, T2>::iterator::operator*() { return cur->Key; }

template<class T1, class T2>
T2 BinaryTree<T1, T2>::iterator::operator~() { return cur->Value; }

// --------------- BINARY TREE ----------------
// --------- Constructor & destructor ---------
template<class T1, class T2>
BinaryTree<T1, T2>::BinaryTree(): Root(nullptr), Size(0) {};

template<class T1, class T2>
BinaryTree<T1, T2>::BinaryTree(const BinaryTree& o) : Root(nullptr), Size(o.Size) {
  Root = CopyTree(o.Root, nullptr);
}

template<class T1, class T2>
BinaryTree<T1, T2>::BinaryTree(BinaryTree&& o) : Root(o.Root), Size(o.Size) {
  o.Root = nullptr;
  o.Size = 0;
}

template<class T1, class T2>
BinaryTree<T1, T2>::~BinaryTree() { DestroyTree(Root); }

// ---------------- Operator -----------------
template<class T1, class T2>
BinaryTree<T1, T2>& BinaryTree<T1, T2>::operator=(BinaryTree &&o) {
  if (this != &o) {
    Root = o.Root;
    Size = o.Size;
    o.Root = nullptr;
    o.Size = 0;
  }
  return *this;
}

// ----------------- Methods -----------------
template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator BinaryTree<T1, T2>::begin() { return BinaryTree::iterator(GetMin(Root)); }

template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator BinaryTree<T1, T2>::end() { return BinaryTree::iterator(GetMax(Root)); }

template<class T1, class T2>
typename BinaryTree<T1, T2>::Node* BinaryTree<T1, T2>::GetMin(Node* root) {
  Node *min = root;
  while (min && min->Left) {
    min = min->Left;
  }
  return min;
}

template<class T1, class T2>
typename BinaryTree<T1, T2>::Node* BinaryTree<T1, T2>::GetMax(Node* root) {
  Node *max = root;
  while (max && max->Right) {
    max = max->Right;
  }
  return max;
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
  Node **cur = &Root;                        // сохраняем адрес УКАЗАТЕЛЯ на узел
  Node *parent = nullptr;
  while (*cur && !flag_identic_key) {        // пока корень не пустой
    Node &node = **cur;                      // создаем ссылку на адрес УКАЗАТЕЛЯ на узел
    parent = *cur;
    if (key < node.Key)
      cur = &node.Left;                      // берем адрес УКАЗАТЕЛЯ на левый узел
    else if (key > node.Key)
      cur = &node.Right;                     // берем адрес УКАЗАТЕЛЯ на правый узел
    else
      flag_identic_key = true;
  }
  if (!flag_identic_key) {
    *cur = new Node(key, value);             // меняем указатель на новую ноду
    if (*cur) {
      (*cur)->Parent = parent;
      return_value = true;
      Size++;
    }
  }
  return return_value;  
}

template<class T1, class T2>
void BinaryTree<T1, T2>::erase(iterator pos) {
  EraseElement(*pos);
}

// декомпозировать
template<class T1, class T2>
void BinaryTree<T1, T2>::EraseElement(T1 key) {
  bool flag_identic_key = false;
  Node *cur = Root;
  Node *parent = nullptr;
  while (cur && !flag_identic_key) {
    parent = cur;
    if (key < cur->Key)
      cur = cur->Left;
    else if (key > cur->Key)
      cur = cur->Right;
    else flag_identic_key = true;
  }
  if (flag_identic_key && !cur) {
    if (cur->Left == nullptr) {
      // Вместо cur подвешивается его правое поддерево
      if (parent && parent->Left == cur)
        parent->Left = cur->Right;
      if (parent && parent->Right == cur)
        parent->Right = cur->Right;
      Size--;
      delete cur;
    } else if (cur->Right == nullptr) {
      // Вместо cur подвешивается его левое поддерево
      if (parent && parent->Left == cur)
        parent->Left = cur->Left;
      if (parent && parent->Right == cur)
        parent->Right = cur->Left;
      Size--;
      delete cur;
    } else {
      // У элемента есть два потомка, тогда на место элемента поставим
      // наименьший элемент из его правого поддерева
      Node *replace = cur->Right;
      while (replace->Left)
        replace = replace->Left;
      int replace_value = replace->Key;
      EraseElement(replace_value);
      cur->Key = replace_value;
    }
    cur->Parent = parent;
  }
}


template<class T1, class T2>
void BinaryTree<T1, T2>::swap(BinaryTree& o) {
  Node* root_tmp = Root;
  size_type size_tmp = Size;
  Root = o.Root;
  o.Root = root_tmp;
  Size = o.Size;
  o.Size = size_tmp;
}

template<class T1, class T2>
void BinaryTree<T1, T2>::merge(BinaryTree& o) {
  if (this != &o && o.Root) {
    iterator cur_element_o = o.begin();
    for (size_type i = 0; i < o.Size; ++i) {
      this->Insert(*cur_element_o, ~cur_element_o);
      if (cur_element_o != o.end()) 
        ++cur_element_o;
    }
  }
}

// дописать отсутсвие элемента
template<class T1, class T2>
typename BinaryTree<T1, T2>::iterator BinaryTree<T1, T2>::find(const T1 key) {
  Node *cur = Root;
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
  Node *cur = Root;
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

// ----------------- Support -----------------
template<class T1, class T2>
typename BinaryTree<T1, T2>::Node* BinaryTree<T1, T2>::CopyTree(Node *root, Node *parent) {
  Node* new_node = nullptr;
  if (root != nullptr)  {
    new_node = new Node(root->Key, root->Value, parent);
    new_node->Left = CopyTree(new_node->Left, new_node);
    new_node->Right = CopyTree(new_node->Right, new_node);
  }
  return new_node;
}

template<class T1, class T2>
void BinaryTree<T1, T2>::DestroyTree(Node *node) {
  if (node) {
    DestroyTree(node->Left);
    DestroyTree(node->Right);
    delete node;
  } 
}

template<class T1, class T2>
void BinaryTree<T1, T2>::TreePrint(Node *node){
  if (node != NULL) {
    TreePrint(node->Left);
    std::cout << node->Key << " ";
    // std::cout << node->Key << " - ";
    // (*node).PrintNodeParent();
    TreePrint(node->Right);
  }
}

template<class T1, class T2>
void BinaryTree<T1, T2>::Print() {
  TreePrint(Root);
  std::cout << std::endl;
}

template<class T1, class T2>
void BinaryTree<T1, T2>::PrintByIterator() {
  if (this->Root) {
    iterator cur_element = this->begin();
    for (size_type i = 0; i < Size; ++i) {
      std::cout << *cur_element << std::endl;
      if (cur_element != this->end()) 
        ++cur_element;
    }
  }
}

} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_BINARYTREE_H__
