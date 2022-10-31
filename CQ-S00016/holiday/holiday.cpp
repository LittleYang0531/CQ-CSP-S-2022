#include<bits/stdc++.h>
using namespace std; 
const int N=2505,M=10005;
inline long long read(){long long f=0;char c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))f=(f<<3)+(f<<1)+c-'0',c=getchar();return f;}
void write(long long x){if(x>=10)write(x/10);putchar(x%10+'0');return;}
int n,m,k,num[N],cnt[N],f[N][N],p[N][N];
bool inq[N];
long long ans;
struct P {
	long long s;
	int id;
}a[N];
vector<int>G[N];
inline bool cmp(P x,P y) {
	return x.s<y.s;
}
queue<int>q;
void spfa(int st) {
	f[st][st]=0;
	q.push(st);
	while (!q.empty()) {
		int p=q.front();
		q.pop();
		inq[p]=0;
		int siz=G[p].size();
		for (int j=0;j<siz;j++) {
			int x=G[p][j];
			if (f[st][p]+1<f[st][x]) {
				f[st][x]=f[st][p]+1;
				if (!inq[x]) inq[x]=1,q.push(x);
			}
		}
	}
	return;
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	a[1].id=1;
	for (int i=2;i<=n;i++) scanf("%lld",&a[i].s),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) num[a[i].id]=i;
	memset(f,63,sizeof f);
	for (int i=1;i<=m;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		x=num[x],y=num[y];
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++) spfa(i);
	for (int i=2;i<=n;i++) {
		for (int j=n;j>=2;j--) if (f[i][j]<=k+1&&f[1][j]<=k+1&&j!=i) p[i][++cnt[i]]=j;
	}
	for (int i=2;i<=n;i++) {
		for (int j=2;j<=n;j++) {
			if (i==j||f[i][j]>k+1) continue;
			int idxn1=1,idxn2=1;
			if (p[i][idxn1]==j) idxn1++;
			if (p[j][idxn2]==i) idxn2++;
			if (idxn1>cnt[i]||idxn2>cnt[j]) continue;
			if (p[i][idxn1]==p[j][idxn2]) {
				int IDXN=idxn1+1;
				if (p[i][IDXN]==j) IDXN++;
				if (IDXN<=cnt[i]) ans=max(ans,a[i].s+a[j].s+a[p[i][IDXN]].s+a[p[j][idxn2]].s);
				IDXN=idxn2+1;
				if (p[j][IDXN]==i) IDXN++;
				if (IDXN<=cnt[j]) ans=max(ans,a[i].s+a[j].s+a[p[i][idxn1]].s+a[p[j][IDXN]].s);
			} else {
				ans=max(ans,a[i].s+a[j].s+a[p[i][idxn1]].s+a[p[j][idxn2]].s);
			}
		}
	}
	cout<<ans;
	return 0;
}
