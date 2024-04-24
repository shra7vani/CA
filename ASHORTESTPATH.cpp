#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V));

    // Initialize distances
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Main algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "All Pair Shortest Paths:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use INF for infinity):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);

    return 0;
}
