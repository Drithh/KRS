#include <bits/stdc++.h>

using namespace std;

struct MataKuliah {
    int kode;
    string nama;
    int sks;
};


int main() {
    vector<vector<string>> data;
    ifstream infile("matkul.txt");

    while (infile) {
        string s;
        if (!getline(infile, s))
            break;

        istringstream ss(s);
        vector<string> record;

        while (ss) {
            string s;
            if (!getline(ss, s, ','))
                break;
            record.push_back(s);
        }

        data.push_back(record);
    }
    for (auto i : data) {
        cout << i[0] << i[1] << i[2] << endl;
    }
    if (!infile.eof()) {
        cerr << "Fooey!\n";
    }
}