#include "hashmap.h"
#include "book.h"


class Library
{
    HashMap<Book> lib;

        void insert()
    {
        int issn, refC, issC;
        string t;
        string a;
        cout << "Enter the ISSN of book\n"; cin >> issn;
        cin.ignore();
        cout << "Enter the title of book\n"; 
        getline(cin, t);
        cout << "Enter the authors of the book\n"; 
        getline(cin, a);
        cout << "Enter the number of books available as reference book\n"; 
        cin >> refC;
        cout << "Enter the number of books avaiable as issueable books\n"; 
        cin >> issC;

        lib.insert(issn, Book{issn, t, a, refC, issC});
    }
    void printTable()
    {
        lib.printTable();
    }
    void searchBook()
    {
        int issn;
        cout << "Enter the ISSN number of the book you wish to search\n"; 
        cin >> issn;
        HashItem<Book>* h = lib.search(issn);
        if(h == NULL)
        {
            cout << "Book not found\n";
            return;
        }
        else
        {
            Book searched = h->getValue();
            cout << searched.getTitle();
        }
    }
    void reviewBook()
    {
        int issn;
        cout << "Enter the ISSN number of the book you wish to review\n"; cin >> issn;
        HashItem<Book>* h = lib.search(issn);
        if(h)
            (*h).getValue().printDetails();
        else
            cout << "Book not found\n";
    }
    void editBook()
    {
        int issn;
        cout << "Enter the ISSN number of the book you wish to edit\n"; 
        cin >> issn;
        HashItem<Book>* h = lib.search(issn);
        if(h == NULL)
        {
            cout << "Book not found\n";
            return;       
        }
        else
        {
            (*h).getValue().update();
        }
    }
    void deleteBook()
    {
        int issn;
        cout << "Enter the ISSN number of the book you wish to delete\n"; 
        cin >> issn;
        bool check = lib.remove(issn);
        if(check)
        {
            cout << "Book successfully deleted\n";
        }
        else
        {
            cout << "Book not found\n";
        }
    }

public:
    Library() {}

    void run()
	{
		bool flag = true;
		while (flag)
		{
			cout << "Library DataBase\n" << endl;
			int c;
			cout << "1. Create a book record\n";
			cout << "2. Review a book record\n";
			cout << "3. Update a book record\n";
			cout << "4. Delete a book record\n";
			cout << "5. List all book records\n";
			cout << "\nChoose desired operation : "; cin >> c;
			switch (c)
			{
			case 1:
			{
                system("clear");
				insert();
                system("clear");
				break;
			}
			case 2:
			{
                system("clear");
				reviewBook();
                cout << endl << endl << endl;
				break;
			}
			case 3:
			{
                system("clear");
				editBook();
                system("clear");
				break;
			}
			case 4:
			{
                system("clear");
				deleteBook();
                system("clear");
				break;
			}
			case 5:
			{
                system("clear");
				printTable();
                break;
			}
			default:
				flag = false;
				break;
			}
		}
	}
};
