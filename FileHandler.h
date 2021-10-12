#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

namespace filehandler {
void appendFile(pair<int, DataMataKuliah> &dataMK) {
    FILE *file;
    file = fopen("datamatkul.dat", "a");
    if (file == NULL) {
        cout << "File Tidak Ditemukan\n";
        return;
    }
    fprintf(file, "(%d, %s, %d, %d, %d, ", dataMK.first, dataMK.second.m_nama,
            dataMK.second.m_sks, dataMK.second.m_kuota, dataMK.second.m_jenis);
    for (auto i : dataMK.second.m_prasyarat) {
        fprintf(file, "%d|", i);
    }
    fprintf(file, ", ");
    for (auto i : dataMK.second.m_jadwal) {
        fprintf(file, "%d|", i);
    }
    fprintf(file, ")\n");
}

void readFile(unordered_map<int, MataKuliah> &MK) {
    FILE *file;
    file = fopen("datamatkul.dat", "r");
    if (file == NULL) {
        cout << "File Tidak Ditemukan\n";
        return;
    }

    fseek(file, 0, SEEK_END);
    const long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    while (ftell(file) < size) {
        int kodeMK;
        DataMataKuliah temp;

        fscanf(file, "(%d, %[^,], %d, %d, %d,", &kodeMK, temp.m_nama,
               &temp.m_sks, &temp.m_kuota, &temp.m_jenis);
        for (int i = 0; i < 5; i++) {
            fscanf(file, "%d|", &temp.m_prasyarat[i]);
        }
        MK[kodeMK] = temp;
        fseek(file, 2, SEEK_CUR);
    }
}
} // namespace filehandler
