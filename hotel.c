#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int home();
int awal();
int login();
int loginAll();
int daftarKamar();
int daftraKamarTamu();
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


int main (){
	awal();
	system("pause");
	return 0;
}

//AWAL
int awal(){
int menu;
printf("================================================\n");
 printf(" Selamat Datang \n");
 printf(" Entity's Hotel \n");
 printf("================================================\n\n");
 printf("1. Masuk\n");
 printf("2. Tentang\n");
 printf("3. Keluar\n");
 printf("Masukkan nomor menu yang anda inginkan : ");
 scanf_s("%d", &menu);
 system("cls");


switch (menu){
 case 1:
 loginAll(); // jika user memasukkan 1, makan menjalankan fungsi loginAll()
 break;
 case 2:
 tentangProgram(); // jika user memasukkan 2, makan menjalankan fungsi tentangTamu()
 break;
 case 3:
 keluar(); // jika user memasukkan 3, makan menjalankan fungsi keluar()
 break; 
 default:
 printf("Nomor menu yang anda masukkan tidak ada\n");
 }
 return 0;
}

//loginAll
int loginAll(){
	int menu;
 printf("================================================\n");
 printf(" Selamat Datang \n");
 printf(" Entity's Hotel \n");
 printf("================================================\n\n");
 printf("Login sebagai : \n");
 printf("1. Admin\n");
 printf("2. Tamu\n");
 printf("3. Halaman Depan\n");
 printf("Masukkan menu pilihan anda : ");
 scanf_s("%d", &menu);
 system("cls");

 switch (menu){
 case 1:
 login();
 break;
 default:
 printf("Nomor menu yang anda masukkan tidak ada\n");
 break;
 }
 return 0;
}

//login
int login(){
 printf("================================================\n");
 printf(" Selamat Datang \n");
 printf(" Entity's Hotel \n");
 printf("================================================\n\n");

 printf("Masukkan Username : ");
 scanf_s("%s", &id_admin);
 printf("Masukkan Password : ");
 scanf_s("%s", &pass_admin);

 if (strcmp(id_admin,"admin1")==0 && strcmp(pass_admin,"admin")==0){
 	strcpy(nama_admin,"widi");
 	strcpy(kode_admin,"1");
 	printf("login berhasil\n");
 }else if (strcmp(id_admin,"admin2")==0 && strcmp(pass_admin,"admin")==0){
 	strcpy(nama_admin,"bayu");
 	strcpy(kode_admin,"2");
 	printf("login berhasil\n");
 }else{
 	printf("salah");
 }
 return 0;
}

//tentang program
int tentangProgram(){
 int menu;

 printf("================================================\n");
 printf(" Tentang \n");
 printf("================================================\n\n");
 printf(" Aplikasi Reservasi Kamar Hotel \n\n");
 printf(" Dibuat Oleh : \n");
 printf(" Widi dan Bayu \n");
 printf(" 2105551015 dan 2105551018 \n");
 printf(" TI Udayana \n");
}
//kode program untuk keluar
int keluar(){
 printf("================================================\n");
 printf(" Terima Kasih \n");
 printf(" Sampai Jumpa \n");
 printf("================================================\n");

 return 0;
}
