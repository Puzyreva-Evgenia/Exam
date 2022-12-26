#include <iostream>
#include <string>
#include<vector>
#include <Windows.h>
#include <fstream>
#include "Note.h"

void PrintList(std::vector<Note> notes) {
    if (notes.size() == 0) {
    std::cout << "Доступных записей нет" << std::endl;
    return;
    }
    for (int i = 0; i < notes.size(); i++) {
        std::cout << i + 1 << ". " << notes[i].GetText() << std::endl;
    }
}

void Save(std::vector<Note> notes, std::string file) {
    std::ofstream out(file);
    for (int i = 0; i < notes.size(); i++) {
        out << notes[i].GetText() << std::endl;
    }
    out.close();
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ::setlocale(LC_ALL, "rus");
    std::ifstream in("notes.txt");
    std::vector<Note> notes;
    char sing{};
    std::string text;
    bool found = false;
    while (getline(in, text)) {
        Note note(text);
        notes.push_back(note);
    }
    in.close();
    std::cout<<"Ваши записи: " << std::endl;
    PrintList(notes);
    std::string answer;
    int number;
    while (true)
    {
        std::cout << "\t\nХотите добавить в блокнот новую запись? \nВведите 1.\n\
\nХотите найти уже существующую запись?\nВведите 2.\n\
\nХотите изменить существующую запись?\nВведите 3.\n\
\nХотите удалить запись?\nВведите 4.\n\
\nХотите завершить работу с программой?\nВведите 0." << std::endl;
        std::cin >> sing;
        if (sing == '1') {
            std::cout << "Что вы хотите записать?" << std::endl;
            std::cin >> text;
            Note note(text);
            notes.push_back(note);
            std::cout << "Запись успешно добавлена!" << std::endl;
            PrintList(notes);
            Save(notes, "notes.txt");
            std::cout << "Данные успешно сохранены." << std::endl;
        }
        else if (sing == '2') {
            std::cout << "Что вы хотите найти?" << std::endl;
            std::cin >> text;
            found = false;
            for (int i = 0; i < notes.size(); i++) {
                if (notes[i].GetText().find(text) != std::string::npos) {
                    found = true;
                    std::cout << "Запись: " << notes[i].GetText() << std::endl;
                }
            }
            if (!found) {
                std::cout << "Записи не найдено!" << std::endl;
            }
        }
        else if (sing == '3') {
            std::cout << "Что вы хотите изменить?";
            std::cin >> text;
            found = false;
            for (int i = 0; i < notes.size(); i++) {
                if (notes[i].GetText().find(text) != std::string::npos) {
                    found = true;
                    std::cout << "Вы хотите изменить эту запись?(y/n): " << notes[i].GetText()<< std::endl;;
                    std::cin >> answer;
                    if (answer == "y") {
                        std::cout << "Введите новый текст" << std::endl;
                        std::cin >> text;
                        notes[i].SetText(text);
                        std::cout << "Запись успешно изменена" << std::endl;
                        break;
                    }
                }
            }
            if (!found) {
                std::cout << "Записи не найдено!" << std::endl;   
            }
            else {
                Save(notes, "notes.txt");
                PrintList(notes);
                std::cout << "Данные успешно сохранены." << std::endl;
            }
        }
        else if (sing == '4') {
            PrintList(notes);
            if (notes.empty()) {
                continue;
            }
            std::cout << "Введите номер записи, которую хотите удалить: ";
            std::cin >> number;
            if (number <= 0 || number > notes.size()) {
                std::cout<<"Некорректный номер записи. Попробуйте еще раз: " << std::endl;
                continue;
            }
            notes.erase(notes.begin() + number - 1);
            std::cout << "Запись успешно удалена." << std::endl;
            PrintList(notes);
            Save(notes, "notes.txt");
            std::cout << "Данные успешно сохранены." << std::endl;
        }
        else if (sing == '0') {
            std::cout<<"Данные успешно сохранены." << std::endl;
            return 0;
        }
    }
}
