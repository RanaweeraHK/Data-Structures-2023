#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#define INF numeric_limits<int>::max() // Infinity value

// Function to find the city with the minimum time taken to visit
int minTime(int dist[], bool visited[], int V)
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the time array and visited city path
void printSolution(int dist[], int V, vector<int> path[])
{
    cout << "Source city is 0" << endl;
    int total_time = 0;
    cout << "Cities \tTime taken \tVisited city Path\n";
    for (int i = 0; i < V; i++)
    {
        cout << "  " << i << "\t" << dist[i] << "\t\t\t";
        for (int j = 0; j < path[i].size(); j++)
        {
            cout << path[i][j];

            if (j != path[i].size() - 1)
                cout << " -> ";
        }
        cout << endl;
        total_time += dist[i]; // Calculate the total time
    }
    cout << "Average time to visit all the cities from source city: " << total_time / (V - 1) << endl;
}

void dijkstra(int graph[][6], int src, int V)
{
    int dist[V]; // Array to store the least time from source to vertices
    bool visited[V]; // Array to track visited vertices
    vector<int> path[V]; // Array to store the visited vertex path

    // Initialize all times as INFINITE and visited array as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;  // time of source city from itself is always 0
    path[src].push_back(src); // Add source vertex to the visited path

    for (int count = 0; count < V - 1; count++)
    {
        int u = minTime(dist, visited, V); // Find the vertex with the minimum time 

        visited[u] = true; // Mark the selected vertex as visited

        // Update the time value of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                path[v] = path[u]; // Update the visited path of the adjacent city
                path[v].push_back(v); // Add the current city to the visited path
            }
        }
    }

    printSolution(dist, V, path); // Print the calculated least time and visited city path
}

int main()
{
    int V = 6; // Number of cities in the graph

    int graph[6][6] = {{0, 10, 0, 0, 15, 5},
                      {10, 0, 10, 30, 0, 0},
                      {0, 10, 0, 12, 5, 0},
                      {0, 30, 12, 0, 0, 20},
                      {15, 0, 5, 0, 0, 0},
                      {5, 0, 0, 20, 0, 0}};

    int src = 0; // Source city

    dijkstra(graph, src, V);

    return 0;
}

