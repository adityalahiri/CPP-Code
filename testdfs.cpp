#include<bits/stdc++.h>



using namespace std;

int G[2019][2019] = {0,0};

bool containsOdd(int G[][2019], int src, int n)
{
    // Create a color array to store colors assigned
    // to all veritces. Vertex number is used as index
    // in this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to
    // vertex 'i'.  The value 1 is used to indicate first
    // color is assigned and value 0 indicates second
    // color is assigned.
    int colorArr[n];
    for (int i = 0; i < n; ++i)
        colorArr[i] = -1;

    // Assign first color to source
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and
    // enqueue source vertex for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue
        int u = q.front();
        q.pop();

        // Return true if there is a self-loop
        if (G[u][u] == 1)
           return true;

        // Find all non-colored adjacent vertices
        for (int v = 0; v < n; ++v)
        {
            // An edge from u to v exists and destination
            // v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent
                // v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            // An edge from u to v exists and destination
            // v is colored with same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return true;
        }
    }

    // If we reach here, then all adjacent
    // vertices can be colored with alternate
    // color
    return false;
}

int main(){

  int num_tests = 0;
  cin>>num_tests;

  for(int j = 1; j<=num_tests; j++){

  int n = 0, m = 0;
  cin>>n>>m;

  for(int i = 0; i<n; i++){
    for(int k =0; k<n;k++)
      G[i][k] = 0;

  }

  for(int i = 0; i<m; i++){

    int a = 0, b = 0;
    cin>>a>>b;
    G[a-1][b-1] = 1;

  }

  if(containsOdd(G,0,n))
    cout<<"Scenario #"<<j<<":"<<endl<<"Suspicious bugs found!"<<endl;
  else
    cout<<"Scenario #"<<j<<":"<<endl<<"No suspicious bugs found!"<<endl;


}

}
