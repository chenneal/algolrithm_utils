bool dfs(vector<int>& result, vector< vector<int> >& graph, vector<int>& visit, int u, int& index) {
    visit[u] == -1;
    int n = graph[0].size();
    // the edge u to itself is 0 
    for (int v = 0; v < n; v++) if (graph[u][v]) {
        if (visit[v] == -1)
            return false;
        else if (!visit[v] && !dfs(result, graph, visit, v, index))
            return false;
    }
    visit[u] = 1;
    result[--index] = u;
    return true;
}

//visit must be clear to 0
bool toposort(vector<int>& result, vector< vector<int> >& graph, vector<int>& visit) {
    int n = graph[0].size();
    int index = n;
    for (int u = 0; u < n; u++) if (!visit[u]) {
        if (!dfs(result, graph, visit, u, index))
            return false;
    }
    return true;
}

/* single test */
/*
int main() {
    int m, n;
    cin >> n >> m;
    vector< vector<int> > graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
    }
    vector<int> visit(n, 0);
    vector<int> result(n, 0);
    toposort(result, graph, visit);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    int a;
    cin >> a;
    return 0;
}
*/