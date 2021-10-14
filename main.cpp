#include <iostream>
#include <string.h>
#include "Mahasiswa.h"
using namespace std;

void casePrasyarat();
void caseKuota();
void caseTubrukan();

int main() {
    // casePrasyarat();
    // caseKuota();
    caseTubrukan();
}

void caseTubrukan() {
    Mahasiswa mahasiswa1("Mahasiwa1", "M05200012");
    mahasiswa1.searchCourse("Konsep Pemrograman"); // Mencari matkul konsep pemrograman
    cin.get();
    mahasiswa1.addKRS(1, 1); // menambahkan matkul konpro ke KRS
    cin.get();
    mahasiswa1.printKRS(); // mencetak krs
    cin.get();

    mahasiswa1.searchCourse("Kalkulus 1"); // Mencari matkul kalkulus 1
    cin.get();
    mahasiswa1.addKRS(2, 1); // mencoba menambahkan matkul kalkulus, tapi gagal
    cin.get();
    mahasiswa1.printKRS(); // mencetak krs
    cin.get();
}


void caseKuota() {
    Mahasiswa mahasiswa1("Mahasiwa1", "M05200012");
    mahasiswa1.printCourses(); // mahasiswa1 mencetak semua course yang bisa diambil olehnya
    cin.get();
    mahasiswa1.addKRS(2, 2); // mahasiswa1 mengambil kelas kalkulus 2 dengan kuota 2 (kelas 2)
    cin.get();
    mahasiswa1.printKRS(); // mahasiswa1 berhasil mengambil kalkulus 2
    cin.get();


    Mahasiswa mahasiswa2("Mahasiwa2", "M05200013");
    mahasiswa2.searchCourse("Kalkulus 1"); // mahasiswa2 mencari kalkulus1 kuota sisa 1 untuk kelas 2
    cin.get();
    mahasiswa2.addKRS(2, 2); // berhasil menambahkan ke krs
    cin.get();

    Mahasiswa mahasiswa3("Mahasiwa3", "M05200014");
    mahasiswa3.searchCourse("Kalkulus 1"); // mahasiswa3 mencari kalkulus1 kuota sudah 0 untuk kelas 2
    cin.get();
    mahasiswa3.addKRS(2, 2); // gagal menambahkan ke krs
    cin.get();
    mahasiswa3.printKRS(); // krs kosong
}

void casePrasyarat() {
    Mahasiswa mahasiswa1("Mahasiwa1", "M05200012");
    mahasiswa1.searchCourse("DAA"); // Mempunyai prasyarat SD dan Algo
    cin.get();
    mahasiswa1.searchCourse("SD dan Algo"); // Mempunyai prasyarat Konsep Pemrograman
    cin.get();
    mahasiswa1.addKRS(5, 2); // Mencoba mengambil  SD dan Algo di kelas ke 2 tapi gagal
    cin.get();


    mahasiswa1.searchCourse("Konsep Pemrograman"); // Karena diberitahu belum lulus MK Konpro maka mencari
    cin.get();
    mahasiswa1.addKRS(1, 2); // Mengambil Konpro di kelas 2
    cin.get();
    mahasiswa1.printKRS(); // Melihat KRS terisi konpro
    cin.get();


    mahasiswa1.setLulus(1, 1); // Lulus MK kode 1 (Konpro)
    cin.get();
    mahasiswa1.printKRS(); // Melihat KRS sudah kosong
    cin.get();


    mahasiswa1.addKRS(5, 2); // Mengambil SD dan Algo di kelas 2
    cin.get();
    mahasiswa1.setLulus(5, 1);
    cin.get();


    mahasiswa1.searchCourse("DAA");
    cin.get();
    mahasiswa1.addKRS(8, 2); // Mengambil kelas DAA
    cin.get();


    mahasiswa1.printKRS();
    cin.get();
    mahasiswa1.setLulus(8, 1);
    cin.get();

    mahasiswa1.printCourseHistory();
}
