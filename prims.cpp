#include <iostream>
#define V 10
using namespace std;

int minkey(int key[], bool visited[])
{
    int min = 999, min_ind;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false && key[i] < min)
        {
            min = key[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \t Weight\n";
    int cnt = 0;
    for (int i = 1; i < 4; i++)
    {
        cout << parent[i] << " - " << i << " \t " << graph[i][parent[i]] << "\n";
        cnt = cnt + graph[i][parent[i]];
    }
    cout << "Minimum cost is : " << cnt;
}

void primMST(int graph[V][V])
{
    int parent[V], key[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = 999;
        visited[i] = false;
    }
    key[0] = 0;
    parent[0] = -1; // initialisation

    for (int j = 0; j < V - 1; j++)
    {
        int u = minkey(key, visited);
        visited[u] = true;
        for (int i = 0; i < V; i++)
        {
            if (graph[u][i] && visited[i] == false && graph[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    printMST(parent, graph);
}

int main()
{
    int n, e, graph[V][V], e1, e2, c;
    cout << "Enter number of nodes" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter the number of edges : " << endl;
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        cout << "Enter edge (e1,e2) " << endl;
        cin >> e1 >> e2;
        cout << "Enter the cost of edge(e1,e2)" << endl;
        ;
        cin >> c;
        graph[e1][e2] = c;
        graph[e2][e1] = c;
    }

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cout << graph[a][b] << "\t";
        }
        cout << endl;
    }

    primMST(graph);
    return 0;
}