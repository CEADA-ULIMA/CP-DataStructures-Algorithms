#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
const int N = 5;
const int INF = 1e9; 

//implementación con matriz de adyacencia (Se presta para el DP)
vvi AdjMat ={{0,2,1,INF,3},
            {INF, 0, INF, 4, INF},
            {INF, 1, 0, INF, 1},
            {1,INF,3,0,5},
            {INF,INF,INF,INF,0}};
            
//O(V^3) solamente usar con grafos pequeños V <= 400
void floydWarshall(){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
            }
        }
    }
}

int main(){
    floydWarshall();
    for(auto &c : AdjMat){
        for(auto &d : c){
            if(d == INF) cout << "INF ";
            else cout << d << " ";
        }
        cout << endl;
    }
    return 0;
}