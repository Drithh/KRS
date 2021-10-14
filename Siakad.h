#pragma once
#include "Courses.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Siakad : Courses {

  public:
    void displayMataKuliah() {
        for (auto course : courses) {
            printMataKuliah(course);
        }
    }

    template <class T> void searchMataKuliah(T mataKuliah) {
        printMataKuliah(*Courses::searchMataKuliah(mataKuliah));
    }

    void printMataKuliah(Course &course) {
        course.printMataKuliah();
        cout << (course.getPrasyarat().empty() ? "Prasyarat Tidak Ada" : "Prasyarat :") << endl;
        for (int kodePrasyarat : course.getPrasyarat()) {
            auto prasyarat = Courses::searchMataKuliah(kodePrasyarat);
            if (!prasyarat->getLulus()) {
                cout << "\t" << prasyarat->getNama() << endl;
            }
        }
        cout << "\n\n";
    }



    pair<Course &, pair<int, int>> confirmMataKuliah(int kodeMK, int jadwalDipilih) {
        Course &MK = *Courses::searchMataKuliah(kodeMK);
        return {MK, MK.getJadwal().at(jadwalDipilih - 1)};
    }
};
