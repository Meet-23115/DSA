#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList; // Adjacency list representation

public:
    // Add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for a directed graph
    }

    // Display the adjacency list
    void display() {
        for (auto& pair : adjList) {
            cout << pair.first << ": ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Breadth-First Search (BFS)
    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS starting from node " << start << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Depth-First Search (DFS)
    void dfs(int start) {
        unordered_map<int, bool> visited;
        cout << "DFS starting from node " << start << ": ";
        dfsHelper(start, visited);
        cout << endl;
    }

    // Helper for DFS
    void dfsHelper(int node, unordered_map<int, bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g;

    // Add edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 7);

    // Display the graph
    cout << "Graph representation:" << endl;
    g.display();

    // Perform BFS
    g.bfs(1);

    // Perform DFS
    g.dfs(1);

    return 0;
}
