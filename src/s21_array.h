#ifndef CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using iterator = T *;
  using const_reference = const T &;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array() = default;
  array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other);
  ~array() = default;

  value_type back();
  value_type front();
  value_type *data();
  iterator begin();
  iterator end();

  reference operator[](value_type index);
  value_type operator[](value_type index) const;

 private:
  value_type arr_[N];
  const size_type size_ = N;
};  // class array

template <class T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  if (items.size() > N) {
    throw std::out_of_range("array::initilized_constructor out of range");
  }
  std::copy(items.begin(), items.end(), arr_);
}

template <class T, std::size_t N>
typename array<T, N>::value_type array<T, N>::back() {
  return arr_[N - 1];
}

template <class T, std::size_t N>
typename array<T, N>::value_type array<T, N>::front() {
  return arr_[0];
}

template <class T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::data() {
  return arr_;
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return &arr_[size_];
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](value_type index) {
  return arr_[index];
}

template <class T, std::size_t N>
typename array<T, N>::value_type array<T, N>::operator[](
    value_type index) const {
  return arr_[index];
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
