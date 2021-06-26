#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Book;
class Author;
class Library;
class Librarian;
class Visitor;

//Предметная область: Библиотека
//Информационные объекты: Библиотека, Библиотекарь, Книги, Авторы, Посетитель

//У книги может быть только один автор.

//Посетитель посещает библиотеку с целью найти книгу по имени автора И/ИЛИ по названию книги.

//Необходимо реализовать данный функционал, придерживаясь принципов DRY, KISS, YAGNI
// и Single Responsibility Principle

class Book {
public:
    string name;
    string author;

    Book(const string &name, const string &author) : name(name), author(author) {}

    Book (const Book &obj) {
        name = obj.name;
        author = obj.author;
    }
};


class Author {
    string name;
    vector<Book> books;
public:
    Author (const string &name) : name(name) {}
    void addBook (Book book) {
        books.push_back(book);
    }

    int searchBook (Book book) {
        for (int i = 0; i < books.size(); ++i) {
            if (books[i].name == book.name) {
                return i;
            }
        }
        return -1;
    }
};


class Library {
public:
    vector<Book> books;
    Librarian &librarian;
};

class Librarian {
public:
    Library &Library;

    void addBook (Book book) {
        Library.books.push_back(book);
    }

    int searchBook (Book book) {
        for (int i = 0; i < Library.books.size(); ++i) {
            if (Library.books[i].name == book.name && Library.books[i].author == book.author) {
                return i;
            }
        }
        return -1;
    }

    int searchBookByName (string name) {
        for (int i = 0; i < Library.books.size(); ++i) {
            if (Library.books[i].name == name) {
                return i;
            }
        }
        return -1;
    }

    int searchBookByAuthor (string author) {
        for (int i = 0; i < Library.books.size(); ++i) {
            if (Library.books[i].author == author) {
                return i;
            }
        }
        return -1;
    }

};

class Visitor {
public:
    Library library;

    int searchBook (Book book) {
        return library.librarian.searchBook(book);
    }

    int searchBookByName (string name) {
        return library.librarian.searchBookByName(name);
    }

    int searchBookByAuthor (string author) {
        return library.librarian.searchBookByAuthor(author);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
