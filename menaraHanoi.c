#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Untuk membersihkan input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Validasi input
float validasi(const char* teks) {
    float angka;
    char input[100];
    while (1) {
        printf("%s", teks);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Harap masukkan data dengan benar!\n");
            continue;
        }
        char* akhirInput;
        angka = strtof(input, &akhirInput);
        if (akhirInput == input || *akhirInput != '\n' || angka <= 0) {
            printf("Harap masukkan angka yang benar!\n");
        } else {
            break;
        }
    }
    return angka;
}

// Fungsi rekursif Menara Hanoi
void hanoiRekursif(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", from, to);
        return;
    }
    hanoiRekursif(n - 1, from, to, aux);
    printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, from, to);
    hanoiRekursif(n - 1, aux, from, to);
}

// Fungsi iteratif untuk menghitung total langkah
int hanoiIteratif(int n) {
    return (1 << n) - 1;  // 2^n - 1
}

// Tampilan awal
void tampilanAwal(){
    printf("|| ===================================================== ||\n");
    printf("||           PROGRAM PERMAINAN MENARA HANOI              ||\n");
    printf("|| ===================================================== ||\n");
}

// Tampilan jika sesuai pilihan
void tampilanPilihan(){
    printf("|| ===================================================== ||\n");
    printf("||      SELAMAT DATANG DI PERMAINAN MENARA HANOI         ||\n");
    printf("||               SILAHKAN PILIH METODE                   ||\n");
    printf("||                                                       ||\n");
    printf("||       1. Rekursif (Menampilkan Langkah)               ||\n");
    printf("||       2. Iteratif (Hanya Menampilkan Langkah Minimal) ||\n");
    printf("||       0. Keluar Program                               ||\n");
    printf("||                                                       ||\n");
    printf("|| ===================================================== ||\n");

}

void akhir(){
    printf("|| ===================================================== ||\n");
    printf("||     TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI        ||\n");
    printf("|| ===================================================== ||\n");
}
// Fungsi utama
int main() {
    int n, choice, back;

do{
    // Tampilan awal dari program
    tampilanAwal();
   
    // Input jumlah cakram dengan validasi
    n = validasi(">> Masukkan jumlah cakram = ");

    // Input metode dengan validasi
    tampilanPilihan();
    choice = validasi(">> Masukkan pilihan anda = ");


    // Proses sesuai pilihan
    switch (choice) {
        case 1:
            printf("Langkah-langkah penyelesaian Menara Hanoi (Metode Rekursif):\n\n");
            hanoiRekursif(n, 'A', 'B', 'C');
            printf("\nTotal langkah minimal = %d\n", hanoiIteratif(n));
            break;
        case 2:
            printf("Total langkah minimal untuk %d cakram (Metode Iteratif): %d\n", 
                   n, hanoiIteratif(n));
            break;
        
        case 0:
            akhir();
            break;
        default:
            printf("Mohon Masukkan antara Metode 1 dan 2 !");
            break;
    }
    

    do{
        back = validasi("\nApakah ingin mengulang program? = yes (1) / no (2) = ");
        if (back == 1){
            system("cls");
        }
        if(back!= 1 && back != 2){
            printf("Mohon Masukkan 1 atau 2 !");
        }
    }while(back!= 1 && back != 2);
    
    }while(back ==1);
    
    akhir();

      

    

    return 0;
}
