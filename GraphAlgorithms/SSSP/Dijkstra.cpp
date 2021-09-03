#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int N = 3e5;

vpii adj[N];
vi dist(N, INT_MAX);
priority_queue<pii , vector<pii> , greater<pii>> pq;

//O((V + E)log V) además usa memoria extra (tener cuidado)
void dijkstra(int s){
    dist[s] = 0;
    pq.push({0 , s});
    while(!pq.empty()){
        pii front = pq.top(); pq.pop();
        int d = front.first , u = front.second;
        if(d > dist[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            pii v = adj[u][i];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first] , v.first});
            }
        }
    }
}

int main(){
    adj[0] = {{2,6} , {4,1}};
    adj[1] = {{2,2} , {3,3} , {4,6}};
    adj[2] = {{1,2} , {3,7} , {0,6}};
    adj[3] = {{1,3} , {2,7} , {4,5}};
    adj[4] = {{0,1} , {1,6} , {3,5}};
    dijkstra(2);
    for(int i = 0; i < 5 ; i++){
        cout << dist[i] << ' ';
    }
    return 0;
}