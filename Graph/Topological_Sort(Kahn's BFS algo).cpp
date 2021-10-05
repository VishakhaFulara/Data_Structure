//Topological Sorting-using BFS(Kahn's Algorithm)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v,int *indegree)
{
	adj[u].push_back(v);
	indegree[v]++;
}

void topological_Sort(vector<int> adj[],int v,int *indegree)
{
	int u;
	queue<int>q;
	//push the vertex whose indegree is 0
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(q.empty()==false){
		u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int i=0;i<adj[u].size();i++)
		{
			indegree[adj[u][i]]--;
			if(indegree[adj[u][i]]==0)
			{
				q.push(adj[u][i]);
			}
		}
	}
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
	int v=5;            //given vertex
	vector<int>adj[v];  //array of vector 
	int indegree[v]={0};      //array for storing degree of each vertex
	addEdge(adj,0,2,indegree);
	addEdge(adj,0,3,indegree);
	addEdge(adj,1,3,indegree);
	addEdge(adj,1,4,indegree);
	addEdge(adj,2,3,indegree);
	Display(adj,v);
	topological_Sort(adj,v,indegree);
	return 0;
}
