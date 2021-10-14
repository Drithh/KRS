#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Siakad.h"
using namespace std;
class Mahasiswa : public Siakad {
    string m_nama;
    string m_nim;

  public:
    Mahasiswa(string nama, string nim) : m_nama(nama), m_nim(nim){};


    void printKRS() {
        cout << "\n===============KRS===============" << endl;
        cout << "Nama: " << m_nama << endl;
        cout << "NIM: " << m_nim << endl;
        Siakad::printKRS();
        cout << "===============KRS==============="
             << "\n\n\n";
    }

    /**
     * @brief Mencetak mata kuliah yang sudah lulus
     */
    void printCourseHistory() {
        cout << "\n==========COURSE HISTORY==========" << endl;
        cout << "Nama: " << m_nama << endl;
        cout << "NIM: " << m_nim << endl;
        Siakad::printCourseHistory();
        cout << "==========COURSE HISTORY=========="
             << "\n\n\n";
    }
};