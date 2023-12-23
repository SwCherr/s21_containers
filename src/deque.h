#ifndef S21_CONTAINERS_DEQUE_H_
#define S21_CONTAINERS_DEQUE_H_

namespase s21 {

  template <class T> //
  class deque {
  public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = std::size_t;

    deque();
    ~deque();

  protected:
    struct Node {
      _Map_pointer _M_map;
      size_t _M_map_size;
      iterator _M_start;
      iterator _M_finish;
    };
  };

} // namespase s21
#endif S21_CONTAINERS_DEQUE_H_
