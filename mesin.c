#include "header.h"

//create list
void createList (list *L){
	(*L).first = NULL;
}

//menghitung elemen
int countElement(list L){
	int hasil = 0;

	if (L.first != NULL){
		elemen *elmt;

		elmt = L.first;

		while (elmt != NULL){
			hasil = hasil + 1;

			elmt = elmt->next;
		}

	}
	return hasil;
}

//addfirst
void addFirst(char nama[],int jumlah,list *L){

	elemen  *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	//strcpy(baru->elmt.kode,kode);
	strcpy(baru->elmt.nama,nama);
	baru->elmt.jumlah = jumlah;
	
	//(*L).elmt.kontainer.jumlah=jumlah;
	//strcpy(baru->elmt.nilai,nilai);

	if((*L).first == NULL){
		baru->next = NULL;
	}else{
		baru->next = (*L).first;
	}
	(*L).first = baru;
	baru = NULL;
}

//add after
void addAfter(elemen *prev,char nama[],int jumlah,list *L){

	elemen *baru;
	baru = (elemen*) malloc (sizeof(elemen));
	//strcpy(baru->elmt.kode,kode);
	strcpy(baru->elmt.nama,nama);
	baru->elmt.jumlah = jumlah;
	//strcpy(baru->elmt.nilai,nilai);

	if (prev->next == NULL){
		baru->next =NULL;
	}else{
		baru->next=prev->next;
	}
	prev->next = baru;
	baru = NULL;
}

//add Last
void addLast(char nama[],int jumlah,list *L){

	if ((*L).first == NULL){
		addFirst(nama,jumlah,L);
	}else{
		elemen *prev = (*L).first;
		while(prev->next != NULL){
			prev = prev->next;
		}
		addAfter(prev,nama,jumlah,L);
	}
}

//delete first
void delFirst(list *L){
	if((*L).first != NULL){
		elemen *hapus = (*L).first;
		if(countElement (*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

//delete after
void delAfter(elemen *prev, list *L){
	elemen *hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL){
			prev->next=NULL;
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

//delete Last
void delLast(list *L){
	if ((*L).first != NULL){
		if(countElement(*L) == 1){
			delFirst(L);
		}else{
			elemen *last = (*L).first;
			elemen *prev;

			while (last->next != NULL){
				prev = last;
				last = last->next;
			}
		delAfter(prev,L);
		}
	}
}

//print elemen
void printElement(list L){
	if (L.first != NULL){
		elemen *elmt = L.first;
		int i = 1;

		while (elmt != NULL){
			//printf("Elemen ke  : %d\n",i);
			//printf("%s ",elmt->elmt.kode);
			printf("%s ",elmt->elmt.nama);
			printf("%d\n",elmt->elmt.jumlah);
			//printf("-----------------------\n");
			elmt = elmt->next;
			i = i + 1;
		}
	}else{
			printf("List Kosong\n");
	}
}

void delAll(list *L){
	int i;
	for(i = countElement (*L);i>=1;i--){
		delLast(L);
	}
}

//proses pengurutan
void selectionSort (list *L){
	int i,j;
	elemen *akhir, *awal, *s_akhir,*s_awal, *temp_akhir, *temp_awal, *indeks_sebelum;
	awal=(*L).first; //pointer data awal
	s_awal=NULL; //pointer sebelum data awal
	while (awal!=NULL){
		temp_awal=awal;
		temp_akhir=awal;
		akhir=awal->next; //pointer data yang dibandingin
		indeks_sebelum=temp_awal;
		s_akhir=indeks_sebelum;
		while (akhir!=NULL){
			if(akhir->elmt.jumlah > temp_akhir->elmt.jumlah){
				temp_akhir=akhir; //pointer data yang ingin ditukar
				s_akhir=indeks_sebelum;
			}
			indeks_sebelum=akhir;
			akhir=akhir->next; //increment			
		}
		awal = awal -> next; //increment
		
		
		
		//jika indeks beda maka pointer ada yang ditukar
		if(temp_akhir!=temp_awal){
			//jika data yang ingin ditukar bersebelahan
			if(temp_awal->next==temp_akhir){	
				if(temp_awal!=(*L).first)	s_awal->next=temp_awal->next;
				else (*L).first=temp_akhir;
				s_akhir->next=temp_akhir->next;
				temp_akhir->next=temp_awal;
				s_awal=temp_akhir;
				awal=temp_awal;
			}else{ //jika data yang ingin ditukar tidak bersebelahan
				if(temp_awal==(*L).first){ //jika data diawal
					s_akhir->next=temp_akhir->next;
					temp_akhir->next=temp_awal->next;
					temp_awal->next=s_akhir->next;
					s_akhir->next=temp_awal;
					temp_awal=temp_akhir; //supaya perulangan diulang dari data yang ditukar
					s_awal=temp_awal;
					(*L).first=temp_akhir;
				}else{
					s_awal->next=temp_awal->next;
					s_akhir->next=temp_akhir->next;
					temp_akhir->next=s_awal->next;
					temp_awal->next=s_akhir->next;
					s_awal->next=temp_akhir;
					s_akhir->next=temp_awal;
					temp_awal=temp_akhir; //supaya perulangan diulang dari data yang ditukar
					s_awal=temp_awal;
				}
			}
		}else s_awal=temp_awal; //increment	
	}
}

//proses hapus yang dicari
void delSearch(char cari[], list *L){
 
    if ((*L).first != NULL){
        elemen *elmt = (*L).first;
		elemen *prev=NULL; //pointer data sebelum
 
        while (elmt != NULL){
            if(strcmp(elmt->elmt.nama,cari)==0){
				elmt = elmt->next;
				if (prev==NULL) delFirst(L);
				else delAfter(prev,L); //hapus data yang dicari
			}else{
				prev=elmt;
				elmt = elmt->next;
			}
        }
    }
}

//proses hitung bonus untuk senior
void hitung(list *L){
	
	if ((*L).first != NULL){
        elemen *elmt = (*L).first;
        while (elmt != NULL){
		
			//jika lebih dari 300000
			if (elmt->elmt.jumlah>=300000){
				int temp;
				temp=elmt->elmt.jumlah*20/100;
				elmt->elmt.jumlah = elmt->elmt.jumlah + temp;
			}
			//jika lebih dari 200000
			else if (elmt->elmt.jumlah>= 200000){
				int temp;
				temp=elmt->elmt.jumlah*15/100;
				elmt->elmt.jumlah = elmt->elmt.jumlah + temp;
			}
			//jika lebih dari 100000
			else if (elmt->elmt.jumlah>= 100000){
				int temp;
				temp=elmt->elmt.jumlah*10/100;
				elmt->elmt.jumlah = elmt->elmt.jumlah + temp;
			}
 
            elmt = elmt->next;
        }
    }
}
