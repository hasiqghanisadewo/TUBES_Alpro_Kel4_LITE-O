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
        strcpy(kata_output, Selesai); 
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
// ---- BAGIAN 3: FUNGSI GERAK

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

        // jika mesin kata meninggalkan token string Selesai
        if (strcmp(tamp, "Selesai") == 0) break;
        arr[*n].x = atoi(tamp);

        // membaca koordinat y
        if (fscanf(fgerak, "%99s", tamp) != 1) {
            break;
        }
        if (strcmp(tamp, "Selesai") == 0) break;
        arr[*n].y = atoi(tamp);

        (*n)++; // jika pasangan x dan y berhasil dibaca, count naik
    }

    fclose(fgerak); // file ditutup
}

// menyimpan semua data koordinat dari array memori ke file
void tulisSemuaGerak(Gerak arr[], int n) {
    FILE *fgerak = fopen(FILE_GERAK, "w"); // membuka file tgerak.txt dengan izin tulis
    if (fgerak == NULL) {   // jika file kosong
        printf("Error: tidak bisa dibuka %s\n", FILE_GERAK);
        return;
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
    printf("----------\n");
    printf("| %-3s | %-3s |\n", "x", "y");
    printf("----------\n");
    if (n == 0) {   // jika  belum ada data gerak
        printf("| (kosong)   |\n");
    } else {        
        for (int i = 0; i < n; i++) // menampilkan data gerak dengan perulangan
            printf("| %-3d | %-3d |\n", arr[i].x, arr[i].y);
    }
    printf("----------\n");
}

// fungsi yang membantu menyisipkan koordinat baru lewat array
void inputGerak(int x, int y) {
    Gerak temp_arr[MAX_GERAK];
    int jumlah_data = 0;

    // baca data koordinat dari file ke memori
    bacaGerak(temp_arr, &jumlah_data);

    // memastikan kondisi array masih kosong atau sudah penuh
    if (jumlah_data >= MAX_GERAK) {
        printf("Gagal menambahkan gerak: memori sudah penuh.\n");
        return;
    }

    // menambahkan koordinat baru ke index paling akhir
    temp_arr[jumlah_data].x = x;
    temp_arr[jumlah_data].y = y;
    jumlah_data++;  // naikkan count jumlah data

    // menulis kembali semua data ke dalam file
    tulisSemuaGerak(temp_arr, jumlah_data);
    printf("Koordinat baru berhasil ditambahkan: (%d, %d)\n", x, y);
}

// menu controlller untuk tambah gerak pada program
void menuTambahGerak() {
    Gerak daftar[MAX_GERAK];
    int total = 0;
    char pil;

    // menampilkna table gerak saat ini
    bacaGerak(daftar, &total);
    tampilTabelGerak(daftar, total);

    printf("\nIngin mengisi koordinat gerak baru? (Y/T): ");
    scanf(" %c", &pil); // butuh spasi sebelum %c supaya menangani sisa buffer dari enter

    // jika pilihan bukan ya, maka penambahan koordinat dibatalkan
    if (pil != 'Y' && pil != 'y') {
        printf("Penambahan gerak dibatalkan.\n");
        return;
    }

    Gerak baru;

    // input data gerak baru dari user
    printf("\n======== Tambah Gerak ========\n");
    printf("Masukkan koordinat x gerak: "); scanf("%d", &baru.x);
    printf("Masukkan koordinat y gerak: "); scanf("%d", &baru.y);

    // membersihkan buffer sisa input
    while (getchar() != '\n');

    // menggunakan fungsi inputGerak 
    inputGerak(baru.x, baru.y);
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

//BAGIAN 5 - UI/UX & MAIN MENU CONTROLLER
void tampilMenu() {
    system("cls");

    printf("\n");
    printf(" ================================================================= \n");
    printf("  #                                                               #\n");
    printf("  #        ██╗     ██╗████████╗███████╗             ██████╗       #\n");
    printf("  #        ██║     ██║╚══██╔══╝██╔════╝            ██╔═══██╗      #\n");
    printf("  #        ██║     ██║   ██║   █████╗     █████    ██║   ██║      #\n");
    printf("  #        ██║     ██║   ██║   ██╔══╝              ██║   ██║      #\n");
    printf("  #        ███████╗██║   ██║   ███████╗            ╚██████╔╝      #\n");
    printf("  #        ╚══════╝╚═╝   ╚═╝   ╚══════╝             ╚═════╝       #\n");   
    printf("  #                                                               #\n");
    printf("  #      ===================================================      #\n");
    printf("  #                                                               #\n");
    printf("  #             ██╗  ██╗███████╗██╗         ██╗  ██╗              #\n");
    printf("  #             ██║ ██╔╝██╔════╝██║         ██║  ██║              #\n");
    printf("  #             █████╔╝ █████╗  ██║         ███████║              #\n");
    printf("  #             ██╔═██╗ ██╔══╝  ██║         ╚════██║              #\n");
    printf("  #             ██║  ██╗███████╗███████╗         ██║              #\n");
    printf("  #             ╚═╝  ╚═╝╚══════╝╚══════╝         ╚═╝              #\n");
    printf("  #                                                               #\n");                                
    printf("  #                       >> KELOMPOK  4 <<                       #\n");
    printf("  #                                                               #\n");
    printf("  ================================================================ \n");
    printf("\n");
    printf("  /==============================================================\\n");
    printf("  |                        MAIN  MENU                            | \n");
    printf("  |==============================================================| \n");
    printf("  |                                                              | \n");
    printf("\n");
    printf("  |                    [ 1 ]   Tambah Hadiah                     | \n");
    printf("  |                    [ 2 ]   Tambah Gerak                      | \n");
    printf("  |                    [ 3 ]   Simulasi Lite O                   | \n");
    printf("  |                    [ 4 ]   Keluar                            | \n");
    printf("\n");
    printf("  |                                                              | \n");
    printf("  \\=============================================================/ \n");
    printf("\n");
    printf("  >> Pilih menu (1-4): ");
}

// Taruh ini di paling bawah function.c
void simulasiLiteO(Hadiah list_hadiah[], int jh, Gerak list_gerak[], int jg) {
    printf("\n=== SIMULASI LITE O ===");
    printf("\n[Sistem] Fungsi simulasi masih kosong/dalam pengembangan.\n");
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
}