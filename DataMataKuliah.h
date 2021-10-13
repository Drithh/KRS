#include <vector>
#include <string>
#include <utility>
#pragma once

using namespace std;

struct DataMataKuliah {
    int m_kode;
    string m_nama;
    int m_sks;
    int m_kuota;
    int m_jenis;
    vector<int> m_prasyarat;
    vector<pair<int, int>> m_jadwal;
};
