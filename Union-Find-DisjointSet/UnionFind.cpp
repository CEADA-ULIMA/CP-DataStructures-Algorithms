/*
    Union-Find DisjointSet implementation with compress path
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind{
    private: vi p, rank;
    public:
        UnionFind(int N) {rank.assign(N,0); p.assign(N,0); for(int i = 0; i< N; i++) p[i] = i;}
        int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));} //compress path
        bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
        void unionSet(int i, int j){
            if(!isSameSet(i,j)){
                int x = findSet(i) , y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else {p[x] = y; if(rank[x] == rank[y]) rank[y]++;}
            }
        }
};

int main()
{
    UnionFind* disj = new UnionFind(10);
    disj->unionSet(1,2);
    disj->unionSet(8,9);
    disj->unionSet(2,3);
    disj->unionSet(3,4);
    disj->unionSet(7,8);
    //disj->unionSet(4,7); <- une los 2 subconjuntos

    for(int i = 0; i < 10; i++){
        cout << "Conjunto del numero " << i << " es: " << disj->findSet(i) << '\n'; 
    }
    return 0;
}
