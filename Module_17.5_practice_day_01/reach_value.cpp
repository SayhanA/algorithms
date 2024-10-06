#include <bits/stdc++.h>
using namespace std;

bool number(int i, int n)
{
    if (n <= 0 || i > n)
        return false;
    if (i == n)
        return true;
    else
    {
        return number(i * 10, n) || number(i * 20, n);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;

        number(1, num) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}