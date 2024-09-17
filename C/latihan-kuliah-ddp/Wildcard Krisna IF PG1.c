#include <stdio.h>
#include <stdlib.h> // Untuk clear console
#include <math.h> // Untuk perhitungan matematika
#include <windows.h> // Untuk membuat console mengerti unicode
#include <time.h> // Untuk mendapatkan tahun sekarang

// ================================================================ [ Fungsi-fungsi ]
unsigned long long hitungFaktorial(int angkaFaktorial) {
    unsigned long long hasilFaktorial = 1;

    for(int i = angkaFaktorial; i > 1; i--) {
        hasilFaktorial *= i;
    }

    return hasilFaktorial;
}

void hitungDeretAritmetika(int nilaiAwal, int bedaSuku, int jumlahDeret) {
    for(int i = 1; i <= jumlahDeret - 1; i++) {
        printf("%d, ", nilaiAwal + (i - 1) * bedaSuku);
    }
    if(jumlahDeret >= 1) {
        printf("%d", nilaiAwal + (jumlahDeret - 1) * bedaSuku);
    }
}

double hitungSukuNAritmetika(int nilaiAwal, int bedaSuku, int jumlahDeret) {
    return (jumlahDeret * 1.0) / 2 * (2 * nilaiAwal + (jumlahDeret - 1) * bedaSuku);
}

void hitungDeretGeometri(int nilaiAwal, int rasio, int jumlahDeret) {
    for(int i = 1; i <= jumlahDeret - 1; i++) {
        printf("%g, ", nilaiAwal * pow(rasio, (i - 1)));
    }
    if(jumlahDeret >= 1) {
        printf("%g", nilaiAwal * pow(rasio, (jumlahDeret - 1)));
    }
}

double hitungSukuNGeometri(int nilaiAwal, int rasio, int jumlahDeret) {
    if(rasio < 1) {
        return nilaiAwal * (1 - pow(rasio, jumlahDeret)) / (1 - rasio);
    } else if(rasio > 1) {
        return nilaiAwal * (pow(rasio, jumlahDeret) - 1) / (rasio - 1);
    }
}

void hitungDeretFibonacci(int jumlahDeretFibonacci) {
    int angka1 = 1;
    int angka2 = 1;
    int sementara;

    if(jumlahDeretFibonacci == 1) {
        printf("%d", angka1);
    } else if(jumlahDeretFibonacci == 2) {
        printf("%d, %d", angka1, angka2);
    } else if(jumlahDeretFibonacci >= 3) {
        printf("%d, %d, ", angka1, angka2);

        for(int i = 1; i <= jumlahDeretFibonacci - 3; i++) {
            // Mulai dari menghitung deret ke 3
            sementara = angka1 + angka2;
            angka1 = angka2;
            angka2 = sementara;
            printf("%d, ", sementara);
        }
        if(jumlahDeretFibonacci >= 3) {
            sementara = angka1 + angka2;
            angka1 = angka2;
            angka2 = sementara;
            printf("%d", sementara);
        }
    } else {
        printf("0");
    }
}

double hitungLogaritma(int numerus, int basis) {
    return log(numerus) / log(basis) * 1.0;
}

float hitungDerajatKeRadian(int sudutDerajat) {
    return sudutDerajat * (M_PI / 180.0);
}

double hitungPythagorasSisiA(int sisiB, int sisiC) {
    return sqrt(sisiC * sisiC - sisiB * sisiB);
}

double hitungPythagorasSisiB(int sisiA, int sisiC) {
    return sqrt(sisiC * sisiC - sisiA * sisiA);
}

double hitungPythagorasSisiC(int sisiA, int sisiB) {
    return sqrt(sisiA * sisiA + sisiB * sisiB);
}

int hitungMencariUmur(int tahunLahir) {
    // Mendapatkan tahun sekarang
    time_t waktuSekarang;
    struct tm *waktuLokal;
    time(&waktuSekarang);
    waktuLokal = localtime(&waktuSekarang);

    return waktuLokal->tm_year + 1900 - tahunLahir;
}





// ================================================================ [ Kalkulator ]
void kalkulator() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Kalkulator                             |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Kalkulator            |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Program sederhana untuk berhitung      |\n");
    printf("|                                        |\n");
    printf("| Daftar Operator                        |\n");
    printf("| + untuk penjumlahan                    |\n");
    printf("| - untuk pengurangan                    |\n");
    printf("| * untuk perkalian                      |\n");
    printf("| / untuk pembagian                      |\n");
    printf("| %% untuk mencari sisa bagi (modulus)    |\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int angka1;
    int angka2;
    char operator;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan angka pertama : ");
    while(scanf("%d", &angka1) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan angka pertama : ");
        while(getchar() != '\n');
    }

    printf("Masukkan angka kedua   : ");
    while(scanf("%d", &angka2) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan angka kedua   : ");
        while(getchar() != '\n');
    }
    getchar();

    do {
        printf("Masukkan operator      : ");
        operator = getchar();

        if(operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%' && operator != '0') {
            printf("Operator kurang tepat, operator bisa +, -, *, /, atau %%\n\n");
            while(getchar() != '\n');
        }
    } while (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%' && operator != '0');
    getchar();

    // Menghitung hasil
    if(operator == '+') {
        printf("\nHasil dari %d + %d = %d\n\n", angka1, angka2, angka1 + angka2);
    } else if(operator == '-') {
        printf("\nHasil dari %d - %d = %d\n\n", angka1, angka2, angka1 - angka2);
    } else if(operator == '*') {
        printf("\nHasil dari %d * %d = %lld\n\n", angka1, angka2, angka1 * angka2);
    } else if(operator == '/') {
        if(angka2 == 0) {
            printf("\nHasil dari %d / %d = Tak terdefinisi\n\n", angka1, angka2);
        } else {
            printf("\nHasil dari %d / %d = %g\n\n", angka1, angka2, angka1 / (angka2 * 1.0));
        }
    } else if(operator == '%') {
        printf("\nHasil dari %d %% %d = %u\n\n", angka1, angka2, angka1 % angka2);
    } else if(operator == '0') {
        goto akhirKalkulator;
    } else {
        printf("\nHasil: Diluar dugaan.\n\n");
    }

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        kalkulator();
    }

    akhirKalkulator:
}





// ================================================================ [ Faktorial ]
void faktorial() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Faktorial                              |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Faktorial             |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Program untuk mencari nilai Faktorial  |\n");
    printf("| Masukkan input dalam bilangan cacah    |\n");
    printf("|                                        |\n");
    printf("| Catatan: hanya sanggup sampai 20!      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int angkaFaktorial;
    unsigned long long hasilFaktorial = 1;
    char apakahUlang;

    // Meminta input
    printf("Mencari nilai Faktorial dari: ");
    while(scanf("%d", &angkaFaktorial) != 1 || angkaFaktorial < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Mencari nilai Faktorial dari: ");
        while(getchar() != '\n');
    }
    getchar();

    // Mencari hasil faktorial
    hasilFaktorial = hitungFaktorial(angkaFaktorial);
    printf("Faktorial dari %d adalah %llu\n\n", angkaFaktorial, hasilFaktorial);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        faktorial();
    }
}





// ================================================================ [ Deret Bilangan ]
void deretAritmetika() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Deret Aritmetika                       |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Deret Bilangan >      |\n");
    printf("| Deret Aritmetika                       |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Menampilkan deret dengan rumus         |\n");
    printf("| Un = a + (n - 1)b                      |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = nilai awal                         |\n");
    printf("| b = beda nilai antar suku              |\n");
    printf("| n = jumlah deret yang ditampilkan      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int nilaiAwal;
    int bedaSuku;
    int jumlahDeret;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan nilai awal   : ");
    while(scanf("%d", &nilaiAwal) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan nilai awal   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan beda suku    : ");
    while(scanf("%d", &bedaSuku) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan beda suku    : ");
        while(getchar() != '\n');
    }

    printf("Masukkan jumlah deret : ");
    while(scanf("%d", &jumlahDeret) != 1 || jumlahDeret < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan jumlah deret : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nHasilnya adalah: ");
    hitungDeretAritmetika(nilaiAwal, bedaSuku, jumlahDeret);
    printf("\n\n");

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        deretAritmetika();
    }
}

void sukuNAritmetika() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Suku N Aritmetika                      |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Deret Bilangan >      |\n");
    printf("| Suku N Aritmetika                      |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari suku ke n dengan rumus         |\n");
    printf("| Sn = n/2 (2a + (n - 1)b)               |\n");
    printf("| Atau                                   |\n");
    printf("| Sn = n/2 (a + Un)                      |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = nilai awal                         |\n");
    printf("| b = beda nilai antar suku              |\n");
    printf("| n = jumlah deret yang ditampilkan      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int nilaiAwal;
    int bedaSuku;
    int jumlahDeret;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan nilai awal   : ");
    while(scanf("%d", &nilaiAwal) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan nilai awal   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan beda suku    : ");
    while(scanf("%d", &bedaSuku) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan beda suku    : ");
        while(getchar() != '\n');
    }

    printf("Masukkan jumlah deret : ");
    while(scanf("%d", &jumlahDeret) != 1 || jumlahDeret < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan jumlah deret : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nHasilnya adalah: %g\n\n", hitungSukuNAritmetika(nilaiAwal, bedaSuku, jumlahDeret));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        sukuNAritmetika();
    }
}

void deretGeometri() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Deret Geometri                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Deret Bilangan >      |\n");
    printf("| Deret Geometri                         |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Menampilkan deret dengan rumus         |\n");
    printf("| Un = ar^n-1                            |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = nilai awal                         |\n");
    printf("| r = rasio                              |\n");
    printf("| n = jumlah deret yang ditampilkan      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int nilaiAwal;
    int rasio;
    int jumlahDeret;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan nilai awal   : ");
    while(scanf("%d", &nilaiAwal) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan nilai awal   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan rasio        : ");
    while(scanf("%d", &rasio) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan rasio        : ");
        while(getchar() != '\n');
    }

    printf("Masukkan jumlah deret : ");
    while(scanf("%d", &jumlahDeret) != 1 || jumlahDeret < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan jumlah deret : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nHasilnya adalah: ");
    hitungDeretGeometri(nilaiAwal, rasio, jumlahDeret);
    printf("\n\n");

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        deretGeometri();
    }
}

void sukuNGeometri() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Suku N Geometri                        |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Deret Bilangan >      |\n");
    printf("| Suku N Geometri                        |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari suku ke n dengan rumus         |\n");
    printf("| Sn = a(1 - r^n) / (1 - r)              |\n");
    printf("| Jika r < 1                             |\n");
    printf("| Atau                                   |\n");
    printf("| Sn = a(r^n - 1) / (r - 1)              |\n");
    printf("| Jika r > 1                             |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = nilai awal                         |\n");
    printf("| r = rasio                              |\n");
    printf("| n = jumlah deret yang ditampilkan      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int nilaiAwal;
    int rasio;
    int jumlahDeret;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan nilai awal   : ");
    while(scanf("%d", &nilaiAwal) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan nilai awal   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan rasio        : ");
    while(scanf("%d", &rasio) != 1 || rasio == 1) {
        printf("Input harus bilangan bulat dan bukan 1.\n\n");
        printf("Masukkan rasio        : ");
        while(getchar() != '\n');
    }

    printf("Masukkan jumlah deret : ");
    while(scanf("%d", &jumlahDeret) != 1 || jumlahDeret < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan jumlah deret : ");
        while(getchar() != '\n');
    }
    getchar();

    if(rasio < 1 || rasio > 1) {
        printf("\nHasilnya adalah: %g\n\n", hitungSukuNGeometri(nilaiAwal, rasio, jumlahDeret));
    } else {
        printf("\nHasilnya adalah: Diluar dugaan\n\n");
    }

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        sukuNGeometri();
    }
}

void deretFibonacci() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Deret Fibonacci                        |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Deret Bilangan >      |\n");
    printf("| Deret Fibonacci                        |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Menampilkan deret Fibonacci            |\n");
    printf("| Masukkan input dalam bilangan asli     |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jumlahDeretFibonacci;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan jumlah deret Fibonacci: ");
    while(scanf("%d", &jumlahDeretFibonacci) != 1 || jumlahDeretFibonacci < 1) {
        printf("Input harus bilangan asli (1 - \u221E).\n\n");
        printf("Masukkan jumlah deret Fibonacci: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nHasilnya adalah: ");
    hitungDeretFibonacci(jumlahDeretFibonacci);
    printf("\n\n");

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        deretFibonacci();
    }
}

void deretBilangan() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Deret Bilangan                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Deret Bilangan        |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| A. Aritmetika                          |\n");
    printf("| 1. Menampilkan deret bilangan          |\n");
    printf("| 2. Mencari suku ke n                   |\n");
    printf("|                                        |\n");
    printf("| B. Geometri                            |\n");
    printf("| 3. Menampilkan deret bilangan          |\n");
    printf("| 4. Mencari suku ke n                   |\n");
    printf("|                                        |\n");
    printf("| C. Fibonacci                           |\n");
    printf("| 5. Menampilkan deret Fibonacci         |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 6 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 5.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirDeretBilangan;
            break;
        case 1:
            deretAritmetika();
            break;
        case 2:
            sukuNAritmetika();
            break;
        case 3:
            deretGeometri();
            break;
        case 4:
            sukuNGeometri();
            break;
        case 5:
            deretFibonacci();
            break;
        default:
            goto akhirDeretBilangan;
            break;
    }

    deretBilangan();

    akhirDeretBilangan:
}





// ================================================================ [ Luas Bangun Datar ]
void luasPersegiPanjang() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Persegi Panjang                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Luas Bangun Datar >   |\n");
    printf("| Luas Persegi Panjang                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|  --------------                        |\n");
    printf("|  |            |                        |\n");
    printf("|  --------------                        |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Persegi Panjang = p x l           |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| p = panjang                            |\n");
    printf("| l = lebar                              |\n");
    printf("|                                        |\n");
    printf("| Hasil juga bisa untuk persegi.         |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int panjang;
    int lebar;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Panjang : ");
    while(scanf("%d", &panjang) != 1 || panjang < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Panjang : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Lebar   : ");
    while(scanf("%d", &lebar) != 1 || lebar < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Lebar   : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuasnya adalah %d\n\n", panjang * lebar);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPersegiPanjang();
    }
}

void luasSegitiga() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Segitiga                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Luas Bangun Datar >   |\n");
    printf("| Luas Segitiga                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|    /\\                                  |\n");
    printf("|   /  \\                                 |\n");
    printf("|  /____\\                                |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Segitiga = (a x t) / 2            |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = alas                               |\n");
    printf("| t = tinggi                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int alas;
    int tinggi;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Alas   : ");
    while(scanf("%d", &alas) != 1 || alas < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Alas   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi : ");
    while(scanf("%d", &tinggi) != 1 || tinggi < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuasnya adalah %g\n\n", (alas * tinggi) / 2.0);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasSegitiga();
    }
}

void luasLingkaran() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Lingkaran                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Luas Bangun Datar >   |\n");
    printf("| Luas Lingkaran                         |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|   /---\\                                |\n");
    printf("|  |     |                               |\n");
    printf("|   \\---/                                |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Lingkaran = π x r x r             |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari Lingkaran: ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari Lingkaran: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuasnya adalah %g\n\n", (22/7.0) * jariJari * jariJari);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasLingkaran();
    }
}

void luasTrapesium() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Trapesium                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Luas Bangun Datar >   |\n");
    printf("| Luas Trapesium                         |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|    /------------\\                      |\n");
    printf("|   /              \\                     |\n");
    printf("|  /________________\\                    |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Trapesium = (a + b) x t / 2       |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = sisi atas                          |\n");
    printf("| b = sisi bawah                         |\n");
    printf("| t = tinggi                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisiAtas;
    int sisiBawah;
    int tinggi;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi Atas  : ");
    while(scanf("%d", &sisiAtas) != 1 || sisiAtas < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi Atas  : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi Bawah : ");
    while(scanf("%d", &sisiBawah) != 1 || sisiBawah < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi Bawah : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi     : ");
    while(scanf("%d", &tinggi) != 1 || tinggi < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi     : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuasnya adalah %g\n\n", (sisiAtas + sisiBawah) * tinggi / 2.0);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasTrapesium();
    }
}

void luasBelahKetupat() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Belah Ketupat                     |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Luas Bangun Datar >   |\n");
    printf("| Luas Belah Ketupat                     |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|   /\\                                   |\n");
    printf("|  <  >                                  |\n");
    printf("|   \\/                                   |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Belah Ketupat = d1 x d2 / 2       |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| d1 = diagonal 1                        |\n");
    printf("| d2 = diagonal 2                        |\n");
    printf("|                                        |\n");
    printf("| Hasil juga bisa untuk layang-layang.   |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int diagonal1;
    int diagonal2;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Diagonal 1 : ");
    while(scanf("%d", &diagonal1) != 1 || diagonal1 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Diagonal 1 : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Diagonal 2 : ");
    while(scanf("%d", &diagonal2) != 1 || diagonal2 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Diagonal 2 : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuasnya adalah %g\n\n", diagonal1 * diagonal2 / 2.0);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasBelahKetupat();
    }
}

void luasBangunDatar() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Bangun Datar                      |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Luas Bangun Datar     |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Persegi Panjang                     |\n");
    printf("| 2. Segitiga                            |\n");
    printf("| 3. Lingkaran                           |\n");
    printf("| 4. Trapesium                           |\n");
    printf("| 5. Belah Ketupat                       |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 6 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 5.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirLuasBangunDatar;
            break;
        case 1:
            luasPersegiPanjang();
            break;
        case 2:
            luasSegitiga();
            break;
        case 3:
            luasLingkaran();
            break;
        case 4:
            luasTrapesium();
            break;
        case 5:
            luasBelahKetupat();
            break;
        default:
            goto akhirLuasBangunDatar;
            break;
    }

    luasBangunDatar();

    akhirLuasBangunDatar:
}





// ================================================================ [ Keliling Bangun Datar ]
void kelilingPersegiPanjang() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Keliling Persegi Panjang               |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Keliling Bangun Datar |\n");
    printf("| > Keliling Persegi Panjang             |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|  --------------                        |\n");
    printf("|  |            |                        |\n");
    printf("|  --------------                        |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Kll Persegi Panjang = (p + l) x 2      |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| p = panjang                            |\n");
    printf("| l = lebar                              |\n");
    printf("|                                        |\n");
    printf("| Hasil juga bisa untuk persegi.         |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int panjang;
    int lebar;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Panjang : ");
    while(scanf("%d", &panjang) != 1 || panjang < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Panjang : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Lebar   : ");
    while(scanf("%d", &lebar) != 1 || lebar < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Lebar   : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nKelilingnya adalah %d\n\n", (panjang + lebar) * 2);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        kelilingPersegiPanjang();
    }
}

void kelilingSegitiga() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Keliling Segitiga                      |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Keliling Bangun Datar |\n");
    printf("| > Keliling Segitiga                    |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|    /\\                                  |\n");
    printf("|   /  \\                                 |\n");
    printf("|  /____\\                                |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Keliling Segitiga = a + b + c          |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = sisi 1                             |\n");
    printf("| b = sisi 2                             |\n");
    printf("| c = sisi 3                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisi1;
    int sisi2;
    int sisi3;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi 1: ");
    while(scanf("%d", &sisi1) != 1 || sisi1 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 1: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 2: ");
    while(scanf("%d", &sisi2) != 1 || sisi2 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 2: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 3: ");
    while(scanf("%d", &sisi3) != 1 || sisi3 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 3: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nKelilingnya adalah %d\n\n", sisi1 + sisi2 + sisi3);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        kelilingSegitiga();
    }
}

void kelilingLingkaran() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Keliling Lingkaran                     |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Keliling Bangun Datar |\n");
    printf("| > Keliling Lingkaran                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|   /---\\                                |\n");
    printf("|  |     |                               |\n");
    printf("|   \\---/                                |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Keliling Lingkaran = π x r x 2         |\n");
    printf("| Atau                                   |\n");
    printf("| Keliling Lingkaran = π x D             |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("| D = diameter lingkaran                 |\n");
    printf("| D = r + r atau r x 2                   |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari Lingkaran: ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari Lingkaran: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nKelilingnya adalah %g\n\n", (22/7.0) * jariJari * 2);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        kelilingLingkaran();
    }
}

void kelilingTrapesium() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Keliling Trapesium                     |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Keliling Bangun Datar |\n");
    printf("| > Keliling Trapesium                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|    /------------\\                      |\n");
    printf("|   /              \\                     |\n");
    printf("|  /________________\\                    |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Keliling Trapesium = a + b + c + d     |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = sisi 1                             |\n");
    printf("| b = sisi 2                             |\n");
    printf("| c = sisi 3                             |\n");
    printf("| d = sisi 4                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisi1;
    int sisi2;
    int sisi3;
    int sisi4;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi 1: ");
    while(scanf("%d", &sisi1) != 1 || sisi1 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 1: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 2: ");
    while(scanf("%d", &sisi2) != 1 || sisi2 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 2: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 3: ");
    while(scanf("%d", &sisi3) != 1 || sisi3 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 3: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 4: ");
    while(scanf("%d", &sisi4) != 1 || sisi4 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 4: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nKelilingnya adalah %d\n\n", sisi1 + sisi2 + sisi3 + sisi4);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        kelilingTrapesium();
    }
}

void kelilingBelahKetupat() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Keliling Belah Ketupat                 |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Keliling Bangun Datar |\n");
    printf("| > Keliling Belah Ketupat               |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|   /\\                                   |\n");
    printf("|  <  >                                  |\n");
    printf("|   \\/                                   |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Keliling Belah Ketupat = a + b + c + d |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = sisi 1                             |\n");
    printf("| b = sisi 2                             |\n");
    printf("| c = sisi 3                             |\n");
    printf("| d = sisi 4                             |\n");
    printf("|                                        |\n");
    printf("| Hasil juga bisa untuk layang-layang.   |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisi1;
    int sisi2;
    int sisi3;
    int sisi4;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi 1: ");
    while(scanf("%d", &sisi1) != 1 || sisi1 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 1: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 2: ");
    while(scanf("%d", &sisi2) != 1 || sisi2 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 2: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 3: ");
    while(scanf("%d", &sisi3) != 1 || sisi3 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 3: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi 4: ");
    while(scanf("%d", &sisi4) != 1 || sisi4 < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi 4: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nKelilingnya adalah %d\n\n", sisi1 + sisi2 + sisi3 + sisi4);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        kelilingBelahKetupat();
    }
}

void kelilingBangunDatar() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Keliling Bangun Datar                  |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Keliling Bangun Datar |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Persegi Panjang                     |\n");
    printf("| 2. Segitiga                            |\n");
    printf("| 3. Lingkaran                           |\n");
    printf("| 4. Trapesium                           |\n");
    printf("| 5. Belah Ketupat                       |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 6 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 5.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirLuasBangunDatar;
            break;
        case 1:
            kelilingPersegiPanjang();
            break;
        case 2:
            kelilingSegitiga();
            break;
        case 3:
            kelilingLingkaran();
            break;
        case 4:
            kelilingTrapesium();
            break;
        case 5:
            kelilingBelahKetupat();
            break;
        default:
            goto akhirLuasBangunDatar;
            break;
    }

    kelilingBangunDatar();

    akhirLuasBangunDatar:
}





// ================================================================ [ Volume Bangun Ruang ]
void volumeBalok() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Balok                           |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang > |\n");
    printf("| Volume Balok                           |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Volume Balok = p x l x t               |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| p = panjang                            |\n");
    printf("| l = lebar                              |\n");
    printf("| t = tinggi                             |\n");
    printf("|                                        |\n");
    printf("| Hasil juga bisa untuk kubus.           |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int panjang;
    int lebar;
    int tinggi;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Panjang : ");
    while(scanf("%d", &panjang) != 1 || panjang < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Panjang : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Lebar   : ");
    while(scanf("%d", &lebar) != 1 || lebar < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Lebar   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi  : ");
    while(scanf("%d", &tinggi) != 1 || tinggi < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi  : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nVolumenya adalah %d\n\n", panjang * lebar * tinggi);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        volumeBalok();
    }
}

void volumePrisma() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Prisma                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang > |\n");
    printf("| Volume Prisma                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Volume Prisma = Luas alas x h          |\n");
    printf("| Atau                                   |\n");
    printf("| Volume Prisma = (a x t / 2) x h        |\n");
    printf("|                                        |\n");
    printf("| Karena alas Prisma adalah segitiga     |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = alas segitiga                      |\n");
    printf("| t = tinggi segitiga                    |\n");
    printf("| h = tinggi prisma                      |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int alasSegitiga;
    int tinggiSegitiga;
    int tinggiPrisma;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Alas Segitiga   : ");
    while(scanf("%d", &alasSegitiga) != 1 || alasSegitiga < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Alas Segitiga   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Segitiga : ");
    while(scanf("%d", &tinggiSegitiga) != 1 || tinggiSegitiga < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Segitiga : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Prisma   : ");
    while(scanf("%d", &tinggiPrisma) != 1 || tinggiPrisma < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Prisma   : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nVolumenya adalah %g\n\n", (alasSegitiga * tinggiSegitiga / 2.0) * tinggiPrisma);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        volumePrisma();
    }
}

void volumeLimas() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Limas                           |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang > |\n");
    printf("| Volume Limas                           |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Saya memakai Limas dengan alas segi 4  |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Volume Limas = Luas alas x t / 3       |\n");
    printf("| Atau                                   |\n");
    printf("| Volume Limas = (s x s) x t / 3         |\n");
    printf("|                                        |\n");
    printf("| Karena alas Limas adalah persegi       |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| s = sisi persegi                       |\n");
    printf("| t = tinggi limas                       |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisiPersegi;
    int tinggiLimas;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi Persegi: ");
    while(scanf("%d", &sisiPersegi) != 1 || sisiPersegi < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi Persegi: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Limas: ");
    while(scanf("%d", &tinggiLimas) != 1 || tinggiLimas < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Limas: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nVolumenya adalah %g\n\n", (sisiPersegi * sisiPersegi) * tinggiLimas / 3.0);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        volumeLimas();
    }
}

void volumeTabung() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Tabung                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang > |\n");
    printf("| Volume Tabung                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Volume Tabung = Luas alas x t          |\n");
    printf("| Atau                                   |\n");
    printf("| Volume Tabung = (π x r x r) x t        |\n");
    printf("|                                        |\n");
    printf("| Karena alas Tabung adalah lingkaran    |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("| t = tinggi tabung                      |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    int tinggiTabung;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari : ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Tabung : ");
    while(scanf("%d", &tinggiTabung) != 1 || tinggiTabung < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Tabung : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nVolumenya adalah %g\n\n", ((22/7.0) * jariJari * jariJari) * tinggiTabung);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        volumeTabung();
    }
}

void volumeKerucut() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Kerucut                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang > |\n");
    printf("| Volume Kerucut                         |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Volume Kerucut = Luas alas x t / 3     |\n");
    printf("| Atau                                   |\n");
    printf("| Volume Kerucut = (π x r x r) x t / 3   |\n");
    printf("|                                        |\n");
    printf("| Karena alas Kerucut adalah lingkaran   |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("| t = tinggi kerucut                     |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    int tinggiKerucut;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari : ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Tabung : ");
    while(scanf("%d", &tinggiKerucut) != 1 || tinggiKerucut < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Tabung : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nVolumenya adalah %g\n\n", ((22/7.0) * jariJari * jariJari) * tinggiKerucut / 3.0);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        volumeKerucut();
    }
}

void volumeBola() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Bola                            |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang > |\n");
    printf("| Volume Bola                            |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Volume Bola = π x r x r x r x 4 / 3    |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari : ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nVolumenya adalah %g\n\n", (22/7.0) * jariJari * jariJari * jariJari * 4 / 3.0);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        volumeBola();
    }
}

void volumeBangunRuang() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Volume Bangun Ruang                    |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Volume Bangun Ruang   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Balok                               |\n");
    printf("| 2. Prisma                              |\n");
    printf("| 3. Limas                               |\n");
    printf("| 4. Tabung                              |\n");
    printf("| 5. Kerucut                             |\n");
    printf("| 6. Bola                                |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 7 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 6.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirVolumeBangunRuang;
            break;
        case 1:
            volumeBalok();
            break;
        case 2:
            volumePrisma();
            break;
        case 3:
            volumeLimas();
            break;
        case 4:
            volumeTabung();
            break;
        case 5:
            volumeKerucut();
            break;
        case 6:
            volumeBola();
            break;
        default:
            goto akhirVolumeBangunRuang;
            break;
    }

    volumeBangunRuang();

    akhirVolumeBangunRuang:
}





// ================================================================ [ Luas Permukaan Bangun Ruang ]
void luasPermukaanBalok() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Balok                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang >          |\n");
    printf("| Luas Permukaan Balok                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Permukaan Balok =                 |\n");
    printf("| (p x l + p x t + l x t) x 2            |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| p = panjang                            |\n");
    printf("| l = lebar                              |\n");
    printf("| t = tinggi                             |\n");
    printf("|                                        |\n");
    printf("| Hasil juga bisa untuk kubus.           |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int panjang;
    int lebar;
    int tinggi;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Panjang : ");
    while(scanf("%d", &panjang) != 1 || panjang < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Panjang : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Lebar   : ");
    while(scanf("%d", &lebar) != 1 || lebar < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Lebar   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi  : ");
    while(scanf("%d", &tinggi) != 1 || tinggi < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi  : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuas Permukaannya adalah %d\n\n", (panjang * lebar + panjang * tinggi + lebar * tinggi) * 2);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPermukaanBalok();
    }
}

void luasPermukaanPrisma() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Prisma                  |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang >          |\n");
    printf("| Luas Permukaan Prisma                  |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Saya memakai Prisma dengan alas        |\n");
    printf("| segitiga sama sisi                     |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Permukaan Prisma =                |\n");
    printf("| Luas alas x 2 + Keliling alas x h      |\n");
    printf("| Atau                                   |\n");
    printf("| Luas Permukaan Prisma =                |\n");
    printf("| (a x t / 2) x 2 + (a + a + a) x h      |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = alas segitiga                      |\n");
    printf("| t = tinggi segitiga                    |\n");
    printf("| h = tinggi prisma                      |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int alasSegitiga;
    int tinggiSegitiga;
    int tinggiPrisma;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Alas Segitiga   : ");
    while(scanf("%d", &alasSegitiga) != 1 || alasSegitiga < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Alas Segitiga   : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Segitiga : ");
    while(scanf("%d", &tinggiSegitiga) != 1 || tinggiSegitiga < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Segitiga : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Prisma   : ");
    while(scanf("%d", &tinggiPrisma) != 1 || tinggiPrisma < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Prisma   : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuas Permukaannya adalah %g\n\n", (alasSegitiga * tinggiSegitiga / 2.0) * 2 + (alasSegitiga + alasSegitiga + alasSegitiga) * tinggiPrisma);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPermukaanPrisma();
    }
}

void luasPermukaanLimas() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Limas                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang >          |\n");
    printf("| Luas Permukaan Limas                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Saya memakai Limas dengan alas segi 4  |\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Permukaan Limas =                 |\n");
    printf("| Luas alas + Luas sisi miring           |\n");
    printf("| Atau                                   |\n");
    printf("| Luas Permukaan Limas =                 |\n");
    printf("| (s x s) + (s x r / 2) * 4              |\n");
    printf("|                                        |\n");
    printf("| Karena alas Limas adalah persegi       |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| s = sisi persegi                       |\n");
    printf("| t = tinggi limas                       |\n");
    printf("| r = garis pelukis (tinggi sisi miring) |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisiPersegi;
    int tinggiLimas;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi Persegi: ");
    while(scanf("%d", &sisiPersegi) != 1 || sisiPersegi < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi Persegi: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Limas: ");
    while(scanf("%d", &tinggiLimas) != 1 || tinggiLimas < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Limas: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuas Permukaannya adalah %g\n\n", (sisiPersegi * sisiPersegi) + (sisiPersegi * sqrt(((sisiPersegi / 2.0) * (sisiPersegi / 2.0)) + (tinggiLimas * tinggiLimas)) / 2.0) * 4);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPermukaanLimas();
    }
}

void luasPermukaanTabung() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Tabung                  |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang >          |\n");
    printf("| Luas Permukaan Tabung                  |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Permukaan Tabung =                |\n");
    printf("| (π x r x r) x 2 + (π x r x 2) x t      |\n");
    printf("| Atau                                   |\n");
    printf("| Luas Permukaan Tabung =                |\n");
    printf("| π x r x r x 2 x (r + t)                |\n");
    printf("|                                        |\n");
    printf("| Karena alas Tabung adalah lingkaran    |\n");
    printf("| dan sisi tabung adalah persegi panjang |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("| t = tinggi tabung                      |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    int tinggiTabung;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari : ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Tabung : ");
    while(scanf("%d", &tinggiTabung) != 1 || tinggiTabung < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Tabung : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuas Permukaannya adalah %g\n\n", ((22/7.0) * jariJari * jariJari) * 2 * (jariJari + tinggiTabung));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPermukaanTabung();
    }
}

void luasPermukaanKerucut() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Kerucut                 |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang >          |\n");
    printf("| Luas Permukaan Kerucut                 |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Permukaan Kerucut =               |\n");
    printf("| π x r x (r + s)                        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("| t = tinggi kerucut                     |\n");
    printf("| s = garis pelukis (garis miring)       |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    int tinggiKerucut;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari     : ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari     : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Tinggi Tabung : ");
    while(scanf("%d", &tinggiKerucut) != 1 || tinggiKerucut < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tinggi Tabung : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuas Permukaannya adalah %g\n\n", (22/7.0) * jariJari * (jariJari + sqrt(tinggiKerucut * tinggiKerucut + jariJari * jariJari)));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPermukaanKerucut();
    }
}

void luasPermukaanBola() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Bola                    |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang >          |\n");
    printf("| Luas Permukaan Bola                    |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Luas Permukaan Bola = π x r x r x 4    |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| π = pi                                 |\n");
    printf("| r = jari-jari lingkaran                |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jariJari;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Jari-jari : ");
    while(scanf("%d", &jariJari) != 1 || jariJari < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Jari-jari : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLuas Permukaannya adalah %g\n\n", (22/7.0) * jariJari * jariJari * 4);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        luasPermukaanBola();
    }
}

void luasPermukaanBangunRuang() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Luas Permukaan Bangun Ruang            |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Luas Permukaan Bangun Ruang            |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Balok                               |\n");
    printf("| 2. Prisma                              |\n");
    printf("| 3. Limas                               |\n");
    printf("| 4. Tabung                              |\n");
    printf("| 5. Kerucut                             |\n");
    printf("| 6. Bola                                |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 7 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 6.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirLuasPermukaanBangunRuang;
            break;
        case 1:
            luasPermukaanBalok();
            break;
        case 2:
            luasPermukaanPrisma();
            break;
        case 3:
            luasPermukaanLimas();
            break;
        case 4:
            luasPermukaanTabung();
            break;
        case 5:
            luasPermukaanKerucut();
            break;
        case 6:
            luasPermukaanBola();
            break;
        default:
            goto akhirLuasPermukaanBangunRuang;
            break;
    }

    volumeBangunRuang();

    akhirLuasPermukaanBangunRuang:
}





// ================================================================ [ Skala ]
void mencariSkala() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Skala                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Skala >    |\n");
    printf("| Mencari Skala                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Skala = js / jp                        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| js = jarak sebenarnya                  |\n");
    printf("| jp = jarak di peta                     |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input km, hasilnya juga km        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jarakSebenarnya;
    int jarakDiPeta;
    char apakahUlang;

    // Meminta input angka
    printf("Jika Jarak Sebenarnya : ");
    while(scanf("%d", &jarakSebenarnya) != 1 || jarakSebenarnya < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Jika Jarak Sebenarnya : ");
        while(getchar() != '\n');
    }

    printf("Dan Jarak di Peta     : ");
    while(scanf("%d", &jarakDiPeta) != 1 || jarakDiPeta <= 0) {
        printf("Input harus bilangan asli (1 - \u221E).\n\n");
        printf("Dan Jarak di Peta     : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nJadi, Skalanya adalah %g\n\n", jarakSebenarnya / (jarakDiPeta * 1.0));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariSkala();
    }
}

void mencariJarakSebenarnya() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Jarak Sebenarnya               |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Skala >    |\n");
    printf("| Mencari Jarak Sebenarnya               |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Jarak Sebenarnya = sk * jp             |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| sk = skala                             |\n");
    printf("| jp = jarak di peta                     |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input km, hasilnya juga km        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int skala;
    int jarakDiPeta;
    char apakahUlang;

    // Meminta input angka
    printf("Jika Skalanya         : ");
    while(scanf("%d", &skala) != 1 || skala < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Jika Skalanya          : ");
        while(getchar() != '\n');
    }

    printf("Tetapi Jarak di Peta  : ");
    while(scanf("%d", &jarakDiPeta) != 1 || jarakDiPeta < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Tetapi Jarak di Peta  : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nBerarti, Jarak Sebenarnya adalah %d\n\n", skala * jarakDiPeta);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariJarakSebenarnya();
    }
}

void mencariJarakDiPeta() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Jarak di Peta                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Skala >    |\n");
    printf("| Jarak di Peta                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| Jarak di Peta = js / sk                |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| js = jarak sebenarnya                  |\n");
    printf("| sk = skala                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input km, hasilnya juga km        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jarakSebenarnya;
    int skala;
    char apakahUlang;

    // Meminta input angka
    printf("Jika Jarak Sebenarnya : ");
    while(scanf("%d", &jarakSebenarnya) != 1 || jarakSebenarnya < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Jika Jarak Sebenarnya : ");
        while(getchar() != '\n');
    }

    printf("Kemudian Skalanya     : ");
    while(scanf("%d", &skala) != 1 || skala <= 0) {
        printf("Input harus bilangan asli (1 - \u221E).\n\n");
        printf("Kemudian Skalanya     : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nMaka, Jarak di Peta adalah %g\n\n", jarakSebenarnya / (skala * 1.0));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariJarakDiPeta();
    }
}

void menghitungSkala() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Menghitung Skala                       |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Skala      |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| sk = js / jp                           |\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Mencari Skala                       |\n");
    printf("| 2. Mencari Jarak Sebenarnya            |\n");
    printf("| 3. Mencari Jarak di Peta               |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 4 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 3.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirMencariSkala;
            break;
        case 1:
            mencariSkala();
            break;
        case 2:
            mencariJarakSebenarnya();
            break;
        case 3:
            mencariJarakDiPeta();
            break;
        default:
            goto akhirMencariSkala;
            break;
    }

    menghitungSkala();

    akhirMencariSkala:
}





// ================================================================ [ Jarak, Kecepatan, Waktu ]
void mencariJarak() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Jarak                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung JKW >      |\n");
    printf("| Mencari Jarak                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| j = k * w                              |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| j = jarak                              |\n");
    printf("| k = kecepatan                          |\n");
    printf("| w = waktu                              |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika kecepatan = km/jam, waktu = jam   |\n");
    printf("| Maka jarak = km                        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int kecepatan;
    int waktu;
    char apakahUlang;

    // Meminta input angka
    printf("Jika Kecepatannya : ");
    while(scanf("%d", &kecepatan) != 1 || kecepatan < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Jika Kecepatannya : ");
        while(getchar() != '\n');
    }

    printf("Dengan Waktu      : ");
    while(scanf("%d", &waktu) != 1 || waktu < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Dengan Waktu      : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nMaka, Jaraknya adalah %d\n\n", kecepatan * waktu);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariJarak();
    }
}

void mencariKecepatan() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Kecepatan                      |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung JKW >      |\n");
    printf("| Mencari Kecepatan                      |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| k = j / w                              |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| k = kecepatan                          |\n");
    printf("| j = jarak                              |\n");
    printf("| w = waktu                              |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika jarak = km, waktu = menit         |\n");
    printf("| Maka kecepatan = km/menit              |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jarak;
    int waktu;
    char apakahUlang;

    // Meminta input angka
    printf("Jika Jaraknya         : ");
    while(scanf("%d", &jarak) != 1 || jarak < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Jika Jaraknya         : ");
        while(getchar() != '\n');
    }

    printf("Kemudian dengan Waktu : ");
    while(scanf("%d", &waktu) != 1 || waktu <= 0) {
        printf("Input harus bilangan asli (1 - \u221E).\n\n");
        printf("Kemudian dengan Waktu : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nJadi, Kecepatannya adalah %g\n\n", jarak / (waktu * 1.0));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariKecepatan();
    }
}

void mencariWaktu() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Waktu                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung JKW >      |\n");
    printf("| Mencari Waktu                          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| w = j / k                              |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| w = waktu                              |\n");
    printf("| j = jarak                              |\n");
    printf("| k = kecepatan                          |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika jarak = m, kecepatan = m/detik    |\n");
    printf("| Maka waktu = detik                     |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int jarak;
    int kecepatan;
    char apakahUlang;

    // Meminta input angka
    printf("Tempat Berjarak  : ");
    while(scanf("%d", &jarak) != 1 || jarak < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Tempat Berjarak  : ");
        while(getchar() != '\n');
    }

    printf("Dengan Kecepatan : ");
    while(scanf("%d", &kecepatan) != 1 || kecepatan <= 0) {
        printf("Input harus bilangan asli (1 - \u221E).\n\n");
        printf("Dengan Kecepatan : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nWaktu yang diperlukan adalah %g\n\n", jarak / (kecepatan * 1.0));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariWaktu();
    }
}

void menghitungJKW() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Menghitung JKW                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung JKW        |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| JKW = Jarak, Kecepatan, Waktu          |\n");
    printf("| j = k * w                              |\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Mencari Jarak                       |\n");
    printf("| 2. Mencari Kecepatan                   |\n");
    printf("| 3. Mencari Waktu                       |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 4 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 3.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirMenghitungJKW;
            break;
        case 1:
            mencariJarak();
            break;
        case 2:
            mencariKecepatan();
            break;
        case 3:
            mencariWaktu();
            break;
        default:
            goto akhirMenghitungJKW;
            break;
    }

    menghitungJKW();

    akhirMenghitungJKW:
}





// ================================================================ [ Konversi Suhu ]
void konversiDariCelcius() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Konversi dari Celcius                  |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Konversi Suhu >       |\n");
    printf("| Konversi dari Celcius                  |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("|   x   - xAtas      y   - yBawah        |\n");
    printf("| -------------- = --------------        |\n");
    printf("| xAtas - xBawah   yAtas - yBawah        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| x = suhu asal                          |\n");
    printf("| y = suhu tujuan                        |\n");
    printf("| Atas = puncak suhu                     |\n");
    printf("| Bawah = titik bawah suhu               |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int suhuCelcius;
    float suhuReamur, suhuFahrenheit, suhuKelvin;
    int celciusAtas = 100, celciusBawah = 0;
    int reamurAtas = 80, reamurBawah = 0;
    int fahrenheitAtas = 212, fahrenheitBawah = 32;
    float kelvinAtas = 373.15, kelvinBawah = 273.15;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan suhu Celcius: ");
    while(scanf("%d", &suhuCelcius) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan suhu Celcius: ");
        while(getchar() != '\n');
    }
    getchar();

    suhuReamur = ((suhuCelcius - celciusBawah) * (reamurAtas - reamurBawah) / ((celciusAtas - celciusBawah) * 1.0)) + reamurBawah;
    suhuFahrenheit = ((suhuCelcius - celciusBawah) * (fahrenheitAtas - fahrenheitBawah) / ((celciusAtas - celciusBawah) * 1.0)) + fahrenheitBawah;
    suhuKelvin = ((suhuCelcius - celciusBawah) * (kelvinAtas - kelvinBawah) / ((celciusAtas - celciusBawah) * 1.0)) + kelvinBawah;

    printf("\nSuhu dalam Reamur     = %g\n", suhuReamur);
    printf("Suhu dalam Fahrenheit = %g\n", suhuFahrenheit);
    printf("Suhu dalam Kelvin     = %g\n\n", suhuKelvin);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        konversiDariCelcius();
    }
}

void konversiDariReamur() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Konversi dari Reamur                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Konversi Suhu >       |\n");
    printf("| Konversi dari Reamur                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("|   x   - xAtas      y   - yBawah        |\n");
    printf("| -------------- = --------------        |\n");
    printf("| xAtas - xBawah   yAtas - yBawah        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| x = suhu asal                          |\n");
    printf("| y = suhu tujuan                        |\n");
    printf("| Atas = puncak suhu                     |\n");
    printf("| Bawah = titik bawah suhu               |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int suhuReamur;
    float suhuCelcius, suhuFahrenheit, suhuKelvin;
    int celciusAtas = 100, celciusBawah = 0;
    int reamurAtas = 80, reamurBawah = 0;
    int fahrenheitAtas = 212, fahrenheitBawah = 32;
    float kelvinAtas = 373.15, kelvinBawah = 273.15;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan suhu Reamur: ");
    while(scanf("%d", &suhuReamur) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan suhu Reamur: ");
        while(getchar() != '\n');
    }
    getchar();

    suhuCelcius = ((suhuReamur - reamurBawah) * (celciusAtas - celciusBawah) / ((reamurAtas - reamurBawah) * 1.0)) + celciusBawah;
    suhuFahrenheit = ((suhuReamur - reamurBawah) * (fahrenheitAtas - fahrenheitBawah) / ((reamurAtas - reamurBawah) * 1.0)) + fahrenheitBawah;
    suhuKelvin = ((suhuReamur - reamurBawah) * (kelvinAtas - kelvinBawah) / ((reamurAtas - reamurBawah) * 1.0)) + kelvinBawah;

    printf("\nSuhu dalam Celcius   = %g\n", suhuCelcius);
    printf("Suhu dalam Fahrenheit = %g\n", suhuFahrenheit);
    printf("Suhu dalam Kelvin     = %g\n\n", suhuKelvin);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        konversiDariReamur();
    }
}

void konversiDariFahrenheit() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Konversi dari Fahrenheit               |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Konversi Suhu >       |\n");
    printf("| Konversi dari Fahrenheit               |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("|   x   - xAtas      y   - yBawah        |\n");
    printf("| -------------- = --------------        |\n");
    printf("| xAtas - xBawah   yAtas - yBawah        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| x = suhu asal                          |\n");
    printf("| y = suhu tujuan                        |\n");
    printf("| Atas = puncak suhu                     |\n");
    printf("| Bawah = titik bawah suhu               |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int suhuFahrenheit;
    float suhuCelcius, suhuReamur, suhuKelvin;
    int celciusAtas = 100, celciusBawah = 0;
    int reamurAtas = 80, reamurBawah = 0;
    int fahrenheitAtas = 212, fahrenheitBawah = 32;
    float kelvinAtas = 373.15, kelvinBawah = 273.15;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan suhu Fahrenheit: ");
    while(scanf("%d", &suhuFahrenheit) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan suhu Fahrenheit: ");
        while(getchar() != '\n');
    }
    getchar();

    suhuCelcius = ((suhuFahrenheit - fahrenheitBawah) * (celciusAtas - celciusBawah) / ((fahrenheitAtas - fahrenheitBawah) * 1.0)) + celciusBawah;
    suhuReamur = ((suhuFahrenheit - fahrenheitBawah) * (reamurAtas - reamurBawah) / ((fahrenheitAtas - fahrenheitBawah) * 1.0)) + reamurBawah;
    suhuKelvin = ((suhuFahrenheit - fahrenheitBawah) * (kelvinAtas - kelvinBawah) / ((fahrenheitAtas - fahrenheitBawah) * 1.0)) + kelvinBawah;

    printf("\nSuhu dalam Celcius = %g\n", suhuCelcius);
    printf("Suhu dalam Reamur   = %g\n", suhuReamur);
    printf("Suhu dalam Kelvin   = %g\n\n", suhuKelvin);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        konversiDariFahrenheit();
    }
}

void konversiDariKelvin() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Konversi dari Kelvin                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Konversi Suhu >       |\n");
    printf("| Konversi dari Kelvin                   |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("|   x   - xAtas      y   - yBawah        |\n");
    printf("| -------------- = --------------        |\n");
    printf("| xAtas - xBawah   yAtas - yBawah        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| x = suhu asal                          |\n");
    printf("| y = suhu tujuan                        |\n");
    printf("| Atas = puncak suhu                     |\n");
    printf("| Bawah = titik bawah suhu               |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int suhuKelvin;
    float suhuCelcius, suhuReamur, suhuFahrenheit;
    int celciusAtas = 100, celciusBawah = 0;
    int reamurAtas = 80, reamurBawah = 0;
    int fahrenheitAtas = 212, fahrenheitBawah = 32;
    float kelvinAtas = 373.15, kelvinBawah = 273.15;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan suhu Kelvin: ");
    while(scanf("%d", &suhuKelvin) != 1) {
        printf("Input harus bilangan bulat.\n\n");
        printf("Masukkan suhu Kelvin: ");
        while(getchar() != '\n');
    }
    getchar();

    suhuCelcius = ((suhuKelvin - kelvinBawah) * (celciusAtas - celciusBawah) / ((kelvinAtas - kelvinBawah) * 1.0)) + celciusBawah;
    suhuReamur = ((suhuKelvin - kelvinBawah) * (reamurAtas - reamurBawah) / ((kelvinAtas - kelvinBawah) * 1.0)) + reamurBawah;
    suhuFahrenheit = ((suhuKelvin - kelvinBawah) * (fahrenheitAtas - fahrenheitBawah) / ((kelvinAtas - kelvinBawah) * 1.0)) + fahrenheitBawah;

    printf("\nSuhu dalam Celcius   = %g\n", suhuCelcius);
    printf("Suhu dalam Reamur     = %g\n", suhuReamur);
    printf("Suhu dalam Fahrenheit = %g\n\n", suhuFahrenheit);

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        konversiDariKelvin();
    }
}

void konversiSuhu() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Konversi Suhu                          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Konversi Suhu         |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Suhu ada Celcius (C), Reamur (R),      |\n");
    printf("| Fahrenheit (F), dan Kelvin (K)         |\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Konversi dari Celcius               |\n");
    printf("| 2. Konversi dari Reamur                |\n");
    printf("| 3. Konversi dari Fahrenheit            |\n");
    printf("| 4. Konversi dari Kelvin                |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 5 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 4.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirKonversiSuhu;
            break;
        case 1:
            konversiDariCelcius();
            break;
        case 2:
            konversiDariReamur();
            break;
        case 3:
            konversiDariFahrenheit();
            break;
        case 4:
            konversiDariKelvin();
            break;
        default:
            goto akhirKonversiSuhu;
            break;
    }

    konversiSuhu();

    akhirKonversiSuhu:
}





// ================================================================ [ Logaritma ]
void menghitungLogaritma() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Menghitung Logaritma                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Logaritma  |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| (basis) log (numerus) = hasil          |\n");
    printf("|                                        |\n");
    printf("| Mencari hasil logaritma dari input     |\n");
    printf("| numerus dan basis                      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int numerus;
    int basis;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Numerus : ");
    while(scanf("%d", &numerus) != 1 || numerus <= 0) {
        printf("Input harus bilangan asli (1 - \u221E).\n\n");
        printf("Masukkan Numerus : ");
        while(getchar() != '\n');
    }

    printf("Masukkan Basis   : ");
    while(scanf("%d", &basis) != 1 || basis <= 1) {
        printf("Input harus bilangan asli (1 - \u221E) dan bukan 1.\n\n");
        printf("Masukkan Basis   : ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nLogaritma basis %d dari %d adalah %g\n\n", basis, numerus, hitungLogaritma(numerus, basis));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        menghitungLogaritma();
    }
}





// ================================================================ [ Sudut Trigonometri ]
void sudutTrigonometri() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Menghitung Sudut Trigonometri          |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna >                       |\n");
    printf("| Menghitung Sudut Trigonometri          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mengubah sudut dalam derajat menjadi   |\n");
    printf("| sinus, kosinus, dan tangen             |\n");
    printf("|                                        |\n");
    printf("| Catatan: Hasil bisa saja kurang akurat |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sudutDerajat;
    char apakahUlang;
    float radian, sinus, kosinus, tangen;

    // Meminta input angka
    printf("Masukkan Sudut dalam Derajat: ");
    while(scanf("%d", &sudutDerajat) != 1 || sudutDerajat < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sudut dalam Derajat: ");
        while(getchar() != '\n');
    }
    getchar();

    // Mengubah derajat ke radian
    radian = hitungDerajatKeRadian(sudutDerajat);
    sinus = sin(radian);
    kosinus = cos(radian);
    tangen = tan(radian);

    // Menampilkan hasil
    printf("Nilai sinus-nya   = %.2f\n", sinus);
    printf("Nilai cosinus-nya = %.2f\n", kosinus);
    
    // Memastikan tangen hanya dihitung jika cosinus tidak sama dengan 0
    if (fmod(sudutDerajat, 180) != 90) {
        printf("Nilai tangen-nya  = %.2f\n\n", tangen);
    } else {
        printf("Nilai tangen-nya  = terdefinisi\nKarena tangen = sinus / kosinus.\n\n");
    }

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        sudutTrigonometri();
    }
}





// ================================================================ [ Pythagoras ]
void mencariSisiA() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Sisi A                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Pythagoras |\n");
    printf("| > Mencari Sisi A                       |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| a^2 = c^2 - b^2                        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| a = sisi a                             |\n");
    printf("| c = sisi c                             |\n");
    printf("| b = sisi b                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisiC;
    int sisiB;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi C: ");
    while(scanf("%d", &sisiC) != 1 || sisiC < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi C: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi B: ");
    while(scanf("%d", &sisiB) != 1 || sisiB < 0 || sisiB > sisiC) {
        printf("Input harus bilangan cacah (0 - \u221E) dan < Sisi C.\n\n");
        printf("Masukkan Sisi B: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nPanjang Sisi A adalah %g\n\n", hitungPythagorasSisiA(sisiB, sisiC));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariSisiA();
    }
}

void mencariSisiB() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Sisi B                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Pythagoras |\n");
    printf("| > Mencari Sisi B                       |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| b^2 = c^2 - a^2                        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| b = sisi b                             |\n");
    printf("| c = sisi c                             |\n");
    printf("| a = sisi a                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisiC;
    int sisiA;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi C: ");
    while(scanf("%d", &sisiC) != 1 || sisiC < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi C: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi A: ");
    while(scanf("%d", &sisiA) != 1 || sisiA < 0 || sisiA > sisiC) {
        printf("Input harus bilangan cacah (0 - \u221E) dan < Sisi C.\n\n");
        printf("Masukkan Sisi A: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nPanjang Sisi B adalah %g\n\n", hitungPythagorasSisiB(sisiA, sisiC));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariSisiB();
    }
}

void mencariSisiC() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Sisi C                         |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Pythagoras |\n");
    printf("| > Mencari Sisi C                       |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Mencari dengan rumus                   |\n");
    printf("| c^2 = a^2 + b^2                        |\n");
    printf("|                                        |\n");
    printf("| Dengan                                 |\n");
    printf("| c = sisi c                             |\n");
    printf("| a = sisi a                             |\n");
    printf("| b = sisi b                             |\n");
    printf("|                                        |\n");
    printf("| Satuan hasil tergantung satuan input   |\n");
    printf("| Jika input cm, hasilnya juga cm        |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int sisiA;
    int sisiB;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Sisi A: ");
    while(scanf("%d", &sisiA) != 1 || sisiA < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi A: ");
        while(getchar() != '\n');
    }

    printf("Masukkan Sisi B: ");
    while(scanf("%d", &sisiB) != 1 || sisiB < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Sisi B: ");
        while(getchar() != '\n');
    }
    getchar();

    printf("\nPanjang Sisi C adalah %g\n\n", hitungPythagorasSisiC(sisiA, sisiB));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariSisiC();
    }
}

void menghitungPythagoras() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Menghitung Pyhagoras                   |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Menghitung Pyhagoras  |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("|    |\\                                  |\n");
    printf("|    | \\                                 |\n");
    printf("|  b |  \\  c                             |\n");
    printf("|    |   \\                               |\n");
    printf("|    |____\\                              |\n");
    printf("|       a                                |\n");
    printf("|                                        |\n");
    printf("| Rumus Pyhagoras: c^2 = a^2 + b^2       |\n");
    printf("|                                        |\n");
    printf("| 0 Kembali ke halaman awal              |\n");
    printf("|                                        |\n");
    printf("| 1. Mencari Sisi A                      |\n");
    printf("| 2. Mencari Sisi B                      |\n");
    printf("| 3. Mencari Sisi C                      |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 4 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 3.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirMenghitungPythagoras;
            break;
        case 1:
            mencariSisiA();
            break;
        case 2:
            mencariSisiB();
            break;
        case 3:
            mencariSisiC();
            break;
        default:
            goto akhirMenghitungPythagoras;
            break;
    }

    menghitungPythagoras();

    akhirMenghitungPythagoras:
}





// ================================================================ [ Mencari Umur ]
void mencariUmur() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Mencari Umur                           |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna > Mencari Umur          |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Program untuk mencari umur dengan      |\n");
    printf("| input tahun lahir                      |\n");
    printf("|                                        |\n");
    printf("| Catatan: Hasil tergantung penginput    |\n");
    printf("| Data Anda 100%% rahasia!!               |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int tahunLahir;
    char apakahUlang;

    // Meminta input angka
    printf("Masukkan Tahun Lahir: ");
    while(scanf("%d", &tahunLahir) != 1 || tahunLahir < 0) {
        printf("Input harus bilangan cacah (0 - \u221E).\n\n");
        printf("Masukkan Tahun Lahir: ");
        while(getchar() != '\n');
    }
    getchar();

    // Menampilkan hasil
    printf("Dari data tersebut, umurmu adalah %d.\n\n", hitungMencariUmur(tahunLahir));

    // Apakah mengulang game?
    do {
        printf("Apakah mau mencoba lagi? [y/n]: ");
        scanf("%c", &apakahUlang);

        if(apakahUlang != 'y' && apakahUlang != 'n') {
            printf("Masukkan huruf y (yes) atau n (no)\n\n");
            while(getchar() != '\n');
        }
    } while (apakahUlang != 'y' && apakahUlang != 'n');

    if(apakahUlang == 'y') {
        mencariUmur();
    }
}





// ================================================================ [ Menu Utama ]
// Fungsi untuk menampilkan beranda
void pilihanAwal() {
    system("cls");
    printf("=----------------------------------------=\n");
    printf("| Selamat Datang di Program Krisna       |\n");
    printf("=----------------------------------------=\n");
    printf("| Program Krisna                         |\n");
    printf("=----------------------------------------=\n");
    printf("|                                        |\n");
    printf("| Pilih salah satu game di bawah,        |\n");
    printf("| Ketik nomor game & tekan enter.        |\n");
    printf("|                                        |\n");
    printf("| 0. Keluar dari Game                    |\n");
    printf("|                                        |\n");
    printf("| A. Game Umum                           |\n");
    printf("| 1. Kalkulator                          |\n");
    printf("| 2. Menghitung Faktorial                |\n");
    printf("| 3. Deret Bilangan                      |\n");
    printf("|                                        |\n");
    printf("| B. Game 2D dan 3D                      |\n");
    printf("| 4. Mencari Luas Bangun Datar           |\n");
    printf("| 5. Mencari Keliling Bangun Datar       |\n");
    printf("| 6. Mencari Volume Bangun Ruang         |\n");
    printf("| 7. Mencari Luas Permukaan Bangun       |\n");
    printf("|                                        |\n");
    printf("| C. Game Konversi                       |\n");
    printf("| 8. Menghitung Skala                    |\n");
    printf("| 9. Menghitung Jarak, Kecepatan, Waktu  |\n");
    printf("| 10. Konversi Suhu                      |\n");
    printf("|                                        |\n");
    printf("| D. Game Matematika Tulen               |\n");
    printf("| 11. Menghitung Logaritma               |\n");
    printf("| 12. Menghitung Sudut Trigonometri      |\n");
    printf("| 13. Menghitung Pythagoras              |\n");
    printf("|                                        |\n");
    printf("| E. Game Tebakan                        |\n");
    printf("| 14. Mencari Umur                       |\n");
    printf("|                                        |\n");
    printf("=----------------------------------------=\n\n");

    int pilihan = 0;

    // Meminta pilihan game
    printf("Pilihan Anda: ");
    while(scanf("%d", &pilihan) != 1 || (pilihan <= -1 || 15 <= pilihan)) {
        printf("Input kurang tepat, masukkan salah satu angka dari 0 sampai 14.\n\n");
        printf("Pilihan Anda: ");
        while(getchar() != '\n');
    }

    // Pindah ke game
    switch (pilihan) {
        case 0:
            goto akhirPilihanAwal;
            break;
        case 1:
            kalkulator();
            break;
        case 2:
            faktorial();
            break;
        case 3:
            deretBilangan();
            break;
        case 4:
            luasBangunDatar();
            break;
        case 5:
            kelilingBangunDatar();
            break;
        case 6:
            volumeBangunRuang();
            break;
        case 7:
            luasPermukaanBangunRuang();
            break;
        case 8:
            menghitungSkala();
            break;
        case 9:
            menghitungJKW();
            break;
        case 10:
            konversiSuhu();
            break;
        case 11:
            menghitungLogaritma();
            break;
        case 12:
            sudutTrigonometri();
            break;
        case 13:
            menghitungPythagoras();
            break;
        case 14:
            mencariUmur();
            break;
        default:
            goto akhirPilihanAwal;
            break;
    }

    pilihanAwal();

    akhirPilihanAwal:
}

int main() {    
    // Membuat console menampilkan UNICODE
    SetConsoleOutputCP(CP_UTF8);

    pilihanAwal();

    printf("\n=----------------------------------------=\n");
    printf("| Akhir dari Program, terima kasih.      |\n");
    printf("=----------------------------------------=\n\n");

    return 0;
}