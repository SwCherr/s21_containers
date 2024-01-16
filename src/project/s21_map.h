#ifndef __CPP2_S21_CONTAINERS_SRC_MAP_H__
#define __CPP2_S21_CONTAINERS_SRC_MAP_H__

namespace s21 {
template<class Key, class Value>
class map : public BinaryTree<Key, Value> {
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

  // std::pair<iterator, bool> insert(const value_type& value);
};

template<class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i!= items.end(); i++)
    BinaryTree<Key, Value>::Insert(*i);
}

} // namespace s21
#endif  // __CPP2_S21_CONTAINERS_SRC_MAP_H__
