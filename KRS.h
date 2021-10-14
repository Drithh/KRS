#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Courses.h"
using namespace std;

class KRS : Courses {
    vector<int> courseHistory;
    vector<Course> krs;
    int sksMaksimal;

    bool checkKuota(Course &MK);
    bool checkPrasyarat(Course &MK);
    bool checkJadwalTubrukan(Course &MK, pair<int, int> &pilihJadwal);



  public:
    void addMataKuliah(pair<Course &, pair<int, int>> courseJadwal) {
        Course *MK = &courseJadwal.first;
        pair<int, int> pilihJadwal = courseJadwal.second;

        if (!checkKuota(*MK)) {
            return;
        }
        if (!checkPrasyarat(*MK)) {
            return;
        }
        if (!checkJadwalTubrukan(*MK, pilihJadwal)) {
            return;
        }

        cout << "Kelas " << MK->getNama() << " Berhasil Diambil" << endl;
        MK->kelasTerambil();
        Course mataKuliah = *MK;
        cout << mataKuliah.getKode() << endl;
        mataKuliah.setJadwal({pilihJadwal});
        krs.push_back(mataKuliah);
    }

    void displayKRS() {
        for (auto mataKuliah : krs) {
            mataKuliah.printMataKuliah();
        }
    }

    void setLulus(int kodeMK, bool lulus) {
        auto matkulLulus = searchMataKuliah(kodeMK);
        krs.erase(matkulLulus);
        if (lulus) {
            courseHistory.push_back(kodeMK);
            matkulLulus.base()->setLulus(true);
        }
    }
};

bool KRS::checkKuota(Course &MK) {
    if (MK.getKuota() > 0) {
        return true;
    }
    else {
        cout << "Gagal Mengambil Kelas " << MK.getNama() << endl;
        cout << "Kelas " << MK.getNama() << " Sudah Penuh" << endl;
        return false;
    }
}

bool KRS::checkPrasyarat(Course &MK) {
    for (int prasyarat : MK.getPrasyarat()) {
        if (find(courseHistory.begin(), courseHistory.end(), prasyarat) == courseHistory.end()) {
            cout << "Gagal Mengambil Kelas " << MK.getNama() << endl;
            cout << "Kamu Belum Lulus Mata Kuliah "
                 << Courses::searchMataKuliah(prasyarat)->getNama() << endl;
            return false;
        }
    }
    return true;
}

bool KRS::checkJadwalTubrukan(Course &MK, pair<int, int> &pilihJadwal) {
    for (Course course : courses) {
        if (course.getKode() != MK.getKode()) {
            const int menitPerSKS = 50;
            const int durasiPelajaran = course.getSks() * menitPerSKS;
            for (auto jadwal : course.getJadwal()) {
                if (jadwal.first == pilihJadwal.first) {
                    if ((jadwal.second < pilihJadwal.second &&
                         jadwal.second + durasiPelajaran > pilihJadwal.second)) {
                        cout << "Gagal Mengambil Kelas " << MK.getNama() << endl;
                        cout << "Ada Tubrukan Dengan Kelas " << course.getNama() << endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
