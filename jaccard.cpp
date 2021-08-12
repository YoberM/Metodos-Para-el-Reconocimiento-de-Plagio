#include "jaccard.h"

float Jaccard::indice(set<string> s1,set<string> s2){
    
    // Sizes of both the sets
    double size_s1 = s1.size();
    double size_s2 = s2.size();
  
    // Get the intersection set
    set<string> intersect = intersection(s1, s2);
  
    // Size of the intersection set
    double size_in = intersect.size();
  
    // Calculate the Jaccard index
    // using the formula
    double jaccard_in = size_in
                        / (size_s1 + size_s2 - size_in);
  
    // Return the Jaccard index
    return jaccard_in;
    return 0.0;
}

set<string> Jaccard::tokenizar(string archivo){
    ifstream file;
    string linea;
    vector<string> lineas;
    file.open(archivo,ios::in);
    if(file.fail()){exit(1);}

    while(!file.eof()){
        getline(file,linea);
        lineas.push_back(linea);
    }
    int k=0;
    set<string> res;


    for(auto i:lineas){
        vector<Token> tokens;
        tokens = Analizador::tokenizar(i);
        string ins ="";
        for(int j = 0; j < tokens.size(); j++){
            ins+=tokens[j].tipo;
        }
        res.insert(ins);
        // cout<<k++<<" |" << ins << endl;
    }
    // cout << "==============" << endl;
    // cout << res.size() << endl;
    k = 0;
    for(auto i:res){
        cout << k++ <<" |"<<i << endl;
    }
    cout << "==============" << endl;

    // cout << "TEXTO:\n" << texto << endl;
    // for(auto i:texto){
    //     if(i == '\n'){
    //         cout << "salto de linea GAAAAA" << endl;
    //     }
    // }
    return res;
}

set<string> Jaccard::intersection(set<string> s1, set<string> s2){
    //Codigo usado de GeekForGeeks
    set<string> intersect;
  
    // Find the intersection of the two sets
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                     inserter(intersect, intersect.begin()));
  
    return intersect;
}

float Jaccard::similitud_archivo(string archivo1, string archivo2 ){
    double res;
    //Tokenizar A
    set<string> A = Jaccard::tokenizar(archivo1);
    //Tokenizar B
    set<string> B = Jaccard::tokenizar(archivo2);

    res = indice(A,B);

    return res;
}
float Jaccard::similitud_palabras(string archivo1, string archivo2 ){
   return 0.0;
}