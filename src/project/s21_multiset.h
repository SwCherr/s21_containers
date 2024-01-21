#ifndef __CPP2_S21_CONTAINERS_SRC_multiset_H__
#define __CPP2_S21_CONTAINERS_SRC_multiset_H__

#include "binary_tree.h"

namespace s21 {
// class multisetContainer {}; // общий класс для множеств
// class Multimultiset: public multisetContainer {}; // допка - заглушка

template<class Key>
class multiset: public BTree<Key, Key> {
public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BTree<Key, Key>::iterator;
  using const_iterator = typename BTree<Key, Key>::const_iterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Key>::Node;

  multiset() : BTree<Key, Key>() {};
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &s) : BTree<Key, Key>(s) {};           // copy constructor
  multiset(multiset &&s) = default;                                   // move constructor
  ~multiset() = default;
  multiset& operator=(multiset &&s);

  std::pair<iterator, bool> insert(const value_type& value);
  bool InsertElement(Key key, Key value);

  size_type count(const Key& key);
  std::pair<iterator,iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);
};

template<class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BTree<Key, Key>::Insert(*i, *i);
}

template <class Key>
multiset<Key>& multiset<Key>::operator=(multiset &&s) {
  if (this != &s)
    BTree<Key, Key>::operator=(std::move(s));
  return *this;
}

template <class Key>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::insert(const value_type& value) {
  return BTree<Key, Key>::Insert(value, value);
}

template<class Key>
bool multiset<Key>::InsertElement(Key key, Key value) {
  bool return_value = false;
  Node **cur = &(BTree<Key, Key>::Root);
  Node *parent = nullptr;
  while (*cur) {
    Node &node = **cur;
    parent = *cur;
    if (key <= node.Key)
      cur = &node.Left;
    else if (key > node.Key)
      cur = &node.Right;
  }
  *cur = new Node(key, value); 
  if (*cur) {
    (*cur)->Parent = parent;
    return_value = true;
    BTree<Key, Key>::Size++;
  }
  return return_value;  
}

template<class Key>
typename multiset<Key>::size_type multiset<Key>::count(const Key& key) {
  int count = 0;
  for (auto cur = this->begin(); cur != this->end(); ++cur) {
    if (key == cur.first())
      ++count;
  }
  return count;
}

} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_multiset_H__
