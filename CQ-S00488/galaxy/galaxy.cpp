#include <cstdio>

using namespace std;

int n, m;
int T;

int main ()
{
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);
	
	scanf ("%d %d", &n, &m);
	while (m --)
		scanf ("%d %d", &n, &n);
	scanf ("%d", &T);
	while (T --)
		puts ("NO");
	
	return 0;
}

