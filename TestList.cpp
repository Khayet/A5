#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "List.hpp"

TEST_CASE("list", "aufgabe1") {
  List<int> l1;
  REQUIRE(l1.empty() == true);

  l1.push_front(45);
  l1.push_front(0);

  REQUIRE(l1.empty() == false);
  REQUIRE(l1.size() == 2);

  l1.push_back(222);

  REQUIRE(l1.size() == 3);

  l1.pop_front();
  l1.pop_back(); 

  REQUIRE(l1.size() == 1);
  REQUIRE(l1.front() == 45);

  l1.push_back(341);
  REQUIRE(l1.back() == 341);
} 

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}