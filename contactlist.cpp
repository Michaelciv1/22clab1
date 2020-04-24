#include "contactlist.h"
#include <iostream>

contactlist::contactlist()
{
    //ctor
}

contactlist::~contactlist()
{
    ContactNode *nodePtr;
    ContactNode *nextNode;
    ContactNode = head;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next; // save the pointer to the next node
        delete nodePtr;  // delete the current node
        nodePtr = nextNode; // move on the next node on the list
    }
}

void insertNode(string first_name, string last_name, string phoneNumber)
{
    ContactNode *newNode;
    ContactNode *nodePtr;
    ContactNode *previousNode = nullptr;

    newNode = new ContactNode;

    /*** assign new contact info to the new node here ***/

    if (!head)  // head points to nullptr meaning list is empty
    {
        head = newNode;  // head now points to the new node
        newNode->next = nullptr;
    }
    else // otherwise look for the right place to insert node
    {
        nodePtr = head;
        previousNode = nullptr;
        while (nodePtr != nullptr /*** && condition you need to keep the list sorted ***/)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == nullptr) // if the new node is to be the first in the list
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else // otherwise insert after the previous node
        {
            previousNode->next = newNode;
            newNode -> next = nodePtr;
        }
    }
}

void deleteNode (string name)
{
   ContactNode *nodePtr;
   ContactNode *previousNode;

   if (!head) // if the list is empty, do nothing
      return;

   /*** write code to test if the first node is the one ***/
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      nodePtr = head;
      // skip all nodes whose values don't match
      while (nodePtr != nullptr /*** && test for node values) ***/
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      if (nodePtr) // if nodePtr is not at the end
      {
         previousNode->next = nodePtr->next; // link the previous node to the node after
         delete NodePtr;  // delete the node
      }
   }
}
