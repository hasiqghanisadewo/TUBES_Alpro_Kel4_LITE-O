#include <stdio.h>
#include <string.h> 
#include "header.h"

FILE *f; 
// bagian 1 Mesin Abstrak
void start(char* nama_file) {
    f = fopen(nama_file, "r");
}

void baca(char* kata_output) {
    if (f != NULL && fscanf(f, "%s", kata_output) == 1) {
    } else {
        strcpy(kata_output, "Selesai"); // Ditambahkan tanda kutip agar dibaca sebagai string
    }
}

// Bagian 2 Fungsi Hadiah

void bacaFileHadiah(Hadiah list_hadiah[], int *jumlah_hadiah) {
    start("thadiah.txt");

    if (f == NULL) {
        printf("\nBelum ada data hadiah.\n");
        *jumlah_hadiah = 0;
        return;
    }

    int i = 0;
    char kata[50];

    printf("\n-------------------------------------------------\n");
    printf("| %-5s | %-5s | %-20s | %-6s |\n", "X", "Y", "Nama", "Skor");
    printf("-------------------------------------------------\n");

    baca(kata);

    while (strcmp(kata, Selesai) != 0) {
        list_hadiah[i].x = atoi(kata);     
        baca(kata);
        list_hadiah[i].y = atoi(kata);        
        baca(kata);
        strcpy(list_hadiah[i].nama, kata);        
        baca(kata);
        list_hadiah[i].skor = atoi(kata);

        printf("| %-5d | %-5d | %-20s | %-6d |\n",
               list_hadiah[i].x,
               list_hadiah[i].y,
               list_hadiah[i].nama,
               list_hadiah[i].skor);

        i++;

        if (i >= MAX_HADIAH) {
            printf("Kapasitas memori penuh, sebagian data tidak termuat.\n");
            break;
        }

        baca(kata);
    }
    printf("-------------------------------------------------\n");

    *jumlah_hadiah = i;
    fclose(f);
}

void menuTambahHadiah() {
    Hadiah daftar[MAX_HADIAH];
    int total = 0;
    char jawab;

    // tampilkan hadiah yang sudah ada
    bacaFileHadiah(daftar, &total);

    printf("\nIngin mengisi hadiah baru? (Y/T): ");
    scanf(" %c", &jawab);

    if (jawab != 'Y' && jawab != 'y') {
        printf("Penambahan hadiah dibatalkan.\n");
        return;
    }

    Hadiah baru;

    printf("\n------ Tambah Hadiah -----\n");
    printf("Masukkan koordinat x hadiah: ");
    scanf("%d", &baru.x);
    printf("Masukkan koordinat y hadiah: ");
    scanf("%d", &baru.y);
    printf("Masukkan nama hadiah: ");
    scanf(" %49s", baru.nama);
    printf("Masukkan skor hadiah: ");
    scanf("%d", &baru.skor);

    while (getchar() != '\n');

    start("thadiah.txt");
    FILE *f_new = fopen("temp.txt", "w");

    if (f_new == NULL) {
        printf("Gagal membuka file.\n");
        if (f) fclose(f);
        return;
    }

    if (f != NULL) {
        char kata[50];
        baca(kata);

        while (strcmp(kata, Selesai) != 0) {
            char x_str[50], y_str[50], nama_str[50], skor_str[50];

            strcpy(x_str, kata);
            baca(y_str);
            baca(nama_str);
            baca(skor_str);

            fprintf(f_new, "%s %s %s %s\n",
                    x_str, y_str, nama_str, skor_str);

            baca(kata);
        }

        fclose(f);
    }

    fprintf(f_new, "%d %d %s %d\n",
            baru.x,
            baru.y,
            baru.nama,
            baru.skor);

    fprintf(f_new, "%s %s %s %s\n",
            Selesai,
            Selesai,
            Selesai,
            Selesai);

    fclose(f_new);

    remove("thadiah.txt");
    rename("temp.txt", "thadiah.txt");
}
// Bagian 3 Fungsi Gerak 
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

// === BAGIAN 4 - DATA SORTER & VALIDASI ===a

void urutkanHadiah(Hadiah arr[], int n)
{
    int i, j;
    Hadiah temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j].skor < arr[j + 1].skor)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Untuk Validasi apakah koordinat masih berada di dalam papan
int cekValidasiGerak(int x, int y)
{
    //memastikan variabel panjang_papan dan lebar_papan sudah dideklarasikan di header.h
    if(x < 0 || x >= panjang_papan)
    {
        return 0;
    }

    if(y < 0 || y >= lebar_papan)
    {
        return 0;
    }

    return 1; 
}
