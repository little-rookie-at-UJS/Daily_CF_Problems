
void solve() {
    int n, m, f, t;
    cin >> n >> m >> f >> t;
    vector<array<int, 3>> edge(m + 1);
    Graph g(n), rg(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
        rg.add_edge(v, u, w);
        edge[i] = {u, v, w};
    }
    vector<int> disf = g.dij(f, n), dist = rg.dij(t, n);
//    debug(disf);
//    debug(dist);
    TGraph tg(n);
    for (int i = 1; i <= m; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        if (disf[u] + dist[v] + w == disf[t]) {
//            debug("add", u, v);
            tg.add_edge(u, v);
        }
    }
    tg.dfs(f);
    set<pair<int, int>> ans = tg.ans;
//    debug(ans);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = edge[i];
        if (disf[u] + dist[v] + w == disf[t] && ans.count(make_pair(u, v))) {
            cout << "YES" << endl;
            continue;
        }
        int y = disf[t] - (disf[u] + dist[v]) - 1;
//        debug(w, y);
        if (y <= 0) {
            cout << "NO" << endl;
        } else {
            cout << "CAN " << w - y << endl;
        }
    }
}

 
