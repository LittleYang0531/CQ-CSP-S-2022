#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=500000;
int n,m,q,X[N+5],Y[N+5],sta[N+5],tag[N+5],isbad[N+5];
vector<int> g[N+5],inbad[N+5];
mt19937_64 rng(19260817);
ull all=0,cur=0,a[N+5],in[N+5],firin[N+5];
map<int,int> id[N+5];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=rng();
	//for(int i=1;i<=n;i++)a[i]=(1<<i-1);
	for(int i=1;i<=n;i++)all+=a[i],tag[i]=1;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y),sta[i]=1,X[i]=x,Y[i]=y;
		g[y].push_back(i),in[y]+=a[x],id[x][y]=i;
	}
	for(int i=1;i<=n;i++)cur+=in[i],firin[i]=in[i];
	scanf("%d",&q);
	for(int i=1,op,x,y;i<=q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			int t=id[x][y];
			if(!isbad[t]){
				if(0==tag[y]){//不变 
					goto uu;
				}
				//tag[y]=1
				isbad[t]=1;
				sta[t]=0;
				inbad[y].push_back(t);
				in[y]-=a[x];
				cur-=a[x];
			}
			else {
				if(0==sta[t])goto uu;//不变
				sta[t]=0;
				in[y]-=a[x];
				cur-=a[x];
			}
		}
		if(op==2){
			scanf("%d",&x);
			cur-=in[x];
			in[x]=0;
			tag[x]=0;
			for(int id:inbad[x])isbad[id]=0;
			inbad[x].clear();
		}
		if(op==3){
			scanf("%d%d",&x,&y);
			int t=id[x][y];
			if(!isbad[t]){
				if(1==tag[y])goto uu;
				isbad[t]=1;
				sta[t]=1;
				inbad[y].push_back(t);
				in[y]+=a[x];
				cur+=a[x];
			}
			else {
				if(1==sta[t])goto uu;
				sta[t]=1;
				in[y]+=a[x];
				cur+=a[x];
			}
		}
		if(op==4){
			scanf("%d",&x);
			cur-=in[x];
			in[x]=firin[x];
			cur+=in[x];
			tag[x]=1;
			for(int id:inbad[x])isbad[id]=0;
			inbad[x].clear();
		}
		uu:
		cout<<(all==cur?"YES":"NO")<<'\n';
		//cout<<all<<' '<<cur<<'\n';
	}
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
int wrnd(int l,int r){
	if(r-l<=1)return rnd(l,r);
	if(rng()%3)return l;
	return wrnd(l+1,r);
}
vector<int> g[105];
int X[105],Y[105],m;
int main(){
	freopen("seed.txt","r",stdin);
	unsigned long long seed;
	scanf("%llu",&seed);
	rng=mt19937_64(seed+time(0));
	freopen("seed.txt","w",stdout);
	printf("%llu\n",rng());
	freopen("galaxy.in","w",stdout);
	int n=rnd(2,8),m=0,q=500000;
	for(int i=1;i<=n;i++){
		set<int> u;
		u.insert(i);
		int x=wrnd(1,n-1);
		for(int j=1;j<=x;j++){
			int p=rnd(1,n);
			while(u.count(p))p=rnd(1,n);
			u.insert(p),g[i].push_back(p);
			X[++m]=i,Y[m]=p;
		}
	}
	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;i++)for(int j:g[i])cout<<i<<' '<<j<<'\n';
	cout<<q<<'\n';
	for(int i=1;i<=q;i++){
		int op=rnd(1,4);
		if(op==1||op==3){
			int id=rnd(1,m);
			cout<<op<<' '<<X[id]<<' '<<Y[id]<<'\n';
		}
		else {
			int id=rnd(1,n);
			cout<<op<<' '<<id<<'\n';
		}
	}
}
*/
