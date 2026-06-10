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

// membaca gerak dari file
int bacaGerakDariFile(FILE *fgerak, Gerak *g) {
    char tamp[100]; // tampungan sementara untuk teks yang sedang dibaca
    
    // membaca 1 data x
    if (fscanf(fgerak, "%99s", tamp) != 1) {
        return 0;   // mengembalikan nilai 0 jika tidak berhasil dibaca
    }
    g->x = atoi(tamp);
    
    // membaca 1 data y
    if (fscanf(fgerak, "%99s", tamp) != 1) {
        return 0; 
    }
    g->y = atoi(tamp);
    
    return 1; // berhasil membaca sepasang koordinat x dan y jika mengembalikan nilai 1
}

// membaca semua gerak
void bacaGerakSemua(Gerak arr[], int *n) {
    FILE *fgerak = fopen(NAMA_FILE_GERAK, "r"); // membuka file dengan izin read
    *n = 0; // reset nilai *n jumlah data gerak
    if (fgerak == NULL) {   // jika file kosong, langsung kembali
        return;
    }

    // selama data gerak dibaca, nilai *n bertambah terus
    while (*n < MAX_GERAK && bacaGerakDariFile(fgerak, &arr[*n]))
        (*n)++;
    fclose(fgerak); // menutup file tgerak.txt
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