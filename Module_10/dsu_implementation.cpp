#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int arr[N];

void dsu_initialization(int n){
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    arr[1] = 3;
    arr[2] = 1;
}

int find(int node){
    if(arr[node] == -1) return node;
    return find(arr[node]);
}

int main(){
    int n = 4;
    dsu_initialization(n);
    cout << find(2) << endl;
    
    return 0;
}