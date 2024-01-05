#ifndef S21_CONTAINERS_1_SRC_S21_CONTAINER_ADAPTOR_H_
#define S21_CONTAINERS_1_SRC_S21_CONTAINER_ADAPTOR_H_

#include <deque>

namespace s21 {

template <class T, class C>
class container_adaptor {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // container_adaptor();
  // ~container_adaptor();

  bool empty();
  size_type size();
  void swap(container_adaptor &other) noexcept;
  virtual void pop() = 0;

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

#endif  // S21_CONTAINERS_1_SRC_S21_CONTAINER_ADAPTOR_H_
