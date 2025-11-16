import random

def make_graph(n_nodes, n_edges, fname):
    edges = set()
    while len(edges) < n_edges:
        u = random.randint(0, n_nodes-1)
        v = random.randint(0, n_nodes-1)
        if u != v:
            edges.add((u, v))
    with open(fname, 'w') as f:
        for u, v in edges:
            f.write(f"{u}-{v}\n")

make_graph(5, 7, 'small.txt')
make_graph(20, 50, 'medium.txt')
make_graph(100, 1000, 'large.txt')
