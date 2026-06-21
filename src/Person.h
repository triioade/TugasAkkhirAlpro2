// kelas induk sebelum di get mahasiswa (buat pewarisan,polimorfisme)


#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string nama;
    string email;

public:
    Person() {}
    Person(string nama, string email)
    {
        this->nama = nama;
        this->email = email;
    }
    string getNama()
    {
        return nama;
    }
    string getEmail()
    {
        return email;
    }
    virtual string getStatus() = 0;
    virtual void tampilkan() = 0;
    virtual void tampilkanDetail() = 0;
    virtual ~Person() {}
};

#endif
// (ok )