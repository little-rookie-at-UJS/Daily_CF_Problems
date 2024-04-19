// link  https://codeforces.com/contest/662/submission/257243871

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g1(n), g2(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        // g1 是代表变成蓝色
        if (c == 'R') {
            // u,v选一个 g1
            g1.add_edge(u, v + n);
            g1.add_edge(v, u + n);
//            debug("addg1", u, v + n);
//            debug("addg1", v, u + n);
            // u,v选两个或者都不选 g2
            g2.add_edge(u + n, v + n);
            g2.add_edge(v, u);
//            debug("addg2", u + n, v + n);
//            debug("addg2", v, u);
        } else {
            // u,v选一个 g2
            g2.add_edge(u, v + n);
            g2.add_edge(v, u + n);
//            debug("addg2", u, v + n);
//            debug("addg2", v, u + n);
            // u,v选两个或者都不选 g1
            g1.add_edge(u + n, v + n);
            g1.add_edge(v, u);
//            debug("addg1", u + n, v + n);
//            debug("addg1", v, u);
        }
    }
    g1.run();
    g2.run();
    debug(g1.ans, g1.arr);
    debug(g2.ans, g2.arr);
    if (g1.ans < g2.ans) {
        cout << g1.ans << endl;
        for (auto x: g1.arr) {
            cout << x << " ";
        }
    }else {
        if(g2.ans == inf){
            cout << -1;
            return;
        }else{
            cout << g2.ans << endl;
            for (auto x: g2.arr) {
                cout << x << " ";
            }
        }
    }
}
