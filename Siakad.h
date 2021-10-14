#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Courses.h"
#include "KRS.h"
#include "Kelas.h"
using namespace std;

class Siakad : public Courses, public KRS {
    bool checkKuota(Course &course, int pilihKelas);
    bool checkPrasyarat(Course &course);
    bool checkJadwalTubrukan(Course &course, Kelas &pilihJadwal);

  public:
    /**
     * @brief Mencetak semua course yang ada
     *
     */
    void printCourses() {
        for (Course course : courses) {
            printCourse(course);
        }
    }

    /**
     * @brief Mencetak isi dari course, jika course sudah lulus maka tidak mencetak
     *
     * @param course Object course
     */
    void printCourse(Course &course) {
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
    /**
     * @brief cari matakuliah dengan nama atau kodenya
     *
     * @tparam T string atau int
     * @param course
     */
    template <class T> void searchCourses(T course) {
        printCourse(*Courses::searchCourses(course));
    }

    /**
     * @brief Tambah Mata Kuliah ke KRS, Digunakan saat mahasiswa memilih mata kuliah yang ingin
     * diambil
     * @param kodeCourse integer, kode dari mata kuliah
     * @param pilihKelas, integer jadwal yang dipilih
     *
     *
     */
    void addKRS(int kodeCourse, int pilihKelas) {
        Course &course = *Courses::searchCourses(kodeCourse);
        Kelas kelas = course.getKelas().at(pilihKelas - 1);

        if (!checkKuota(course, pilihKelas) || !checkPrasyarat(course) ||
            !checkJadwalTubrukan(course, kelas) || searchCourseHistory(kodeCourse) ||
            searchKRS(kodeCourse) != krs.end()) {
            return;
        }
        cout << "Kelas " << course.getNama() << " Berhasil Diambil" << endl;
        course.kelasTerambil(pilihKelas);

        Course courseDiambil = course;
        courseDiambil.setJadwal({kelas});
        krs.push_back(courseDiambil);
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
bool Siakad::checkKuota(Course &course, int pilihKelas) {
    if (course.getKelas().at(pilihKelas - 1).m_kuota > 0) {
        return true;
    }
    else {
        cout << "Gagal Mengambil Kelas " << course.getNama() << endl;
        cout << "Kelas " << course.getNama() << " Sudah Penuh" << endl;
        return false;
    }
}

/**
 * @brief Check Prasyarat dari Course yang dipilih
 *
 * @param course - Object kelas yang ingin diambil
 * @return true - Prasyarat terpenuhi
 * @return false - Prasyarat tidak terpenuhi
 */
bool Siakad::checkPrasyarat(Course &course) {
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
bool Siakad::checkJadwalTubrukan(Course &course, Kelas &pilihKelas) {
    for (Course course : courses) {
        if (course.getKode() != course.getKode()) {
            // Menghitung Durasi Pelajaran
            const int menitPerSKS = 50;
            const int durasiPelajaran = course.getSks() * menitPerSKS;
            for (Kelas kelas : course.getKelas()) {
                // Check apakah harinya sama
                if (kelas.m_jadwal.first == pilihKelas.m_jadwal.first) {
                    // Check apakah Jam mulai Kelas yang dipilih ada diantara jam kelas yang sudah ada di KRS
                    if ((kelas.m_jadwal.second < pilihKelas.m_jadwal.second &&
                         kelas.m_jadwal.second + durasiPelajaran > pilihKelas.m_jadwal.second)) {
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
