//
// Created by Wepdekr on 2021/11/21.
//

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int zl[10][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 1, 1, 1}
};

const int N = 10 * 10 * 10 * 10 + 100;
const int M = N * 20 + 1000;

int head[N], nex[M], to[M];

inline void addEdge(int u, int v) {
    static int cc = 0;
    nex[++cc] = head[u], head[u] = cc;
    to[cc] = v;
}

inline int getNex(int u, int i, int e) {
    int a = u % 10, b = u / 10 % 10, c = u / 100 % 10, d = u / 1000;
    a += e * zl[i][0], b += e * zl[i][1], c += e * zl[i][2], d += e * zl[i][3];
    if(a == 10) a = 0;
    if(b == 10) b = 0;
    if(c == 10) c = 0;
    if(d == 10) d = 0;
    if(a == -1) a = 9;
    if(b == -1) b = 9;
    if(c == -1) c = 9;
    if(d == -1) d = 9;
    return a + b * 10 + c * 100 + d * 1000;
}

queue<int> Q; int dis[N];

inline int modify(int u, int e) {
    int a = u % 10, b = u / 10 % 10, c = u / 100 % 10, d = u / 1000;
    int x = e % 10, y = e / 10 % 10, z = e / 100 % 10, w = e / 1000;
    a -= x, b -= y, c -= z, d -= w;
    if(a < 0) a += 10;
    if(b < 0) b += 10;
    if(c < 0) c += 10;
    if(d < 0) d += 10;
    return a + b * 10 + c * 100 + d * 1000;
}

int main() {
    for(int i = 0; i <= 9999; i++) {
        for(int j = 0; j < 10; j++) {
            int v1 = getNex(i, j, 1), v2 = getNex(i, j, -1);
            addEdge(i, v1), addEdge(i, v2);
        }
    }
    dis[0] = 1, Q.push(0);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = head[u]; i; i = nex[i]) {
            if(!dis[to[i]]) {
                dis[to[i]] = dis[u] + 1;
                Q.push(to[i]);
            }
        }
    }
    int T; scanf("%d", &T);
    while(T--) {
        int a, b; scanf("%d%d", &a, &b);
        b = modify(b, a);
        //printf("b = %d\n", b);
        printf("%d\n", dis[b] - 1);
    }
    return 0;
}
