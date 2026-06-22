#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// KONSTANTA YANG AKAN DIGUNAKAN
#define MAX_HADIAH 100
#define MAX_GERAK 100
#define Selesai "##"

// Ukuran papan simulasi
#define panjang_papan 20
#define lebar_papan 50

// STRUKTUR BUAT PENEMPATAN HADIAH
typedef struct {
    int x;
    int y;
    char nama[50];
    int skor;
} Hadiah;

// STRUKTUR BUAT GERAK O
typedef struct {
    int x;
    int y;
} Gerak;


// MESIN ABSTRAK
void start(char* nama_file);
void baca(char* kata_output);
int endKata();


// FITUR HADIAH
void bacaFileHadiah(Hadiah list_hadiah[], int *jumlah_hadiah);
void menuTambahHadiah();


// FITUR GERAK (DISESUAIKAN TOTAL DENGAN FUNCTION.C LU)
void bacaGerak(Gerak arr[], int *n);
void tulisSemuaGerak(Gerak arr[], int n);
void tampilTabelGerak(Gerak arr[], int n);
void inputGerak(int x, int y);
void menuTambahGerak(); // DISESUAIKAN: Jadi kosong tanpa parameter


// SORTING
void urutkanHadiah(Hadiah arr[], int n);


// VALIDASI
int cekValidasiGerak(int x, int y);


// UI MENU
void tampilMenu(); // DISESUAIKAN: Mengganti 'void menu()' agar sinkron dengan function.c


// SIMULASI LITE O
void wait(float x); // FUNGSI ANIMASI DARI PDF
void inisialisasiPapan(char papan[][lebar_papan], int panjang, int lebar);
void tempatkanHadiah(char papan[][lebar_papan], Hadiah arr[], int n);
void cetakPapan(char papan[][lebar_papan], int panjang, int lebar, int skor);
int  cekCollision(Hadiah arr[], int n, int ox, int oy, int *idxHit);

#endif