#ifndef JACCARD_H
#define JACCARD_H
#include "Analizador.h"

class Jaccard: public Analizador{
    public:
        Jaccard() = default;

        float indice(set<string>,set<string>);

        set<string> tokenizar(string);
        set<string> intersection(set<string>, set<string>);
        float similitud_archivo(string archivo1, string archivo2) ;
        float similitud_palabras(string archivo1, string archivo2) ;
};

#endif