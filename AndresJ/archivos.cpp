#include <fstream.h>

int main()
{
    ofstream archivo;  // objeto de la clase ofstream

    archivo.open("datos.txt");

    archivo << "Primera l�nea de texto" << endl;
    archivo << "Segunda l�nea de texto" << endl;
    archivo << "�ltima l�nea de texto" << endl;

    archivo.close();
    return 0;
} 
