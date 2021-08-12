#include "Levenshtein.h"
#include "Lectura.h"

float Levenshtein::levenshtein(const string &palabra1, const string &palabra2){
   int N1 = palabra1.size();
   int N2 = palabra2.size();
   int i, j;
   vector<int> T(N2+1);

   for ( i = 0; i <= N2; i++ )
         T[i] = i;

   for ( i = 0; i < N1; i++ ) 
   {
         T[0] = i+1;
         int corner = i;
         for ( j = 0; j < N2; j++ ) 
         {
            int upper = T[j+1];
            if ( palabra1[i] == palabra2[j] )
               T[j+1] = corner;
            else
               T[j+1] = min(T[j], min(upper, corner)) + 1;
            corner = upper;
         }
   }
   return T[N2];
}


float Levenshtein::similitud_palabras(string palabra1, string palabra2){
   float dist = levenshtein(palabra1,palabra2);
   //cout<<palabra1<<" "<<palabra2<<" "<<dist;
   float tam = max(palabra1.length(),palabra2.length());
   //cout<<tam<<" lev: "<< 1 - (dist/tam) << endl;
   return (1 - (dist/tam));
}

float Levenshtein::similitud_archivo(string archivo1, string archivo2){
            string texto1 = Analizador::contenido(archivo1);
            string texto2 = Analizador::contenido(archivo2);
            //cout<<texto1<<endl<<texto2<<endl;
            vector<Token> A = Analizador::tokenizar(texto1);
            //Analizador::printTokens(A);
            vector<Token> B = Analizador::tokenizar(texto2);
            //Analizador::printTokens(B);
            float sum = 0.0;
            for (int i=0; i < min(A.size(),B.size()) ; i++){
                sum = sum + similitud_palabras(A[i].dato,B[i].dato);
                //cout<<A[i].dato<<" "<<B[i].dato<<" "<<similitud_palabras(A[i].dato,B[i].dato)<<endl;
            }
            return sum/A.size();
}

float Levenshtein::similitud_archivo_v2(string archivo1, string archivo2){
   string texto1 = Analizador::contenido(archivo1);
   string texto2 = Analizador::contenido(archivo2);
   //cout<<texto1<<endl<<texto2<<endl;
   vector<Token> A = Analizador::tokenizar(texto1);
   //Analizador::printTokens(A);
   vector<Token> B = Analizador::tokenizar(texto2);
   //Analizador::printTokens(B);
   float sum = 0.0;
   float maximo = 0.0;
   float temp = 0.0;
   for (int i=0; i < A.size() ; i++){
         for(int j=0; j < B.size() ; j++ ){
            temp = similitud_palabras(A[i].dato,B[j].dato);
            if(temp > maximo){
               maximo = temp; 
            }
         }
         sum = sum + maximo;
         maximo = 0.0;
   }
   return sum/A.size();
}