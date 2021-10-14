#pragma once
#include <iostream>
#include <utility>
#include "Siakad.h"

using namespace std;

namespace Tool {
string jenisTeks[2] = {"Wajib", "Pilihan"};
string hari[7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

auto convertTimeToString(pair<int, int> time) -> string {
    string hours = to_string(time.second / 60);
    string minutes = to_string(time.second % 60);
    return hari[time.first] + string(8 - hari[time.first].length(), ' ') + " " +
           string(2 - hours.length(), '0') + hours + ":" + string(2 - minutes.length(), '0') + minutes;
}


} // namespace Tool