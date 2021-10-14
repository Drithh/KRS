#pragma once
#include <vector>
#include <string>
#include "Course.h"
#include <algorithm>

using namespace std;
class KRS {

  protected:
    vector<Course> krs;
    vector<int> courseHistory;
    int sksMaksimal;

  public:
    bool searchCourseHistory(int kodeCourse) {
        return find(courseHistory.begin(), courseHistory.end(), kodeCourse) != courseHistory.end();
    }

    vector<Course>::iterator searchKRS(int kodeCourse) {
        return find_if(krs.begin(), krs.end(),
                       [kodeCourse](const Course &c) -> bool { return kodeCourse == c.getKode(); });
    }

    vector<Course>::iterator searchKRS(string namaCourse) {
        return find_if(krs.begin(), krs.end(),
                       [namaCourse](const Course c) -> bool { return namaCourse == c.getNama(); });
    }

    void printKRS() {
        if (krs.empty()) {
            cout << "KRS anda kosong" << endl;
        }
        else {
            for (auto courseDiambil : krs) {
                courseDiambil.printCourse();
            }
        }
    }

    /**
     * @brief Set object Lulus bisa lulus bisa tidak.
     * lalu menghapus objectnya dari krs
     * @param kodeCourse - Kode Kelas yang ingin di-set
     * @param lulus - Kondisi lulus atau tidak
     */
    void setLulus(int kodeCourse, bool lulus) {
        auto courseLulus = searchKRS(kodeCourse);
        if (courseLulus != krs.end()) {
            krs.erase(courseLulus);
            if (lulus) {
                courseHistory.push_back(kodeCourse);
                courseLulus.base()->setLulus(true);
            }
        }
    }
};
