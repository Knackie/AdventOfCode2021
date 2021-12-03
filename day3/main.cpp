#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream fichier("input.txt");
	vector <int> nbz;
	vector <int> nbu;
	for (int i =0;i<12;i++)
	{
	nbz.push_back(0);
	nbu.push_back(0);
	}
	vector <string> number;
	int forward = 0;
	int depth = 0;
	string finalnb = "";

	if (fichier)
	{
		//L'ouverture s'est bien passée, on peut donc lire

		string ligne; //Une variable pour stocker les lignes lues

		while (getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
			number.push_back(ligne);
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	cout << "end read of file \n"; 

	for (int i = 0; i < number.size(); i++)
	{
		for (int j = 0; j < 12 ; j++)
		{
			if (number[i][j]=='0')
			{
				nbz[j]++;	
			}
			else
			{
				nbu[j]++;	
			}
		}

	}

	for ( int i = 0; i < nbz.size(); i++)
	{
		if (nbu[i]>nbz[i])
		{
			finalnb += "1"; 	
		}
		else
		{
			finalnb += "0"; 	
		}	
	}
	cout << finalnb << endl;
	return 0;
}

