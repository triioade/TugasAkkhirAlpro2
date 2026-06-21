// file admin crud (jangan ubah string)

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iomanip>

#include "MahasiswaAktif.h"
#include "MahasiswaRevisi.h"

using namespace std;

class DataManager
{
private:
    vector<Mahasiswa *> data;
public:
    DataManager() {}
    ~DataManager()
    {
        for (Mahasiswa *m : data)
        {
            delete m;
        }
    }
    vector<string> getDaftarKelas()
    {
        vector<string> daftar;

        for (Mahasiswa *m : data)
        {
            bool ada = false;

            for (string k : daftar)
            {
                if (k == m->getKelas())
                {
                    ada = true;
                    break;
                }
            }

            if (!ada)
            {
                daftar.push_back(
                    m->getKelas());
            }
        }

        return daftar;
    }

    vector<string> getDaftarStatus()
    {
        vector<string> daftar;

        for (Mahasiswa *m : data)
        {
            bool ada = false;

            for (string s : daftar)
            {
                if (s == m->getStatus())
                {
                    ada = true;
                    break;
                }
            }

            if (!ada)
            {
                daftar.push_back(
                    m->getStatus());
            }
        }

        return daftar;
    }

    vector<Mahasiswa *> &getData()
    {
        return data;
    }

    // TAMPILKAN DATA

    void tampilkanSemua()
    {
        cout << "\n";
        cout << left
             << setw(12) << "NIM" << " | "
             << setw(27) << "NAMA" << " | "
             << setw(30) << "EMAIL" << " | "
             << setw(12) << "KELAS" << " | "
             << setw(6) << "TAHUN" << " | "
             << setw(8) << "STATUS" << "\n";

        cout << "-------------------------------------------------------------------------------------------" << "\n";

        for (Mahasiswa *m : data)
        {
            m->tampilkan();
        }
    }

    void tampilkanPerKelas(string kelas)
    {
        cout << "\n===== DATA KELAS " << kelas << " =====\n";

        cout << left
             << setw(12) << "NIM" << " | "
             << setw(27) << "NAMA" << " | "
             << setw(30) << "EMAIL" << " | "
             << setw(12) << "KELAS" << " | "
             << setw(6) << "TAHUN" << " | "
             << setw(8) << "STATUS" << "\n";

        cout << "-------------------------------------------------------------------------------------------" << "\n";

        for (Mahasiswa *m : data)
        {
            if (m->getKelas() == kelas)
            {
                m->tampilkan();
            }
        }
    }

    void tampilkanPerStatus(string status)
    {
        cout << "\n===== DATA STATUS " << status << " =====\n";

        cout << left
             << setw(12) << "NIM" << " | "
             << setw(27) << "NAMA" << " | "
             << setw(30) << "EMAIL" << " | "
             << setw(12) << "KELAS" << " | "
             << setw(6) << "TAHUN" << " | "
             << setw(8) << "STATUS" << "\n";

        cout << "-------------------------------------------------------------------------------------------" << "\n";

        for (Mahasiswa *m : data)
        {
            if (m->getStatus() == status)
            {
                m->tampilkan();
            }
        }
    }

    void tampilkanPerKelasDanStatus(
        string kelas,
        string status)
    {
        cout << "\n===== DATA " << kelas
             << " - " << status << " =====\n";

        cout << left
             << setw(12) << "NIM" << " | "
             << setw(27) << "NAMA" << " | "
             << setw(30) << "EMAIL" << " | "
             << setw(12) << "KELAS" << " | "
             << setw(6) << "TAHUN" << " | "
             << setw(8) << "STATUS" << "\n";

        cout << "-------------------------------------------------------------------------------------------" << "\n";

        for (Mahasiswa *m : data)
        {
            if (
                m->getKelas() == kelas &&
                m->getStatus() == status)
            {
                m->tampilkan();
            }
        }
    }

    // TABAH DATA

    void tambahData()
    {
        try
        {
            string nim;
            string nama;
            string email;
            string kelas;
            int tahunMasuk;

            cout << "\nNIM : ";
            cin >> nim;

            regex nimRegex("^[0-9]{12}$");

            if (!regex_match(nim, nimRegex))
            {
                throw invalid_argument(
                    "NIM harus terdiri dari 12 digit angka");
            }

            cin.ignore();

            cout << "Nama : ";
            getline(cin, nama);

            cout << "Email : ";
            getline(cin, email);

            regex emailRegex(
                "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

            if (!regex_match(email, emailRegex))
            {
                throw invalid_argument(
                    "Format email tidak valid");
            }

            cout << "Kelas : ";
            getline(cin, kelas);

            cout << "Tahun Masuk : ";
            cin >> tahunMasuk;

            if (tahunMasuk >= 2024)
            {
                data.push_back(
                    new MahasiswaAktif(
                        nim,
                        nama,
                        email,
                        kelas,
                        tahunMasuk));
            }
            else
            {
                data.push_back(
                    new MahasiswaRevisi(
                        nim,
                        nama,
                        email,
                        kelas,
                        tahunMasuk));
            }

            cout << "\nData berhasil ditambahkan.\n";

            cout << "\n===== DATA TERBARU =====\n";
            data.back()->tampilkan();
        }
        catch (exception &e)
        {
            cout << "\nError : "
                 << e.what()
                 << endl;
        }
    }

    // EDIT DATA

    void editData()
    {
        try
        {
            string cariNim;

            cout << "\nMasukkan NIM yang akan diedit : ";
            cin >> cariNim;

            bool ditemukan = false;

            for (int i = 0; i < data.size(); i++)
            {
                if (data[i]->getNim() == cariNim)
                {
                    ditemukan = true;

                    string namaBaru;
                    string emailBaru;
                    string kelasBaru;
                    int tahunBaru;

                    cin.ignore();

                    cout << "Nama Baru : ";
                    getline(cin, namaBaru);

                    cout << "Email Baru : ";
                    getline(cin, emailBaru);

                    cout << "Kelas Baru : ";
                    getline(cin, kelasBaru);

                    cout << "Tahun Masuk Baru : ";
                    cin >> tahunBaru;

                    regex emailRegex(
                        "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

                    if (!regex_match(emailBaru, emailRegex))
                    {
                        throw invalid_argument(
                            "Format email tidak valid");
                    }

                    delete data[i];

                    if (tahunBaru >= 2024)
                    {
                        data[i] = new MahasiswaAktif(
                            cariNim,
                            namaBaru,
                            emailBaru,
                            kelasBaru,
                            tahunBaru);
                    }
                    else
                    {
                        data[i] = new MahasiswaRevisi(
                            cariNim,
                            namaBaru,
                            emailBaru,
                            kelasBaru,
                            tahunBaru);
                    }

                    cout << "\nData berhasil diperbarui.\n";
                    cout << "\n===== DATA TERBARU =====\n";
                    data[i]->tampilkan();

                    break;
                }
            }

            if (!ditemukan)
            {
                cout << "\nNIM tidak ditemukan.\n";
            }
        }
        catch (exception &e)
        {
            cout << "\nError : "
                 << e.what()
                 << endl;
        }
    }

    // HAPUS DATA

    void hapusData()
    {
        string cariNim;

        cout << "\nMasukkan NIM yang akan dihapus : ";
        cin >> cariNim;

        bool ditemukan = false;

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i]->getNim() == cariNim)
            {
                ditemukan = true;

                cout << "\nData ditemukan:\n";
                data[i]->tampilkan();

                char konfirmasi;

                cout << "\nYakin hapus data? (Y/T) : ";
                cin >> konfirmasi;

                if (toupper(konfirmasi) == 'Y')
                {
                    delete data[i];

                    data.erase(data.begin() + i);

                    cout << "\nData berhasil dihapus.\n";
                }
                else
                {
                    cout << "\nPenghapusan dibatalkan.\n";
                }

                break;
            }
        }

        if (!ditemukan)
        {
            cout << "\nNIM tidak ditemukan.\n";
        }
    }

    // FILE I/O

    void clearData()
    {
        for (Mahasiswa *m : data)
        {
            delete m;
        }
        data.clear();
    }

    bool adaNIM(const string &nim)
    {
        for (Mahasiswa *m : data)
        {
            if (m->getNim() == nim)
            {
                return true;
            }
        }
        return false;
    }

    void muatFileDefault()
    {
        string fullPath = "data/mahasiswa.txt";
        ifstream file(fullPath);

        if (!file.is_open())
        {
            return;
        }

        clearData();
        muatDariPath(file, fullPath, true, false);
    }

    void muatDariPath(ifstream &file, const string &fullPath, bool clearBeforeLoad = false, bool showDuplicateMessages = false)
    {
        if (clearBeforeLoad)
        {
            clearData();
        }

        string line;
        int loadedCount = 0;
        int duplicateCount = 0;

        while (getline(file, line))
        {
            // Lewati baris kosong
            if (line.empty() || line.length() < 10)
            {
                continue;
            }

            stringstream ss(line);

            string nim;
            string nama;
            string email;
            string kelas;
            string tahunStr;
            string status;

            getline(ss, nim, '|');
            getline(ss, nama, '|');
            getline(ss, email, '|');
            getline(ss, kelas, '|');
            getline(ss, tahunStr, '|');
            getline(ss, status, '|');

            if (nim.empty())
            {
                continue;
            }

            int tahunMasuk;

            try
            {
                tahunMasuk = stoi(tahunStr);
            }
            catch (exception &)
            {
                cout << "\nBaris file tidak valid:\n";
                cout << line << endl;
                continue;
            }

            if (adaNIM(nim))
            {
                duplicateCount++;
                if (showDuplicateMessages)
                {
                    cout << "Data atas nama: " << nama << " sudah ada di data dan dilewati.\n";
                }
                continue;
            }

            if (status == "Aktif")
            {
                data.push_back(
                    new MahasiswaAktif(
                        nim,
                        nama,
                        email,
                        kelas,
                        tahunMasuk));
            }
            else
            {
                data.push_back(
                    new MahasiswaRevisi(
                        nim,
                        nama,
                        email,
                        kelas,
                        tahunMasuk));
            }
            loadedCount++;
        }

        file.close();

        cout << "\n";
        if (loadedCount > 0)
        {
            cout << loadedCount << " data berhasil dimuat dari " << fullPath << ".\n";
        }
        else if (duplicateCount > 0 && !showDuplicateMessages)
        {
            cout << duplicateCount << " data duplikat ditemukan di " << fullPath << ". Tidak ada data baru yang dimuat.\n";
        }
        else if (loadedCount == 0 && duplicateCount == 0)
        {
            cout << "Tidak ada data baru yang dimuat dari " << fullPath << ".\n";
        }

        if (showDuplicateMessages && duplicateCount > 0)
        {
            cout << duplicateCount << " data duplikat dilewati.\n";
        }
    }

    void simpanFile()
    {
        string fileName = "data/mahasiswa.txt";
        ofstream file(fileName);

        if (!file.is_open())
        {
            cout << "Gagal membuka file: " << fileName << "\n";
            return;
        }

        for (Mahasiswa *m : data)
        {
            file
                << m->getNim() << "|"
                << m->getNama() << "|"
                << m->getEmail() << "|"
                << m->getKelas() << "|"
                << m->getTahunMasuk() << "|"
                << m->getStatus()
                << endl;
        }

        file.close();

        cout << "\nData berhasil disimpan ke file mahasiswa.txt (file master)\n";
    }

    void muatFile()
    {
        string fileName;

        cout << "\nMasukkan nama file di folder data (contoh: data03TPLE10.txt): ";
        getline(cin, fileName);

        if (fileName.empty())
        {
            cout << "Nama file tidak boleh kosong.\n";
            return;
        }

        if (fileName.size() < 4 || fileName.substr(fileName.size() - 4) != ".txt")
        {
            cout << "File harus berekstensi .txt.\n";
            return;
        }

        string fullPath = "data/" + fileName;
        ifstream file(fullPath);

        if (!file.is_open())
        {
            cout << "File " << fullPath << " belum ditemukan.\n";
            return;
        }

        cout << "\nMenambahkan data baru dari " << fullPath << "...\n";
        muatDariPath(file, fullPath, false, true);
    }
};

#endif

// ok
