#include <bits/stdc++.h>
using namespace std;

int n;
char s[20000], t[20000];
int dif[20000];
int use[30], val[30];

int main()

{
    scanf("%d", &n);
    scanf("%s", s+1);
    vector<string> ans;
    for (int k = 1;k <= n; ++k)
    {
        int cnt = 0;
        memset(val, 0, sizeof(val));
        memset(use, 0, sizeof(use));
        for (int i = k;i >= 1; --i)
        {
            dif[i] = cnt;
            if (use[s[i]-'a'] == 0) cnt++;
            use[s[i]-'a'] = 1;
            if (val[s[i]-'a'] == 0)
            {
                val[s[i]-'a'] = dif[i]+1;
            }
        }
        string tmp = "";
        for (int i = 1;i <= k; ++i)
        {
            tmp += val[s[i]-'a']-1+'a';
        }
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());

    string tmp = ans.back();
    int tmp_len = tmp.length();
    for (int i = 0;i < tmp_len; ++i)
    {
        printf("%c", tmp[i]);
    }
    puts("");

    return 0;
}
