#pragma once
#include "DataMataKuliah.h"
#include "Tool.h"
#include <vector>


class Course : DataMataKuliah {
    bool m_lulus = false;

  public:
    Course(){};
    Course(DataMataKuliah dataMK) : DataMataKuliah(dataMK){};

    int getKode() const {
        return m_kode;
    }

    std::string getNama() const {
        return m_nama;
    }

    int getSks() const {
        return m_sks;
    }
    int getKuota() const {
        return m_kuota;
    }
    std::string getJenis() const {
        return Tool::jenisTeks[m_jenis - 1];
    }
    std::vector<int> getPrasyarat() {
        return m_prasyarat;
    }
    std::vector<std::pair<int, int>> getJadwal() const {
        return m_jadwal;
    }
    void setLulus(bool lulus) {
        m_lulus = lulus;
    }
    bool getLulus() {
        return m_lulus;
    }

    void printMataKuliah() {
        if (m_lulus) {
            return;
        }
        cout << "Kode Mata Kuliah: " << m_kode << "\nNama Mata Kuliah: " << m_nama
             << "\nJumlah SKS: " << m_sks << "\nJenis: " << m_jenis << endl;
        cout << "Jadwalnya :" << endl;
        for (auto jadwal : m_jadwal) {
            cout << "\t" << Tool::convertTimeToString(jadwal) << endl;
        }
    }
};
