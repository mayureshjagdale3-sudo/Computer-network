#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

#define V 7

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest Distance Table\n";
    cout << "-------------------------------\n";
    cout << left << setw(15) << "Destination"
         << "Distance from A\n";
    cout << "-------------------------------\n";

    for (int i = 0; i < V; i++) {
        cout << left << setw(15) << char('A' + i);

        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 3, 0, 0, 0},
        {2, 0, 1, 0, 0, 4, 0},
        {0, 1, 0, 0, 5, 0, 2},
        {3, 0, 0, 0, 2, 0, 6},
        {0, 0, 5, 2, 0, 1, 0},
        {0, 4, 0, 0, 1, 0, 3},
        {0, 0, 2, 6, 0, 3, 0}
    };

    dijkstra(graph, 0);

    return 0;
}