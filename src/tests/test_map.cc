// #include "test.h"

// TEST(map, ConstructorDefaultMap) {
//   s21::map<int, char> my_empty_map;
//   std::map<int, char> orig_empty_map;
//   EXPECT_EQ(my_empty_map.empty(), orig_empty_map.empty());
// }

// TEST(map, ConstructorInitializerMap) {
//   s21::map<int, char> my_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
//   std::map<int, char> orig_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
//   EXPECT_EQ(my_map.size(), orig_map.size());
//   // auto my_it = my_map.begin();
//   // auto orig_it = orig_map.begin();
//   // for (; my_it != my_map.end(); ++my_it, ++orig_it) {
//   //   EXPECT_TRUE((*my_it).first == (*orig_it).first);
//   //   EXPECT_TRUE((*my_it).second == (*orig_it).second);
//   // }
// }

// // TEST(map, test_class_map_string_1) {
// //   s21::map<std::string, unsigned> map_test {{"This", 0}, {"is", 1}, {"my", 2}};
// //   std::map<std::string, unsigned> orig_map {{"This", 0}, {"is", 1}, {"my", 2}};
// //   auto map_it = map_test.begin();
// //   auto orig_it = orig_map.begin();
// //   for (size_t i = 0; i < map_test.size(); ++i) {
// //     EXPECT_TRUE(*orig_it == *map_it);
// //     if (map_it != map_test.end()) 
// //       ++map_it;
// //       ++orig_it;
// //   }
// //   ASSERT_EQ(map_test.size(), orig_map.size());
// // }