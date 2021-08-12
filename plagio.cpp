#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Levenshtein.h"
#include "Contador.h"
#include "lcs.h"
#include "jaccard.h"
using namespace std;

//g++ -std=c++11 .\plagio.cpp .\Analizador.cpp .\Sintactico.cpp .\Lectura.cpp .\Contador.cpp .\lcs.cpp .\jaccard.cpp & .\a.exe

int main(){
    
    cout << "========= LEVENSHTEIN ========" << endl;
    Levenshtein lev;
    float sim1 = lev.similitud_archivo("codigo1.txt","codigo2.txt");
    cout<<"Similitud entre los archivos = "<<sim1<<endl;
    float sim1_2 = lev.similitud_archivo_v2("codigo1.txt","codigo2.txt");
    cout<<"Similitud entre los archivos = "<<sim1_2<<endl;
    cout << endl;

    cout << "============ LCS =============" << endl;
    LongestCommonSubsequence longcs;
    float sim2 = longcs.similitud_archivo("codigo1.txt","codigo2.txt");
    cout<<"Subsecuencia comun mas larga = "<<sim2<<endl;


    cout << "========== CONTADOR ==========" << endl;
    Contador con;
    float sim3 = con.similitud_palabras("codigo1.txt","codigo2.txt");
    cout <<"Contador de Palabras = "<< sim3 << endl;

    float sim3_1 = con.similitud_archivo("codigo1.txt","codigo2.txt");
    cout <<"Contador de archivo = " << sim3_1 << endl;
    cout << endl;
    
    
    
    cout << "========== JARCCARD =========" << endl;
    Jaccard jac;
    float sim4 = jac.similitud_archivo("codigo1.txt","codigo2.txt");
    cout << sim4 << endl;


    return 0;

    /* Analizador A(),B();
    string texto1 = A.contenido("codigo1.txt");
    string texto1 = B.contenido("codigo2.txt");
    float sim = similitud_archivo("codigo1.txt","codigo2.txt");
    
    string texto1 = contenido("codigo1.txt");
    string texto2 = contenido("codigo2.txt");
    Analizador A(texto1);
    A.tokens = A.tokenizar();
    Analizador B(texto2);
    B.tokens = B.tokenizar();
    
    cout<<"Similitud entre los archivos = "<<sim<<endl;
    cout << ContadorSintactico(A.tokens,B.tokens) << endl;

    cout << ContadorLexico(texto1,texto2) << endl;

    vector<string> lineas = contenido_lineas("codigo1.txt");

    for(int i =0; i < lineas.size() ; i++){
        cout << lineas[i] << endl;
    } */

    return 0;
}