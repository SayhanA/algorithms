#include <bits/stdc++.h>
using namespace std;

int fectorial(int n){
    int cost = 1;
    if(n != 0){
        return cost = fectorial(n-1) * n;
    }
    return cost;
}

int main(){
    int n;
    cin >> n;

    cout << fectorial(n) << endl;
    
    return 0;
}