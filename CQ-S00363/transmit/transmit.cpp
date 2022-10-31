#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0,f=1;
	char c=getchar();
	while(!isalnum(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isalnum(c)){
		w*=10;
		w+=c-'0';
		c=getchar();
	}
	return w*f;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	return 0;
}

