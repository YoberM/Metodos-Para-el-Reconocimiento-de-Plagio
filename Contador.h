#ifndef CONTADOR_H
#define CONTADOR_H
#include "Analizador.h"

class Contador: public Analizador{
    public:
        Contador() = default;

        float lexico(string,string);
        float sintactico(vector<Token>,vector<Token>); 
        float diferencia(int,int);

        float similitud_palabras(string palabra1, string palabra2);
        float similitud_archivo(string archivo1, string archivo2) ;
};

#endif