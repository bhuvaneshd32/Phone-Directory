#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class node
{
public:
    string name;
    string place;
    string phoneNo;
    string emailAdd;
    node *prev, *next;
    node(string, string, string, string);

    friend class nodelist;
};

class nodelist
{
private:
    node *head, *newn, *ptr;
    node *ptr1, *ptr2, *dup;

public:
    node *preven;
    nodelist();
    void accept();
    void display();
    void update(string);
    void deleteContact(string);
    void deleteSameName();
    void deleteSameNumber();
    void deleteSameEmail();
    void searchbyName(string);
    void searchbyEmail(string);
    void searchbyNumber(string);
    void displaySuggestions(string);
};
