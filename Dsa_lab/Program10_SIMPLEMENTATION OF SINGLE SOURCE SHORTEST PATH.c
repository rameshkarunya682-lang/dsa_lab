#include <stdio.h>

#define INF 9999

int main()
{
    int cost[10][10], dist[10], visited[10];
    int n, source, i, j, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++)
    {
        min = INF;
        next = -1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                next = i;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] &&
                dist[next] + cost[next][i] < dist[i])
            {
                dist[i] = dist[next] + cost[next][i];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);

    return 0;
}

Output:

Enter number of vertices: 5
Enter cost matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0

Enter source vertex: 0

Shortest distances from source 0:
To 0 = 0
To 1 = 10
To 2 = 50
To 3 = 30
To 4 = 60
