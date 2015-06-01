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
//not implemented yet
private:
  std::size_t m_size;
  ListNode<T>* m_first;
  ListNode<T>* m_last;
};

#endif // #define BUW_LIST_HPP