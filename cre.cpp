#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("test.in", "w", stdout);
    int n = 10000;
    int m = n-1;
    cout << n << ' ' << m << endl;
    for (int i = 1;i < n; ++i)
    {
        cout << i << ' ' << i+1 << ' ' << ((1<<30)-1) << endl;
    }

    return 0;
}
