#include "header.h"
int main() {
    Hadiah daftar_hadiah[MAX_HADIAH];
    Gerak daftar_gerak[MAX_GERAK];
    
    int jumlah_hadiah = 0;
    int jumlah_gerak = 0;
    int pilihan;

    bacaFileHadiah(daftar_hadiah, &jumlah_hadiah);
    bacaGerak(daftar_gerak, &jumlah_gerak);

    while(1){
        tampilMenu();
        scanf("%d", &pilihan);

        switch(pilihan){
            case 1:
                menuTambahHadiah();
                bacaFileHadiah(daftar_hadiah, jumlah_hadiah);
                urutkanHadiah(daftar_hadiah, jumlah_hadiah);
                break;
            
             case 2:
                menuTambahGerak(daftar_gerak, &jumlah_gerak);
                tulisSemuaGerak(daftar_gerak, jumlah_gerak);
                break;

              case 3:
                 simulasiLiteO(daftar_hadiah, jumlah_hadiah, daftar_gerak, jumlah_gerak);
                 break;
            
              case 4:
                system("cls");
                printf("\n Makasih sudah main LITE O Kelompok 4! See u~ \n\n");
                return 0;

            default:
                printf("\n [!] Pilihan tidak valid. Masukkan angka 1-4.\n");
                printf(" Tekan ENTER untuk kembali...");
                while(getchar() != '\n');
                getchar();
                break;
            
        }
    }
    return 0;
}
