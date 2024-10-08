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

void solve()
{
    int n;
    cin >> n;

    vi g(n);
    vi r(n);

    for2(i, n) cin >> g[i] >> r[i];

    if (n == 1)
    {
        cout << "N\n";
        return;
    }

    int c = r[0];

    unordered_map<int, int> m;
    for2(i, n) c = gcd(r[i], c);

    int ss = 0;

    bool w = false;
    for2(i, n)
    {
        ss += g[i];
        if (g[i] == 0)
            w = true;
        m[g[i]]++;
    }

    vii g_count;

    foreach (i, m)
    {
        g_count.pb({i.f, i.s});
    }

    int dp[m.size()][ss + 1];

    for2(i, m.size()) dp[i][0] = 0;

    for2(i, m.size()) for1(j, 1, ss + 1)
    {
        if (i != 0 && dp[i - 1][j] >= 0)
        {
            dp[i][j] = 0;
            continue;
        }

        if (j >= g_count[i].f && dp[i][j - g_count[i].f] >= 0 && dp[i][j - g_count[i].f] < g_count[i].s)
        {
            dp[i][j] = dp[i][j - g_count[i].f] + 1;
            continue;
        }

        dp[i][j] = -1;
    }

    for2(j, ss + 1)
    {
        if (dp[g_count.size() - 1][j] == -1)
            continue;

        if ((j == 0 || j == ss) && !w)
            continue;

        int q = abs(ss - 2 * j);

        if (q % c == 0)
        {
            cout << "Y\n";
            return;
        }
    }

    cout << "N\n";
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