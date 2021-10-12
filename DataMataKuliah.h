#include <array>

#pragma once
struct DataMataKuliah {
    char m_nama[30];
    int m_sks;
    int m_kuota;
    int m_jenis;
    int m_durasi;
    std::array<int, 5> m_prasyarat;
    std::array<char[20], 3> m_jadwal;
};
