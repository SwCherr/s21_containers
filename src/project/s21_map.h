#ifndef __CPP2_S21_CONTAINERS_SRC_MAP_H__
#define __CPP2_S21_CONTAINERS_SRC_MAP_H__

#include "binary_tree.h"

namespace s21 {
template<class Key, class Value>
class map: public BTree<Key, Value> {
public:
  class MapIterator;
  class ConstMapIterator;
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = MapIterator;
  using const_iterator = ConstMapIterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Value>::Node;

  map() : BTree<Key, Value>() {};
  map(std::initializer_list<value_type> const &items);
  map(const map &s) : BTree<Key, Value>(s) {};
  map(map &&s) = default;
  ~map() = default;
  map& operator=(map &&s);

  iterator begin();
  iterator end();
  const iterator begin() const;
  const iterator end() const;
  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);
  std::pair<iterator, bool> insert(const_reference value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& value);
  std::pair<iterator, bool> insert_or_assign(const key_type& key, const mapped_type& value);
  // std -> s21 change
  template <class... Args>
  std::vector<std::pair<iterator,bool>> insert_many(Args&&... args);

  class MapIterator : public BTree<Key, Value>::Iterator {
  public:
    friend class map;
    MapIterator() : BTree<Key, Value>::Iterator(){};
    MapIterator(Node* node): BTree<Key, Value>::Iterator(node){};
    std::pair<Key, Value>& operator*();
  };

  class ConstMapIterator : public MapIterator {
   public:
    friend class map;
    ConstMapIterator() : MapIterator(){};
    ConstMapIterator(Node *node): MapIterator(node){};
    const_reference operator*() const { return MapIterator::operator*(); };
  };
};

template<class Key, class Value>
template <class... Args>
std::vector<std::pair<typename map<Key, Value>::iterator,bool>> map<Key, Value>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator,bool>> insert_results{};
  for (const auto &arg : {args...})
    insert_results.push_back(insert(arg));
  return insert_results;
}

// ---------------- ITERATOR -----------------
// ---------------- Operator -----------------
template<class Key, class Value>
std::pair<Key, Value>& map<Key, Value>::iterator::operator*() {
  static std::pair<key_type, mapped_type> it_element;
  it_element.first = BTree<Key, Value>::iterator::cur->Key;
  it_element.second = BTree<Key, Value>::iterator::cur->Value;
  return it_element;
}

template<class Key, class Value>
typename map<Key, Value>::mapped_type& map<Key, Value>::operator[](const Key& key) {
  auto cur_it = begin();
  size_type i = 0;
  while (key != (*cur_it).first && i < BTree<Key, Value>::size()) {
    ++cur_it;
    ++i;
  }
  return (*cur_it).second;
}

// ---------------- MAP -----------------
// --------- Constructor & destructor --------
template<class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BTree<Key, Value>::BTInsert(i->first, i->second);
}

// ----------------- Methods -----------------
template<class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::begin() { 
  return iterator(BTree<Key, Value>::BTGetMin(BTree<Key, Value>::Root));
}

template<class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::end() { 
  return iterator(BTree<Key, Value>::BTGetMax(BTree<Key, Value>::Root)->Right);
}

template<class Key, class Value>
const typename map<Key, Value>::iterator map<Key, Value>::begin() const { 
  return iterator(BTree<Key, Value>::BTGetMin(BTree<Key, Value>::Root));
}

template<class Key, class Value>
const typename map<Key, Value>::iterator map<Key, Value>::end() const { 
  return iterator(BTree<Key, Value>::BTGetMax(BTree<Key, Value>::Root)->Right);
}

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const_reference value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = nullptr;
  if (!BTree<Key, Value>::contains(value.first))
    insert_node = BTree<Key, Value>::BTInsert(value.first, value.second);
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
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const key_type& key, const mapped_type& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = nullptr;
  if (!BTree<Key, Value>::contains(key))
    insert_node = BTree<Key, Value>::BTInsert(key, value);
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
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert_or_assign(const key_type& key, const mapped_type& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = BTree<Key, Value>::BTInsert(key, value);
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
  Node *cur = BTree<Key, Value>::Root;
  while (cur && cur->Key != key) {
    if (cur->Key > key)
      cur = cur->Left;
    else
      cur = cur->Right;
  }
  return cur->Value;
}
} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_MAP_H__
