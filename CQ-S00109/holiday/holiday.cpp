#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N = 3e3+10,M = 1e4+10;
int n,m,k,cnt,ans;
int a[N],hed[N],nex[M<<1],to[M<<1],d[N][N];
queue<int>p;
vector<int>px[N];
bool cmp(int x,int y){return a[x]>a[y];}
void add(int u,int v){
	nex[++cnt]=hed[u],hed[u]=cnt,to[cnt]=v;
	nex[++cnt]=hed[v],hed[v]=cnt,to[cnt]=u;
}
void bfs(int x){
	p.push(x),d[x][x] = 0;
	while(!p.empty()){
		int u = p.front();p.pop();
		for(int i = hed[u];i;i=nex[i])
			if(d[x][u]+1<d[x][to[i]]) d[x][to[i]]=d[x][u]+1,p.push(to[i]);
	}
}
void init(){
	memset(d,0x3f,sizeof(d));
	for(int i = 1;i<=n;i++) bfs(i);
}
void solve(){
	for(int i = 1;i<=n;i++){
		for(int j = 2;j<=n;j++){
			if(i==j or d[i][j]>k or d[1][j]>k) continue;
			px[i].push_back(j);
		}
		sort(px[i].begin(),px[i].end(),cmp);
	}
	for(int i = 2;i<=n;i++){
		if(px[i].empty()) continue;
		for(int j = i+1;j<=n;j++){
			if(d[i][j]>k or px[j].empty()) continue;
			int l = (px[i][0]==j),r = (px[j][0]==i);
			if(l==px[i].size() or r==px[j].size()) continue;
			int ad = a[px[i][l]]+a[px[j][r]];
			if(px[i][l]==px[j][r]){
				int mx = 0;ad-=a[px[i][l]],l++,r++;
				while(l<px[i].size() and px[i][l]==j) l++;
				while(r<px[j].size() and px[j][r]==i) r++;
				if(l<px[i].size()) mx=max(mx,ad+a[px[i][l]]);
				if(r<px[j].size()) mx=max(mx,ad+a[px[j][r]]);
				if(!mx) continue;ad = mx;
			}
			ans = max(ans,ad+a[i]+a[j]);
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n = read(),m = read(),k = read()+1;
	for(int i = 2;i<=n;i++) a[i] = read();
	for(int i = 1;i<=m;i++) add(read(),read());
	init(),solve(),write(ans);
	return 0;
}

