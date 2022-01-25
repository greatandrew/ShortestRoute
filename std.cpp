// Standard
// O(2^n * n^2)

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const char *cityName[] = { "北京", "天津", "上海", "珠海", "深圳", "中山", "安阳", "郑州", "许昌", "西安" };
const int INF = 0x3f3f3f3f;
const int N = 10;
const int S = (1 << N);
int n, all;
int w[N][N];
int f[N][S], g[N][S];

inline void upd (int &x, int &s) {
	int y = g[x][s];
	s -= (1 << x);
	x = y;
}

int main () {
	
	scanf("%d", &n); all = (1 << n) - 1;
	for(int x = 0; x < n - 1; ++ x)
		for(int y = x + 1; y < n; ++ y) {
			int z; scanf("%d", &z);
			w[x][y] = w[y][x] = z;
		}
	
	memset(g, -1, sizeof g);
	memset(f, 0x3f, sizeof f);
	for(int x = 0; x < n; ++ x)
		f[x][1 << x] = 0;
	for(int s = 1; s <= all; ++ s) {
		for(int x = 0; x < n; ++ x) {
			if(f[x][s] == INF) continue;
			for(int y = 0; y < n; ++ y) {
				if((s >> y) & 1) continue;
				int t = s | (1 << y), v = f[x][s] + w[x][y];
				if(v < f[y][t]) f[y][t] = v, g[y][t] = x;
			}
		}
	}
	
	int ans = INF, st;
	for(int x = 0; x < n; ++ x)
		if(f[x][all] < ans) ans = f[x][all], st = x;
	
	printf("%d\n", ans);
	for(int x = st, s = all; ~x; upd(x, s))
		printf("%s ", cityName[x]);
	putchar('\n');
	
	return 0;
}
