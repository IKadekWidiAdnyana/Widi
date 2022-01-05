#include<stdio.h> //header standar input output dalam bahasa C
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define JUM_BLOK 1

// Struct User untuk menyimpan member nama, username, password
typedef struct {
    char nama[50];
    char username[15];
    char password[15];
    char email[50];
} User;
User u;

//deklarasi variabel global
time_t waktuserver;
int biaya_admin=5000;
int hari1;
int pilih1;
char jawab;

//struct untuk pesan kamar
typedef struct pesanKamar{
		int id_pemesan;
		char nama[20];
		char noHP[20];
		char jenis_kelamin[5];
		int umur;
		int pilih_tipe;
		int jumlah_kamar;
		int lama_sewa;
		int tglCI;
		int blnCI;
		int thnCI;
		int tglCO;
		int blnCO;
		int thnCO;
	}pesanKamar;
	pesanKamar Pesan;
	
int total=0;

//Deklarasi Variabel admin
char id_admin[20];
char pass_admin[20];

//Deklarasi fungsi-fungsi yang digunakan pada program ini
void header();
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
void data_pemesan();
void list_data_pemesan();
void lihat_data_pemesan();
void hari();
void kalenderuntukCO ();
int Februari (int thn);        
int BknFeb (int thn, int bln);
void rumus_total();
int checkNomor(pesanKamar Pesan, int id);
void hapus_pesanan();
void hapus();
void hapusdtpesan (pesanKamar Pesan, int r);
	
// assign namaFile (nF) agar menyimpan string "logRecord.txt"
char namaFile[] = "logRecord.txt";
FILE *tampilan;


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
    tampilan=fopen("header.txt","r");
	char file[300];	
		while(fgets(file, sizeof(file), tampilan)){ 
			printf("\t\t\t\t %s", file);
		}
		fclose(tampilan);
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
	switch(kategori){
		case 1:
			// Jika pengguna menginput angka 1 maka dipanggil fungsi tentang_hotel()
			tentang_hotel();
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
	printf  ("\t\t\t\t\t||   3   |    LIHAT DATA PEMESANAN                     ||\n");
	printf  ("\t\t\t\t\t||   4   |    HAPUS DATA PESANAN                       ||\n");
	printf  ("\t\t\t\t\t||   5   |    KEMBALI KE MENU PROGRAM                  ||\n");
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
			lihat_data_pemesanan();
			break;
		case 4:
			hapus_pesanan();
		case 5:
			menu_masuk();
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
	tampilan=fopen("tentangHotel.txt","r");
	char file[300];	
		while(fgets(file, sizeof(file), tampilan)){ 
			printf("\t\t\t\t %s", file);
		}
		fclose(tampilan);
	int pilih;
			tekan:
			printf("\n");
			printf("\t\t\t\t  Tekan 1 Untuk Kembali	:");
			scanf("%d", &pilih);
			if (pilih== 1)
				menu_kategori();
			else 
			printf ("\t\t\t\t  Anda Tidak Menekan 1!, Silahkan Tekan  Ulang 1 \n");
			goto tekan;
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
	system ("cls");
	tipe_kamar();
	
    printf ("\n\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||                MASUKKAN DATA PEMESANAN KAMAR               ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    
    FILE* dtpesan;
    dtpesan = fopen ("datapesan.txt", "ab");
    if (dtpesan== NULL ){
		printf("\t\t\t\t\t|File tidak dapat dibuat!\r\n");
		menu_admin();
	}
	
	do{
		printf  ("\t\t\t\t\t|PILIH KODE TIPE KAMAR     :");
		scanf("%d", &Pesan.pilih_tipe);
		if (Pesan.pilih_tipe >=1 && Pesan.pilih_tipe <=5){	
		printf  ("\t\t\t\t\t|ID PEMESAN                :"); fflush(stdin); scanf("%d", &Pesan.id_pemesan);
	    printf  ("\t\t\t\t\t|NAMA PEMESAN              :"); fflush(stdin); gets (Pesan.nama);
	    printf  ("\t\t\t\t\t|NOMOR HP                  :"); fflush(stdin); scanf("%s", &Pesan.noHP);
	    printf  ("\t\t\t\t\t|JENIS KELAMIN             :"); fflush(stdin); scanf("%s", &Pesan.jenis_kelamin);
	    printf  ("\t\t\t\t\t|UMUR                      :"); fflush(stdin); scanf("%d", &Pesan.umur);
	    printf  ("\t\t\t\t\t|JUMLAH KAMAR PESAN        :"); fflush(stdin); scanf("%d", &Pesan.jumlah_kamar);
    	printf  ("\t\t\t\t\t|LAMA INAP                 :"); fflush(stdin); scanf("%d", &Pesan.lama_sewa);
   		printf  ("\t\t\t\t\t|Check In HARI [ANGKA]     :"); scanf ("%d", &hari1);
    	printf  ("\t\t\t\t\t|Check In [DD/MM/YYYY]     :"); fflush(stdin); scanf ("%d/%d/%d", &Pesan.tglCI, &Pesan.blnCI, &Pesan.thnCI);
    	rumus_total();
    	printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", Pesan.total);
    	
		fwrite(&Pesan, sizeof(Pesan), 1, dtpesan);
		}
		else{
			fflush(stdin);
			printf("\t\t\t\t\t|MASUKKAN KODE TIPE KAMAR YANG SUDAH ADA\n");
			getch();
			pesan_kamar();
		}
		data_pemesan();
		printf("\t\t\t\t\t--------------------------------------------------------------\n");
		printf ("\t\t\t\t\t|DATA PEMESANAN BERHASIL TERSIMPAN!. \n");
		printf ("\t\t\t\t\t|Pesan Kamar Lagi? Y/T :"); fflush(stdin);
		scanf("%s", &jawab);
	}
	while (jawab == 'Y' || jawab=='y');
	fclose(dtpesan);
	menu_admin();
}

void data_pemesan(){
	system("cls");
	printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf ("\t\t\t\t\t||                       DATA PEMESANAN                       ||\n");
    printf  ("\t\t\t\t\t---------------------------------------------------------------\n");
    printf  ("\t\t\t\t\t|PILIHAN KODE TIPE KAMAR   :%d\n", Pesan.pilih_tipe);
	printf  ("\t\t\t\t\t|ID PEMESAN                :%d\n", Pesan.id_pemesan);
    printf  ("\t\t\t\t\t|NAMA PEMESAN              :%s\n", Pesan.nama);
    printf  ("\t\t\t\t\t|NOMOR HP                  :%s\n", Pesan.noHP);
    printf  ("\t\t\t\t\t|JENIS KELAMIN             :%s\n", Pesan.jenis_kelamin);
    printf  ("\t\t\t\t\t|UMUR                      :%d\n", Pesan.umur);
    printf  ("\t\t\t\t\t|JUMLAH KAMAR PESAN        :%d\n", Pesan.jumlah_kamar);
    printf  ("\t\t\t\t\t|LAMA INAP                 :%d HARI\n", Pesan.lama_sewa);
    printf  ("\t\t\t\t\t|Check In                  :");
	hari (); //memanggil fungsi hari 
	printf (" %d/%d/%d\n", Pesan.tglCI, Pesan.blnCI, Pesan.thnCI);
	kalenderuntukCO (); //memanggil fungsi kalenderuntukCO
	
	hari1=hari1+(Pesan.lama_sewa%7);
	while (hari1>7)
		hari1=hari1%7;	
	printf  ("\t\t\t\t\t|Check Out                 :");
	hari();
	printf (" %d/%d/%d\n", Pesan.tglCO,Pesan.blnCO, Pesan.thnCO) ;
	printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", Pesan.total);
		
}

void rumus_total(){
	if(Pesan.pilih_tipe==1, "DELUXE ROOM"){
		jmlh_deluxeR -= Pesan.jumlah_kamar;
		Pesan.total = (Pesan.lama_sewa*deluxeR+biaya_admin)* Pesan.jumlah_kamar;
		//printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);	
	}
	else if(Pesan.pilih_tipe==2, "JUNIOR SUITE"){
		jmlh_juniorS -= Pesan.jumlah_kamar;
		Pesan.total = (Pesan.lama_sewa*juniorS+biaya_admin)* Pesan.jumlah_kamar;
	//	printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	}
	else if(Pesan.pilih_tipe==3, "EXECUTIVE SUITE"){
		jmlh_executiveS -= Pesan.jumlah_kamar;
		Pesan.total = (Pesan.lama_sewa*executiveS+biaya_admin)* Pesan.jumlah_kamar;
		//printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	}
	else if(Pesan.pilih_tipe==4, "REGENCY SUITE"){
		jmlh_regencyS -= Pesan.jumlah_kamar;
		Pesan.total = (Pesan.lama_sewa*regencyS+biaya_admin)* Pesan.jumlah_kamar;
		//printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	}
	else if(Pesan.pilih_tipe==5, "PRESIDENTIAL SUITE"){
		jmlh_presidentialS -= Pesan.jumlah_kamar;
		Pesan.total = (Pesan.lama_sewa*presidentialS+biaya_admin)* Pesan.jumlah_kamar;
		//printf  ("\t\t\t\t\t|HARGA TOTAL               :Rp. %d\n", total);
	} 
}

void lihat_data_pemesan(){
	char kembali; //deklarasi opsi_kembali ke dalam variabel bertipe data char
	system ("cls");
	list_data_pemesan (); //memanggil fungsi list_data_pemesan
	opsi :
	printf("\t\t| Kembali ke menu ketik Y : ");
	scanf ("%s", &kembali);
	if (kembali=='Y'||kembali=='y') //jika mengetik Y atau y maka akan mengarah pada fungsi menuadm
	    menu_admin();
	else //jika selain Y atau y maka akan balik pada opsi
	    goto opsi ;
}

void pesan_lagi(){
	char pesan;
	printf("\t\t\t\t\t------------------------------------------------------------\n");
	printf ("\t\t\t\t\t|Pesan Kamar Lagi [Y/T]	: ") ;
	scanf  ("%s", &pesan);
	system ("cls");
	if (pesan == 'Y'|| pesan == 'y')
		pesan_kamar();  //jika ingin memesan kamar maka akan menuju fungsi pesan_kama()
	else 
		menu_admin();//kembali ke fungsi menu_admin() jika tidak ingin memesan kamar
}

void list_data_pemesan(){
	system ("cls");
	printf ("\t\t|**********************************************************************************************************************************|\n");
	printf ("\t\t|                                                 DATA PEMESAN KAMAR                                                               |\n");
	printf ("\t\t|**********************************************************************************************************************************|\n");
	printf ("\t\t| Id Pemesan | Kode Kamar |     Nama Pemesan      |        NO HP      |     Jumlah Kamar Pesan     | Lama Inap  |   Total Bayar    |\n");
	printf ("\t\t|------------|------------|-----------------------|-------------------|----------------------------|------------|------------------|\n");                                                                                          
	FILE*dtpesan ; // Membuat pointer dtpesan untuk menunjuk pada file "datapesan.txt"
    dtpesan = fopen ("datapesan.txt", "rt"); // Membuka file "datapesan.txt" dengan mode "rt"
    if (dtpesan== NULL ){ // Melakukan Pengecekan apakah pointer dtpesan menunjuk kepada file yang dituju ("datapesan.txt")
		printf("\t\t\t| FILE TIDAK DAPAT DIBUKA!\r\n");
		menu_admin();
	}
		/* Ambil isi file ngenggunakan fungsi fread(), lalu tampilkan ke layar */
	while ((fread(&Pesan, sizeof(Pesan), JUM_BLOK, dtpesan)) == JUM_BLOK )
	printf ("\t\t|     %d          %d           %s               %s           %d       %d Hari     Rp.%.2f\n", Pesan.id_pemesan, Pesan.pilih_tipe, Pesan.nama, Pesan.noHP, Pesan.jumlah_kamar, Pesan.lama_sewa, total);
	fclose(dtpesan);
	printf ("\t\t|==================================================================================================================================|\n");
}

int checkNomor(pesanKamar Pesan,int id){
	FILE *dtpesan;
	int c = 1;
	if(c==1){
		dtpesan = fopen("datapesan.txt","rb");
		while(fread(&Pesan, sizeof(Pesan),1,dtpesan)){
			if( id == Pesan.pilih_tipe){
				fclose(dtpesan);
				return 1;
			}
		}
	}else{
		c = 0;
		fclose(dtpesan);
		return 0;
	}
}

void hapus_pesanan (){
	system ("cls");
	int pil_hapus ; //deklarasi variabel pil_hapus bertipe data integer
	list_data_pemesan (); //memanggil fungsi list_data_pemesan
	printf ("\n\n"); //untuk enter jarak
	printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t|                       HAPUS PESANAN                     |\n");
    printf ("\t\t\t\t\t|=========================================================|\n");
    printf ("\t\t\t\t\t| TEKAN 1 untuk hapus pesanan di atas                     |\n");
    printf ("\t\t\t\t\t| TEKAN 2 untuk keluar                                    |\n");
    kembali_memilih :
    printf ("\t\t\t\t\t| Pilihan : ");
    scanf  ("%d", &pil_hapus);
    if (pil_hapus==1){ //jika memilih 1 akan mengarah pada fungsi hapus
    	hapus ();
	}
	else if (pil_hapus==2){ //jika memilih 2 akan mengarah pada fungsi menuadm
		menu_admin ();
	}
	else //jika salah memilih maka akan tampil error dengan memanggil fungsi error_alert dan kembali untuk memilih pilihan yang sesuai
		error_alert ();
		goto kembali_memilih ;
}

void hapus (){
	int pil_hapus ; //deklarasi pil_hapus pada fungsi hapus ke dalam variabel bertipe data int
	printf ("\t\t\t\t\t| Pilih ID pemesanan yang akan dihapus : ");
	scanf  ("%d",&pil_hapus); fflush(stdin);
	printf ("\t\t\t\t\t| Apakah anda yakin? (Y/T) : ");
	jawab = toupper(getche());			/* Baca jawaban dari keyboard */
	if (jawab == 'Y'|| jawab == 'y') 
	{	hapusdtpesan(Pesan, pil_hapus); //memanggil fungsi hapusdtpesan
		hapus_pesanan();
	}hapus_pesanan(); //kembali pada fungsi hapus_pesanan jika tidak memilih Y atau y
}

void hapusdtpesan (pesanKamar Pesan, int r){
	FILE *tmp; // Membuat pointer tmp untuk menunjuk pada file "Temp_Data.txt"
	int s;
	
		if (checkNomor(Pesan, r) == 0){ //memanggil fungsi checkNomor jika 0 maka akan menampilkan data pemesanan tidak ditemukan
			printf("\t\t\t\t\t Data pemesanan %d tidak ditemukan\n",r);
		}
		else{
			FILE*dtpesan ; // Membuat pointer dtpesan untuk menunjuk pada file "datapesan.txt"
			dtpesan = fopen("datapesan.txt","rb"); //membuka file "datapesan.txt" dengan rb
			tmp = fopen("Temp_Data.txt","wb");  //membuka file "Temp_Data.txt"
			while (fread(&Pesan, sizeof(Pesan), 1, dtpesan)){
				s = Pesan.pilih_tipe;
				if ( s != r){
					//Menyalin data file yang tidak ingin dihapus
					fwrite(&Pesan, sizeof(Pesan), 1, tmp);
				}
			}
			fclose(dtpesan);
			fclose(tmp);
			dtpesan = fopen("datapesan.txt","wb");
			tmp = fopen("Temp_Data.txt","rb");
			while(fread(&Pesan,sizeof(Pesan),1,tmp)){
				fwrite(&Pesan,sizeof(Pesan),1,dtpesan);
			}
			fclose(dtpesan);  //Menggunakan fungsi fclose untuk menutup file "datapesan.txt" agar tidak diproses lagi
			fclose(tmp);      //Menggunakan fungsi fclose untuk menutup file "tmp" agar tidak diproses lagi
		}
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

void hari (){
	switch (hari1){
		case 1 : printf ("SENIN"); break ;
		case 2 : printf ("SELASA"); break ;
		case 3 : printf ("RABU"); break ;
		case 4 : printf ("KAMIS"); break ;
		case 5 : printf ("JUMAT"); break ;
		case 6 : printf ("SABTU"); break ;
		case 7 : printf ("MINGGU"); break ;
	}
}

void kalenderuntukCO (){
	
	Pesan.tglCO = 0 ;
	Pesan.blnCO = 0 ;
	Pesan.thnCO = 0 ;
	//menggunakan do while 
	do {
		if (Pesan.lama_sewa <= 31) 
		{
			if (Pesan.blnCI == 2) 
				Pesan.tglCO = Februari (Pesan.thnCI);
			else 
				Pesan.tglCO = BknFeb (Pesan.thnCI,Pesan.blnCI);
				
			if (Pesan.tglCI + Pesan.lama_sewa > Pesan.tglCO) 
			{
				Pesan.blnCO = Pesan.blnCI + 1 ;
				
				/
				if (Pesan.blnCO>12){
					Pesan.thnCO=Pesan.thnCI+1;
					Pesan.blnCO=1;
				}
				else
				Pesan.thnCO = Pesan.thnCI ;
				Pesan.tglCO = Pesan.tglCI + Pesan.lama_sewa - Pesan.tglCO ;

			}
			else 
			{
				Pesan.tglCO= Pesan.tglCI+Pesan.lama_sewa;
				Pesan.blnCO=Pesan.blnCI;
				Pesan.thnCO=Pesan.thnCI;
			}
		
		}
		else 
		{
			if (Pesan.blnCI == 2) 
				Pesan.tglCO = Februari (Pesan.blnCI);
			else 
				Pesan.tglCO = BknFeb (Pesan.thnCI,Pesan.blnCI);
				Pesan.lama_sewa = Pesan.lama_sewa - Pesan.tglCO;
			if (Pesan.blnCI == 12)
			{
				Pesan.blnCI = 1 ; 
				Pesan.thnCI = Pesan.thnCI + 1 ;
			}
			else
				Pesan.blnCI = Pesan.blnCI + 1 ;
		}
	}
	while (Pesan.thnCO== 0); 
}

int BknFeb (int thn, int bln){
	thn = Pesan.thnCI;
	bln = Pesan.blnCI;
	
	if ((Pesan.blnCI==1) || (Pesan.blnCI==3) || (Pesan.blnCI==5) || (Pesan.blnCI==7) || (Pesan.blnCI==8) || (Pesan.blnCI==10) || (Pesan.blnCI==12)){
		return 31 ;
	}
	else { 
		return 30 ;
	}
}

int Februari (int thn){
	thn = Pesan.thnCI;
	if ((Pesan.thnCI % 100 != 0) && (Pesan.thnCI % 4 == 0)||(Pesan.thnCI % 400 == 0)){ 
		return 29 ; 
	}
	else {
		return 28 ;
	}		
}
