#include <vector>
#include <string>
#include <utility>
#pragma once

struct DataMataKuliah {
    int m_kode;
    std::string m_nama;
    int m_sks;
    int m_kuota;
    int m_jenis;
    std::vector<int> m_prasyarat;
    std::vector<std::pair<int, int>> m_jadwal;
};

namespace Tool {
char m_jenisTeks[2][10] = {"Wajib", "Minat"};
// std::string convertTimeToString(int time) {
// }
// int convertStringToTime(std::string time) {
// }



} // namespace Tool
