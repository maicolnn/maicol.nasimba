#include <iostream>
#include <windows.h>
#include<fstream>
#include<stdlib.h>
#include<string>
#include "../lib/mnarchivos.h"

using namespace std;

const string MNCEDULA = "1754491494";
const string MNNOMBRE_COMPLETO ="MAICOL ESTUARDO NASIMBA QUINGA";


struct mnCoordenada{
	int mnCap;
    string mnGeo;
    string mnArsenal;
	mnCoordenada *der;
	mnCoordenada *izq;
};
int main()
{
HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,1);
cout<<"Leyendo archivos"<<endl;
SetConsoleTextAttribute(hConsole,2);
leer("archivodatos.txt");

return 0;
}