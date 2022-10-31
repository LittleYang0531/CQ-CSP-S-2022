#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
map<int,int>id[maxn]; 	
const int maxs=8e6+5;
inline int read(){
	int x=0,f=1;
	char c=getchar(); 
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10ll+c-48;
		c=getchar(); 
	} 
	return f*x;
}
struct Seg{ 
	int tot;
	void init(){
		tot=1;
		ls[1]=rs[1]=cnt[1]=0;
	}
	int cnt[maxs];
	int ls[maxs],rs[maxs];
	void update(int &i,int l,int r,int u,int v){
		if(!i){
			i=++tot; 
			cnt[i]=0;
			ls[i]=0;
			rs[i]=0;
		}
		if(u<=l&&r<=v){
			cnt[i]++;
			return ;
		}
		int mid=(l+r)/2;
		if(u<=mid)update(ls[i],l,mid,u,v);
		if(mid+1<=v)update(rs[i],mid+1,r,u,v);
	} 
	int query(int i,int l,int r,int x){
		if(!i)return 0;
		if(l==r)return cnt[i];
		int mid=(l+r)/2;
		if(x<=mid)return cnt[i]+query(ls[i],l,mid,x);
		else return cnt[i]+query(rs[i],mid+1,r,x);
	}
}A,B;
struct edge{
	int u,v;	
}e[maxn];
vector<int>ope[maxn],opn[maxn];
#define mp make_pair
#define fr first
#define sc second
vector<int>hv[maxn];
vector<pair<int,int> >lt[maxn];
int q;
int rt;
void dfs(int i,int l,int r,int val){
	if(!i){ 
		if(val==1){ 
			B.update(rt,0,q,l,r);
		}
		return ;
	}
	val+=A.cnt[i];
	if(val>1)return ;  
	int mid=(l+r)/2;
	dfs(A.ls[i],l,mid,val);
	dfs(A.rs[i],mid+1,r,val);
}
inline bool cmp(int a,int b){
	return abs(a)<abs(b);
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	rt=1;
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();
		id[e[i].u][e[i].v]=i;
		hv[e[i].u].push_back(i); 
	}
	B.init();
	q=read();
	int t,u,v;
	for(int i=1;i<=q;i++){ 		
		t=read();
		if(t==1){
			u=read();v=read();
			ope[id[u][v]].push_back(-i);
		}
		if(t==2){
			u=read();
			opn[u].push_back(-i);
		} 
		if(t==3){
			u=read();v=read();
			ope[id[u][v]].push_back(i);
		}
		if(t==4){
			u=read();
			opn[u].push_back(i);
		}  
	}     
	for(int i=1;i<=m;i++){ 
//		cout<<i<<":"; 
		for(auto v:opn[e[i].v])ope[i].push_back(v); 
		sort(ope[i].begin(),ope[i].end(),cmp);
		ope[i].push_back(-q-1);
		bool le=1;
		int tim=0;
		A.init(); 
		for(auto v:ope[i]){
			if(v<0){
				if(le){ 
					if(abs(v)!=tim)
					lt[i].push_back(mp(tim,-v-1));
//					cout<<tim<<" "<<-v-1<<endl;
					le=0;
				}
			}
			else{
				if(!le){ 
					le=1;
					tim=v;
				}
			}
		} 
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<":";
		A.init();
		for(auto v:hv[i]){
			for(auto pp:lt[v]){
				A.update(rt,0,q,pp.fr,pp.sc);
			}
		}
		dfs(1,0,q,0);
	} 
	for(int i=1;i<=q;i++){
		if(B.query(1,0,q,i)==n){
			putchar('Y');
			putchar('E');
			putchar('S');
			putchar('\n');
		}
		else{ 
			putchar('N');
			putchar('O'); 
			putchar('\n');
		}  
	}
	return 0;
}
