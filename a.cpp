#include<bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    uint num_dir, min;

    cin >> num_dir;
    cin >> min;

    uint tempo_dir = (min - (num_dir - 1)) / num_dir;

    cout << tempo_dir << "\n";

    return 0;
}
