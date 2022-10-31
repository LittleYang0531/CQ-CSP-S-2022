#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define ll long long
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
using namespace std;
//
bool H1;
const ll N=5e5;
vector<ll> side[N+10],aside[N+10];
ll out[N+10];
set<ll> aba[N+10];
bool h1;
//
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll gt(){
	ll x=0,b=0; char c=getchar();
	while(!isdigit(c)) b|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return b?-x:x;
}
inline void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int main(){
//	cout<<(&h1-&H1)/1024/1024<<endl;
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ll n=gt(),m=gt(),cnt=0;
	FOR(i,1,m){
		ll x=gt(),y=gt();
		aba[y].insert(x);
		side[x].pb(y);
		aside[y].pb(x);
		++out[x];
	}
	FOR(i,1,n) cnt+=(out[i]==1);
	ll q=gt();
	FOR(i,1,q){
		ll op=gt();
		if(op==1){
			ll x=gt(),y=gt();
			aba[y].erase(x);
			if(out[x]==1) --cnt;
			--out[x]; 
			if(out[x]==1) ++cnt;
		}
		else if(op==2){
			ll x=gt();
			auto id=aba[x].begin();
			while(id!=aba[x].end()){
				ll y=*id;
				if(out[y]==1) --cnt;
				--out[y]; 
				if(out[y]==1) ++cnt;
				++id;
			}
			aba[x].clear();
		}
		else if(op==3){
			ll x=gt(),y=gt();
			aba[y].insert(x);
			if(out[x]==1) --cnt;
			++out[x];
			if(out[x]==1) ++cnt;
		}
		else if(op==4){
			ll x=gt();
			for(auto y:aside[x]){
				if(aba[x].find(y)==aba[x].end()){
					aba[x].insert(y);
					if(out[y]==1) --cnt;
					++out[y];
					if(out[y]==1) ++cnt;
				}
			}
		}
		if(cnt==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


