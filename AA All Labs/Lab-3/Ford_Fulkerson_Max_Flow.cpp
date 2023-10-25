#include <iostream>
#include<bits/stdc++.h>
#define n 6

using namespace std;

bool bfs(int rsdgraph [n][n],int first, int last, int array[n]){
    
    int visited[6];
    
    for(int i=0; i<n;i++){
        visited[i] = 0;
    }
    
    
    queue<int> Q ;
    Q.push(first);
    visited[first] = 1;
    array[first] = -1;
    
    while(!Q.empty()){
        int u = Q.front(); 
        Q.pop();
        
        for(int v=0;v<n;v++){
            if(visited[v] ==0 && rsdgraph[u][v]>0){
                if(v == last){
                    array[v] = u;
                    return true;
                }
                
                Q.push(v);
                visited[v] = 1;
                array[v] = u;
                
            }
        }
    }
    
    return false;
}

int FordFulkarson(int graph[n][n],int s,int t){
    
    int rgraph[6][6];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rgraph[i][j] = graph[i][j];
        }
    }
    
    int parent[6];
    int Max_flow = 0,u;
    
    while(bfs(rgraph,s,t,parent)){
        int pathflow = 5000;
        
        for(int v=t; v!=s; v= parent[v]){
            u = parent[v];
            pathflow = min(pathflow,rgraph[u][v]);
        }
        
        for(int v=t; v!=s; v= parent[v]){
            u = parent[v];
           rgraph[u][v] = rgraph[u][v] - pathflow;
           rgraph[v][u] = rgraph[v][u] + pathflow;
        }
        
        Max_flow = Max_flow + pathflow;
        
    }
    
    return Max_flow;
    
    
}

int main()
{
    int G[6][6] = { {0,16,13,0,0,0},
                    {0,0,10,12,0,0},
                    {0,4,0,0,14,0},
                    {0,0,9,0,0,20},
                    {0,0,0,7,0,4},
                    {0,0,0,0,0,0}
                };
            
    int maxflow = FordFulkarson(G,0,5);
    cout<<"The maxflow is: "<<maxflow;
    return 0;
}

