#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pii pair <int , int>
#define pll pair <LL , LL>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(x<0) {putchar('-');x=-x;}
	if(!x) {putchar('0');putchar(s);return;}
	T tmp[25] = {} , t = 0;
	while(x) tmp[t ++] = x % 10 , x /= 10;
	while(t-->0) putchar('0' + tmp[t]);
	putchar(s);
}

const int MAXN = 1e5 + 5;

int st[6][MAXN][22];
/*
0: Mx A   1: Mn A
2: Mx A for A_i < 0
3: Mn A for A_i > 0
4: Mx B
5: Mn B
*/
int A[MAXN] , B[MAXN] , n , m , Q , Lg[MAXN];

inline int calc(int k , int x , int y) {
	int t = Lg[y - x + 1];
	if(k & 1) return min(st[k][x][t] , st[k][y - (1 << t) + 1][t]);
	return max(st[k][x][t] , st[k][y - (1 << t) + 1][t]);
}

int main() {
	freopen("game.in" , "r" , stdin);
	freopen("game.out" , "w" , stdout);
	read(n),read(m),read(Q);
	Lg[0] = -1;
	for (int i = 1; i <= max(n , m); ++i) Lg[i] = Lg[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) {
		read(A[i]);
		st[0][i][0] = st[1][i][0] = A[i];
		st[2][i][0] = (A[i] <= 0?A[i]:-2e9);
		st[3][i][0] = (A[i] >= 0?A[i]:2e9);
	}
	
	for (int k = 0; k < 4; k += 2) {
		for (int j = 1; (1 << j) <= n; ++j) {
			for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
				st[k][i][j] = max(st[k][i][j - 1] , st[k][i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	
	for (int k = 1; k < 4; k += 2) {
		for (int j = 1; (1 << j) <= n; ++j) {
			for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
				st[k][i][j] = min(st[k][i][j - 1] , st[k][i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	
	
	for (int i = 1; i <= m; ++i) {
		read(B[i]);
		st[4][i][0] = st[5][i][0] = B[i];
	}
	
	for (int j = 1; (1 << j) <= m; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
			st[4][i][j] = max(st[4][i][j - 1] , st[4][i + (1 << (j - 1))][j - 1]);
		}
	}
	
	for (int j = 1; (1 << j) <= m; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
			st[5][i][j] = min(st[5][i][j - 1] , st[5][i + (1 << (j - 1))][j - 1]);
		}
	}
	/*
	0: Mx A   1: Mn A
	2: Mx A for A_i < 0
	3: Mn A for A_i > 0
	4: Mx B
	5: Mn B
	*/
	while(Q -- > 0) {
		int l1 , r1 , l2 , r2;
		read(l1),read(r1),read(l2),read(r2);
		LL Mx1 = calc(0 , l1 , r1) , Mn1 = calc(1 , l1 , r1);
		LL Mx2 = calc(4 , l2 , r2) , Mn2 = calc(5 , l2 , r2);
		if(Mn2 >= 0) {
			if(Mx1 <= 0) write(Mx1 * Mx2);
			else write(Mx1 * Mn2);
		}
		else if(Mx2 <= 0) {
			if(Mn1 >= 0) write(Mn1 * Mn2);
			else write(Mn1 * Mx2);
		}
		else {
			if(Mn1 >= 0) write(Mn1 * Mn2);
			else if(Mx1 <= 0) write(Mx1 * Mx2);
			else write(max(Mx2 * calc(2 , l1 , r1) , Mn2 * calc(3 , l1 , r1)));
		}
	}
	
	return 0;
}
