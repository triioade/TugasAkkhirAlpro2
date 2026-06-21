# SISTEM MANAJEMEN DATA MAHASISWA (C++)

## Cara Menjalankan Program
### Persyaratan

* Sistem Operasi Windows
* File project sudah diekstrak (Extract ZIP)

### Langkah Menjalankan

1. Ekstrak file ZIP project ke folder yang diinginkan.
2. Buka folder hasil ekstraksi.
3. Jalankan file:
main.exe
4. Program akan langsung menampilkan menu utama:


=================================
SISTEM MANAJEMEN MAHASISWA
=================================
1. Tampilkan Data
2. Cari Mahasiswa
3. Urutkan Data
4. Manajemen Data
5. Simpan ke File
6. Muat Data dari File
0. Keluar


### Catatan

* Jangan memindahkan file `data/mahasiswa.txt` dari folder project.
* Program otomatis memuat `data/mahasiswa.txt` saat dijalankan jika file ada.
* Menu **Muat Data dari File** dapat memuat file `.txt` lain dari folder `data/`.
* Jika data baru memiliki NIM yang sama dengan data yang sudah ada, file tersebut tidak akan ditambahkan dan program akan menampilkan catatan duplikat.
* Perubahan data dapat disimpan menggunakan menu **Simpan ke File**.

---

## Deskripsi Program

Program ini merupakan aplikasi manajemen data mahasiswa berbasis console yang dibuat menggunakan bahasa C++ dengan menerapkan konsep:

* Object Oriented Programming (OOP)
* File Input/Output (File I/O)
* Array / Vector dan Pointer
* Searching Algorithm
* Sorting Algorithm
* Regular Expression (Regex)
* Exception Handling (Try-Catch)

Program digunakan untuk mengelola data mahasiswa berdasarkan:

* NIM
* Nama
* Email
* Kelas
* Tahun Masuk
* Status (Aktif / Revisi)

---

## Struktur File Project

### 1. Person.h

Class induk (Parent Class) yang menyimpan atribut dasar identitas.

Fungsi:

* Menyimpan data nama
* Menjadi dasar pewarisan (Inheritance)

---

### 2. Mahasiswa.h

Class utama mahasiswa yang mewarisi Person.

Fitur:

* Enkapsulasi data mahasiswa
* Getter dan Setter
* Virtual Function untuk Polymorphism

Data:

* NIM
* Nama
* Email
* Kelas
* Tahun Masuk

---

### 3. MahasiswaAktif.h

Class turunan dari Mahasiswa.

Status:

* Aktif

Implementasi:

* Method getStatus()
* Method tampilkan()

---

### 4. MahasiswaRevisi.h

Class turunan dari Mahasiswa.

Status:

* Revisi

Implementasi:

* Method getStatus()
* Method tampilkan()

---

### 5. DataManager.h

Class yang bertanggung jawab mengelola seluruh data mahasiswa.

Fitur:

* Tambah Data
* Edit Data
* Hapus Data
* Tampilkan Data
* Simpan File
* Muat File
* Filter Kelas
* Filter Status

Konsep:

* CRUD
* File I/O
* Regex
* Exception Handling

---

### 6. SearchSort.h

Berisi algoritma pencarian dan pengurutan data.

Searching:

* Linear Search Nama
* Binary Search NIM

Sorting:

* Bubble Sort NIM
* Merge Sort Nama

---

### 7. main.cpp

File utama program.

Tanggung Jawab:

* Menampilkan Menu
* Menerima Input User
* Menghubungkan seluruh fitur program

---

### 8. data/mahasiswa.txt

File database sederhana untuk menyimpan seluruh data mahasiswa.

Format:

NIM|Nama|Email|Kelas|TahunMasuk|Status
Contoh:
241011450004|TRIO ADE PAMUNGKAS|trioemailtest@gmail.com|03TPLE001|2024|Aktif

## Fitur Program

### 1. Tampilkan Data

Sub Menu:

* Tampilkan Semua Data
* Tampilkan Berdasarkan Kelas
* Tampilkan Berdasarkan Status
* Tampilkan Berdasarkan Kelas dan Status

### 2. Cari Mahasiswa

Metode:

1. Binary Search (NIM)
2. Linear Search (Nama)

### 3. Urutkan Data

Metode:

1. Bubble Sort (NIM)
2. Merge Sort (Nama)

### 4. Manajemen Data

Fitur:

* Tambah Data
* Edit Data
* Hapus Data

### 5. Simpan ke File

Menyimpan seluruh data mahasiswa ke file `data/mahasiswa.txt`.

### 6. Muat Data dari File

Membaca data mahasiswa dari file `.txt` yang dipilih di folder `data/`.
Jika NIM sudah ada di data, catatan tersebut tidak akan ditambahkan dan akan diberi tahu sebagai duplikat.

---

## Implementasi OOP
### Encapsulation

Data mahasiswa disimpan dalam atribut private dan diakses melalui getter dan setter.

### Inheritance

Person
↓
Mahasiswa
↓
MahasiswaAktif
MahasiswaRevisi

### Polymorphism

Method:

virtual string getStatus()

Di-override oleh:

* MahasiswaAktif
* MahasiswaRevisi

---

## Implementasi Regex

Regex digunakan untuk validasi:

* Email
* NIM

---

## Implementasi Exception Handling

Menggunakan:
try
catch

Untuk menangani:

* Kesalahan input
* Data tidak ditemukan
* Kesalahan pembacaan file

---

## Analisis Time Complexity

| Fitur              | Kompleksitas |
| ------------------ | ------------ |
| Linear Search Nama | O(n)         |
| Binary Search NIM  | O(log n)     |
| Bubble Sort NIM    | O(n²)        |
| Merge Sort Nama    | O(n log n)   |

---

## Best Practice yang Digunakan

* Penamaan variabel yang jelas
* Modularisasi kode per file
* Komentar pada bagian penting
* Pemisahan logika program dan tampilan menu
* Penggunaan OOP untuk mempermudah pengembangan

---

## Kesimpulan

Program berhasil memenuhi seluruh requirement tugas:

- Array / Vector
- Pointer
- Function
- File I/O
- OOP
- Encapsulation
- Inheritance
- Polymorphism
- Linear Search
- Binary Search
- Bubble Sort
- Merge Sort
- Regex
- Try-Catch Exception
- Time Complexity Analysis
- Modularisasi Program