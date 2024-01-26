#ifndef CPP2_S21_CONTAINERS_SRC_S21_ARRAY_ITERATOR
#define CPP2_S21_CONTAINERS_SRC_S21_ARRAY_ITERATOR

#include <iostream>

namespace s21 {

template <class T>
class ArrayIterator {
 public:
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using size_type = std::size_t;

  ArrayIterator(pointer arr_ptr) : arr_ptr_(arr_ptr), position_(0) {}
  ArrayIterator(pointer arr_ptr, size_type size)
      : arr_ptr_(arr_ptr), position_(size) {}

  bool operator!=(const ArrayIterator &other) const {
    return !(this->arr_ptr_ == other.arr_ptr_);
  }
  bool operator==(const ArrayIterator &other) const {
    return this->arr_ptr_ == other.arr_ptr_;
  }
  ArrayIterator &operator++() {
    ++position_;
    return *this;
  }
  ArrayIterator &operator++(int) {
    ++position_;
    return *this;
  }
  ArrayIterator &operator+(int index) {
    position_ += index;
    return *this;
  }
  ArrayIterator<T> &operator-(int index) {
    position_ -= index;
    return *this;
  }
  size_type operator-(const ArrayIterator &other) const {
    return position_ - other.position_;
  }
  ArrayIterator &operator--() {
    --position_;
    return *this;
  }
  ArrayIterator &operator--(int) {
    --position_;
    return *this;
  }
  reference operator*() const { return *(arr_ptr_ + position_); }

 private:
  pointer arr_ptr_;
  size_type position_;
};

}  // namespace s21

#endif
