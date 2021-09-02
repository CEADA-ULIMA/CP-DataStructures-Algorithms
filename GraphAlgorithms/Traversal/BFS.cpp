#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int N = 3e5;

vpii AdjList[N];

void bfs(int n){
    vi d(N, INT_MAX); d[n] = 0;
    queue<int> q; q.push(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        //cout << u << " ";
        for(int i = 0; i < AdjList[u].size(); i++){
            pii v = AdjList[u][i];
            if(d[v.first] == INT_MAX){
                d[v.first] = d[u] + 1;
                q.push(v.first);
            }
        }
    }
}

int main()
{
    //Nodo 0 
    AdjList[0].push_back({1,0});
    AdjList[0].push_back({2,0});
    AdjList[0].push_back({3,0});

    //Nodo 1
    AdjList[1].push_back({2, 0});
    AdjList[1].push_back({5, 0});
    AdjList[1].push_back({6, 0});

    //Nodo 2
    AdjList[2].push_back({4, 0});

    // dfs desde 0
    bfs(0);

    return 0;
}