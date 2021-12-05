#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int awal();
int login();
int loginAll();
int ListKamar();
int daftarKamarTamu();
int pemesananKamar();
int keluar();
int tentang();
int tentangProgram();
int halamanTamu();
int menu;

//variabel admin
char id_admin[20];
char pass_admin[20];
char nama_admin[20];
char kode_admin[20];

int header();

int main (){
	awal();
	system("pause");
	return 0;
}

nt header (){
	printf("\t==========================================================\n");
 	printf(" \t\t\t>>>>>Selamat Datang<<<<< \n");
 	printf(" \t\t\t>>>>>Entity's Hotel<<<<< \n");
 	printf("\t==========================================================\n");
}

//AWAL
int awal(){
	int menu;
	
 	printf("\t1. Masuk\n");
 	printf("\t2. Tentang Program\n");
 	printf("\t3. Keluar\n");
 	printf("\tMasukkan nomor menu yang anda inginkan : ");
 	scanf_s("%d", &menu);


switch (menu){
	case 1:
 		loginAll(); // jika user memasukkan 1, makan menjalankan fungsi loginAll()
 		break;
 	case 2:
 		tentangProgram(); // jika user memasukkan 2, makan menjalankan fungsi tentangProgram()
 		break;
 	case 3:
 		keluar(); // jika user memasukkan 3, makan menjalankan fungsi keluar()
 		break; 
 	default:
 	printf("Maaf Nomor menu yang anda masukkan \n");
 }
 return 0;
}

//Menu LogIn Utama
int loginAll(){
	int menu;
 printf("\tLogin sebagai : \n");
 printf("\t1. Admin\n");
 printf("\t2. Tamu\n");
 printf("\t3. Halaman Depan\n");
 printf("\tMasukkan menu pilihan anda : ");
 scanf_s("%d", &menu);
 system("cls");

 switch (menu){
 case 1:
 login();
 break;
 case 2:
 halamanTamu();
 break;
 case 3:
 awal();
 break;
 default:
 printf("Nomor menu yang anda masukkan tidak ada\n");
 break;
 }
 return 0;
}

//login Sebagai Admin
int login(){
 	printf("\t==========================================================\n");
 	printf(" \t\t\t>>>>>Selamat Datang<<<<< \n");
 	printf(" \t\t\t>>>>>Entity's Hotel<<<<< \n");
 	printf("\t==========================================================\n");
 	
 	login:
 printf("\tMasukkan Username : ");
 scanf_s("%s", &id_admin);
 printf("\tMasukkan Password : ");
 scanf_s("%s", &pass_admin);

 if (strcmp(id_admin,"widi")==0 && strcmp(pass_admin,"2105551015")==0){
 	printf("\tlogin berhasil\n");
 }else if (strcmp(id_admin,"bayu")==0 && strcmp(pass_admin,"2105551018")==0){
 	printf("\tlogin berhasil\n");
 }else{
 	printf("\tMohon Maaf Username atau Password yang Anda Masukkan Salah!\n \tSilahkan Coba Lagi\n");
 	goto login;
 }
}

//tentang program
int tentangProgram(){
 int menu;
 printf("\t==========================================================\n");
 printf(" \t\t\t>>>>>Tentang Program<<<<< \n");
 printf("\t==========================================================\n");
 printf(" \t\t\tAplikasi Reservasi Kamar Hotel \n\n");
 printf(" Dibuat Oleh : \n");
 printf(" Widi dan Bayu \n");
 printf(" 2105551015 dan 2105551018 \n");
 printf(" TI Udayana \n");
}

//Halaman Tamu
int halamanTamu(){
	int menu;
	printf("\t==========================================================\n");
 	printf(" \t\t\t>>>>>Selamat Datang<<<<< \n");
 	printf(" \t\t\t>>>>>Entity's Hotel<<<<< \n");
 	printf("\t==========================================================\n");
	
}

//kode program untuk keluar
int keluar(){
 printf("\t==========================================================\n");
 printf(" \t\t>>>>>Terima Kasih Telah Menginap<<<<< \n");
 printf(" \t\t\t>>>>>Sampai Jumpa<<<<< \n");
 printf("\t==========================================================\n");

 return 0;
}
