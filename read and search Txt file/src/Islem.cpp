/**
* @file.......: Islem.cpp
* @description: Islem sýnýfýnýn degiskenleri uzerinde islem yapýldýgý.methodlarýn govdelerinin yazýldýgý dosya
* @course.....: 2.Ogretim B grubu
* @assignment.: 03 Numaralý Odev
* @date.......: 24/11/2017
* @author.....: Aytekin Erlale/Oðuzhan Alipek --- aytekin.erlale@Ogr.Sakarya.edu.tr / oguzhan.alipek@Ogr.Sakarya.edu.tr
*/


#include "Islem.h"
#include "Liste.h"
#include<dirent.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

Islem::Islem()
{
}

//girilecek dizindeki dosyalara ulaþmak icin yapýlan tanýmlamalar
ifstream fin;
string dir;
int num;
DIR *dp;
struct dirent *dirp;

void Islem::YoluAl()
{
	cout << "Klasor..: ";
	cin >> dir;
}


bool Islem::hataKontrol()
{
	//eger dizin ismi hatalýysa hata no ilke birlikte bir yazi bastiracak ekrana ve fok false dönecek
	//eger dizin mevcutsa true dönecek ve iþlem devam edecektir
	if ((dp = opendir(dir.c_str())) == NULL) {
		cout << "Hata NO(" << errno << ")" << dir << endl;
		system("pause");

		return false;
	}
	return true;
}


void Islem::DosyalariBulEkle()
{
	//eger dizin isminde bir hata yoksa fonksiyon calisacak
	if (hataKontrol())
	{
		Liste * list = new Liste();
		//verilen dizindeki dosyalarý okuyoruz
		while (dirp = readdir(dp)) {
			
			fin.open(dirp->d_name);
			fin >> num;
			//burdaki for döngüsü oluþturduðumuz kontrol ile 
			//uzantýsý .txt olan dosyalarý iþleme girdirecek

			for (int i = 0; dirp->d_name[i] != '\0'; i++)
			{
				if (dirp->d_name[i] == '.' && dirp->d_name[i + 1] == 't' &&dirp->d_name[i + 2] == 'x' &&dirp->d_name[i + 3] == 't')
				{
					//burada baglý listeye agac ekleyecegiz
					string ara_deger = "";

					//ifstream nesnesiyle okuma islemini baslatiyoruz
					ifstream DosyayiOku;
					//istemilen klasördeki dosyayý açýyoruz
					DosyayiOku.open(dir + "\\" + dirp->d_name);
					//dosyadaki degerleri okuyoruz
					DosyayiOku >> ara_deger;
					//heap bölgesinde agac adýnda bir Agac nesnesi olusturuyoruz
					Agac * agac = new Agac(ara_deger);
					//dosyanýn sonuna gelene kadar okuma iþlemine devam ediyoruz
					while (!DosyayiOku.eof()) {

						DosyayiOku >> ara_deger;
						//dosyadan okuduðumuz her deðeri aðaca ekliyoruz
						agac->AgacaEkle(ara_deger);
					}
					//dosyada okunacak baþka deðer kalmayýnca dosyayý kapatýyoruz
					DosyayiOku.close();
					//dosyadan okuduðumuz deðerlerle oluþturduðumuz agacý dosya ismiyle beraber 
					//baðlý listedeki düðümlere ekliyoruz
					list->ListeyeEkle(agac, dirp->d_name);
				}
			}
		}
		closedir(dp);
	}
	//eger dizin isminde hata alýndýysa fonksiyon bitecek
	else
		return;
	
}









