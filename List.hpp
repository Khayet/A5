#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>
#include <iterator>

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
public:
  typedef ListIterator<T> Self;
  typedef ListNode<T> Node;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  friend class List<T>;

  ListIterator() : m_node(nullptr) {}
  ListIterator(ListNode<T>* n) : m_node(n) {}
  reference operator*() const { return m_node->m_value; }
  pointer operator->() const { return &(m_node->m_value); }
  Self& operator++() { 
    if (m_node != nullptr) {
      m_node = m_node->m_next;
    }
    return *this;
  }

  Self operator++(int) { 
    ListIterator temp{*this}; 
    ++(*this);
    return temp;
  }

  bool operator==(const Self& x) const { return (m_node == x.m_node); }
  bool operator!=(const Self& x) const { return (m_node != x.m_node); }
  Self next() const
  {
    if (m_node)
      return ListIterator(m_node->m_next);
    else
      return ListIterator(nullptr);
  }

private:
  // The Node the iterator is pointing to 
  ListNode<T>* m_node;
};


template <typename T>
struct ListConstIterator
{
  typedef ListConstIterator<T> Self;
  typedef ListNode<T> Node;
  typedef T value_type;
  typedef T* pointer;
  typedef T const& reference;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  friend class List<T>;

  ListConstIterator() : m_node(nullptr) {}
  ListConstIterator(ListNode<T>* n) : m_node(n) {}
  reference operator*() const { return m_node->m_value; }
  pointer operator->() const { return &(m_node->m_value); }
  Self& operator++() {
    if (m_node != nullptr) 
      m_node = m_node->m_next;
    
    return *this;
  }

  Self operator++(int) {
    if (m_node != nullptr) 
      m_node = m_node->m_next;
    
    return this;
  }

  bool operator==(const Self& x) const { return (m_node == x.m_node); }
  bool operator!=(const Self& x) const { return (m_node != x.m_node); }
  Self next() const
  {
    if (m_node)
      return ListConstIterator(m_node->m_next);
    else
      return ListConstIterator(nullptr);
  }

private:
  ListNode<T>* m_node; 
};


template <typename T>
class List
{
public:
  List() : m_size{0}, m_first{nullptr}, m_last{nullptr} {}
  
  //copy ctor
  List(List const& l) : m_size{0}, m_first{nullptr}, m_last{nullptr} {
    for (auto i : l) {
      push_back(i);
    }
  }

  //move ctor
  List(List&& l) : m_size{l.m_size}, m_first{l.m_first}, m_last{l.m_last} {
    
    l.m_size = 0;
    l.m_first = nullptr;
    l.m_last = nullptr;

    std::cout << "move constructed! \n";
  }

  ~List() { clear(); }

  bool empty() const { return m_size == 0; }
  std::size_t size() const { return m_size; }

  void push_front(T const& v) {
    ListNode<T>* ln = new ListNode<T>{v, nullptr, m_first};

    if (size() > 0) 
      m_first->m_prev = ln;

    if (empty()) 
      m_last = ln;

    m_first = ln;
    ++m_size;
  };

  void push_back(T const& v) {   
    ListNode<T>* ln = new ListNode<T>{v, m_last, nullptr};

    if (size() > 0) 
      m_last->m_next = ln;

    if (empty()) 
      m_first = ln;

    m_last = ln;
    ++m_size;
  }

  void pop_front() {
    if (!empty()) {

      if (size() > 1) {
        ListNode<T>* newFirst = m_first->m_next;
        newFirst->m_prev = nullptr;
        delete m_first;
        m_first = newFirst;
      } else { //size==1
        delete m_first;
        m_first = nullptr;       
      }

      --m_size;
    }
  }

  void pop_back() {
    if (!empty()) {

      if (size() > 1) {
        ListNode<T>* newLast = m_last->m_prev;
        newLast->m_next = nullptr;
        delete m_last;
        m_last = newLast;
      } else {
        delete m_last;
        m_last = nullptr;
      }

      --m_size;
    }
  }

  T& front() const {
    if (!empty()) 
      return m_first->m_value; 
  }

  T& back() const {
    if (!empty()) 
      return m_last->m_value;
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  ListIterator<T> begin() const {
    return ListIterator<T>{m_first};
  }

  ListIterator<T> end() const {
    return ListIterator<T>{};
  }

  ListConstIterator<T> cbegin() const {
    return ListConstIterator<T>{m_first};
  }

  ListConstIterator<T> cend() const {
    return ListConstIterator<T>{};
  }

private:
  std::size_t m_size;
  ListNode<T>* m_first;
  ListNode<T>* m_last;
};


template<typename T>
bool operator==(List<T> const& xs, List<T> const& ys) {

  if (xs.size() != ys.size())
    return false;

  ListConstIterator<T> it1 = xs.cbegin();
  ListConstIterator<T> it2 = ys.cbegin();

  for (ListConstIterator<T> i = xs.cbegin(); i != xs.cend(); ++i) {
    if (*i != *it2) 
      return false;
    ++it2;
  }

  return true;
}

#endif // #define BUW_LIST_HPP