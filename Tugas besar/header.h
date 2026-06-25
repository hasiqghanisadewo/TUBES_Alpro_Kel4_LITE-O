#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// WARNA ANSI
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define WHITE   "\033[37m"

// KONSTANTA YANG AKAN DIGUNAKAN
#define MAX_HADIAH 100
#define MAX_GERAK 100
#define Selesai "##"

// SISTEM WARNA ANSI
#define RESET               "\033[0m"
#define WARNA_O             "\033[1;33m"   // Kuning terang (Karakter O)
#define WARNA_PAPAN         "\033[1;34m"   // Biru terang (Batas papan)
#define WARNA_SKOR          "\033[1;33m"   // Kuning terang (Teks Skor)
#define JUMLAH_WARNA_HADIAH 4              // Jumlah warna yang tersedia untuk hadiah

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
int cekValidasiGerak(int x, int y, int panjang, int lebar);


// UI MENU
void tampilMenu(); // DISESUAIKAN: Mengganti 'void menu()' agar sinkron dengan function.c
void simulasiLiteO(Hadiah list_hadiah[], int jh, Gerak list_gerak[], int jg); //untuk main.c, sesuai dengan function.c lu (lu: Hadiah list_hadiah[], int jh, Gerak list_gerak[], int jg)

// SIMULASI LITE O
void wait(float x); // FUNGSI ANIMASI DARI PDF
void inisialisasiPapan(int panjang, int lebar, char papan[panjang][lebar]);
void tempatkanHadiah(int panjang, int lebar, char papan[panjang][lebar], Hadiah arr[], int n);
void cetakPapan(int panjang, int lebar, char papan[panjang][lebar], int skor, Hadiah arr[], int n);
int  cekCollision(Hadiah arr[], int n, int ox, int oy, int *idxHit);



// SIMULASI LITE O
void wait(float x); // FUNGSI ANIMASI DARI PDF
void inisialisasiPapan(char papan[][lebar_papan], int panjang, int lebar);
void tempatkanHadiah(char papan[][lebar_papan], Hadiah arr[], int n);
void cetakPapan(char papan[][lebar_papan], int panjang, int lebar, int skor);
int  cekCollision(Hadiah arr[], int n, int ox, int oy, int *idxHit);

#endif
