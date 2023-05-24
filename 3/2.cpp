#include <iostream>
#include <string>
#include <algorithm>

// Структура "Книга"
struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;
};

// Функція для редагування книги
void editBook(Book& book) {
    std::cout << "Введіть нову назву книги: ";
    std::getline(std::cin >> std::ws, book.title);

    std::cout << "Введіть нового автора книги: ";
    std::getline(std::cin >> std::ws, book.author);

    std::cout << "Введіть нове видавництво книги: ";
    std::getline(std::cin >> std::ws, book.publisher);

    std::cout << "Введіть новий жанр книги: ";
    std::getline(std::cin >> std::ws, book.genre);

    std::cout << "Книга була успішно відредагована." << std::endl;
}

// Функція для друку інформації про книгу
void printBook(const Book& book) {
    std::cout << "Назва: " << book.title << std::endl;
    std::cout << "Автор: " << book.author << std::endl;
    std::cout << "Видавництво: " << book.publisher << std::endl;
    std::cout << "Жанр: " << book.genre << std::endl;
    std::cout << std::endl;
}

// Функція для друку усіх книг
void printAllBooks(const Book library[], int size) {
    std::cout << "Книги у бібліотеці:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Книга #" << i + 1 << std::endl;
        printBook(library[i]);
    }
}

// Функція для пошуку книг за автором
void searchBooksByAuthor(const Book library[], int size, const std::string& author) {
    std::cout << "Результати пошуку книг за автором \"" << author << "\":" << std::endl;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (library[i].author == author) {
            found = true;
            printBook(library[i]);
        }
    }

    if (!found) {
        std::cout << "Книги за вказаним автором не знайдено." << std::endl;
    }
}

// Функція для пошуку книги за назвою
void searchBookByTitle(const Book library[], int size, const std::string& title) {
    std::cout << "Результати пошуку книги за назвою \"" << title << "\":" << std::endl;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (library[i].title == title) {
            found = true;
            printBook(library[i]);
            break; // Знайдена книга, виходимо з циклу
        }
    }

    if (!found) {
        std::cout << "Книга за вказаною назвою не знайдена." << std::endl;
    }
}

// Функція для порівняння книг за назвою
bool compareByTitle(const Book& book1, const Book& book2) {
    return book1.title < book2.title;
}

// Функція для порівняння книг за автором
bool compareByAuthor(const Book& book1, const Book& book2) {
    return book1.author < book2.author;
}

// Функція для порівняння книг за видавництвом
bool compareByPublisher(const Book& book1, const Book& book2) {
    return book1.publisher < book2.publisher;
}

int main() {
    const int librarySize = 10;
    Book library[librarySize];

    // Заповнення книг в бібліотеці (демонстраційні дані)
    library[0] = { "Book 1", "Author 1", "Publisher 1", "Genre 1" };
    library[1] = { "Book 2", "Author 2", "Publisher 2", "Genre 2" };
    library[2] = { "Book 3", "Author 3", "Publisher 3", "Genre 3" };
    library[3] = { "Book 4", "Author 1", "Publisher 2", "Genre 3" };
    library[4] = { "Book 5", "Author 2", "Publisher 1", "Genre 2" };
    library[5] = { "Book 6", "Author 3", "Publisher 3", "Genre 1" };
    library[6] = { "Book 7", "Author 1", "Publisher 1", "Genre 3" };
    library[7] = { "Book 8", "Author 2", "Publisher 3", "Genre 2" };
    library[8] = { "Book 9", "Author 3", "Publisher 2", "Genre 1" };
    library[9] = { "Book 10", "Author 1", "Publisher 3", "Genre 2" };

    // Виконання операцій над бібліотекою
    editBook(library[0]);
    printAllBooks(library, librarySize);
    searchBooksByAuthor(library, librarySize, "Author 1");
    searchBookByTitle(library, librarySize, "Book 3");

    // Сортування книг за назвою
    std::sort(library, library + librarySize, compareByTitle);
    std::cout << "Бібліотека після сортування за назвою:" << std::endl;
    printAllBooks(library, librarySize);

    // Сортування книг за автором
    std::sort(library, library + librarySize, compareByAuthor);
    std::cout << "Бібліотека після сортування за автором:" << std::endl;
    printAllBooks(library, librarySize);

    // Сортування книг за видавництвом
    std::sort(library, library + librarySize, compareByPublisher);
    std::cout << "Бібліотека після сортування за видавництвом:" << std::endl;
    printAllBooks(library, librarySize);

    return 0;
}
