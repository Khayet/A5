#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "List.hpp"

#include <vector>

TEST_CASE("aufgabe1", "[list]") {
  List<int> l1;
  REQUIRE(true == l1.empty());

  l1.push_front(45);
  l1.push_front(0);

  REQUIRE(false == l1.empty());
  REQUIRE(2 == l1.size());
}


TEST_CASE("aufgabe2", "[list]") {
  List<int> l1;

  l1.push_back(222);
  l1.push_front(82);
  l1.push_front(33);

  REQUIRE(3 == l1.size());

  l1.pop_front();
  l1.pop_back();

  REQUIRE(1 == l1.size());
  REQUIRE(82 == l1.front());

  l1.push_back(341); 

  REQUIRE(341 == l1.back());
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

TEST_CASE("aufgabe8", "[insert]") {
  List<int> list;
  
  list.insert(list.begin(), 42);

  list.push_front(3);
  list.insert(list.begin(), 1);

  list.push_back(5);

  list.insert((++list.begin()), 2);

  REQUIRE(list.front() == 1);
  REQUIRE(2 == ((++list.begin()).node())->m_value);
}

TEST_CASE("aufgabe9", "[reverse]") {
  List<int> l1;
  l1.push_front(11);
  l1.push_back(99);

  l1.reverse();

  REQUIRE(99 == l1.front());
  REQUIRE(11 == l1.back());

  List<char> l2;
  l2.push_back('a');
  l2.push_back('l');
  l2.push_back('u');
  l2.push_back('c');
  l2.push_back('a');
  l2.push_back('r');
  l2.push_back('d');

  auto l3 = reverse(l2);

  l2.reverse();
  std::copy(l2.begin(), l2.end(), std::ostream_iterator<char>(std::cout, ""));
}

TEST_CASE("aufgabe11", "[copy]") {
  List<int> l1;
  std::vector<int> v1(4);

  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);

  std::copy(l1.begin(), l1.end(), v1.begin());
}


int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}
