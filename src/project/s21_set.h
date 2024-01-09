#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

#include "binary_tree.h"

namespace s21 {
// class SetContainer {}; // общий класс для множеств
// class Multiset: public SetContainer {}; // допка - заглушка

template<class T1, class T2>
class set: public BinaryTree<T1, T2> {
public:
  using key_type = T1;                               // первый параметр шаблона
  using value_type = T1;                              // Тип значения ключа (само значение является ключом)
  using reference = value_type &;                       // тип ссылки на элемент
  using const_reference = const value_type &;           // тип ссылки на константу
  using iterator = typename BinaryTree<T1, T2>::iterator;             // тип для итерации по контейнеру
  // using const_iterator = BinaryTree::const_iterator; // тип константы для итерации по контейнеру
  using size_type = size_t;                           // определяет тип размера контейнера (стандартный тип - size_t);
  
  // основные публичные методы для взаимодействия с классом
  // 5 конструкторов и 1 деструктор
  set() : BinaryTree<T1, T2>() {};

  set(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i!= items.end(); i++) {
      BinaryTree<T1, T2>::Insert(*i, 0);
    }
  }

  // set(const set &s);                                    // copy constructor
  // set(const set &s) : BinaryTree<T1, T2>(s) {}
  // set(const set &s) : BinaryTree<T1, T2>(), Root(s.Root), Size(s.Size) {}

  // set(set &&s);                                         // move constructor
  // ~set();                                               // destructor
  // operator=(set &&s);                                   // assignment operator overload for moving object


  // публичные методы для итерирования по элементам класса

  // публичные методы для изменения контейнера
  std::pair<iterator, bool> insert(const value_type& value) {
    return BinaryTree<T1, T2>::Insert(value, 0);
  }

  // исправить ошибку довйного освобождения памяти
  void erase(iterator pos) {
    BinaryTree<T1, T2>::Erase(pos);
  }

  // void swap(set& other)
  // void merge(set& other);

  // + ready? + публичные методы для просмотра контейнера

private:
  // BinaryTree<T1, T2> set_values;
  // T1 value;
};
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
