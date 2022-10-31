#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,n,m,K,t1,t2,s[3005],cnt,head[3005],nxt[20005],txt[20005],dis[2505][2505];
struct ok{
	int d,z;
};
queue<int> q;
vector<ok> e[3005];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline bool cmp(ok x,ok y){
	return x.z<y.z;
}
inline void js(int x,int p){
	dis[p][x]=1;
	q.push(x);
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=head[t];i;i=nxt[i]){
			if(dis[p][txt[i]]==0){
				dis[p][txt[i]]=dis[p][t]+(int)1;
				q.push(txt[i]);
			}
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),K=read()+(int)2;
	for(int i=2;i<=n;i++) s[i]=read();
	for(int i=1;i<=m;i++){
		t1=read(),t2=read();
		nxt[++cnt]=head[t1],head[t1]=cnt,txt[cnt]=t2;
		nxt[++cnt]=head[t2],head[t2]=cnt,txt[cnt]=t1;
	}
	for(int i=1;i<=n;i++) js(i,i);
	for(int i=2;i<=n;i++){
		if(dis[1][i]<=K){
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				if(dis[i][j]<=K){
					e[j].push_back((ok){i,s[i]+s[j]});
				}
			}
		}
	}
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end(),cmp);
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j) continue;
			if(dis[i][j]>K) continue;
			int sz1=e[i].size()-(int)1,sz2=e[j].size()-(int)1,s1=sz1-(int)3,s2=sz2-(int)3;
			s1=max(s1,(int)0);s2=max(s2,(int)0);
			for(int g=sz1;g>=s1;g--){
				for(int h=sz2;h>=s2;h--){
					if(e[i][g].d==e[j][h].d||i==e[j][h].d||j==e[i][g].d) continue;
					ans=max(ans,e[i][g].z+e[j][h].z);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

