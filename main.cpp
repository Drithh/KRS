#include <iostream>
#include <string.h>
#include "Mahasiswa.h"
using namespace std;



int main() {

    Mahasiswa udin("Udin Nidu", "M0520012");
    // udin.printCourses();

    udin.addKRS(1, 1);
    udin.addKRS(1, 1);
    udin.addKRS(1, 1);
    udin.printKRS();

    Mahasiswa siti("Siti Itis", "M0520022");
    siti.addKRS(1, 1);
    siti.printKRS();
    // udin.setLulus(1, 0);

    // udin.printKRS();

    // udin.printCourses();
}

//
