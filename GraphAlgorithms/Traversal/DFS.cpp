#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int N = 3e5;

/*
    Trabajamos el grafo como lista de adyacencia utilizando un arreglo de vector pairs
    indice del arreglo -> numero del vertice
    par -> first = nodo adyacente , second = peso para llegar hasta ese nodo
*/

vpii AdjList[N];
vi vis;

void dfs(int n){
    cout << n << " "; 
    vis[n] = 1;
    for(int i = 0; i < AdjList[n].size(); i++){
        pii v = AdjList[n][i];
        if(!vis[v.first]){
            dfs(v.first);
        }
    }
}

int main() {
    vis.assign(N,0);
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
    dfs(0);

    return 0;
}