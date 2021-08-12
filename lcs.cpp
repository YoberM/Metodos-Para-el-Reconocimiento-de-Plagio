#include "lcs.h"


float LongestCommonSubsequence::lcs( string X, string Y, int m, int n ){
    int L[m + 1][n + 1];
    int i, j;
    
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;
    
        else if (X[i - 1] == Y[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;
    
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

float LongestCommonSubsequence::similitud_palabras(string palabra1, string palabra2){
            float dist = lcs(palabra1,palabra2,palabra1.size(),palabra2.size());
            //cout<<palabra1<<" "<<palabra2<<" "<<dist;
            float tam = max(palabra1.length(),palabra2.length());
            //cout<<tam<<" lev: "<< 1 - (dist/tam) << endl;
            return dist;
        }

float LongestCommonSubsequence::similitud_archivo(string archivo1, string archivo2){
    string texto1 = Analizador::contenido(archivo1);
    string texto2 = Analizador::contenido(archivo2);
    
    float sum = 0.0;

    sum = sum + similitud_palabras(texto1,texto2);
    return sum/texto2.size();
}