#include <stdio.h>

int main()
{
    int n, i, j, source;
    int queue[20], front = -1, rear = -1;
    int visited[20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    queue[++rear] = source;
    visited[source] = 1;

    printf("BFS Traversal: ");

    while(front != rear)
    {
        source = queue[++front];
        printf("%d ", source);

        for(i = 0; i < n; i++)
        {
            if(adj[source][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
