#ifndef S21_CONTAINERS_1_SRC_S21_VECTOR_H
#define S21_CONTAINERS_1_SRC_S21_VECTOR_H

#include <iostream>

namespace s21 {

template <class T>
class vector {
 public:
  using type_name = T;

  size_t size() const;
  void resize(size_t new_size);

  size_t capacity() const;
  void reserve(size_t naw_capacity);

  void push_back(const T& value);

 private:
  T* arr_;
  size_t size_;
  size_t capacity_;
};

template <class T>
void vector<T>::push_back(const T& value) {
  if (size_ >= capacity_) {
    reserve(capacity_ * 2);
  }
  new (arr_ + size_) T(value);
  // put new element on it`s place
}

}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_VECTOR_H
