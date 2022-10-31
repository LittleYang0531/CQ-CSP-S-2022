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
int N,M,K;
LL n[2600];
int f[2600][2600];
pair<int,LL> s1[2600];
pair<int,LL> s2[2600];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	N=read();
	M=read();
	K=read();
	K++;
	for(int i=2;i<=N;i++){
		n[i]=readl();
	}
	int aa,bb;
	for(int i=1;i<=M;i++){
		aa=read();
		bb=read();
		f[aa][bb]=1;
		f[bb][aa]=1;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			for(int k=1;k<=N;k++){
				if(i==k||j==k) continue;
				if(f[j][k]==0||f[i][k]==0) continue;
				if(f[i][j]==0||f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[j][i]=f[i][k]+f[k][j];
				}
			}
		}
	}
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			if(i==j)continue;
			if(f[1][j]>K||f[i][j]>K) continue;
			if(n[j]+n[i]>s1[i].second){
				s2[i].first=s1[i].first;
				s2[i].second=s1[i].second;
				s1[i].first=j;
				s1[i].second=n[j]+n[i];
			}
			else{
				if(n[j]+n[i]>s2[i].second){
					s2[i].first=j;
					s2[i].second=n[i]+n[j];
				}
			}
		}
	}
	LL ans=0;
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			if(f[i][j]>K) continue;
			if(i==j) continue;
			if(s1[i].first!=s1[j].first){
				if(s1[i].first!=j&&s1[j].first!=i)
					ans=max(ans,s1[i].second+s1[j].second);
				else{
					if(s1[i].first==j&&s1[j].first==i){
						if(s2[i].first!=s2[j].first)
							ans=max(ans,s2[i].second+s2[j].second);
					}
					else if(s1[i].first==j){
						if(s2[i].first==s1[j].first){
							if(s2[i].first!=s2[j].first)
								ans=max(ans,s2[i].second+s2[j].second);
						}
						else if(s2[i].first!=s1[j].first) ans=max(ans,s2[i].second+s1[j].second);
					}
					else{
						if(s2[j].first==s1[i].first){
							if(s2[i].first!=s2[j].first)
							ans=max(ans,s2[j].second+s2[i].second);
						}
						else if(s1[i].first!=s2[j].first) ans=max(ans,s2[j].second+s1[i].second);
					}
				}
			}
			else{
				if(s2[i].first!=0||s2[j].first!=0)
						ans=max(ans,max(s2[i].second+s1[j].second,s2[j].second+s1[i].second));
			}
			if(ans==3912){
				puts("");
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
