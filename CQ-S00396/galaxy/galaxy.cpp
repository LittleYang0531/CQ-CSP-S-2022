#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,Q,t1,t2,t3,t4,cnt,T[500005],head[500005],nxt[1000005],txt[1000005],zhi[1000005];
bool v[500005];
struct ok{
	int x,y;
	bool operator < (const ok &A) const{
		if(x==A.x) return y<A.y;
		return x<A.x;
	}
};
vector<ok> e[500005];
vector<ok> w[500005];
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
	return x.x<y.x;
}
inline int find(int x,int y){
	int sz=w[x].size()-1;
	int l=0,r=sz;
	while(l<=r){
		int mid=(l+r)>>1;
		if(w[x][mid].x<y) l=mid+1;
		else if(w[x][mid].x>y) r=mid-1;
		else return w[x][mid].y;
	}
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) v[i]=1;
	for(int i=1;i<=m;i++){
		t1=read(),t2=read();
		nxt[++cnt]=head[t1],head[t1]=cnt,txt[cnt]=t2,zhi[cnt]=1;
		T[t1]++;
		w[t1].push_back((ok){t2,cnt});
		e[t2].push_back((ok){t1,cnt});
	}
	for(int i=1;i<=n;i++) sort(w[i].begin(),w[i].end(),cmp);
	for(int i=1;i<=n;i++) if(T[i]==1) ans++;
	Q=read();
	for(int i=1;i<=Q;i++){
		t1=read(),t2=read();
		if(t1==1){
			t3=read();
			int d=find(t2,t3);
			zhi[d]=0;
			T[t2]--;
			if(T[t2]==0) ans--;
			else if(T[t2]==1) ans++;
		}
		if(t1==2){
			int sz=e[t2].size()-1;
			for(int j=0;j<=sz;j++){
				if(zhi[e[t2][j].y]==1){
					T[e[t2][j].x]--;
					if(T[e[t2][j].x]==0) ans--;
					else if(T[e[t2][j].x]==1) ans++;
					zhi[e[t2][j].y]=0;	
				}
			}
		}
		if(t1==3){
			t3=read();
			int d=find(t2,t3);
			zhi[d]=1;
			T[t2]++;
			if(T[t2]==1) ans++;
			else if(T[t2]==2) ans--;
		}
		if(t1==4){
			int sz=e[t2].size()-1;
			for(int j=0;j<=sz;j++){
				if(zhi[e[t2][j].y]==0){
					T[e[t2][j].x]++;
					if(T[e[t2][j].x]==1) ans++;
					else if(T[e[t2][j].x]==2) ans--;
					zhi[e[t2][j].y]=1;	
				}
			}
		}
		if(ans==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
还有十分钟，感觉会做了，但是写不完了。 
开摆,rp++，希望我仅有的分不要挂
就算不挂，也完蛋了，要死了 
*/
