/*
 * SList.h
 *
 * Singly-linked list for type T
 *
 *  Created on: 19.02.2013
 *      Author: rbondere
 */

#ifndef SLIST_H_
#define SLIST_H_
#include "List.h"

template <typename T>
class SList: public List<T>
{
  public:
    SList();
    virtual ~SList();

    virtual void insertAt(int pos,
                          T val);
    // inserts element at (after) position pos (0: at head)

    virtual void deleteAt(int pos);
    // deletes element at position pos (>0)

    virtual int search(T val) const;
    // searches val in list and returns position of first match, starting
    // at head
    // returns 0 if value is not found

    virtual T getValue(int pos) const;
    // returns value at position pos

    virtual void setValue(int pos,
                          T val);
    // sets value val at position pos

    virtual void print() const;
    // prints content of list to console

  private:
    struct Node
    {
      T value;
      Node* next;
    };
    Node* pHead; // ptr to head of list
    Node* nodePtr(int pos) const
    // returns a pointer to the node given by position pos
    {
      assert(pos > 0 && pos <= List<T>::nr);
      Node* p = pHead; // p points to element at pos 1, if not empty
      for (int i = 1; p && i < pos; i++)
      {
        p = p->next;
      }
      return p;
    }
};

// ugly include
#include "SList.cpp"

#endif /* SLIST_H_ */
