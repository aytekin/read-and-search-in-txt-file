/**
* @file.......: LÝste.h
* @description: Liste sýnýfýnýn tanýmlandýgý h dosyasý
* @course.....: 2.Ogretim B grubu
* @assignment.: 03 Numaralý Odev
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale/Oðuzhan Alipek --- aytekin.erlale@Ogr.Sakarya.edu.tr / oguzhan.alipek@Ogr.Sakarya.edu.tr
*/

#pragma once
#include<string>
#include"Agac.h"
class Liste
{
public:
	Liste();
	~Liste();
	std::string dosya_adi;
	Agac * dugumdeki_agac;
	Liste * next;
	void ListeyeEkle(Agac * a1, std::string dosya_adi);
	void dolas();
	void Bul(std::string aranan);
	void DugumleriSil();
};

