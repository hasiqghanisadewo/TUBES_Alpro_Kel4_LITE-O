#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
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

// struktur buat gerak nanti
typedef struct {
    int x;
    int y;
} Gerak;

// fungsi dari pdf buat animasi nanti
void wait(float x);

//  Mesin abstark
void start(char* nama_file);
void baca(char* kata_output);
int endKata();


// FITUR HADIAH


void bacaFileHadiah(Hadiah list_hadiah[], int *jumlah_hadiah);
void menuTambahHadiah();


// FITUR GERAK


int bacaGerakDariFile(FILE *fgerak, Gerak *g);
void bacaGerakSemua(Gerak arr[], int *n);
void tulisSemuaGerak(Gerak arr[], int n);
void tampilTabelGerak(Gerak arr[], int n);


// SORTING

void urutkanHadiah(Hadiah arr[], int n);

// VALIDASI

int cekValidasiGerak(int x, int y);

// buat menu nanti
void menu();


//nyimpen input nanti dari fungsi input
#endif
