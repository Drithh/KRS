#pragma once
#include "Courses.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Siakad : Courses {

  public:
    Siakad();

    void displayMataKuliah() {
        for (auto course : courses) {
            printMataKuliah(course);
        }
    }

    void printMataKuliah(Course &course) {
        course.printMataKuliah();
        cout << (course.getPrasyarat().empty() ? "Prasyarat Tidak Ada" : "Prasyarat :") << endl;
        for (int kodePrasyarat : course.getPrasyarat()) {
            auto prasyarat = searchMataKuliah(kodePrasyarat);
            if (!prasyarat->getLulus()) {
                cout << "\t" << prasyarat->getNama() << endl;
            }
        }
        cout << "\n\n";
    }
};


Siakad::Siakad() {
    courses.push_back((DataMataKuliah){
        1, "Konsep Pemrograman", 4, 20, 1, {3, 2}, {{1, 900}, {3, 600}, {5, 420}}});
    courses.push_back(
        (DataMataKuliah){2, "Kalkulus 1", 3, 25, 1, {}, {{1, 900}, {3, 600}, {5, 420}}});
    courses.push_back(
        (DataMataKuliah){4, "Kalkulus 2", 4, 20, 2, {3, 2}, {{1, 900}, {3, 600}, {5, 420}}});
    courses.push_back(
        (DataMataKuliah){3, "Sistem Digital", 4, 20, 2, {1, 2}, {{1, 900}, {3, 600}, {5, 420}}});
}
