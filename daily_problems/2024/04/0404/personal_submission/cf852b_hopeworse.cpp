// link : https://codeforces.com/contest/852/submission/254917816
int n, l, m;
    cin >> n >> l >> m;
    vec a(m), b(m), c(m);
    vector<int> v(n);
    for (int i = 0, x; i < n; i++)cin >> x, a.v[x % m]++;
    for (int i = 0, x; i < n; i++)cin >> x, v[i] = x, b.v[x % m]++;
    for (int i = 0, x; i < n; i++)cin >> x, x += v[i], c.v[x % m]++;
    b = a * qpow(b, l - 2) * c;
    cout << b.v[0] << endl;
