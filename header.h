/*Saya Misdan Wijaya (1305262) dengan ini bersumpah demi tuhan
bahwa mengerjakan TP 2 ini tanpa melakukan kecurangan,
seperti mencatat atau melihat kode sejenis milik teman dan atau 
segala bentuk kecurangan seperti yang telah disepakati bersama*/

//list dinamis

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char nama[100];
	int jumlah;
}orang;

typedef struct elmt *alamatelmt;

typedef struct elmt{
	orang elmt;
	alamatelmt next;
}elemen;

typedef struct {
	elemen *first;
}list;

int banyak;
void delSearch(char cari[], list *L);
void selectionSort (list *L);
void hitung(list *L);
