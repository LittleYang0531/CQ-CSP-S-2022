#include<cstdio>
template<typename _T>
void read(_T& x){
	static bool f;
	static char ch;
	x=0,f=0,ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=f?-x:x;
}
inline long long int max(const long long int& a,const long long int& b){
	return a>b?a:b;
}
inline long long int min(const long long int& a,const long long int& b){
	return a<b?a:b;
}
int n,m,q;
long long int a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1,x;i<=n;i++)
		read(a[i])/*,a[i]=a[i-1]+x*/;
	for(int i=1,x;i<=m;i++)
		read(b[i])/*,b[i]=b[i-1]+x*/;
	int l1,r1,l2,r2;
	while(q--){
		read(l1),read(r1),read(l2),read(r2);
		long long int maa=0,maaf=0,mab=0,mabf=0;
		long long int mia=0x3f3f3f3f3f3f3f3f,miaf=-0x3f3f3f3f3f3f3f3f,mib=0x3f3f3f3f3f3f3f3f,mibf=-0x3f3f3f3f3f3f3f3f;
		bool za=0,zb=0;
		for(int i=l1;i<=r1;i++){
			if(a[i]>0&&maa<a[i]) maa=a[i];
			if(a[i]>0&&mia>a[i]) mia=a[i];
			if(a[i]<0&&maaf>a[i]) maaf=a[i];
			if(a[i]<0&&miaf<a[i]) miaf=a[i];
			if(a[i]==0) za=1;
		}
		for(int i=l2;i<=r2;i++){
			if(b[i]>0&&mab<b[i]) mab=b[i];
			if(b[i]>0&&mib>b[i]) mib=b[i];
			if(b[i]<0&&mabf>b[i]) mabf=b[i];
			if(b[i]<0&&mibf<b[i]) mibf=b[i];
			if(b[i]==0) zb=1;
		}
//		printf("%lld %lld %lld %lld %lld\n%lld %lld %lld %lld %lld\n",maa,mia,maaf,miaf,za,mab,mib,mabf,mibf,zb);
//		if(maa&&mibf) ans=max(ans,maa*mibf);
		long long int ans=-0x3f3f3f3f3f3f3f3f;
		if(maa&&mib!=0x3f3f3f3f3f3f3f3f&&mabf==0) ans=max(ans,maa*mib);
		if(mib==0x3f3f3f3f3f3f3f3f&&mibf!=-0x3f3f3f3f3f3f3f3f&&maaf) ans=max(ans,mibf*maaf);
		if(maa&&mib!=0x3f3f3f3f3f3f3f3f&&mabf==0) ans=max(ans,maa*mib);
		if(mab&&miaf!=-0x3f3f3f3f3f3f3f3f) ans=max(ans,mab*miaf);
//		if(mib!=0x3f3f3f3f&&maaf!=-0x3f3f3f3f) ans=max(ans,mib*maaf);
		if(mia!=0x3f3f3f3f3f3f3f3f&&mabf!=0) ans=max(ans,mia*mabf);
		if(za) ans=max(ans,0);
		if(zb) ans=min(ans,0);
		printf("%lld\n",ans);
	}
	return 0;
} 


