
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Mountain/Mountain.h"
using std::string;
using std::vector;

void operacoesGrafo();
int main(int argc, char **argv) {
int opcao = 0;
//Mountain myMountain("G.txt");

	do
	{
		cout << "1. Carregar ficheiro" << endl;
		cout << "2. Dar instrucoes" << endl;

		cin >> opcao;
	}while(opcao != 1 && opcao != 2);



if(opcao == 1) Mountain myMountain("G.txt");
else operacoesGrafo();

}


void operacoesGrafo()
{
	Mountain myMountain;
	int opcao;
	string str,str2;
	int num;
do{
	cout << endl <<  "1. Adicionar ponto com turistas" << endl;
	cout << "2. Adicionar ponto com veiculo" << endl;
	cout << "3. Remover ponto" << endl;
	cout << "4. Adicionar caminho entre dois pontos com peso" << endl;
	cout << "5. Remover caminho entre dois pontos" << endl;
	cout << "0. Terminado" << endl;
	cin >> opcao;
	switch(opcao)
	{
	case 1:
		cout << "Qual o nome do ponto? " ;
		cin>> str;
		cout << endl << "Quantos turistas? ";
		cin >> num;

		myMountain.addTouristPoint(str,num);
		break;

	case 2:
		cout << "Qual o nome do ponto? " ;
		cin >> str;
		cout << endl << "Qual a capacidade do veiculo? ";
		cin >> num;

		myMountain.addVehiclePoint(str,num);
		break;

	case 3:
		cout << "Qual o nome do ponto a remover? ";
		cin >> str;

		myMountain.removePoint(str);
		break;

	case 4:
		cout << "Nome do primeiro ponto: ";
		cin >> str;
		cout << endl << "Nome do segundo ponto: ";
		cin >> str2;
		cout << endl << "Peso da ligacao: ";
		cin >> num;

		myMountain.addRoad(str,str2,num);
		break;

	case 5:
		cout << "Nome do primeiro ponto: ";
		cin >> str;
		cout << endl << "Nome do segundo ponto: ";
		cin >> str2;

		myMountain.removeRoad(str,str2);
		break;

	default:
		break;

	}

}while(opcao != 0);


system("pause");
}

