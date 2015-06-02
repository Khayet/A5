#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "List.hpp"

TEST_CASE("list", "aufgabe1") {
  List<int> l1;
  l1.push_front(45);
  REQUIRE(l1.size() == 0);
  REQUIRE(l1.empty() == true);
} 

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}