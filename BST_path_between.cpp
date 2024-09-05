#include <bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool isVis[100];

int main(){
    int n, e, a, b, src, dec;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> src >> dec;
    cout << src << " " << dec << endl;
    
    return 0;
}