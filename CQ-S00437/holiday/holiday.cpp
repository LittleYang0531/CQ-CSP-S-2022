#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,d[2505];
ll ans,a[2505],mx[3][2505];
bool ca[2505][2505];
vector<int>e[2505];
void spfa(int v0) {
	queue<int>q;
	memset(d,0x3f,sizeof(d)),q.push(v0),d[v0]=0;
	while(q.size()) {
		int x=q.front();q.pop();
		ca[v0][x]=1;
		if(d[x]==k)continue;
		for(auto y:e[x])if(d[y]>d[x]+1)d[y]=d[x]+1,q.push(y);
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),k++;
	for(int i=2;i<=n;i++)scanf("%lld",a+i);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=n;i++)spfa(i);
	for(int i=2;i<=n;i++) {
		mx[0][i]=mx[1][i]=mx[2][i]=-1;
		for(int j=2;j<=n;j++) {
			if(i!=j&&ca[i][j]&&ca[1][j]) {
				if(a[j]>mx[0][i])mx[2][i]=mx[1][i],mx[1][i]=mx[0][i],mx[0][i]=a[j];
				else if(a[j]>mx[1][i])mx[2][i]=mx[1][i],mx[1][i]=a[j];
				else mx[2][i]=max(mx[2][i],a[j]);
			}
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=n;j++) {
			if(i!=j&&ca[i][j]) {
				int p=(mx[0][i]==a[j]&&ca[1][j]),q=(mx[0][j]==a[i]&&ca[1][i]);
				if(mx[p][i]==-1||mx[q][j]==-1)continue;
				if(mx[p][i]==mx[q][j]) {
					ll t=max(mx[p+1][i],mx[q+1][j]);
					if(a[i]==t)t=mx[q+2][j];
					if(a[j]==t)t=mx[p+2][i];
					if(t!=-1)ans=max(ans,a[i]+a[j]+mx[p][i]+t);
//					cout<<ans<<" "<<a[i]<<" "<<a[j]<<" "<<mx[p][i]<<" "<<t<<endl;
				}else ans=max(ans,a[i]+a[j]+mx[p][i]+mx[q][j]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
