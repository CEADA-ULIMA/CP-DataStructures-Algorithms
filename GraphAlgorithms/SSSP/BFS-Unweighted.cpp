#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int N = 3e5;

/*
    Implementacion parecida a traversal/bfs.cpp 
    PrintPath muestra el camino más corto
    El algoritmo solamente funciona en grafo que tengan pesos iguales o que no tengan pesos
*/

vpii AdjList[N];
vi p(N, 0);
void printPath(int u, int source){
    if(u == source){cout << to_string(source) + " "; return;}
    printPath(p[u], source);
    cout << to_string(u) + " "; 
}
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
                p[v.first] = u;
                q.push(v.first);
    }}}
    //muestra el camino más corto de 0 hasta 4
    printPath(4,0); cout << endl; 
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