// Brute Force
// O(n! * n)

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const char *cityName[] = {"", "北京", "天津", "上海", "珠海", "深圳", "中山", "安阳", "郑州", "许昌", "西安" };
const int INF = 0x3f3f3f3f;
const int N = 20;
int n;
int w[N][N];
int p[N], q[N];
int ans = INF;

int main () {

	scanf("%d", &n);
	for(int x = 1; x < n; ++ x)
		for(int y = x + 1; y <= n; ++ y) {
			int z; scanf("%d", &z);
			w[x][y] = w[y][x] = z;
		}
	
	for(int i = 1; i <= n; ++ i) p[i] = i;
	do {
		int s = 0;
		for(int i = 2; i <= n; ++ i)
			s += w[p[i - 1]][p[i]];
		if(s < ans) {
			ans = s;
			for(int i = 1; i <= n; ++ i)
				q[i] = p[i];
		}
	} while(next_permutation(p + 1, p + n + 1));

	printf("%d\n", ans);
	for(int i = 1; i <= n; ++ i)
		printf("%s ", cityName[q[i]]);
	putchar('\n');
	
	return 0;
}
