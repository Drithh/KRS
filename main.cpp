#include <iostream>
#include <string.h>
#include "Siakad.h"
#include "Mahasiswa.h"
using namespace std;



int main() {
    Siakad siakad;
    siakad.searchMataKuliah(2);


    Mahasiswa udin;
    udin.addMataKuliah(siakad.confirmMataKuliah(2, 1));
    udin.displayKRS();
    udin.setLulus(2, 1);
    siakad.searchMataKuliah(2);
}
