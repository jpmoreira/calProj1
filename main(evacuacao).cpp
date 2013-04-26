
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Mountain/Mountain.h"
using std::string;
using std::vector;

void operacoesGrafo();
void evacuar();
Mountain *myMountain;
int main(int argc, char **argv) {
int opcao = 0;



	do
	{
		cout << "1. Carregar ficheiro" << endl;
		cout << "2. Dar instrucoes" << endl;

		cin >> opcao;
	}while(opcao != 1 && opcao != 2);



if(opcao == 1)  myMountain = new Mountain("G.txt");
else myMountain = new Mountain;


operacoesGrafo();
}


void operacoesGrafo()
{
	int opcao;
	string str,str2;
	int num;
do{
	cout << endl <<  "1. Adicionar ponto com turistas" << endl;
	cout << "2. Adicionar ponto com veiculo" << endl;
	cout << "3. Remover ponto" << endl;
	cout << "4. Adicionar caminho entre dois pontos com peso" << endl;
	cout << "5. Remover caminho entre dois pontos" << endl;
	cout << "6. Evacuar" << endl;
	cout << "0. Terminado" << endl;
	cin >> opcao;
	switch(opcao)
	{
	case 1:
		cout << "Qual o nome do ponto? " ;
		cin>> str;
		cout << endl << "Quantos turistas? ";
		cin >> num;

		myMountain->addTouristPoint(str,num);
		break;

	case 2:
		cout << "Qual o nome do ponto? " ;
		cin >> str;
		cout << endl << "Qual a capacidade do veiculo? ";
		cin >> num;

		myMountain->addVehiclePoint(str,num);
		break;

	case 3:
		cout << "Qual o nome do ponto a remover? ";
		cin >> str;

		myMountain->removePoint(str);
		break;

	case 4:
		cout << "Nome do primeiro ponto: ";
		cin >> str;
		cout << endl << "Nome do segundo ponto: ";
		cin >> str2;
		cout << endl << "Peso da ligacao: ";
		cin >> num;

		myMountain->addRoad(str,str2,num);
		break;

	case 5:
		cout << "Nome do primeiro ponto: ";
		cin >> str;
		cout << endl << "Nome do segundo ponto: ";
		cin >> str2;

		myMountain->removeRoad(str,str2);
		break;

	case 6:
		evacuar();
		break;

	default:
		break;

	}

}while(opcao != 0);

/*cout << "Primeiro: ";
cin >> str;

cout << "Segundo :";
cin >> str2;


Graph<Point> *grafo = myMountain->getGraph();
vector<Vertex<Point>*> pontos = grafo->getVertexSet();

Point *p1;
Point *p2;

for(unsigned int i = 0;i<pontos.size();i++)
{
	if(pontos[i]->getInfo().getName() == str) p1 =new Point (pontos[i]->getInfo());
	if(pontos[i]->getInfo().getName() == str2) p2 =new Point (pontos[i]->getInfo());
}
grafo->floydWarshallShortestPath();


vector<Point> caminho_mais_curto = grafo->getfloydWarshallPath(*p1,*p2);

cout << "Caminho mais curto de " << p1->getName() << " a " <<  p2->getName() << " :" << endl;

for (unsigned int i = 0;i<caminho_mais_curto.size();i++) cout << caminho_mais_curto[i].getName() << endl;

system("pause");*/

return;
}

void evacuar()
{
	Graph<Point> *grafo = myMountain->getGraph();
	vector<Vehicle> veiculos;
	grafo->floydWarshallShortestPath();
	int turistas_restantes;
	int **w = grafo->getW();

	vector<Vertex<Point>*> pontos = grafo->getVertexSet();

	for(unsigned int i = 0;i<pontos.size();i++)
	{

		int pos = -1;


			if(pontos[i]->getInfo().getVehicle() == NULL)
			{
				int menor = INT_MAX;
				turistas_restantes = pontos[i]->getInfo().getNrTourists();
				cout << "Ponto : " << pontos[i]->getInfo().getName() << endl;
				for(unsigned int j = 0;j<pontos.size();j++)
				{
					if(pontos[j]->getInfo().getVehicle() != NULL)
						if(w[i][j] <= menor && w[i][j] != 0 )

						{
							menor = w[i][j];
							pos = j;

						}

				}
			}

		//if(pos != -1) cout << "Sera socorrido pelo veiculo do ponto " << pontos[pos]->getInfo().getName() << endl ;
			if(pos != -1)
			do{
					cout << "Veiculo do ponto " << pontos[pos]->getInfo().getName() << " a desocupar " << turistas_restantes << " turistas" << endl;
					turistas_restantes -= pontos[pos]->getInfo().getVehicle()->getCapacity();
			}while(turistas_restantes > 0);

		cout << "-------------------------------"<< endl;
	}
}

