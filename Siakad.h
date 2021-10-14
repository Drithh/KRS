#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Courses.h"
#include "KRS.h"
#include "Kelas.h"
using namespace std;

class Siakad : public Courses, public KRS {
    static auto checkKuota(Course &course, int pilihKelas) -> bool;
    auto checkPrasyarat(Course &course) -> bool;
    auto checkJadwalTubrukan(Course &course, Kelas &pilihKelas) -> bool;
    void printCourse(Course &course);

  public:
    /**
     * @brief Mencetak semua course yang ada
     *
     */
    void printCourses() {
        cout << "\n==========ALL COURSE==========" << endl;
        for (Course course : courses) {
            printCourse(course);
        }
        cout << "\n==========ALL COURSE=========="
             << "\n\n\n";
    }

    /**
     * @brief cari matakuliah dengan nama atau kodenya
     *
     * @tparam T string atau int
     * @param course
     */
    template <class T> void searchCourse(T course) {
        cout << "\n============SEARCH COURSE============" << endl;
        printCourse(*Courses::searchCourses(course));
        cout << "============SEARCH COURSE============"
             << "\n\n\n";
    }

    /**
     * @brief Tambah Mata Kuliah ke KRS, Digunakan saat mahasiswa memilih mata kuliah yang ingin
     * diambil.
     * @param kodeCourse integer, kode dari mata kuliah
     * @param pilihKelas, integer jadwal yang dipilih
     *
     *
     */
    void addKRS(int kodeCourse, int pilihKelas) {

        Course &course = *Courses::searchCourses(kodeCourse);
        if (course.getKelas().size() < pilihKelas) {
            cout << "Kelas yang kamu pilih tidak ada" << endl;
            return;
        }
        Kelas kelas = course.getKelas().at(pilihKelas - 1);


        // Check apakah kuota habis, prayarat tidak terpenuhi, jadwal tubrukan, sudah lulus, sudahdiambil
        if (!checkKuota(course, pilihKelas) || !checkPrasyarat(course) ||
            !checkJadwalTubrukan(course, kelas) || searchCourseHistory(kodeCourse) ||
            searchKRS(kodeCourse) != krs.end()) {
            return;
        }

        // Check apakah mahasiswa mengambil sks kelebihan
        int currentSKS = sksMaksimal - course.getSks();
        if (currentSKS < 0) {
            cout << "Kamu mengambil terlalu banyak kelas" << endl;
            return;
        }

        cout << "Kelas " << course.getNama() << " Berhasil Diambil" << endl;
        course.kelasTerambil(pilihKelas);
        sksMaksimal = currentSKS;
        Course courseDiambil = course;
        courseDiambil.setJadwal({kelas});
        krs.push_back(courseDiambil);
    }

    void printCourseHistory() {
        if (courseHistory.empty()) {
            cout << "Kamu belum pernah lulus apa-apa" << endl;
        }
        else {
            for (auto kodeCourse : courseHistory) {
                auto course = *Courses::searchCourses(kodeCourse);
                cout << "Nama:" << course.getNama() << " SKS:" << course.getSks() << endl;
            }
        }
    }
};

/**
 * @brief Check Kuota Kelas
 *
 * @param course - Object kelas yang ingin diambil
 * @param pilihKelas - nomor kelas
 * @return true - kuota masih ada
 * @return false  - kuota sudah habis
 */
auto Siakad::checkKuota(Course &course, int pilihKelas) -> bool {
    if (course.getKelas().at(pilihKelas - 1).m_kuota > 0) {
        return true;
    }

    cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
    cout << "Kelas " << course.getNama() << " Sudah Penuh" << endl;
    return false;
}

/**
 * @brief Check Prasyarat dari Course yang dipilih
 *
 * @param course - Object kelas yang ingin diambil
 * @return true - Prasyarat terpenuhi
 * @return false - Prasyarat tidak terpenuhi
 */
auto Siakad::checkPrasyarat(Course &course) -> bool {
    for (int prasyarat : course.getPrasyarat()) {
        if (!searchCourseHistory(prasyarat)) {
            cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
            cout << "Kamu Belum Lulus Mata Kuliah " << Courses::searchCourses(prasyarat)->getNama() << endl;
            return false;
        }
    }
    return true;
}

/**
 * @brief Check apakah ada waktu yang tabrakan dengan kelas lain yang diambil
 * (1 SKS = 50 Menit)
 * @param course - Object kelas yang ingin diambil
 * @param pilihKelas - nomor kelas
 * @return true - ketika tidak ada tubrukan
 * @return false - ketika terjadi tubrukan
 */
auto Siakad::checkJadwalTubrukan(Course &course, Kelas &pilihKelas) -> bool {
    // Menghitung Durasi Pelajaran
    const int menitPerSKS = 50;
    const int durasiPelajaran = course.getSks() * menitPerSKS;
    for (Course courseTerambil : krs) {
        auto kelasTerambil = courseTerambil.getKelas().at(0);

        if (kelasTerambil.m_jadwal.first == pilihKelas.m_jadwal.first) {
            // Check apakah Jam mulai Kelas yang dipilih ada diantara jam kelas yang sudah ada di KRS
            if ((kelasTerambil.m_jadwal.second < pilihKelas.m_jadwal.second &&
                 kelasTerambil.m_jadwal.second + durasiPelajaran > pilihKelas.m_jadwal.second)) {
                cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
                cout << "Ada Tubrukan Dengan Kelas " << course.getNama() << endl;
                return false;
            }
        }
    }
    return true;
}

void Siakad::printCourse(Course &course) {
    int kodeCourse = course.getKode();
    if (!searchCourseHistory(kodeCourse)) {
        course.printCourse();
        cout << (course.getPrasyarat().empty() ? "Prasyarat Tidak Ada" : "Prasyarat :") << endl;
        for (int kodePrasyarat : course.getPrasyarat()) {
            auto prasyarat = Courses::searchCourses(kodePrasyarat);
            if (!prasyarat->getLulus()) {
                cout << "\t" << prasyarat->getNama() << endl;
            }
        }
    }

    cout << "\n\n";
}
