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
    int sksMaksimal = 8;

  public:
    auto searchCourseHistory(int kodeCourse) -> bool {
        return find(courseHistory.begin(), courseHistory.end(), kodeCourse) != courseHistory.end();
    }

    auto searchKRS(int kodeCourse) -> vector<Course>::iterator {
        return find_if(krs.begin(), krs.end(),
                       [kodeCourse](const Course &c) -> bool { return kodeCourse == c.getKode(); });
    }

    auto searchKRS(string namaCourse) -> vector<Course>::iterator {
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
        auto namaCourse = courseLulus->getNama();
        if (courseLulus != krs.end()) {
            sksMaksimal += courseLulus->getSks();
            krs.erase(courseLulus);
            if (lulus) {
                cout << "Selamat Kamu Lulus Matkul " << namaCourse << endl;
                courseHistory.push_back(kodeCourse);
            }
            else {
                cout << "Kamu Tidak Lulus Matkul " << namaCourse << endl;
            }
        }
    }
};
