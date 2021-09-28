/*Given an unordered(undirected) graph and a source vertex 's' print BFS from the 
given source*/
//implementation of BFS

#include<iostream>
#include<queue>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void BFS(vector<int> adj[],int v,int s){
	int u;
	bool visited[v+1];           //visited array of type bool
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	queue<int>q;
	q.push(s);
	visited[s]=true;             //visited means-source vertex added into a queue
	cout<<"BFS of graph:\n";
	while(q.empty()==false){
		u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int i=0;i<adj[u].size();i++)
		{
			if(visited[adj[u][i]]==false){
				q.push(adj[u][i]);
				visited[adj[u][i]]=true;         //visited
			}
		}
	}
}
int main(void)
{
	int v=5;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	addEdge(adj,4,3);
	BFS(adj,v,0);          //source=0;
	return 0;
}
