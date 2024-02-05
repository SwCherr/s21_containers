#ifndef __CPP2_S21_CONTAINERS_SRC_MAP_H__
#define __CPP2_S21_CONTAINERS_SRC_MAP_H__

#include "../s21_sequential_container/s21_vector.h"
#include "binary_tree.h"

namespace s21 {
template <class Key, class Value>
class map : public BTree<Key, Value> {
 public:
  class MapIterator;
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = MapIterator;
  using const_iterator = const MapIterator;
  using size_type = size_t;
  using Node = typename BTree<Key, Value>::Node;

  map() : BTree<Key, Value>(){};
  map(std::initializer_list<value_type> const& items);
  map(const map& s) : BTree<Key, Value>(s){};
  map(map&& s) = default;
  ~map() = default;

  iterator begin();
  iterator end();
  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);
  std::pair<iterator, bool> insert(const_reference value);
  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& value);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& value);

  template <class... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  class MapIterator : public BTree<Key, Value>::Iterator {
   public:
    friend class map;
    MapIterator() : BTree<Key, Value>::Iterator(){};
    MapIterator(Node* node) : BTree<Key, Value>::Iterator(node){};
    std::pair<Key, Value>& operator*();
  };
};

// --------------------------------------------------
//  ITERATOR
// --------------------------------------------------
template <class Key, class Value>
std::pair<Key, Value>& map<Key, Value>::iterator::operator*() {
  static std::pair<key_type, mapped_type> it_element;
  it_element.first = BTree<Key, Value>::iterator::cur_->Key;
  it_element.second = BTree<Key, Value>::iterator::cur_->Value;
  return it_element;
}

template <class Key, class Value>
typename map<Key, Value>::mapped_type& map<Key, Value>::operator[](
    const Key& key) {
  auto cur__it = begin();
  size_type i = 0;
  while (key != (*cur__it).first && i < BTree<Key, Value>::size()) {
    ++cur__it;
    ++i;
  }
  return (*cur__it).second;
}

// --------------------------------------------------
//  MAP
// --------------------------------------------------
template <class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const& items) {
  for (auto i = items.begin(); i != items.end(); i++)
    BTree<Key, Value>::BTInsert(i->first, i->second);
}

template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::begin() {
  return iterator(BTree<Key, Value>::BTGetMin(BTree<Key, Value>::root_));
}

template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::end() {
  return iterator(BTree<Key, Value>::BTGetMax(BTree<Key, Value>::root_)->Right);
}

template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(
    const_reference value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = nullptr;
  if (!BTree<Key, Value>::contains(value.first))
    insert_node = BTree<Key, Value>::BTInsert(value.first, value.second);
  return_value.first = iterator(insert_node);
  return_value.second = (insert_node != nullptr);
  return return_value;
}

template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(
    const key_type& key, const mapped_type& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = nullptr;
  if (!BTree<Key, Value>::contains(key))
    insert_node = BTree<Key, Value>::BTInsert(key, value);
  return_value.first = iterator(insert_node);
  return_value.second = (insert_node != nullptr);
  return return_value;
}

template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool>
map<Key, Value>::insert_or_assign(const key_type& key,
                                  const mapped_type& value) {
  std::pair<iterator, bool> return_value;
  Node* insert_node = BTree<Key, Value>::BTInsert(key, value);
  return_value.first = iterator(insert_node);
  return_value.second = (insert_node != nullptr);
  return return_value;
}

template <class Key, class Value>
Value& map<Key, Value>::at(const Key& key) {
  Node* cur_ = BTree<Key, Value>::root_;
  while (cur_ && cur_->Key != key) {
    if (cur_->Key > key)
      cur_ = cur_->Left;
    else
      cur_ = cur_->Right;
  }
  return cur_->Value;
}

template <class Key, class Value>
template <class... Args>
s21::vector<std::pair<typename map<Key, Value>::iterator, bool>>
map<Key, Value>::insert_many(Args&&... args) {
  s21::vector<std::pair<iterator, bool>> insert_results{};
  for (const auto& arg : {args...}) insert_results.push_back(insert(arg));
  return insert_results;
}
}  // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_MAP_H__
