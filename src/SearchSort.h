// algo pencarian full ()


#ifndef SEARCHSORT_H
#define SEARCHSORT_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include "Mahasiswa.h"

using namespace std;

class SearchSort
{
public:
    // helper insensitive search
    static string toLower(const string &s)

    {
        string r = s;
        for (char &c : r)
        {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        return r;
    }

    // LINEAR SEARCH NAMA (kecil besar / case insensitive/1 kata/)
static vector<Mahasiswa *> linearSearchNama(
    vector<Mahasiswa *> &data,
    string nama)
{
    vector<Mahasiswa *> hasil;

    string namaLower = toLower(nama);

    for (Mahasiswa *m : data)
    {
        if (
            toLower(m->getNama()).find(namaLower)
            != string::npos
        )
        {
            hasil.push_back(m);
        }
    }
    return hasil;
}

    // BINARY SEARCH NIM
    // Data harus diurut nim dulu (lama)

    static int binarySearchNIM(
        vector<Mahasiswa *> &data,
        string nim)
    {
        int kiri = 0;
        int kanan = data.size() - 1;
        while (kiri <= kanan)
        {
            int tengah = (kiri + kanan) / 2;
            if (data[tengah]->getNim() == nim)
            {
                return tengah;
            }
            if (data[tengah]->getNim() < nim)
            {
                kiri = tengah + 1;
            }
            else
            {
                kanan = tengah - 1;
            }
        }
        return -1;
    } 
// done 

    // BUBBLE SORT NIM ( backup search untuk binary search nim)

    static void bubbleSortNIM(
        vector<Mahasiswa *> &data)
    {
        int n = data.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (
                    data[j]->getNim() >
                    data[j + 1]->getNim())
                {
                    swap(
                        data[j],
                        data[j + 1]);
                }
            }
        }
    }
private:

    // MERGE SORT NAMA (backup search untuk linear search nama)

    static void merge(
        vector<Mahasiswa *> &data,
        int kiri,
        int tengah,
        int kanan)
    {
        vector<Mahasiswa *> kiriData;
        vector<Mahasiswa *> kananData;
        for (int i = kiri; i <= tengah; i++)
        {
            kiriData.push_back(data[i]);
        }
        for (int i = tengah + 1; i <= kanan; i++)
        {
            kananData.push_back(data[i]);
        }
        int i = 0;
        int j = 0;
        int k = kiri;
        while (
            i < kiriData.size() &&
            j < kananData.size())
        {
            if (
                kiriData[i]->getNama() <=
                kananData[j]->getNama())
            {
                data[k] = kiriData[i];
                i++;
            }

            else
            {
                data[k] = kananData[j];
                j++;
            }
            k++;
        }

        while (i < kiriData.size())
        {
            data[k] = kiriData[i];
            i++;
            k++;
        }

        while (j < kananData.size())
        {
            data[k] = kananData[j];
            j++;
            k++;
        }
    }



public:

    // MERGE SORT NAMA (ok)

    static void mergeSortNama(
        vector<Mahasiswa *> &data,
        int kiri,
        int kanan)
    {

        if (kiri < kanan)
        {
            int tengah =
                kiri +
                (kanan - kiri) / 2;

            mergeSortNama(
                data,
                kiri,
                tengah);

            mergeSortNama(
                data,
                tengah + 1,
                kanan);

            merge(
                data,
                kiri,
                tengah,
                kanan);
        }
    }

    // TAMPILKAN DATA

    static void tampilkanData(
        vector<Mahasiswa *> &data)
    {

        if (data.empty())
        {
            cout
                << "\nTidak ada data ditemukan.\n";
            return;
        }
        cout << "\n";

        cout << left
             << setw(12) << "NIM" << " | "
             << setw(27) << "NAMA" << " | "
             << setw(30) << "EMAIL" << " | "
             << setw(12) << "KELAS" << " | "
             << setw(6) << "TAHUN" << " | "
             << setw(8) << "STATUS" << "\n";

        cout << "---------------------------------------------------------------------------------------------------" << "\n";


        
        for (Mahasiswa *m : data)
        {
            m->tampilkan();
        }
    }
};

#endif

// (ok )