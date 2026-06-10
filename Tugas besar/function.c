#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

void menuTambahHadiah() {
    Hadiah baru;

    printf("------ Tambah Hadiah -----\n");
    printf("Masukkan koordinat x hadiah: ");
    scanf("%d", &baru.x);
    printf("Masukkan koordinat y hadiah: ");
    scanf("%d", &baru.y);
    printf("Masukkan nama hadiah: ");
    scanf(" %49s", baru.nama);
    printf("Masukkan skor hadiah: ");
    scanf("%d", &baru.skor);

FILE *f_old = fopen("thadiah.txt", "r");
    FILE *f_new = fopen("temp.txt", "w");

    if (f_new == NULL) {
        printf("Gagal membuka file sementara.\n");
        if (f_old) fclose(f_old);
        return;
    }

    // Jika file lama sudah ada, salin semua isinya KECUALI baris yang berisi "##"
    if (f_old != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), f_old) != NULL) {
            // Jika baris mengandung kata "##", maka dilewati (tidak disalin)
            if (strstr(buffer, Selesai) != NULL) {
                continue;
            }
            fputs(buffer, f_new);
        }
        fclose(f_old);
    }

    // Tulis data hadiah baru ke file sementara
    fprintf(f_new, "%d %d %s %d\n", baru.x, baru.y, baru.nama, baru.skor);
    
    // Tulis penanda selesai HANYA di baris paling bawah file sementara
    fprintf(f_new, "%s %s %s %s\n", Selesai, Selesai, Selesai, Selesai);
    fclose(f_new);

    // Hapus file lama dan ganti nama file temp menjadi thadiah.txt
    remove("thadiah.txt");
    rename("temp.txt", "thadiah.txt");

}

void bacaFileHadiah(Hadiah list_hadiah[], int *jumlah_hadiah) {
    FILE *f = fopen("thadiah.txt", "r");

    if (f == NULL) {
        printf("\nBelum ada data hadiah.\n");
        *jumlah_hadiah = 0;
        return;
    }

    char buffer[256];
    int i = 0;

    printf("-------------------------------------------------\n");
    printf("| %-5s | %-5s | %-20s | %-6s |\n", "X", "Y", "Nama Hadiah", "Skor");
    printf("-------------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (sscanf(buffer, " %d %d %49s %d",
                   &list_hadiah[i].x,
                   &list_hadiah[i].y,
                   list_hadiah[i].nama,
                   &list_hadiah[i].skor) == 4) {

            printf("| %-5d | %-5d | %-20s | %-6d |\n",
                   list_hadiah[i].x,
                   list_hadiah[i].y,
                   list_hadiah[i].nama,
                   list_hadiah[i].skor);

            i++;
            if (i >= MAX_HADIAH) break;
        }
    }
    printf("-------------------------------------------------\n");

    *jumlah_hadiah = i;
    fclose(f);
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