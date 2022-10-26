#include "Library.h"

int Knihovna::dejmirok(){return(rok);}
int Knihovna::dejmicislo(){return (cislo);}
string Knihovna::dejmivydavatel(){return(vydavatel);}
string Knihovna::dejminazev(){return(nazev);}
string Knihovna::dejmizanr(){return (zanr);}
string Knihovna::dejmientry(){return (datumVlozeni);}
string Knihovna::dejmiautor(){return (autor);}
void Knihovna::nastavRok(int r){rok = r;}
void Knihovna::nastavcislo(int c){cislo = c;}
void Knihovna::nastavvydavatel(string v){vydavatel = v;}
void Knihovna::nastavnazev(string n){nazev = n;}
void Knihovna::nastavzanr(string z){zanr = z;}
void Knihovna::nastaventry(string z){datumVlozeni = z;}
void Knihovna::nastavautor(string a){autor = a;}
Casopis::Casopis(){cout << "casopis created" << endl;}
Casopis::~Casopis(){cout << "casopis destroyed" << endl;}
Kniha::Kniha(){/* cout << "kniha created" << endl; */}
Kniha::~Kniha(){/* cout << "kniha destroyed" << endl; */}
void uppercaseNazevCasopis(vector<Casopis>& casaky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < casaky.size(); i++)
	{
		str = casaky[i].dejminazev();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		casaky[i].nastavnazev(str2);
	}
}
void uppercaseVydavatelCasopis(vector<Casopis>& casaky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < casaky.size(); i++)
	{
		str = casaky[i].dejmivydavatel();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		casaky[i].nastavvydavatel(str2);
	}
}
void uppercaseZanrCasopis(vector<Casopis>& casaky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < casaky.size(); i++)
	{
		str = casaky[i].dejmizanr();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		casaky[i].nastavzanr(str2);
	}
}
void uppercaseNazevKniha(vector<Kniha>& knizky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < knizky.size(); i++)
	{
		str = knizky[i].dejminazev();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		knizky[i].nastavnazev(str2);
	}
}
void uppercaseAutorKniha(vector<Kniha>& knizky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < knizky.size(); i++)
	{
		str = knizky[i].dejmiautor();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		knizky[i].nastavautor(str2);
	}
}
void uppercaseVydavatelKniha(vector<Kniha>& knizky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < knizky.size(); i++)
	{
		str = knizky[i].dejmivydavatel();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		knizky[i].nastavvydavatel(str2);
	}
}
void uppercaseZanrKniha(vector<Kniha>& knizky)
{
	string str, str2;
	char c, h;
	for (unsigned int i = 0; i < knizky.size(); i++)
	{
		str = knizky[i].dejmizanr();
		for (unsigned int j = 0; j < str.length(); j++)
		{
			if (j == 0)
			{
				c = toupper(str[j]);
				str2 = c;
			}
			else
			{
				h = tolower(str[j]);
				str2 += h;
			}
		}
		knizky[i].nastavzanr(str2);
	}
}
void pripravSaveCasopis( vector<Casopis>& casaky)
{
	uppercaseNazevCasopis(casaky);
	uppercaseVydavatelCasopis(casaky);
	uppercaseZanrCasopis(casaky);
	if(casaky.empty())
	{
		cout << "There is nothing to save" << endl;
	}
	else
	{
			fstream file;
			file.open("Casopisy.txt", ios::out|ios::trunc);
			if (!"Casopisy.txt") 
			{
				cout << "File not created!";
			}
			else 
			{	
				for (unsigned int i = 0; i < casaky.size(); i++)
				{	
					string nazev = casaky[i].dejminazev();
					string temp = "";
					for (unsigned int j = 0; j < nazev.size(); j++)
					{
						if (nazev[j] != ' ')
						{
							temp += nazev[j];
						}
						else
						{
							temp += ";";
						}
					}
					string vydavatel = casaky[i].dejmivydavatel();
					string temp1 = "";
					for (unsigned int j = 0; j < vydavatel.size(); j++)
					{
						if (vydavatel[j] != ' ')
						{
							temp1 += vydavatel[j];
						}
						else
						{
							temp1 += ";";
						}
					}
					string zanr = casaky[i].dejmizanr();
					string temp2 = "";
					for (unsigned int j = 0; j < zanr.size(); j++)
					{
						if (zanr[j] != ' ')
						{
							temp2 += zanr[j];
						}
						else
						{
							temp2 += ";";
						}
					}
					string a = temp;
					string b = temp1;
					string c = temp2;
					int d = casaky[i].dejmirok();
					int e = casaky[i].dejmicislo();
					string f = casaky[i].dejmientry();
					file << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;     
				} 
			    //cout << "File created successfully!" << endl;
            }
			file.close();	
	}
}
void pripravLoadCasopis(vector<Casopis>& casaky, Casopis& casak)
{	
	casaky.clear();
    int i = 0;
	string word, v;
	fstream file;
	file.open("Casopisy.txt");
			while (file >> word)
			{			
				++i;
				if (i==1)
				{ 
					casaky.push_back(casak);

					string name = word;
					string temp = "";
					for (unsigned int i = 0; i < name.size(); i++)
					{
						if (name[i] != ';')
						{
							temp += name[i];
						}
						else
						{
							temp += " ";
						}
					}
					casaky.back().nastavnazev(temp);
				}
				if (i==2)
				{
					string vydavatel = word;
					string temp1 = "";
					for (unsigned int i = 0; i < vydavatel.size(); i++)
					{
						if (vydavatel[i] != ';')
						{
							temp1 += vydavatel[i];
						}
						else
						{
							temp1 += " ";
						}
					}
					casaky.back().nastavvydavatel(temp1);		
				}
				if (i == 3)
				{
					string zanr = word;
					string temp2 = "";
					for (unsigned int i = 0; i < zanr.size(); i++)
					{
						if (zanr[i] != ';')
						{
							temp2 += zanr[i];
						}
						else
						{
							temp2 += " ";
						}
					}
					casaky.back().nastavzanr(temp2);		
				}
				if (i == 4)
				{
					casaky.back().nastavRok(stoi(word));
				}
				if (i == 5)
				{					
					casaky.back().nastavcislo(stoi(word));
				}
				if(i >= 6 && i <= 8)
				{
					v += word;
					v += " ";
				}	
				if (i == 8)
				{
					casaky.back().nastaventry(v);
					i = 0;
					v.erase();
				}
			}
	file.close();
}
void pripravSaveKniha(vector<Kniha>& knizky)
{
	uppercaseNazevKniha(knizky);
	uppercaseAutorKniha(knizky);
	uppercaseVydavatelKniha(knizky);
	uppercaseZanrKniha(knizky);
	if(knizky.empty())
	{
		cout << "There is nothing to save" << endl;
	}
	else
	{
			fstream file;
			file.open("Knihy.txt", ios::out|ios::trunc);
			if (!"Knihy.txt") 
			{
				cout << "File not created!";
			}
			else 
			{	
				for (unsigned int i = 0; i < knizky.size(); i++)
				{	
					string nazev = knizky[i].dejminazev();
					string temp = "";
					for (unsigned int j = 0; j < nazev.size(); j++)
					{
						if (nazev[j] != ' ')
						{
							temp += nazev[j];
						}
						else
						{
							temp += ";";
						}
					}
					string autor = knizky[i].dejmiautor();
					string temp1 = "";
					for (unsigned int j = 0; j < autor.size(); j++)
					{
						if (autor[j] != ' ')
						{
							temp1 += autor[j];
						}
						else
						{
							temp1 += ";";
						}
					}
					string vydavatel = knizky[i].dejmivydavatel();
					string temp2 = "";
					for (unsigned int j = 0; j < vydavatel.size(); j++)
					{
						if (vydavatel[j] != ' ')
						{
							temp2 += vydavatel[j];
						}
						else
						{
							temp2 += ";";
						}
					}
					string zanr = knizky[i].dejmizanr();
					string temp3 = "";
					for (unsigned int j = 0; j < zanr.size(); j++)
					{
						if (zanr[j] != ' ')
						{
							temp3 += zanr[j];
						}
						else
						{
							temp3 += ";";
						}
					}
					string a = temp;
					string b = temp1;
					string c = temp2;
					string d = temp3;
					int e = knizky[i].dejmirok();
					string f = knizky[i].dejmientry();
					file << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;     
				} 
            }
			file.close();	
	}
}
void pripravLoadKniha(vector<Kniha>& knizky, Kniha& knizka)
{
	knizky.clear();
    int i = 0;
	string word, v;
	fstream file;
	file.open("Knihy.txt");
			while (file >> word)
			{			
				++i;
				if (i==1)
				{ 
					knizky.push_back(knizka);
					string name = word;
					string temp = "";
					for (unsigned int i = 0; i < name.size(); i++)
					{
						if (name[i] != ';')
						{
							temp += name[i];
						}
						else
						{
							temp += " ";
						}
					}
					knizky.back().nastavnazev(temp);
				}
				if (i==2)
				{
					string autor = word;
					string temp1 = "";
					for (unsigned int i = 0; i < autor.size(); i++)
					{
						if (autor[i] != ';')
						{
							temp1 += autor[i];
						}
						else
						{
							temp1 += " ";
						}
					}
					knizky.back().nastavautor(temp1);
				}
				if (i == 3)
				{
					string vydavatel = word;
					string temp2 = "";
					for (unsigned int i = 0; i < vydavatel.size(); i++)
					{
						if (vydavatel[i] != ';')
						{
							temp2 += vydavatel[i];
						}
						else
						{
							temp2 += " ";
						}
					}
					knizky.back().nastavvydavatel(temp2);
				}
				if (i == 4)
				{
					string zanr = word;
					string temp3 = "";
					for (unsigned int i = 0; i < zanr.size(); i++)
					{
						if (zanr[i] != ';')
						{
							temp3 += zanr[i];
						}
						else
						{
							temp3 += " ";
						}
					}
					knizky.back().nastavzanr(temp3);						}
				if (i == 5)
				{					
					knizky.back().nastavRok(stoi(word));
				}
				if(i >= 6 && i <= 8)
				{
					v += word;
					v += " ";
				}	
				if (i == 8)
				{
					knizky.back().nastaventry(v);
					i = 0;
					v.erase();
				}
			}
	file.close();
}
void newEntryCasopis(Casopis& casak)
{
		string v;
		cin.clear();
		cin.ignore();
		cout << "Magazin name?" << endl;	getline(cin, v);
		casak.nastavnazev(v);
		cout << "Publisher?" << endl;		getline(cin, v);
		casak.nastavvydavatel(v);
		cout << "Genre?" << endl;			getline(cin, v);
		casak.nastavzanr(v);
		cout << "Year of issue?" << endl;	cin >> v; casak.nastavRok(stoi(v));
		cout << "Issue number?" << endl;	cin >>v; casak.nastavcislo(stoi(v));
	time_t mujcas = time(NULL);
	string str = ctime(&mujcas);
	string a, b, c, d;
	for (int i = 4; i <=6; i++){a += str.at(i);}
	for (int i = 8; i <=9; i++){b += str.at(i);}	
	for (int i = 11; i <=18; i++){c += str.at(i);}	
	d = b + " " + a + " " + c + " " ;
	casak.nastaventry(d);
}
void newEntryKniha(Kniha& knizka)
{
	string v;
		cin.clear();
		cin.ignore();
		cout << "Book name?" << endl;	    getline(cin, v);
		knizka.nastavnazev(v);
		cout << "Author?" << endl;	        getline(cin, v);
		knizka.nastavautor(v);
		cout << "Publisher?" << endl;		getline(cin, v);
		knizka.nastavvydavatel(v);
		cout << "Genre?" << endl;			getline(cin, v);
		knizka.nastavzanr(v);
		cout << "Year of issue?" << endl;	cin >> v; knizka.nastavRok(stoi(v));
	time_t mujcas = time(NULL);
	string str = ctime(&mujcas);
	string a, b, c, d;
	for (int i = 4; i <=6; i++){a += str.at(i);}
	for (int i = 8; i <=9; i++){b += str.at(i);}	
	for (int i = 11; i <=18; i++){c += str.at(i);}	
	d = b + " " + a + " " + c + " " ;
	knizka.nastaventry(d);	
}
void vypisCasopis( vector<Casopis>& casaky)
	{
	    if(casaky.size())
		{	cout << " " << "************************************************"
				<< "***********************************" << endl << " " 
				<< "Magazin         "    << "Publisher       "
				<< "Genre           "      << "Year      "
				<< "Issue     " << "Date of entry" << endl << " " << "*********************"
				<< "**************************************************************" << endl; 
			for (unsigned int i = 0; i < casaky.size(); i++)
			{
				string mezera(15 - casaky[i].dejminazev().length(), ' ');
				cout << " " << casaky[i].dejminazev() << mezera;
				string mezera2(15 - casaky[i].dejmivydavatel().length(), ' ');
				cout << " " << casaky[i].dejmivydavatel() << mezera2;
				string mezera3(15 - casaky[i].dejmizanr().length(), ' ');
				cout << " " << casaky[i].dejmizanr() << mezera3;
				string x = to_string(casaky[i].dejmirok());
				string mezera4(9 - x.length(), ' ');	
				cout << " " << casaky[i].dejmirok() << mezera4;
				string y = to_string(casaky[i].dejmicislo());
				string mezera5(9 - y.length(), ' ');
				cout << " " << casaky[i].dejmicislo() << mezera5; 
				cout << " " << casaky[i].dejmientry() << endl;
	        }
			cout << " " << "*****************************************"
				<< "******************************************" << endl;
	    }
		else {cout << "Nothing to view" << endl;}
    }
void vypisKniha( vector<Kniha>& knizky)
{
	if(knizky.size())
	{	cout << " " << "************************************************"
			<< "***********************************" << endl << " " 
			<< "Book          "    << "Author        "
			<< "Publisher     "      << "Genre        "
			<< "Year      " << "Date of entry" << endl << " " << "*********************"
			<< "**************************************************************" << endl; 
		for (unsigned int i = 0; i < knizky.size(); i++)
		{
			string mezera(13 - knizky[i].dejminazev().length(), ' ');
			cout << " " << knizky[i].dejminazev() << mezera;
			string mezera2(13 - knizky[i].dejmiautor().length(), ' ');
			cout << " " << knizky[i].dejmiautor() << mezera2;
			string mezera3(13 - knizky[i].dejmivydavatel().length(), ' ');
			cout << " " << knizky[i].dejmivydavatel() << mezera3;
			string mezera4(13 - knizky[i].dejmizanr().length(), ' ');
			cout << " " << knizky[i].dejmizanr() << mezera4;
			string x = to_string(knizky[i].dejmirok());
			string mezera5(8 - x.length(), ' ');	
			cout << " " << knizky[i].dejmirok() << mezera5;
			cout << " " << knizky[i].dejmientry() << endl;
		}
		cout << " " << "*****************************************"
			<< "******************************************" << endl;
	}
	else {cout << "Nothing to view" << endl;}
}
void razeniNazevCasopis(vector<Casopis>& casaky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < casaky.size(); j++)
	{
		for (unsigned int i = 0; i < casaky.size()-1; i++)
		{		
			     if(x == 1 && casaky[i].dejminazev() > casaky[i+1].dejminazev()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
	        else if(x == 2 && (casaky[i].dejminazev()) < casaky[i+1].dejminazev()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
		}
	}	
}
void razeniVydavatelCasopis(vector<Casopis>& casaky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < casaky.size(); j++)
	{
		for (unsigned int i = 0; i < casaky.size()-1; i++)
		{		
			     if(x == 1 && casaky[i].dejmivydavatel() > casaky[i+1].dejmivydavatel()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
	        else if(x == 2 && (casaky[i].dejmivydavatel()) < casaky[i+1].dejmivydavatel()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
		}
	}	
}
void razeniZanrCasopis(vector<Casopis>& casaky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < casaky.size(); j++)
	{
		for (unsigned int i = 0; i < casaky.size()-1; i++)
		{		
			     if(x == 1 && casaky[i].dejmizanr() > casaky[i+1].dejmizanr()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
	        else if(x == 2 && (casaky[i].dejmizanr()) < casaky[i+1].dejmizanr()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
		}
	}	
}
void razeniRokCasopis(vector<Casopis>& casaky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < casaky.size(); j++)
	{
		for (unsigned int i = 0; i < casaky.size()-1; i++)
		{		
			     if(x == 1 && casaky[i].dejmirok() > casaky[i+1].dejmirok()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
	        else if(x == 2 && casaky[i].dejmirok() < casaky[i+1].dejmirok()){iter_swap (casaky.begin()+i, casaky.begin()+i+1);}
		}
	}	
}
void razeniNazevKniha(vector<Kniha>& knizky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < knizky.size(); j++)
	{
		for (unsigned int i = 0; i < knizky.size()-1; i++)
		{		
			     if(x == 1 && knizky[i].dejminazev() > knizky[i+1].dejminazev()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
	        else if(x == 2 && (knizky[i].dejminazev()) < knizky[i+1].dejminazev()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
		}
	}	
}
void razeniAutorKniha(vector<Kniha>& knizky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < knizky.size(); j++)
	{
		for (unsigned int i = 0; i < knizky.size()-1; i++)
		{		
			     if(x == 1 && knizky[i].dejmiautor() > knizky[i+1].dejmiautor()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
	        else if(x == 2 && (knizky[i].dejmiautor()) < knizky[i+1].dejmiautor()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
		}
	}	
}
void razeniZanrKniha(vector<Kniha>& knizky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < knizky.size(); j++)
	{
		for (unsigned int i = 0; i < knizky.size()-1; i++)
		{		
			     if(x == 1 && knizky[i].dejmizanr() > knizky[i+1].dejmizanr()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
	        else if(x == 2 && (knizky[i].dejmizanr()) < knizky[i+1].dejmizanr()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
		}
	}	
}
void razeniRokKniha(vector<Kniha>& knizky)
{
	int x = 0;
	cout << "1: Ascending" << endl << "2: Descending" << endl << endl;
	cin >> x;	
	for (unsigned int j = 0; j < knizky.size(); j++)
	{
		for (unsigned int i = 0; i < knizky.size()-1; i++)
		{		
			     if(x == 1 && knizky[i].dejmirok() > knizky[i+1].dejmirok()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
	        else if(x == 2 && knizky[i].dejmirok() < knizky[i+1].dejmirok()){iter_swap (knizky.begin()+i, knizky.begin()+i+1);}
		}
	}	
}
void smazaniCasopis(vector<Casopis>& casaky)
{
	int x, y;
	unsigned int i, j, k;
	vector<int> pozicevektoru;
	vector<int> pozicevektoru2;
	string a, b, c;
	cout << "Name of magazine to delete?" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, a);
	for (i = 0; i < casaky.size(); i++)
	{
		if (a == casaky[i].dejminazev())
		{
			pozicevektoru.push_back(i);
		}
	}	
		if (pozicevektoru.size() > 1)
		{
			cout << "Year?" << endl;
			getline(cin, b);
			x = stoi(b);
			for (j = 0; j < pozicevektoru.size(); j++)
			{
				if (x == casaky[pozicevektoru[j]].dejmirok())
				{
					pozicevektoru2.push_back(j);
				}
			}
			if (pozicevektoru2.size() > 1)
			{
				cout << "Issue?" << endl;
				getline(cin, c);
				y = stoi(c);
				for (k = 0; k < pozicevektoru2.size(); k++)
				{
					if (y == casaky[pozicevektoru[pozicevektoru2[k]]].dejmicislo())
					{
						casaky.erase(casaky.begin() + pozicevektoru[pozicevektoru2[k]]);
					}
				}
			}
			if (pozicevektoru2.size() == 1)
			{
				casaky.erase(casaky.begin() + pozicevektoru[pozicevektoru2[0]]);
			}
		}
		if (pozicevektoru.size() == 1)
		{
			casaky.erase(casaky.begin() + pozicevektoru[0]);
		}
}
void smazaniKniha(vector<Kniha>& knizky)
{
	int y;
	unsigned int i, j, k;
	vector<int> pozicevektoru;
	vector<int> pozicevektoru2;
	string a, b, c;
	cout << "Name of book to delete?" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, a);
	for (i = 0; i < knizky.size(); i++)
	{
		if (a == knizky[i].dejminazev())
		{
			pozicevektoru.push_back(i);
		}
	}	
		if (pozicevektoru.size() > 1)
		{
			cout << "Author?" << endl;
			getline(cin, b);
			//x = stoi(b);
			for (j = 0; j < pozicevektoru.size(); j++)
			{
				if (b == knizky[pozicevektoru[j]].dejmiautor())
				{
					pozicevektoru2.push_back(j);
				}
			}
			if (pozicevektoru2.size() > 1)
			{
				cout << "Year?" << endl;
				getline(cin, c);
				y = stoi(c);
				for (k = 0; k < pozicevektoru2.size(); k++)
				{
					if (y == knizky[pozicevektoru[pozicevektoru2[k]]].dejmirok())
					{
						knizky.erase(knizky.begin() + pozicevektoru[pozicevektoru2[k]]);
					}
				}
			}
			if (pozicevektoru2.size() == 1)
			{
				knizky.erase(knizky.begin() + pozicevektoru[pozicevektoru2[0]]);
			}
		}
		if (pozicevektoru.size() == 1)
		{
			knizky.erase(knizky.begin() + pozicevektoru[0]);
		}
}
int giveMeInt()
{	
	string x;
	int loop = 1;
	unsigned int i = 0;
	while(loop)
	{
		int wrong = 0;
		cin >> x;
		for (i = 0; i < x.size(); ++i)
		{
			if (isdigit(x[i]))	continue;
			else wrong++;
		}
		if (i == x.size() && wrong > 0) 
		{
			cout << "Try again!" << endl;
			loop = 1; 
		}
		else
			loop = 0;
	}
	int vrat = stoi(x);
	return vrat;
}