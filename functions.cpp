#include "class.hpp"
#include "tabulate-master\single_include\tabulate\tabulate.hpp"

using namespace tabulate;

node::node(string name, string place, string phoneNo, string emailAdd)
{
    this->name = name;
    this->place = place;
    this->phoneNo = phoneNo;
    this->emailAdd = emailAdd;
    prev = NULL;
    next = NULL;
}

nodelist::nodelist()
{
    head = NULL;
    newn = NULL;
    ptr = NULL;
    ptr1 = NULL;
    ptr2 = NULL;
    dup = NULL;
}

void nodelist::accept()
{
    string name;
    string place;
    string phoneNo;
    string emailAdd;
    char choice;
    do
    {
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter place: ";
        getline(cin,place);
        do
        {
            cout<<"Enter valid 10 digit phone number: ";
            cin>>phoneNo;
            if(phoneNo.length() != 10)
            {
                cout<<"Invalid phone number\n";
            }
        }
        while(phoneNo.length() != 10);
        cout<<"Enter email address: ";
        cin>>emailAdd;

        newn = new node(name, place, phoneNo, emailAdd);

        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newn;
            newn->prev = ptr;
        }
        cout<<"NEW CONTACT ADDED\n";
        cout<<"Enter 'Y' to add another contact\n";
        cout<<"Enter 'N' to stop\n";
        cout<<"Enter your choice: ";
        cin>>choice;
    }
    while(choice == 'Y' || choice == 'y');
}

void nodelist::display()
{
    Table t;
    t.add_row({"NAME","PLACE","PHONE NUMBER","EMAIL"});
    ptr = head;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        t.add_row({ptr->name, ptr->place, ptr->phoneNo, ptr->emailAdd});
        ptr = ptr->next;
    }
    cout<<t<<endl;
}

void nodelist::update(string name)
{
    ptr = head;
    char choice;
    bool flag = false;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        if(name == ptr->name)
        {
            flag = true;
            do
            {
                cout<<"What do you want to update?"<<endl;
                cout<<" 1] Name"<<endl;
                cout<<" 2] Place"<<endl;
                cout<<" 3] Phone Number"<<endl;
                cout<<" 4] Email Address"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                switch(choice)
                {
                case '1':
                {
                    cout<<"Enter new name: ";
                    cin.ignore();
                    getline(cin,ptr->name);
                    cout<<"CONTACT NAME UPDATED\n";
                    break;
                }
                case '2':
                {
                    cout<<"Enter new place: ";
                    cin.ignore();
                    getline(cin,ptr->place);
                    cout<<"CONTACT PLACE UPDATED\n";
                    break;
                }
                case '3':
                {
                    do
                    {
                        cout<<"Enter new phone number: ";
                        cin>>ptr->phoneNo;
                        if(ptr->phoneNo.length() != 10)
                        {
                            cout<<"Invalid phone number\n";
                            cout<<"Valid phone number must have exactly 10 digits\n";
                        }
                    }
                    while(ptr->phoneNo.length() != 10);
                    cout<<"CONTACT PHONE NUMBER UPDATED\n";
                    break;
                }
                case '4':
                {
                    cout<<"Enter new email address: ";
                    cin>>ptr->emailAdd;
                    cout<<"CONTACT EMAIL ADDRESS UPDATED\n";
                    break;
                }
                default:
                {
                    cout<<"Invalid choice\n";
                }
                }
                cout<<"Enter 'Y' to update contact again\n";
                cout<<"Enter 'N' to stop\n";
                cout<<"Enter your choice: ";
                cin>>choice;
            }
            while(choice == 'Y' || choice == 'y');
        }
        ptr = ptr->next;
    }
    if(flag == false)
    {
        cout<<"Contact does not exist\n";
    }
}

void nodelist::deleteContact(string name)
{
    bool flag = false;
    ptr = head;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        if(name == ptr->name)
        {
            flag = true;
            break;
        }
        ptr = ptr->next;
    }
    if(flag == true && ptr == head && ptr->next == NULL)
    {
        delete ptr;
        head = NULL;
    }
    else if(flag == true && ptr == head && ptr->next != NULL)
    {
        head = ptr->next;
        ptr->next->prev = NULL;
        delete ptr;
    }
    else if(flag == true && ptr != head && ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        delete ptr;
    }
    else if(flag == true && ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
    if(flag == true)
    {
        cout<<"CONTACT DELETED\n";
    }
    else
    {
        cout<<"Contact does not exist\n";
    }
}

void nodelist::deleteSameName()
{
    ptr1 = head;
    if(ptr1 == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->name == ptr2->name)
            {
                dup = ptr2;
                if(ptr2->next == NULL)
                {
                    ptr2->prev->next = NULL;
                }
                else if(ptr2->next != NULL)
                {
                    ptr2->prev->next = ptr2->next;
                    ptr2->next->prev = ptr2->prev;
                }
                ptr2 = ptr2->next;
                delete dup;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    cout<<"CONTACTS WITH SAME NAME DELETED\n";
}

void nodelist::deleteSameNumber()
{
    ptr1 = head;
    if(ptr1 == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->phoneNo == ptr2->phoneNo)
            {
                dup = ptr2;
                if(ptr2->next == NULL)
                {
                    ptr2->prev->next = NULL;
                }
                else if(ptr2->next != NULL)
                {
                    ptr2->prev->next = ptr2->next;
                    ptr2->next->prev = ptr2->prev;
                }
                ptr2 = ptr2->next;
                delete dup;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    cout<<"CONTACTS WITH SAME PHONE NUMBER DELETED\n";
}

void nodelist::deleteSameEmail()
{
    ptr1 = head;
    if(ptr1 == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->emailAdd == ptr2->emailAdd)
            {
                dup = ptr2;
                if(ptr2->next == NULL)
                {
                    ptr2->prev->next = NULL;
                }
                else if(ptr2->next != NULL)
                {
                    ptr2->prev->next = ptr2->next;
                    ptr2->next->prev = ptr2->prev;
                }
                ptr2 = ptr2->next;
                delete dup;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    cout<<"CONTACTS WITH SAME EMAIL DELETED\n";
}

void nodelist::searchbyName(string name)
{
    Table t;
    t.add_row({"NAME","PLACE","PHONE NUMBER","EMAIL"});
    ptr = head;
    bool flag = false;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        if(name == ptr->name)
        {
            t.add_row({ptr->name, ptr->place, ptr->phoneNo, ptr->emailAdd});
            flag = true;
        }
        ptr = ptr->next;
    }
    if(flag == true)
    {
        cout<<"Contact found\n";
        cout<<t<<endl;
    }
    else
    {
        cout<<"Contact does not exist\n";
    }
}

void nodelist::searchbyNumber(string number)
{
    Table t;
    t.add_row({"NAME","PLACE","PHONE NUMBER","EMAIL"});
    ptr = head;
    bool flag = false;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        if(number == ptr->phoneNo)
        {
            t.add_row({ptr->name, ptr->place, ptr->phoneNo, ptr->emailAdd});
            flag = true;
        }
        ptr = ptr->next;
    }
    if(flag == true)
    {
        cout<<"Contact found\n";
        cout<<t<<endl;
    }
    else
    {
        cout<<"Contact does not exist\n";
    }
}

void nodelist::searchbyEmail(string email)
{
    Table t;
    t.add_row({"NAME","PLACE","PHONE NUMBER","EMAIL"});
    ptr = head;
    bool flag = false;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        if(email == ptr->emailAdd)
        {
            t.add_row({ptr->name, ptr->place, ptr->phoneNo, ptr->emailAdd});
            flag = true;
        }
        ptr = ptr->next;
    }
    if(flag == true)
    {
        cout<<"Contact found\n";
        cout<<t<<endl;
    }
    else
    {
        cout<<"Contact does not exist\n";
    }
}

void nodelist::displaySuggestions(string n)
{
    Table t;
    t.add_row({"NAME","PLACE","PHONE NUMBER","EMAIL"});
    ptr = head;
    bool flag = false;
    if(ptr == NULL)
    {
        cout<<"Phonebook is empty\n";
        return;
    }
    while(ptr != NULL)
    {
        if(ptr->name.find(n) != string::npos)
        {
            t.add_row({ptr->name, ptr->place, ptr->phoneNo, ptr->emailAdd});
            flag = true;
        }
        ptr = ptr->next;
    }
    if(flag == true)
    {
        cout<<"Contact suggestions found\n";
        cout<<t<<endl;
    }
    else
    {
        cout<<"No contact suggestions\n";
    }
}
