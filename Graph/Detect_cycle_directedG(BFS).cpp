//Detect cycle in a directed graph-using BFS /Kahn's Algo


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v,int *indegree)
{
	adj[u].push_back(v);
	indegree[v]++;
}

bool Detect_cycle(vector<int> adj[],int v,int *indegree)
{
	int u,count=0;
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
		for(int i=0;i<adj[u].size();i++)
		{
			indegree[adj[u][i]]--;
			if(indegree[adj[u][i]]==0)
			{
				q.push(adj[u][i]);
			}
		}
		count++;
	}
	return (count!=v);
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
	addEdge(adj,0,1,indegree);
	addEdge(adj,1,2,indegree);
	addEdge(adj,2,0,indegree);
	addEdge(adj,2,3,indegree);
	Display(adj,v);
	if(Detect_cycle(adj,v,indegree))
	{
		cout<<"Cycle is present";
	}
	else{
		cout<<"Cycle is not present";
	}
	return 0;
}
