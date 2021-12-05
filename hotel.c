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
int header();
int menu;

//variabel admin
char id_admin[20];
char pass_admin[20];
char nama_admin[20];
char kode_admin[20];

int main (){
	awal();
	system("pause");
	return 0;
}

int header (){
	printf("\t==========================================================\n");
 	printf(" \t\t\t >>>>>Selamat Datang<<<<< \n");
 	printf(" \t\t\t >>>>>Entity's Hotel<<<<< \n");
 	printf("\t==========================================================\n");
}

//AWAL
int awal(){
	int menu;
	header();
 	printf("\t 1. Masuk \n");
 	printf("\t 2. Tentang Program \n");
 	printf("\t 3. Keluar \n");
 	printf("\t Masukkan nomor menu yang anda inginkan : ");
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
 	printf("Maaf, nomor menu yang anda masukkan salah! \n");
 }
 return 0;
}

//Menu LogIn Utama
int loginAll(){
	int menu;
	header();
 printf("\t Login sebagai : \n");
 printf("\t 1. Admin \n");
 printf("\t 2. Tamu \n");
 printf("\t 3. Halaman Depan \n");
 printf("\t Masukkan menu pilihan anda : ");
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
 printf("Maaf, nomor menu yang anda masukkan tidak ada! \n");
 break;
 }
 return 0;
}

//login Sebagai Admin
int login(){
 	header();
 	login:
 printf("\t Masukkan Username : ");
 scanf_s("%s", &id_admin);
 printf("\t Masukkan Password : ");
 scanf_s("%s", &pass_admin);

 if (strcmp(id_admin,"widi")==0 && strcmp(pass_admin,"2105551015")==0){
 	printf("\t Login berhasil! \n");
 }else if (strcmp(id_admin,"bayu")==0 && strcmp(pass_admin,"2105551018")==0){
 	printf("\t Login berhasil! \n");
 }else{
 	printf("\t Mohon Maaf Username atau Password Yang Anda Masukkan Salah! \n \t Silahkan Coba Lagi! \n");
 	goto login;
 }
}

//tentang program
int tentangProgram(){
 int menu;
 printf("\t==========================================================\n");
 printf(" \t\t\t >>>>>Tentang Program<<<<< \n");
 printf("\t==========================================================\n");
 printf(" \t\t\t Aplikasi Reservasi Kamar Hotel \n\n");
 printf("Dibuat Oleh : \n");
 printf("Widi dan Bayu \n");
 printf("2105551015 dan 2105551018 \n");
 printf("TI Udayana \n");
}

//Halaman Tamu
int halamanTamu(){
	int menu;
	header();
	
}

//kode program untuk keluar
int keluar(){
 printf("\t==========================================================\n");
 printf(" \t\t >>>>>Terima Kasih Telah Menginap<<<<< \n");
 printf(" \t\t\t >>>>>Sampai Jumpa<<<<< \n");
 printf("\t==========================================================\n");

 return 0;
}
