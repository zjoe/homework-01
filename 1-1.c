#include <stdio.h>
#define MAXN 100000000
FILE *fin,*fout;
int main(void)
{
	fin=fopen("input.txt","r");
	fout=fopen("output.txt","w");
	int n,i,sum,m,ans,a,f;
	
	fscanf(fin,"%d\n",&n);

	sum=0;
	m=0;
	ans=-MAXN;
	
	for(i=1;i<=n;i++)
	{
		fscanf(fin,",%d",&a);
		sum+=a;
		f=sum-m;
		if(f>ans)ans=f;
		if(sum<m)m=sum;
	}
	
	fprintf(fout,"%d\n",ans);
	return 0;
}