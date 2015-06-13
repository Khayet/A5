#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "List.hpp"

#include <algorithm>
#include <iterator>

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


TEST_CASE("should be empty after clearing", "[clear]") {
  List<int> list;

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  list.clear();

  REQUIRE(list.empty());
}


TEST_CASE("should be an empty range after default construction", 
  "[begin_end]") {
  List<int> list;
  auto b = list.begin();
  auto e = list.end();
  REQUIRE( b == e );
}

TEST_CASE("provide access to the first element with begin", "[begin]") {
  List<int> list;
  list.push_front(42);
  REQUIRE(42 == *list.begin());
}

TEST_CASE("aufgabe5", "[iterator]") {
  List<int> list;
  REQUIRE(list.end() == ListIterator<int>{});
  REQUIRE(list.begin() == ListIterator<int>{});
}

TEST_CASE("aufgabe6", "[list_comparison]") {
  List<int> l1;
  List<int> l2;

  l1.push_front(42);
  l2.push_front(42);

  l1.push_back(72);
  l2.push_back(72);

  REQUIRE(l1 == l2);
}

TEST_CASE("copy constructor", "[constructor]")  {
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  List<int> list2{list};

  REQUIRE(list == list2);
}

TEST_CASE("move constructor", "[constructor]") {
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List<int> list2(std::move(list));

  REQUIRE(0 == list.size());
  REQUIRE(list.empty());
  REQUIRE(4 == list2.size());
}

TEST_CASE("aufgabe8_insert", "[insert]") {
  List<char> list;
  list.push_front('a');
  list.push_back('c');

  auto it = list.begin();
  ++it;
  for (auto i : list) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;

  list.insert(list.begin(), 'z');

  for (auto i : list) {
    std::cout << i << ", ";
  }
}

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}
