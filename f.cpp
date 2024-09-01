#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p, f=0, nf=1, aux;

    cin >> p;

    for(int i=1; i<=p; i++){
        aux = f;
        f = nf;
        nf += aux;
    }

    cout << nf;

    return 0;
}