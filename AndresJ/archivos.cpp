#include <fstream.h>

int main()
{
    ofstream archivo;  // objeto de la clase ofstream

    archivo.open("datos.txt");

    archivo << "Primera línea de texto" << endl;
    archivo << "Segunda línea de texto" << endl;
    archivo << "Última línea de texto" << endl;

    archivo.close();
    return 0;
} 
