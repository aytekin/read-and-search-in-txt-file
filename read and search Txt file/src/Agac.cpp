/**
* @file.......: Agac.cpp
* @description: Agac sýnýfýnýn degiskenleri uzerinde islem yapýldýgý.methodlarýn govdelerinin yazýldýgý dosya
* @course.....: 2.Ogretim B grubu
* @assignment.: 03 Numaralý Odev
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale/Oðuzhan Alipek --- aytekin.erlale@Ogr.Sakarya.edu.tr / oguzhan.alipek@Ogr.Sakarya.edu.tr
*/

#include "Agac.h"
#include<iostream>
#include "Liste.h"
Agac::Agac(std::string kelime)
{
	sol = sag = NULL;
	this->kelime = kelime;
}

void Agac::AgacaEkle(std::string Item)
{

	if (kelime.compare(Item) > 0) {
		if (sol)
			return sol->AgacaEkle(Item);

		Agac * yeni = new Agac(Item);
		sol = yeni;
		
	}
	if (kelime.compare(Item) < 0) {
		//saga ekleme
		if (sag)
			return sag->AgacaEkle(Item);

		Agac * yeni = new Agac(Item);
		sag = yeni;
		
	}
}



//bagli listedeki root->next inden baslayýp her düðümdeki agacý buraya vermeliyiz
//her düðümdeki dosya ismide gelmeli
void Agac::dolas(Agac * agac)
{

	// dolaþacak deðer kalmadýðýnda geriye dönüyoruz
	if (agac == NULL)
	{
		return;
	}
	// önce sol alt aðacýmýza uðruyoruz
	 dolas(agac->sol);
	// sol alt aðaçtaki yaprak düðümümüzü yazdýrýyoruz
	std::cout << agac->kelime << " ";
	// sonra sað alt aðaca geçiyoruz
	 dolas(agac->sag);
}

bool Agac::Varmi(Agac * agac,std::string aranan)
{
	//aranan kelime agactaki kelimeye eþitse 
	if (agac->kelime == aranan)
	{
		return true;
	}	
	//aranan kelimenin alfabetik sýrada agactaki kelimeden önce gelme durumu
	else if (agac->kelime.compare(aranan) > 0)
	{
		if (agac->sol != NULL) {
			return Varmi(agac->sol, aranan);
		}		
			return false;
	}
	//aranan kelimenin alfabetik sýrada agactaki kelimeden sonra gelme durumu
	else {
		if (agac->sag != NULL) {
			return Varmi(agac->sag, aranan);
		}
			return false;

	}
}

void Agac::sil(Agac * agac)
{
	delete agac;
	agac->kelime = "";
	agac->sag = NULL;
	agac->sol = NULL;
	
}



