#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функція для заміни усіх входжень слова на нове слово
void replaceWord(char* text, const char* oldWord, const char* newWord) {
    char* pos = strstr(text, oldWord); // Знаходимо перше входження слова

    while (pos != NULL) {
        // Замінюємо слово на нове слово
        strncpy(pos, newWord, strlen(newWord));
        pos = strstr(pos + strlen(newWord), oldWord); // Знаходимо наступне входження слова
    }
}

// Функція для зміни тексту, щоб кожне речення починалося з великої літери
void capitalizeSentences(char* text) {
    int length = strlen(text);
    int capitalizeNext = 1; // Флаг, що показує, що наступний символ треба зробити великою літерою

    for (int i = 0; i < length; i++) {
        if (capitalizeNext && islower(text[i])) {
            text[i] = toupper(text[i]);
        }

        capitalizeNext = (text[i] == '.' || text[i] == '!' || text[i] == '?');
    }
}

// Функція для підрахунку кількості входжень кожної літери у тексті
void countLetters(const char* text) {
    int count[26] = { 0 }; // Масив для підрахунку кількості входжень кожної літери (a-z)

    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        char c = tolower(text[i]); // Перетворюємо символ на нижній регістр

        if (isalpha(c)) {
            count[c - 'a']++; // Збільшуємо лічильник відповідної літери
        }
    }

    // Виводимо результати
    printf("Кількість входжень кожної літери у тексті:\n");

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, count[i]);
    }
}

// Функція для підрахунку кількості входжень цифр у тексті
void countDigits(const char* text) {
    int count[10] = { 0 }; // Масив для підрахунку кількості входжень кожної цифри (0-9)

    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (isdigit(text[i])) {
            count[text[i] - '0']++; // Збільшуємо лічильник відповідної цифри
        }
    }

    // Виводимо результати
    printf("Кількість входжень кожної цифри у тексті:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, count[i]);
    }
}

int main() {
    char text[] = "Це є деякий текст, що містить слова і речення. Тут є багато цифр 1234567890.";
    const char oldWord[] = "деякий";
    const char newWord[] = "новий";

    // Заміна входжень слова на нове слово
    replaceWord(text, oldWord, newWord);
    printf("Текст після заміни:\n%s\n\n", text);

    // Зміна тексту, щоб кожне речення починалося з великої літери
    capitalizeSentences(text);
    printf("Текст з кожним реченням, що починається з великої літери:\n%s\n\n", text);

    // Підрахунок кількості входжень кожної літери у тексті
    countLetters(text);
    printf("\n");

    // Підрахунок кількості входжень цифр у тексті
    countDigits(text);
    printf("\n");

    return 0;
}
