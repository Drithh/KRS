#pragma once
// #include "DataMataKuliah.h"
#include "Tool.h"
#include <vector>

using namespace std;
class Course {
    bool m_lulus = false;
    int m_kode;
    string m_nama;
    int m_sks;
    int m_kuota;
    int m_jenis;
    vector<int> m_prasyarat;
    vector<pair<int, int>> m_jadwal;
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
     * @param jadwal - jadwal, vector pair, dengan pair.first = harinys dan pair.seecond = waktu
     * dengan menit
     */
    Course(string nama, int sks, int kuota, int jenis, vector<int> prasyarat,
           vector<pair<int, int>> jadwal)
        : m_nama(nama), m_sks(sks), m_kuota(kuota), m_jenis(jenis), m_prasyarat(prasyarat),
          m_jadwal(jadwal) {
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
    void kelasTerambil() {
        m_kuota--;
    }
    int getKuota() const {
        return m_kuota;
    }
    string getJenis() const {
        return Tool::jenisTeks[m_jenis - 1];
    }
    vector<int> getPrasyarat() {
        return m_prasyarat;
    }
    void setJadwal(vector<pair<int, int>> newJadwal) {
        m_jadwal.clear();
        m_jadwal = newJadwal;
    }


    vector<pair<int, int>> getJadwal() const {
        return m_jadwal;
    }
    void setLulus(bool lulus) {
        m_lulus = lulus;
    }
    bool getLulus() const {
        return m_lulus;
    }

    void printCourse() {
        cout << "Kode Mata Kuliah: " << m_kode << "\nNama Mata Kuliah: " << m_nama
             << "\nJumlah SKS: " << m_sks << "\nJenis: " << m_jenis << "\nKuota: " << m_kuota
             << endl;
        cout << "Jadwalnya :" << endl;

        int i = 1;
        for (pair<int, int> jadwal : m_jadwal) {
            cout << "\t" << i++ << ". " << Tool::convertTimeToString(jadwal) << endl;
        }
    }
};

int Course::orderKode = 0;


// 3 Jadwal tapi cuma 1 kuota