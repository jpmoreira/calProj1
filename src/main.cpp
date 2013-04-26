#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Mountain/Mountain.h"
using std::string;
using std::vector;

void operacoesGrafo();
void evacuar();
string getFileName();
Mountain *myMountain;
int main(int argc, char **argv) {
int opcao = 0;



	do
	{
		cout << "1. Carregar ficheiro" << endl;
		cout << "2. Dar instrucoes" << endl;

		cin >> opcao;
	}while(opcao != 1 && opcao != 2);



if(opcao == 1){
	myMountain=new Mountain(getFileName());

}
else myMountain = new Mountain;


operacoesGrafo();
}


string getFileName(){
	string s;
	while(s==""){
		cout<<"Please enter the file name: "<<endl;
		cin >>s;
	}

	return s;

}

void operacoesGrafo()
{
	int opcao;
	string str,str2;
	int num,num2;
do{
	cout << endl <<  "1. Adicionar ponto com turistas" << endl;
	cout << "2. Adicionar ponto com veiculo" << endl;
	cout << "3. Remover ponto" << endl;
	cout << "4. Adicionar caminho entre dois pontos com peso" << endl;
	cout << "5. Remover caminho entre dois pontos" << endl;
	cout << "6. Evacuar" << endl;
	cout << "7. Distribuir Veiculos"<<endl;
	cout << "0. Terminado" << endl;
	cin >> opcao;
	switch(opcao)
	{
	case 1:
		cout << "Qual o nome do ponto? " ;
		cin>> str;
		cout << endl << "Quantos turistas? ";
		cin >> num;

		if(num<0){num=1;}

		myMountain->addPoint(str);
		myMountain->AddTouristToPoint(str,num);
		break;

	case 2:
		cout << "Qual o nome do ponto? " ;
		cin >> str;
		cout << endl << "Qual a capacidade do veiculo? ";
		cin >> num;

		if(num<0){num=1;}
		myMountain->addPoint(str);
		myMountain->addVehicleToPoint(str,num);
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
		if(num<0){num=1;}

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

	case 7:

		cout<<"Quantos veiculos pretende adicionar: ";
		cin >> num;
		cout<<endl<<"Quantos lugares deve ter cada veiculo: ";
		cin >> num2;
		if(num<0){num=0;}
		if(num2<0){num2=1;}
		myMountain->placeVehicles(num,num2);
		break;

	default:
		cout<<"Invalid operation. Please enter a valid one"<<endl;
		break;

	}

}while(opcao != 0);



return;
}

void evacuar()
{
	myMountain->evaquate();
}

