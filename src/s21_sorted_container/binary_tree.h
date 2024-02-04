#ifndef __CPP2_S21_CONTAINERS_SRC_BTree_H__
#define __CPP2_S21_CONTAINERS_SRC_BTree_H__

#include <iostream>
#include <cstdint>

namespace s21 {
template<class T1, class T2>
class BTree {
protected:
  class Node;

public:
  class Iterator;
  using key_type = T1;
  using value_type = T2;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using const_iterator = const Iterator;
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
  void swap(BTree& o) noexcept;
  void merge(const BTree& o);
  bool contains(const key_type& key) const;
  iterator find(const key_type key) const;
  // void Print();   // вспомогательные ф-ии

  class Iterator {
    friend class BTree;
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
    Node *cur_;
  };
  
protected:
  Node *root_;
  Node* BTGetMin(Node* root) const;
  Node* BTGetMax(Node* root) const;
  Node* BTInsert(key_type key, value_type value);
  Node* BTErase(Node* root, key_type key);

  class Node {
  public:
    key_type Key;
    value_type Value;
    Node *Left;
    Node *Right;
    Node *Parent;
    Node(const key_type key, const value_type value);
    Node(const key_type key, const value_type value, Node* parent);
  };

private:
  void DestroyTree(Node *node);
  Node* CopyTree(Node *root, Node *parent);
  void TreePrint(Node *node);
};


// --------------------------------------------------
//  NODE 
// --------------------------------------------------
template<class T1, class T2>
BTree<T1, T2>::Node::Node(const key_type key, const value_type value) : Key(key), Value(value), Left(nullptr), Right(nullptr), Parent(nullptr) {}

template<class T1, class T2>
BTree<T1, T2>::Node::Node(const key_type key, const value_type value, Node* parent) : Key(key), Value(value), Left(nullptr), Right(nullptr), Parent(parent) {}

// --------------------------------------------------
//  ITERATOR 
// --------------------------------------------------
template<class T1, class T2>
BTree<T1, T2>::iterator::Iterator() : cur_(nullptr) {}

template<class T1, class T2>
BTree<T1, T2>::iterator::Iterator(Node *node) : cur_(node) {}

template<class T1, class T2>
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator++() {
  if (!cur_)
    throw std::invalid_argument("Iterator is nullptr");
  if (cur_->Right) {
    cur_ = cur_->Right;
    while (cur_ && cur_->Left)
      cur_ = cur_->Left;
  } else {
    if (!cur_->Parent) {
      cur_ = cur_->Right;
    } else {
      Node *tmp_right = cur_->Right;
      key_type tmp_key = cur_->Key;
      cur_ = cur_->Parent;
      while (tmp_key > cur_->Key && cur_->Parent)
        cur_ = cur_->Parent;
      if (!cur_->Parent) {
        if (tmp_key > cur_->Key) cur_ = tmp_right;
      }
    }
  }
  return *this;
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator+(int count) {
  for (int i = 0; i < count; ++i)
    ++(*this);
  return *this;
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator& BTree<T1, T2>::iterator::operator--() {
  if (!cur_)
    throw std::invalid_argument("Iterator is nullptr");
  if (cur_->Left) {
    cur_ = cur_->Left;
    while (cur_ && cur_->Right)
      cur_ = cur_->Right;
  } else if (cur_->Parent) {
    if (cur_->Key > cur_->Parent->Key)
      cur_ = cur_->Parent;
    else {
      key_type tmp_key = cur_->Key;
      while (tmp_key <= cur_->Key)
        cur_ = cur_->Parent;
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
  return cur_ != o.cur_;
}

template<class T1, class T2>
bool BTree<T1, T2>::iterator::operator==(const iterator& o) const {
  return cur_ == o.cur_;
}

template<class T1, class T2>
typename BTree<T1, T2>::key_type& BTree<T1, T2>::iterator::operator*() { return cur_->Key; }

template<class T1, class T2>
typename BTree<T1, T2>::reference BTree<T1, T2>::iterator::operator~() { return cur_->Value; }

// --------------------------------------------------
//  BINARY TREE 
// --------------------------------------------------
template<class T1, class T2>
BTree<T1, T2>::BTree(): root_(nullptr) {};

template<class T1, class T2>
BTree<T1, T2>::BTree(const BTree& o) {
  root_ = CopyTree(o.root_, nullptr);
}

template<class T1, class T2>
BTree<T1, T2>::BTree(BTree&& o) : root_(o.root_) {
  o.root_ = nullptr;
}

template<class T1, class T2>
BTree<T1, T2>::~BTree() { DestroyTree(root_); }

template<class T1, class T2>
BTree<T1, T2>& BTree<T1, T2>::operator=(BTree &&o) {
  if (this != &o) {
    root_ = o.root_;
    o.root_ = nullptr;
  }
  return *this;
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator BTree<T1, T2>::begin() { return BTree::iterator(BTGetMin(root_)); }

template<class T1, class T2>
typename BTree<T1, T2>::iterator BTree<T1, T2>::end() { return BTree::iterator(BTGetMax(root_)->Right); }

template<class T1, class T2>
const typename BTree<T1, T2>::Iterator BTree<T1, T2>::begin() const {
  return BTree::iterator(BTGetMin(root_));
}

template<class T1, class T2>
const typename BTree<T1, T2>::Iterator BTree<T1, T2>::end() const {
  return BTree::iterator(BTGetMax(root_)->Right);
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
  return root_ == nullptr;
}

template<class T1, class T2>
typename BTree<T1, T2>::size_type BTree<T1, T2>::size() const {
  size_type size = 0;
  if (root_)
    for (auto iter = begin(); iter != end(); ++iter, ++size);
  return size;
}

template<class T1, class T2>
typename BTree<T1, T2>::size_type BTree<T1, T2>::max_size() const {
  return SIZE_MAX / sizeof(BTree<T1, T2>);
}

template<class T1, class T2>
void BTree<T1, T2>::clear() { 
  DestroyTree(root_);
  root_ = nullptr;
}

template<class T1, class T2>
typename BTree<T1, T2>::Node* BTree<T1, T2>::BTInsert(key_type key, value_type value) {
  bool flag_identic_key = false;
  Node **cur_ = &root_;
  Node *parent = nullptr;
  while (*cur_ && !flag_identic_key) {
    Node &node = **cur_;
    parent = *cur_;
    if (key < node.Key)
      cur_ = &node.Left;
    else if (key > node.Key)
      cur_ = &node.Right;
    else
      flag_identic_key = true;
  }
  if (flag_identic_key)
    (*cur_)->Value = value;
  else {
    *cur_ = new Node(key, value);
    if (*cur_) {
      (*cur_)->Parent = parent;
    }
  }
  return *cur_;
}

template<class T1, class T2>
void BTree<T1, T2>::erase(iterator pos) {
  if (pos.cur_ != nullptr) {
    root_ = BTErase(root_, *pos);
  }
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
      Node* tmp = nullptr;
      if (root->Left)
        tmp = root->Left;
      else if (root->Right)
        tmp = root->Right;
      else
        tmp = nullptr;
      delete root;
      root = tmp;
    }
  }
  return root;
}

template<class T1, class T2>
void BTree<T1, T2>::swap(BTree& o) noexcept {
  Node* root_tmp = root_;
  root_ = o.root_;
  o.root_ = root_tmp;
}

template<class T1, class T2>
void BTree<T1, T2>::merge(const BTree& o) {
  if (this != &o && o.root_) {
    for (auto iter = o.begin(); iter != o.end(); ++iter)
      this->BTInsert(*iter, ~iter);
  }
}

template<class T1, class T2>
typename BTree<T1, T2>::iterator BTree<T1, T2>::find(const key_type key) const {
  Node *cur_ = root_;
  while (cur_ && cur_->Key != key) {
    if (cur_->Key > key)
      cur_ = cur_->Left;
    else
      cur_ = cur_->Right;
  }
  return iterator(cur_);
}

template<class T1, class T2>
bool BTree<T1, T2>::contains(const key_type& key) const {
  Node *cur_ = root_;
  bool return_res = false;
  while (cur_ && !return_res) {
    if (cur_->Key == key) return_res = true;
    else if (cur_->Key > key)
      cur_ = cur_->Left;
    else
      cur_ = cur_->Right;
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

// template<class T1, class T2>
// void BTree<T1, T2>::TreePrint(Node *node){
//   if (node != nullptr) {
//     TreePrint(node->Left);
//     std::cout << node->Key << " ";
//     TreePrint(node->Right);
//   }
// }

// template<class T1, class T2>
// void BTree<T1, T2>::Print() {
//   TreePrint(root_);
//   std::cout << std::endl;
// }
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_BTree_H__
