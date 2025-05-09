#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 20;

int parent[MAX];
pair <int, pair<int, int> > p[MAX];

int Find(int i)
{
    while(parent[i]!=-1)
        i=parent[i];
    return i;
}

void Union(int j, int k)
{
    if(j<k)
        parent[j]=k;
    else
        parent[k]=j;
}

void kruskal(int vertex, int mst[][3], int edges)
{

    for(int i=0;i<vertex;i++)
        parent[i]=-1;

    int a, b, mincost = 0, cnt=0;
    for(int i=0; i<edges;i++){
        int j=Find(a = p[i].second.first);
        int k=Find(b = p[i].second.second);
        if(j!=k)
        {
            cnt++;
            mst[cnt][0]=a;
            mst[cnt][1]=b;
            mst[cnt][2]=p[i].first;
            mincost += p[i].first;
            Union(j,k);
        }
    }
    if(cnt !=vertex-1)
        cout<<"no spanning tree", exit(0);
    else
        for(int i=1;i<vertex;i++)
            cout<<mst[i][0]<<" - "<<mst[i][1]<<" : "<<mst[i][2]<<endl;
        cout<<"minimum cost : "<<mincost;
}

int main(){

    int edges, cost, vertex, vertex1, vertex2;

    cout<<"Enter total number of vertices : ";
    cin>>vertex;

    int mst[vertex-1][3];

    cout<<"Enter no of edges : ";
    cin>>edges;

    for(int i=0;i<edges;i++){
        cout<<"Enter vertices and cost of the edge "<<i+1<<" <vertex1, vertex2, cost>: ";
        cin>>vertex1>>vertex2>>cost;
        p[i]= make_pair(cost,make_pair(vertex1,vertex2));
    }

    sort(p,p+edges);

    kruskal(vertex, mst,edges);

    return 0;
}
