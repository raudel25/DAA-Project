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

int dp[64][64][3];

int mod = 1e9 + 7;

pair<pii, int> func(int n, int k)
{
    if (k < 0)
        return {{0, 0}, 0};

    int m = 63 - __builtin_clzll(n);

    if ((1ll << m) == n)
        return {{dp[m][k][0], dp[m][k][1]}, dp[m][k][2]};

    auto [q1, ans1] = func((1ll << m), k);
    auto [l1, r1] = q1;

    auto [q2, ans2] = func(n - (1ll << m), k - 1);
    auto [l2, r2] = q2;

    if (l1 == (1ll << m))
        l1 += l2;

    if (r2 == n - (1ll << m))
        r2 += r1;

    int ans = ((ans1 + ans2) % mod + ((r1 % mod) * (l2 % mod)) % mod) % mod;
    return {{l1, r2}, ans};
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int m = 63 - __builtin_clzll(n);

    for2(i, m + 1)
    {
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
        dp[i][0][2] = 1;
    }

    for2(i, k + 1)
    {
        dp[0][i][0] = 1;
        dp[0][i][1] = 1;
        dp[0][i][2] = 1;
    }

    for1(i, 1, m + 1) for1(j, 1, k + 1)
    {
        int l1 = dp[i - 1][j][0];
        int r1 = dp[i - 1][j][1];
        int ans1 = dp[i - 1][j][2];

        int l2 = dp[i - 1][j - 1][0];
        int r2 = dp[i - 1][j - 1][1];
        int ans2 = dp[i - 1][j - 1][2];

        if (l1 == (1ll << (i - 1)))
            l1 += l2;

        if (r2 == (1ll << (i - 1)))
            r2 += r1;

        int ans = ((ans1 + ans2) % mod + ((r1 % mod) * (l2 % mod)) % mod) % mod;

        dp[i][j][0] = l1;
        dp[i][j][1] = r2;
        dp[i][j][2] = ans;
    }

    cout << func(n, k).s << "\n";
    ;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}