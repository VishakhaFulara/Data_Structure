//Detect cycle in a undirected graph-using DFS

#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool DFS_rec(vector<int> adj[],bool visited[],int s,int parent)
{
	visited[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
		{
			if(DFS_rec(adj,visited,adj[s][i],s)==true)
			{
				return true;
			}
		}
		else if(adj[s][i]!=parent){
			return true;
		}
	}
	return false;
	
}
bool detect_cycle(vector<int> adj[],int v){
	bool visited[v]={false};
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			if(DFS_rec(adj,visited,i,-1)==true)
			{
				return true;
			}
		}
	}
	return false;
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
	int v=8;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	addEdge(adj,5,6);
	addEdge(adj,5,7);
	addEdge(adj,6,7);
	Display(adj,v);
	if(detect_cycle(adj,v)==true)
	{
		cout<<"Cycle is present";
	}
	else{
		cout<<"Cycle is not present";
	}
	return 0;
}
