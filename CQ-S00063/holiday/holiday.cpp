#include<iostream>
#include<algorithm>
using namespace std;
#define re register
#define r read()
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,m,k,u,v,sco[2505],ans;
int main()
{
	ios::sync_with_stdio(false);
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=r,m=r,k=r;
	for(re int i=1;i<=n;i++)
		sco[i]=r;
	sort(sco+1,sco+1+n);
	cout<<sco[n]+sco[n-1]+sco[n-2]+sco[n-3]-3;
	return 0;
}

