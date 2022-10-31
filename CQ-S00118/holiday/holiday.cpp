// Fight For the ASoul Kingdom.
#include <queue>
#include <cstdio>
using namespace std;

typedef long long LL;
LL Abs (LL x) { return x < 0 ? -x : x; }
LL Max (LL x, LL y) { return x > y ? x : y; }
LL Min (LL x, LL y) { return x < y ? x : y; }

int Read () {
	int x = 0, k = 1;
	char s = getchar ();
	while (s < '0' || s > '9') {
		if (s == '-')
			k = -1;
		s = getchar ();
	}
	while ('0' <= s && s <= '9')
		x = (x << 3) + (x << 1) + (s ^ 48), s = getchar ();
	return x * k;
}

void Write (LL x) {
	if (x < 0)
		putchar ('-'), x = -x;
	if (x > 9)
		Write (x / 10);
	putchar (x % 10 + '0');
}

void Print (LL x, char s) { Write (x), putchar (s); }

const int Maxn = 2505;

LL Val[Maxn];
queue <int> q;
bool Vis[Maxn];
int Dis[Maxn][Maxn], n, m, k;
vector <int> Graph[Maxn], To[Maxn];

void Add_Edge (int u, int v) { Graph[u].push_back (v), Graph[v].push_back (u); }

void Bfs (int s) {
	for (int i = 1; i <= n; i++)
		Vis[i] = false, Dis[s][i] = -1;
	Dis[s][s] = 0, Vis[s] = true, q.push (s);
	while (!q.empty ()) {
		int u = q.front (); q.pop ();
		if (s != u && u != 1)
			To[s].push_back (u);
		for (int i = 0, v; i < Graph[u].size (); i++) {
			v = Graph[u][i];
			if (Vis[v])
				continue;
			if (Dis[s][u] + 1 <= k + 1)
				Dis[s][v] = Dis[s][u] + 1, Vis[v] = true, q.push (v);
		}
	}
}

int main () {
	freopen ("holiday.in", "r", stdin);
	freopen ("holiday.out", "w", stdout);
	n = Read (), m = Read (), k = Read ();
	for (int i = 2; i <= n; i++)
		scanf ("%lld", &Val[i]);
	for (int i = 1, u, v; i <= m; i++)
		u = Read (), v = Read (), Add_Edge (u, v);
	for (int i = 1; i <= n; i++)
		Bfs (i);
	LL Res = 0;
	for (int i = 0, a; i < To[1].size (); i++) {
		a = To[1][i];
		for (int j = 0, b; j < To[a].size (); j++) {
			b = To[a][j];
			for (int x = 0, c; x < To[b].size (); x++) {
				c = To[b][x];
				if (c != a)
					for (int y = 0, d; y < To[1].size (); y++) {
						d = To[1][y];
						if (d != a && d != b && d != c && Dis[c][d] != -1)
							Res = Max (Res, Val[a] + Val[b] + Val[c] + Val[d]);
					}
			}			
		}	
	}			
	Print (Res, '\n'); 
	return 0;
}
