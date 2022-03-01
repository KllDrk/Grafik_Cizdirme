#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

typedef struct CizimTuru{
	int CizdirilenTur;
	int CizimSayisi;
	struct CizimTuru *sonraki;
}Cizim;

	Cizim *ilkCizim = NULL, *sonCizim = NULL, *yeniCizim, *silGeciciCizim, *geciciCizim;
	int CizdirilenTur=0,CizimSayisi=0;
	bool Cizdirilebilirlik=true;

typedef struct Polinom{
	int CizimSayisiPolinom;
	int KatSayiPolinom[50];
	int DerecePolinom[50];
	int BaslangicKordinatX;
	int BaslangicKordinatY;
	struct Polinom *sonraki;
}polinom;

	polinom *ilkPolinom = NULL, *sonPolinom = NULL, *yeniPolinom, *silGeciciPolinom, *geciciPolinom;
	int CizimSayisiPolinom=0,KatSayiPolinom[50],DerecePolinom[50],BaslangicKordinatX=0,BaslangicKordinatY=0;

typedef struct Disk{
	int CizimSayisiDisk;
	int EliptikYariCaplar[2];
	int CapMerkezKordinatX;
	int CapMerkezKordinatY;
	struct Disk *sonraki;
}disk;

	disk *ilkDisk = NULL, *sonDisk = NULL, *yeniDisk, *silGeciciDisk, *geciciDisk;
	int CizimSayisiDisk=0,EliptikYariCaplar[2],CapMerkezKordinatX=0,CapMerkezKordinatY=0;

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
	
typedef struct Dortgen{
	int CizimSayisiDortgen;
	int BaslangicKordinatX;
	int BaslangicKordinatY;
	int KenarUzunluklari[2];
	bool DolulukDortgen;
	struct Dortgen *sonraki;
}dortgen;

	dortgen *ilkDortgen = NULL, *sonDortgen = NULL, *yeniDortgen, *silGeciciDortgen, *geciciDortgen;
	int CizimSayisiDortgen=0,BaslangicKordinatDortenX=0,BaslangicKordinatDortgenY=0,KenarUzunluklari[2];
	bool DolulukDortgen=false;
	
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
	int CizimSayisiEliptik=0,KatSayiX=0,KatSayiY=0,CapMerkezKordinatEliptikX=0,CapMerkezKordinatEliptikY=0,EliptikYariCap=0;
	bool DolulukEliptik=false;
		
typedef struct Poligon{
	
}poligon;

typedef struct Yildiz{
	
}yildiz;


char harita[399][399];
bool kontrol[7]={false,false,false,false,false,false,false};
int otelemeX=0,otelemeY=0;
int dondurmeX=0,dondurmeY=0;
FILE *dosyaKontrol;

void CizimEkle();
void CizimSil();
void CizimAra();

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
void SekilMenu();
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

void IlkHaritaCizdir(){
	dosyaKontrol = fopen("Grafik.txt","w");
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			harita[i+199][j+199]=' ';
			//printf("%c",harita[i+199][j+199]);
			fprintf(dosyaKontrol,"%c%c",harita[i+199][j+199],harita[i+199][j+199]);
		}
		fprintf(dosyaKontrol,"\n");
		//printf("\n");
	}
	fclose(dosyaKontrol);
}

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
			
			//printf("%c",harita[i+199][j+199]);
			fprintf(dosyaKontrol,"%c%c",harita[i+199][j+199],harita[i+199][j+199]);
		}
		fprintf(dosyaKontrol,"\n");
		//printf("\n");
	}
	fclose(dosyaKontrol);
}

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
}

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
 
 
            if (geciciCizim->sonraki->CizdirilenTur == CizdirilenTur && geciciCizim->sonraki->CizimSayisi == CizimSayisi) {
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


void PolinomEkle(){
	yeniPolinom = (polinom *)malloc(sizeof(polinom));
	yeniPolinom->CizimSayisiPolinom = CizimSayisiPolinom;
	yeniPolinom->BaslangicKordinatX = BaslangicKordinatX;
	yeniPolinom->BaslangicKordinatY = BaslangicKordinatY;
		for(int i=0;i<50;i++){
			yeniPolinom->DerecePolinom[i] = DerecePolinom[i];
			yeniPolinom->KatSayiPolinom[i] = KatSayiPolinom[i];
		}
	if(ilkPolinom == NULL){
		ilkPolinom = yeniPolinom;
		sonPolinom = ilkPolinom;
	}else{
		sonPolinom->sonraki = yeniPolinom;
		sonPolinom->sonraki = sonPolinom;
	}
}

void PolinomSil(){
	int kontrol = 0;
    if (ilkPolinom->CizimSayisiPolinom == CizimSayisiPolinom) {
        silGeciciPolinom = ilkPolinom;
        ilkPolinom = ilkPolinom->sonraki;
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
                free(silGeciciPolinom);
                break;
 
            }
            geciciPolinom = geciciPolinom->sonraki;
        }
    }
}

void PolinomAra(){
	int kontrol = 0;
    geciciPolinom = ilkPolinom;
    while (geciciPolinom != NULL) {
        if (geciciPolinom->CizimSayisiPolinom == CizimSayisiPolinom) {
            kontrol = 1;
        }
        geciciPolinom = geciciPolinom->sonraki;
    }
    if(kontrol==1){
    	Cizdirilebilirlik=false;
	}
}


void DiskEkle(){
	yeniDisk = (disk *)malloc(sizeof(disk));
	yeniDisk->CizimSayisiDisk = CizimSayisiDisk;
	yeniDisk->CapMerkezKordinatX = CapMerkezKordinatX;
	yeniDisk->CapMerkezKordinatY = CapMerkezKordinatY;
		for(int i=0;i<2;i++){
			yeniDisk->EliptikYariCaplar[i] = EliptikYariCaplar[i];
		}
	if(ilkDisk == NULL){
		ilkDisk = yeniDisk;
		sonDisk = ilkDisk;
	}else{
		sonDisk->sonraki = yeniDisk;
		sonDisk->sonraki = sonDisk;
	}
}

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


void UcgenEkle(){
	yeniUcgen = (Ucgen *)malloc(sizeof(Ucgen));
	yeniUcgen->CizimSayisiUcgen = CizimSayisiUcgen;
	yeniUcgen->DolulukUcgen = DolulukUcgen;
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
		sonUcgen->sonraki = sonUcgen;
	}
}

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


void DortgenEkle(){
	yeniDortgen = (Dortgen *)malloc(sizeof(Dortgen));
	yeniDortgen->CizimSayisiDortgen = CizimSayisiDortgen;
	yeniDortgen->DolulukDortgen = DolulukDortgen;
	yeniDortgen->BaslangicKordinatX = BaslangicKordinatX;
	yeniDortgen->BaslangicKordinatY = BaslangicKordinatY;
		for(int i=0;i<2;i++){	
			yeniDortgen->KenarUzunluklari[i] = KenarUzunluklari[i];	
		}
	if(ilkDortgen == NULL){
		ilkDortgen = yeniDortgen;
		sonDortgen = ilkDortgen;
	}else{
		sonDortgen->sonraki = yeniDortgen;
		sonDortgen->sonraki = sonDortgen;
	}
}

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


void EliptikEkle(){
	yeniEliptik = (Eliptik *)malloc(sizeof(Eliptik));
	yeniEliptik->CizimSayisiEliptik = CizimSayisiEliptik;
	yeniEliptik->DolulukEliptik = DolulukEliptik;
	yeniEliptik->EliptikYariCap = EliptikYariCap;
	yeniEliptik->CapMerkezKordinatX = CapMerkezKordinatX;
	yeniEliptik->CapMerkezKordinatY = CapMerkezKordinatY;
	yeniEliptik->KatSayiX = KatSayiX;
	yeniEliptik->KatSayiY = KatSayiY;
	if(ilkEliptik == NULL){
		ilkEliptik = yeniEliptik;
		sonEliptik = ilkEliptik;
	}else{
		sonEliptik->sonraki = yeniEliptik;
		sonEliptik->sonraki = sonEliptik;
	}
}

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


void Menu(){
	system("CLS");
	int secim=0;
	printf("1-Sekil Cizdirme\n2-Hareket Islemleri\n3-Zoom Islemleri\n4-Kirpma\n5-Cikis\nSecim:");
	scanf("%d",&secim);
	switch(secim){
		case 1:{
			SekilMenu();
			break;
		}
		case 2:{
			HareketMenu();
			break;
		}
		case 3:{
			EkranZoom();
			break;
		}
		case 4:{
			Kirpma();
			break;
		}
		case 5:{
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

void SekilMenu(){
	EkranTemizle();
	int secim=0;
	printf("Not:Her Sekilden yalnizca bir defa cizilebilir.\n");
	printf("1-Polinom Cizdir\n2-Disk Cizdir\n3-Ucgen Cizdir\n4-Dortgen Cizdir\n");
	printf("5-Eliptik Cizdir\n6-Poligon Cizdir\n7-Yildiz Cizdir\n8-Menuye Geri Don\nSecim:");
	scanf("%d",&secim);
	CizdirilenTur = secim;
	CizimAra();
	if(Cizdirilebilirlik==true){
		CizimEkle();
	}else{
		CizimSil();
		SekilSilme();
		CizimEkle();
	}
	if(secim != 8){
		kontrol[secim-1] = true;
	} 
	switch(secim){
		case 1:{
			PolinomCizdir();
			break;
		}
		case 2:{
			DiskCizdir();
			break;
		}
		case 3:{
			UcgenCizdir();
			break;
		}
		case 4:{
			DortgenCizdir();
			break;
		}
		case 5:{
			EliptikCizdir();
			break;
		}
		case 6:{
			PoligonCizdir();
			break;
		}
		case 7:{
			YildizCizdir();
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
	SekilMenu();	
}

void PolinomCizdir(){
	EkranTemizle();
	
}

void DiskCizdir(){
	EkranTemizle();
	bool kontrol=false;
	int yariCap=0,katSayiX1=0,katSayiY1=0,konum1=0,konum2=0;
	dosyaKontrol = fopen("Grafik.txt","w");
	
	printf("Yaricap Giriniz:");
	scanf("%d",&yariCap);
	printf("katSayiY1 Giriniz:");
	scanf("%d",&katSayiY1);
	printf("katsayiX1 Giriniz:");
	scanf("%d",&katSayiX1);
	printf("konumX Giriniz:");
	scanf("%d",&konum1);
	printf("konumY Giriniz:");
	scanf("%d",&konum2);
	konum1-=(2*konum1);
	//konum2=(-konum2);
	printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
	scanf("%i",&kontrol);
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
				if(kontrol == false ){
				if(katSayiY1*pow(i,2)+katSayiX1*pow(j,2)-pow(yariCap,2)>=-yariCap && katSayiY1*pow(i,2)+katSayiX1*pow(j,2)-pow(yariCap,2)<=yariCap){
					//printf("NN");
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							harita[i+199+konum2][j+199+konum1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}
					
				}else{
					//printf("  ");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
						harita[i+199+konum2][j+199+konum1]=' ';
						fprintf(dosyaKontrol,"  ");	
						}
						
					}
					
				}
			}else if(kontrol == true){
				if(katSayiY1*pow(i,2)+katSayiX1*pow(j,2) <= pow(yariCap,2)){
					//printf("##");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							fprintf(dosyaKontrol,"##");
							harita[i+199+konum2][j+199+konum1]='#';
						}
						
					}
					
				}else{
					//printf("  ");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							fprintf(dosyaKontrol,"  ");
							harita[i+199+konum2][j+199+konum1]=' ';	
						}
						
					}
					
				}
			}else{
				printf("Hatali Deger!");
				break;
			}
			}
			
		
		//printf("\n");
		fprintf(dosyaKontrol,"\n");
	}
	HaritaCizdir();
	getchar();
	getchar();
	fclose(dosyaKontrol);
	
	
}

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
	
	konumY1=(-konumY1);
	konumY2=(-konumY2);
	konumY3=(-konumY3);
	konumX1=(-konumX1);
	konumX2=(-konumX2);
	konumX3=(-konumX3);
	
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
	
	konumX1=(-konumX1);
	konumX2=(-konumX2);
	konumX3=(-konumX3);
	
	printf("fonkA1:%f\tfonkB1=%f\n",fonkA1,fonkB1);
	printf("fonkA2:%f\tfonkB2=%f\n",fonkA2,fonkB2);
	printf("fonkA3:%f\tfonkB3=%f\n",fonkA3,fonkB3);
	
	printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
	scanf("%i",&kontrol);
	for(int i=199;i>=-199;i--){
		for(int j=-199;j<=199;j++){
			if(kontrol==false){

				if((-i==fonkA1*j+fonkB1 &&(i<=konumY1 && i>=konumY3))){
				if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						printf("X:%d\tY:%d\n",j,i);
						if(harita[i+199+konumY1][j+199+konumX1]=='*'){
							harita[i+199+konumY1][j+199+konumX1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}	
				}else if((-i==fonkA2*j+fonkB2 &&(i<=konumY1 && i>=konumY3))){
					if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						printf("X:%d\tY:%d\n",j,i);
						if(harita[i+199+konumY1][j+199+konumX1]=='*'){
							harita[i+199+konumY1][j+199+konumX1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}
				}else if((-i==fonkA3*j+fonkB3 &&(i<=konumY1 && j>=konumY3))){
					if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						printf("X:%d\tY:%d\n",j,i);
						if(harita[i+199+konumY1][j+199+konumX1]=='*'){
							harita[i+199+konumY1][j+199+konumX1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}
				}else{
					if((i+konumY1 >199 || j+konumX1 >199 || i+konumY1 <-199 || j+konumX1 <-199)){
						continue;
					}else{
						if(harita[i+199+konumY1][j+199+konumX1]=='*'){
						harita[i+199+konumY1][j+199+konumX1]=' ';
						fprintf(dosyaKontrol,"  ");	
						}
						
					}
				
				}	
				
				}
				
				else if(kontrol == true){
					int sayac=0;
					if(harita[i+199][j+199]=='N'){
						printf("%c%c",harita[i+199][j+199],harita[i+199][j+199]);	
					}else{
						printf("  ");
					}
					if(harita[i+199][j+199]=='N'){
						sayac++;
					}
					switch(sayac%4){
						case 0:{
							harita[i+199][j+199]=' ';
							fprintf(dosyaKontrol,"  ");
							break;
						}
						case 1:{
							harita[i+199][j+199]='#';
							fprintf(dosyaKontrol,"##");
							break;
						}
						case 2:{
							harita[i+199][j+199]='#';
							fprintf(dosyaKontrol,"##");
							break;
						}
						case 3:{
							harita[i+199][j+199]=' ';
							fprintf(dosyaKontrol,"  ");
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
}

void DortgenCizdir(){
	EkranTemizle();
	bool kontrol=false;
	int birinciKenar=0,ikinciKenar=0,konum1=0,konum2=0;
	dosyaKontrol = fopen("Grafik.txt","w");
	
	printf("Birinci Kenari Giriniz:");
	scanf("%d",&birinciKenar);
	printf("Ikinci Kenari Giriniz:");
	scanf("%d",&ikinciKenar);
	printf("KonumX Giriniz:");
	scanf("%d",&konum1);
	printf("KonumY Giriniz:");
	scanf("%d",&konum2);
	konum1=(-konum1);
	konum2=(-konum2);
	printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
	scanf("%i",&kontrol);
	
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
			if(kontrol==false){
				if((konum1==j || konum1+birinciKenar==j) && (konum2<=i && konum2+ikinciKenar>=i)){
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							harita[i+199+konum2][j+199+konum1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}
				}else if((konum2==i || konum2+ikinciKenar==i)&& (konum1<=j && konum1+birinciKenar>=j)){
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							harita[i+199+konum2][j+199+konum1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}
				}else{
					//printf("  ");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
						harita[i+199+konum2][j+199+konum1]=' ';
						fprintf(dosyaKontrol,"  ");	
						}
						
					}
					
				}
			}else if(kontrol==true){
				
				if((konum1<=j && konum1+birinciKenar>=j) && (konum2<=i && konum2+ikinciKenar>=i)){
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							harita[i+199+konum2][j+199+konum1]='#';
							fprintf(dosyaKontrol,"##");
						}
						
					}
				}else{
					//printf("  ");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
						harita[i+199+konum2][j+199+konum1]=' ';
						fprintf(dosyaKontrol,"  ");	
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
	getchar();
	fclose(dosyaKontrol);
}

void EliptikCizdir(){
	EkranTemizle();
	bool kontrol=false;
	int yariCap=0,katSayiX=0,katSayiY=0,konum1=0,konum2=0;
	dosyaKontrol = fopen("Grafik.txt","w");
	
	printf("Yaricap Giriniz:");
	scanf("%d",&yariCap);
	printf("katSayiY Giriniz:");
	scanf("%d",&katSayiY);
	printf("katsayiX Giriniz:");
	scanf("%d",&katSayiX);
	printf("konumX Giriniz:");
	scanf("%d",&konum1);
	printf("konumY Giriniz:");
	scanf("%d",&konum2);
	//konum1=(-konum1);
	konum2=(-konum2);
	printf("Icý Bos mu Dolu mu olacak?\nNot:Ici bos icin 0,dolu icin 1 basýn.\n");
	scanf("%i",&kontrol);
	for(int i=-199;i<=199;i++){
		for(int j=-199;j<=199;j++){
				if(kontrol == false ){
				if(katSayiY*pow(i,2)+katSayiX*pow(j,2)-pow(yariCap,2)>=-yariCap && katSayiY*pow(i,2)+katSayiX*pow(j,2)-pow(yariCap,2)<=yariCap){
					//printf("NN");
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							harita[i+199+konum2][j+199+konum1]='N';
							fprintf(dosyaKontrol,"NN");
						}
						
					}
					
				}else{
					//printf("  ");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
						harita[i+199+konum2][j+199+konum1]=' ';
						fprintf(dosyaKontrol,"  ");	
						}
						
					}
					
				}
			}else if(kontrol == true){
				if(katSayiY*pow(i,2)+katSayiX*pow(j,2) <= pow(yariCap,2)){
					//printf("##");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							fprintf(dosyaKontrol,"##");
							harita[i+199+konum2][j+199+konum1]='#';
						}
						
					}
					
				}else{
					//printf("  ");
					
					if((i+konum2 >199 || j+konum1 >199 || i+konum2 <-199 || j+konum1 <-199)){
						continue;
					}else{
						if(harita[i+199+konum2][j+199+konum1]=='*'){
							fprintf(dosyaKontrol,"  ");
							harita[i+199+konum2][j+199+konum1]=' ';	
						}
						
					}
					
				}
			}else{
				printf("Hatali Deger!");
				break;
			}
			}
			
		
		//printf("\n");
		fprintf(dosyaKontrol,"\n");
	}
	HaritaCizdir();
	getchar();
	getchar();
	fclose(dosyaKontrol);
	
}

void PoligonCizdir(){
	EkranTemizle();
	
}

void YildizCizdir(){
	EkranTemizle();
}


void HareketMenu(){
	EkranTemizle();
	int secim=0;
	printf("1-Oteleme\n2-Dondurme\n3-Olceklendirme\n4-Birlesik Donusumler\n5-Yansima\n");
	printf("6-Meyillendirme\n7-Menuye Geri Donme\nSecim:");
	scanf("%d",&secim);
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
			
			break;
		}
	}
	HareketMenu();
}

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

void Kirpma(){
	EkranTemizle();
}
