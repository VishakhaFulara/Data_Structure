//Topological sort-using DFS

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

void DFS_rec(vector<int> adj[],bool visited[],int s,stack<int>&st)
{
	visited[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
		{
			DFS_rec(adj,visited,adj[s][i],st);
		}
	}
	st.push(s);	
}
void Topological_Sort(vector<int> adj[],int v)
{
	int u;
	bool visited[v]={false};
	stack<int>st;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			DFS_rec(adj,visited,i,st);
		}
	}
	while(st.empty()==false)
	{
		u=st.top();
		cout<<u<<" ";
		st.pop();
	}
}

int main(){
	int v=5;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	cout<<"Topological Sort:\n";
	Topological_Sort(adj,v);
	return 0;
}
