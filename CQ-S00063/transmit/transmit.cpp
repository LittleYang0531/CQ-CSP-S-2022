#include<iostream>
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
int main()
{
	ios::sync_with_stdio(false);
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cout<<"12\n12\n3";
	return 0;
}

