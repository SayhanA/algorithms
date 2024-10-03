#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int arr[N];
int groupSize[N];

void dsu_init(int n){
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node){
    if(arr[node] == -1) return node;
    return arr[node] = dsu_find(arr[node]);
}

void dsu_union_by_size(int node1, int node2){
    int leadA = dsu_find(node1);
    int leadB = dsu_find(node2);

    if(groupSize[leadA] > groupSize[leadB]){
        arr[leadB] = leadA;
        groupSize[leadA] += groupSize[leadB];
    }
    else{
        arr[leadA] = leadB;
        groupSize[leadB] += groupSize[leadA];
    }
}

int main(){
    dsu_init(7);

    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);

    cout << dsu_find(1) << endl;

    dsu_union_by_size(1, 4);

    cout << dsu_find(1) << endl;
    
    return 0;
}