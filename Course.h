#pragma once
// #include "DataMataKuliah.h"
#include "Tool.h"
#include <vector>
#include "Kelas.h"
using namespace std;



class Course {
    bool m_lulus = false;
    int m_kode;
    string m_nama;
    int m_sks;
    // int m_kuota;
    int m_jenis;
    vector<int> m_prasyarat;
    vector<Kelas> m_kelas;
    static int orderKode;

  public:
    Course(){};
    /**
     * @brief Construct Course object
     *
     * @param kode - kode mata kuliah otomatis tergenerate dari orderKode
     * @param nama - nama mata kuliah
     * @param sks - jumlah SKS
     * @param kuota - kuota kelas
     * @param jenis - Jenis mata kuliah (wajib/pilihan)
     * @param prasyarat - prasyarat, berisi vector dari kode mata kuliah
     * @param kelas - kelas, struct berisi nama dosen, kuota, jadwal
     * jadwal berisi pair, jadwal.first = hari, jadwal.second = waktu dalam menit
     */
    Course(string nama, int sks, int jenis, vector<int> prasyarat, vector<Kelas> kelas)
        : m_nama(nama), m_sks(sks), m_jenis(jenis), m_prasyarat(prasyarat), m_kelas(kelas) {
        m_kode = orderKode++;
    };

    int getKode() const {
        return m_kode;
    }

    string getNama() const {
        return m_nama;
    }

    int getSks() const {
        return m_sks;
    }
    void kelasTerambil(int nomorKelas) {
        m_kelas[nomorKelas - 1].m_kuota--;
    }
    string getJenis() const {
        return Tool::jenisTeks[m_jenis - 1];
    }
    vector<int> getPrasyarat() {
        return m_prasyarat;
    }
    void setJadwal(vector<Kelas> newKelas) {
        m_kelas.clear();
        m_kelas = newKelas;
    }


    vector<Kelas> getKelas() const {
        return m_kelas;
    }
    void setLulus(bool lulus) {
    }
    bool getLulus() const {
        return m_lulus;
    }

    void printCourse() {
        cout << "Kode Mata Kuliah: " << m_kode << "\nNama Mata Kuliah: " << m_nama
             << "\nJumlah SKS: " << m_sks << "\nJenis: " << getJenis() << endl;
        cout << "Jadwalnya :" << endl;

        int i = 1;
        for (Kelas &kelas : m_kelas) {
            cout << "\t" << i++ << ". " << kelas.pengampu
                 << " Waktu:" << Tool::convertTimeToString(kelas.m_jadwal) << " - Kuota:" << kelas.m_kuota
                 << endl;
        }
    }
};

int Course::orderKode = 1;
