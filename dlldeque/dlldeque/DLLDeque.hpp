#ifndef DLLDEQUE_HPP
#define DLLDEQUE_HPP

#include <iostream>
#include <memory>

// class representing a double-ended queue as a doubly-linked list
template <typename T>
class DLLDeque
{
private:
  // forward declaration for iterator
  struct Node;

  typedef std::shared_ptr<Node> NodeNextPtr;
  // avoid cycles
  typedef std::weak_ptr<Node> NodePrevPtr;
  // the deque should only have one of these, but they will need to be copied to and from so keep shared
  typedef std::shared_ptr<Node> HeadPtr;
  typedef std::shared_ptr<Node> TailPtr;
  typedef std::shared_ptr<Node> IterPtr;

public:
  // iterator over deque
  class iterator
  {
  public:
    iterator(IterPtr n);                 // construct from a Node pointer
    iterator(const iterator &it);        // copy iterator
    iterator &operator++();              // move the iterator to the next item, return new value
    iterator operator++(int);            // move the iterator to the next item, return old value
    T &operator*();                      // dereference to get the current item
    bool operator==(const iterator &it); // compare iterators
    bool operator!=(const iterator &it); // compare iterators

    // types for STL algorithms
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef long difference_type;

  private:
    IterPtr m_node;
  };

  DLLDeque() = default;
  ~DLLDeque() = default;

  bool empty() const;       // return true if the deque is empty, false otherwise
  void debug_print() const; // print the contents of the list to stdout

  void push_front(const T &t); // push an element onto the front of the deque
  void push_back(const T &t);  // push an element onto the back of the deque

  void pop_front(); // pop an element off the front of the deque, does nothing if empty
  void pop_back();  // pop an element off the back of the deque, does nothing if empty

  iterator begin(); // return an iterator to the beginning of the deque
  iterator end();   // return an iterator to the ending of the deque (i.e. "one off the end")

private:
  DLLDeque(const DLLDeque &) = delete;
  DLLDeque &operator=(const DLLDeque &) = delete;
  DLLDeque(DLLDeque &&) = delete;
  DLLDeque &operator=(DLLDeque &&) = delete;

  struct Node
  {
    T item; // item for this node

    NodeNextPtr next; // pointer to next node (null if tail)
    NodePrevPtr prev; // pointer to previous node (null if head)
  };

  HeadPtr m_head; // pointer to head node
  TailPtr m_tail; // pointer to tail node
};

#include "DLLDeque.tmpl.hpp"

template <typename T>
bool DLLDeque<T>::empty() const
{
  return !m_head;
}

// utility functions for display
template <typename U>
char debug_char(U *p)
{
  return p ? 'O' : 'X';
}

template <typename U>
char debug_char(std::shared_ptr<U> p)
{
  return p ? 'O' : 'X';
}

template <typename U>
char debug_char(std::weak_ptr<U> p)
{
  return !(p.expired()) ? 'O' : 'X';
}

template <typename T>
void DLLDeque<T>::debug_print() const
{
  std::cout << "deque:";
  std::cout << " " << debug_char(m_head);
  for (auto node = m_head; node; node = node->next)
  {
    std::cout << " " << debug_char(node->prev) << ':' << node->item << ':' << debug_char(node->next);
  }
  std::cout << " " << debug_char(m_tail);
  std::cout << std::endl;
}

#endif
