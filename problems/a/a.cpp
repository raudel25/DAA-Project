// raudel25
#include <bits/stdc++.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define sz(x) (int)(x).size()
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define emp emplace
#define ft front()
#define bk back()
#define f first
#define s second

#define for1(i, a, b) for (int i = ((int)a); i < ((int)b); i++)
#define for2(i, a) for (int i = 0; i < ((int)a); i++)
#define for3(i, a, b, c) for (int i = a; i < ((int)b); i += c)
#define foreach(i, a) for (auto &i : a)
#define print(a)          \
    foreach (i, a)        \
        cout << i << " "; \
    cout << "\n";

#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yes_no(x) cout << ((x) ? ("YES") : ("NO")) << "\n";
#define impossible cout << "IMPOSSIBLE\n";
#define possible cout << "POSSIBLE\n";

using namespace std;

vi mt;
vector<bool> used;
vector<bool> cover;

bool try_kuhn(int v, vi adj[])
{
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adj[v])
    {
        if (mt[to] == -1 || try_kuhn(mt[to], adj))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void kuhn(int n, int m, vi adj[])
{
    int max_matching = 0;

    mt.assign(m, -1);
    int ans = 0;
    for2(v, n)
    {
        used.assign(n, false);
        if (try_kuhn(v, adj))
            max_matching++;
    }
}

void dfs(int n, vi adj[], vector<bool> &visited, int nn)
{
    visited[n] = true;

    if (n >= nn)
    {
        if (!visited[mt[n - nn]])
            dfs(mt[n - nn], adj, visited, nn);
        return;
    }

    for2(i, adj[n].size()) if (!visited[adj[n][i] + nn]) dfs(adj[n][i] + nn, adj, visited, nn);
}

void vertex_cover(int n, int m, vi adj[])
{
    used.assign(m, false);
    for2(i, m) if (mt[i] != -1) used[mt[i]] = true;

    vector<bool> visited(n + m);
    for2(i, n) if (!used[i] && !visited[i]) dfs(i, adj, visited, n);

    cover.assign(n + m, false);

    for2(i, n) if (!visited[i] && used[i]) cover[i] = true;
    for2(i, m) if (visited[i + n] && mt[i] != -1) cover[i + n] = true;
}

void solve()
{
    int n, m, c, q;
    cin >> n >> m >> c >> q;

    vi adj[n];

    map<pii, int> edges;

    for2(i, c)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].pb(y);

        edges[{x, y}] = i;
    }

    kuhn(n, m, adj);
    vertex_cover(n, m, adj);

    vii ans_queries;

    int sum_edges = 0;

    for2(i, m)
    {
        if (mt[i] != -1 && cover[mt[i]])
        {
            ans_queries.pb({mt[i] + 1, edges[{mt[i], i}] + 1});
            sum_edges += edges[{mt[i], i}] + 1;
        }
        if (mt[i] != -1 && cover[i + n])
        {
            ans_queries.pb({-i - 1, edges[{mt[i], i}] + 1});
            sum_edges += edges[{mt[i], i}] + 1;
        }
    }

    int last = ans_queries.size() - 1;

    for2(i, q)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            auto [v, e] = ans_queries[last];

            last--;

            sum_edges -= e;
            cout << 1 << endl;
            cout << v << endl;
            cout << sum_edges << endl;
        }
        else
        {
            cout << last + 1 << endl;

            for2(i, last + 1)
            {
                cout << ans_queries[i].s << " ";
            }
            cout << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}