#include "MataKuliah.h"
#include "DataMataKuliah.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Siakad {
    vector<MataKuliah> courses;

  public:
    Siakad();
    vector<MataKuliah>::iterator searchMataKuliah(int kode) {
        return find_if(courses.begin(), courses.end(),
                       [kode](const MataKuliah &MK) -> bool { return kode == MK.getKode(); });
    }
    vector<MataKuliah>::iterator searchMataKuliah(string nama) {
        return find_if(courses.begin(), courses.end(),
                       [nama](const MataKuliah &MK) -> bool { return nama == MK.getNama(); });
    }
    void displayMataKuliah() {
        for (auto course : courses) {
            printMataKuliah(course);
        }
    }

    void printMataKuliah(MataKuliah &course) {
        cout << "Kode Mata Kuliah: " << course.getKode()
             << "\nNama Mata Kuliah: " << course.getNama() << "\nJumlah SKS: " << course.getSks()
             << "\nJenis: " << course.getJenis() << endl;
        cout << (course.getPrasyarat().empty() ? "Prasyarat Tidak Ada" : "Prasyarat :") << endl;
        for (int kodePrasyarat : course.getPrasyarat()) {
            auto prasyarat = searchMataKuliah(kodePrasyarat);
            if (!prasyarat->getLulus()) {
                cout << "\t" << prasyarat->getNama() << endl;
            }
        }
        cout << "Jadwalnya :" << endl;
        for (auto jadwal : course.getJadwal()) {
            cout << "\t" << Tool::convertTimeToString(jadwal) << endl;
        }
        cout << "\n\n";
    }
};

Siakad::Siakad() {
    courses.push_back((DataMataKuliah){
        1, "Konsep Pemrograman", 4, 20, 1, {3, 2}, {{1, 900}, {3, 600}, {5, 420}}});
    courses.push_back(
        (DataMataKuliah){2, "Kalkulus 1", 3, 25, 1, {}, {{1, 900}, {3, 600}, {5, 420}}});
    courses.push_back(
        (DataMataKuliah){3, "Sistem Digital", 4, 20, 2, {3, 2}, {{1, 900}, {3, 600}, {5, 420}}});
    courses.push_back((DataMataKuliah){
        1, "Konsep Pemrograman", 4, 20, 2, {3, 2}, {{1, 900}, {3, 600}, {5, 420}}});
}