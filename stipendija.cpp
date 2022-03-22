#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
class Student{//apstraktna klasa
	protected:
		char ime[50], prezime[50], fakultet[50]; //podatocni clenovi
		string drzavjanstvo; 
		float uspeh;
		int broj_polozeni_ispiti,indeks;
		public: 
		void set(char* i, char* p,char* f, string d, float u, int br,int ind){//funckija za setiranje
			strcpy(ime,i);
			ime[0]=toupper(ime[0]);
			strcpy(prezime,p);
			prezime[0]=toupper(prezime[0]);
			strcpy(fakultet,f);
			fakultet[0]=toupper(fakultet[0]);
			drzavjanstvo=d;
			uspeh=u;
			broj_polozeni_ispiti=br;
			indeks=ind;
		}
		static float bod_uspeh;//staticki promenlivi 
		static float bodovi_faks;
		static float stipendija;
		static int bod_mp;
		float Kriterium();
		virtual float Stipendija()=0;//virtuelna funckija
		float presmetka_bodovi();
		virtual void pecati()=0;
};
float Student::bodovi_faks=0;
float Student::stipendija=0;
float Student::bod_uspeh=0;
int Student::bod_mp=0;
class grupa1:public Student{ //izvedena klasa
	public: 
	float mesecni_primanja();//prototip na funckija 
	float dopolnitelni_bodovi(){
		if(fakultet=="tehnicki" or fakultet=="medicina"){
		bodovi_faks=20;
		return bodovi_faks;}
	}
	float presmetka_bodovi(){
		bod_uspeh=uspeh*2;
		return bod_uspeh*dopolnitelni_bodovi()*mesecni_primanja();
	}
	float Kriterium(){
		if(presmetka_bodovi()<70 or broj_polozeni_ispiti<8)
		cout<<"Studentot ne moze da bide rangiran!"<<endl;
		else {
		stipendija=3300;
		return stipendija;}
	}	
	float Stipendija(){//presmetka na stipendija
		return Kriterium()*9;
	}
	void pecati(){//pecatenje 
		cout<<"Indeks: "<<indeks<<" Ime: "<<ime<<" Prezime: "<<prezime<<" Fakultet: "<<fakultet<<" Iznos na stipendija:"<<Stipendija()<<endl;
	}
};
float grupa1::mesecni_primanja(){//
	int vkupno=0; 
	int plata_majka, plata_tatko, plata_drug_clen, n, prihodi;
	cout<<"Vnesi broj na clenovi vo semejstvoto:";cin>>n; 
	cout<<"Vnesi plata na majka:";cin>>plata_majka;
	cout<<"Vnesi plata na tatko:";cin>>plata_tatko;
	cout<<"Vnesi plata na ostanan clen na semejstvo:";cin>>plata_drug_clen;
	cout<<"Vnesi dopolnitelni prihodi:";cin>>prihodi;
	vkupno=(plata_majka+plata_tatko+plata_drug_clen)/n+(prihodi/12*n);//presmetka na mesecnite primanja
	if(vkupno<10000)
	bod_mp=60;
	if(vkupno>10000 and vkupno<=20000)
	bod_mp=50;
	if(vkupno>20000 and vkupno<=30000)
	bod_mp=40;
	if(vkupno>30000 and vkupno<=40000)
	bod_mp=30;
	if(vkupno>40000 and vkupno<=50000)
	bod_mp=20;
	if(vkupno>50000)
	bod_mp=0;
	return bod_mp;
}
class grupa2:public Student{//izvedena klasa
	public: 
	float presmetka_bodovi(){	
		bod_uspeh=uspeh*10;
		return bod_uspeh;
	}
	float Kriterium(){
		if(presmetka_bodovi()>80 or broj_polozeni_ispiti>10){
			if(fakultet=="informatika" and uspeh>=9.00){
				stipendija=6050;}
			else{
				stipendija=4400;
		}return stipendija;}
		else{
			cout<<"Studentot ne moze da bide rangiran!"<<endl;
		}}
	float Stipendija(){//presmetka na stipendija
		return Kriterium()*9;
	}
	void pecati(){
		cout<<"Indeks: "<<indeks<<" Ime: "<<ime<<" Prezime: "<<prezime<<" Fakultet: "<<fakultet<<" Iznos na stipendija: "<<Stipendija()<<endl;
	}
};
class grupa3:public Student{
	public:
		float presmetka_bodovi(){
			bod_uspeh=uspeh*10;
			return bod_uspeh;
		}
		float Kriterium(){
			if(presmetka_bodovi()>80 or broj_polozeni_ispiti>10){
			if(fakultet=="matematika" and uspeh>=7.00){
					stipendija=18000;}
				else{
					stipendija=3300;
				}return stipendija;}
			else{
				cout<<"Studentot ne moze da bide rangiran!"<<endl;
			}}
		float Stipendija(){
			return Kriterium()*9;
		}
		void pecati(){
		cout<<"Indeks: "<<indeks<<" Ime: "<<ime<<" Prezime: "<<prezime<<" Fakultet: "<<fakultet<<" Iznos na stipendija: "<<Stipendija()<<endl;
	}
};

int main()
{
	Student *s;//pokazuvac
	int n, j,br, k,ind;
	string d; 
	char i[50],p[50],faks[50];
	float uspeh;
	
	cout<<"**********************************************"<<endl;
	cout<<"KATEGORII ZA STIPENDII:"<<endl;
	cout<<"1. Socijalna kategorija"<<endl;
	cout<<"2. Kategorija spored uspeh"<<endl;
	cout<<"3. Kategorija za fakulteti od naucni podracja"<<endl;
	cout<<"**********************************************"<<endl;
	cout<<"Vnesi broj na studenti:";
	cin>>n;
	grupa1 g1;
	grupa2 g2;
	grupa3 g3;
		for(j=0;j<n;j++){{//vnesuvanje na studentit 
		cout<<"Vnesi broj na indeks so maksimum 6 karakteri:";cin>>ind;
		cout<<"Vnesi ime na student:";cin>>i;
		cout<<"Vnesi prezime na student:";cin>>p;
		cout<<"Vnesi fakultet:";cin>>faks;
		cout<<"Vnesi drzavjanstvo:";cin>>d;
		cout<<"Vnesi uspeh:";cin>>uspeh;
		cout<<"Vnesi broj na polozeni ispiti:";cin>>br;}
		cout<<"Vo koja kategorija apliciral "<<j+1<<"-ot student(1 ili 2 ili 3):";
		cin>>k; 
		if(k==1){
		if(d!="makedonsko"){//proverka na drzavjanstvo
			cout<<"Ne moze da bide dodelena stipendija na student koj nema makedonsko drzavjanstvo!"<<endl;
	}
	else{
		s=&g1;//pokazuvac pokazuva na adresa na objekt od izvedena klasa
		s->set(i,p,faks,d,uspeh,br,ind);
		s->pecati();		
	}}
	if(k==2){
		if(d!="makedonsko"){
			cout<<"Ne moze da bide dodelena stipendija na student koj nema makedonsko drzavjanstvo!"<<endl;
	}
	else{
		s=&g2;
		s->set(i,p,faks,d,uspeh,br,ind);
		s->pecati();
	}
	}
	if(k==3){
		if(d!="makedonsko"){
			cout<<"Ne moze da bide dodelena stipendija na student koj nema makedonsko drzavjanstvo!"<<endl;
	}
	else{
		s=&g3;
		s->set(i,p,faks,d,uspeh,br,ind);
		s->pecati();
	}
	}}
	return 0;}
	


