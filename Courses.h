#pragma once
#include <vector>
#include <string>
#include "Course.h"
#include <algorithm>

using namespace std;
class Courses {

  protected:
    static vector<Course> courses;

  public:
    Courses();

    vector<Course>::iterator searchMataKuliah(int kode) {
        return find_if(courses.begin(), courses.end(),
                       [kode](const Course &c) -> bool { return kode == c.getKode(); });
    }


    vector<Course>::iterator searchMataKuliah(string nama) {
        return find_if(courses.begin(), courses.end(),
                       [nama](const Course c) -> bool { return nama == c.getNama(); });
    }
};

vector<Course> Courses::courses;

Courses::Courses() {
    if (courses.empty()) {
        courses.push_back({"Konsep Pemrograman", 4, 20, 1, {}, {{1, 100}, {3, 600}, {5, 420}}});
        courses.push_back({"Kalkulus 1", 3, 25, 1, {}, {{1, 900}, {3, 600}, {5, 420}}});
        courses.push_back({"Sistem Digital", 4, 20, 2, {1, 2}, {{1, 900}, {3, 600}, {5, 420}}});
        courses.push_back({"Kalkulus 2", 4, 20, 2, {3, 2}, {{1, 900}, {3, 600}, {5, 420}}});
    }
}
