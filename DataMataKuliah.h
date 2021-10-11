#include <array>

#pragma once
struct DataMataKuliah {
    char nama[30];
    int sks;
    int kuota;
    int jenis;
    std::array<int, 5> prasyarat;
};
