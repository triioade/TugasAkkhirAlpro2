#include <iostream>
#include <vector>
#include "src/DataManager.h"
#include "src/SearchSort.h"

using namespace std;

bool bacaPilihan(int &pilihan)
{
    if (!(cin >> pilihan))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInput harus berupa angka!\n";
        return false;
    }

    cin.ignore(10000, '\n');
    return true;
}

void tampilkanMenu()
{
    cout << "\n=================================\n";
    cout << "SISTEM MANAJEMEN MAHASISWA\n";
    cout << "=================================\n";
    cout << "1. Tampilkan Data\n";
    cout << "2. Cari Mahasiswa\n";
    cout << "3. Urutkan Data\n";
    cout << "4. Manajemen Data\n";
    cout << "5. Simpan ke File\n";
    cout << "6. Muat Data dari File\n";
    cout << "0. Keluar\n";
}

void menuTampilkan()
{
    cout << "\n===== TAMPILKAN DATA =====\n";
    cout << "1. Semua Data\n";
    cout << "2. Berdasarkan Kelas\n";
    cout << "3. Berdasarkan Status\n";
    cout << "4. Berdasarkan Kelas dan Status\n";
    cout << "0. Kembali\n";
}

void menuCari()
{
    cout << "\n===== CARI DATA =====\n";
    cout << "1. Cari By NIM (Binary Search)\n";
    cout << "2. Cari By Nama (Linear Search)\n";
    cout << "0. Kembali\n";
}

void menuUrutkan()
{
    cout << "\n===== URUTKAN DATA =====\n";
    cout << "1. Urutkan By NIM (Bubble Sort)\n";
    cout << "2. Urutkan By Nama (Merge Sort)\n";
    cout << "0. Kembali\n";
}

void menuManajemen()
{
    cout << "\n===== MANAJEMEN DATA =====\n";
    cout << "1. Tambah Data\n";
    cout << "2. Edit Data\n";
    cout << "3. Hapus Data\n";
    cout << "0. Kembali\n";
}

int main()
{
    DataManager dm;
    dm.muatFileDefault();
    int pilihan;
    do
    {
        tampilkanMenu();
        cout << "\nPilih Menu : ";
        if (!bacaPilihan(pilihan))
        {
            continue;
        }

        switch (pilihan)
        {
        case 1:
        {
            int sub;
            do
            {
                menuTampilkan();

                cout << "\nPilih : ";
                if (!bacaPilihan(sub))
                {
                    continue;
                }

                switch (sub)
                {
                case 1:
                    dm.tampilkanSemua();
                    break;

                case 2:
                {
                    vector<string> kelasList =
                        dm.getDaftarKelas();

                    cout << "\n===== DAFTAR KELAS =====\n";

                    for (int i = 0; i < kelasList.size(); i++)
                    {
                        cout
                            << i + 1
                            << ". "
                            << kelasList[i]
                            << endl;
                    }

                    int pilih;

                    cout << "\nPilih Kelas : ";
                    if (!bacaPilihan(pilih))
                    {
                        break;
                    }

                    if (
                        pilih < 1 ||
                        pilih > kelasList.size())
                    {
                        cout << "\nPilihan tidak tersedia!\n";
                        break;
                    }

                    dm.tampilkanPerKelas(
                        kelasList[pilih - 1]);

                    break;
                }

                case 3:
                {
                    vector<string> statusList =
                        dm.getDaftarStatus();

                    cout << "\n===== DAFTAR STATUS =====\n";

                    for (int i = 0; i < statusList.size(); i++)
                    {
                        cout
                            << i + 1
                            << ". "
                            << statusList[i]
                            << endl;
                    }

                    int pilih;

                    cout << "\nPilih Status : ";
                    if (!bacaPilihan(pilih))
                    {
                        break;
                    }

                    if (
                        pilih < 1 ||
                        pilih > statusList.size())
                    {
                        cout << "\nPilihan tidak tersedia!\n";
                        break;
                    }

                    dm.tampilkanPerStatus(
                        statusList[pilih - 1]);

                    break;
                }

                case 4:
                {
                    vector<string> kelasList =
                        dm.getDaftarKelas();

                    vector<string> statusList =
                        dm.getDaftarStatus();

                    cout << "\n===== PILIH KELAS =====\n";

                    for (int i = 0; i < kelasList.size(); i++)
                    {
                        cout
                            << i + 1
                            << ". "
                            << kelasList[i]
                            << endl;
                    }

                    int pilihKelas;

                    cout << "\nPilih Kelas : ";
                    if (!bacaPilihan(pilihKelas))
                    {
                        break;
                    }

                    cout << "\n===== PILIH STATUS =====\n";

                    for (int i = 0; i < statusList.size(); i++)
                    {
                        cout
                            << i + 1
                            << ". "
                            << statusList[i]
                            << endl;
                    }

                    int pilihStatus;

                    cout << "\nPilih Status : ";
                    if (!bacaPilihan(pilihStatus))
                    {
                        break;
                    }

                    if (
                        pilihKelas < 1 ||
                        pilihKelas > kelasList.size() ||
                        pilihStatus < 1 ||
                        pilihStatus > statusList.size())
                    {
                        cout << "\nPilihan tidak tersedia!\n";
                        break;
                    }
                    {
                        dm.tampilkanPerKelasDanStatus(
                            kelasList[pilihKelas - 1],
                            statusList[pilihStatus - 1]);
                    }

                    break;
                }

                case 0:
                    break;

                default:
                    cout << "\nPilihan tidak valid\n";
                }

            } while (sub != 0);

            break;
        }

        case 2:
        {
            int sub;

            do
            {
                menuCari();

                cout << "\nPilih : ";
                if (!bacaPilihan(sub))
                {
                    continue;
                }

                switch (sub)
                {
                case 1:
                {
                    string nim;
                    cout << "Masukkan NIM (contoh:241011450004) : ";
                    getline(cin, nim);

                    SearchSort::bubbleSortNIM(
                        dm.getData());

                    int index =
                        SearchSort::binarySearchNIM(
                            dm.getData(),
                            nim);

                    if (index != -1)
                    {
                        cout << "\nData Ditemukan\n";
                        dm.getData()[index]->tampilkanDetail();
                    }
                    else
                    {
                        cout << "\nData Tidak Ditemukan\n";
                    }

                    break;
                }

                case 2:
                {
                    string nama;
                    cout << "Masukkan Nama (contoh :trio) : ";
                    getline(cin, nama);

                    vector<Mahasiswa *> hasil =
                        SearchSort::linearSearchNama(
                            dm.getData(),
                            nama);
                    if (hasil.empty())
                    {
                        cout << "\nData Tidak Ditemukan\n";
                    }
                    else
                    {
                        for (Mahasiswa *m : hasil)
                        {
                            m->tampilkanDetail();
                            cout << "\n";
                        }
                    }
                    break;
                }

                case 0:
                    break;

                default:
                    cout << "\nPilihan tidak valid\n";
                }
            } while (sub != 0);
            break;
        }

        case 3:
        {
            int sub;

            do
            {
                menuUrutkan();

                cout << "\nPilih : ";
                if (!bacaPilihan(sub))
                {
                    continue;
                }

                switch (sub)
                {
                case 1:
                {
                    SearchSort::bubbleSortNIM(
                        dm.getData());
                    cout
                        << "\nData berhasil diurutkan berdasarkan NIM\n";
                    dm.tampilkanSemua();
                    break;
                }

                case 2:
                {
                    SearchSort::mergeSortNama(
                        dm.getData(),
                        0,
                        dm.getData().size() - 1);
                    cout
                        << "\nData berhasil diurutkan berdasarkan Nama\n";
                    dm.tampilkanSemua();
                    break;
                }

                case 0:
                    break;
                default:
                    cout << "\nPilihan tidak valid\n";
                }

            } while (sub != 0);
            break;
        }

        case 4:
        {
            int sub;

            do
            {
                menuManajemen();

                cout << "\nPilih : ";
                if (!bacaPilihan(sub))
                {
                    continue;
                }
                switch (sub)
                {
                case 1:
                    dm.tambahData();
                    break;

                case 2:
                    dm.editData();
                    break;

                case 3:
                    dm.hapusData();
                    break;

                case 0:
                    break;

                default:
                    cout << "\nPilihan tidak valid\n";
                }
            } while (sub != 0);
            break;
        }

        case 5:
            dm.simpanFile();
            break;

        case 6:
            dm.muatFile();
            break;

        case 0:
            cout << "\nProgram Selesai\n";
            break;

        default:
            cout << "\nPilihan tidak valid\n";
        }

    } while (pilihan != 0);

    return 0;
}
