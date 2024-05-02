#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list representation

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void DFSUtil(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main()
{
    int num_vertices, num_edges;
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;
    cout << "Enter the number of edges: ";
    cin >> num_edges;

    Graph graph(num_vertices);

    cout << "Enter edges in the format 'source destination':" << endl;
    for (int i = 0; i < num_edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int start_vertex;
    cout << "Enter the starting vertex: ";
    cin >> start_vertex;

    cout << "BFS Traversal: ";
    graph.BFS(start_vertex);
    cout << endl;

    cout << "DFS Traversal: ";
    graph.DFS(start_vertex);
    cout << endl;

    return 0;
}
