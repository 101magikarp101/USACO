#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=1e5+5;
int n,m,a[N],s[N][65],c[N],f[N],b[N],cc,tmp[N];
ll g[N],tt[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<=50;j++)
		s[i][j]=s[i-1][j];
		s[i][a[i]]++;
	}
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		int len=r-l+1,ma=0;ll ss=0;
		for(int j=0;j<=50;j++)
		c[j]=s[r][j]-s[l-1][j],ma=max(ma,c[j]);
		if(c[0])printf("%d %d\n",len-1,c[0]);
		else if(ma>=2){
			for(int j=0;j<=50;j++)
			if(c[j]>=2)ss=(ss+1ll*c[j]*(c[j]-1)/2%mod)%mod;
			printf("%d %lld\n",len-2,ss);
		}
		else{
			cc=0;
			for(int j=0;j<64;j++){
				if(c[j])b[++cc]=j;
				f[j]=1e9;g[j]=0;
			}
			for(int i=1;i<=cc;i++){
				for(int j=0;j<64;j++){
					if(j==b[i])tmp[b[i]]=1,tt[b[i]]=1;
					else if(f[j^b[i]]+1<f[j]){
						tmp[j]=f[j^b[i]]+1;
						tt[j]=g[j^b[i]];
					}
					else if(f[j^b[i]]+1==f[j])
					tt[j]=(g[j]+g[j^b[i]])%mod,tmp[j]=f[j];
					else tt[j]=g[j],tmp[j]=f[j];
				}
				for(int j=0;j<64;j++)
				f[j]=tmp[j],g[j]=tt[j];
			}
			if(!g[0])puts("-1");
			else printf("%d %lld\n",len-f[0],g[0]);
		}
	}
	return 0;
}