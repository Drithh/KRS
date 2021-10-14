#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Courses.h"
using namespace std;

class Siakad : Courses {
    vector<int> courseHistory;
    vector<Course> krs;
    int sksMaksimal;

    bool checkKuota(Course &course);
    bool checkPrasyarat(Course &course);
    bool checkJadwalTubrukan(Course &course, pair<int, int> &pilihJadwal);

  public:
    /**
     * @brief Mencetak list mata kuliah yang belum lulus
     *
     */
    void displayMataKuliah() {
        for (auto course : courses) {
            printCourse(course);
        }
    }


    void printCourse(Course &course) {
        int kodeCourse = course.getKode();
        if (find(courseHistory.begin(), courseHistory.end(), kodeCourse) != courseHistory.end()) {
            course.printCourse();
            cout << (course.getPrasyarat().empty() ? "Prasyarat Tidak Ada" : "Prasyarat :") << endl;
            for (int kodePrasyarat : course.getPrasyarat()) {
                auto prasyarat = Courses::searchMataKuliah(kodePrasyarat);
                if (!prasyarat->getLulus()) {
                    cout << "\t" << prasyarat->getNama() << endl;
                }
            }
        }

        cout << "\n\n";
    }

    template <class T> void searchMataKuliah(T course) {
        printCourse(*Courses::searchMataKuliah(course));
    }

    /**
     * @brief Tambah Mata Kuliah ke KRS, Digunakan saat mahasiswa memilih mata kuliah yang ingin
     * diambil
     * @param kodeCourse integer, kode dari mata kuliah
     * @param jadwalDipilih, integer jadwal yang dipilih
     *
     *
     */

    void addMataKuliah(int kodeCourse, int jadwalDipilih) {
        Course &course = *Courses::searchMataKuliah(kodeCourse);
        pair<int, int> pilihJadwal = course.getJadwal().at(jadwalDipilih - 1);

        if (!checkKuota(course) || !checkPrasyarat(course) ||
            !checkJadwalTubrukan(course, pilihJadwal)) {
            return;
        }
        cout << "Kelas " << course.getNama() << " Berhasil Diambil" << endl;
        course.kelasTerambil();

        Course courseDiambil = course;
        courseDiambil.setJadwal({pilihJadwal});
        krs.push_back(courseDiambil);
    }

    void displayKRS() {
        for (auto courseDiambil : krs) {
            courseDiambil.printCourse();
        }
    }

    void setLulus(int kodeCourse, bool lulus) {
        auto courseLulus = Courses::searchMataKuliah(kodeCourse);
        krs.erase(courseLulus);
        if (lulus) {
            courseHistory.push_back(kodeCourse);
            courseLulus.base()->setLulus(true);
        }
    }
};

bool Siakad::checkKuota(Course &course) {
    if (course.getKuota() > 0) {
        return true;
    }
    else {
        cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
        cout << "Kelas " << course.getNama() << " Sudah Penuh" << endl;
        return false;
    }
}

bool Siakad::checkPrasyarat(Course &course) {
    for (int prasyarat : course.getPrasyarat()) {
        if (find(courseHistory.begin(), courseHistory.end(), prasyarat) == courseHistory.end()) {
            cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
            cout << "Kamu Belum Lulus Mata Kuliah "
                 << Courses::searchMataKuliah(prasyarat)->getNama() << endl;
            return false;
        }
    }
    return true;
}

bool Siakad::checkJadwalTubrukan(Course &course, pair<int, int> &pilihJadwal) {
    for (Course course : courses) {
        if (course.getKode() != course.getKode()) {
            const int menitPerSKS = 50;
            const int durasiPelajaran = course.getSks() * menitPerSKS;
            for (auto jadwal : course.getJadwal()) {
                if (jadwal.first == pilihJadwal.first) {
                    if ((jadwal.second < pilihJadwal.second &&
                         jadwal.second + durasiPelajaran > pilihJadwal.second)) {
                        cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
                        cout << "Ada Tubrukan Dengan Kelas " << course.getNama() << endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
