#include "test.h"
#include <map>

// ******************** MAP *******************
// --------- Constructor & destructor ---------
// default constructor, creates empty tree
TEST(map, test_class_map_default_constructor) {
  s21::map<int, int> map_test;
  std::map<int, int> map_orig;
  ASSERT_EQ(map_test.size(), map_orig.size());
}

// initializer list constructor
TEST(map, test_class_map_initializer_list_constructor) {
  s21::map<int, char> map_test = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  std::map<int, char> map_orig = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  EXPECT_EQ(map_test.size(), map_orig.size());
  auto map_test_it = map_test.begin();
  auto map_orig_it = map_orig.begin();
  for (; map_test_it != map_test.end(); ++map_test_it, ++map_orig_it) {
    EXPECT_TRUE(map_test_it.first() == (*map_orig_it).first);
    EXPECT_TRUE(map_test_it.second() == (*map_orig_it).second);
  }
}

// // copy constructor
// TEST(map, test_class_map_copy_constructor_1) {
//   s21::map<int, int> map_test_1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
//   s21::map<int, int> map_test_2{map_test_1};
//   EXPECT_EQ(map_test_1.size(), map_test_2.size());
//   auto map_test_1_it = map_test_1.begin();
//   auto map_test_2_it = map_test_2.begin();
//   for (size_t i = 0; i < map_test_1.size(); ++i) {
//     // std::cout << map_test_1_it.first() << " ";
//     // std::cout << map_test_1_it.second() << " | ";
//     // std::cout << map_test_2_it.first() << " ";
//     // std::cout << map_test_2_it.second() << std::endl;
//     EXPECT_TRUE(map_test_1_it.first() == map_test_2_it.first());
//     EXPECT_TRUE(map_test_1_it.second() == map_test_2_it.second());
//     if (map_test_1_it != map_test_1.end()) {
//       ++map_test_1_it;
//       ++map_test_2_it;
//     }
//   } 
// }

// copy constructor
TEST(map, test_class_map_copy_constructor_2) {
  s21::map<int, int> map_test_1;
  s21::map<int, int> map_test_2{map_test_1};
  ASSERT_EQ(map_test_1.size(), map_test_2.size());
}

// move constructor
TEST(map, test_class_map_move_constructor) {
  s21::map<int, int> map_test;
  s21::map<int, int> map_test_2(std::move(map_test));
  const unsigned long check_size = 0;
  ASSERT_EQ(check_size, map_test.size());
}

// // move constructor
// TEST(map, test_class_map_move_constructor_2) {
//   s21::map<int, int> map_test;
//   map_test.insert(15, 1);
//   map_test.insert(9, 2);
//   map_test.insert(12, 3);
//   map_test.insert(11, 3);
//   map_test.insert(13, 3);
//   s21::map<int, int> map_test_2(std::move(map_test));
//   const unsigned long check_size = 0;
//   ASSERT_EQ(check_size, map_test.size());
// }

// ---------------- Operator -----------------
// operator=(map&& o)
TEST(map, test_class_map_operator) {
  s21::map<int, int> map_test;
  s21::map<int, int> map_test_2 = std::move(map_test);
  const unsigned long check_size = 0;
  ASSERT_EQ(check_size, map_test.size());
}

// // operator=(map&& o)
// TEST(map, test_class_map_operator_2) {
//   s21::map<int, int> map_test;
//   map_test.insert(15, 1);
//   map_test.insert(9, 2);
//   map_test.insert(12, 3);
//   map_test.insert(11, 3);
//   map_test.insert(13, 3);
//   s21::map<int, int> map_test_2 = std::move(map_test);
//   const unsigned long check_size = 0;
//   ASSERT_EQ(check_size, map_test.size());
// }

// *************** ITERATOR ***************
// iterator& operator++()
// исправить тест после доработки итератора
TEST(map, test_class_map_iterator_1) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  std::map<int, int> map_orig {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  EXPECT_EQ(map_test.size(), map_orig.size());
  auto map_test_it = map_test.begin();
  auto map_orig_it = map_orig.begin();
  for (; map_test_it != map_test.end(); ++map_test_it, ++map_orig_it) {
    EXPECT_TRUE(map_test_it.first() == (*map_orig_it).first);
    EXPECT_TRUE(map_test_it.second() == (*map_orig_it).second);
  }
}

// исправить тест после доработки итератора
TEST(map, test_class_map_iterator_2) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  std::map<int, int> map_orig {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  EXPECT_EQ(map_test.size(), map_orig.size());
  auto map_test_it = map_test.end();
  auto map_orig_it = map_orig.end();
  --map_orig_it;
  for (size_t i = 0; i < map_test.size() - 1; ++i, --map_test_it, --map_orig_it) {
    // std::cout << map_test_it.first() << " ";
    // std::cout << map_test_it.second() << " | ";
    // std::cout << (*map_orig_it).first << " ";
    // std::cout << (*map_orig_it).second << std::endl;
    EXPECT_TRUE(map_test_it.first() == (*map_orig_it).first);
    EXPECT_TRUE(map_test_it.second() == (*map_orig_it).second);
  }
}


// empty()
TEST(map, test_class_map_empty) {
  s21::map<int, int> map_test{};
  EXPECT_TRUE(map_test.empty());
}

// empty()
TEST(map, test_class_map_empty_2) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  EXPECT_FALSE(map_test.empty());
}

// size()
TEST(map, test_class_map_size_1) {
  s21::map<int, int> map_test {};
  size_t check = 0;
  ASSERT_EQ(map_test.size(), check);
}

// size()
TEST(map, test_class_map_size_2) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  size_t check = 5;
  ASSERT_EQ(map_test.size(), check);
}

// size()
TEST(map, test_class_map_size_3) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  map_test.erase(map_test.begin());
  size_t res = map_test.size();
  size_t check = 4;
  ASSERT_EQ(res, check);
}

// size()
TEST(map, test_class_map_size_4) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  map_test.clear();
  size_t res = map_test.size();
  size_t check = 0;
  ASSERT_EQ(res, check);
}

// max_size()
TEST(map, test_class_map_max_size) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  size_t res = map_test.max_size();
  size_t check = 461168601842738790;
  ASSERT_EQ(res, check);
}

// clear()
TEST(map, test_class_map_clear) {
  s21::map<int, int> map_test {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  map_test.clear();
  EXPECT_TRUE(map_test.empty());
}

// insert()
TEST(map, test_class_map_insert_key_value) {
  s21::map<int, int> map_test;
  std::map<int, int> map_orig {{15, 1}, {9, 2}, {12, 3}, {11, 3}, {13, 3}};
  map_test.insert(15, 1);
  map_test.insert(9, 2);
  map_test.insert(12, 3);
  map_test.insert(11, 3);
  map_test.insert(13, 3);
  EXPECT_EQ(map_test.size(), map_orig.size());
  auto map_test_it = map_test.begin();
  auto map_orig_it = map_orig.begin();
  for (; map_test_it != map_test.end();) {
    EXPECT_TRUE(map_test_it.first() == (*map_orig_it).first);
    EXPECT_TRUE(map_test_it.second() == (*map_orig_it).second);
    if (map_test_it != map_test.end()) {
      ++map_test_it;
      ++map_orig_it;
    }
  }
}

// erase
TEST(map, test_class_map_erase_1) {
  s21::map<int, int> map_test{{1, 10}, {2, 20}, {5, 50}, {6, 60}, {8, 80}};
  auto map_it = map_test.begin();
  map_test.erase(map_it);
  EXPECT_TRUE(map_test.size() == 4);
  EXPECT_FALSE(map_test.contains(1));
}

// erase
TEST(map, test_class_map_erase_2) {
  s21::map<int, int> map_test{{1, 10}, {2, 20}, {5, 50}, {6, 60}, {8, 80}};
  auto map_it = map_test.begin() + 1;
  map_test.erase(map_it);
  map_test.erase(++map_it);
  EXPECT_TRUE(map_test.size() == 3);
  EXPECT_FALSE(map_test.contains(2));
  EXPECT_FALSE(map_test.contains(5));
}

// erase
TEST(map, test_class_map_erase_3) {
  s21::map<int, int> map_test{{1, 10}, {2, 20}, {5, 50}, {6, 60}, {8, 80}};
  auto map_it = map_test.end();
  map_test.erase(map_it);
  EXPECT_TRUE(map_test.size() == 4);
  EXPECT_FALSE(map_test.contains(8));
}

// erase
TEST(map, test_class_map_erase_4) {
  s21::map<int, int> map_test{{1, 10}};
  auto map_it = map_test.begin();
  map_test.erase(map_it);
  EXPECT_TRUE(map_test.size() == 0);
  EXPECT_FALSE(map_test.contains(1));
}

// erase
TEST(map, test_class_map_erase_5) {
  s21::map<int, int> map_test{{}};
  auto map_it = map_test.begin();
  map_test.erase(map_it);
  EXPECT_TRUE(map_test.size() == 0);
}

// swap()
TEST(map, test_class_map_swap) {
  s21::map<int, char> map_test_1{{1, 'a'}, {2, 'b'}, {5, 'c'}, {6, 'd'}, {8, 'e'}};
  s21::map<int, char> map_test_2{{9, 'a'}, {8, 'b'}, {7, 'c'}};
  s21::map<int, char> map_test_res_1{{9, 'a'}, {8, 'b'}, {7, 'c'}};
  s21::map<int, char> map_test_res_2{{1, 'a'}, {2, 'b'}, {5, 'c'}, {6, 'd'}, {8, 'e'}};
  map_test_1.swap(map_test_2);
  auto map_test_it = map_test_1.begin();
  auto map_orig_it = map_test_res_1.begin();
  for (; map_test_it != map_test_1.end(); ++map_test_it, ++map_orig_it) {
    EXPECT_TRUE(map_test_it.first() == map_orig_it.first());
    EXPECT_TRUE(map_test_it.second() == map_orig_it.second());
    if (map_test_it != map_test_1.end()) {
      ++map_test_it;
      ++map_orig_it;
    }
  }
  map_test_it = map_test_2.begin();
  map_orig_it = map_test_res_2.begin();
  for (; map_test_it != map_test_2.end(); ++map_test_it, ++map_orig_it) {
    EXPECT_TRUE(map_test_it.first() == map_orig_it.first());
    EXPECT_TRUE(map_test_it.second() == map_orig_it.second());
    if (map_test_it != map_test_1.end()) {
      ++map_test_it;
      ++map_orig_it;
    }
  }
  EXPECT_TRUE(map_test_1.size() == 3);
  EXPECT_TRUE(map_test_2.size() == 5);
}

// merge()
TEST(map, test_class_map_merge) {
  s21::map<int, char> map_test_1{{1, 'a'}, {2, 'b'}, {5, 'c'}, {6, 'd'}, {8, 'e'}};
  s21::map<int, char> map_test_2{{9, 'a'}, {8, 'b'}, {7, 'c'}};
  s21::map<int, char> map_test_res_1{{1, 'a'}, {2, 'b'}, {5, 'c'}, {6, 'd'}, {8, 'e'}, {9, 'a'}, {8, 'b'}, {7, 'c'}};
  map_test_1.merge(map_test_2);
  auto map_test_it = map_test_1.begin();
  auto map_orig_it = map_test_res_1.begin();
  for (; map_test_it != map_test_1.end(); ++map_test_it, ++map_orig_it) {
    EXPECT_TRUE(map_test_it.first() == map_orig_it.first());
    EXPECT_TRUE(map_test_it.second() == map_orig_it.second());
    if (map_test_it != map_test_1.end()) {
      ++map_test_it;
      ++map_orig_it;
    }
  }
  std::cout << map_test_1.size() << std::endl;
  EXPECT_TRUE(map_test_1.size() == 7);
}


// contains()
TEST(map, test_class_map_contains) {
  s21::map<int, char> map_test{{1, 'a'}, {2, 'b'}, {5, 'c'}, {6, 'd'}, {8, 'e'}};
  EXPECT_TRUE(map_test.contains(1));
  EXPECT_TRUE(map_test.contains(2));
  EXPECT_TRUE(map_test.contains(5));
  EXPECT_TRUE(map_test.contains(6));
  EXPECT_TRUE(map_test.contains(8));
  EXPECT_FALSE(map_test.contains(0));
  EXPECT_FALSE(map_test.contains(0));
  EXPECT_FALSE(map_test.contains(-77));
}
