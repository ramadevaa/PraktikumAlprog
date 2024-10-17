#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int validasi (const char* teks){
    int angka;
    char input[100];
    while (1){
        printf("%s", teks);
        if(fgets(input, sizeof(input), stdin)== NULL){
            printf("Error!, harap masukkan data dengan benar! \n");
            continue;
        }
        char* akhirInput;
        angka = strtol(input, &akhirInput, 10);
        if (akhirInput == input || *akhirInput != '\n'){
            printf("Harap masukkan angka yang benar! \n");
        }
        else{
            break;
        }
    }
    return angka;
}
float volume_tabung(float r, float t) {
    return (22.0/7.0) * r * r * t;
}

float luas_permukaan_tabung(float r, float t) {
    return 2 * (22.0/7.0) * r * (r + t);
}

float volume_bola(float r) {
    return (4.0/3.0) * (22.0/7.0) * pow(r, 3);
}

float luas_permukaan_bola(float r) {
    return 4 * (22.0/7.0) * r * r;
}

float volume_limas_segiempat(float p, float l, float t) {
    return (1.0/3.0) * p * l * t;
}

float luas_permukaan_limas_segiempat(float p, float l, float tinggi_segitiga) {
    return p * l + 2 * (p * tinggi_segitiga / 2) + 2 * (l * tinggi_segitiga / 2);
}

float volume_prisma_segitiga(float alas, float tinggi_segitiga, float tinggi_prisma) {
    return (0.5 * alas * tinggi_segitiga) * tinggi_prisma;
}

float luas_permukaan_prisma_segitiga(float alas, float tinggi_segitiga, float tinggi_prisma) {
    float sisi_miring = sqrt(pow(alas / 2, 2) + pow(tinggi_segitiga, 2));
    return (2 * (0.5 * alas * tinggi_segitiga)) + (alas + 2 * sisi_miring) * tinggi_prisma;
}

float volume_kerucut(float r, float t) {
    return (1.0/3.0) * (22.0/7.0) * r * r * t;
}

float luas_permukaan_kerucut(float r, float s) {
    return (22.0/7.0)  * r * (r + s);
}

int main() {
    int pilihan;
    float r, t, p, l, tinggi_segitiga, tinggi_prisma, s;
    int back;
    awal:
    // \||2. Bola|| \n ||3. Limas Segiempat || \n ||4. Prisma Segitiga || \n ||5. Kerucut || \n ||0. Keluar ||\n");
   
    printf("============================================\n");
    printf("||    Program menghitung bangun ruang     ||\n============================================\n");
    printf("|| Pilih Bangun ruang yang ingin dihitung ||\n============================================\n");
    printf("||              1. Tabung                 ||\n");
    printf("||               2. Bola                  ||\n");
    printf("||           3. Limas Segiempat           ||\n");
    printf("||           4. Prisma Segitiga           ||\n");
    printf("||              5. Kerucut                ||\n");
    printf("||              0. Keluar                 ||\n");
   pilihan= validasi("|| > Masukkan pilihan (0-5):              ||\n============================================  \n >>");

    switch (pilihan) {
        case 1:
            // Tabung
             printf("|| ================================================== ||\n");
             printf("||        PROGRAM MENGHITUNG BANGUN RUANG TABUNG      ||\n");
             printf("|| ================================================== ||\n");
            r = validasi("Masukkan jari-jari tabung: ");
            t = validasi("Masukkan tinggi tabung: ");
            printf("Volume tabung: %.2f\n", volume_tabung(r, t));
            printf("Luas permukaan tabung: %.2f\n", luas_permukaan_tabung(r, t));
            back= validasi("Ingin mengulang program? 1 (yes), 2 (no) = ");
            if (back == 1){
                goto awal;
            }
            else if (back == 2){
                printf("Terimakasih sudah menggunakan program ini!");
                break;
            }
            else {
                do {
                back = validasi("Apakah anda ingin mengulang program operasi aritmatika? 1 (ya) , 2 (tidak) = ");
                if (back != 1 && back != 2) {
                    printf("Pilihan tidak valid. Silakan masukkan 1 atau 2.\n");
                }
            } while (back != 1 && back != 2);

                }
            
            break;
           

        case 2:
            // Bola
             printf("|| ================================================== ||\n");
             printf("||        PROGRAM MENGHITUNG BANGUN RUANG BOLA        ||\n");
             printf("|| ================================================== ||\n");
            r = validasi("Masukkan jari-jari bola: ");
            printf("Volume bola: %.2f\n", volume_bola(r));
            printf("Luas permukaan bola: %.2f\n", luas_permukaan_bola(r));
            back= validasi("Ingin mengulang program? 1 (yes), 2 (no) = ");
            if (back == 1){
                goto awal;
            }
            else if (back == 2){
                printf("Terimakasih sudah menggunakan program ini!");
                break;
            }
            break;

        case 3:
            // Limas Segiempat
             printf("|| ========================================================== ||\n");
             printf("||        PROGRAM MENGHITUNG BANGUN RUANG LIMAS SEGIEMPAT     ||\n");
             printf("|| ========================================================== ||\n");
            p= validasi("Masukkan panjang alas limas: ");
            
            l=validasi("Masukkan lebar alas limas: ");
            
            t=validasi("Masukkan tinggi limas: ");
            
            tinggi_segitiga= validasi("Masukkan tinggi segitiga sisi limas: ");
            printf("Volume limas segiempat: %.2f\n", volume_limas_segiempat(p, l, t));
            back= validasi("Ingin mengulang program? 1 (yes), 2 (no) = ");
            if (back == 1){
                goto awal;
            }
            else if (back == 2){
                printf("Terimakasih sudah menggunakan program ini!");
                break;
            }
            break;

        case 4:
            // Prisma Segitiga
             printf("|| ========================================================== ||\n");
             printf("||        PROGRAM MENGHITUNG BANGUN RUANG PRISMA SEGITIGA     ||\n");
             printf("|| ========================================================== ||\n");
             p= validasi("Masukkan panjang alas segitiga: ");
            
           l=validasi("Masukkan tinggi segitiga: ");
            
            t=validasi("Masukkan tinggi prisma: ");
            
            printf("Volume prisma segitiga: %.2f\n", volume_prisma_segitiga(p, tinggi_segitiga, tinggi_prisma));
            printf("Luas permukaan prisma segitiga: %.2f\n", luas_permukaan_prisma_segitiga(p, tinggi_segitiga, tinggi_prisma));
            back= validasi("Ingin mengulang program? 1 (yes), 2 (no) = ");
            if (back == 1){
                goto awal;
            }
            else if (back == 2){
                printf("Terimakasih sudah menggunakan program ini!");
                break;
            }
         
            break;

        case 5:
            // Kerucut
             printf("|| ================================================== ||\n");
             printf("||        PROGRAM MENGHITUNG BANGUN RUANG KERUCUT     ||\n");
             printf("|| ================================================== ||\n");
            r = validasi("Masukkan jari-jari kerucut: ");
            
            t = validasi("Masukkan tinggi kerucut: ");
            
            s =validasi("Masukkan garis pelukis kerucut: ");
            
            printf("Volume kerucut: %.2f\n", volume_kerucut(r, t));
            printf("Luas permukaan kerucut: %.2f\n", luas_permukaan_kerucut(r, s));
            back= validasi("Ingin mengulang program? 1 (yes), 2 (no) = ");
            if (back == 1){
                goto awal;
            }
            else if (back == 2){
                printf("Terimakasih sudah menggunakan program ini!");
                break;
            }
          
            break;
            case 0:
             printf("|| ================================================== ||\n");
             printf("||     TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI     ||\n");
             printf("|| ================================================== ||\n");
            break;
            default:
            printf("Pilihan tidak Valid! silahkan mengisi ulang! \n");
            goto awal;
            break;


    return 0;
}
}
