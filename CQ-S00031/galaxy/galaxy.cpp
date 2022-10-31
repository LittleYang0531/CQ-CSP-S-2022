#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double 
	#define unsigned U
	#define ULL U LL
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	int inf=0x3f3f3f3f;
	int INF=0x7fffffff;
	LL infll=0x3f3f3f3f3f3f3f3fll;
	LL INFll=0x7fffffffffffffffll;
	template<typename T>void read(T &x){
		x=0;
		int f=0;
		char c=getchar();
		while(c<'0'||'9'<c){
			if(c=='-')f=1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			x=x*10+(c^48);
			c=getchar();
		}
		x=f?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 1050
#define M 10050

int n,m;

struct node{
	int u,v,nxt;
}e[M<<1];

int head[N];

int tit;

typedef pair<int,int> P;

map<P,int>mp;

vector<int>eg[N];

void add(int u,int v){
	e[++tit]=node{u,v,head[u]};
	head[u]=tit;
	mp[P(u,v)]=tit;
	eg[v].emplace_back(tit);
}

int des[M<<1];

int du[N];

//int duu[N];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\galaxy\\galaxy2.in","r",stdin);
//	freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\galaxy\\galaxy2.txt","w",stdout);
//	srand((unsigned)time(0));
//	clock_t st,ed;
	read(n,m);
	int u,v;
	f(1,m,i){
		read(u,v);
		add(u,v);
	}
//	st=clock();
	int opt,q;
	read(q);
	f(1,q,i){
		read(opt);
		if(opt==1){
			read(u,v);
			des[mp[P(u,v)]]=1;
		}
		else if(opt==2){
			read(u);
			for(auto i:eg[u])des[i]=1;
		}
		else if(opt==3){
			read(u,v);
			des[mp[P(u,v)]]=0;
		}
		else if(opt==4){
			read(u);
			for(auto i:eg[u])des[i]=0;
		}
		memset(du,0,sizeof du);
		int fl=2;
		f(1,m,i){
			if(des[i])continue;
			du[e[i].u]++;
		}
		f(1,n,i){
			if(du[i]!=1){
				fl=0;
				break;
			}
		}
		if(!fl){
			puts("NO");
			continue;	
		}
		puts("YES");
		
	}
//	ed=clock();
//	db DTIME=(ed-st)/1000.0;
//	printf("%.4lf",DTIME);
	return 0;
}
