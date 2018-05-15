/**
* @file.......: Liste.cpp
* @description: Liste sýnýfýnýn degiskenleri uzerinde islem yapýldýgý.methodlarýn govdelerinin yazýldýgý dosya
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale
*/


#include "Liste.h"
#include<iostream>

//liste sýnýfýnýn kurucu methodu 
Liste::Liste()
{
	//olusturulacak her nesnenin bir sonraki elemaný null olacak
	//Çunki listeye eleman eklerken en sona ekleme yapýyoruz
	next = NULL;
	
}
Liste::~Liste()
{
	next = NULL;
	dugumdeki_agac = NULL;
	dosya_adi = "";
}
//olustulan root adýndaki bu nesne
//her zaman bagli listenin ilk elemanýndan bir önceki 
//gorunmez bir ilk eleman gibi dusunulebilir
//bir baska deyisle root nesnesinin next i bagli listedeki
//ilk elemani gostermektedir
Liste * root = new Liste(); //root tanýmla diye bir fonksiyon yapýp dene !!!! 28/11/2017

//listeye eleman ekleniyor 
//projenin bu kýsmýnda tek yonlu baglý liste turunu kullandýk
//cunku dizinden okudugumuz verilerle olusan agaclarý
//sona ekleme teknigi ile bagli listenin sonuna ekleyecegimiz icin
//fazla alan kaplamamak icin (binlerce txt dosyasý olabilir)
void Liste::ListeyeEkle(Agac * a1, std::string dosya_adi)
{
	//heap de eklenecek adýnda bir nesne olusturuyoruz
	Liste * eklenecek = new Liste();

	//baglý listenin bos olma durumu 
	if (root->next == NULL)
	{
		//liste bostur.
		//eklenecek eleman hem basa hem sona eklenmis olur

		//rootun nexti eklenen elemaný gosteriyor
		root->next = eklenecek;
		//parametre olarak gelen dosya adý eklenecek dugumun dosya adý oluyor
		eklenecek->dosya_adi = dosya_adi;
		//parametre olarak gelen agac dugumdeki?agac degiskenine atanýyor
		eklenecek->dugumdeki_agac = a1;
		//eknlenecek elemanýn nexti NULL degerini gosterecek
		eklenecek->next = NULL;
		return;
	}

	//root un bir copyasýný alacak gecici bir deger olusuyor
	Liste * temp = new Liste();
	temp = root;

	//son dugume ulasana kadar temp dugumu kendisinin nextine atanýyor
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	//yine ayný islemler gerceklesiyor
	temp->next = eklenecek;
	eklenecek->next = NULL;
	eklenecek->dosya_adi = dosya_adi;
	eklenecek->dugumdeki_agac = a1;
	
}

void Liste::DugumleriSil()
{
	
	while (root->next != NULL)
	{
		Liste * temp = root;
			
	while (temp->next->next != NULL)
		temp = temp->next;

		Liste * silinecek;
		silinecek = temp->next;
		temp->next = NULL;
		temp->next->dosya_adi = "";
		temp->next->dugumdeki_agac->sil(temp->next->dugumdeki_agac);
		delete silinecek;

	}
	
	
}

Liste * li = root;

void Liste::dolas()
{
		li = li->next;
		std::cout << "\n\n" << li->dosya_adi << ":\n\n";
		dugumdeki_agac->dolas(li->dugumdeki_agac);

		if (li->next != NULL)
			return dolas();

		std::cout << "\n\n";
		li = root;
	
}

Liste * lis = root;
int sayac = 0;
void Liste::Bul(std::string aranan)
{
	
	while (lis->next != NULL)
	{
		lis = lis->next;
		if (dugumdeki_agac->Varmi(lis->dugumdeki_agac, aranan))
		{		
			sayac = 1;
			std::cout << "aranan kelime " << lis->dosya_adi << " icerisinde.\n\n";
		}
		else {
			if (lis->next != NULL)
			{
				return Bul(aranan);
			}
			else if(lis->next == NULL && sayac == 0)
				std::cout<<"aranan kelime bu dizinde bulunamadi\n\n";
		}
	}
	lis = root;
	sayac = 0;


}
