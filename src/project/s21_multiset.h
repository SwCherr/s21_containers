#ifndef __CPP2_S21_CONTAINERS_SRC_multiset_H__
#define __CPP2_S21_CONTAINERS_SRC_multiset_H__

#include "binary_tree.h"

namespace s21 {
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
  multiset(const multiset &s) : BTree<Key, Key>(s) {};
  multiset(multiset &&s) = default;
  ~multiset() = default;
  multiset& operator=(multiset &&s);

  std::pair<iterator, bool> insert(const value_type& value);
  size_type count(const Key& key);
  std::pair<iterator,iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);
};

template<class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    insert(*i);
}

template <class Key>
multiset<Key>& multiset<Key>::operator=(multiset &&s) {
  if (this != &s)
    BTree<Key, Key>::operator=(std::move(s));
  return *this;
}

template <class Key>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::insert(const value_type& value) {
  std::pair<iterator, bool> return_value;
  Node **cur = &(BTree<Key, Key>::Root);
  Node *parent = nullptr;
  while (*cur) {
    Node &node = **cur;
    parent = *cur;
    if (value <= node.Key)
      cur = &node.Left;
    else if (value > node.Key)
      cur = &node.Right;
  }
  *cur = new Node(value, value); 
  if (*cur) {
    return_value.first = iterator(*cur);
    return_value.second = true;
    (*cur)->Parent = parent;
    BTree<Key, Key>::Size++;
  } else {
    return_value.first = iterator(nullptr);
    return_value.second = false;
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

template<class Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator> multiset<Key>::equal_range(const Key& key) {
  std::pair<iterator, iterator> return_value;
  auto cur = this->begin();
  while (cur != this->end() && key != cur.first())
    ++cur;
  return_value.first = iterator(cur);
  while (cur != this->end() && key == cur.first()) {
    return_value.second = iterator(cur);
      ++cur;
  }
  return return_value;
}

template<class Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
  iterator return_value;
  auto cur = this->begin();
  while (cur != this->end() && key != cur.first())
    ++cur;
  return_value = iterator(cur);
  return return_value;
}

template<class Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
  iterator return_value;
  auto cur = this->begin();
  while (cur != this->end() && key >= cur.first())
    ++cur;
  return_value = iterator(cur);
  return return_value;
}
} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_multiset_H__
