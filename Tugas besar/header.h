#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <time.h>

// --- KONSTANTA GLOBAL ---
#define MAX_HADIAH 100
#define MAX_GERAK 100

// --- STRUKTUR ---
typedef struct {
    int x;
    int y;
    char nama[50];
    int skor;
} Hadiah;

typedef struct {
    int x;
    int y;
} Gerak;


#endif