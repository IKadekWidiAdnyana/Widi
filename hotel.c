#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int pilihanmenu;
int pilihanmasuk;
time_t waktuserver;

// Struct User untuk menyimpan member nama, username, password
typedef struct {
    char nama[50];
    char username[15];
    char password[15];
    char email[50];
} User;

void header();
void menu();
void input_masukan();
void error_alert();
void menu_program();
void menu_masuk();
void menu_kategori();
void email_pw();
void daftar();
void masuk();
void waktu();
void welcome();
void keluar();
void tentang_hotel();
void tipe_kamar();
User u; 

char namaFile[] = "logRecord.txt";

//harga kamar/malam
const float deluxeR = 900000;
const float juniorS = 1500000;
const float executiveS = 2500000;
const float regencyS = 5500000;
const float presidentialS = 10500000;

//jumlah kamar/tipe
int jmlh_deluxeR = 10;
int jmlh_juniorS = 10;
int jmlh_executiveS = 5;
int jmlh_regencyS = 5;
int jmlh_presidentialS = 3;


int main (){
    system ("color 2f");
    header();
    system ("cls");
    menu_masuk();
    menu_program();
    //pemanggilan fungsi untuk menu program
}

void header(){
    system ("cls");
    welcome();
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");	
	printf  ("\t\t\t\t\t||       *Program Reservasi Kamar Entity's Hotel*      ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                         Oleh                        ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t||  1. I Kadek Widi Adnyana             (2105551015)   ||\n");
	printf  ("\t\t\t\t\t||  2. Bayu Indra Mahadika              (2105551018)   ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t||           Program Studi Teknologi Informasi         ||\n");
	printf  ("\t\t\t\t\t||                   Fakultas Teknik                   ||\n");
	printf  ("\t\t\t\t\t||                 Universitas Udayana                 ||\n");
	printf  ("\t\t\t\t\t||                        2021                         ||\n");
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t                Tekan ENTER  untuk melanjutkan...        \n");
    printf  ("\t\t\t\t\t=========================================================\n");
	getchar ();
    system ("cls");
}

void menu_program(){
    pilih:
    printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                     MENU PROGRAM                    ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   NO  |    PILIHAN MENU                             ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   1   |    MENU                                     ||\n");
	printf  ("\t\t\t\t\t||   2   |    KELUAR                                   ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf ("\t\t\t\t\t Masukkan nomor menu yang anda inginkan ==> ");
    scanf  ("%d",&pilihanmenu);
    printf  ("\t\t\t\t\t---------------------------------------------------------\n");
    system("cls");
    
    switch(pilihanmenu){
    	case 1:
    		menu_kategori();
    		break;
    	case 2:
    		system (EXIT_SUCCESS);
		break;
    	default:
        	error_alert();
        	goto pilih;
                break;
	}
}

void menu_kategori(){
	int kategori;
	system("cls");
	kategori_menu:
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                     KATEGORI MENU                   ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   NO  |    PILIHAN KATEGORI MENU                    ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   1   |    TENTANG HOTEL                            ||\n");
	printf  ("\t\t\t\t\t||   2   |    LIHAT TIPE KAMAR                         ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t Masukkan nomor menu yang anda inginkan ==> ");
	scanf   ("%d", &kategori);
	system  ("cls");
	
	switch(kategori){
		case 1:
			tentang_hotel();
			break;
		case 2:
			tipe_kamar();
			break;	
		default:
        	error_alert();
        	goto kategori_menu;
        	break;	
	}
}
void menu_masuk(){
    // Variabel pilihan yang digunakan untuk menyimpan pilihan pengguna antara Masuk dengan Registrasi
    int pilihan;

    // Instruksi yang diberikan kepada pengguna
    menu_program:
    printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                     MENU PROGRAM                    ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   NO  |    PILIHAN MENU                             ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   1   |    MASUK                                    ||\n");
	printf  ("\t\t\t\t\t||   2   |    REGISTRASI                               ||\n");
	printf  ("\t\t\t\t\t||   3   |    KELUAR                                   ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf ("\t\t\t\t\t Masukkan nomor menu yang anda inginkan ==> ");
    scanf  ("%d", &pilihan);
    printf ("\t\t\t\t\t|================================================|\n");
    // Membersihkan Layar terminal 
    system ("cls");

    /* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pilihan jika pengguna menuliskan 1 maka akan dipanggil fungsi masuk()
       jika pengguna menuliskna 2 maka akan dipanggil fungsi registrasi()    */
    switch (pilihan){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk
        masuk();
        break;
    case 2:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi registrasi
        daftar();
        break;
    case 3:
        exit(1);
        break;
    default:
        error_alert();
        // Kembali ke label instruksi jika terjadi kesalahan dalam menginput pilihan
        goto menu_program;
        break;
    }
}

void tentang_hotel(){
	int tekan1;
	printf ("\t\t\t\t\t-----------------------------------------------------------\n");
	printf ("\t\t\t\t\t||                     TENTANG HOTEL                     ||\n");
	printf ("\t\t\t\t\t-----------------------------------------------------------\n");
	printf ("\t\t\t\t\t| ENTITY'S HOTEL terletak di suatu lahan seluas 39 hektar |\n");
    printf ("\t\t\t\t\t|di garis pantai  yang indah di mana merupakan tempat yang|\n");
    printf ("\t\t\t\t\t|   cocok untuk bisnis dan liburan. Lokasinya langsung    |\n");
    printf ("\t\t\t\t\t|mengarah ke matahari terbit di pantai, di mana menawarkan|\n");
    printf ("\t\t\t\t\t|   layanan terbaik dengan jangkauan layanan 24 jam dan   |\n");
    printf ("\t\t\t\t\t|     keramahan yang ditawarkan selama masa inap Anda.    |\n");
    printf ("\t\t\t\t\t|         Alamat Hotel : Jln. Hang Tuah, Sanur Bali       |\n");
    printf ("\t\t\t\t\t|                  Telepon : +62 36123456                 |\n");
    printf ("\t\t\t\t\t|           Email Reservasi: entity@hotel.co.id           |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|          Tekan 1 untuk kembali ke kategori menu         |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    tekan:
    	printf ("\t\t\t\t\t|Tekan 1 : ") ;
	scanf  ("%d", &tekan1);
	if (tekan1== 1)
		menu_kategori();
	else 
		printf ("\t\t\t\t\t|Anda Tidak Menekan 1!, Silahkan Tekan  Ulang 1 \n");
		goto tekan;
}

void tipe_kamar(){
	system("cls");
	int tekan1;
	printf  ("\n");
	printf  ("\t|--------------------------------------------------------DAFTAR TIPE KAMAR-----------------------------------------------------|\n");
	printf  ("\t|------------------------------------------------------------------------------------------------------------------------------|\n");
	printf  ("\t| KODE TIPE KAMAR | NAMA TIPE KAMAR |                    FASILITAS                                | HARGA/MALAM | JUMLAH KAMAR |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        D        |   DELUXE ROOM   | Lokasi Di Lantai 3 - 9, Tempat Tidur King/Twin,             |Rp.900.000   |   10 Kamar   |\n");
	printf  ("\t|                 |    Kapasitas    | Ukuran 32m2, Balkon Pribadi, Pembuat Kopi Dengan            |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Cangkir N Saucer, Kamar Mandi Dengan Bathtub Terpisah,      |             |              |\n");
	printf  ("\t|                 |                 | Koneksi WI-FI Dalam Kamar, Mini Bar Isi Ulang Harian Untuk  |             |              |\n");
	printf  ("\t|                 |                 | Untuk Minuman Non Alkohol, AC, Televisi Kabel Dan Telepon   |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        J        |   JUNIOR SUITE  | Lokasi Di Lantai 3, Tempat Tidur King, Ukuran 100m2,        |Rp.1.500.000 |   10 Kamar   |\n");
	printf  ("\t|                 |    Kapasitas    | Balkon Pribadi, Pembuat Kopi Dengan Cangkir N Saucer,       |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Kamar Mandi Dengan Bathtub Terpisah, Koneksi WI-FI          |             |              |\n");
	printf  ("\t|                 |                 | Dalam Kamar, Mini Bar Isi Ulang Harian Untuk Minuman        |             |              |\n");
	printf  ("\t|                 |                 | Non Alkohol, AC, Televisi Kabel Dan Telepon Sambungan       |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        E        | EXECUTIVE SUITE | Lokasi Di Lantai 3-6 dan 9, Tempat Tidur King, Ukuran 99m2, |Rp.2.500.000 |   5 Kamar    |\n");
	printf  ("\t|                 |    Kapasitas    | Balkon Pribadi, Pembuat Kopi Dengan Cangkir N Saucer,       |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Kamar Mandi Dengan Bathtub Terpisah, Koneksi WI-FI          |             |              |\n");
	printf  ("\t|                 |                 | Dalam Kamar, Mini Bar Isi Ulang Harian Untuk Minuman        |             |              |\n");
	printf  ("\t|                 |                 | Non Alkohol, AC, Televisi Kabel Dan Telepon Sambungan       |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        R        |  REGENCY SUITE  | Lokasi Di Lantai 4-9, Tempat Tidur King, Ukuran 106m2,      |Rp.5.500.000 |   5 Kamar    |\n");
	printf  ("\t|                 |    Kapasitas    | Balkon Pribadi, Pembuat Kopi Dengan Cangkir N Saucer,       |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Kamar Mandi Dengan Bathtub Terpisah, Koneksi WI-FI          |             |              |\n");
	printf  ("\t|                 |                 | Dalam Kamar, Mini Bar Isi Ulang Harian Untuk Minuman        |             |              |\n");
	printf  ("\t|                 |                 | Non Alkohol, AC, Televisi Kabel Dan Telepon Sambungan       |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        P        |   PRESIDENTIAL  | Lokasi Di Lantai 7-8, 2 Tempat Tidur King, Ukuran 165m2,    |Rp.10.500.000|   3 Kamar    |\n");
	printf  ("\t|                 |      SUITE      | Satu Ruang Pertemuan, Ruang Perpustakaan, Ruang Tamu        |             |              |\n");
	printf  ("\t|                 |    Kapasitas    | yang Luas,  Balkon Pribadi yang luas, Pembuat Kopi Dengan   |             |              |\n");
	printf  ("\t|                 |     4 Orang     | Cangkir N Saucer, Kamar Mandi Dengan Bathtub dan Pancuran   |             |              |\n");
	printf  ("\t|                 |                 | Terpisah, Koneksi WI-FI Dalam Kamar, Mini Bar Isi Ulang     |             |              |\n");
	printf  ("\t|                 |                 | Harian Untuk MinumanNon Alkohol, AC, Tangga Unik Penghubung |             |              |\n");
	printf  ("\t|                 |                 | Ke Lantai 8 Televisi Kabel Dan Telepon Sambungan Langsung   |             |              |\n");
	printf  ("\t|                 |                 | Internasional.                                              |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|---------------------------------------------Tekan 1 untuk kembali ke kategori menu-------------------------------------------|\n");
	printf  ("\t|------------------------------------------------------------------------------------------------------------------------------|\n");
	tekan:
    	printf ("\t|Tekan 1 : ") ;
	scanf  ("%d", &tekan1);
	if (tekan1== 1)
		menu_kategori();
	else 
		printf ("\t|Anda Tidak Menekan 1!, Silahkan Tekan Ulang 1 \n");
		goto tekan;
}

void masuk(){
    /*  Variabel username[15] digunakan untuk menyimpan input username
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan username yang sudah terdaftar pada file logRecord.txt   */
    char username[15];

    /*  Variabel password[15] digunakan untuk menyimpan input password
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan password yang sudah terdaftar pada file logRecord.txt   */
    char password[15];

    // Variabel pilihan untuk pilihan user apakah ingin mendaftar atau keluar
    int pilihan;

    // Membuat pointer record untuk menunjuk pada file "logRecord.txt"
    FILE *record;
    // Membuka file dengan mode "r"
    record = fopen (namaFile, "r");
    if (record == NULL){
        fputs ("Error, Tidak terdapat File untuk penyimpanan akun\n", stderr);
        daftar();
    }

    // Memperlihatkan tanggal login
    waktu();
    // Instruksi untuk LOGIN
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||   SILAHKAN LOGIN DENGAN MEMASUKKAN USERNAME DAN PASSWORD!  ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t|| Username: ");
    scanf  ("%s", username);
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t|| Password: ");
    scanf  ("%s", password);
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    system ("cls");
    // Membeaca file "logRecord.txt"
    while(fread(&u,sizeof(u),1,record)){
        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
    		printf  ("\t\t\t\t\t||                  LOGIN BERHASIL!                    ||\n");
    		printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	
        }
        //  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program
        else {
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
            printf  ("\t\t\t\t\t||                 AKUN TIDAK TERDAFTAR!               ||\n");
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");

            instruksi:
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
            printf  ("\t\t\t\t\t|| KETIK 1 UNTUK DAFTAR                                ||");
            printf  ("\n\t\t\t\t\t|| KETIK 2 UNTUK MASUK ULANG                           ||");
            printf  ("\n\t\t\t\t\t|| KETIK 3 UNTUK KELUAR                                ||\n");
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
            printf ("\n\t\t\t\t\t||Pilihan: ");
            scanf ("%d", &pilihan);
            system ("cls");
            // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi daftar
            if (pilihan == 1){
                daftar();
            /* Menggunakan fungsi recursive kepada fungsi masuk agar pengguna
               dapat melakukan percobaan masuk kembali jika terjadi kesalahan penulisan */
            } else if (pilihan==2) {
                masuk();
            } else if (pilihan ==3){
                exit(1);
            } else {
            	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
                printf ("\t\t\t\t\t|| ERROR!! SILAHKAN KETIK PERINTAH YANG SUDAH DIBERIKAN ||\n");
                printf  ("\t\t\t\t\t---------------------------------------------------------\n");
                goto instruksi;
            }
        }
    }
    fclose(record);
    return;
}

void error_alert(){
    printf   ("\t\t\t\t\t=========================================================\n");
    printf   ("\t\t\t\t\t||          Pilihan yang Anda masukan Salah!!!         ||\n");
    printf   ("\t\t\t\t\t||     Silahkan Memilih Pilihan Menu Yang Sudah Ada!   ||\n");
    printf   ("\t\t\t\t\t=========================================================\n");
}

void welcome(){
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");	
	printf  ("\t\t\t\t\t||          *SELAMAT DATANG DI ENTITY'S HOTEL*         ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t=========================================================\n");
}

void keluar(){
	printf  ("\t\t\t\t\t=========================================================\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");	
	printf  ("\t\t\t\t\t||             *TERIMA KASIH TELAH MEMESAN*            ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t=========================================================\n");
}

void daftar(){
    // Membuat pointer regis untuk file "logRecord.txt"
    FILE *regis;

    // Membuka file "logRecord.txt" dengan mode "w"
    regis = fopen(namaFile,"w");

    // Melakukan Pengecekan apakah pointer regis menunjuk kepada file yang dituju ("logRecord.txt")
    if (regis == NULL)
    {
        fputs("ERROR, Tidak ada File!", stderr);
        exit(1);
    }

    // Instruksi untuk menginput nama
    printf ("\t\t\t\t\t||============================================================||\n");
    printf ("\t\t\t\t\t||               SILAHKAN REGISTRASI AKUN ANDA                ||\n");
    printf ("\t\t\t\t\t||============================================================||\n");
    getchar();
    printf("\t\t\t\t\t|| Nama Lengkap: ");
    gets(u.nama);
    printf ("\t\t\t\t\t||============================================================||\n");
    printf("\t\t\t\t\t|| Email anda: ");
    scanf ("%s", u.email);
    printf ("\t\t\t\t\t||============================================================||\n");
    printf("\n\t\t\t\t\t Hallo %s!\n", u.nama);
    printf ("\t\t\t\t\t Silahkan membuat username (max 15 karakter) serta membuat password (max 15 karakter)\n");

    // Instruksi untuk menginput username serta password
    printf("\n\t\t\t\t\t Enter Username:");
    scanf ("%s", u.username);
    printf("\n\t\t\t\t\t Enter Password:");
    scanf ("%s", u.password);
    
    // Membersikan layar terminal
	system("cls");
	
    // Menuliskan nama yang diinput oleh pengguna kedalam file "logRecord.txt"
    fwrite(&u,sizeof(u),1,regis);
    fclose(regis);
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||  REGISTRASI SELESAI, AKUN ANDA TERDAFTAR SILAHKAN MENCOBA  ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    getchar();
    
    // Memanggil fungsi masuk()
    masuk();
}

void waktu(){
    time( & waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    printf("\n\t\t\t\t\t||========================Tanggal: %i/%i/%i=================||\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
}
