#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

FILE *f

void start(char* nama_file) {
    f = fopen(nama_file, "r");
}

void maju(char* kata_output) {
    if (f != NULL && fscanf(f, "%s", kata_output) == 1) {

    } else {
        strcpy(kata_output, Selesai);
    }
}

#define NAMA_FILE_GERAK "tgerak.txt"    // tgerak.txt sebagai NAMA_FILE_GERAK

// membaca semua data gerak dari file tgerak.txt
void bacaGerakSemua(Gerak arr[], int *n) {
    FILE *fgerak = fopen(NAMA_FILE_GERAK, "r"); // membuka file dengan izin read
    *n = 0; // reset nilai *n jumlah data gerak
    
    if (fgerak == NULL) {   // jika file gagal dibuka / kosong, langsung kembali
        return;
    }

    char tamp[100]; // tampungan sementara untuk teks yang sedang dibaca

    // selama jumlah data belum melebihi MAX_GERAK
    while (*n < MAX_GERAK) {
        // membaca koordinat x
        if (fscanf(fgerak, "%99s", tamp) != 1) {
            break; // keluar dari loop jika file habis atau gagal membaca
        }
        arr[*n].x = atoi(tamp);

        // membaca koordinat y
        if (fscanf(fgerak, "%99s", tamp) != 1) {
            break; // Keluar dari loop jika koordinat y tidak lengkap
        }
        arr[*n].y = atoi(tamp);

        // jika pasangan x dan y berhasil dibaca, naikkan count data
        (*n)++;
    }

    fclose(fgerak); // menutup file
}

// menyimpan semua data koordinat ke file
void tulisSemuaGerak(Gerak arr[], int n) {
    FILE *fgerak = fopen(NAMA_FILE_GERAK, "w"); // membuka file tgerak.txt
    if (fgerak == NULL) {   // jika file kosong
        printf("Error: tidak bisa membuka %s\n", NAMA_FILE_GERAK);
        return; // kembali
    }
    
    // mencetak semua data koordinat dari memori ke file
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %d\n", arr[i].x, arr[i].y); 
    }
    
    fclose(fgerak);
}

// menampilkan data gerak O dalam bentuk tabel
void tampilTabelGerak(Gerak arr[], int n) {
    printf("Isi gerak O saat ini:\n");
    printf("%-5s %-5s\n", "x", "y");
    printf("----------\n");
    if (n == 0) {   // jika  belum ada data gerak
        printf("  (belum ada data gerak)\n");
    } else {        // menampilkan data gerak secara perulangan
        for (int i = 0; i < n; i++)
            printf("%-5d %-5d\n", arr[i].x, arr[i].y);
    }
    printf("----------\n");
}