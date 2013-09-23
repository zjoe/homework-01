#include <stdio.h>
#define MAXN 100000000
FILE *fin,*fout;
int sum[100][100];
int main(void)
{
	fin=fopen("input.txt","r");
	fout=fopen("output.txt","w");
	int n,m,i,j,k,a,ans,min,f;

	fscanf(fin,"%d,%d,",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			fscanf(fin,"%d,",&a);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a;
		}
	
	ans=-MAXN;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			min=0;
			for(k=1;k<=m;k++)
			{
				f=sum[j][k]-sum[i-1][k]-min;
				if(f>ans)
					ans=f;
				if(sum[j][k]-sum[i-1][k]<min)
					min=sum[j][k]-sum[i-1][k];
			}
		}

	fprintf(fout,"%d\n",ans);
	return 0;
}