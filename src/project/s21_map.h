#ifndef __CPP2_S21_CONTAINERS_SRC_MAP_H__
#define __CPP2_S21_CONTAINERS_SRC_MAP_H__

#include "binary_tree.h"

namespace s21 {
template<class Key, class Value>
class map: public BTree<Key, Value> {
public:
  class MapIterator;
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const Key, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator; // typename BTree<Key, Value>::iterator;
  // using iterator = typename BTree<Key, Value>::iterator;
  using const_iterator = typename BTree<Key, Value>::const_iterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Value>::Node;

  map() : BTree<Key, Value>() {};
  map(std::initializer_list<value_type> const &items);
  map(const map &s) : BTree<Key, Value>(s) {};
  map(map &&s) = default;
  ~map() = default;
  map& operator=(map &&s);

  Value& at(const Key& key);
  Value& operator[](const Key& key);
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const Value& value);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const Value& value);

  class MapIterator : public BTree<Key, Value>::Iterator {
  public:
    friend class map;
    MapIterator() : BTree<Key, Value>::Iterator(){};
    MapIterator(Node* node): BTree<Key, Value>::Iterator(node){};
    // std::pair<const Key, Value> &operator*();
  };

  // class ConstMapIterator : public MapIterator {
  //  public:
  //   friend struct map;
  //   ConstMapIterator() : MapIterator(){};
  //   ConstMapIterator(typename BTree<Key, Value>::Node *node,
  //                    typename BTree<Key, Value>::Node *past_node = nullptr)
  //       : MapIterator(node, past_node = nullptr){};
  //   const_reference operator*() const { return MapIterator::operator*(); };
  // };
};

// ---------------- ITERATOR -----------------
// ---------------- Operator -----------------
// template<class Key, class Value>
// std::pair<const Key, Value>& map<Key, Value>::iterator::operator*() {
//   std::pair<const Key, Value> return_value;
//   return_value.first = cur->Key;
//   return_value.second = cur->Value;
//   return return_value;
// }

// ---------------- MAP -----------------
// --------- Constructor & destructor --------
template<class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BTree<Key, Value>::Insert(i->first, i->second);
}

// template<class Key, class Value>
// Key map<Key, Value>::iterator::operator*() {
//   value_type return_value;
//   return_value.first = cur->Key;
//   return_value.second = cur->Value;
//   return return_value;
// }

// ----------------- Methods -----------------
template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const value_type& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = nullptr;
  if (!BTree<Key, Value>::contains(value.first))
    insert_node = BTree<Key, Value>::Insert(value.first, value.second);
  if (insert_node) {
    return_value.first = iterator(insert_node);
    return_value.second = true;
  } else {
    return_value.first = iterator(nullptr);
    return_value.second = false;
  }
  return return_value;
}

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const Key& key, const Value& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = nullptr;
  if (!BTree<Key, Value>::contains(key))
    insert_node = BTree<Key, Value>::Insert(key, value);
  if (insert_node) {
    return_value.first = iterator(insert_node);
    return_value.second = true;
  } else {
    return_value.first = iterator(nullptr);
    return_value.second = false;
  }
  return return_value;
}

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert_or_assign(const Key& key, const Value& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = BTree<Key, Value>::Insert(key, value);
  if (insert_node) {
    return_value.first = iterator(insert_node);
    return_value.second = true;
  } else {
    return_value.first = iterator(nullptr);
    return_value.second = false;
  }
  return return_value;
}


template<class Key, class Value>
Value& map<Key, Value>::at(const Key& key) {
  return BTree<Key, Value>::find(key).second();
}

template<class Key, class Value>
Value& map<Key, Value>::operator[](const Key& key) {
  auto cur_it = BTree<Key, Value>::begin();
  size_type i = 0;
  while (key != cur_it.first() && i < BTree<Key, Value>::size()) {
    ++cur_it;
    ++i;
  }
  return cur_it.second();
}
} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_MAP_H__
