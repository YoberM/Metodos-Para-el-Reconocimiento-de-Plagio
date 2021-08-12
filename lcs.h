#include "Analizador.h"

class LongestCommonSubsequence: public Analizador{
    public:
        LongestCommonSubsequence() = default;

        float lcs( string, string, int, int);

        float similitud_palabras(string, string);

        float similitud_archivo(string, string);
};