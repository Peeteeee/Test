#include "Library.h"
#include "Library.cpp"

int main()
{
	vector<Casopis> casaky;
	vector<Kniha> knizky;
	Casopis casak;
	Kniha knizka;
	casaky.clear();
	pripravLoadCasopis(casaky, casak);
	knizky.clear();
	pripravLoadKniha(knizky, knizka);
	int konec = 1;
	while (konec)
	{	
		int koneccasopis = 1;
		int koneckniha = 1;
		cout << endl << "***********" << endl << " MAIN MENU" << endl << "***********" 
	         << endl << " 0: Exit" << endl << " 1: Magazine"  << endl 
			 << " 2: Book" << endl << endl;
		switch (giveMeInt())
		{
			case (0):
			{
					konec = 0;
					break;
			}		
			case (1):
			{			
				while(koneccasopis)
				{
					vypisCasopis(casaky);
					cout << endl << "***********" << endl << " MAGAZINES" << endl << "***********" << endl << " 0: Exit" 
					     << endl << " 1: Entry" << endl << " 2: Sort"  << endl << " 3: Erase"  << endl << endl;
					switch (giveMeInt())
					{
						case (0):
								koneccasopis = 0;
								break;
						case (1):
								casaky.push_back(casak);
								newEntryCasopis(casaky.back());
								pripravSaveCasopis( casaky);
								break;
						case (2):
								cout << "******************" << endl << "SORTING PARAMETR" << endl 
								     << "******************" << endl << " 1: Name" << endl 
									 << " 2: Publisher" << endl << " 3: Genre" << endl << " 4: Year" << endl;
								{
									int volbicka = giveMeInt();
									if (volbicka == 1){razeniNazevCasopis(casaky);}
									if (volbicka == 2){razeniVydavatelCasopis(casaky);}
									if (volbicka == 3){razeniZanrCasopis(casaky);}
									if (volbicka == 4){razeniRokCasopis(casaky);}
								}
								pripravSaveCasopis(casaky);
								break;
						case (3):
								smazaniCasopis(casaky);
								pripravSaveCasopis(casaky);
								break;				
						default:
								break;
					}
				}
				break;
			}	
			case (2):
			{
				while (koneckniha)
				{	
					vypisKniha(knizky);
					cout << endl << "*******" << endl << " BOOKS" << endl << "*******" << endl 
					     << " 0: Exit" << endl << " 1: Entry" << endl << " 2: Sort"  << endl 
						 << " 3: Erase" << endl << endl;
					switch (giveMeInt())
					{
						case (0):
						{		
								koneckniha = 0;
								break;
						}
						case (1):
								knizky.push_back(knizka);
								newEntryKniha(knizky.back());
								pripravSaveKniha(knizky);
								break;
						case (2):
								cout << " 1: Name" << endl << " 2: Author" 
								     << endl << " 3: Genre" << endl << " 4: Year" 
								     << endl;
								{
									int volbicka = giveMeInt();
									if (volbicka == 1){razeniNazevKniha(knizky);}
									if (volbicka == 2){razeniAutorKniha(knizky);}
									if (volbicka == 3){razeniZanrKniha(knizky);}
									if (volbicka == 4){razeniRokKniha(knizky);}
								}
								pripravSaveKniha(knizky);
								break;	
						case (3):
								smazaniKniha(knizky);
								pripravSaveKniha(knizky);
								break;	
						default:
								break;		
					}
				}
				break;
			}		
			default:
					break;
		}				
	}
return 0;
}
