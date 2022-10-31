#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int re=0,base=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') base=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		re=re*10+ch-'0';
		ch=getchar();
	}
	return re*base;
}
void write(int num){
	if(num>9) write(num/10);
	putchar(num%10+'0');
}
int main(){
//	freopen("transmit.in","r",stdin);
//	freopen("transmit.out","w",stdout);
//	fclose(stdin);
//	fclose(stdout);	
	return 0;
}
