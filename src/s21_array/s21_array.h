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

  // Array Constructors
  array() : size_(N){};
  array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other) noexcept;
  ~array() = default;

  // Array Element acces
  reference at(size_type index);
  value_type front();
  value_type back();
  value_type *data();

  // Array Capacity
  bool empty() { return size_ ? false : true; }
  size_type size() const noexcept { return size_; }
  size_type max_size() const noexcept { return N; }

  // Array Modifiers
  void swap(array &other);
  void fill(const_reference value);

  // Array Iterators
  iterator begin() { return iterator(arr_); }
  iterator end() { return iterator(arr_, size_); }
  const_iterator cbegin() { return const_iterator(arr_); }
  const_iterator cend() { return const_iterator(arr_, size_); }

  // Array Operators
  array operator=(array &&a) noexcept;
  reference operator[](size_t index) { return arr_[index]; }
  value_type operator[](size_t index) const { return arr_[index]; }

 private:
  const size_type size_;
  value_type arr_[N];

};  // class array

// --------------------------------------------------
// Array Constructors
// --------------------------------------------------

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

// --------------------------------------------------
// Array Element acces
// --------------------------------------------------

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type index) {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[index];
}

template <class T, std::size_t N>
typename array<T, N>::value_type array<T, N>::front() {
  return arr_[0];
}

template <class T, std::size_t N>
typename array<T, N>::value_type array<T, N>::back() {
  return arr_[N - 1];
}

template <class T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::data() {
  return arr_;
}

// --------------------------------------------------
// Array Modifiers
// --------------------------------------------------

template <class T, std::size_t N>
void array<T, N>::swap(array &other) {
  if (this != &other) {
    std::swap(arr_, other.arr_);
  }
}

template <class T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill_n(arr_, N, value);
}

// --------------------------------------------------
// Array Operators
// --------------------------------------------------

template <class T, std::size_t N>
array<T, N> array<T, N>::operator=(array &&other) noexcept {
  for (size_t i = 0; i < size_; ++i) {
    arr_[i] = std::move(other.arr_[i]);
  }
  return this;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
