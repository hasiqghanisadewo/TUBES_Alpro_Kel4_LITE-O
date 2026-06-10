#include <stdio.h>
#include <string.h> 
#include "header.h"

FILE *f; 

// === BAGIAN DARI TEMPLATE TIM ===

void start(char* nama_file) {
    f = fopen(nama_file, "r");
}

void maju(char* kata_output) {
    if (f != NULL && fscanf(f, "%s", kata_output) == 1) {
        // Proses pembacaan kata dari file teks
    } else {
        strcpy(kata_output, "Selesai"); // Ditambahkan tanda kutip agar dibaca sebagai string
    }
}


// === BAGIAN 4 - DATA SORTER & VALIDASI ===

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
