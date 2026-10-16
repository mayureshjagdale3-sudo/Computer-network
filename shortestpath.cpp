#include <iostream>
using namespace std;

int main()
{
    int n, e, i, j, k;
    int cost[10][10], dist[10], visited[10];
    int u, v, minDist;
    char a, b, s;

    cout << "Enter number of nodes (7 to 10): ";
    cin >> n;

    if (n < 7 || n > 10)
    {
        cout << "Enter nodes between 7 and 10.";
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = 99999;

            if (i == j)
                cost[i][j] = 0;
        }
    }

    cout << "Enter edges and costs (Example: A B 4):\n";

    for (i = 0; i < e; i++)
    {
        cin >> a >> b >> j;

        cost[a - 'A'][b - 'A'] = j;
        cost[b - 'A'][a - 'A'] = j;
    }

    cout << "Enter source node: ";
    cin >> s;

    int source = s - 'A';

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (k = 1; k < n; k++)
    {
        minDist = 99999;
        u = -1;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 &&
                dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (v = 0; v < n; v++)
        {
            if (visited[v] == 0 &&
                cost[u][v] != 99999 &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "\nSource\tDestination\tShortest Cost\n";

    for (i = 0; i < n; i++)
    {
        cout << s << "\t"
             << char('A' + i) << "\t\t";

        if (dist[i] == 99999)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}