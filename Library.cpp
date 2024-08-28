#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:

    void hello() {
        cout << "Hello, I am a Book. Title: " << endl;
    }
};

class User {
private:
    string name;
    int user_id;

public:

    void hello() {
        cout << "Hello, I am a User. Name: " << name << endl;
    }
};

int main() {
    Book myBook;
    User myUser;


    myBook.hello();
    myUser.hello();

    return 0;
}
