#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of nodes

class Graph {
private:
    int graph[MAX][MAX]; // Adjacency matrix
    int n;               // Number of nodes

public:
    Graph(int nodes) {
        n = nodes;
        // Initialize matrix with 0s
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = 0;
    }

    void addEdge(int u, int v) {
        if (u >= 0 && v >= 0 && u < n && v < n) {
            graph[u][v] = 1;
            graph[v][u] = 1; // Remove for directed graph
        }
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFSUtil(int node, bool visited[]) {
        cout << node << " ";
        visited[node] = true;

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[MAX] = { false };
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        bool visited[MAX] = { false };
        int queue[MAX], front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "\nBFS Traversal: ";

        while (front < rear) {
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < n; i++) {
                if (graph[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    Graph g(nodes);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayMatrix();

    int start;
    cout << "\nEnter starting node for DFS and BFS: ";
    cin >> start;

    g.DFS(start);
    g.BFS(start);

    return 0;
}
