#include <unistd.h>
#define MAX_SIZE 1001
#define VERTICES 4

int size_ = 0;
int rank[MAX_SIZE];
int root[MAX_SIZE];


//    0 1 2 3
//  0 0 1 0 0
//  1 1 0 1 0
//  2 1 1 1 0
//  3 1 1 0 1
//   _______________
//  |_____|______   |
//  |     |     |   |
//  0 <-> 1 -> (2) (3)
//
//  0 1 2 3 
//  | | | | \
//  1 3 0 0  1
//      

void __init__union(int size)
{
    for (int i = 0; i < size; i++)
    {
        rank[i] = 0;
        root[i] = i;
    }
    size_ = size;
}

int find(int x)
{
    if (root[x] == x)
            return x;
    return (root[x] = find(root[x]));
}

void    __union__(int x, int y)
{

    int rootx = find(x);
    int rooty = find(y);

    if (rootx == rooty)
        return ;

    if (rank[rootx] > rank[rooty])
        root[rooty] = rootx;
    else if (rank[rootx] < rank[rooty])
        root[rootx] = rooty;
    else {
        root[rooty] = rootx;
        rank[rootx]++;
    }
    size_--;
}

#include <stdio.h>

int main()
{
    __init__union(VERTICES);

    __union__(0, 1);
    __union__(1, 0);
    __union__(1, 2);
    __union__(2, 0);
    __union__(2, 1);
    __union__(2, 2);
    __union__(3, 0);
    __union__(3, 2);
    __union__(3, 3);

    for (int i = 0; i < VERTICES; i++)
        printf("root of %d is %d \n",i ,find(i));
    printf("Number of components is %d \n", size_);
    return 0;
}
