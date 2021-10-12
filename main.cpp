#include <iostream>
#include <string.h>
#include <unordered_map>

#include "DataMataKuliah.h"
#include "MataKuliah.h"
#include "FileHandler.h"
using namespace std;



class KRS {
    unordered_map<int, MataKuliah> courses;

  public:
    KRS() {
        filehandler::readFile(courses);
    }
};

int main() {
    filehandler::appendFile({2, {"Konsep Pemrograman", 4, 30, 2, {3}}});



    // for (auto &i : courses) {
    //     cout << "Nama:" << i.second.getNama() << "\nSKS:" <<
    //     i.second.getSks()
    //          << "\nKuota:" << i.second.getKuota()
    //          << "\nJenis:" << i.second.getJenis() << endl;
    //     for (auto j : i.second.getPrasyarat()) {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
}
