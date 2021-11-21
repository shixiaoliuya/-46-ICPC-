#include <bits/stdc++.h>
using namespace std;

int dp[200010], vis[200010];
int add[15][5] = {
{0, 0, 0, 0, 0},
{0, 1, 1, 1, 1},
{0, 1, 1, 1, 0},
{0, 0, 1, 1, 1},
{0, 1, 1, 0, 0},
{0, 0, 1, 1, 0},
{0, 0, 0, 1, 1},
{0, 1, 0, 0, 0},
{0, 0, 1, 0, 0},
{0, 0, 0, 1, 0},
{0, 0, 0, 0, 1},
};
int a, b;
int ar[5], br[5], v[5], tmp[5];
int bfs_arr[5];


int cel(int *v)
{
    int sum = 0;
    for (int i = 1;i <= 4; ++i)
    {
        sum = sum*10+v[i];
    }
    return sum;
}

void solve()
{

    scanf("%d%d", &a, &b);
    for (int i = 4; i >= 1; --i)
    {
        ar[i] = a%10;
        br[i] = b%10;
        a /= 10;
        b /= 10;
        br[i] = (10 + br[i]-ar[i])%10;
    }
    ¡¢¡¢for (int i = 1;i <= 4; ++i) cout << br[i] << ' '; cout << endl;
    printf("%d\n", dp[cel(br)]);
}


void bfs()
{
    dp[0] = 0;
    for (int i = 0;i < 10000; ++i)
    {
        //dp[i] = 1;
        //cout << i << endl;
        //assert(dp[i] >= 0);
        if (dp[i] == -1) continue;
        //cout << "---" << endl;
        int x = i;
        for (int k = 4;k >= 1; --k)
        {
            v[k] = x%10;
            x /= 10;
        }
        for (int t = 1;t <= 9; ++t)
        {
            for (int j = 1;j <= 10; ++j)
            {
                bool ok = 1;
                int cnt = min(t, 10-t);
                for (int k = 1;k <= 4; ++k)
                    tmp[k] = (v[k]+t*add[j][k])%10;
                //for (int k = 1;k <= 4; ++k) cout << tmp[k] << ' '; cout << endl;
                if (dp[cel(tmp)] == -1) dp[cel(tmp)] = dp[i]+cnt;
                else dp[cel(tmp)] = min(dp[cel(tmp)], dp[i]+cnt);
            }
        }
    }

}

int main()
{
    memset(dp, -1, sizeof(dp));
    bfs();
    int T;
    scanf("%d", &T);
    while(T--) solve();

    return 0;
}
