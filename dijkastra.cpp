#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N=1e5+10;
typedef pair<int,int> ipair;
vector<ipair>adj[N];

void shortestpath(int s,vector<pair<int,int> >adj[],int ver,int destination){
   priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
   vector<int>dist(N,INF);
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        vector<pair<int,int> >::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            int v=(*it).first;
            int weight=(*it).second;
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
  cout<<dist[destination]<<endl;
}
int main(){
    int ver,edges;
    cout<<"Enter the number of vertex:";
    cin>>ver;

    cout<<"Enter the edges:";
    cin>>edges;
    for(int i=1;i<=edges;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    int src,desti;
    cout<<"Enter the source vertex:";
    cin>>src;
    cout<<"Enter the Destination:";
    cin>>desti;
    shortestpath(src,adj,ver,desti);
}
