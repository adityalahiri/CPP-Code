// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
using namespace std;

int flag = 0, found = 0;

// Prints all paths from 's' to 'd'
void printAllPaths(int s, int d,vector<pair<int,int> > adj[], int n)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[n];

    // Create an array to store paths
    int *path = new int[n];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index,adj);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void printAllPathsUtil(pair<int,int> u, int d, bool visited[],
                              int path[], int &path_index,vector<pair<int,int> > adj[n])
{
    // Mark the current node and store it in path[]
    visited[u.first] = true;
    path[path_index] = u.second;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u.first == d)
    {
        for (int i = 0; i<path_index-1; i++){

          if(path[i] == path[i+1])
            flag = 1;
        }

    if(flag == 0)
        found = 1;

    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u.first].begin(); i != adj[u.first].end(); ++i)
            if (!visited[*i.first])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u.first] = false;
}

// Driver program
int main()
{

	int n = 0, e = 0;
	cin>>n>>e;

	vector<pair<int,int> > adj[n];

	for(int i = 0; i<e; i++){

		int u = 0, v = 0, w = 0;
		cin>>u>>v>>w;

		adj[u].push_back({v,w});


	}

	int s = 0;
	cin>>s;

	int q = 0;
	cin>>q;

	while(q--){

		int d = 0;
		cin>>d;

    flag = 0;
    found = 0;

    printAllPathsUtil()

		if(found)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

}
