#include <iostream>
#include <vector>

using namespace std;

int main (){
    int vertices = 0;
    cin >> vertices;

    vector <int> aresta(vertices+1);
    int aux;

    int aluno = 1;
    while(cin >> aux){
        aresta[aluno] = aux;
        aluno++;
    }
    
    for(int a = 1 ; a <= vertices ;++a ){
        vector<bool> furo(vertices+1,0);
        furo[a] = true;
        aux = aresta[a];
        while(true){
            if(furo[aux] == true){
                break;
            }
            furo[aux] = true;
            aux = aresta[aux];
        }
        cout << aux << ' ';
    }
    cout << endl;
    
    return 0;
}