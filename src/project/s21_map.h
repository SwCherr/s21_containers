#ifndef __CPP2_S21_CONTAINERS_SRC_MAP_H__
#define __CPP2_S21_CONTAINERS_SRC_MAP_H__

#include "binary_tree.h"

namespace s21 {
template<class Key, class Value>
class map: public BTree<Key, Value> {
public:
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BTree<Key, Value>::iterator;
  using const_iterator = typename BTree<Key, Value>::const_iterator;
  using size_type = size_t;

  map() : BTree<Key, Value>() {};
  map(std::initializer_list<value_type> const &items);
  map(const map &s) : BTree<Key, Value>(s) {};           // copy constructor
  map(map &&s) = default;                                     // move constructor
  ~map() = default;
  map& operator=(map &&s);

  // В этой таблице перечислены публичные методы для доступа к элементам класса:
  Value& at(const Key& key);
  Value& operator[](const Key& key);

  // В этой таблице перечислены публичные методы для изменения контейнера:
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const Value& value);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const Value& value);
};

template<class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BTree<Key, Value>::Insert(i->first, i->second);
}

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const value_type& value) {
  std::pair<iterator, bool> return_res;
  if (!BTree<Key, Value>::contains(value.first)) 
    return_res = BTree<Key, Value>::Insert(value.first, value.second);
  else {
    return_res.first = iterator(nullptr);
    return_res.second = false;
  }
  return return_res;
}

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const Key& key, const Value& value) {
  std::pair<iterator, bool> return_res;
  if (!BTree<Key, Value>::contains(key)) 
    return_res = BTree<Key, Value>::Insert(key, value);
  else {
    return_res.first = iterator(nullptr);
    return_res.second = false;
  }
  return return_res;
}

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert_or_assign(const Key& key, const Value& value) {
  return BTree<Key, Value>::Insert(key, value);;
}

template<class Key, class Value>
Value& map<Key, Value>::at(const Key& key) {
  return BTree<Key, Value>::find(key).second();
}

template<class Key, class Value>
Value& map<Key, Value>::operator[](const Key& key) {
  iterator cur_it = BTree<Key, Value>::begin();
  size_type i = 0;
  while (key != cur_it.first() && i < BTree<Key, Value>::size()) {
    ++cur_it;
    ++i;
  }
  return cur_it.second();
}
} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_MAP_H__
