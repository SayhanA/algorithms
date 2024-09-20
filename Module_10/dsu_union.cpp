#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int arr[N];

void dsu_initialization(int n){
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    arr[1] = 2;
    arr[2] = 3;

    arr[5] = 6;
    arr[6] = 7;
}

int dsu_find(int node){
    if(arr[node] == -1) return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union(int node1, int node2){
    int leadA = dsu_find(node1);
    int leadB = dsu_find(node2);
    arr[leadA] = leadB;
}

int main(){
    dsu_initialization(8);
    
    return 0;
}