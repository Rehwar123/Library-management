 #include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    int quantity;

    Book(string t, string a, int q) {
        title = t;
        author = a;
        quantity = q;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, int quantity) {
        Book newBook(title, author, quantity);
        books.push_back(newBook);
    }

    void removeBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books.erase(books.begin() + i);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void searchBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                cout << "Book found!" << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "Quantity: " << books[i].quantity << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayBooks() {
        for (int i = 0; i < books.size(); i++) {
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Quantity: " << books[i].quantity << endl;
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    Library lib;

    int choice;
    string title, author;
    int quantity;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter quantity: ";
                cin >> quantity;
                lib.addBook(title, author, quantity);
                break;
            case 2:
                cout << "Enter title: ";
                cin >> title;
                lib.removeBook(title);
                break;
            case 3:
                cout << "Enter title: ";
                cin >> title;
                lib.searchBook(title);
                break;
            case 4:
                lib.displayBooks();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}