#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

/*
	Iyi Gunler Hocam. Bu aciklama satirlari yazmamain nedeni odevi hem yetistiremeem hem de yazdigim
	fonksiyonlar (Sekil Guncelleme vs.) sikinti cikarmasinda dolayi odev yarida kaldi. Ayrica ko satiri
	epey uzun oldugu icinde aciklama satirlari yerlestirdim. Suan bu aciklama satirlarini 15 Kasim 21
	civarlarinda yaziyorum. Bilgilendirmek icin ekledim.
	Not1: Az önce Putpixel ile bir þeyler denedim ama çizdirmeye çalýþtýgým yer iki de bir cokuyor.Ondan
	txt dosyasýnda islemler tutulacak.
*/


//Cizim Tur ve Sayisi Tutualrak Her Cizim Icin Ozel Struct Yapisi Tutulur. Bu sayede guncelleme ve silme
//gibi islemlerde bulmasini kolaylastirir 
typedef struct CizimTuru{
	int CizdirilenTur;
	int CizimSayisi;
	struct CizimTuru *sonraki;
}Cizim;

	Cizim *ilkCizim = NULL, *sonCizim = NULL, *yeniCizim, *silGeciciCizim, *geciciCizim;
	int CizdirilenTur=0,CizimSayisi=0;
	int GuncellemeCizdirilenTur=0,GuncellemeCizimSayisi=0;
	bool Cizdirilebilirlik=true;

//Polinomun Derece ve Katsayi degerlerini tutar. Mesela: y=3*X^3-6*X^2 fonksiyonunda 3,3 ve 2,-6 deger
//lerini icinde tutar.
typedef struct DereceKat{
	int DereceKatSayisi;
	float KatSayi;
	int Derece;
	bool KordinatDuzlemi;
	struct DereceKat *sonraki;
}derecekat;

	derecekat *ilkDereceKat = NULL, *sonDereceKat = NULL, *yeniDereceKat, *silGeciciDereceKat, 
	*geciciDereceKat;
	int Derece=0,DereceKatSayisi=0;
	float KatSayi=0;
	bool KordinatDuzlemi=false;
	
//Ýstedigi Egri ve Cizgi Cizdirmek icin Polinom Fonksiyonundan fonksiyon yazmasi gerekmektedir
//Normalde Secim degeri ile bunu ayiracaktim ama zaman yetismedi.
typedef struct Polinom{
	int CizimSayisiPolinom;
	int BaslangicKordinatX[2];
	int BaslangicKordinatY[2];
	int Secim[4];
	struct Polinom *sonraki;
}polinom;

	polinom *ilkPolinom = NULL, *sonPolinom = NULL, *yeniPolinom, *silGeciciPolinom, *geciciPolinom;
	int CizimSayisiPolinom=0,BaslangicKordinatX[2],BaslangicKordinatY[2],Secim[4];

//Disk Degerlerinin tutuldugu sturct yapisi
typedef struct Disk{
	int CizimSayisiDisk;
	int EliptikYariCaplar[2];
	int DiskKatSayiX;
	int DiskKatSayiY;
	int CapMerkezKordinatX;
	int CapMerkezKordinatY;
	struct Disk *sonraki;
}disk;

	disk *ilkDisk = NULL, *sonDisk = NULL, *yeniDisk, *silGeciciDisk, *geciciDisk;
	int CizimSayisiDisk=0,EliptikYariCaplar[2],CapMerkezKordinatX=0,CapMerkezKordinatY=0,
	DiskKatSayiX=0,DiskKatSayiY=0;

//Ucgen Degerlerinin tutuldugu struct yapisi
typedef struct Ucgen{
	int CizimSayisiUcgen;
	int KoseKordinatX[3];
	int KoseKordinatY[3];
	int fonkA[3];
	int fonkB[3];
	bool DolulukUcgen;
	struct Ucgen *sonraki;
}ucgen;

	ucgen *ilkUcgen = NULL, *sonUcgen = NULL, *yeniUcgen, *silGeciciUcgen, *geciciUcgen;
	int CizimSayisiUcgen=0,KoseKordinatY[3],KoseKordinatX[3],fonkA[3],fonkB[3];
	bool DolulukUcgen=false;
	
//Dikdortgen ve Kare Degerlerinin tutuldugu struct yapisi
//kenar uzunluklari esitse kare degilse Dikdortgen cizdirir
typedef struct Dortgen{
	int CizimSayisiDortgen;
	int BaslangicKordinatX;
	int BaslangicKordinatY;
	int KenarUzunluklari[2];
	bool DolulukDortgen;
	struct Dortgen *sonraki;
}dortgen;

	dortgen *ilkDortgen = NULL, *sonDortgen = NULL, *yeniDortgen, *silGeciciDortgen, *geciciDortgen;
	int CizimSayisiDortgen=0,BaslangicKordinatDortgenX=0,BaslangicKordinatDortgenY=0,
	KenarUzunluklari[2];
	bool DolulukDortgen=false;

//Eliptik ve Daire Degerlerinin tutuldugu struct yapisi
//Katsayiler esitse daire degilse eliptik cizdirir
// a*(y-y1)^2+b*(x-x1)^2 = r^2 fonksiyonu ele alinmistir.
typedef struct Eliptik{
	int CizimSayisiEliptik;
	int KatSayiX;
	int KatSayiY;
	int CapMerkezKordinatX;
	int CapMerkezKordinatY;
	int EliptikYariCap;
	bool DolulukEliptik;
	struct Eliptik *sonraki;
}eliptik;

	eliptik *ilkEliptik = NULL, *sonEliptik= NULL, *yeniEliptik, *silGeciciEliptik, *geciciEliptik;
	int CizimSayisiEliptik=0,KatSayiX=0,KatSayiY=0,CapMerkezKordinatEliptikX=0,
	CapMerkezKordinatEliptikY=0,EliptikYariCap=0;
	bool DolulukEliptik=false;
	
//Not1: ZamanYeterse Bunlara da Aynisi Uygulanacak.
//Not2: Zaman Yetmedi...	
typedef struct Poligon{
	
}poligon;

typedef struct Yildiz{
	
}yildiz;


char harita[399][399];
//Alttaki Tanimlamalar hareketMenusunde kullanilacaktir.
bool kontrol[7]={false,false,false,false,false,false,false};
int otelemeX=0,otelemeY=0;
int dondurmeX=0,dondurmeY=0;
char karakterDegerleri[4]={' ','#','N','*'};
int karakterDizisi[4]={0,1,2,3};
float olceklendirme=1;

FILE *dosyaKontrol;

void CizimEkle();
void CizimSil();
void CizimAra();

void DereceKatEkle();
void DereceKatSil();
void DereceKatAra();

void PolinomEkle();
void PolinomSil();
void PolinomAra();

void DiskEkle();
void DiskSil();
void DiskAra();

void UcgenEkle();
void UcgenSil();
void UcgenAra();

void DortgenEkle();
void DortgenSil();
void DortgenAra();

void EliptikEkle();
void EliptikSil();
void EliptikAra();

void PoligonEkle();
void PoligonSil();
void PoligonAra();

void YildizEkle();
void YildizSil();
void YildizAra();


void Menu();
void SekilEkleMenu();
void SekilSilMenu();
void SekilGuncellemeMenu();
void KarakterDizisiGuncelleme();
void SekilAraMenu();
void HareketMenu();
void EkranTemizle();
void HaritaCizdir();
void IlkHaritaCizdir();
void EkranZoom();
void SekilSilme();
void Kirpma();


void PolinomCizdir();
void DiskCizdir();
void UcgenCizdir();
void DortgenCizdir();
void EliptikCizdir();
void PoligonCizdir();
void YildizCizdir();


void Oteleme();
void Dondurme();
void Olceklendirme();
void BirlesikDonusumler();
void Yansima();
void Meyillendirme();

int main(){
	IlkHaritaCizdir();
	HaritaCizdir();	
	Menu();
	return 0;
}

//Harita Icýný Bosaltmak icin Yapilmistir
void IlkHaritaCizdir(){
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			harita[i+199][j+199]=' ';
			fprintf(dosyaKontrol,"%c%c",harita[i+199][j+199],harita[i+199][j+199]);
		}
		fprintf(dosyaKontrol,"\n");
	}
	fclose(dosyaKontrol);
}

//Harita Sonrasi Yapilan Degisikligi Txt Dosyasina Kaydeder.
void HaritaCizdir(){
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			if(harita[i+199][j+199] == ' '){
				if(i==0 || j==0){
					harita[i+199][j+199]='$';
				}else{
					harita[i+199][j+199]='*';	
				}	
			}
			fprintf(dosyaKontrol,"%c%c",harita[i+199][j+199],harita[i+199][j+199]);
		}
		fprintf(dosyaKontrol,"\n");
	}
	fclose(dosyaKontrol);
}

//Yapilan Cizime Erisebilmek icin Cizim Structýnda Kaydedilir
void CizimEkle(){
	yeniCizim = (Cizim *)malloc(sizeof(Cizim));
	yeniCizim->CizdirilenTur = CizdirilenTur;
	yeniCizim->CizimSayisi = CizimSayisi;
	yeniCizim->sonraki = NULL;
	
	if(ilkCizim==NULL){
		ilkCizim = yeniCizim;
		sonCizim = ilkCizim;
	}else{
		sonCizim->sonraki = yeniCizim;
		sonCizim = sonCizim->sonraki;
	}
	switch(CizdirilenTur){
		case 1:{
			CizimSayisiPolinom = CizimSayisi;
			DereceKatSayisi = CizimSayisi;
			PolinomEkle();
			PolinomCizdir();
			break;
		}
		case 2:{
			CizimSayisiDisk = CizimSayisi;
			DiskEkle();
			DiskCizdir();
			break;
		}
		case 3:{
			CizimSayisiUcgen = CizimSayisi;
			UcgenEkle();
			UcgenCizdir();
			break;
		}
		case 4:{
			CizimSayisiDortgen = CizimSayisi;
			DortgenEkle();
			DortgenCizdir();
			break;
		}
		case 5:{
			CizimSayisiEliptik = CizimSayisi;
			EliptikEkle();
			EliptikCizdir();
			break;
		}
		case 6:{
			//CizimSayisiPoligon = CizimSayisi;
			PoligonCizdir();
			break;
		}
		case 7:{
			//CizimSayisiYildiz = CizimSayisi;
			YildizCizdir();
			break;
		}
	}
	
}

//Uzerinde Guncelleme Yapilacak veya Silinecek Seklin Ilk Halini Silmek Icýn Kullanilacaktir.
void CizimSil(){
		int kontrol = 0;
    if (ilkCizim->CizdirilenTur == CizdirilenTur && ilkCizim->CizimSayisi == CizimSayisi) {
        silGeciciCizim = ilkCizim;
        ilkCizim = ilkCizim->sonraki;
        free(silGeciciCizim);
        kontrol = 1;
    } else {
        geciciCizim = ilkCizim;
        while (geciciCizim->sonraki != NULL) {
            if (geciciCizim->sonraki->CizdirilenTur == CizdirilenTur 
			 && geciciCizim->sonraki->CizimSayisi == CizimSayisi) {
                kontrol = 1;
                silGeciciCizim = geciciCizim->sonraki;
                if (silGeciciCizim == sonCizim)
                    sonCizim = geciciCizim;
                geciciCizim->sonraki = silGeciciCizim->sonraki;
                free(silGeciciCizim);
                break;
            }
            geciciCizim = geciciCizim->sonraki;
        }
    }
}

//Cizim Duzenleme Yapabilmek icin Onu Bulmaya Yarayan Fonksiyon.
void CizimAra(){
	int kontrol = 0;
    geciciCizim = ilkCizim;
    while (geciciCizim != NULL) {
        if (geciciCizim->CizdirilenTur == CizdirilenTur && geciciCizim->CizimSayisi == CizimSayisi) {
            kontrol = 1;
        }
        geciciCizim = geciciCizim->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Polinom Cizdirmek icin denklem derece ve kat tutuluyor
void DereceKatEkle(){
	yeniDereceKat = (derecekat *)malloc(sizeof(derecekat));
	yeniDereceKat->Derece = Derece;
	yeniDereceKat->KatSayi = KatSayi;
	yeniDereceKat->DereceKatSayisi = DereceKatSayisi;
	yeniDereceKat->KordinatDuzlemi = KordinatDuzlemi;
	yeniDereceKat->sonraki =NULL;
	if(ilkDereceKat==NULL){
		ilkDereceKat = yeniDereceKat;
		sonDereceKat = ilkDereceKat;
	}else{
		sonDereceKat->sonraki = yeniDereceKat;
		sonDereceKat = sonDereceKat->sonraki;
	}
	printf("DereceKat Derece:%d\tDereceKat KatSayi:%f\tDereceKat DereceKatSayisi:%d\n"
	,yeniDereceKat->Derece,yeniDereceKat->KatSayi,yeniDereceKat->DereceKatSayisi);
}

//Polinom Uzerýnde degisiklik yapilmak icin Derece Silme kullanilmasi gerekecekti...
void DereceKatSil(){
	int kontrol = 0;
    if (ilkDereceKat->DereceKatSayisi == DereceKatSayisi) {
        silGeciciDereceKat = ilkDereceKat;
        ilkDereceKat = ilkDereceKat->sonraki;
        free(silGeciciDereceKat);
        kontrol = 1;
    } else {
        geciciDereceKat = ilkDereceKat;
        while (geciciDereceKat->sonraki != NULL) {
            if (geciciDereceKat->DereceKatSayisi == DereceKatSayisi) {
                kontrol = 1;
                silGeciciDereceKat = geciciDereceKat->sonraki;
 
                if (silGeciciDereceKat == sonDereceKat)
                    sonDereceKat = geciciDereceKat;
                geciciDereceKat->sonraki = silGeciciDereceKat->sonraki;
                free(silGeciciDereceKat);
                break;
            }
            geciciDereceKat = geciciDereceKat->sonraki;
        }
    }
}

//Polinom Uzerýnde Guncelleme Yapabilmek Icin Onu Bulmaya Yarayan Fonksiyon
void DereceKatAra(){
	int kontrol = 0;
    geciciDereceKat = ilkDereceKat;
    while (geciciDereceKat != NULL) {
        if (geciciDereceKat->DereceKatSayisi == DereceKatSayisi) {
            kontrol = 1;
        }
        geciciDereceKat = geciciDereceKat->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Polinom Eklemeye Yarayan Fonksiyon
void PolinomEkle(){
	yeniPolinom = (polinom *)malloc(sizeof(polinom));
	yeniPolinom->CizimSayisiPolinom = CizimSayisiPolinom;
	yeniPolinom->BaslangicKordinatX[0] = BaslangicKordinatX[0];
	yeniPolinom->BaslangicKordinatX[1] = BaslangicKordinatX[1];
	yeniPolinom->BaslangicKordinatY[0] = BaslangicKordinatY[0];
	yeniPolinom->BaslangicKordinatY[1] = BaslangicKordinatY[1];
	yeniPolinom->sonraki = NULL;
	bool secim=true;
		while(secim==true){
			printf("Deger Ekleyin:");
			scanf("%d",&Derece);
			printf("Katsayi Ekleyin:");
			scanf("%f",&KatSayi);
			DereceKatEkle();
			printf("Devam Etmek Istiyor musunuz?\n");
			scanf("%i",&secim);
		}
	if(ilkPolinom == NULL){
		ilkPolinom = yeniPolinom;
		sonPolinom = ilkPolinom;
	}else{
		sonPolinom->sonraki = yeniPolinom;
		sonPolinom = sonPolinom->sonraki ;
	}
}

//Polinom Silmeye Yarayan Fonksiyon
void PolinomSil(){
	int kontrol = 0;
    if (ilkPolinom->CizimSayisiPolinom == CizimSayisiPolinom) {
        silGeciciPolinom = ilkPolinom;
        ilkPolinom = ilkPolinom->sonraki;
        DereceKatSil();
        free(silGeciciPolinom);
        kontrol = 1;
    } else {
        geciciPolinom = ilkPolinom;
        while (geciciPolinom->sonraki != NULL) {
            if (geciciPolinom->CizimSayisiPolinom == CizimSayisiPolinom) {
                kontrol = 1;
                silGeciciPolinom = geciciPolinom->sonraki;
 
                if (silGeciciPolinom == sonPolinom)
                    sonPolinom = geciciPolinom;
                geciciPolinom->sonraki = silGeciciPolinom->sonraki;
                DereceKatSil();
                free(silGeciciPolinom);
                break;
            }
            geciciPolinom = geciciPolinom->sonraki;
        }
    }
}

//Polinom Guncellemek icin Arama Yapmaya Yarayan Fonksiyon
void PolinomAra(){
	int kontrol = 0;
    geciciPolinom = ilkPolinom;
    while (geciciPolinom != NULL) {
        if (geciciPolinom->CizimSayisiPolinom == CizimSayisiPolinom) {
            kontrol = 1;
            DereceKatAra();
        }
        geciciPolinom = geciciPolinom->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Disk Eklemeye Yarayan Fonksiyon
void DiskEkle(){
	yeniDisk = (disk *)malloc(sizeof(disk));
	yeniDisk->CizimSayisiDisk = CizimSayisiDisk;
	yeniDisk->CapMerkezKordinatX = CapMerkezKordinatX;
	yeniDisk->CapMerkezKordinatY = CapMerkezKordinatY;
	yeniDisk->sonraki = NULL;
		for(int i=0;i<2;i++){
			yeniDisk->EliptikYariCaplar[i] = EliptikYariCaplar[i];
		}
	if(ilkDisk == NULL){
		ilkDisk = yeniDisk;
		sonDisk = ilkDisk;
	}else{
		sonDisk->sonraki = yeniDisk;
		sonDisk = sonDisk->sonraki;
	}
}

//Disk Silmeye Yarayan Fonksiyon
void DiskSil(){
	int kontrol = 0;
    if (ilkDisk->CizimSayisiDisk == CizimSayisiDisk) {
        silGeciciDisk = ilkDisk;
        ilkDisk = ilkDisk->sonraki;
        free(silGeciciDisk);
        kontrol = 1;
    } else {
        geciciDisk = ilkDisk;
        while (geciciDisk->sonraki != NULL) {
            if (geciciDisk->CizimSayisiDisk == CizimSayisiDisk) {
                kontrol = 1;
                silGeciciDisk = geciciDisk->sonraki;
 
                if (silGeciciDisk == sonDisk)
                    sonDisk = geciciDisk;
                geciciDisk->sonraki = silGeciciDisk->sonraki;
                free(silGeciciDisk);
                break;
            }
            geciciDisk = geciciDisk->sonraki;
        }
    }
}

//Disk Guncellemek icin Arama Yapmaya Yarayan Fonksiyon
void DiskAra(){
	int kontrol = 0;
    geciciDisk = ilkDisk;
    while (geciciDisk != NULL) {
        if (geciciDisk->CizimSayisiDisk == CizimSayisiDisk) {
            kontrol = 1;
        }
        geciciDisk = geciciDisk->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Ucgen Eklemeye Yarayan Fonksiyon
void UcgenEkle(){
	yeniUcgen = (Ucgen *)malloc(sizeof(Ucgen));
	yeniUcgen->CizimSayisiUcgen = CizimSayisiUcgen;
	yeniUcgen->DolulukUcgen = DolulukUcgen;
	yeniUcgen->sonraki = NULL;
		for(int i=0;i<3;i++){
			yeniUcgen->KoseKordinatY[i] = KoseKordinatY[i];
			yeniUcgen->KoseKordinatX[i] = KoseKordinatX[i];
			yeniUcgen->fonkA[i] = fonkA[i];
			yeniUcgen->fonkB[i] = fonkB[i];
		}
	if(ilkUcgen == NULL){
		ilkUcgen = yeniUcgen;
		sonUcgen = ilkUcgen;
	}else{
		sonUcgen->sonraki = yeniUcgen;
		sonUcgen = sonUcgen->sonraki;
	}
}

//Ucgen Silmeye Yarayan Fonksiyon
void UcgenSil(){
	int kontrol = 0;
    if (ilkUcgen->CizimSayisiUcgen == CizimSayisiUcgen) {
        silGeciciUcgen = ilkUcgen;
        ilkUcgen = ilkUcgen->sonraki;
        free(silGeciciUcgen);
        kontrol = 1;
    } else {
        geciciUcgen = ilkUcgen;
        while (geciciUcgen->sonraki != NULL) {
            if (geciciUcgen->CizimSayisiUcgen == CizimSayisiUcgen) {
                kontrol = 1;
                silGeciciUcgen = geciciUcgen->sonraki;
                if (silGeciciUcgen == sonUcgen)
                    sonUcgen = geciciUcgen;
                geciciUcgen->sonraki = silGeciciUcgen->sonraki;
                free(silGeciciUcgen);
                break;
            }
            geciciUcgen = geciciUcgen->sonraki;
        }
    }
}

//Ucgen Guncellemek icin Arama Yapmaya Yarayan Fonksiyon
void UcgenAra(){
	int kontrol = 0;
    geciciUcgen = ilkUcgen;
    while (geciciUcgen != NULL) {
        if (geciciUcgen->CizimSayisiUcgen == CizimSayisiUcgen) {
            kontrol = 1;
        }
        geciciUcgen = geciciUcgen->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Dortgen Eklemeye Yarayan Fonksiyon
void DortgenEkle(){
	yeniDortgen = (Dortgen *)malloc(sizeof(Dortgen));
	yeniDortgen->CizimSayisiDortgen = CizimSayisiDortgen;
	yeniDortgen->DolulukDortgen = DolulukDortgen;
	yeniDortgen->BaslangicKordinatX = BaslangicKordinatDortgenX;
	yeniDortgen->BaslangicKordinatY = BaslangicKordinatDortgenY;
	yeniDortgen->sonraki = NULL;
		for(int i=0;i<2;i++){	
			yeniDortgen->KenarUzunluklari[i] = KenarUzunluklari[i];	
		}
	if(ilkDortgen == NULL){
		ilkDortgen = yeniDortgen;
		sonDortgen = ilkDortgen;
	}else{
		sonDortgen->sonraki = yeniDortgen;
		sonDortgen = sonDortgen->sonraki;
	}
}

//Dortgen Silmeye Yarayan Fonksiyon
void DortgenSil(){
	int kontrol = 0;
    if (ilkDortgen->CizimSayisiDortgen == CizimSayisiDortgen) {
        silGeciciDortgen = ilkDortgen;
        ilkDortgen = ilkDortgen->sonraki;
        free(silGeciciDortgen);
        kontrol = 1;
    } else {
        geciciDortgen = ilkDortgen;
        while (geciciDortgen->sonraki != NULL) {
            if (geciciDortgen->CizimSayisiDortgen == CizimSayisiDortgen) {
                kontrol = 1;
                silGeciciDortgen = geciciDortgen->sonraki;
 
                if (silGeciciDortgen == sonDortgen)
                    sonDortgen = geciciDortgen;
                geciciDortgen->sonraki = silGeciciDortgen->sonraki;
                free(silGeciciDortgen);
                break;
            }
            geciciDortgen = geciciDortgen->sonraki;
        }
    }
}

//Dortgen Guncellemek icin Arama Yapmaya Yarayan Fonksiyon
void DortgenAra(){
	int kontrol = 0;
    geciciDortgen = ilkDortgen;
    while (geciciDortgen != NULL) {
        if (geciciDortgen->CizimSayisiDortgen == CizimSayisiDortgen) {
            kontrol = 1;
        }
        geciciDortgen = geciciDortgen->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Eliptik Eklemeye Yarayan Fonksiyon
void EliptikEkle(){
	yeniEliptik = (Eliptik *)malloc(sizeof(Eliptik));
	yeniEliptik->CizimSayisiEliptik = CizimSayisiEliptik;
	yeniEliptik->DolulukEliptik = DolulukEliptik;
	yeniEliptik->EliptikYariCap = EliptikYariCap;
	yeniEliptik->CapMerkezKordinatX = CapMerkezKordinatX;
	yeniEliptik->CapMerkezKordinatY = CapMerkezKordinatY;
	yeniEliptik->KatSayiX = KatSayiX;
	yeniEliptik->KatSayiY = KatSayiY;
	yeniEliptik->sonraki = NULL;
	if(ilkEliptik == NULL){
		ilkEliptik = yeniEliptik;
		sonEliptik = ilkEliptik;
	}else{
		sonEliptik->sonraki = yeniEliptik;
		sonEliptik = sonEliptik->sonraki;
	}
}

//Eliptik Silmeye Yarayan Fonksiyon
void EliptikSil(){
	int kontrol = 0;
    if (ilkEliptik->CizimSayisiEliptik == CizimSayisiEliptik) {
        silGeciciEliptik = ilkEliptik;
        ilkEliptik = ilkEliptik->sonraki;
        free(silGeciciEliptik);
        kontrol = 1;
    } else {
        geciciEliptik = ilkEliptik;
        while (geciciEliptik->sonraki != NULL) {
            if (geciciEliptik->CizimSayisiEliptik == CizimSayisiEliptik) {
                kontrol = 1;
                silGeciciEliptik = geciciEliptik->sonraki;
 
                if (silGeciciEliptik == sonEliptik)
                    sonEliptik = geciciEliptik;
                geciciEliptik->sonraki = silGeciciEliptik->sonraki;
                free(silGeciciEliptik);
                break;
            }
            geciciEliptik = geciciEliptik->sonraki;
        }
    }
}

//Eliptik Guncellemek icin Arama Yapmaya Yarayan Fonksiyon
void EliptikAra(){
	int kontrol = 0;
    geciciEliptik = ilkEliptik;
    while (geciciEliptik != NULL) {
        if (geciciEliptik->CizimSayisiEliptik == CizimSayisiEliptik) {
            kontrol = 1;
        }
        geciciEliptik = geciciEliptik->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}

//Not1: ZamanYeterse Bunlara da Aynisi Uygulanacak.
//Not2: Zaman Yetmedi...
void PoligonEkle(){
	
}

void PoligonSil(){
	
}

void PoligonAra(){
	
}

void YildizEkle(){
	
}

void YildizSil(){
	
}

void YildizAra(){
	
}

//Ana Menu de Gezinmeyi Saglar
void Menu(){
	system("CLS");
	int secim=0;
	printf("1-Sekil Cizdirme\n2-Sekil Silme\n3-Sekil Arama\n4-Hareket Islemleri\n5-Zoom Islemleri"
	"\n6-Kirpma\n7-Cikis\nSecim:");
	scanf("%d",&secim);
	switch(secim){
		case 1:{
			SekilEkleMenu();
			break;
		}
		case 2:{
			SekilSilMenu();
			break;
		}
		case 3:{
			SekilAraMenu();
			break;
		}
		case 4:{
			HareketMenu();
			break;
		}
		case 5:{
			EkranZoom();
			break;
		}
		case 6:{
			Kirpma();
			break;
		}
		case 7:{
			printf("Programdan Cikiliyor...");
			exit(0);
			break;
		}
		default:{
			printf("Hatali Deger!!!");
			break;
		}
	}
	Menu();
}

void EkranTemizle(){
	system("CLS");
}

void SekilEkleMenu(){
	EkranTemizle();
	int secim=0,kontrolNoktasi=false;
	printf("Not:Her Sekilden yalnizca bir defa cizilebilir.\n");
	printf("1-Polinom Cizdir\n2-Disk Cizdir\n3-Ucgen Cizdir\n4-Dortgen Cizdir\n");
	printf("5-Eliptik Cizdir\n6-Poligon Cizdir\n7-Yildiz Cizdir\n8-Menuye Geri Don\nSecim:");
	scanf("%d",&secim);
	if(secim !=8){
		CizdirilenTur = secim;
		kontrolNoktasi=true;
	}
	if(kontrolNoktasi == true){
		printf("Kacinci Grafik Olarak Kaydedilsin?\n");
		scanf("%d",&CizimSayisi);	
	}
	switch(secim){
		case 1:{
			printf("BaslangicNoktasiX Giriniz:");
			scanf("%d",&BaslangicKordinatX[0]);
			printf("BaslangicNoktasiY Giriniz:");
			scanf("%d",&BaslangicKordinatY[0]);
			printf("BitisNoktasiX Giriniz:");
			scanf("%d",&BaslangicKordinatX[1]);
			printf("BitisNoktasiY Giriniz:");
			scanf("%d",&BaslangicKordinatY[1]);
			printf("X kordinat Duzleminde mi yoksa Y kordinat duzleminde islem yapilacak?\n"
			"X kordinat Duzlem icin 0 Y kordinat Duzlemi icin 1 basiniz.");
			scanf("%i",&KordinatDuzlemi);
			//Normalde baslangic ve bitis degeri ile kisitli bir alaný cizdirmeye Calisacaktim
			//Ama bazi Degerler bu kisitli alan disina ciktigi icin bunun baslangic degerlerini
			//sifir aldirdim.	
				for(int i=0;i<2;i++){
					BaslangicKordinatX[i] = 0;
					BaslangicKordinatY[i] = 0;
				}
			BaslangicKordinatY[0] = (-BaslangicKordinatY[0]);
			BaslangicKordinatY[1] = (-BaslangicKordinatY[1]);
			break;
		}
		case 2:{
			printf("Yaricap1 Giriniz:");
			scanf("%d",&EliptikYariCaplar[0]);
			printf("Yaricap2 Giriniz:");
			scanf("%d",&EliptikYariCaplar[1]);
			printf("katSayiY Giriniz:");
			scanf("%d",&DiskKatSayiY);
			printf("katsayiX Giriniz:");
			scanf("%d",&DiskKatSayiX);
			printf("konumX Giriniz:");
			scanf("%d",&CapMerkezKordinatX);
			printf("konumY Giriniz:");
			scanf("%d",&CapMerkezKordinatY);
			CapMerkezKordinatY=(-CapMerkezKordinatY);
			break;
		}
		case 3:{
			//UcgenCizdir();
			break;
		}
		case 4:{
			printf("Birinci Kenari Giriniz:");
			scanf("%d",&KenarUzunluklari[0]);
			printf("Ikinci Kenari Giriniz:");
			scanf("%d",&KenarUzunluklari[1]);
			printf("KonumX Giriniz:");
			scanf("%d",&BaslangicKordinatDortgenX);
			printf("KonumY Giriniz:");
			scanf("%d",&BaslangicKordinatDortgenY);
			BaslangicKordinatDortgenY=(-BaslangicKordinatDortgenY);
			printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
			scanf("%i",&DolulukDortgen);
			break;
		}
		case 5:{
			printf("Yaricap Giriniz:");
			scanf("%d",&EliptikYariCap);
			printf("katSayiY Giriniz:");
			scanf("%d",&KatSayiY);
			printf("katsayiX Giriniz:");
			scanf("%d",&KatSayiX);
			printf("konumX Giriniz:");
			scanf("%d",&CapMerkezKordinatX);
			printf("konumY Giriniz:");
			scanf("%d",&CapMerkezKordinatY);
			CapMerkezKordinatY=(-CapMerkezKordinatY);
			printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
			scanf("%i",&DolulukEliptik);
			break;
		}
		case 6:{
			//PoligonCizdir();
			break;
		}
		case 7:{
			//YildizCizdir();
			break;
		}
		case 8:{
			Menu();
			break;
		}
		default:{
			printf("Hatali Deger!!!");
			break;
		}
	}
	CizimEkle();
	SekilEkleMenu();	
}

//Polinom Cizdiren Fonksiyon
//Istedigi Egri ve Cizgileri Cizmesi icin Hazirlanmistir.
//Polinom Fonksiyonu Oldugu icin Yay Cizemez.
void PolinomCizdir(){
	EkranTemizle();
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			geciciDereceKat=ilkDereceKat;
			geciciPolinom = ilkPolinom;
			float sonuc1=0,katsayili1=0,sonuc2=0,katsayili2=0;
			while(geciciDereceKat != NULL){
				if(geciciDereceKat->DereceKatSayisi == DereceKatSayisi){
					if(geciciDereceKat->KordinatDuzlemi == false){
					katsayili1=pow(j,geciciDereceKat->Derece);
				sonuc1+=geciciDereceKat->KatSayi*katsayili1;
				switch(geciciDereceKat->Derece%2){
					case 0:{
						if(j<0){
							katsayili2=pow((j-1)-BaslangicKordinatX[0],geciciDereceKat->Derece);
							sonuc2+=geciciDereceKat->KatSayi*katsayili2;
						}else{
							katsayili2=pow((j+1)-BaslangicKordinatX[0],geciciDereceKat->Derece);
							sonuc2+=geciciDereceKat->KatSayi*katsayili2;
						}
						break;
					}
					case 1:{
						if(j<0){
							katsayili2=pow((j+1)-BaslangicKordinatX[0],geciciDereceKat->Derece);
							sonuc2+=geciciDereceKat->KatSayi*katsayili2;
						}else{
							katsayili2=pow((j+1)-BaslangicKordinatX[0],geciciDereceKat->Derece);
							sonuc2+=geciciDereceKat->KatSayi*katsayili2;
							}
						break;
					}
				}
				}else if(geciciDereceKat->KordinatDuzlemi == true){
					katsayili1=pow(-i,geciciDereceKat->Derece);
				sonuc1+=geciciDereceKat->KatSayi*katsayili1;
				switch(geciciDereceKat->Derece%2){
					case 0:{
						if(i>0){
							katsayili2=pow((-i+1)+BaslangicKordinatY[0],geciciDereceKat->Derece);
							sonuc2=geciciDereceKat->KatSayi*katsayili2;
						}else{
							katsayili2=pow((-i-1)+BaslangicKordinatY[0],geciciDereceKat->Derece);
							sonuc2=geciciDereceKat->KatSayi*katsayili2;
						}
						break;
					}
					case 1:{
						if(i>0){
							katsayili2=pow((-i-1)+BaslangicKordinatY[0],geciciDereceKat->Derece);
							sonuc2+=geciciDereceKat->KatSayi*katsayili2;
						}else{
							katsayili2=pow((-i-1)+BaslangicKordinatY[0],geciciDereceKat->Derece);
							sonuc2+=geciciDereceKat->KatSayi*katsayili2;
							}
						break;
					}
				}
				}else{
					printf("Hatali Deger!!!\n");
					break;
					}
				}
				geciciDereceKat = geciciDereceKat->sonraki;
			}
			if(KordinatDuzlemi == true){
				sonuc1-=BaslangicKordinatY[0];
				sonuc2-=BaslangicKordinatY[0];	
			}else if(KordinatDuzlemi == false){
				sonuc1+=BaslangicKordinatY[0];
				sonuc2+=BaslangicKordinatY[0];
			}
			else{
				break;
			}
			if(((j<=(int)sonuc1 && j>=(int)sonuc2) 
			 || (j>=(int)sonuc1 && j<=(int)sonuc2))
			 && KordinatDuzlemi == true){
				if((i+BaslangicKordinatY[0] >199 || j+BaslangicKordinatX[0] >199 
				 || i+BaslangicKordinatY[0]<-199 || j+BaslangicKordinatX[0] <-199) 
				 ||(i+BaslangicKordinatY[1] >199 || j+BaslangicKordinatX[1] >199 
				 || i+BaslangicKordinatY[1]<-199 || j+BaslangicKordinatX[1] <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatY[0]][j+199+BaslangicKordinatX[0]]
						== karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
							harita[i+199+BaslangicKordinatY[0]][j+199+BaslangicKordinatX[0]]=
							karakterDegerleri[karakterDizisi[1]];
						}
					}
			}else if(((i<=-(int)sonuc1 && i>=-(int)sonuc2) 
			      || (i>=-(int)sonuc1 && i<=-(int)sonuc2))
				  && KordinatDuzlemi == false){
				if((i+BaslangicKordinatY[0] >199 || j+BaslangicKordinatX[0] >199 
				 || i+BaslangicKordinatY[0]<-199 || j+BaslangicKordinatX[0] <-199) 
				 ||(i+BaslangicKordinatY[1] >199 || j+BaslangicKordinatX[1] >199 
				 || i+BaslangicKordinatY[1]<-199 || j+BaslangicKordinatX[1] <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatY[0]][j+199+BaslangicKordinatX[0]]
						== karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
							harita[i+199+BaslangicKordinatY[0]][j+199+BaslangicKordinatX[0]]=
							karakterDegerleri[karakterDizisi[1]];
						}	
					}
				}
			else{
				if((i<=-(int)sonuc1 && i>=-(int)sonuc2)){
				if((i+BaslangicKordinatY[0] >199 || j+BaslangicKordinatX[0] >199 
				 || i+BaslangicKordinatY[0]<-199 || j+BaslangicKordinatX[0] <-199) 
				 ||(i+BaslangicKordinatY[1] >199 || j+BaslangicKordinatX[1] >199 
				 || i+BaslangicKordinatY[1]<-199 || j+BaslangicKordinatX[1] <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatY[0]][j+199+BaslangicKordinatX[0]]
						==karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
							karakterDegerleri[karakterDizisi[0]]);
							harita[i+199+BaslangicKordinatY[0]][j+199+BaslangicKordinatX[0]]=
							karakterDegerleri[karakterDizisi[0]];
						}
					}
				}
			}
		}
	}
	HaritaCizdir();
	geciciPolinom = ilkPolinom;
	while(geciciPolinom != NULL){
		printf("Bilgiler:\n X1:%d,X2:%d,Y1:%d,Y2%d,CizimSayisi:%d\n",
		geciciPolinom->BaslangicKordinatX[0],geciciPolinom->BaslangicKordinatX[1],
		geciciPolinom->BaslangicKordinatY[0],geciciPolinom->BaslangicKordinatY[1],
		geciciPolinom->CizimSayisiPolinom);
		geciciPolinom = geciciPolinom->sonraki;
	}
	getchar();
	printf("Polinom Cizildi!!");
	getchar();
	fclose(dosyaKontrol);
	KarakterDizisiGuncelleme();
}

//Disk Cizen Fonksiyon
//Ýki Daire Merkezi Ortaktir.
//Ýki Daire Capi Alinark Sorgu Yapilir.
void DiskCizdir(){
	EkranTemizle();
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			geciciDisk = ilkDisk;
				if(DiskKatSayiY*pow(i,2)+DiskKatSayiX*pow(j,2) <= pow(EliptikYariCaplar[0],2) 
				&& DiskKatSayiY*pow(i,2)+DiskKatSayiX*pow(j,2)>= pow(EliptikYariCaplar[1],2)){
					if((i+CapMerkezKordinatY >199 || j+CapMerkezKordinatX >199 
					 || i+CapMerkezKordinatY <-199 || j+CapMerkezKordinatX <-199)){
						continue;
					}else{
						if(harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
							harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]=
							karakterDegerleri[karakterDizisi[1]];
						}	
					}	
				}else{
					if((i+CapMerkezKordinatY >199 || j+CapMerkezKordinatX >199 
					 || i+CapMerkezKordinatY <-199 || j+CapMerkezKordinatX <-199)){
						continue;
					}else{
						if(harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
							karakterDegerleri[karakterDizisi[0]]);
							harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]=
							karakterDegerleri[karakterDizisi[0]];	
						}	
					}
				}
			}
		fprintf(dosyaKontrol,"\n");
	}
	HaritaCizdir();
	geciciDisk = ilkDisk;
	while(geciciDisk != NULL){
		printf("Bilgiler:\n X:%d,Y:%d,KatSayix:%d,KatSayiY:%d,CizimSayisi:%d\n",
		geciciDisk->CapMerkezKordinatX,geciciDisk->CapMerkezKordinatY,
		geciciDisk->DiskKatSayiX,geciciDisk->DiskKatSayiY,
		geciciDisk->CizimSayisiDisk);
		geciciDisk = geciciDisk->sonraki;
	}
	getchar();
	printf("Disk Cizildi!!");
	getchar();
	fclose(dosyaKontrol);
	KarakterDizisiGuncelleme();
}

//Buna Zaman Kalirsa Bakilacak!
//Not2: Zaman Yetmedi...
//Ucgen Cizdirmek icin Uc Dogru Kesisiyor ama Dogru Kirpma Ýslemi Yapmiyor
void UcgenCizdir(){
	EkranTemizle();
	bool kontrol=false;
	int konumX1=0,konumX2=0,konumX3=0,konumY1=0,konumY2=0,konumY3=0;
	float fonkA1=0,fonkA2=0,fonkA3=0,fonkB1=0,fonkB2=0,fonkB3=0;
	dosyaKontrol = fopen("Grafik.txt","w");
	printf("Birinci Kose Kordinatlarini Giriniz:");
	scanf("%d,%d",&konumX1,&konumY1);
	printf("Ikinci Kose Kordinatlarini Giriniz:");
	scanf("%d,%d",&konumX2,&konumY2);
	printf("Ucuncu Kose Kordinatlarini Giriniz:");
	scanf("%d,%d",&konumX3,&konumY3);
	/*
	konumX1=(-konumX1);
	konumX2=(-konumX2);
	konumX3=(-konumX3);
	konumY1=(-konumY1);
	konumY2=(-konumY2);
	konumY3=(-konumY3);
	*/
	fonkA1=((float)konumY1-(float)konumY2)/((float)konumX2-(float)konumX1);
	fonkA2=((float)konumY2-(float)konumY3)/((float)konumX3-(float)konumX2);
	fonkA3=((float)konumY3-(float)konumY1)/((float)konumX1-(float)konumX3);
		
	fonkB1=(float)konumY1-(fonkA1*(float)konumX1);
	fonkB2=(float)konumY2-(fonkA2*(float)konumX2);
	fonkB3=(float)konumY3-(fonkA3*(float)konumX3);
	/*
	konumX1=(-konumX1);
	konumX2=(-konumX2);
	konumX3=(-konumX3);
	*/
	konumY1=(-konumY1);
	konumY2=(-konumY2);
	konumY3=(-konumY3);
	printf("fonkA1:%f\tfonkB1=%f\n",fonkA1,fonkB1);
	printf("fonkA2:%f\tfonkB2=%f\n",fonkA2,fonkB2);
	printf("fonkA3:%f\tfonkB3=%f\n",fonkA3,fonkB3);
	printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
	scanf("%i",&kontrol);
	for(int i=199;i>=-199;i--){
		for(int j=-199;j<=199;j++){
			if(kontrol==false){
				if((i==fonkA1*j+fonkB1 &&(i<=konumY1 && i>=konumY3))){
				if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						if(harita[i+199+konumY1][j+199+konumX1]==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+konumY1][j+199+konumX1]=karakterDegerleri[karakterDizisi[2]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[2]],
							karakterDegerleri[karakterDizisi[2]]);
						}
					}	
				}else if((i==fonkA2*j+fonkB2 &&(i<=konumY1 && i>=konumY3))){
					if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						if(harita[i+199+konumY1][j+199+konumX1]==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+konumY1][j+199+konumX1]=karakterDegerleri[karakterDizisi[2]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[2]],
							karakterDegerleri[karakterDizisi[2]]);
						}
					}
				}else if((i==fonkA3*j+fonkB3 &&(i<=konumY1 && j>=konumY3))){
					if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						if(harita[i+199+konumY1][j+199+konumX1]==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+konumY1][j+199+konumX1]=karakterDegerleri[karakterDizisi[2]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[2]],
							karakterDegerleri[karakterDizisi[2]]);
						}
					}
				}else{
					if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						if(harita[i+199+konumY1][j+199+konumX1]==karakterDegerleri[karakterDizisi[3]]){
						harita[i+199+konumY1][j+199+konumX1]=karakterDegerleri[karakterDizisi[0]];
						fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
						karakterDegerleri[karakterDizisi[0]]);	
						}
					}
				}	
				}
				else if(kontrol == true){
					int sayac=0;
					if(harita[i+199][j+199]==karakterDegerleri[karakterDizisi[2]]){
						printf("%c%c",harita[i+199][j+199],harita[i+199][j+199]);	
					}else{
						printf("  ");
					}
					if(harita[i+199][j+199]==karakterDegerleri[karakterDizisi[2]]){
						sayac++;
					}
					switch(sayac%4){
						case 0:{
							harita[i+199][j+199]=karakterDegerleri[karakterDizisi[0]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
							karakterDegerleri[karakterDizisi[0]]);
							break;
						}
						case 1:{
							harita[i+199][j+199]=karakterDegerleri[karakterDizisi[1]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
							break;
						}
						case 2:{
							harita[i+199][j+199]=karakterDegerleri[karakterDizisi[1]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
							break;
						}
						case 3:{
							harita[i+199][j+199]=karakterDegerleri[karakterDizisi[0]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
							karakterDegerleri[karakterDizisi[0]]);
							break;
						}
					}
			}else{
				printf("Hatali Deger!");
				break;
			}
		}
		fprintf(dosyaKontrol,"\n");
	}
	HaritaCizdir();
	getchar();
	getchar();
	fclose(dosyaKontrol);
	KarakterDizisiGuncelleme();
}

//Dortgen Olarak Kare ve Dikdortgeni Ortak Cizdiriyor.
//Alinan iki Kenara Göre ve Baslangic Pozisyonuna göre Dortgen Ciziyor
void DortgenCizdir(){
	EkranTemizle();
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			if(DolulukDortgen==false){
				if((BaslangicKordinatDortgenX==j || BaslangicKordinatDortgenX+KenarUzunluklari[0]==j) 
				&& (BaslangicKordinatDortgenY<=i && BaslangicKordinatDortgenY+KenarUzunluklari[1]>=i)){
					if((i+BaslangicKordinatDortgenY >199 || j+BaslangicKordinatDortgenX >199 
					 || i+BaslangicKordinatDortgenY <-199 || j+BaslangicKordinatDortgenX <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]=
							karakterDegerleri[karakterDizisi[2]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[2]],
							karakterDegerleri[karakterDizisi[2]]);
						}
					}
				}else if((BaslangicKordinatDortgenY==i || BaslangicKordinatDortgenY+
				KenarUzunluklari[1]==i)
				&& (BaslangicKordinatDortgenX<=j && BaslangicKordinatDortgenX+KenarUzunluklari[0]>=j)){
					if((i+BaslangicKordinatDortgenY >199 || j+BaslangicKordinatDortgenX >199 
					 || i+BaslangicKordinatDortgenY <-199 || j+BaslangicKordinatDortgenX <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]
						==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]=
							karakterDegerleri[karakterDizisi[2]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[2]],
							karakterDegerleri[karakterDizisi[2]]);
						}	
					}
				}else{
					if((i+BaslangicKordinatDortgenY >199 || j+BaslangicKordinatDortgenX >199 
					 || i+BaslangicKordinatDortgenY <-199 || j+BaslangicKordinatDortgenX <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]
						 ==karakterDegerleri[karakterDizisi[3]]){
						harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]=
						karakterDegerleri[karakterDizisi[0]];
						fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
						karakterDegerleri[karakterDizisi[0]]);	
						}
					}
					
				}
			}else if(DolulukDortgen==true){
				if((BaslangicKordinatDortgenX<=j && BaslangicKordinatDortgenX+KenarUzunluklari[0]>=j) 
				&& (BaslangicKordinatDortgenY<=i && BaslangicKordinatDortgenY+KenarUzunluklari[1]>=i)){
					if((i+BaslangicKordinatDortgenY >199 || j+BaslangicKordinatDortgenX >199 
					 || i+BaslangicKordinatDortgenY <-199 || j+BaslangicKordinatDortgenX <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]=
							karakterDegerleri[karakterDizisi[1]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
						}	
					}
				}else{
					if((i+BaslangicKordinatDortgenY >199 || j+BaslangicKordinatDortgenX >199 
					 || i+BaslangicKordinatDortgenY <-199 || j+BaslangicKordinatDortgenX <-199)){
						continue;
					}else{
						if(harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]
						 ==karakterDegerleri[karakterDizisi[3]]){
						harita[i+199+BaslangicKordinatDortgenY][j+199+BaslangicKordinatDortgenX]=
						karakterDegerleri[karakterDizisi[0]];
						fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
						karakterDegerleri[karakterDizisi[0]]);	
						}	
					}
				}
			}else{
				printf("Hatali Deger!");
				break;
			}
		}
		fprintf(dosyaKontrol,"\n");
	}
	HaritaCizdir();
	getchar();
	printf("Dortgen Cizildi!!");
	getchar();
	fclose(dosyaKontrol);
	KarakterDizisiGuncelleme();
}

//Daire ve Eliptik yni Fonksiyonda Cizdiriliyor
//Burada a*(y-y1)^2+b*(x-x1)^2 = r^2 formulune göre hesaplama alýnmistir
//a = b olursa daire ,diger durumlarda eliptik cizer
void EliptikCizdir(){
	EkranTemizle();
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
				if(DolulukEliptik == false ){
				if(KatSayiY*pow(i,2)+KatSayiX*pow(j,2)-pow(EliptikYariCap,2)>=-EliptikYariCap 
				&& KatSayiY*pow(i,2)+KatSayiX*pow(j,2)-pow(EliptikYariCap,2)<=EliptikYariCap){
					if((i+CapMerkezKordinatY >199 || j+CapMerkezKordinatX >199 
					 || i+CapMerkezKordinatY <-199 || j+CapMerkezKordinatX <-199)){
						continue;
					}else{
						if(harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]=
							karakterDegerleri[karakterDizisi[2]];
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[2]],
							karakterDegerleri[karakterDizisi[2]]);
						}
					}
				}else{
					if((i+CapMerkezKordinatY >199 || j+CapMerkezKordinatX >199 
					 || i+CapMerkezKordinatY <-199 || j+CapMerkezKordinatX <-199)){
						continue;
					}else{
						if(harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]
						 ==karakterDegerleri[karakterDizisi[3]]){
						harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]=
						karakterDegerleri[karakterDizisi[0]];
						fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
						karakterDegerleri[karakterDizisi[0]]);	
						}	
					}
				}
			}else if(DolulukEliptik == true){
				if(KatSayiY*pow(i,2)+KatSayiX*pow(j,2) <= pow(EliptikYariCap,2)){
					if((i+CapMerkezKordinatY >199 || j+CapMerkezKordinatX >199 
					 || i+CapMerkezKordinatY <-199 || j+CapMerkezKordinatX <-199)){
						continue;
					}else{
						if(harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[1]],
							karakterDegerleri[karakterDizisi[1]]);
							harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]=
							karakterDegerleri[karakterDizisi[1]];
						}	
					}
				}else{
					if((i+CapMerkezKordinatY >199 || j+CapMerkezKordinatX >199 
					 || i+CapMerkezKordinatY <-199 || j+CapMerkezKordinatX <-199)){
						continue;
					}else{
						if(harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]
						 ==karakterDegerleri[karakterDizisi[3]]){
							fprintf(dosyaKontrol,"%c%c",karakterDegerleri[karakterDizisi[0]],
							karakterDegerleri[karakterDizisi[0]]);
							harita[i+199+CapMerkezKordinatY][j+199+CapMerkezKordinatX]=
							karakterDegerleri[karakterDizisi[0]];	
						}
					}
				}
			}else{
				printf("Hatali Deger!");
				break;
			}
			}
		fprintf(dosyaKontrol,"\n");
	}
	HaritaCizdir();
	getchar();
	printf("Eliptik Cizildi!!");
	getchar();
	fclose(dosyaKontrol);
	KarakterDizisiGuncelleme();	
}

//Not1: ZamanYeterse Bunlara da Aynisi Uygulanacak.
//Not2: Zaman Yetmedi...
void PoligonCizdir(){
	EkranTemizle();
	
}

void YildizCizdir(){
	EkranTemizle();
}


void SekilSilMenu(){
	EkranTemizle();
	Menu();
}

//Burada sekil guncellemek icin ilk halinin ozelliklerini alip Sildirecektim  fakat nedense tum sekiller
//Siliniyor. Bu yuzden yarida birakmak zorunda kaldim. Bunu yapamadigim icin otelendirme dondurme gibi
//fonksiyonlari yazmadim.
void SekilGuncellemeMenu(){
	EkranTemizle();
	geciciCizim=ilkCizim;
	printf("Hangi Tür Güncellenecek?\n"
	"1-Polinom\n"
	"2-Disk\n"
	"3-Ucgen\n"
	"4-Dortgen\n"
	"5-Eliptik\n"
	"6-Poligon\n"
	"7-Yildiz\n"
	"8-Geri Don\n"
	"Secim:");
	scanf("%d",&GuncellemeCizdirilenTur);
	printf("Kacinci Cizim Guncellenecek?\n"
	"Mevcut Olanlar:\n");
	while(geciciCizim != NULL){
		if(geciciCizim->CizdirilenTur == GuncellemeCizdirilenTur){
			printf("%d. Cizim Mevcut\n",geciciCizim->CizimSayisi);
		}
		geciciCizim= geciciCizim->sonraki;
	}
	printf("Secim:");
	scanf("%d",&GuncellemeCizimSayisi);
	geciciCizim=ilkCizim;
	while(geciciCizim != NULL){
		printf("Konum 1");
		if(geciciCizim->CizdirilenTur == GuncellemeCizdirilenTur 
		&& geciciCizim->CizimSayisi == GuncellemeCizimSayisi){
			switch(GuncellemeCizdirilenTur){
				case 1:{
					geciciPolinom = ilkPolinom;
					geciciDereceKat = ilkDereceKat;
					CizimSayisiPolinom = GuncellemeCizimSayisi;
					DereceKatSayisi = CizimSayisiPolinom;
						for(int i=0;i<4;i++){
							if(i==3){
								karakterDizisi[i]=1;
							}else{
								karakterDizisi[i]=0;
							}
						}
						while(geciciPolinom != NULL){
							if(geciciPolinom->CizimSayisiPolinom == CizimSayisiPolinom){
								for(int i=0;i<2;i++){
									geciciPolinom->BaslangicKordinatX[i] = BaslangicKordinatX[i];
									geciciPolinom->BaslangicKordinatY[i] = BaslangicKordinatY[i];
								}
							}
							geciciPolinom = geciciPolinom->sonraki;
						}
						while(geciciDereceKat != NULL){
							if(geciciDereceKat->DereceKatSayisi == DereceKatSayisi){
								geciciDereceKat->KordinatDuzlemi = KordinatDuzlemi;
							}
							geciciDereceKat = geciciDereceKat->sonraki;
						}
						PolinomCizdir();
					break;
				}
				case 2:{
					geciciDisk = ilkDisk;
					CizimSayisiDisk = GuncellemeCizimSayisi;
					for(int i=0;i<4;i++){
							if(i==3){
								karakterDizisi[i]=1;
							}else{
								karakterDizisi[i]=0;
							}
						}
					while(geciciDisk != NULL){
						printf("Konum 3");
						if(geciciDisk->CizimSayisiDisk == CizimSayisiDisk){
							printf("%d\t%d\n",GuncellemeCizimSayisi,CizimSayisiDisk);
							for(int i=0;i<2;i++){
								EliptikYariCaplar[i] = geciciDisk->EliptikYariCaplar[i];
							}
							CapMerkezKordinatX = geciciDisk->CapMerkezKordinatX;
							CapMerkezKordinatY = geciciDisk->CapMerkezKordinatY;
							DiskKatSayiX = geciciDisk->DiskKatSayiX;
							DiskKatSayiY = geciciDisk->DiskKatSayiY;
						}
						geciciDisk = geciciDisk->sonraki;
					}
					getchar();
					getchar();
					DiskCizdir();
					break;
				}
				case 3:{
					geciciUcgen = ilkUcgen;
					CizimSayisiUcgen = GuncellemeCizimSayisi;
					
					UcgenCizdir();
					break;
				}
				case 4:{
					geciciDortgen = ilkDortgen;
					CizimSayisiDortgen = GuncellemeCizimSayisi;
					while(geciciDortgen != NULL){
						if(geciciDortgen->CizimSayisiDortgen == CizimSayisiDortgen){
							for(int i=0;i<2;i++){
								geciciDortgen->KenarUzunluklari[i] = KenarUzunluklari[i];
							}
							geciciDortgen->BaslangicKordinatX = BaslangicKordinatDortgenX;
							geciciDortgen->BaslangicKordinatY = BaslangicKordinatDortgenY;
						}
					
						geciciDortgen = geciciDortgen->sonraki;	
					}				
					DortgenCizdir();
					break;
				}
				case 5:{
					geciciEliptik = ilkEliptik;
					CizimSayisiEliptik = GuncellemeCizimSayisi;
					
					EliptikCizdir();
					break;
				}
				case 6:{
					
					//PoligonCizdir();
					break;
				}
				case 7:{
					
					//YildizCizdir();
					break;
				}
			}
		}
		geciciCizim = geciciCizim->sonraki;
	}
}

//burada karakter dizisine gore gonderme yapiyorum. Eger # kullanilmak fonksiyon varsa 0,0,0,1 degeri ile
//silme yaparken 0,0,0,2 ile N harfli olanlari yani ici bos degerleri sildirmeye yariyordu.
void KarakterDizisiGuncelleme(){
	for(int i=0;i<4;i++){
		karakterDizisi[i]=i;
	}
}

//Burada Sekil Guncelleme Ile calisacagi icin bu da yarida kaldi...
void SekilAraMenu(){
	EkranTemizle();
}

//Hareket Menu Oteleme Dondurme gibi fonksiyonlarin bulundugu Menu
void HareketMenu(){
	EkranTemizle();
	int secim=0;
	printf("1-Oteleme\n2-Dondurme\n3-Olceklendirme\n4-Birlesik Donusumler\n5-Yansima\n");
	printf("6-Meyillendirme\n7-Menuye Geri Donme\nSecim:");
	scanf("%d",&secim);
	//SekilGuncellemeMenu();
	switch(secim){
		case 1:{
			Oteleme();
			break;
		}
		case 2:{
			Dondurme();
			break;
		}
		case 3:{
			Olceklendirme();
			break;
		}
		case 4:{
			BirlesikDonusumler();
			break;
		}
		case 5:{
			Yansima();
			break;
		}
		case 6:{
			Meyillendirme();
			break;
		}
		case 7:{
			Menu();
			break;
		}
		default:{
			printf("Hatali Deger!!!");	
			break;
		}
	}
	HareketMenu();
}

//Not1: ZamanYeterse Bunlara da Aynisi Uygulanacak.
//Not2: Guncelleme Fonksiyonu Sikinti Cikardi...
void Oteleme(){
	EkranTemizle();

}

void Dondurme(){
	EkranTemizle();
	
}

void Olceklendirme(){
	EkranTemizle();
}

void BirlesikDonusumler(){
	EkranTemizle();
}

void Yansima(){
	EkranTemizle();
}

void Meyillendirme(){
	EkranTemizle();
}


void EkranZoom(){
	EkranTemizle();	
}

void SekilSilme(){
	EkranTemizle();
}

//Baslangic ve Bitis kordinati alip dizide bu bolumler txt dosyasýna yazdiriliyor
void Kirpma(){
	EkranTemizle();
	dosyaKontrol = fopen("Grafik.txt","w");
	bool secim = false;
	printf("0-Kirpma\n1-Eski Hal\n Secim:");
	scanf("%i",&secim);
	switch(secim){
		case false:{
			int BaslangicKordinat[2],BitisKordinat[2];
			printf("ilk Kordinati Girin:");
			scanf("%d,%d",&BaslangicKordinat[0],&BaslangicKordinat[1]);
			printf("ilk Kordinati Girin:");
			scanf("%d,%d",&BitisKordinat[0],&BitisKordinat[1]);
			BaslangicKordinat[1] = (-BaslangicKordinat[1]);
			BitisKordinat[1] = (-BitisKordinat[1]);
			for(int i=BaslangicKordinat[1];i<=BitisKordinat[1];i++){
				for(int j=BaslangicKordinat[0];j<=BitisKordinat[0];j++){
					if(harita[i+199][j+199] == ' '){
						if(i==0 || j==0){
							harita[i+199][j+199]='$';
						}else{
							harita[i+199][j+199]='*';	
						}	
					}
				fprintf(dosyaKontrol,"%c%c",harita[i+199][j+199],harita[i+199][j+199]);	
				}
			fprintf(dosyaKontrol,"\n");
			}
			printf("Basasriyla Kirpilmistir!!");
			break;
		}
		case true:{
			HaritaCizdir();
			printf("Islem Geri Alinmistir..");
			break;
		}
		default:{
			printf("Hatali Deger!!\n");
			break;
		}
	}
	getchar();
	getchar();
	fclose(dosyaKontrol);
}
