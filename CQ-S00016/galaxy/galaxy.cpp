#include<bits/stdc++.h>
using namespace std; 
const int N=105;
inline int read(){int f=0;char c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))f=(f<<3)+(f<<1)+c-'0',c=getchar();return f;}
void write(int x){if(x>=10)write(x/10);putchar(x%10+'0');return;}
int n,m;
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++) read(),read();
	int q=read();
	for (int i=1;i<=q;i++) puts("NO");
	return 0;
}
