#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX_NODES 1001
#define BUFFER_SIZE 4

// matrixamos de ints aka grafamos de ints
// so da para 1001 porque matrixamos normal fica foda
// 1001 * 1001 * 8b ja sao bues bro sao tipo 8Mb
int grafamos[MAX_NODES][MAX_NODES];
bool visitamos[MAX_NODES];
int MAX_IDX = 0;
int queue[MAX_NODES];

int __max__(int a, int b)
{
    return (a >= b) ? a : b;
}
// dequeue remove first shift all
void __dequeue__(int *idx)
{
    for (int i = 0; i < MAX_IDX - 1; i++)
    {
        queue[i] ^= queue[i + 1];
        queue[i + 1] ^= queue[i];
        queue[i] ^= queue[i + 1];
    }
    (*idx)--;
}

//parse file like (1-3\n2-0\n3-2) ...
void __init__(int fd)
{
    char* edge = (char*)malloc(sizeof(char) * 5);
    edge[4] = 0;
    int size = read(fd, edge, BUFFER_SIZE);
    while (size > 0) {
        int u = edge[0] - '0';
        int v = edge[2] - '0';
        MAX_IDX = __max__(__max__(u, v), MAX_IDX);
        printf("edge: %s \n read on buffer: %d \n", edge, size);
        grafamos[u][v] = 1; // edge[1] is '-' set
        size = read(fd, edge, BUFFER_SIZE);
    }
}

void __unsetVisitamos__()
{
    for (int i = 0; i < MAX_IDX; i++)
        visitamos[i] = 0;
}

void __unsetQueue__()
{
    for (int i = 0; i < MAX_NODES; i++)
        queue[i] = 0;
}

void dfs(int u)
{
    visitamos[u] = 1;
    printf("%d ", u);
    for (int i = 0; i < MAX_IDX; i++)
    {
        if (!visitamos[i] && grafamos[u][i])
            dfs(i);
    }
}

void __dfs__()
{
    __unsetVisitamos__();
    int component = 0;
    for (int i = 0; i < MAX_IDX; i++) {
        if (!visitamos[i]) {
            component++;
            printf("Component: %d \n", component);
            dfs(i);
            printf("\n");
        }
    }
}

void bfs(int u)
{
    __unsetQueue__();
    int level = 0, idx = 0;
    //enqueue u
    queue[idx++] = u;

    while (idx)
    {
        int size = idx;
        printf("level: %d \n", level);
        for (int i = 0; i < size; i++)
        {
            int front = queue[0];
            __dequeue__(&idx);
            printf("%d ", front);
            for (int j = 0; j < MAX_IDX; j++)
            {
                if (!visitamos[j] && grafamos[i][j])
                {
                    visitamos[j] = 1;
                    queue[idx++] = j;
                }
            }
        }
        level++;
        printf("\n");
    }
}

void __bfs__()
{ 
    __unsetVisitamos__();
    printf("starting bfs");
    for (int i = 0; i < MAX_IDX; i++)
        if (!visitamos[i])
            bfs(i);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        perror("Input a single file name to parse the grafamos\n");
        return 1;
    }
    int fd = open(av[1], O_RDWR);
    if (fd == -1)
    {
        perror("Error processing file");
        return 1;
    }
    __init__(fd);
    printf("Grafamos initializado \n");
    printf("Components: \n");
    __dfs__();
    printf("bfs: \n");
    __bfs__();
    return 0;
}
