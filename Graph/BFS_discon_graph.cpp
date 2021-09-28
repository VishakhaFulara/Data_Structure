/*No source given and graph may be disconnected
		0	      4
	   /  \      /  \
	  1	   2    5____6
	  \	  /
	  	3
	  
	print all the vertex	& count connected component in an undirected graph(No. of islands in the graph)
	connected means-if every vertex reachable from every other vertex
	In above eg-connected component=2
*/
#include<iostream>
#include<queue>
using namespace std;
void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void BFS(vector<int> adj[],int s,bool visited[]){
	int u;
	queue<int>q;
	q.push(s);
	visited[s]=true;             //visited means-source vertex added into a queue
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
void BFS_Disc(vector<int>adj[],int v)
{
	int count=0;
	bool visited[v+1];           //visited array of type bool
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		//check if vertex is visited or not
		if(visited[i]==false){           
			BFS(adj,i,visited);           //source=i
			count++;
		}
	}
	cout<<"\nConnected components in an undirected graph="<<count;
}
int main(void)
{
	int v=7;            //given vertex
	vector<int>adj[v];  //array of vector   
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	BFS_Disc(adj,v);          //source=0;
	return 0;
}	  	
