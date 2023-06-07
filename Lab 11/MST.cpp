
#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999
#define V 6

int G[V][V] = {
    {0, 3, 0, 0, 0, 1},
    {3, 0, 2, 1, 10, 0},
    {0, 2, 0, 3, 0, 5},
    {0, 1, 3, 0, 5, 0},
    {0, 10, 0, 5, 0, 4},
    {1, 0, 5, 0, 4, 0}
};

int main() {
    int selected[V];
    memset(selected, false, sizeof(selected));

    selected[0] = true;

    int edge_num = 0;
    int x, y;
    int total_weight = 0;

    cout << "Edge : Weight" << endl;

    while (edge_num < V - 1) {
        int min_weight = INF;
        x = 0;
        y = 0;

        // Find the minimum weight edge from the selected vertices
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min_weight > G[i][j]) {
                            min_weight = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        // Print the selected edge and its weight
        cout << x << " - " << y << " : " << G[x][y] << endl;

        // Update the total weight
        total_weight += G[x][y];

        // Mark the newly selected vertex as visited
        selected[y] = true;
        edge_num++;
    }

    cout << "Total Weight: " << total_weight << endl;

    return 0;
}
