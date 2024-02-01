#ifndef CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTOR_S21_CONTAINER_ADAPTOR_H_
#define CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTOR_S21_CONTAINER_ADAPTOR_H_

#include <cstddef>

namespace s21 {

template <class T, class C>
class container_adaptor {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  virtual ~container_adaptor() = default;

  bool empty();
  size_type size();
  void swap(container_adaptor &other) noexcept;
  virtual void pop() = 0;
  virtual void push(const_reference) = 0;

 protected:
  C container_;
};

template <class T, class C>
bool container_adaptor<T, C>::empty() {
  return container_.empty();
}

template <class T, class C>
typename container_adaptor<T, C>::size_type container_adaptor<T, C>::size() {
  return this->container_.size();
}

template <class T, class C>
void container_adaptor<T, C>::swap(container_adaptor &other) noexcept {
  this->container_.swap(other.container_);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTOR_S21_CONTAINER_ADAPTOR_H_
