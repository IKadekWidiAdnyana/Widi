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
    char username[12];
    char password[10];
    char email[50];
}User;

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
const float regencyS = 5500000;
const float executiveS = 2500000;
const float presidentialS = 10500000;


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
	printf  ("\t\t\t\t\t                Tekan ENTER  untuk melanjutkan....       \n");
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
    	default:
        	error_alert();
        	goto pilih;
        break;
	}
    
}
