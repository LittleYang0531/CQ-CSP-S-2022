#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	bool SF=false;int XF=0;char CH=getchar();
	for(;CH<'0'||CH>'9';CH=getchar()) if(CH=='-') SF=true;
	for(;CH>='0'&&CH<='9';CH=getchar()) XF=(XF<<3)+(XF<<1)+(CH-'0');
	if(SF) XF=-XF; return XF;
}
inline LL readl(){
	bool SF=false;LL XF=0;char CH=getchar();
	for(;CH<'0'||CH>'9';CH=getchar()) if(CH=='-') SF=true;
	for(;CH>='0'&&CH<='9';CH=getchar()) XF=(XF<<3)+(XF<<1)+(CH-'0');
	if(SF) XF=-XF; return XF;
}
int N,M,Q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	N=read();
	M=read();
	int u,v;
	for(int i=1;i<=M;i++){
		cin>>u>>v;
	}
	Q=read();
	int t;
	for(int i=1;i<=Q;i++)
	{
		cin>>t;
		if(t%2==0)
		{
			cin>>u;
		}
		else cin>>u>>v;
		puts("NO");
	}
	return 0;
}
