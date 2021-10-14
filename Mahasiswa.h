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
};