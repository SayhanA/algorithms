// #include <bits/stdc++.h>
// using namespace std;
// vector<int> v[100];
// bool isV[100];
// int level[100];

// void fun(int src){
//     queue<int> q;
//     q.push(src);
//     isV[src] = true;
//     level[src] = 0;
//     while (!q.empty())
//     {
//         int par = q.front();
//         q.pop();

//         cout << par << " ";

//         for(int child:v[par]){
//             if(isV[child] == false){
//                 q.push(child);
//                 level[child] = level[par] + 1;
//             }
//         }
//     }

// }

// int main(){
//     int n, e, a, b;
//     cin >> n >> e;
//     while (e--)
//     {
//         cin >> a >> b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     memset(isV, false, sizeof(isV));
//     memset(level, -1, sizeof(level));

//     fun(0);
//     // for (int i = 0; i < n; i++)
//     // {
//     //     if(level[i] == 1){
//     //         cout << i << " ";
//     //     }
//     // }

//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << i << ": " << level[i] << endl;
//     // }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool isV[100];
int level[100];

void bst_level(int src)
{
    queue<int> q;
    q.push(src);
    isV[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout <<  par << endl;

        for (int child : v[par])
        {
            if (isV[child] == false)
            {
                q.push(child);
                level[child] = level[par] + 1;
                isV[child] = true;
            }
        }
    }
}

int main()
{
    int n, e, a, b, x;
    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> x;
    memset(isV, false, sizeof(isV));
    memset(level, -1, sizeof(level));

    bst_level(0);

    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (level[i] == x)
        {
            temp.push_back(i);
        }
    }

    sort(temp.begin(), temp.end(), greater<int>());
    
    for(int val:temp){
        cout << val << " ";
    }

    return 0;
}