def solution(n, computers):
    def union(a, b):
        a = find(a)
        b = find(b)
        if a<b:
            parent[b] = a
        else:
            parent[a] = b
        
    def find(x):
        if x == parent[x]:
            return x
        return find(parent[x])
    
    parent = [i for i in range(n)]
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1:
                union(i, j)
    
    for i in range(n):
        parent[i] = find(i)
    
    return len(set(parent))
