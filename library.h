#include "hashmap.h"
#include "book.h"


class Library
{
    HashMap<Book> lib;

public:
    Library() {}
    void insert()
    {
        int issn, refC, issC;
        string t;
        string a;
        cout << "Enter the ISSN of book\n"; cin >> issn;
        cin.ignore();
        cout << "Enter the title of book\n"; getline(cin, t);
        cout << "Enter the authors of the book\n"; getline(cin, a);
        // cout << "Enter the number of books available as reference book\n"; cin >> refC;
        // cout << "Enter the number of books avaiable as issueable books\n"; cin >> issC;
        refC = 10;
        issC = 10;
        lib.insert(issn, Book{issn, t, a, refC, issC});
    }
    void printTable()
    {
        lib.printTable();
    }
    void searchBook()
    {
        int issn;
        cout << "Enter the ISSN number of the book you wish to search\n"; cin >> issn;
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
    void editBook()
    {
        int issn;
        cout << "Enter the ISSN number of the book you wish to edit\n"; cin >> issn;
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
};