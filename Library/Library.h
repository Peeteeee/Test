#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <iostream>
#include<string>
#include <vector>
#include<ctime>
#include<fstream>
#include <algorithm>
using namespace std;
class Knihovna
{
protected:	
	int cislo = 0;
	int rok = 0;
	string autor = {0};
	string nazev = {0};
	string vydavatel = {0};
	string datumVlozeni = {0};
	string zanr = {0};
public:
	virtual int dejmirok();
	virtual int dejmicislo();
	virtual string dejmivydavatel();
	virtual string dejminazev();
	virtual string dejmizanr();
	virtual string dejmientry();
	virtual string dejmiautor();
	virtual void nastavRok(int r);
	virtual void nastavcislo(int c);
	virtual void nastavvydavatel(string v);
	virtual void nastavnazev(string n);
	virtual void nastavzanr(string z);
	virtual void nastaventry(string z);
	virtual void nastavautor(string a);
};
class Casopis: public Knihovna
{
	public:
		Casopis();
		~Casopis();
};
class Kniha : public Knihovna
{
	public:
		Kniha();
		~Kniha();
};
void uppercaseNazevCasopis(vector<Casopis>& casaky);
void uppercaseVydavatelCasopis(vector<Casopis>& casaky);
void uppercaseZanrCasopis(vector<Casopis>& casaky);
void uppercaseNazevKniha(vector<Kniha>& knizky);
void uppercaseAutorKniha(vector<Kniha>& knizky);
void uppercaseVydavatelKniha(vector<Kniha>& knizky);
void uppercaseZanrKniha(vector<Kniha>& knizky);
void pripravSaveCasopis( vector<Casopis>& casaky);
void pripravLoadCasopis(vector<Casopis>& casaky, Casopis& casak);
void pripravSaveKniha(vector<Kniha>& knizky);
void pripravLoadKniha(vector<Kniha>& knizky, Kniha& knizka);
void newEntryCasopis(Casopis& casak);
void newEntryKniha(Kniha& knizka);
void vypisCasopis( vector<Casopis>& casaky);
void vypisKniha( vector<Kniha>& knizka);
void razeniNazevCasopis(vector<Casopis>& casaky);
void razeniVydavatelCasopis(vector<Casopis>& casaky);
void razeniZanrCasopis(vector<Casopis>& casaky);
void razeniRokCasopis(vector<Casopis>& casaky);
void razeniNazevKniha(vector<Kniha>& knizky);
void razeniAutorKniha(vector<Kniha>& knizky);
void razeniZanrKniha(vector<Kniha>& knizky);
void razeniRokKniha(vector<Kniha>& knizky);
int  giveMeInt();
void smazaniCasopis(vector<Casopis>& casaky);
void smazaniKniha(vector<Kniha>& knizky);
#endif