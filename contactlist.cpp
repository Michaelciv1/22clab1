#include "contactlist.h"

contactlist::~contactlist()
{
    ContactNode *nodePtr;
    ContactNode *nextNode;

    nodePtr = head;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next; // save the pointer to the next node
        delete nodePtr;  // delete the current node
        nodePtr = nextNode; // move on the next node on the list
    }
}

void contactlist::displayList() const{
    ContactNode *nodePtr;

    nodePtr = head;

    while(nodePtr)
    {
        cout << nodePtr->firstName << " " << nodePtr->lastName << " " << nodePtr->phoneNumber << endl;
        nodePtr = nodePtr->next;
    }
}

void contactlist::insertNode(string first_name, string last_name, string phoneNumber)
{
    ContactNode *newNode;
    ContactNode *nodePtr;
    ContactNode *previousNode = nullptr;

    newNode = new ContactNode;
    newNode->firstName = first_name;
    newNode->lastName = last_name;
    newNode->phoneNumber = phoneNumber;

    if (!head)  // head points to nullptr meaning list is empty
    {
        head = newNode;  // head now points to the new node
        newNode->next = nullptr;
    }
    else // otherwise look for the right place to insert node
    {
        nodePtr = head;
        previousNode = nullptr;
        while (nodePtr != nullptr && nodePtr->lastName < last_name)
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

void contactlist::deleteNode (string first_name, string last_name)
{
   ContactNode *nodePtr;
   ContactNode *previousNode;

   if (!head)
    return;

   if (first_name == head->firstName && last_name == head->lastName)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      nodePtr = head;
      // skip all nodes whose values don't match
      while (nodePtr != nullptr && first_name != nodePtr->firstName && last_name != nodePtr->lastName)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      if (nodePtr && first_name == nodePtr->firstName && last_name == nodePtr->lastName) // if nodePtr is not at the end
      {
         previousNode->next = nodePtr->next; // link the previous node to the node after
         delete nodePtr;  // delete the node
      }
   }
}
