#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool ST;
const int N=2510,M=2e4+10;
int n,m,k,val[N];
int head[N],to[M],nxt[M],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
int d[N][N];queue<int> q;
void bfs(int *d,int s){
	memset(d,0x3f,sizeof(int)*(n+5));
	d[s]=0,q.push(s);while(!q.empty()){
		int u=q.front();q.pop();
		if(d[u]==k)continue;
		go(u){
			int v=to[i];if(d[v]>d[u]+1){
				d[v]=d[u]+1,q.push(v);
			}
		}
	}
}
int tmp[N],tp;
vector<int> mx1[N],mx2[N];
bool cmp(int i,int j){return val[i]>val[j];}
void brute(int &ans){
	For(A,2,n)if(d[1][A]<=k)For(B,2,n)if(B!=A&&d[A][B]<=k)
		For(C,2,n)if(C!=B&&C!=A&&d[B][C]<=k)
			For(D,2,n)if(D!=C&&D!=B&&D!=A&&d[C][D]<=k&&d[D][1]<=k)
				ans=max(ans,val[A]+val[B]+val[C]+val[D]);
}
bool ED;
signed main(){
//	fprintf(stderr,"%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read()+1;For(i,2,n)val[i]=read();
	For(i,1,m){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}For(i,1,n)bfs(d[i],i);
	For(B,2,n){
		tp=0;
		For(A,2,n)if(B!=A&&d[1][A]<=k&&d[A][B]<=k){
			tmp[++tp]=A;
		}if(tp){
			sort(tmp+1,tmp+1+tp,cmp);
			For(i,1,min(tp,3ll))mx1[B].push_back(tmp[i]);
		}
	}
	For(C,2,n){
		tp=0;
		For(D,2,n)if(C!=D&&d[D][1]<=k&&d[C][D]<=k){
			tmp[++tp]=D;
		}
		if(tp){
			sort(tmp+1,tmp+1+tp,cmp);
			For(i,1,min(tp,3ll))mx2[C].push_back(tmp[i]);
		}
	}int ans=0;
	For(B,2,n)For(C,2,n)if(B!=C&&d[B][C]<=k){
		for(auto A:mx1[B])for(auto D:mx2[C]){
			if(A!=D&&A!=C&&D!=B)ans=max(ans,val[A]+val[B]+val[C]+val[D]);
		}
	}cout<<ans<<endl;
	return 0;
}
