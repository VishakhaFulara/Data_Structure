// Adjacency list implementation-undirected graph

#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void Display(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int v=4;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	Display(adj,v);
	return 0;
}
