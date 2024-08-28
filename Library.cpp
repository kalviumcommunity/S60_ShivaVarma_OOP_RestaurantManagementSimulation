#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(string t, string a) {
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
    User(int id, string n) {
        this->user_id = id;
        this->name = n;
    }

    void hello() {
        cout << "Hello, I am a User. Name: " << this->name << endl;
    }
};

int main() {
    Book myBook("2001", "Jatin");
    User myUser(1, "Vinay");
    myBook.hello();
    myUser.hello();

    return 0;
}
