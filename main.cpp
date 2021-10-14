#include <iostream>
#include <string.h>
#include "Mahasiswa.h"
using namespace std;



int main() {


    Mahasiswa udin;
    udin.addMataKuliah(2, 1);
    udin.displayKRS();
    udin.setLulus(2, 1);
    // udin.searchMataKuliah(2);
}
