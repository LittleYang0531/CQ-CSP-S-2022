#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;
int n,m,k,idx,ans;
int arr[N],ne[N],e[N],h[N];
bool vis[N];

int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = r * 10 + c - '0';
		c = getchar();
	}
	return r * w;
}

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u,int fa,int res,int w){
	if (res == 4){
		ans = max(ans,w);
		return;
	}
	for (int i = h[u];~i;i = ne[i]){
		int j = e[i];
		if (j != fa && !vis[j]){
			vis[j] = true;
			dfs(j,u,res + 1,w + arr[j]);
			vis[j] = false;
		}
	}
}

signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof(h));
	n = read();
	m = read();
	k = read();
	for (int i = 2;i <= n;i++) arr[i] = read();
	for (int i = 1;i <= m;i++){
		int a,b;
		a = read();
		b = read();
		add(a,b);
		add(b,a);
	}
	if (k == 0){
		vis[1] = true;
		dfs(1,0,0,0);
		printf("%lld",ans);
	}
	else{
		int ans = 0; 
		sort(arr + 1,arr + 1 + n);
		for (int i = n;i;i--) ans += arr[i];
		printf("%lld",ans); 
	}
	return 0;
}

/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
