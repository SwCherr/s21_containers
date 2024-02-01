#ifndef CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTOR_S21_STACK_H_
#define CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTOR_S21_STACK_H_

#include <deque>

#include "s21_container_adaptor.h"

namespace s21 {

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

  reference top();
  const_reference top() const;
  void pop() override;
  void push(const_reference value) override;

  stack operator=(const stack &other);
  bool operator==(const stack &other) const;
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
typename stack<T, C>::reference stack<T, C>::top() {
  return this->container_.back();
}

template <class T, class C>
typename stack<T, C>::const_reference stack<T, C>::top() const {
  return this->container_.back();
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
stack<T, C> stack<T, C>::operator=(const stack &other) {
  this->container_ = other.container_;
  return *this;
}

template <class T, class C>
bool stack<T, C>::operator==(const stack &other) const {
  return this->container_ == other.container_;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_CONTAINER_ADAPTOR_S21_STACK_H_
