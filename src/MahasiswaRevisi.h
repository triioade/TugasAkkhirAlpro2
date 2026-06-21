// pewarisan mahasiswa revisi dari mahasiswa biasa (status revisi)


#ifndef MAHASISWAREVISI_H
#define MAHASISWAREVISI_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Mahasiswa.h"

class MahasiswaRevisi : public Mahasiswa
{
public:
    MahasiswaRevisi(
        string nim,
        string nama,
        string email,
        string kelas,
        int tahunMasuk)
        : Mahasiswa(
              nim,
              nama,
              email,
              kelas,
              tahunMasuk)
    {
    }

    string getStatus() override
    {
        return "Revisi";
    }

    void tampilkan() override
    {
        cout << left
             << setw(12) << nim << " | "
             << setw(27) << nama << " | "
             << setw(30) << email << " | "
             << setw(12) << kelas << " | "
             << setw(6) << tahunMasuk << " | "
             << setw(8) << getStatus()
             << endl;
    }

    void tampilkanDetail() override
    {
        cout << left
             << setw(13) << "NIM" << ": " << nim << endl
             << setw(13) << "Nama" << ": " << nama << endl
             << setw(13) << "Email" << ": " << email << endl
             << setw(13) << "Kelas" << ": " << kelas << endl
             << setw(13) << "Tahun Masuk" << ": " << tahunMasuk << endl
             << setw(13) << "Status" << ": " << getStatus() << endl;
    }
};

#endif