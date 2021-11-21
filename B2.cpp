#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n, m;
int color[N], edge[2*N][35];
int a, b;
vector<pair<int, int>> G[N];
bool dfs(int u, int j, int c, int pre)
{
    color[u] = c;
    if (c == 1) a++;
    if (c == 2) b++;
    for (auto pi : G[u]) if (pi.second != pre)
    {
        int v = pi.second;
        int sta = edge[pi.first][j];
        if (color[v] == 0)
        {
            int next_c = (sta == 1) ? (3-c) : c;
            bool tmp = dfs(v, j, next_c, u);
            if (!tmp) return false;
        }
        else if ((sta == 1 && c == color[v]) || (sta == 2 && c != color[v]))
            return false;
    }
    return true;
}

int main()
{
    //freopen("test.in", "r", stdin);
    //cout << 1LL*(10000/2)*((1<<30)-1) << endl;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(make_pair(i, v));
        G[v].push_back(make_pair(i, u));
        for (int j = 0;j < 30; ++j)
        {
            if ((w>>j) & 1)
            {
                edge[i][j] = 1;
            }
            else
            {
                edge[i][j] = 2;
            }
        }
    }
    ll sum = 0;
    bool tmp;
    //cout << "ok" << endl;
    for (int j = 0;j < 30; ++j)
    {
        memset(color, 0, sizeof(color));
        int tmp_sum = 0;
        for (int i = 1;i <= n; ++i)
        {
            if (G[i].empty()) continue;
            if (color[i] == 0)
            {
                a = 0;
                b = 0;
                tmp = dfs(i, j, 1, 0);
                //cout << a << ' ' << b << endl;
                if (!tmp)
                {
                    //cout << j << endl;
                    puts("-1");
                    return 0;
                }
                tmp_sum += min(a, b);
            }

        }
        //cout << j << ' ' << tmp_sum << endl;
        //cout << 1LL*tmp_sum*(1LL<<j) << endl;
        sum += 1LL*tmp_sum*(1LL<<j);
    }
    printf("%lld\n", sum);

    return 0;
}
/*

4 4
1 2 3
2 3 3
3 4 3
4 1 3
*/
