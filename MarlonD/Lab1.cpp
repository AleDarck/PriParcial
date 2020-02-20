
#include <iostream>
#include "conio.h"
#include "string"
using namespace std;

int main()
{
    string nombre[30];
    float salario[10];
    float igss=0.0483, igsst[10];
    float isr=0.05, isrt[10];
    int boni=250;
    float salariot[10];
    float desc[10];
    cout <<  "\n******* Planilla de Salarios" << "********:\n";
    for(int i = 1; i <=5; i++)
    {
        cout << "Nombre: "<<endl;
        cin>>nombre[i];
        cout << "Salario: "<<endl;
        cin>>salario[i];
		}
	for(int e = 1; e <= 5; e++)
    {
	    igsst[e]= salario[e]*igss;
	    if (salario[e]>=5000){
	    isrt[e]=salario[e]*isr
		;}else {
	    isr=0.0; }
	    desc[e]=igsst[e]+isrt[e];
	    salariot[e]=(salario[e]+boni)-desc[e];
    }
		
	    for(int e = 1; e <=5; e++)
    {
    	cout << "Nombre: "<<" "<<nombre[e]<<endl;
    	cout<<"Total descuentos:"<<" "<<desc[e]<<endl;
    	cout<<"Salario total:"<<" "<<salariot[e]<<endl;
    }
	    
}
