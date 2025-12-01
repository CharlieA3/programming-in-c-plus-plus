// iterator functions

// creating an iterator from a iterator pointer? is an iterator just a pointer?
template <typename T>
DLLDeque<T>::iterator::iterator(IterPtr n)
{
  m_node = n;
}

// basically what this is saying is that this iterator is taking in this other iterator as a paramter, this should copy it
// a copy is supposed use value from the iterator getting copied from, putting in a new piece of memory
template <typename T>
DLLDeque<T>::iterator::iterator(const iterator &it)
{
  m_node = it.m_node;
}

template <typename T>
typename DLLDeque<T>::iterator &DLLDeque<T>::iterator::operator++()
{
  m_node = m_node->next;
  return *this;
}

template <typename T>
typename DLLDeque<T>::iterator DLLDeque<T>::iterator::operator++(int)
{
  // creating a copy, so no matter what, we can return this and it will contain all the values from this before incrementing
  iterator old_iter(*this);
  // this is the same as ++(*this), if it was (*this)++ it would call the postfix operator function we are in, causing unwanted recursion (I think?)
  m_node = m_node->next;
  return old_iter;
}

template <typename T>
T &DLLDeque<T>::iterator::operator*()
{
  return m_node->item;
}

template <typename T>
bool DLLDeque<T>::iterator::operator==(const iterator &it)
{
  // TODO: Does checking that the shared pointers are equal work?
  // is == operator implemented for shared pointer type? how exactly does that work?
  // should it be for comparing the nodes? nah i dont think so
  return m_node == it.m_node;
}

template <typename T>
bool DLLDeque<T>::iterator::operator!=(const iterator &it)
{
  return m_node != it.m_node;
}

// deque functions

template <typename T>
void DLLDeque<T>::push_front(const T &t)
{
  std::shared_ptr<Node> n_node_ptr = std::make_shared<Node>();
  n_node_ptr->item = t;

  // if the deque is currently empty
  if ((m_head == nullptr) && (m_tail == nullptr))
  {
    n_node_ptr->next = nullptr;
    // nulls the weak pointer
    n_node_ptr->prev.reset();

    m_head = n_node_ptr;
    m_tail = n_node_ptr;
  } // if deque is not empty
  else
  {
    // setting pointers for new item
    n_node_ptr->next = m_head;
    n_node_ptr->prev.reset();

    // modifying current head
    m_head->prev = n_node_ptr;

    // updating head
    m_head = n_node_ptr;
  }
}

template <typename T>
void DLLDeque<T>::push_back(const T &t)
{
  std::shared_ptr<Node> n_node_ptr = std::make_shared<Node>();
  n_node_ptr->item = t;

  if ((m_head == nullptr) && (m_tail == nullptr))
  {
    n_node_ptr->next = nullptr;
    n_node_ptr->prev.reset();

    m_head = n_node_ptr;
    m_tail = n_node_ptr;
  }
  else
  {
    n_node_ptr->next = nullptr;
    // set tail's next before changing tail
    m_tail->next = n_node_ptr;
    // assign copy of weak pointer to the previous tail before reassigning tail
    n_node_ptr->prev = std::weak_ptr<Node>(m_tail);

    m_tail = n_node_ptr;
  }
}

template <typename T>
void DLLDeque<T>::pop_front()
{
  if (m_head == nullptr)
  {
    return;
  }

  if (m_head == m_tail)
  {
    m_head.reset();
    m_tail.reset();
    return;
  }
  std::shared_ptr next_head = m_head->next;

  next_head->prev.reset();
  m_head->next.reset();

  m_head = next_head;
}

template <typename T>
void DLLDeque<T>::pop_back()
{
  if (m_head == nullptr)
  {
    return;
  }

  // if there is only one node
  if (m_head == m_tail)
  {
    m_head.reset();
    m_tail.reset();
    return;
  }

  std::shared_ptr<Node> prev_next = m_tail->prev.lock();

  // gets rid of last node
  prev_next->next.reset();

  m_tail = prev_next;
}

template <typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::begin()
{
  return iterator(m_head);
}

template <typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::end()
{
  return iterator(nullptr);
}
