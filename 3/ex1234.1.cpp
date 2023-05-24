#include <iostream>
#include <string>

// Структура "Пральна машинка"
struct WashingMachine {
    std::string brand;
    std::string color;
    int width;
    int length;
    int height;
    int power;
    int spinSpeed;
    int heatingTemperature;
};

// Структура "Праска"
struct Iron {
    std::string brand;
    std::string model;
    std::string color;
    int minTemperature;
    int maxTemperature;
    bool steamFunction;
    int power;
};

// Структура "Бойлер"
struct Boiler {
    std::string brand;
    std::string color;
    int power;
    int capacity;
    int heatingTemperature;
};

// Структура "Тварина"
struct Animal {
    std::string name;
    std::string species;
    std::string nickname;
};

// Функція для заповнення об'єкта "Тварина"
void fillAnimal(Animal& animal, const std::string& name, const std::string& species, const std::string& nickname) {
    animal.name = name;
    animal.species = species;
    animal.nickname = nickname;
}

// Функція для виведення даних про об'єкт "Тварина" на екран
void printAnimal(const Animal& animal) {
    std::cout << "Назва: " << animal.name << std::endl;
    std::cout << "Клас: " << animal.species << std::endl;
    std::cout << "Кличка: " << animal.nickname << std::endl;
}

int main() {
    // Завдання 1: Реалізація структури "Пральна машинка"
    WashingMachine washingMachine;
    washingMachine.brand = "Samsung";
    washingMachine.color = "White";
    washingMachine.width = 60;
    washingMachine.length = 60;
    washingMachine.height = 85;
    washingMachine.power = 2000;
    washingMachine.spinSpeed = 1200;
    washingMachine.heatingTemperature = 40;

    // Завдання 2: Реалізація структури "Праска"
    Iron iron;
    iron.brand = "Philips";
    iron.model = "SteamGlide";
    iron.color = "Blue";
    iron.minTemperature = 100;
    iron.maxTemperature = 200;
    iron.steamFunction = true;
    iron.power = 2400;

    // Завдання 3: Реалізація структури "Бойлер"
    Boiler boiler;
    boiler.brand = "Bosch";
    boiler.color = "Silver";
    boiler.power = 2000;
    boiler.capacity = 50;
    boiler.heatingTemperature = 60;

    // Завдання 4: Робота зі структурою "Тварина"
    Animal animal;
    fillAnimal(animal, "Собака", "Ссавець", "Рекс");
    printAnimal(animal);

    return 0;
}
