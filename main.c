#include "header.h"

int main(){
	//deklarasi
	list L;
	createList (&L);
	orang isi;
	int i;
	
	//banyak anggota senior
	scanf("%d",&banyak);
	
	for(i=0;i<banyak;i++){
		scanf("%s %d",&isi.nama,&isi.jumlah);
		addLast(isi.nama,isi.jumlah,&L);	
	}
	
	//hitung bonus untuk senior
	hitung(&L);
	
	//banyak anggota junior
	scanf("%d",&banyak);
	
	for(i=0;i<banyak;i++){
		scanf("%s %d",&isi.nama,&isi.jumlah);
		addLast(isi.nama,isi.jumlah,&L);
	}
	
	//hapus yang dipilih
	scanf("%d", &banyak);
	
	//input data yang akan dihapus
	for(i=0; i<banyak; i++){
		scanf("%s", &isi.nama);
		delSearch(isi.nama, &L);
	}
	
	//sorting
	selectionSort(&L);
	//printf("=====\n");
	//print hasil
	printElement(L);
	
	return 0;
}
