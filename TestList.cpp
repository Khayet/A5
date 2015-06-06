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
  std::cout << "back(): " << l1.back() << "\n"; 
  l1.push_front(82);
  l1.push_front(33);


  REQUIRE(l1.size() == 3);

  l1.pop_front();

  std::cout << "size(): " << l1.size() << " ,back(): " << l1.back() << "\n"; 

  l1.pop_back();
  std::cout << "size(): " << l1.size() << " ,back(): " << l1.back() << "\n"; 

  REQUIRE(l1.size() == 1);
  REQUIRE(l1.front() == 82);

  std::cout << "back(): " << l1.back() << "\n";
  l1.push_back(341); 
  std::cout << "line 39 " << l1.size() << "\n";

  REQUIRE(l1.back() == 341); //culprit
  std::cout << "Test case aufgabe2 finished" << std::endl;

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

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}