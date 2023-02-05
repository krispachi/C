// Program Jarak Lingkaran Berputar
// Oleh Krispachi
// Jika ada komentar yang tidak dimengerti artinya, mungkin itu ga ada artinya :v

/* info program: program ini mencari jarak yang ditempuh sebuah roda,
dengan memasukkan input jari-jari dan banyak roda itu berputar, 
nanti mengeluarkan output jarak yang ditempuh roda itu,
saya juga membuat supaya bisa memilih untuk menginput apa saja,
maksudnya anda bisa menginputkan jarak dan banyaknya berputar
atau yang lain sesuai pilihan yang ada*/

#include <stdio.h>

int main() {

// deklarasi variabel
int pilihan;
float phi = 3.1428571429;
float diameter, jari, kll, nputar, njarak;


//selamat datang di dunia lain :v
printf("\nSelamat datang di program Jarak Lingkaran Berputar\n\n");

//menanyakan pilihan
printf("Mau cari apa?\n\n");

printf("1. Berapa jarak yang ditempuh lingkaran dengan memasukkan\n");
printf(" - Jari-jari Lingkarannya dan banyaknya berputar\n\n");

printf("2. Berapa kali lingkaran berputar dengan memasukkan\n");
printf(" - Jarak dan Jari-jari Lingkaran\n\n");

printf("3. Berapa Jari-jari Lingkaran dengan memasukkan Banyaknya\n");
printf(" - Lingkaran berputar dan Jarak yang ditempuh\n\n");
//saya tahu teks diatas banyak printf nya, seharusnya pakai \n aja
//jadi tidak perlu banyak printf.
//ya wkkwk tapi supaya terlihat agak sedikit rapi saya buat seperti itu hehe

//masukkan pilihan anda!!
printf("[1/2/3] : ");
scanf("%d", &pilihan);

//pengkondisian yang merepotkan (mungkin sebaiknya pakai switch case)
if( pilihan == 1 ) {
    printf("\nMencari jarak yang ditempuh lingkaran?\n");

    printf("Jari-jarinya berapa? : ");
    scanf("%f", &jari);

    diameter = jari * 2;

    printf("Berputar sebanyak? : ");
    scanf("%f", &nputar);

    //mari kita proses (maksudnya saya yg proses)
    kll = phi * diameter;
    njarak = kll * nputar;

    printf("\nJadi, jika Jari-jarinya %.2f dan berputar sebanyak %.2f\n", jari, nputar);
    printf("Maka, jarak yang ditempuh adalah %.2f (satuannya = satuan Jari-jari\n)", njarak);
    //teks diatas ini juga bisa dijadikan 1 printf tapi supaya
    //saya tidak bingung aowkaowka

} else if( pilihan == 2 ) {
    printf("\nMencari berapa kali lingkaran berputar ya?\n");

    printf("Jaraknya berapa ya? : ");
    scanf("%f", &njarak);

    printf("Jari-jari lingkarannya berapa? : ");
    scanf("%f", &jari);

    diameter = jari * 2;

    kll = phi * diameter;
    //menghitung berapa kali berputar
    nputar = njarak / kll;

    printf("\nJadi, jika Jaraknya %.2f dan Jari-jarinya %.2f\n", njarak, jari);
    printf("Maka, Lingkaran akan berputar sebanyak %.2f kali\n", nputar);

//waduh ini yang terakhir wkwkw, jangan lupa di share kalau anda bukan saya
} else if( pilihan == 3) {
    printf("\nMencari Jari-jarinya ya?\nHmm.. okelah wkwk\n");

    printf("Lingkarannya berputar berapa kali? : ");
    scanf("%f", &nputar);

    printf("Sejauh mana dia berputar? : ");
    scanf("%f", &njarak);

    //waduh, gimana logikanya ini hitungnya wkkwk
    kll = njarak / nputar;
    //nah begitu cara mencari kelilingnya (jangan sampai terbalik ya)

    //jika kll = phi * diameter, jadi...
    diameter = kll / phi;
    //nanti jadinya diameter = kll / 3.1428571429
    //diameter = kll * 10000000000/3.1428571429
    //kurang lebih cara kerjanya begitu tetapi tidak ditampilkan
    //hasilnya saja yang ditmpilkan nanti

    //sekarang ubah diameter menjadi Jari-jari
    jari = diameter / 2;

    printf("Jadi, jika diketahui Jarak = %.2f dan Banyaknya berputar = %.2f\n", njarak, nputar);
    printf("Maka, Jari-jarinya adalah %.2f\n", jari);

} else {
    printf("\nKetik angka 1 sampai 3 saja sesuai pilihan");
}

return 0;

}

//jika ada error, bisa kasi tahu saya kwkwk
