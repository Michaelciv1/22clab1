#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include <iostream>
using namespace std;

class contactlist
{
    private:
        struct ContactNode{
            string firstName;
            string lastName;
            string phoneNumber;
            struct ContactNode *next;
        };

        ContactNode *head;
    public:
        contactlist() { head = nullptr; }
        virtual ~contactlist();
        void insertNode(string first_name, string last_name, string phoneNumber);
        void displayList() const;
        void deleteNode (string first_name, string last_name);
};

#endif // CONTACTLIST_H
