#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll V=1e18;
char AAA;
int M;//矩阵大小 
struct Mat{
	ll a[5][5];
	void O(){for(int i=0;i<M;i++)for(int j=0;j<M;j++)a[i][j]=V;}
	void E(){for(int i=0;i<M;i++)for(int j=0;j<M;j++)a[i][j]=(i==j?0:V);}
}f[20][200005],v[200005];
Mat operator *(const Mat &x,const Mat &y){
	Mat z;
	z.O();
	for(int i=0;i<M;i++)
		for(int k=0;k<M;k++)
			for(int j=0;j<M;j++)
				z.a[i][j]=min(z.a[i][j],x.a[i][k]+y.a[k][j]);
	return z;
}
int n,q,K,a[200005],p[20][200005],d[200005],b[200005];
vector<int> g[200005];
//800MB，等会卡常再改 
namespace Solve1{

ll s[200005];
int PX,PY;
void dfs(int x,int fa){
	p[0][x]=fa,d[x]=d[fa]+1,s[x]=s[fa]+a[x];
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
}
int LCA(int x,int y){
	bool rev=0;
	if(d[x]<d[y])swap(x,y),rev=1;
	for(int i=17;i>=0;i--)if(d[x]-(1<<i)>=d[y])x=p[i][x];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(p[i][x]^p[i][y])x=p[i][x],y=p[i][y];
	PX=x,PY=y;
	if(rev)swap(PX,PY);
	return p[0][x];
}
void main(){
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=17;i++)for(int j=1;j<=n;j++)p[i][j]=p[i-1][p[i-1][j]];
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		int lca=LCA(x,y);
		printf("%lld\n",s[x]+s[y]-s[lca]-s[p[0][lca]]);
	}
}

}
namespace Solve2{

ll s[200005];
int PX,PY;
void dfs(int x,int fa){
	p[0][x]=fa,d[x]=d[fa]+1,s[x]=s[fa]+a[x];
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
}
int LCA(int x,int y){
	bool rev=0;
	if(d[x]<d[y])swap(x,y),rev=1;
	for(int i=17;i>=0;i--)if(d[x]-(1<<i)>=d[y])x=p[i][x];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(p[i][x]^p[i][y])x=p[i][x],y=p[i][y];
	PX=x,PY=y;
	if(rev)swap(PX,PY);
	return p[0][x];
}
Mat Getmat(int fr,int to){
	Mat ret;
	ret.E();
	for(int i=17;i>=0;i--){
		if(d[fr]-(1<<i)>=d[to]){
			ret=f[i][fr]*ret;
			fr=p[i][fr];
		}
	}
	return ret;
}
void main(){
	M=2; 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		v[i].O();
		v[i].a[0][0]=v[i].a[0][1]=a[i];
		v[i].a[1][0]=0;
	}
	for(int i=1;i<=n;i++){
		if(p[0][i]){
			f[0][i]=v[p[0][i]];
		}
	}
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=p[i-1][p[i-1][j]];
			if(p[i][j]){
				f[i][j]=f[i-1][p[i-1][j]]*f[i-1][j];
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(d[x]>d[y])swap(x,y);
		int lca=LCA(x,y);
		/*if(d[x]-d[lca]+d[y]-d[lca]<=K){
			cout<<a[x]+a[y]<<'\n';
			continue;
		}
		if(lca==x){
			Mat tmp=Getmat(y,x);
			cout<<a[y]+tmp.a[0][0]<<'\n';
			continue;
		}
		if(d[x]==d[lca]+1){
			Mat t1=Getmat(y,lca);
			cout<<a[x]+min(a[y]+t1.a[0][0],a[y]+t1.a[1][0]);
		}*/
		Mat t1=Getmat(x,lca),t2=Getmat(y,lca);
		ll ans=V;
		ans=min(ans,a[x]+a[y]+t1.a[0][0]+t2.a[0][0]-a[lca]);
		ans=min(ans,a[x]+a[y]+t1.a[1][0]+t2.a[1][0]);
		cout<<ans<<'\n';
	}
}

}
namespace Solve3{

ll s[200005];
int PX,PY;
void dfs(int x,int fa){
	p[0][x]=fa,d[x]=d[fa]+1,s[x]=s[fa]+a[x];
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
}
int LCA(int x,int y){
	//bool rev=0;
	if(d[x]<d[y])swap(x,y);//,rev=1;
	for(int i=17;i>=0;i--)if(d[x]-(1<<i)>=d[y])x=p[i][x];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(p[i][x]^p[i][y])x=p[i][x],y=p[i][y];
	//PX=x,PY=y;
	//if(rev)swap(PX,PY);
	return p[0][x];
}
Mat Getmat(int fr,int to){
	Mat ret;
	ret.E();
	for(int i=17;i>=0;i--){
		if(d[fr]-(1<<i)>=d[to]){
			ret=f[i][fr]*ret;
			fr=p[i][fr];
		}
	}
	return ret;
}
void main(){
	M=5; 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		for(int j:g[i])b[i]=min(b[i],a[j]);
		v[i].O();
		v[i].a[0][0]=v[i].a[0][1]=v[i].a[0][2]=v[i].a[0][3]=v[i].a[0][4]=a[i];
		v[i].a[1][0]=v[i].a[1][1]=v[i].a[1][2]=b[i];
		v[i].a[2][0]=0;
		v[i].a[3][1]=0;
		v[i].a[4][2]=0;
	}
	for(int i=1;i<=n;i++){
		if(p[0][i]){
			f[0][i]=v[p[0][i]];
		}
	}
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=p[i-1][p[i-1][j]];
			if(p[i][j]){
				f[i][j]=f[i-1][p[i-1][j]]*f[i-1][j];
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(d[x]>d[y])swap(x,y);
		int lca=LCA(x,y);
		/*if(d[x]-d[lca]+d[y]-d[lca]<=K){
			cout<<a[x]+a[y]<<'\n';
			continue;
		}
		if(lca==x){
			Mat tmp=Getmat(y,x);
			cout<<a[y]+tmp.a[0][0]<<'\n';
			continue;
		}
		if(d[x]==d[lca]+1){
			Mat t1=Getmat(y,lca);
			cout<<a[x]+min(a[y]+t1.a[0][0],a[y]+t1.a[1][0]);
		}*/
		Mat t1=Getmat(x,lca),t2=Getmat(y,lca);
		ll ans=V;
		ans=min(ans,a[x]+a[y]+t1.a[0][0]+t2.a[0][0]-a[lca]);//都到(lca,0)
		ans=min(ans,a[x]+a[y]+t1.a[1][0]+t2.a[1][0]-b[lca]);//都到(lca,1)
		ans=min(ans,a[x]+a[y]+min({t1.a[2][0],t1.a[3][0],t1.a[4][0]})+t2.a[2][0]);//到y下一个,x 234
		ans=min(ans,a[x]+a[y]+min({t2.a[2][0],t2.a[3][0],t2.a[4][0]})+t1.a[2][0]);//到x下一个,y 234
		cout<<ans<<'\n';
	}
}

}
char BBB;
int main(){
	//cerr<<(&AAA-&BBB)/1024.0/1024.0<<'\n';
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&K);
	if(K==1)Solve1::main();
	if(K==2)Solve2::main();
	if(K==3)Solve3::main();
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll V=1e18;
mt19937_64 rng;
int rnd(int l,int r){
	return l+rng()%(r-l+1);
}
int main(){
	freopen("seed.txt","r",stdin);
	unsigned long long seed;
	scanf("%llu",&seed);
	rng=mt19937_64(seed+time(0));
	freopen("seed.txt","w",stdout);
	printf("%llu\n",rng());
	freopen("transmit.in","w",stdout);
	int n=rnd(200000,200000);
	int q=rnd(200000,200000);
	int K=rnd(3,3);
	cout<<n<<' '<<q<<' '<<K<<'\n';
	for(int i=1;i<=n;i++)cout<<rnd(1,1e9)<<' ';
	puts("");
	for(int i=2;i<=70000;i++){
		cout<<i<<' '<<i-1<<'\n';
	}
	cout<<70001<<' '<<1<<'\n';
	for(int i=70002;i<=140000;i++)cout<<i<<' '<<i-1<<'\n';
	for(int i=140001;i<=n;i++)cout<<i<<' '<<rnd(1,i-1)<<'\n';
	for(int i=1;i<=q;i++){
		if(rnd(0,50)==0)cout<<rnd(1,n)<<' '<<rnd(1,n)<<'\n';
		else cout<<65536<<' '<<70000+65535<<'\n';
	}
}
*/
