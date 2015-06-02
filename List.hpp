#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>

template <typename T>
struct List;

template <typename T>
struct ListNode
{
  ListNode() : m_value(), m_prev(nullptr), m_next(nullptr) {}
  ListNode(T const& v, ListNode* prev, ListNode* next)
    : m_value(v), m_prev(prev), m_next(next)
  {}
  T m_value;
  ListNode* m_prev; //
  ListNode* m_next;
};

template <typename T>
struct ListIterator
{
  friend class List<T>;
//not implemented yet
private:
  ListNode<T>* m_node;
};

template <typename T>
struct ListConstIterator
{
public:
//not implemented yet
private:
  ListNode<T>* m_node; 
};

template <typename T>
class List
{
public:
  List() : m_size{0}, m_first{nullptr}, m_last{nullptr} {}
  bool empty() const { return m_size == 0; }
  std::size_t size() const {return m_size; };

  void push_front(T const& v) {
    ++m_size; 
    ListNode<T>* ln = new ListNode<T>{v, nullptr, m_first};
    //m_first->m_prev = ;
    //m_first = ln;
  };

private:
  std::size_t m_size;
  ListNode<T>* m_first;
  ListNode<T>* m_last;
};

#endif // #define BUW_LIST_HPP