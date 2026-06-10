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
void maju(char* kata_output);
int endKata();


// buat menu nanti
void menu();


//nyimpen input nanti dari fungsi input
#endif
