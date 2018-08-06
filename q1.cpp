#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
class graph
{
	vector<vector <int> > Edge;
	vector<unsigned char> visited;
public:
	graph(int V)
	{
		Edge.resize(V);
		visited.resize(V);
	}
	void add_edge(int v, int w)
	{
		Edge[v].push_back(w);
	}
	void bfs(int s)
	{
		for(auto i: visited) i = false;
		list<int>q;
		visited[s] = true;
		q.push_back(s);
		while(!q.empty())
		{
			s = q.front();
			cout<<s<<" ";
			q.pop_front();
			for(auto i: Edge[s])
			{
				if(!visited[i])
				{
					visited[i] = true;
					q.push_back(i);
				}
			}
		}
	}
};
int main()
{
	graph g(6);
	g.add_edge(1,2);
	g.add_edge(2,4);
	g.add_edge(2,5);
	g.add_edge(4,3);
	g.add_edge(3,1);
	g.bfs(1);
	return 0;
}
