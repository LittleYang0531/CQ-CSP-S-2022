//zxt¿É°®qwq 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void read (int &n) {
	n = 0;

	char c = getchar ();
	bool flag = 0;

	while (c < '0' || c > '9') {
		if (c == '-') {
			flag = 1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar ();
	}
	n = flag ? -n : n;
}

int main () {
	int n, m;
	
	scanf ("%d %d", &n, &m); 
	

	return 0;
}


