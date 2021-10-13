#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Courses.h"
using namespace std;

class KRS : Courses {
    vector<int> courseHistory;
    int sksMaksimal;

  public:
    void addMataKuliah(Course MK, pair<int, int> pilihJadwal) {
        if (MK.getKuota() < 0) {
            cout << "Gagal Mengambil Kelas " << MK.getNama() << endl;
            cout << "Kelas " << MK.getNama() << " Sudah Penuh" << endl;
            return;
        }
        for (int prasyarat : MK.getPrasyarat()) {
            if (find(courseHistory.begin(), courseHistory.end(), prasyarat) ==
                courseHistory.end()) {
                cout << "Gagal Mengambil Kelas " << MK.getNama() << endl;
                cout << "Kamu Belum Lulus Mata Kuliah "
                     << searchMataKuliah(prasyarat).base()->getNama() << endl;
                return;
            }
        }
        for (Course course : courses) {
            if (course.getKode() != MK.getKode()) {
                const int menitPerSKS = 50;
                const int durasiPelajaran = course.getSks() * menitPerSKS;
                for (auto jadwal : course.getJadwal()) {
                    if (jadwal.first != pilihJadwal.first) {
                        if (!(jadwal.second < pilihJadwal.second &&
                              jadwal.second + durasiPelajaran > pilihJadwal.second)) {
                            cout << "Gagal Mengambil Kelas " << MK.getNama() << endl;
                            cout << "Ada Tubrukan Dengan Kelas " << course.getNama() << endl;
                            return;
                        }
                    }
                }
            }
        }
        cout << "Kelas " << MK.getNama() << " Berhasil Diambil" << endl;
        courses.push_back(MK);
    }

    void displayKRS() {
        for (auto mataKuliah : courses) {
            mataKuliah.printMataKuliah();
        }
    }

    void setLulus(int kodeMK, bool lulus) {
        if (lulus) {
            courseHistory.push_back(kodeMK);
            auto matkulLulus = searchMataKuliah(kodeMK);
            matkulLulus.base()->setLulus(true);
            courses.erase(matkulLulus);
        }
    }
};