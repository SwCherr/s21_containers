#ifndef __CPP2_S21_CONTAINERS_SRC_SET_H__
#define __CPP2_S21_CONTAINERS_SRC_SET_H__

#include "binary_tree.h"

namespace s21 {
// class SetContainer {}; // общий класс для множеств
// class Multiset: public SetContainer {}; // допка - заглушка

template<class TKey, class TValue>
class set: public BinaryTree<TKey, TValue> {
public:
  // внутриклассовые переопределения типов
  using Tkey_type = TKey;                               // первый параметр шаблона
  using value_type = TKey;                              // Тип значения ключа (само значение является ключом)
  using reference = value_type &;                       // тип ссылки на элемент
  using const_reference = const value_type &;           // тип ссылки на константу
  using iterator = typename BinaryTree<TKey, TValue>::Iterator;             // тип для итерации по контейнеру
  // using const_iterator = BinaryTree::const_iterator; // тип константы для итерации по контейнеру
  // using size_type = size_t;                           // определяет тип размера контейнера (стандартный тип - size_t);
  
  // основные публичные методы для взаимодействия с классом
  // 5 конструкторов и 1 деструктор
  set() : BinaryTree<TKey, TValue>() {};

  set(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i!= items.end(); i++) {
      BinaryTree<TKey, TValue>::Insert(*i, 0);
    }
  }

  // set(const set &s);                                    // copy constructor
  set(const set &s) : BinaryTree<TKey, TValue>(s) {}
  // set(const set &s) : BinaryTree<TKey, TValue>(), Root(s.Root), Size(s.Size) {}



  // set(set &&s);                                         // move constructor
  // ~set();                                               // destructor
  // operator=(set &&s);                                   // assignment operator overload for moving object


  // публичные методы для итерирования по элементам класса
  // class Iterator;
  // Iterator begin() { /* some code */ }
  // Iterator end() { /* some code */ }


  // публичные методы для доступа к информации о наполнении контейнера
  // публичные методы для изменения контейнера

  // пока std::iterator<TKey, TValue>, потом ЗАМЕНИТЬ НА СВОЙ!!
  std::pair<std::iterator<TKey, TValue>, bool> insert(const value_type& value) {
    return BinaryTree<TKey, TValue>::Insert(value, 0);
  }


  // публичные методы для просмотра контейнера
  void DataTypeSize();

private:
  // BinaryTree<TKey, TValue> set_values;
  // TKey value;
};
} // namespace s21

#endif  // __CPP2_S21_CONTAINERS_SRC_SET_H__
