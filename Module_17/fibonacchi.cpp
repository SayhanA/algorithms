#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Max = 1e5+5;
ll arr[Max];

ll fibonacchi(ll n, ll arr[])
{
    if (n <= 1) return n;
    if(arr[n] != -1) return arr[n];
    return arr[n] = fibonacchi(n - 1, arr) + fibonacchi(n - 2, arr);
}

int main()
{
    ll n;
    cin >> n;
    memset(arr, -1, sizeof(arr));

    cout << fibonacchi(n, arr);

    return 0;
}