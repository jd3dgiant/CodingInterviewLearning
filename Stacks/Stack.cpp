#include "Stack.hpp"

template<typename T>
void Stack<T>::push(T item)
{

}

template<typename T>
T Stack<T>::pop()
{
  if (empty()) {
    throw std::exception("Empty stack!");
  }

  T temp = new T;

  return temp;
}

template<typename T>
T Stack<T>::top()
{
  return T();
}

template<typename T>
bool Stack<T>::empty()
{
  return false;
}

template<typename T>
void Stack<T>::clear()
{
}
