#ifndef S21_CONTAINERS_1_SRC_S21_STACK_H_
#define S21_CONTAINERS_1_SRC_S21_STACK_H_

#include <deque>

namespace s21 {

template <class T, class C = std::deque<T>>
class container_adaptor {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  const_reference top();
  bool empty();

 protected:
  C container_;
};

template <class T, class C>
typename container_adaptor<T, C>::const_reference
container_adaptor<T, C>::top() {
  return this->container_.back();
}

template <class T, class C>
bool container_adaptor<T, C>::empty() {
  return container_.empty();
}

template <class T, class C = std::deque<T>>
class stack : public container_adaptor<T, C> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  stack() = default;
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &other);
  stack(stack &&other) noexcept;
  ~stack() = default;

  size_type size();
  void push(const_reference value);
  void swap(stack &other) noexcept;
  void pop();

  stack operator=(const stack &other);
  bool operator==(const stack &other);
};  // class stack

template <class T, class C>
stack<T, C>::stack(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); i++) {
    push(*i);
  }
}

template <class T, class C>
stack<T, C>::stack(const stack &other) {
  this->container_ = other.container_;
}

template <class T, class C>
stack<T, C>::stack(stack &&other) noexcept {
  this->container_ = std::move(other.container_);
}

template <class T, class C>
typename stack<T, C>::size_type stack<T, C>::size() {
  return this->container_.size();
}

template <class T, class C>
void stack<T, C>::push(const_reference value) {
  this->container_.push_back(value);
}

template <class T, class C>
void stack<T, C>::pop() {
  this->container_.pop_back();
}

template <class T, class C>
void stack<T, C>::swap(stack &other) noexcept {
  this->container_.swap(other.container_);
}

template <class T, class C>
stack<T, C> stack<T, C>::operator=(const stack &other) {
  this->container_ = other.container_;
  return *this;
}

template <class T, class C>
bool stack<T, C>::operator==(const stack &other) {
  return this->container_ == other.container_;
}

}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_STACK_H_
