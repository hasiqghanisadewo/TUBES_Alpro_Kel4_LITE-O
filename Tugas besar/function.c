#include<stdio.h>
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