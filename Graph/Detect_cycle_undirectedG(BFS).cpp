#include<iostream>
#include<queue>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
bool BFS(vector<int> adj[],int s,bool visited[],int *parent){
	int u;
	queue<int>q;
	q.push(s);
	visited[s]=true;             //visited means-source vertex added into a queue
	while(q.empty()==false){
		u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			if(visited[adj[u][i]]==false){
				q.push(adj[u][i]);
				visited[adj[u][i]]=true;         //visited
				parent[adj[u][i]]=u;
			}
			else if(adj[u][i]!=parent[u])
			{
				return true;
			}
		}
	}
	return false;
}
bool detectCycle(vector<int>adj[],int v)
{
	int parent[v];
	parent[0]=-1;
	bool visited[v]={false};
	for(int i=0;i<v;i++)
	{
		//check if vertex is visited or not
		if(visited[i]==false){           
			if(BFS(adj,i,visited,parent))
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
int main()
{
	int v=7;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	Display(adj,v);
	if(detectCycle(adj,v))
	{
		cout<<"Cycle is present!!!";
	}
	else{
		cout<<"Cycle is not present!!!";
	}
	return 0;
}	  	
