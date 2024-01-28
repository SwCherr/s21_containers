#ifndef __CPP2_S21_CONTAINERS_SRC_BTree_H__
#define __CPP2_S21_CONTAINERS_SRC_BTree_H__

#include <iostream>
#include <cstdint>

namespace s21 {
template<class T1, class T2>
class BTree {
protected:
  struct Node;

public:
  class Iterator;
  class ConstIterator;
  using key_type = T1;
  using value_type = T2;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;

  BTree();
  BTree(const BTree &o);
  BTree(BTree &&o);
  virtual ~BTree() = 0;
  BTree& operator=(BTree&& o);

  iterator begin();
  iterator end();
  const iterator begin() const;
  const iterator end() const;
  size_type size() const;
  size_type max_size() const;
  bool empty() const;
  void clear();
  void erase(iterator pos);
  void swap(BTree& o);
  void merge(BTree& o);
  bool contains(const key_type& key) const;
  iterator find(const key_type key) const;

  // // вспомогательные ф-ии
  // void Print();

  // ====== ITERATOR ======
  class Iterator {
  public:
    Iterator();
    Iterator(Node *node);
    Iterator& operator++();
    iterator& operator--();
    Iterator& operator+(int count);
    iterator& operator-(int count);
    bool operator!=(const Iterator& o) const;
    bool operator==(const Iterator& o) const;
    key_type& operator*(); // возвращает поле Key
    reference operator~(); // возвращает поле Value
  protected:
    Node *cur;
  };

  class ConstIterator : Iterator {
    ConstIterator() : Iterator(){};
    const_reference operator*() const { return Iterator::operator*(); };
  };
  
protected:
  Node *Root;
  Node* BTGetMin(Node* root) const;
  Node* BTGetMax(Node* root) const;
  Node* BTInsert(key_type key, value_type value);
  Node* BTErase(Node* root, key_type key);

  struct Node {
    key_type Key;
    value_type Value;
    Node *Left;
    Node *Right;
    Node *Parent;
    Node(key_type key, value_type value);
    Node(key_type key, value_type value, Node* parent);
  };

private:
  void DestroyTree(Node *node);
  Node* CopyTree(Node *root, Node *parent);
  void TreePrint(Node *node);
};



// ------------------ NODE -------------------
// --------- Constructor & destructor --------
template<class T1, class T2>
BTree<T1, T2>::Node::Node(T1 key, T2 value) : Key(key), Value(value), Left(nullptr), Right(nullptr), Parent(nullptr) {}

template<class T1, class T2>
BTree<T1, T2>::Node::Node(T1 key, T2 value, Node* parent) : Key(key), Value(value), Left(nullptr), Right(nullptr), Parent(parent) {}

// ---------------- ITERATOR -----------------
// --------- Constructor & destructor --------
template<class T1, class T2>
BTree<T1, T2>::iterator::Iterator() : cur(nullptr) {}

template<class T1, class T2>
BTree<T1, T2>::iterator::Iterator(Node *first) : cur(first) {}

// ---------------- Operator -----------------
template<class T1, class T2>
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator++() {
  if (cur->Right) {
    cur = cur->Right;
    while (cur && cur->Left)
      cur = cur->Left;
  } else if (cur->Parent) {
    Node* tmp_right = cur->Right;
    key_type tmp_key = cur->Key;
    cur = cur->Parent;
    while (tmp_key > cur->Key && cur->Parent)
      cur = cur->Parent;
    if (tmp_key >= cur->Key && cur->Parent == nullptr)
      cur = tmp_right;
  } else cur = cur->Right;
  return *this;
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator+(int count) {
  for (int i = 0; i < count; ++i)
    operator++();
  return *this;
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator--() {
  if (cur) {
    if (cur->Left) {
      cur = cur->Left;
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
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator-(int count) {
  for (int i = 0; i < count; ++i)
    operator--();
  return *this;
}

template<class T1, class T2>
bool BTree<T1, T2>::iterator::operator!=(const iterator& o) const {
  return cur != o.cur;
}

template<class T1, class T2>
bool BTree<T1, T2>::iterator::operator==(const iterator& o) const {
  return cur == o.cur;
}

template<class T1, class T2>
typename BTree<T1, T2>::key_type& BTree<T1, T2>::iterator::operator*() { return cur->Key; }

template<class T1, class T2>
typename BTree<T1, T2>::reference BTree<T1, T2>::iterator::operator~() { return cur->Value; }

// --------------- BINARY TREE ----------------
// --------- Constructor & destructor ---------
template<class T1, class T2>
BTree<T1, T2>::BTree(): Root(nullptr) {};

template<class T1, class T2>
BTree<T1, T2>::BTree(const BTree& o) {
  Root = CopyTree(o.Root, nullptr);
}

template<class T1, class T2>
BTree<T1, T2>::BTree(BTree&& o) : Root(o.Root) {
  o.Root = nullptr;
}

template<class T1, class T2>
BTree<T1, T2>::~BTree() { DestroyTree(Root); }

// ---------------- Operator -----------------
template<class T1, class T2>
BTree<T1, T2>& BTree<T1, T2>::operator=(BTree &&o) {
  if (this != &o) {
    Root = o.Root;
    o.Root = nullptr;
  }
  return *this;
}

// ----------------- Methods -----------------
template<class T1, class T2>
typename BTree<T1, T2>::iterator BTree<T1, T2>::begin() { return BTree::iterator(BTGetMin(Root)); }

template<class T1, class T2>
typename BTree<T1, T2>::iterator BTree<T1, T2>::end() { return BTree::iterator(BTGetMax(Root)->Right); }

template<class T1, class T2>
const typename BTree<T1, T2>::Iterator BTree<T1, T2>::begin() const {
  return BTree::iterator(BTGetMin(Root));
}

template<class T1, class T2>
const typename BTree<T1, T2>::Iterator BTree<T1, T2>::end() const {
  return BTree::iterator(BTGetMax(Root)->Right);
}

template<class T1, class T2>
typename BTree<T1, T2>::Node* BTree<T1, T2>::BTGetMin(Node* root) const {
  Node *min = root;
  while (min && min->Left)
    min = min->Left;
  return min;
}

template<class T1, class T2>
typename BTree<T1, T2>::Node* BTree<T1, T2>::BTGetMax(Node* root) const {
  Node *max = root;
  while (max && max->Right)
    max = max->Right;
  return max;
}

template<class T1, class T2>
bool BTree<T1, T2>::empty() const {
  return Root == nullptr;
}

template<class T1, class T2>
typename BTree<T1, T2>::size_type BTree<T1, T2>::size() const {
  size_type size = 0;
  if (Root)
    for (auto iter = begin(); iter != end(); ++iter, ++size);
  return size;
}

template<class T1, class T2>
typename BTree<T1, T2>::size_type BTree<T1, T2>::max_size() const {
  return SIZE_MAX / sizeof(BTree<T1, T2>);
}

template<class T1, class T2>
void BTree<T1, T2>::clear() { 
  DestroyTree(Root);
  Root = nullptr;
}

template<class T1, class T2>
typename BTree<T1, T2>::Node* BTree<T1, T2>::BTInsert(key_type key, value_type value) {
  bool flag_identic_key = false;
  Node **cur = &Root;
  Node *parent = nullptr;
  while (*cur && !flag_identic_key) {
    Node &node = **cur;
    parent = *cur;
    if (key < node.Key)
      cur = &node.Left;
    else if (key > node.Key)
      cur = &node.Right;
    else
      flag_identic_key = true;
  }
  if (flag_identic_key)
    (*cur)->Value = value;
  else {
    *cur = new Node(key, value);
    if (*cur) {
      (*cur)->Parent = parent;
    }
  }
  return *cur;
}

template<class T1, class T2>
void BTree<T1, T2>::erase(iterator pos) {
  Root = BTErase(Root, *pos);
}

template<class T1, class T2>
typename BTree<T1, T2>::Node* BTree<T1, T2>::BTErase(Node* root, key_type key) {
  if (root) {
    if (key < root->Key)
      root->Left = BTErase(root->Left, key);
    else if (key > root->Key)
      root->Right = BTErase(root->Right, key);
    else if (root->Left && root->Right) {
      root->Key = BTGetMin(root->Right)->Key;
      root->Right = BTErase(root->Right, root->Key);
    } else {
      if (root->Left)
        root = root->Left;
      else if (root->Right)
        root = root->Right;
      else
        root = nullptr;
    }
  }
  return root;
}

template<class T1, class T2>
void BTree<T1, T2>::swap(BTree& o) {
  Node* root_tmp = Root;
  Root = o.Root;
  o.Root = root_tmp;
}

template<class T1, class T2>
void BTree<T1, T2>::merge(BTree& o) {
  if (this != &o && o.Root) {
    for (auto iter = o.begin(); iter != o.end(); ++iter)
      this->BTInsert(*iter, ~iter);
  }
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator BTree<T1, T2>::find(const key_type key) const {
  Node *cur = Root;
  while (cur && cur->Key != key) {
    if (cur->Key > key)
      cur = cur->Left;
    else
      cur = cur->Right;
  }
  return iterator(cur);
}

template<class T1, class T2>
bool BTree<T1, T2>::contains(const key_type& key) const {
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
typename BTree<T1, T2>::Node* BTree<T1, T2>::CopyTree(Node *root, Node *parent) {
  Node* new_node = nullptr;
  if (root)  {
    new_node = new Node(root->Key, root->Value, parent);
    new_node->Left = CopyTree(root->Left, new_node);
    new_node->Right = CopyTree(root->Right, new_node);
  }
  return new_node;
}

template<class T1, class T2>
void BTree<T1, T2>::DestroyTree(Node *node) {
  if (node) {
    DestroyTree(node->Left);
    DestroyTree(node->Right);
    delete node;
  } 
}

template<class T1, class T2>
void BTree<T1, T2>::TreePrint(Node *node){
  if (node != nullptr) {
    TreePrint(node->Left);
    std::cout << node->Key << " ";
    // std::cout << node->Value << std::endl;
    TreePrint(node->Right);
  }
}

// template<class T1, class T2>
// void BTree<T1, T2>::Print() {
//   TreePrint(Root);
//   std::cout << std::endl;
// }
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_BTree_H__
