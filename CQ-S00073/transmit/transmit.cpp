#include <iostream>
using namespace std;
int n,q,k,x,y;
int a[200005];
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",a[x]+a[y]);
	}
	
	return 0;
}
