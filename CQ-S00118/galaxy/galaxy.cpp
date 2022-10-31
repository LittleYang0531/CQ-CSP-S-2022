// Fight For the ASoul Kingdom.
#include <map>
#include <cstdio>
#include <vector>
using namespace std;

int Abs (int x) { return x < 0 ? -x : x; }
int Max (int x, int y) { return x > y ? x : y; }
int Min (int x, int y) { return x < y ? x : y; }

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

void Write (int x) {
	if (x < 0)
		putchar ('-'), x = -x;
	if (x > 9)
		Write (x / 10);
	putchar (x % 10 + '0');
}

void Print (int x, char s) { Write (x), putchar (s); }

const int Maxn = 5e5 + 5;

int Deg[Maxn];
map <int, int> Vis[Maxn];
vector <int> Graph[Maxn];

void Add_Edge (int u, int v) { Graph[v].push_back (u); }

int main () {
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);
	int n = Read (), m = Read ();
	for (int i = 1, u, v; i <= m; i++)
		u = Read (), v = Read (), Deg[u]++, Vis[u][v] = true, Add_Edge (u, v);
	bool Res = true;
	for (int i = 1; i <= n; i++)
		if (!Deg[i]) {
			Res = false;
			break;
		}
	if (!Res) {
		int q = Read ();
		for (int i = 1, Opt, u, v; i <= q; i++) {
			Opt = Read ();
			if (Opt == 1) 
				u = Read (), v = Read ();
			else if (Opt == 2) 
				u = Read ();
			else if (Opt == 3) 
				u = Read (), v = Read ();
			else 
				u = Read ();
			printf ("NO\n");
		}
		return 0;
	}
	int q = Read ();
	for (int i = 1, Opt, u, v; i <= q; i++) {
		Opt = Read ();
		if (Opt == 1) 
			u = Read (), v = Read (), Deg[u]--, Vis[u][v] = false;
		else if (Opt == 2) {
			u = Read ();
			for (int j = 0, v; j < Graph[u].size (); j++) {
				v = Graph[u][j];
				if (Vis[v][u])
					Deg[v]--, Vis[v][u] = false;
			}
		}
		else if (Opt == 3) 
			u = Read (), v = Read (), Deg[u]++, Vis[u][v] = true;
		else {
			u = Read ();
			for (int j = 0, v; j < Graph[u].size (); j++) {
				v = Graph[u][j];
				if (!Vis[v][u])
					Deg[v]++, Vis[v][u] = true;
			}			
		}
		bool Flag = true;
		for (int j = 1; j <= n; j++)
			if (Deg[j] != 1) {
				Flag = false;
				break;
			}
		if (Flag)
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}

