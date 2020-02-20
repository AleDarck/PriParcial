#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include<fstream>

#define ENTER 13 
#define BACKSPACE 8

 
using namespace std;
int main(){
int elec;
int h;
    string nombre[30];
    string apellido[30];
    float salario[10], salarioe[10],comisiones[10], totald[10],salariod[10];
    float igss=0.0483, igsst[10];
    float isr=0.012, isrt[10];
    float boni=154.5;
    float salariot[10];
    float desc[10];
    vector<string> usuarios;
    vector<string> claves;
    ofstream entrada;//creacion del archivo de texto de el control de los empleados
entrada.open("Empleados.txt");
if (entrada.fail())//verificacion si el archivo se creo correctamente
{
cout<<"Ocurrion un problema con el archivo";//mensaje si el archivo no se creo correctamente
return 1;
}
ofstream entrada2;//creacion del archivo de texto que guarda todo lo escrito en el programa
entrada2.open("Bitacora.txt");//verificacion si el archivo se creo correctamente
if (entrada2.fail())
{
cout<<"Ocurrion un problema con el archivo";//mensaje si el archivo no se creo correctamente
return 1;
}
    // Se añaden usuarios al vector
    usuarios.push_back("eduardoing");
    usuarios.push_back("willisistemas");
    usuarios.push_back("marloncont1");
    usuarios.push_back("diegocont2");
    usuarios.push_back("abrahamnomin");
    
    // Se añaden claves al vector
    claves.push_back("umg");
    claves.push_back("wrma");
    claves.push_back("1234");
    claves.push_back("abc1");
    claves.push_back("abr12");
    
    
    string usuario, password;
    
    int contador = 0;
    bool ingresa = false;
cout<<"-----------------------------------"<<endl;
cout<<"- Bienvenido al sistema de nomina -"<<endl;
cout<<"----------------------------------- "<<endl<<endl;

cout<<"          1.Ingresar"<<endl;//menu de inicio del programa
cout<<"          2.Salir"<<endl;
cin>>elec;
if (elec==1){
   do {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        cin>>usuario;
        
        char caracter;
        
        cout << "\tPassword: ";
        caracter = getch();
        
        password = "";
        
        while (caracter != ENTER) {
        
            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";
                } else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            
            caracter = getch();
        }
        
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i] == usuario && claves[i] == password) {
                ingresa = true;
                break;
            }
        }
        
        if (!ingresa) {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
            system("pause");
        }
        
    } while (ingresa == false && contador < 3);
    
    if (ingresa == false) {
        cout << "\n\tUsted no pudo ingresar al sistema. Que tenga un buen dia" << endl;
    } else {
    	entrada2<<"|"<<"Usuario"<<"|"<<"Contraseña"<<"|"<<endl<<usuario<<"      "<<password<<endl;//Ingresa los datos de inicio de sesion al archivo de Bitacora
        cout << "\n\n\tBienvenido al sistema" << endl;
        cout <<"Cuantos empleados desea ingresar?"<<endl;//Pregunta cuantos empleados se ingresaran
        cin>>h;
        system("cls");
        entrada<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Salario"<<"|"<<"Salario Extra."<<"|"<<"Bonificación"<<"|"<<"Comisiones"<<"|"<<"Total Devengado"<<"|"<<endl;//Ingresa los datos al archivo de Bitacora
        entrada2<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Salario"<<"|"<<"Salario Extra."<<"|"<<"Bonificación"<<"|"<<"Comisiones"<<"|"<<"Total Devengado"<<"|"<<endl;//Ingresa los datos al archivo de Empleados
        
    for(int i = 1; i <=h; i++)//ciclo for que ingesa los datos de los empleados
    {
        cout <<  "\n******* Planilla de Salarios" << "********:\n";
		cout << "Nombre: "<<endl;
        cin>>nombre[i];
        cout << "Apellido: "<<endl;
        cin>>apellido[i];
        cout << "Salario: "<<endl;
        cin>>salario[i];
        cout << "Salario Extraordinario: "<<endl;
        cin>>salarioe[i];
        cout << "Comisiones: "<<endl;
        cin>>comisiones[i];
        system("cls");
        totald[i]=salario[i]+salarioe[i]+comisiones[i]+boni;//Operacion que calcula el salario total devengado
		entrada<<nombre[i]<<"   "<<apellido[i]<<"     "<<salario[i]<<"     "<<salarioe[i]<<"             "<<boni<<"           "<<comisiones[i]<<"         "<<totald[i]<<endl;//Ingresa los datos al archivo de empleados
	    entrada2<<nombre[i]<<"   "<<apellido[i]<<"     "<<salario[i]<<"     "<<salarioe[i]<<"             "<<boni<<"           "<<comisiones[i]<<"         "<<totald[i]<<endl;//Ingresa los datos al archivo de Bitacora
		}
		 entrada<<"|"<<"Descuentos"<<"|"<<endl<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Salario"<<"|"<<" IGSS "<<"|"<<" ISR "<<"|"<<"Total Descuentos"<<"|"<<endl;
		 entrada2<<"|"<<"Descuentos"<<"|"<<endl<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Salario"<<"|"<<" IGSS "<<"|"<<" ISR "<<"|"<<"Total Descuentos"<<"|"<<endl;
	for(int e = 1; e <= h; e++)
    {
    	salariod[e]=totald[e]-boni;//operacion que calcula el salario devengado
	    igsst[e]= salariod[e]*igss;//operacion que calcula el IGSS
	    if (salariod[e]>=5000){//ciclo IF que verifica si el salario es mas alto de 5000 para realizar cobro del ISR
	    isrt[e]=salariod[e]*isr//operacion que calcula elISR
		;}else {
	    isr=0.0; }
	    desc[e]=igsst[e]+isrt[e];//Operacion que calcula el total de descuentos
	    salariot[e]=totald[e]-desc[e];//operacion que calcula el salario total liquido
    entrada<<nombre[e]<<"   "<<apellido[e]<<"   "<<totald[e]<<"    "<<igsst[e]<<"   "<<isrt[e]<<"     "<<desc[e]<<endl;
	entrada2<<nombre[e]<<"   "<<apellido[e]<<"   "<<totald[e]<<"    "<<igsst[e]<<"   "<<isrt[e]<<"     "<<desc[e]<<endl;
	}
		entrada<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Total Devengado"<<"|"<<"Total Descuentos"<<"|"<<"Total Liquido"<<"|"<<endl;
	    entrada2<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Total Devengado"<<"|"<<"Total Descuentos"<<"|"<<"Total Liquido"<<"|"<<endl;
		cout << "Nombre"<<"| "<<"Apellido"<<"| "<<"Total Devengado"<<"|"<<"Total Descuentos"<<"|"<<"Total Liquido"<<endl;
		for(int e = 1; e <=h; e++)
    
	{
    	cout<<nombre[e]<<"   "<<apellido[e]<<"       "<<totald[e]<<"           "<<desc[e]<<"             "<<salariot[e]<<endl;//impresion en pantalla de los datos del empleado
    	
    	entrada<<nombre[e]<<"   "<<apellido[e]<<"   "<<totald[e]<<"                "<<desc[e]<<"             "<<salariot[e]<<endl;
	    entrada2<<nombre[e]<<"   "<<apellido[e]<<"   "<<totald[e]<<"              "<<desc[e]<<"             "<<salariot[e]<<endl;
    }
    }
    entrada.close();//cierre del primer archivo
    entrada2.close();//cierre del segundo archivo
    cin.get();
   
}else{
system("cls");	
cout<<"Que tengas un buen dia";	
}


}
