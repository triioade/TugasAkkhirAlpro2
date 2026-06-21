// kelas mahasiswa idnuk yang diwariskan dari person (nim, kelas, tahun masuk)


#ifndef MAHASISWA_H
#define MAHASISWA_H

#include "Person.h"

class Mahasiswa : public Person
{
protected:
    string nim;
    string kelas;
    int tahunMasuk;

public:
    Mahasiswa() {}

    Mahasiswa(
        string nim,
        string nama,
        string email,
        string kelas,
        int tahunMasuk
    ) : Person(nama, email)
    {
        this->nim = nim;
        this->kelas = kelas;
        this->tahunMasuk = tahunMasuk;
    }

    string getNim()
    {
        return nim;
    }

    string getKelas()
    {
        return kelas;
    }

    int getTahunMasuk()
    {
        return tahunMasuk;
    }

    void setNama(string nama)
    {
        this->nama = nama;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    void setKelas(string kelas)
    {
        this->kelas = kelas;
    }

    void setTahunMasuk(int tahunMasuk)
    {
        this->tahunMasuk = tahunMasuk;
    }
};

#endif