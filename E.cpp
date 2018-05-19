#include <iostream>
#include <stack>
#include <array>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int df[1000001];
int sparseTable[1000001][30];
int A[1000001];
array <vector <int>,1000001> graph;
int root;

void dfs(int v, int &cont){
    for(auto it=graph[v].begin(); it!=graph[v].end(); ++it){
        int u=*it;
        if(df[u]==-1){
            sparseTable[u][0]=v;
            int aux=v;
            int ind=0;
            while(ind<30 && sparseTable[aux][ind]!=-1){
                sparseTable[u][ind+1]=sparseTable[aux][ind];
                aux=sparseTable[aux][ind];
                ind++;
            }
            if(aux!=root){
                sparseTable[u][ind+1]=root;
            }
            cont++;
            df[u]=cont;
            dfs(u, cont);
        }
    }
}

int d(int v){
    if(A[v]==1){
        return 0;
    }
    int aux=sparseTable[v][0];
    int ind=0;
    int lastBelow=aux;
    while(A[aux]==0){
        ind++;
        lastBelow=aux;
        aux=sparseTable[v][ind];

    }
    if(ind==0){
        return 1;
    }
    else{
        ind--;
        int dist=1<<ind;
        dist+=d(lastBelow);
        return dist;
    }
}

int main(void){
    std::ios::sync_with_stdio(false);
    memset(sparseTable, -1, sizeof sparseTable);
    memset(df, -1, sizeof df);
    cin >> root;
    int k;
    cin >> k;
    for(int i=1; i<root; i++){
        int aux1, aux2;
        cin >> aux1 >> aux2;
        graph[aux1].push_back(aux2);
        graph[aux2].push_back(aux1);
    }
    int cont=0;
    df[root]=0;
    dfs(root, cont);
    int verts=1;
    int init=root-1;
    A[root]=1;
    while(verts<root-k){
        //cout << verts << "\n";
        int aux=d(init);
        while(aux==0 || aux+verts>root-k){
            init--;
            aux=d(init);
        }
        verts+=aux;
        int auxi=init;
        for(int i=0; i<aux; i++){
            A[auxi]=1;
            auxi=sparseTable[auxi][0];
        }
        init--;
    }
    int ind=1;
    while(A[ind]==1) ind++;
    cout << ind;
    ind++;
    while(ind<=root){
        if(A[ind]==0) cout << " " << ind;
        ind++;
    }

    return 0;
}

