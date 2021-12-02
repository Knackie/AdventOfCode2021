#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream fichier("input.txt");
	vector <string> number;
	int forward = 0;
	int depth = 0;

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
		if (number[i].size() == 9)
		{
			forward += atoi(number[i][8]);
		}

	}
	cout << forward << endl;
	return 0;
}

