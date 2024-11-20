#include "class.hpp"
#include "tabulate-master\single_include\tabulate\tabulate.hpp"

using namespace tabulate;

void welcome()
{
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+                  PHONE DIRECTORY                 +"<<endl;
    cout<<"+             [using DOUBLE LINKED LIST]           +"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"-                          Bhuvanesh D    [22PD07] -"<<endl;
    cout<<"-                          Livin Joseph J [22PD20] -"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<endl;
}

void endProgram()
{
    cout<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+                  PHONE DIRECTORY                 +"<<endl;
    cout<<"+             [using DOUBLE LINKED LIST]           +"<<endl;
    cout<<"+                                                  +"<<endl;
    cout<<"+                          Bhuvanesh D    [22PD07] +"<<endl;
    cout<<"+                          Livin Joseph J [22PD20] +"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<endl;
}

int main()
{
    welcome();
    nodelist contact;
    int choice;
    do
    {
        cout<<"|==================================================|\n";
        cout<<"|                    MAIN MENU                     |\n";
        cout<<"|==================================================|\n";
        cout<<"| 1] DISPLAY PHONE BOOK                            |\n";
        cout<<"| 2] INSERT NEW CONTACT                            |\n";
        cout<<"| 3] UPDATE DETAILS ON EXISTING CONTACT            |\n";
        cout<<"| 4] DELETE CONTACT                                |\n";
        cout<<"| 5] DELETE SAME NAME IN PHONEBOOK                 |\n";
        cout<<"| 6] DELETE SAME NUMBER IN PHONEBOOK               |\n";
        cout<<"| 7] DELETE SAME EMAIL IN PHONEBOOK                |\n";
        cout<<"| 8] SEARCH                                        |\n";
        cout<<"| 9] DISPLAY SUGGESTIONS                           |\n";
        cout<<"| 0] EXIT                                          |\n";
        cout<<"|==================================================|\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            contact.display();
            break;
        }
        case 2:
        {
            contact.accept();
            break;
        }
        case 3:
        {
            string n;
            cout<<"Enter the name of the contact to be updated: ";
            cin.ignore();
            getline(cin,n);
            contact.update(n);
            break;
        }
        case 4:
        {
            string n;
            cout<<"Enter the name of the contact to be deleted: ";
            cin.ignore();
            getline(cin,n);
            contact.deleteContact(n);
            break;
        }
        case 5:
        {
            contact.deleteSameName();
            break;
        }
        case 6:
        {
            contact.deleteSameNumber();
            break;
        }
        case 7:
        {
            contact.deleteSameEmail();
            break;
        }
        case 8:
        {
            char ch;
            do
            {
                cout<<"|==================================================|\n";
                cout<<"|                   SEARCH MENU                    |\n";
                cout<<"|==================================================|\n";
                cout<<"| 1] SEARCH USING NAME                             |\n";
                cout<<"| 2] SEARCH USING NUMBER                           |\n";
                cout<<"| 3] SEARCH USING EMAIL ADDRESS                    |\n";
                cout<<"| 0] EXIT SEARCH MENU                              |\n";
                cout<<"|==================================================|\n";
                cout<<"Enter your choice: ";
                cin>>ch;
                switch(ch)
                {
                case '0':
                {
                    break;
                }
                case '1':
                {
                    string n;
                    cout<<"Enter the name of the contact to be searched: ";
                    cin.ignore();
                    getline(cin,n);
                    contact.searchbyName(n);
                    break;
                }
                case '2':
                {
                    string p;
                    do
                    {
                        cout<<"Enter the phone number of the contact to be searched: ";
                        cin>>p;
                        if(p.length() != 10)
                        {
                            cout<<"Invalid phone number\n";
                            cout<<"Valid phone number must have exactly 10 digits\n";
                        }
                    }
                    while(p.length() != 10);
                    contact.searchbyNumber(p);
                    break;
                }
                case '3':
                {
                    string e;
                    cout<<"Enter the email address of the contact to be searched: ";
                    cin>>e;
                    contact.searchbyEmail(e);
                    break;
                }
                default:
                {
                    cout<<"Invalid choice\n";
                }
                }
            }
            while(ch != '0');
            break;
        }
        case 9:
        {
            string sub;
            cout<<"Enter some text to show suggestions: ";
            cin>>sub;
            contact.displaySuggestions(sub);
            break;
        }
        default:
        {
            cout<<"Invalid choice\n";
        }
        }
    }
    while(choice != 0);
    endProgram();
    return 0;
}
