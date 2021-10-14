#pragma once
#include "DataMataKuliah.h"
#include "Tool.h"
#include <vector>

using namespace std;
class Course : DataMataKuliah {
    bool m_lulus = false;

  public:
    Course(){};
    Course(DataMataKuliah dataMK) : DataMataKuliah(dataMK){};

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

    void printMataKuliah() {
        if (m_lulus) {
            return;
        }
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
