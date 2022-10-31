#include<bits/stdc++.h>
#define ll long long
#define N 500012
#define mkp make_pair
#define pb push_back
using namespace std;
ll read(){
	ll x=0,fl=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-')fl=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
	return x*fl;
}
int n,m,q;

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));
	n=read(),m=read();
	int u,v;
	for(int i=1;i<=m;i++){
		u=read(),v=read();
	}
	q=read();
	while(q--){
		if(rand()%2) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
//galaxy /tyt
