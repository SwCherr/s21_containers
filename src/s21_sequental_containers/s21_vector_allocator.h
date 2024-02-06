#ifndef CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_VECTOR_ALLOCATOR_H_
#define CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_VECTOR_ALLOCATOR_H_

#include <cstddef>
#include <iostream>
#include <new>

namespace s21 {

// --------------------------------------------------------
// STRUCT ALLOCATOR
// --------------------------------------------------------

template <class T>
struct allocator {
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  static void* operator new(size_type size) {
    void* ptr = malloc(size);
    if (ptr == nullptr) {
      throw std::bad_alloc();
    }
    return ptr;
  }

  static void operator delete(void* ptr) { free(ptr); }

  pointer allocate(size_type n) {
    return reinterpret_cast<pointer>(
        allocator::operator new(n * sizeof(value_type)));
  }

  void deallocate(pointer ptr, size_type) { allocator::operator delete(ptr); }

  template <class... Args>
  void construct(pointer ptr, const Args&... args) {
    new (ptr) value_type(args...);
  }

  void destroy(pointer ptr) noexcept { ptr->~value_type(); }
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_SEQUENTAL_CONTAINERS_S21_VECTOR_ALLOCATOR_H_
