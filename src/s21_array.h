#ifndef CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_

#include <initializer_list>
#include <iostream>

#include "s21_array_iterator.h"

namespace s21 {

template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ArrayIterator<T>;
  using const_iterator = const ArrayIterator<T>;
  using size_type = std::size_t;

  array() : size_(N){};
  array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other) noexcept;
  ~array() = default;

  value_type back();
  value_type front();
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  value_type *data();
  iterator begin();
  iterator end();

  array operator=(array &&a) noexcept;
  reference operator[](size_t index);
  value_type operator[](size_t index) const;

 private:
  const size_type size_;
  value_type arr_[N];

};  // class array

template <class T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : size_(N) {
  if (items.size() > size_) {
    throw std::out_of_range("array::initilized_constructor out of range");
  }
  std::copy(items.begin(), items.end(), arr_);
}

template <class T, std::size_t N>
array<T, N>::array(const array &other) : size_(N) {
  for (size_t i = 0; i < size_; ++i) {
    arr_[i] = other.arr_[i];
  }
}

template <class T, std::size_t N>
array<T, N>::array(array &&other) noexcept : size_(N) {
  for (size_t i = 0; i < size_; ++i) {
    arr_[i] = std::move(other.arr_[i]);
  }
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
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return size_;
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return N;
}

template <class T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::data() {
  return arr_;
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return iterator(arr_);
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return iterator(arr_, size_);
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_t index) {
  return arr_[index];
}

template <class T, std::size_t N>
typename array<T, N>::value_type array<T, N>::operator[](size_t index) const {
  return arr_[index];
}

template <class T, std::size_t N>
array<T, N> array<T, N>::operator=(array &&other) noexcept {
  for (size_t i = 0; i < size_; ++i) {
    arr_[i] = std::move(other.arr_[i]);
  }
  return this;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
