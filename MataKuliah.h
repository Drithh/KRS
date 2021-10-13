#include "DataMataKuliah.h"
#include <vector>


class MataKuliah : DataMataKuliah {
    bool m_lulus;

  public:
    MataKuliah(){};
    MataKuliah(DataMataKuliah dataMK) : DataMataKuliah(dataMK){};

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
    std::vector<int> getPrasyarat() const {
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
};
