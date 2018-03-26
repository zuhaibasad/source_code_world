#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    this->head = new ListItem<T>(otherLinkedList.head->value);
    ListItem<T> *cur = otherLinkedList.head;
    ListItem<T> *cur2 = head;
    cur=cur->next;
    while (cur != NULL)
    {
        ListItem<T> *node = new ListItem<T>(cur->value);
        node->prev = cur2;
        node->next = NULL;
        cur2->next = node;

        cur2 = cur2->next;
        cur = cur->next;
    }
    tail = cur2;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    ListItem<T> *cur;
    cur = getTail();
    while(cur != NULL)
    {
        ListItem<T> *temp = cur;
        delete cur;
        cur = temp -> next;
    }
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    if (head == NULL)
    {
        head = new ListItem<T>(item);
        tail = head;
    }
    else
    {
        ListItem<T> *newnode = new ListItem<T>(item);
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    if (head == NULL)
    {
      head = new ListItem<T>(item);
      tail = head;
    }
    else
    {
        ListItem<T> *cur = getTail();
        ListItem<T> *newnode = new ListItem<T>(item);
        newnode->next = NULL;
        newnode->prev = cur;
        cur->next = newnode;
        tail = newnode;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    ListItem<T> *cur = searchFor(afterWhat);
    if(cur != NULL)
    {
	if(cur == getTail())
	{
		insertAtTail(toInsert);
	}
	else
	{
        	ListItem<T> *newnode = new ListItem<T>(toInsert);
        	newnode->next = cur->next;
        	newnode->prev = cur;
	        cur->next = newnode;
	}
    }
}

template <class T>
void LinkedList<T>::insertSorted(T item)
{
    if (head == NULL)
    {
        head = new ListItem<T>(item);
        tail = head;
    }

    else{
            ListItem<T> *cur = head;
        while (cur != NULL)
        {
            if (cur->prev == NULL && cur->value >= item)
            {
                insertAtHead(item);
                return;
            }
            else if (cur->next == NULL && cur->value <= item)
            {
                insertAtTail(item);
                return;
            }
            else if (cur->next->value >= item )
            {
                ListItem<T> *newnode = new ListItem<T>(item);
                newnode->next = cur->next;
                newnode->prev = cur;
                cur->next->prev = newnode;
                cur->next = newnode;
                return;
            }

            cur = cur->next;
        }
    }
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        return head;
    }
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        return tail;
    }
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    if (head == NULL)
    {
        return NULL;
    }
    else{
        ListItem<T> *cur = head;
        while (cur != NULL)
        {
            if( cur->value == item )
            {
                return cur;
            }
            else
            {
                cur = cur->next;
            }
        }
        return NULL;
    }
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
    ListItem<T> *cur = searchFor(item);
    if (cur == head)
    {
        deleteHead();
    }
    else if (cur == tail)
    {
        deleteTail();
    }
    else if (cur->prev != NULL && cur->next != NULL)
    {
        ListItem<T>* tprev = cur->prev;
        ListItem<T>* tnext = cur->next;

        delete cur;
        cur = NULL;

        tprev->next = tnext;
        tnext->prev = tprev;

    }
}

template <class T>
void LinkedList<T>::deleteHead()
{
    ListItem<T> *cur = getHead();
    cur = cur->next;
    delete head;
    head = cur;
    if (cur != NULL)
    head->prev = NULL;
}

template <class T>
void LinkedList<T>::deleteTail()
{
    ListItem<T> *cur = getTail();
    cur = cur->prev;
    delete tail;
    tail = NULL;
    tail = cur;
    if (cur != NULL)
    tail->next = NULL;
}

template <class T>
int LinkedList<T>::length()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        ListItem<T> *cur = head;
        int length = 0;
        while (cur != NULL)
        {
            length ++;
            cur = cur->next;
        }
        return length;
    }
}


#endif
