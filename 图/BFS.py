'''
void BFS(int x)
    visited[x] = true
    Queue.push(x)
    while (!Queue.empty())
        v = Queue.pop()
        for v 的每一个邻接点w(兄弟节点)
            if(!visited[w])
                visited[w] = true
                Queue.push(w)
'''