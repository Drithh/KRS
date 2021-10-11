#include "DataMataKuliah.h"
#include <array>


class MataKuliah {
    DataMataKuliah m_dataMK;
    bool m_lulus;


  public:
    MataKuliah(){};
    MataKuliah(DataMataKuliah dataMK) : m_dataMK(dataMK){};


    char *getNama() {
        return m_dataMK.nama;
    }
    int getSks() {
        return m_dataMK.sks;
    }
    int getKuota() {
        return m_dataMK.kuota;
    }
    int getJenis() {
        return m_dataMK.jenis;
    }
    std::array<int, 5> getPrasyarat() {
        return m_dataMK.prasyarat;
    }
    void setLulus(bool lulus) {
        m_lulus = lulus;
    }
    bool getLulus() {
        return m_lulus;
    }
};
