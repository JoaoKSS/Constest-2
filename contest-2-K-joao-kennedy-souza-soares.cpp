#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main (){
    int i, j, k;
    cin >> i >> j >> k;
    vector <int> vi;
    vector <int> vj;
    vector <int> vk;
    int aux = 0;
    for(int c = 0; c < j; ++c){
        cin >> aux;
        vi.push_back (aux);
        cin >> aux;
        vj.push_back (aux);
        cin >> aux;
        vk.push_back (aux);
    }
    
    vector <bool> deposito(i + 1,false);
    while(cin >> aux){
        deposito[aux] = true;
    }
    
    int menor = INT_MAX;
    bool found = false;
    for(int c = 0; c < j; ++c){
        if(deposito[vi[c]] && !deposito[vj[c]]){
            if(menor > vk[c])menor = vk[c];
            found = true;
        }

        if(!deposito[vi[c]] && deposito[vj[c]]){
            if(menor > vk[c])menor = vk[c];
            found = true;
        }
    }
    if(found == false){
        cout << -1 << endl;
        return 0;
    }
    cout << menor << endl;

    return 0;
}