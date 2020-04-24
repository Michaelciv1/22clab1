#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include <iostream>


class contactlist
{
    private:
    public:
        contactlist();
        void insertNode(string first_name, string last_name, string phoneNumber);
        void deleteNode (string name);
        virtual ~contactlist();
};

#endif // CONTACTLIST_H
