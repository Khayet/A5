#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "List.hpp"

TEST_CASE("aufgabe1", "[list]") {
  List<int> l1;
  REQUIRE(l1.empty() == true);

  l1.push_front(45);
  l1.push_front(0);

  REQUIRE(l1.empty() == false);
  REQUIRE(l1.size() == 2);
}


TEST_CASE("aufgabe2", "[list]") {
  List<int> l1;

  l1.push_back(222);
  l1.push_front(82);
  l1.push_front(33);

  REQUIRE(l1.size() == 3);

  l1.pop_front();
  l1.pop_back(); 

  REQUIRE(l1.size() == 1);
  REQUIRE(l1.front() == 82);

  l1.push_back(341);
  REQUIRE(l1.back() == 341);
} 

TEST_CASE("aufgabe3", "[list]") {
  List<int> l1;

  l1.push_front(23);
  l1.push_front(23);
  l1.push_front(23);
  l1.push_front(23);

  l1.clear();

  REQUIRE(l1.empty());
}

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}