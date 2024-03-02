// Must include the gtest header to use the testing library
#include <gtest/gtest.h>

namespace {
  // We will test this dummy function but you can test
  // any function from any library that you write too.
  int SimpleTest() {  return 42; }

  // int main(){
  //       Test test = Test();
  //       test.test_outpt();
  //       return 0;
  //   }
}

TEST(TestTopic, TrivialEquality) {
  EXPECT_EQ(SimpleTest(), 42);
}

// TEST(TestTopic, TrivialEquality2) {
//   EXPECT_EQ(main(), 0);
// }