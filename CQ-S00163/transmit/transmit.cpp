#include <cstdio>
#include <vector>
#include <deque>
char ch;
template<typename T>
inline void r(T&x){
	while((ch=getchar())<48||ch>57);
	x=ch^48;
	while((ch=getchar())<58&&ch>47)x=(x<<1)+(x<<3)+(ch^48);
}
template<typename... Ar>
inline void r(Ar&...ar){
	int a[]{(r(ar),0)...};
}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline void w(const char&x){
	putchar(x);
}
template<typename... Ar>
inline void w(const Ar&...ar){
	int a[]{(w(ar),0)...};
}
int n,q,k,v[200010],i,x,y,de[200010],fa[200010],q1[200010],q2[200010],f1,l1,f2,l2,lc;
long long ans,dp1[200010],dp2[200010];
std::vector<int>a[200010];
void dfs(const int&x,const int&fa){
	de[x]=de[fa]+1;
	::fa[x]=fa;
	for(int y:a[x])if(y!=fa)dfs(y,x);
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	r(n,q,k);
	for(i=1;i<=n;i++)r(v[i]);
	for(i=1;i<n;i++){
		r(x,y);
		a[x].emplace_back(y);
		a[y].emplace_back(x);
	}
	dfs(1,0);
	while(q--){
		r(x,y);
		f1=f2=0;l1=l2=-1;
		dp1[0]=dp2[0]=q2[f2]=0;
		if(de[x]<de[y])x^=y^=x^=y;
		dp1[x]=v[x];
		q1[++l1]=x;
		x=fa[x];
		while(de[x]>de[y]){
			if(de[q1[f1]]>de[x]+k)f1++;
			dp1[x]=dp1[q1[f1]]+v[x];
			while(l1>=f1&&dp1[q1[l1]]>=dp1[x])l1--;
			q1[++l1]=x;
			x=fa[x];
		}
		if(de[q1[f1]]>de[x]+k)f1++;
		dp1[x]=dp1[q1[f1]]+v[x];
		while(l1>=f1&&dp1[q1[l1]]>=dp1[x])l1--;
		dp2[y]=v[y];
		while(x!=y){
			if(de[q1[f1]]>de[x]+k)f1++;
			dp1[x]=dp1[q1[f1]]+v[x];
			while(l1>=f1&&dp1[q1[l1]]>=dp1[x])l1--;
			q1[++l1]=x;
			x=fa[x];
			if(l2>=f2&&de[q2[f2]]>de[y]+k)f2++;
			dp2[y]=dp2[q2[f2]]+v[y];
			while(l2>=f2&&dp2[q2[l2]]>=dp2[y])l2--;
			q2[++l2]=y;
			y=fa[y];
		}
		ans=dp1[x]+dp2[x]-v[x];
		lc=x;
		for(i=f1;i<=l1;i++){
			x=q1[i];
			for(int j=f2;j<=l2;j++){
				y=q2[j];
				if(x!=y&&de[x]+de[y]-de[lc]-de[lc]-1<=k&&ans<dp1[x]+dp2[y]){
					ans=dp1[x]+dp2[y];
				}
			}
		}
		w(ans,'\n');
	}
	return 0;
}
