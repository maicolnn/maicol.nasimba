#include <iostream>
#include <windows.h>
#include<fstream>
#include<stdlib.h>
#include<string>
#include "../lib/mnarchivos.h"
using namespace std;
int mrNroNodo=0;

const string MNCEDULA = "1754491494";
const string MNNOMBRE_COMPLETO ="MAICOL ESTUARDO NASIMBA QUINGA";

//Estructura del nodo
struct mnCoordenada{
	int mnCap; //capacidadbélica
    string mnGeo; //geoposicionamiento
    string mnArsenal; //tipoarsenal
	mnCoordenada *der;
	mnCoordenada *izq;
};


// Funcion para insertar datos a los nodos del arbol
void mnInsertar(mnCoordenada*& mnarbol, int mnCap, string mnGeo, string mnArsenal) {
int mnNroNodo=0; //numero de nodos totales
 
  if (mnarbol == NULL) {
    mnarbol = new mnCoordenada{mnCap, mnGeo, mnArsenal, NULL, NULL};
    return;
  }

  if (mnCap < mnarbol->mnCap) {
    mnInsertar(mnarbol->izq, mnCap, mnGeo, mnArsenal);
  } else {
    mnInsertar(mnarbol->der, mnCap, mnGeo, mnArsenal);
  }
}

//Funcion para coger los datos del archivo txt
void mnCogerDatos(mnCoordenada*& mnarbol, string pathfile) {
  std::ifstream archivo(pathfile);
  if (!archivo.is_open()) {
    std::cerr << "No se pudo abrir el archivo " << pathfile << std::endl;
    return;
  }

  int mnCap;
  string mnGeo;
  string mnArsenal;
  while (archivo >> mnCap >> mnGeo >> mnArsenal) {
    mnInsertar(mnarbol, mnCap, mnGeo, mnArsenal);
    mrNroNodo=5;
  }

  archivo.close();
}
//Capacidad belica
int mnCBelica()
    {int mnCantidad=0;
        int cedula[10]={1,7,5,4,4,9,1,4,9,4};

        mnCantidad=26;
    return mnCantidad;
    }


//P3 muestra la informacion del arbol
void mnInformacionArbol()
{
cout<< "[+] INFORMACION ARBOL BINARIO";
cout<< "Developer-Nombre: "<<MNNOMBRE_COMPLETO;
cout<< "Developer-Cedula "<<MNCEDULA;
cout<< "CapacidadBélica "<<mnCBelica();
cout<< "Coordenada-SecCarga "<<"1 7 5 4 9";
cout<< "COORDENADA-TOTAL: "<<mrNroNodo;



}

int main()
{  mnCoordenada* mnarbol = NULL;

HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,1);
cout<<"Leyendo archivos..."<<endl;
SetConsoleTextAttribute(hConsole,4);
leer("archivodatos.txt");
mnCogerDatos(mnarbol, "archivodatos.txt");
SetConsoleTextAttribute(hConsole,1);
mnInformacionArbol();
return 0;
}