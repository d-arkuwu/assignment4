#include "library.h"

int main()
{
    // HashMap<Book> library;
    // library.insert(1, Book{1, "C++" , "Anzar Zahid", 10, 10});
    // library.insert1(2, Book{2, "C--" , "Anzar Zahid", 10, 10});
    // library.insert(3, Book{3, "C==" , "Anzar Zahid", 10, 10});
    // library.insert(11, Book{11, "C**" , "Anzar Zahid", 10, 10});
    // library.printTa1ble();
    Library lib;
    lib.insert();
    lib.insert();
    lib.insert();
    lib.searchBook();
    //lib.searchBook();
    //lib.searchBook();
    lib.editBook();
    cout << endl;
    lib.deleteBook();
    lib.printTable();
}
