#include <iostream>
#include <fstream>
using namespace std;

class Book {
    public:
        string bookName;
        double bookPrice;

    Book(string a, double b) {
        bookName = a;
        bookPrice = b;
    }
};

void features();

int indexKey = 1;

void getBooks() {
    // open database file
    ifstream MyReadFile("book-store.txt");

    // read contend
    string content;
    while(getline (MyReadFile, content)) {
        cout << content << endl;
        indexKey++;
    }

    // close database file
    MyReadFile.close();
}

void addBooks(int index) {
    cout << "Enter book name: ";
    string bookName;
    getline(cin, bookName);

    cout << "Enter book price: ";
    double bookPrice;
    cin >> bookPrice;

    Book b1(bookName, bookPrice);

    // open database file
    ofstream MyWriteFile("book-store.txt", ios::app);

    // write new data
    MyWriteFile << index << ".\t" << bookName << "\t\t$" << bookPrice << endl;

    // close database file
    MyWriteFile.close();

    cout << "\n\n\n";
    cout << "Available Books: \n";
    cout << "\tTitle\t\t Price\n";
    getBooks();
}

void features() {
    cout << "\n\nFeatures Included: \n";
    cout << "[1] Add New Book. \t[2] Exit the program. \n\n";

    int option;
    cin >> option;

    cin.ignore();

    if(option == 1) {
       cout << "\n\nAdd New book\n";
       addBooks(indexKey);
    } else {
        cout << "Exiting the program";
    }
}

int main() {
    cout << "----- Welcome to my book store! ----- \n\n";

    cout << "Available Books: \n";
    cout << "\tTitle\t\t Price\n";
    getBooks();
    features();

    cout << "\n\n";
}