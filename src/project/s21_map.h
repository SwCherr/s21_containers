#ifndef __CPP2_S21_CONTAINERS_SRC_MAP_H__
#define __CPP2_S21_CONTAINERS_SRC_MAP_H__

namespace s21 {
template<class Key, class Value>
class map: public BinaryTree<Key, Value> {
public:
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<Key, Value>::iterator;
  using const_iterator = typename BinaryTree<Key, Value>::const_iterator;
  using size_type = size_t;

  map() : BinaryTree<Key, Value>() {};
  map(std::initializer_list<value_type> const &items);
  map(const map &s) : BinaryTree<Key, Value>(s) {};           // copy constructor
  map(map &&s) : BinaryTree<Key, Value>(s) {};                // move constructor
  ~map() = default;
  map& operator=(map &&s);

  // В этой таблице перечислены публичные методы для доступа к элементам класса:
  // Value& at(const Key& key);
  // Value& operator[](const Key& key);

  // В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):
  // iterator begin();
  // iterator end();

  // В этой таблице перечислены публичные методы для изменения контейнера:
  // std::pair<iterator, bool> insert(const value_type& value); // +
  std::pair<iterator, bool> insert(const Key& key, const Value& value); // +
  // std::pair<iterator, bool> insert_or_assign(const Key& key, const Value& obj);
  // void erase(iterator pos);
  // void swap(map& other);
  // void merge(map& other);
};



template<class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BinaryTree<Key, Value>::Insert(i->first, i->second);
}

// template<class Key, class Value>
// std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const value_type& value) {
//   return BinaryTree<Key, Value>::Insert(value.first, value.second);
// }

template<class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const Key& key, const Value& value) {
  return BinaryTree<Key, Value>::Insert(key, value);
}

} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_MAP_H__
