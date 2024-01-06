#ifndef CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_

#include <initializer_list>

namespace s21 {
template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using iterator = T *;
  using const_reference = const T &;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array() = default;
  array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other);
  ~array() = default;

 private:
  value_type arr_[N];
  size_type size_ = N;
};  // class array

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_ARRAY_H_
