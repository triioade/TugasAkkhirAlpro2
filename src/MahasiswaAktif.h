// pewarisan mahasiswa aktif dari mahasiswa biasa (status aktif)

#ifndef MAHASISWAAKTIF_H
#define MAHASISWAAKTIF_H
#include "Mahasiswa.h"
#include <iomanip>



class MahasiswaAktif : public Mahasiswa
{
public:
    MahasiswaAktif(
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
        return "Aktif";
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