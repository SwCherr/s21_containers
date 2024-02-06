#ifndef CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_ARRAY_ITERATOR_
#define CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_ARRAY_ITERATOR_

#include <cstddef>

namespace s21 {

template <class T>
class ArrayIterator {
 public:
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using size_type = std::size_t;
  using iterator = ArrayIterator<T>;
  using const_iterator = const ArrayIterator<T>;

  ArrayIterator(pointer arr_ptr) : arr_ptr_(arr_ptr), position_(0) {}
  ArrayIterator(pointer arr_ptr, size_type size)
      : arr_ptr_(arr_ptr), position_(size) {}

  bool operator!=(const ArrayIterator &other) const {
    return !(this->arr_ptr_ == other.arr_ptr_);
  }
  bool operator==(const ArrayIterator &other) const {
    return this->arr_ptr_ == other.arr_ptr_;
  }

  pointer operator->() const { return arr_ptr_; }

  iterator operator++() {
    ++position_;
    return *this;
  }

  iterator operator++(int) {
    iterator tmp(arr_ptr_, ++position_);
    return tmp;
  }

  const_iterator operator++(int) const {
    size_type new_pos = position_ + 1;
    iterator tmp(arr_ptr_, new_pos);
    return tmp;
  }

  iterator operator+(int index) {
    position_ += index;
    return *this;
  }

  iterator operator-(int index) {
    position_ -= index;
    return *this;
  }

  size_type operator-(const ArrayIterator &other) const {
    return position_ - other.position_;
  }

  iterator operator--() {
    --position_;
    return *this;
  }

  iterator operator--(int) {
    iterator tmp(arr_ptr_, --position_);
    return tmp;
  }

  const_iterator operator--(int) const {
    size_type new_pos = position_ - 1;
    iterator tmp(arr_ptr_, new_pos);
    return tmp;
  }

  reference operator*() const { return *(arr_ptr_ + position_); }

 private:
  pointer arr_ptr_;
  size_type position_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_ARRAY_ITERATOR_
