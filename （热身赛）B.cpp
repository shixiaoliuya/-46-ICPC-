#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+10;

int suf_min[N];
int a[N];

int n;

int main()
{
    //freopen("test.in", "r", stdin);
    int x;
    for (int i = 1;i <= 100000000; ++i)
    {
        a[i%1000] = ++x;
    }

    scanf("%d", &n);
    int pre = 1;
    int cnt = 0;
    for (int i = 1;i <= n; ++i)
        scanf("%d", &a[i]);
    suf_min[n] = a[n];
    for (int i = n-1;i >= 1; --i)
    {
        suf_min[i] = min(suf_min[i+1], a[i]);
    }
    int pre_max = a[1];
    for (int i = 2;i <= n; ++i)
    {
        if (pre_max <= suf_min[i])
        {
            pre = i;
            pre_max = a[i];
            cnt++;
        }
        else pre_max = max(pre_max, a[i]);
    }
    printf("%d\n", ++cnt);

    return 0;
}
