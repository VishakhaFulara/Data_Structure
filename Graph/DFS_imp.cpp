//Implementation of DFS-for undirected graph

#include<iostream>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFS_Recurs(vector<int>adj[],int s,bool visited[]){
	visited[s]=true;
	cout<<s<<" ";
	for(int i=0;i<adj[s].size();i++){
		if(visited[adj[s][i]]==false)
		{
			DFS_Recurs(adj,adj[s][i],visited);
		}
	}
}
void DFS(vector<int> adj[],int v,int s){
	bool visited[v+1];           //visited array of type bool
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	DFS_Recurs(adj,s,visited);
}
int main(){
	int v=5;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	DFS(adj,v,0);               //passing source vertex=0
	return 0;
}
