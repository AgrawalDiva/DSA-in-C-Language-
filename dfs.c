#include <stdio.h>

int main()
{
    int n, i, j, top = -1, source;
    int stack[20], visited[20] = {0};

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

    stack[++top] = source;
    visited[source] = 1;

    printf("DFS Traversal: ");

    while(top >= 0)
    {
        source = stack[top--];
        printf("%d ", source);

        for(i = n - 1; i >= 0; i--)
        {
            if(adj[source][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
