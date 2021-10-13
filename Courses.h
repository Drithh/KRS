#pragma once
#include <vector>
#include <string>
#include "Course.h"
using namespace std;
class Courses {
  protected:
    vector<Course> courses;

  public:
    vector<Course>::iterator searchMataKuliah(int kode) {
        return find_if(courses.begin(), courses.end(),
                       [kode](const Course &c) -> bool { return kode == c.getKode(); });
    }

    vector<Course>::iterator searchMataKuliah(string nama) {
        return find_if(courses.begin(), courses.end(),
                       [nama](const Course &c) -> bool { return nama == c.getNama(); });
    }
};