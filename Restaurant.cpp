#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book() {} 
    Book(string t, string a) {
        this->title = t;
        this->author = a;
    }

    void setBookDetails(string t, string a) {
        this->title = t;
        this->author = a;
    }

    void hello() {
        cout << "Hello, I am a Book. Title: " << this->title << endl;
    }
};

class User {
private:
    string name;
    int user_id;

public:
    User() {} 
    User(int id, string n) {
        this->user_id = id;
        this->name = n;
    }

    void setUserDetails(int id, string n) {
        this->user_id = id;
        this->name = n;
    }

    void hello() {
        cout << "Hello, I am a User. Name: " << this->name << endl;
    }
};

int main() {
    int numBooks, numUsers;

    cout << "Enter the number of books: ";
    cin >> numBooks;
    cin.ignore();

    Book books[numBooks];

    for (int i = 0; i < numBooks; i++) {
        string title, author;
        cout << "Enter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        books[i].setBookDetails(title, author);
    }

    cout << "Enter the number of users: ";
    cin >> numUsers;
    cin.ignore();

    User users[numUsers];

    for (int i = 0; i < numUsers; i++) {
        string name;
        int id;
        cout << "Enter details for User " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, name);
        users[i].setUserDetails(id, name);
    }

    cout << "\nDisplaying Books: " << endl;
    for (int i = 0; i < numBooks; i++) {
        books[i].hello();
    }

    cout << "\nDisplaying Users: " << endl;
    for (int i = 0; i < numUsers; i++) {
        users[i].hello();
    }

    return 0;
}
