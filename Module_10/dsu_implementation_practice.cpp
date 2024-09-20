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

    arr[5] = 6;
    arr[6] = 7;
}

int dsu_find(int node){
    if(arr[node] == -1) return node;
    return  arr[node] = dsu_find(arr[node]);
}

void dsu_union(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    arr[leaderA] = leaderB;
}

int main(){
    dsu_initialization(8);
    
    cout << dsu_find(2) << " " << dsu_find(5) << endl;

    dsu_union(1, 5);
    cout << dsu_find(2) << " " << dsu_find(5) << endl;
    
    return 0;
}