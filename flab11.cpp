#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int> > adj[200005];
int s;
int vis[200005][2];

void bfs(int be)
{
	vis[be][0] = 1;
	vis[be][1] = 1;
	queue <pair<int,int> > q;

	for(int i=0; i<adj[be].size(); i++)
	{
		vis[adj[be][i].first][adj[be][i].second] = 1;
		q.push(make_pair(adj[be][i].first, adj[be][i].second));
	}

	while(!q.empty())
	{
		int cur = q.front().first;
		int sec = q.front().second;

		for(int i=0; i<adj[cur].size(); i++)
		{
			if(adj[cur][i].second != sec && !vis[adj[cur][i].first][adj[cur][i].second])
			{
				vis[adj[cur][i].first][adj[cur][i].second] = 1;
				q.push(make_pair(adj[cur][i].first, adj[cur][i].second));
			}
		}

		q.pop();
	}
}


int main()
{
	cin >> n >> m;

	int u, v, w;

	for(int i=0; i<m; i++)
	{
		cin >> u >> v >> w;

		adj[u].push_back(make_pair(v,w));
	}

	cin >> s;

	bfs(s);

	int q;
	cin >> q;

	int dest;

	while(q--)
	{
		cin >> dest;

		if(vis[dest][0] || vis[dest][1])
		{
			cout << "YES"<<endl;
		}
		else
		{
			cout << "NO"<<endl;
		}
	}
}
