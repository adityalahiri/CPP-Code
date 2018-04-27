#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair


int n, m;
string g[2000];

int vis[2000][2000];
int dist[2000][2000];

void bfs(int x0, int y0)
{
	vis[x0][y0] = 1;
	dist[x0][y0] = 0;

	deque <pair<int,int> > q;

	q.pb(mp(x0, y0));

	while(!q.empty())
	{
		int nxtx = q.front().first;
		int nxty = q.front().second;
		q.pop_front();
		//cout << nxtx << " " << nxty << " :" << dist[nxtx][nxty] << endl;

		if(nxtx-1 >= 0 && !vis[nxtx-1][nxty])
		{
			if(g[nxtx-1][nxty] == '*')
			{
				vis[nxtx-1][nxty] = 1;
				dist[nxtx-1][nxty] = 1 + dist[nxtx][nxty];
				q.push_back(mp(nxtx-1, nxty));
			}
			else if(g[nxtx-1][nxty] != 'B')
			{
				vis[nxtx-1][nxty] = 1;
				dist[nxtx-1][nxty] = dist[nxtx][nxty];
				q.push_front(mp(nxtx-1, nxty));
			}
		}

		if(nxtx+1 < n && !vis[nxtx+1][nxty])
		{

			if(g[nxtx+1][nxty] == '*')
			{
				vis[nxtx+1][nxty] = 1;
				dist[nxtx+1][nxty] = 1 + dist[nxtx][nxty];
				q.push_back(mp(nxtx+1, nxty));
			}
			else if(g[nxtx+1][nxty] != 'B')
			{
				vis[nxtx+1][nxty] = 1;
				dist[nxtx+1][nxty] = dist[nxtx][nxty];
				q.push_front(mp(nxtx+1, nxty));
			}
		}

		if(nxty-1 >= 0 && !vis[nxtx][nxty-1])
		{

			if(g[nxtx][nxty-1] == '*')
			{
				vis[nxtx][nxty-1] = 1;
				dist[nxtx][nxty-1] = 1 + dist[nxtx][nxty];
				q.push_back(mp(nxtx, nxty-1));
			}
			else if(g[nxtx][nxty-1] != 'B')
			{
				vis[nxtx][nxty-1] = 1;
				dist[nxtx][nxty-1] = dist[nxtx][nxty];
				q.push_front(mp(nxtx, nxty-1));
			}
		}

		if(nxty+1 < m && !vis[nxtx][nxty+1])
		{

			if(g[nxtx][nxty+1] == '*')
			{
				vis[nxtx][nxty+1] = 1;
				dist[nxtx][nxty+1] = 1 + dist[nxtx][nxty];
				q.push_back(mp(nxtx, nxty+1));
			}
			else if(g[nxtx][nxty+1] != 'B')
			{
				vis[nxtx][nxty+1] = 1;
				dist[nxtx][nxty+1] = dist[nxtx][nxty];
				q.push_front(mp(nxtx, nxty+1));
			}
		}

		//q.pop_front();
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		cin >> n >> m;

		for(int i=0; i<n; i++)
			cin >> g[i];

		int stx, sty, endx, endy;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				dist[i][j] = -1;
				vis[i][j] = 0;

				if(g[i][j] == 'P')
				{
					stx = i;
					sty = j;
				}

				if(g[i][j] == 'G')
				{
					endx = i;
					endy = j;
				}
			}
		}

		bfs(stx, sty);
/*
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				cout << dist[i][j] << " ";
			cout << endl;
		}
*/
		cout << dist[endx][endy] << endl;
	}
}
