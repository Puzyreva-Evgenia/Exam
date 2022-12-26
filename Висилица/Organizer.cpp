#include <iostream>
#include <string>
#include<vector>
#include <Windows.h>
#include <fstream>
#include "Note.h"

void PrintList(std::vector<Note> notes) {
    if (notes.size() == 0) {
    std::cout << "� ����������� ��� �������" << std::endl;
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
    std::cout<<"���� ������: " << std::endl;
    PrintList(notes);
    std::string answer;
    int number;
    while (true)
    {
        std::cout << "\t\n�������� ������ � �������? ������� 1.\n����� ��� ������������ ������?  ������� 2.\
\n�������� ������������ ������?  �������  3.\n������� ������?  ������� 4.\n����� ����� �� ��������� ������� 0. \n";
        std::cin >> sing;
        if (sing == '1') {
            std::cout << "��� �� ������ ��������?" << std::endl;
            std::cin >> text;
            Note note(text);
            notes.push_back(note);
            std::cout << "������ ������� ���������!" << std::endl;
            PrintList(notes);
            Save(notes, "notes.txt");
            std::cout << "������ ������� ���������." << std::endl;
        }
        else if (sing == '2') {
            std::cout << "��� �� ������ �����?" << std::endl;
            std::cin >> text;
            found = false;
            for (int i = 0; i < notes.size(); i++) {
                if (notes[i].GetText().find(text) != std::string::npos) {
                    found = true;
                    std::cout << "������: " << notes[i].GetText() << std::endl;
                }
            }
            if (!found) {
                std::cout << "������ �� �������!" << std::endl;
            }
        }
        else if (sing == '3') {
            std::cout << "��� �� ������ ��������?";
            std::cin >> text;
            found = false;
            for (int i = 0; i < notes.size(); i++) {
                if (notes[i].GetText().find(text) != std::string::npos) {
                    found = true;
                    std::cout << "�� ������ �������� ��� ������?(y/n): " << notes[i].GetText()<< std::endl;;
                    std::cin >> answer;
                    if (answer == "y") {
                        std::cout << "������� ����� �����" << std::endl;
                        std::cin >> text;
                        notes[i].SetText(text);
                        std::cout << "������ ������� ��������" << std::endl;
                        break;
                    }
                }
            }
            if (!found) {
                std::cout << "������ �� �������!" << std::endl;   
            }
            else {
                Save(notes, "notes.txt");
                PrintList(notes);
                std::cout << "������ ������� ���������." << std::endl;
            }
        }
        else if (sing == '4') {
            PrintList(notes);
            if (notes.empty()) {
                continue;
            }
            std::cout << "������� ����� ������, ������� ������ ������� ";
            std::cin >> number;
            if (number <= 0 || number > notes.size()) {
                std::cout<<"������� ����� �� ������" << std::endl;
                continue;
            }
            notes.erase(notes.begin() + number - 1);
            std::cout << "������ ������� �������" << std::endl;
            PrintList(notes);
            Save(notes, "notes.txt");
            std::cout << "������ ������� ���������." << std::endl;
        }
        else if (sing == '0') {
            std::cout<<"������ ������� ���������." << std::endl;
            return 0;
        }
    }
}
