#ifndef S21_CONTAINERS_1_SRC_S21_STACK_H_
#define S21_CONTAINERS_1_SRC_S21_STACK_H_

#include <deque>
#include <iostream>
#include <list>
#include <stack>

namespace s21 {

template <class T, class C = std::deque<T>>
class stack {
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
  // stack &operator=(stack &&other);

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  // void swap(stack &other);

 private:
  C container_;
};  // class stack

template <class T, class C>
stack<T, C>::stack(std::initializer_list<value_type> const &items) {
  std::cout << "constructor2 " << typeid(std::list<double>).name() << std::endl;
  for (auto i = items.begin(); i != items.end(); i++) {
    push(*i);
  }
}

template <class T, class C>
stack<T, C>::stack(const stack &other) {
  container_ = other.container_;
}

template <class T, class C>
typename stack<T, C>::const_reference stack<T, C>::top() {
  std::cout << typeid(container_).name() << std::endl;
  return container_.back();
}

template <class T, class C>
bool stack<T, C>::empty() {
  return container_.empty();
}

template <class T, class C>
typename stack<T, C>::size_type stack<T, C>::size() {
  return container_.size();
}

template <class T, class C>
void stack<T, C>::push(const_reference value) {
  container_.push_back(value);
}

template <class T, class C>
void stack<T, C>::pop() {
  container_.pop_back();
}

}  // namespace s21

// #include "s21_stack.sex"

#endif  // S21_CONTAINERS_1_SRC_S21_STACK_H_
