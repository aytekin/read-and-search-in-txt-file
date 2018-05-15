/**
* @file.......: Agac.h
* @description: Agac sýnýfýnýn tanýmlandýgý dosya
* @course.....: 2.Ogretim B grubu
* @assignment.: 03 Numaralý Odev
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale/Oðuzhan Alipek --- aytekin.erlale@Ogr.Sakarya.edu.tr / oguzhan.alipek@Ogr.Sakarya.edu.tr
*/



#pragma once
#include<string>

class Agac
{
public:
	std::string kelime;
	Agac * sol;
	Agac * sag;

	Agac(std::string kelime);
	void AgacaEkle(std::string kelime);
	void dolas(Agac * agac);
	bool Varmi(Agac * agac, std::string aranan);
	void sil(Agac * agac);
};

