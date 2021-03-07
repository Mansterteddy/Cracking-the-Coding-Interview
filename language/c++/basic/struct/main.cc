#include <cstring>
#include <iostream>

using namespace std;

struct Books{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main(){
    Books Book1;
    Books Book2;

    strcpy(Book1.title, "C++ Tutorial");
    strcpy(Book1.author, "Runoob");
    strcpy(Book1.subject, "Programming Language");
    Book1.book_id = 12345;

    strcpy(Book2.title, "CSS Tutorial");
    strcpy(Book2.author, "Runoob");
    strcpy(Book2.subject, "Frontend Technology");
    Book2.book_id = 12346;

    cout << Book1.title << " " << Book1.author << " " << Book1.subject << " " << Book1.book_id << endl;
    cout << Book2.title << " " << Book2.author << " " << Book2.subject << " " << Book2.book_id << endl;

    return 0;
}