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

    static auto searchCourses(int kodeCourse) -> vector<Course>::iterator {
        return find_if(courses.begin(), courses.end(),
                       [kodeCourse](const Course &c) -> bool { return kodeCourse == c.getKode(); });
    }


    static auto searchCourses(string namaCourse) -> vector<Course>::iterator {
        return find_if(courses.begin(), courses.end(),
                       [namaCourse](const Course c) -> bool { return namaCourse == c.getNama(); });
    }
};

vector<Course> Courses::courses;

Courses::Courses() {
    if (courses.empty()) {
        courses.push_back(
            {"Konsep Pemrograman", 4, 1, {}, {{"Bu Sari", 10, {1, 600}}, {"Bu Denis", 10, {3, 600}}}});
        courses.push_back({"Kalkulus 1", 3, 1, {}, {{"Bu Umi", 10, {1, 700}}, {"Bu Umi", 2, {4, 720}}}});
        courses.push_back(
            {"Sistem Digital", 4, 1, {}, {{"Pa Wisnu", 10, {3, 400}}, {"Pa Wisnu", 10, {3, 960}}}});
        courses.push_back(
            {"Aljabar Linear", 3, 1, {2}, {{"Pa Bambang", 10, {2, 720}}, {"Pa Bambang", 10, {3, 480}}}});
        courses.push_back(
            {"SD dan Algo", 4, 1, {1}, {{"Pa Wiranto", 10, {4, 480}}, {"Pa Wiranto", 10, {5, 480}}}});
        courses.push_back({"Kalkulus 2", 3, 1, {2}, {{"Bu Umi", 10, {5, 700}}, {"Bu Umi", 10, {2, 720}}}});
        courses.push_back({"PBO", 4, 1, {5}, {{"Pa Ardhi", 10, {2, 720}}, {"Pa Bambang", 10, {1, 540}}}});
        courses.push_back(
            {"DAA", 4, 1, {1, 5}, {{"Pa Wiranto", 10, {1, 600}}, {"Pa Wiranto", 10, {5, 480}}}});
        courses.push_back({"Kalkulus 2", 3, 1, {6}, {{"Bu Umi", 10, {3, 480}}, {"Bu Umi", 10, {5, 720}}}});
        courses.push_back(
            {"Kriptografi", 4, 2, {4}, {{"Pa Bambang", 10, {3, 780}}, {"Pa Bambang", 10, {5, 900}}}});
    }
}
