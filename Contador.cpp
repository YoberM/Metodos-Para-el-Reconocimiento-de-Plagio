#include "Contador.h"

float Contador::sintactico(vector<Token> tokens1,vector<Token> tokens2){
    int op1=0,op2=0;
    int var1=0,var2=0;
    int p1=0,p2=0;
    int e1=0,e2=0;
    for (auto& it:tokens1){
        if(it.tipo == 'O'){
            op1++;
        }
        else if(it.tipo == 'V'){
            var1++;
        }
        else if(it.tipo == 'p'){
            p1++;
        }
        else if(it.tipo == 'E'){
            e1++;
        }
    }
    for (auto& it:tokens2){
        if(it.tipo == 'O'){
            op2++;
        }
        else if(it.tipo == 'V'){
            var2++;
        }
        else if(it.tipo == 'p'){
            p2++;
        }
        else if(it.tipo == 'E'){
            e2++;
        }
    }
    float res = diferencia(op1,op2)/4 + diferencia(var1,var2)/4; 
    res = res + diferencia(p1,p2)/4 + diferencia(e1,e2)/4;

    cout << "--- Contador de Palabras ---" << endl;
    cout << "OP , " << op1 << " | " << op2 << endl;
    cout << "Var, " << var1 << " | " << var2 << endl;
    cout << "Par, " << p1 << " | " << p2  << endl;
    cout << "Ent, " << e1 << " | " << e2 << endl;
    cout << "----------------------------" << endl;

    return res;
}

float Contador::lexico(string code1,string code2){
    int tam1 = code1.length();
    int tam2 = code2.length();
    return diferencia(tam1,tam2);
}

float Contador::diferencia(int a,int b){
    if(a==0 && b ==0){
        return 1;
    }
    else if(a==0 || b ==0){
        return 0;
    }
    return float(min(a,b))/float(max(a,b));
}

float Contador::similitud_palabras(string archivo1, string archivo2 ){
   string texto1 = Analizador::contenido(archivo1);
   string texto2 = Analizador::contenido(archivo2);
   vector<Token> A = Analizador::tokenizar(texto1);
   vector<Token> B = Analizador::tokenizar(texto2);
   return sintactico(A,B);
}
float Contador::similitud_archivo(string archivo1, string archivo2 ){
   string texto1 = Analizador::contenido(archivo1);
   string texto2 = Analizador::contenido(archivo2);
   return lexico(texto1,texto2);
}