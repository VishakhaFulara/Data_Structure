//Implementation of DFS-for undirected graph where graph is discconnected

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
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			DFS_Recurs(adj,i,visited);
		}
	}
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
	int v=5;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,3,4);
//	Display(adj,v);
	DFS(adj,v,0);               //passing source vertex=0
	return 0;
}
