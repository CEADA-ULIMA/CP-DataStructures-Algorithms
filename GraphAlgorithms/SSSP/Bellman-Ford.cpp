#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int N = 5;

vi dist(N, 3e5);
vpii adj[N];

//O(VE)
void bellman_ford(int n){
    dist[n] = 0;
    for(int i = 0; i < N-1; i++) //Relax vertices-1 veces O(v)
        for(int u = 0; u < N; u++) // Relax O(E) los 2 loops con lista de adj.  
            for(int j = 0; j < adj[u].size() ; j++){
                pii v = adj[u][j];
                dist[v.first] = min(dist[v.first] , dist[u] + v.second);
            }
    //detección de ciclo negativo
    /*
        Esta parte detecta si existe algún ciclo negativo en el grafo
        complejidad de O(E)
    */ 
    bool hasNegativeCycle = false;
    for(int u = 0; u < N && !hasNegativeCycle; u++){
        for(int j = 0; j < adj[u].size() && !hasNegativeCycle ; j++){
            pii v = adj[u][j];
            if(dist[v.first] > dist[u] + v.second)
                hasNegativeCycle = true;
        }
    }

    cout << "Ciclo negativo: " << (hasNegativeCycle ? "Yes" : "No") << endl;
}

int main(){
    adj[0] = {{2,6} , {4,1}};
    adj[1] = {{2,2} , {3,3} , {4,6}};
    adj[2] = {{1,2} , {3,7} , {0,6}};
    adj[3] = {{1,3} , {2,7} , {4,5}};
    adj[4] = {{0,1} , {1,6} , {3,5}};

    bellman_ford(2);
    for(auto &c : dist) cout << c << " ";
    return 0;
}