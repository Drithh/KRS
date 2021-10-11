#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

namespace filehandler {
void appendFile(pair<int, DataMataKuliah> dataMK) {
    FILE *file;
    file = fopen("datamatkul.dat", "a");
    if (file == NULL) {
        cout << "File Tidak Ditemukan\n";
        return;
    }
    fprintf(file, "(%d, %s, %d, %d, %d, ", dataMK.first, dataMK.second.nama,
            dataMK.second.sks, dataMK.second.kuota, dataMK.second.jenis);
    for (auto i : dataMK.second.prasyarat) {
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
    int kodeMK;
    DataMataKuliah temp;

    fscanf(file, "(%d, %[^,], %d, %d, %d,", &kodeMK, temp.nama, &temp.sks,
           &temp.kuota, &temp.jenis);
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%d|", &temp.prasyarat[i]);
    }

    MK[kodeMK] = temp;
}
} // namespace filehandler


// char temp[50];
// fgets(temp, 50, file);
// cout << ftell(file) << endl;