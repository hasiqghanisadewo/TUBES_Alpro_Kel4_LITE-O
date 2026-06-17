#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Konstanta yang akan dipakai
#define MAX_HADIAH 100
#define MAX_GERAK 100
#define Selesai "##"

// Ukuran papan simulasi
#define panjang_papan 20
#define lebar_papan 50

// Struktur buat penempatan hadiah
typedef struct {
    int x;
    int y;
    char nama[50];
    int skor;
} Hadiah;

// Struktur buat gerak
typedef struct {
    int x;
    int y;
} Gerak;

// Fungsi animasi dari pdf
void wait(float x);

// Mesin Abstrak
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


// UI & SIMULASI
void tampilMenu(); // DISESUAIKAN: Mengganti 'void menu()' agar sinkron dengan function.c
void simulasiLiteO(Hadiah list_hadiah[], int jh, Gerak list_gerak[], int jg); 

#endif