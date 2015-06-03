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
    ListNode<T>* ln = new ListNode<T>{v, nullptr, m_first};
    if (m_first != nullptr) { m_first->m_prev = ln; }
    m_first = ln;
    ++m_size;
  };

  void push_back(T const& v) {   
    ListNode<T>* ln = new ListNode<T>{v, m_last, nullptr};
    if (m_last != nullptr) { m_last->m_prev = ln; }
    m_last = ln;
    ++m_size;
  }

  void pop_front() {
    if (m_first != nullptr) {

      if (m_first->m_next != nullptr) { //at least two elements
        ListNode<T>* newFirst = m_first->m_next; 
        newFirst->m_prev = nullptr;
        delete m_first;
        m_first = newFirst;
      } else { //only one element in list
        delete m_first;
        m_first = nullptr; 
      }
      --m_size;
    }
  }

  void pop_back() {
    if (m_last != nullptr) {

      if (m_last->m_prev != nullptr) { //at least two elements
        ListNode<T>* newLast = m_last->m_prev;
        newLast->m_next = nullptr;
        delete m_last;
        m_last = newLast;
      } else { //only one element in list
        delete m_last;
        m_last = nullptr;
      }
      --m_size;
    }
  }

  T& front() const {
    return (m_first->m_value); 
  }

  T& back() const {
    return (m_last->m_value);
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

private:
  std::size_t m_size;
  ListNode<T>* m_first;
  ListNode<T>* m_last;
};

#endif // #define BUW_LIST_HPP