#include<stdio.h> //header standar input output dalam bahasa C
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Struct User untuk menyimpan member nama, username, password
typedef struct {
    char nama[50];
    char username[15];
    char password[15];
    char email[50];
} User;
User u;

//deklarasi variabel
time_t waktuserver;
int biaya_admin=5000;


//Deklarasi Variabel admin
char id_admin[20];
char pass_admin[20];

//Deklarasi fungsi-fungsi yang digunakan pada program ini
void header();
void menu();
void error_alert();
void menu_masuk();
void menu_kategori();
void daftar();
void masuk();
void waktu();
void welcome();
void keluar();
void tentang_hotel();
void tipe_kamar();
void pesan_kamar();
void tipe_Kamar();
void masuk_admin();
void menu_admin();
void pesan_lagi();
	
// assign namaFile (nF) agar menyimpan string "logRecord.txt"
char namaFile[] = "logRecord.txt";


//harga kamar/malam
int deluxeR = 900000;
int juniorS = 1500000;
int executiveS = 2500000;
int regencyS = 5500000;
int presidentialS = 10500000;

//jumlah kamar/tipe
int jmlh_deluxeR = 10;
int jmlh_juniorS = 10;
int jmlh_executiveS = 5;
int jmlh_regencyS = 5;
int jmlh_presidentialS = 5;


int main (){
    system ("color 2f");//agar tampilan background dan tulisan program ketika dijalankan berubah warna
    header();
    system ("cls");
    menu_masuk();
    
    //pemanggilan fungsi untuk menu program
}

void header(){
    system ("cls");
    welcome();
	printf  ("\t\t\t\t\t*********************************************************\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");	
	printf  ("\t\t\t\t\t||       *Program Reservasi Kamar Entity's Hotel*      ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t*********************************************************\n");
	printf  ("\t\t\t\t\t||                         PEMBUAT:                    ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t||  1. I Kadek Widi Adnyana             (2105551015)   ||\n");
	printf  ("\t\t\t\t\t||  2. Bayu Indra Mahadika              (2105551018)   ||\n");
	printf  ("\t\t\t\t\t||                                                     ||\n");
	printf  ("\t\t\t\t\t*********************************************************\n");
	printf  ("\t\t\t\t\t                Tekan ENTER untuk lanjut...	 	     \n");
    	printf  ("\t\t\t\t\t*********************************************************\n");
	getchar ();
    system ("cls");
}

void menu_kategori(){
	int kategori;
	kategori_menu:
	system("cls");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                KATEGORI MENU PENGUNJUNG             ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   NO  |    PILIHAN KATEGORI MENU                    ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   1   |    TENTANG HOTEL                            ||\n");
	printf  ("\t\t\t\t\t||   2   |    LIHAT TIPE KAMAR                         ||\n");
	printf  ("\t\t\t\t\t||   3   |    KEMBALI KE MENU PROGRAM                  ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t Masukkan nomor menu yang anda inginkan ==> ");
	scanf   ("%d", &kategori);
	system  ("cls");
	int pilih1;
	switch(kategori){
		case 1:
			// Jika pengguna menginput angka 1 maka dipanggil fungsi tentang_hotel()
			tentang_hotel();
				tekan:
			printf("\t\t\t\t\tTekan 1 Untuk Kembali	:");
			scanf("%d", &pilih1);
			if (pilih1== 1)
				menu_kategori();
			else 
			printf ("\tAnda Tidak Menekan 1!, Silahkan Tekan  Ulang 1 \n");
			goto tekan;
			break;
		case 2:
			// Jika pengguna menginput angka 2 maka dipanggil fungsi tipe_kamar()
			tipe_kamar();
			tekan1:
			printf("\tTekan 1 Untuk Kembali	:");
			scanf("%d", &pilih1);
			if (pilih1== 1)
				menu_kategori();
			else 
			printf ("\tAnda Tidak Menekan 1!, Silahkan Tekan  Ulang 1 \n");
			goto tekan1;
			break;	
		case 3:
			// Jika pengguna menginput angka 3 maka dipanggil fungsi menu_masuk()
			menu_masuk();
			break;
		default:
			// Kembali ke label kategori_menu jika terjadi kesalahan dalam menginput pilihan
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
    system("cls");
    	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                     MENU PROGRAM                    ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   NO  |    PILIHAN MENU                             ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   1   |    MASUK UNTUK ADMIN                        ||\n");
	printf  ("\t\t\t\t\t||   2   |    MASUK UNTUK PENGUNJUNG                   ||\n");
	printf  ("\t\t\t\t\t||   3   |    REGISTRASI UNTUK PENGUNJUNG              ||\n");
	printf  ("\t\t\t\t\t||   4   |    KELUAR                                   ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf ("\t\t\t\t\t Masukkan nomor menu yang anda inginkan ==> ");
    scanf  ("%d", &pilihan);
    printf ("\t\t\t\t\t|================================================|\n");
    // Membersihkan Layar terminal 
    system ("cls");

    switch (pilihan){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk_admin()
        masuk_admin();
        break;
    case 2:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi masuk()
        masuk();
        break;
    case 3:
    	// Jika pengguna menginput angka 3 maka dipanggil fungsi daftar()
        daftar();
        break;
    case 4:
    	// Jika pengguna menginput angka 4 maka program akan keluar/selesai
    	keluar();
    	break;
    default:
    	// Kembali ke label menu_program jika terjadi kesalahan dalam menginput pilihan
        error_alert();
        goto menu_program;
        break;
    }
}

void menu_admin(){
	int admin1;
	ktgri_admin:
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||                  KATEGORI MENU ADMIN                ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   NO  |    PILIHAN KATEGORI MENU                    ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t||   1   |    LIHAT TIPE KAMAR                         ||\n");
	printf  ("\t\t\t\t\t||   2   |    PESAN KAMAR                              ||\n");
	printf  ("\t\t\t\t\t||   3   |    KEMBALI KE MENU PROGRAM                  ||\n");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	printf  ("\t\t\t\t\t Masukkan nomor menu yang anda inginkan ==> ");
	scanf   ("%d", &admin1);
	system("cls");
	
	switch(admin1){
		case 1:
			// Jika pengguna menginput angka 1 maka dipanggil fungsi tipe_kamar()
			tipe_Kamar();
			break;	
		case 2:
			// Jika pengguna menginput angka 2 maka dipanggil fungsi pesan_kamar()
			pesan_kamar();
			break;
		case 3:
			menu_masuk();
			break;
		default:
			// Kembali ke label ktgri_admin jika terjadi kesalahan dalam menginput pilihan
        	error_alert();
        	goto ktgri_admin;
        	break;	
	}
	
}

void masuk_admin(){
 	login:
 	waktu();
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||  SILAHKAN LOGIN DENGAN MEMASUKKAN USERNAME DAN PASSWORD!  ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t|| Username: ");
    scanf  ("%s", &id_admin);
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t|| Password: ");
    fflush(stdin);
	char ch;
	int i=0;
	while((ch =(char)_getch()) !='\r'){//code ini berfungsi untuk mengubah tampilan password admin menjadi'*"
		pass_admin[i] = ch;
		printf("*");
		i++;	
	}
	printf  ("\n\t\t\t\t\t---------------------------------------------------------------\n\n");
	if (strcmp(id_admin,"admin1")==0 && strcmp(pass_admin,"admin1")==0){
		system("cls");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
    	printf  ("\t\t\t\t\t||                   LOGIN BERHASIL!                   ||\n");
    	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
	 	menu_admin();//jika admin memaskukkan username dan password dengan benar akan menuju fungsi menu_admin()
	}else if (strcmp(id_admin,"admin2")==0 && strcmp(pass_admin,"admin2")==0){
		system("cls");
	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
    	printf  ("\t\t\t\t\t||                   LOGIN BERHASIL!                   ||\n");
    	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
		menu_admin();//jika admin memaskukkan username dan password dengan benar akan menuju fungsi menu_admin()
	}else{
		system("cls");
	printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    	printf  ("\t\t\t\t\t||   MAAF USERNAME ATAU PASSWORD YANG ANDA MASUKKAN SALAH    ||\n");
    	printf  ("\t\t\t\t\t||                     SILAHKAN COBA LAGI!                   ||\n");
    	printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
	 	goto login;// Kembali ke label login jika terjadi kesalahan dalam menginput username atau password
 }
}	


void tentang_hotel(){
	system("cls");
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
    	printf ("\t\t\t\t\t|---------------------------------------------------------|\n");
}

void tipe_kamar(){
	system("cls");
	printf  ("\n");
	printf  ("\t|--------------------------------------------------------DAFTAR TIPE KAMAR-----------------------------------------------------|\n");
	printf  ("\t|------------------------------------------------------------------------------------------------------------------------------|\n");
	printf  ("\t| KODE TIPE KAMAR | NAMA TIPE KAMAR |                    FASILITAS                                | HARGA/MALAM | JUMLAH KAMAR |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        1        |   DELUXE ROOM   | Lokasi Di Lantai 3 - 9, Tempat Tidur King/Twin,             |Rp.900.000   |   %d Kamar   |\n", jmlh_deluxeR);
	printf  ("\t|                 |    Kapasitas    | Ukuran 32m2, Balkon Pribadi, Pembuat Kopi Dengan            |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Cangkir N Saucer, Kamar Mandi Dengan Bathtub Terpisah,      |             |              |\n");
	printf  ("\t|                 |                 | Koneksi WI-FI Dalam Kamar, Mini Bar Isi Ulang Harian Untuk  |             |              |\n");
	printf  ("\t|                 |                 | Untuk Minuman Non Alkohol, AC, Televisi Kabel Dan Telepon   |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        2        |   JUNIOR SUITE  | Lokasi Di Lantai 3, Tempat Tidur King, Ukuran 100m2,        |Rp.1.500.000 |   %d Kamar   |\n", jmlh_juniorS);
	printf  ("\t|                 |    Kapasitas    | Balkon Pribadi, Pembuat Kopi Dengan Cangkir N Saucer,       |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Kamar Mandi Dengan Bathtub Terpisah, Koneksi WI-FI          |             |              |\n");
	printf  ("\t|                 |                 | Dalam Kamar, Mini Bar Isi Ulang Harian Untuk Minuman        |             |              |\n");
	printf  ("\t|                 |                 | Non Alkohol, AC, Televisi Kabel Dan Telepon Sambungan       |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        3        | EXECUTIVE SUITE | Lokasi Di Lantai 3-6 dan 9, Tempat Tidur King, Ukuran 99m2, |Rp.2.500.000 |   %d Kamar    |\n", jmlh_executiveS);
	printf  ("\t|                 |    Kapasitas    | Balkon Pribadi, Pembuat Kopi Dengan Cangkir N Saucer,       |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Kamar Mandi Dengan Bathtub Terpisah, Koneksi WI-FI          |             |              |\n");
	printf  ("\t|                 |                 | Dalam Kamar, Mini Bar Isi Ulang Harian Untuk Minuman        |             |              |\n");
	printf  ("\t|                 |                 | Non Alkohol, AC, Televisi Kabel Dan Telepon Sambungan       |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        4        |  REGENCY SUITE  | Lokasi Di Lantai 4-9, Tempat Tidur King, Ukuran 106m2,      |Rp.5.500.000 |   %d Kamar    |\n", jmlh_regencyS);
	printf  ("\t|                 |    Kapasitas    | Balkon Pribadi, Pembuat Kopi Dengan Cangkir N Saucer,       |             |              |\n");
	printf  ("\t|                 |     2 Orang     | Kamar Mandi Dengan Bathtub Terpisah, Koneksi WI-FI          |             |              |\n");
	printf  ("\t|                 |                 | Dalam Kamar, Mini Bar Isi Ulang Harian Untuk Minuman        |             |              |\n");
	printf  ("\t|                 |                 | Non Alkohol, AC, Televisi Kabel Dan Telepon Sambungan       |             |              |\n");
	printf  ("\t|                 |                 | Langsung Internasional.                                     |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
	printf  ("\t|        5        |   PRESIDENTIAL  | Lokasi Di Lantai 7-8, 2 Tempat Tidur King, Ukuran 165m2,    |Rp.10.500.000|   %d Kamar    |\n", jmlh_presidentialS);
	printf  ("\t|                 |      SUITE      | Satu Ruang Pertemuan, Ruang Perpustakaan, Ruang Tamu        |             |              |\n");
	printf  ("\t|                 |    Kapasitas    | yang Luas,  Balkon Pribadi yang luas, Pembuat Kopi Dengan   |             |              |\n");
	printf  ("\t|                 |     4 Orang     | Cangkir N Saucer, Kamar Mandi Dengan Bathtub dan Pancuran   |             |              |\n");
	printf  ("\t|                 |                 | Terpisah, Koneksi WI-FI Dalam Kamar, Mini Bar Isi Ulang     |             |              |\n");
	printf  ("\t|                 |                 | Harian Untuk MinumanNon Alkohol, AC, Tangga Unik Penghubung |             |              |\n");
	printf  ("\t|                 |                 | Ke Lantai 8 Televisi Kabel Dan Telepon Sambungan Langsung   |             |              |\n");
	printf  ("\t|                 |                 | Internasional.                                              |             |              |\n");
	printf  ("\t|-----------------|-----------------|-------------------------------------------------------------|-------------|--------------|\n");
    
}

void tipe_Kamar(){
	char listmenu;
	system ("cls");
    tipe_kamar();
	printf ("\t|Pesan Kamar [Y/T] : ") ;
	scanf  ("%s", &listmenu);
	system ("cls");
	if (listmenu== 'Y'|| listmenu == 'y')
		pesan_kamar ();//jika ingin memesan kamar maka akan menuju fungsi pesan_kamar()
	else 
		menu_admin();//kembali ke fungsi menu_admin() jika tidak ingin memesan kamar
}

//fungsi pemesanan
void pesan_kamar(){
	struct pesanKamar{
		char nama[20];
		char noHP[20];
		char jenis_kelamin[5];
		int umur;
		int pilih_tipe;
		int jumlah_kamar;
		int lama_sewa;
	}Pesan;
	tipe_kamar();
	int total=0;
    printf ("\n\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||                MASUKKAN DATA PEMESANAN KAMAR               ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf  ("\t\t\t\t\t|NAMA PEMESAN              :");
    scanf   ("%s", Pesan.nama, 20);
    printf  ("\t\t\t\t\t|NOMOR HP                  :");
    scanf   ("%s", &Pesan.noHP);
    printf  ("\t\t\t\t\t|JENIS KELAMIN             :");
    scanf   ("%s", &Pesan.jenis_kelamin);
    printf  ("\t\t\t\t\t|UMUR                      :");
    scanf   ("%d", &Pesan.umur);
    
    printf  ("\t\t\t\t\t|PILIHAN TIPE KAMAR\n");
    printf  ("\t\t\t\t\t 1. DELUXE ROOM \n");
    printf  ("\t\t\t\t\t 2. JUNIOR SUITE \n");
    printf  ("\t\t\t\t\t 3. EXECUTIVE SUITE \n");
    printf  ("\t\t\t\t\t 4. REGENCY SUITE \n");
    printf  ("\t\t\t\t\t 5. PRESIDENTIAL SUITE \n");
    
    printf  ("\t\t\t\t\t|PILIH TIPE KAMAR          :");
    scanf   ("%d", &Pesan.pilih_tipe, 10);
    printf  ("\t\t\t\t\t|JUMLAH KAMAR PESAN        :");
    scanf   ("%d", &Pesan.jumlah_kamar);
    printf  ("\t\t\t\t\t|LAMA INAP                 :");
    scanf   ("%d", &Pesan.lama_sewa);
    system("cls");
    
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||                       DATA PEMESANAN                       ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf  ("\t\t\t\t\t|NAMA PEMESAN              :%s\n", Pesan.nama);
    printf  ("\t\t\t\t\t|NOMOR HP                  :%s\n", Pesan.noHP);
    printf  ("\t\t\t\t\t|JENIS KELAMIN             :%s\n", Pesan.jenis_kelamin);
    printf  ("\t\t\t\t\t|UMUR                      :%d\n", Pesan.umur);
    printf  ("\t\t\t\t\t|PILIHAN TIPE KAMAR        :%d\n", Pesan.pilih_tipe);
    printf  ("\t\t\t\t\t|JUMLAH KAMAR PESAN        :%d\n", Pesan.jumlah_kamar);
    printf  ("\t\t\t\t\t|LAMA INAP                 :%d HARI\n", Pesan.lama_sewa);

	if(Pesan.pilih_tipe, "DELUXE ROOM"){
		jmlh_deluxeR -= Pesan.jumlah_kamar;
		total = (Pesan.lama_sewa*deluxeR+biaya_admin)* Pesan.jumlah_kamar;
		printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);	
	}
	else if(Pesan.pilih_tipe, "JUNIOR SUITE"){
		jmlh_juniorS -= Pesan.jumlah_kamar;
		total = (Pesan.lama_sewa*juniorS+biaya_admin)* Pesan.jumlah_kamar;
		printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	}
	else if(Pesan.pilih_tipe, "EXECUTIVE SUITE"){
		jmlh_executiveS -= Pesan.jumlah_kamar;
		total = (Pesan.lama_sewa*executiveS+biaya_admin)* Pesan.jumlah_kamar;
		printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	}
	else if(Pesan.pilih_tipe, "REGENCY SUITE"){
		jmlh_regencyS -= Pesan.jumlah_kamar;
		total = (Pesan.lama_sewa*regencyS+biaya_admin)* Pesan.jumlah_kamar;
		printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	}
	else if(Pesan.pilih_tipe, "PRESIDENTIAL SUITE"){
		jmlh_presidentialS -= Pesan.jumlah_kamar;
		total = (Pesan.lama_sewa*presidentialS+biaya_admin)* Pesan.jumlah_kamar;
		printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	} 
	pesan_lagi();  
}

void pesan_lagi(){
	char pesan;
	printf ("\t|Pesan Kamar Lagi [Y/T] : ") ;
	scanf  ("%s", &pesan);
	system ("cls");
	if (pesan == 'Y'|| pesan == 'y')
		pesan_kamar();  //jika ingin memesan kamar maka akan menuju fungsi pesan_kama()
	else 
		menu_admin();//kembali ke fungsi menu_admin() jika tidak ingin memesan kamar
}

void masuk(){
    char username[15];
    char password[15];
    int pilihan;

    FILE *record;
    // Membuka file dengan mode "r"
    record = fopen (namaFile, "r");
    if (record == NULL){
        fputs ("\t\t\t\t\t\t ERROR!, TIDAK TERDAPAT AKUN YANG TERDAFTAR \n", stderr);
        daftar();
    }

    // Memperlihatkan tanggal login
    waktu();
    // Instruksi untuk LOGIN
    printf  ("\t\t\t\t\t***************************************************************\n");
    printf ("\t\t\t\t\t||   SILAHKAN LOGIN DENGAN MEMASUKKAN USERNAME DAN PASSWORD!  ||\n");
    printf  ("\t\t\t\t\t***************************************************************\n");
    printf ("\t\t\t\t\t|| Username: ");
    scanf  ("%s", username);
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t|| Password: ");
    scanf  ("%s", password);
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    system ("cls");
    // Membeaca file "logRecord.txt"
    while(fread(&u,sizeof(u),1,record)){
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
            	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
    		printf  ("\t\t\t\t\t||                   LOGIN BERHASIL!                   ||\n");
    		printf  ("\t\t\t\t\t---------------------------------------------------------\n");
    		menu_kategori();
        }
        //  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program
        else {
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
            printf  ("\t\t\t\t\t||                 AKUN TIDAK TERDAFTAR!               ||\n");
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");

            kembali:
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
            printf  ("\t\t\t\t\t\t|| TEKAN 1 UNTUK DAFTAR AKUN                             ||");
            printf  ("\n\t\t\t\t\t|| TEKAN 2 UNTUK MASUK ULANG AKUN                      ||");
            printf  ("\n\t\t\t\t\t|| TEKAN 3 UNTUK KELUAR DARI PROGRAM                   ||\n");
            printf  ("\t\t\t\t\t---------------------------------------------------------\n");
            printf ("\n\t\t\t\t\t||Pilihan: ");
            scanf ("%d", &pilihan);
            system ("cls");
            if (pilihan == 1){// Jika pengguna mengetik nomor 1 maka akan dialihkan ke fungsi daftar()
                daftar();
            /* Menggunakan fungsi recursive kepada fungsi masuk agar pengguna
               dapat melakukan percobaan masuk kembali jika terjadi kesalahan penulisan */
            } else if (pilihan==2) {// Jika pengguna mengetik nomor 2 maka akan dialihkan ke fungsi masuk() 
                masuk();
            } else if (pilihan ==3){// Jika pengguna mengetik nomor 3 maka akan keluar dari program 
                exit(1);
            } else {// Jika pengguna mengetik nomor yang tidak sesui maka akan kembali ke label intruksi 
            	printf  ("\t\t\t\t\t---------------------------------------------------------\n");
                printf ("\t\t\t\t\t|| ERROR!!! SILAHKAN KETIK PERINTAH YANG SUDAH ADA 	   ||\n");
                printf  ("\t\t\t\t\t---------------------------------------------------------\n");
                goto kembali;
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
    FILE *regis;
    // Membuka file "logRecord.txt" dengan mode "w"
    regis = fopen(namaFile,"w");

    if (regis == NULL)
    {
        fputs("ERROR, Tidak ada File!", stderr);
        exit(1);
    }

    // Instruksi untuk menginput nama
    printf ("\t\t\t\t\t||************************************************************||\n");
    printf ("\t\t\t\t\t||               SILAHKAN DAFTAR AKUN ANDA                    ||\n");
    printf ("\t\t\t\t\t||************************************************************||\n");
    getchar();
    printf("\t\t\t\t\t|| Nama Lengkap: ");
    gets(u.nama);
    printf ("\t\t\t\t\t||============================================================||\n");
    printf("\t\t\t\t\t|| Email anda: ");
    scanf ("%s", u.email);
    printf ("\t\t\t\t\t||============================================================||\n");
    printf("\n\t\t\t\t\t Selamat Datang %s! di Entity's Hotel \n", u.nama);
    printf ("\t\t\t\t\t Buat username (max 15 karakter) dan buat password (max 15 karakter)\n");

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
    printf("\n\t\t\t\t\t||************************Tanggal: %i/%i/%i/%i:%i*************************||\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900, waktu -> tm_hour, waktu -> tm_min);
}
