#ifndef SINTACTICO_H
#define SINTACTICO_H
#include "Analizador.h"

// Funcion de Levenshtein
class Levenshtein: public Analizador{
    public:
        Levenshtein() = default;

        float levenshtein(const string &, const string&);

        float similitud_palabras(string , string );

        float similitud_archivo(string , string );
        float similitud_archivo_v2(string , string );
};

#endif