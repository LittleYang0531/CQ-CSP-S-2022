#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,h[2501],cnt,h1[2501],cnt1,f[2501];
long long s[2501],ans,jyh[2501][2501][6];
struct qx{
	int to,next;
}a[20001];
struct qxx{
	int to,next;
}aa[200001];
void hb(int x,int y){
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void hb1(int x,int y){
	cnt1++;
	aa[cnt1].to=y;
	aa[cnt1].next=h1[x];
	h1[x]=cnt1;
}
void dfs(int x,int pre,int kk,long long d){
	if(x==1&&kk==5){
		ans=max(ans,d);
		return;
	}
	if(kk==5){
		return;
	}
	for(int i=h[x];i!=0;i=a[i].next){
		int y=a[i].to;
		if(!f[y]){
			if(jyh[y][x][kk+1]<d+s[y]){
				f[y]=1;
				jyh[y][x][kk+1]=d+s[y];
				dfs(y,x,kk+1,d+s[y]);
				f[y]=0;
			}
		}
	}
}
void dfss(int dx,int x,int pre,int d){
	if(d>k) return;
	if(pre){
		hb1(dx,x);
	}
	for(int i=h[x];i!=0;i=a[i].next){
		int y=a[i].to;
		if(y==pre) continue;
		dfss(dx,y,x,d+1);
	}
}
void dfsss(int x,int pre,int kk,long long d){
	if(x==1&&kk==5){
	//	cout<<d<<endl;
		ans=max(ans,d);
		return;
	}
	if(kk==5){
		return;
	}
	for(int i=h1[x];i!=0;i=aa[i].next){
		int y=aa[i].to;
		if(!f[y]){
			if(jyh[y][x][kk+1]<d+s[y]){
				f[y]=1;
				jyh[y][x][kk+1]=d+s[y];
				dfsss(y,x,kk+1,d+s[y]);
				f[y]=0;
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		hb(x,y);
		hb(y,x);
	}
	if(k==0){
		dfs(1,0,0,0);
		printf("%lld",ans);
	}else{
		for(int i=1;i<=n;i++){
			dfss(i,i,0,-1);
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<":";
//			for(int j=h1[i];j!=0;j=aa[j].next){
//				int y=aa[j].to;
//				cout<<y<<" ";
//			}
//			cout<<endl;
//		}
		dfsss(1,0,0,0);
		printf("%lld",ans);
	}
	return 0;
}
