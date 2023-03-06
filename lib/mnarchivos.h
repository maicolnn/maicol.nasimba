
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <windows.h>
#include <iomanip>
#include <string.h>

using namespace std;

void crearescribir(){
 ofstream archivo;
 string nombrearch,frase;
 char band;
 
 cout<<"Digite el nombre del archivo: ";
 getline(cin,nombrearch);
 
 archivo.open(nombrearch.c_str(),ios::out); //Abriendo el archivo
 
 if(archivo.fail()){
  cout<<"No se pudo abrir el archivo";
  exit(1);
 }
 
 do{
  fflush(stdin);
  
  cout<<"\nDigite el texto del archivo: ";
  getline(cin,frase);
  
  archivo<<frase<<endl;
  
  cout<<"\nDesea agregar mas texto al archivo? (s/n)";
  cin>>band;
 }while((band == 's') || (band == 'S'));
 
 archivo.close(); 
}

void mnporcent() //Porcentaje de carga para leer archivos
{
float len=5;
float aumento=100/len;
float porcent=0;
for(int i=0;i<=5;i++)
{
    if(i==0)
    {
    cout<<" "<<porcent<<"%\r";
    }
    else if(i>0)
    {cout<<"\r[";
    for(int x=0;x<=5;x++)
    {
    if(x<i) 
            {
            cout<<'='; 
            }
			else if(x==i) 
            {
            cout<<'>'; 
            }
			else 
            {
            cout<<' ';
            }
    }
    cout<<"] ";
    
    cout<<" "<<fixed<<setprecision(2)<<porcent<<"%\r";
    }
porcent+=aumento;
if(i==5) porcent=100;
Sleep(200);
}
}



void leer(string pathfile)
{
	ifstream archivo(pathfile);
	string texto;
	
	if(archivo.fail())
	{	
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof())
	{ 	
		getline(archivo,texto);
		mnporcent();
		
		cout<<"                          "<<texto<<endl;
	}
	
	archivo.close(); 
}


void escribir(string pathfile){
	ofstream archivo;
	string texto;
	char rpt;
	
	archivo.open(pathfile ,ios::app); 
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"Digite una frase: ";
		getline(cin,texto);
		archivo<<texto<<endl;
		
		cout<<"Desea agregar otra frase? (s/n): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close();
}
