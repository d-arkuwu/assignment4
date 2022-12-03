#include <iostream>
using namespace std;

class Book
{
    int ISSN;
    string title;
    string author;
    int referenceCount;
    int issueableCount;

    friend ostream& operator<< (ostream& out, Book b)
    {
        cout << b.title;
        return out;
    }
	friend bool operator == (Book b1, const Book b2)
	{
		if(b1.ISSN == b2.ISSN)
			return true;
		else
			return false;
	}

public:
    Book() {}
    Book(int issn, string t, string a, int refC, int issC)
    {
        ISSN = issn;
        title = t;
        author = a;
        referenceCount = refC;
        issueableCount = issC;
    }
    Book& operator= (const Book& b)
	{
		this->ISSN = b.ISSN;
		this->issueableCount = b.issueableCount;
        this->referenceCount = b.referenceCount;
        this->title = b.title;
        this->author = b.author;
		return *this;
	}
    string getTitle()
    {
        return title;
    }
    void update()
	{
		char c;
		cout << "Do you wish to change the title of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "Enter new title of the book : ";
			cin.ignore();
			getline(cin, title);
		}

		cout << "Do you wish to change the list of authors of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
            cout << "Enter the list of authors : ";
			cin.ignore();
			getline(cin, author);
		}

		cout << "Do you wish to change the # of copies available as reference book of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "\nEnter number of copies available as reference book : ";
			cin >> referenceCount;
		}

		cout << "Do you wish to change the # of copies available as issuable book of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "\nEnter number of copies available as issuable book : ";
			cin >> issueableCount;
		}
	}
	void printDetails()
	{
		cout << "Title : " << title << endl;
		cout << "Author(s) : " << author << endl;
		cout << "ISSN : " << ISSN << endl;
		cout << "Books available as reference copies : " << referenceCount << endl;
		cout << "Books available as issueable copies : " << issueableCount << endl;
	}

};