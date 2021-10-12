#include "DataMataKuliah.h"
#include <array>


class MataKuliah : private DataMataKuliah {
    bool m_lulus;


  public:
    MataKuliah(){};
    MataKuliah(DataMataKuliah dataMK) : DataMataKuliah(dataMK){};


    char *getNama() {
        return m_nama;
    }
    int getSks() {
        return m_sks;
    }
    int getKuota() {
        return m_kuota;
    }
    int getJenis() {
        return m_jenis;
    }
    std::array<int, 5> getPrasyarat() {
        return m_prasyarat;
    }
    void setLulus(bool lulus) {
        m_lulus = lulus;
    }
    bool getLulus() {
        return m_lulus;
    }
};
