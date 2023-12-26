#include "s21_stack.h"

#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <typeinfo>

namespace s21 {

template <class T, class C>
stack<T, C>::stack() {
  std::cout << "constructor " << typeid(std::list<double>).name() << std::endl;
}

template <class T, class C>
stack<T, C>::stack(std::initializer_list<value_type> const& items) {
  std::cout << "constructor2 " << typeid(std::list<double>).name() << std::endl;
  for (auto i = items.begin(); i != items.end(); i++) {
    push(*i);
  }
}

template <class T, class C>
stack<T, C>::~stack() {
  std::cout << "deconstructor" << std::endl;
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

}  // namespace s21

int main() { return 0; }
