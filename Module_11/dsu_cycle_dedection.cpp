#include <bits/stdc++.h>
using namespace std;

void dsu_init(int n, int *arr, int *groupSize){
    for(int i =0; i<n; i++){
        arr[i] = -1;
        groupSize[i] = 1;
    }
}

int dsu_find(int node, int *arr){
    if(arr[node] == -1) return node;
    return arr[node] = dsu_find(arr[node], arr);
}

void dsu_union(int node1, int node2, int *arr, int *groupSize){
    int parA = dsu_find(node1, arr);
    int parB = dsu_find(node2, arr);

    if(groupSize[parA] > groupSize[parB]){
        arr[parB] = parA;
        groupSize[parA] += groupSize[parB];
    }
    else {
        arr[parA] = parB;
        groupSize[parB] += groupSize[parA];
    }
}

int main(){
    int n, e, a, b;
    cin >> n >> e;
    int arr[n];
    int groupSize[n];
    bool isCycled = false;

    dsu_init(n, arr, groupSize);
    
    while (e--)
    {
        cin >> a >> b;
        if(dsu_find(a, arr) == dsu_find(b, arr)){
            isCycled = true;
        }
        else{
            dsu_union(a, b, arr, groupSize);
        }
    }
    
    isCycled ? cout << "Cycled\n" : cout << "Not cycled\n";
    
    return 0;
}