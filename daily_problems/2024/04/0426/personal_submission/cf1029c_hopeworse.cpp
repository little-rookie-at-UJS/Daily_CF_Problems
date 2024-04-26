
node ands(node &n1, node &n2) {
    int l = max(n1.l, n2.l);
    int r = min(n1.r, n2.r);
    if (l > r) l = r;
    node n;
    n.l = l;
    n.r = r;
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<node> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].l >> arr[i].r;
    }
    vector<node> pre(n + 1);
    vector<node> end(n + 1);
    pre[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        pre[i] = ands(pre[i - 1], arr[i]);
    }
    end[n] = arr[n];
    for (int i = n - 1; i; i--) {
        end[i] = ands(end[i + 1], arr[i]);
    }
    int ans1 = max(pre[n - 1].r - pre[n - 1].l, end[2].r - end[2].l);
    for (int i = 2; i < n; i++) {
        node nn = ands(pre[i - 1], end[i + 1]);
        ans1 = max(ans1, nn.r - nn.l);
    }
    cout << ans1 << endl;
}
