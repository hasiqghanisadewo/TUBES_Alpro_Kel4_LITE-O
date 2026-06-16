#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

FILE *f;

void start(char* nama_file) {
    f = fopen(nama_file, "r");
}

void maju(char* kata_output) {
    if (f != NULL && fscanf(f, "%s", kata_output) == 1) {

    } else {
        strcpy(kata_output, Selesai);
    }
}

#define FILE_GERAK "tgerak.txt"    // tgerak.txt sebagai FILE_GERAK

// membaca semua data gerak dari file tgerak.txt
void bacaGerak(Gerak arr[], int *n) {
    FILE *fgerak = fopen(FILE_GERAK, "r");  // membuka file tgerak.txt dengan izin read
    *n = 0;     // reset nilai *n (jumlah data gerak)

    if (fgerak == NULL) {   // jika file kosong, langsung kembali
        return;
    }

    char tamp[100]; // tampungan sementara untuk teks yang sedang dibaca

    // selama jumlah data belum melebihi MAX_GERAK
    while (*n < MAX_GERAK) {
        // membaca koordinat x
        if (fscanf(fgerak, "%99s", tamp) != 1) {
            break;
        }
        arr[*n].x = atoi(tamp);

        // membaca koordinat y
        if (fscanf(fgerak, "%99s", tamp) != 1) {
            break;
        }
        arr[*n].y = atoi(tamp);

        (*n)++; // jika pasangan x dan y berhasil dibaca, count naik
    }

    fclose(fgerak); // file ditutup
}

// menyimpan semua data koordinat ke file
void tulisSemuaGerak(Gerak arr[], int n) {
    FILE *fgerak = fopen(FILE_GERAK, "w"); // membuka file tgerak.txt
    if (fgerak == NULL) {   // jika file kosong
        printf("Error: tidak bisa membuka %s\n", FILE_GERAK);
        return; // kembali
    }
    
    // mencetak semua data koordinat dari memori ke file
    for (int i = 0; i < n; i++) {
        fprintf(fgerak, "%d %d\n", arr[i].x, arr[i].y); 
    }
    
    fclose(fgerak); // file ditutup
}

// menampilkan data gerak O dalam bentuk tabel
void tampilTabelGerak(Gerak arr[], int n) {
    printf("Isi gerak O saat ini:\n");
    printf("%-5s %-5s\n", "x", "y");
    printf("----------\n");
    if (n == 0) {   // jika  belum ada data gerak
        printf("  (belum ada data gerak)\n");
    } else {        
        for (int i = 0; i < n; i++) // menampilkan data gerak dengan perulangan
            printf("%-5d %-5d\n", arr[i].x, arr[i].y);
    }
    printf("----------\n");
}

void inputGerak(int x, int y) {
    Gerak temp_arr[MAX_GERAK];
    int jumlah_data = 0;

    // ambil data dari file terlebih dahulu
    bacaGerak(temp_arr, &jumlah_data);

    // memastikan array sudah berisi atau belum
    if (jumlah_data >= MAX_GERAK) {
        printf("Gagal menambahkan gerak baru, memori sudah penuh!\n");
        return;
    }

    // memasukkan koordinat baru ke indeks paling akhir
    temp_arr[jumlah_data].x = x;
    temp_arr[jumlah_data].y = y;
    jumlah_data++;

    // simpan semua data yang sudah di-update ke dalam file
    tulisSemuaGerak(temp_arr, jumlah_data);
    printf("Gerak (%d, %d) berhasil ditambahkan.\n", x, y);
}