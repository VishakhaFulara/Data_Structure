//Detect cycle in a directed graph-using DFS

#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

bool DFS_rec(vector<int> adj[],bool visited[],int s,bool recSt[])
{
	visited[s]=true;
	recSt[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
		{
			if(DFS_rec(adj,visited,adj[s][i],recSt)==true)
			{
				return true;
			}
		}
		else if(recSt[adj[s][i]]==true){
			return true;
		}
	}
	recSt[s]=false;
	return false;
	
}
bool detect_cycle(vector<int> adj[],int v){
	bool visited[v]={false};
	bool recSt[v]={false};
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			if(DFS_rec(adj,visited,i,recSt)==true)
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
		cout<<i<<"->";
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
	addEdge(adj,2,1);
	addEdge(adj,2,3);
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
