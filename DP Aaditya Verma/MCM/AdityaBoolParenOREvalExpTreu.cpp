#include<stdio.h>
#include<string.h>
#include<limits.h>
#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

int static t[MAX_SIZE+1][MAX_SIZE+1][2];

int solve(char* str,int i,int j,bool flag)
{
	if(i>j)
	return FALSE;
	
	if(i==j)
	{
		if(flag==TRUE)
		return(str[i]=='T');
		
		else
		return(str[i]=='F');
	}
	
	int v=(flag==TRUE?1:0);
	
	if(t[i][j][v]!=-1)
	return t[i][j][v];
	
	
    
	int k,lt,lf,rt,rf,tempans=0;
	for(k=i+1;k<j;k+=2)
	{
		lt=solve(str,i,k-1,TRUE);
		lf=solve(str,i,k-1,FALSE);
		rt=solve(str,k+1,j,TRUE);
		rf=solve(str,k+1,j,FALSE);
		
		if(str[k]=='&')
		{
			if(flag==TRUE)
			tempans+=lt*rt;
			
			else
			tempans+=lf*rt+lt*rf+lf*rf;
		}
		else if(str[k]=='|')
		{
			if(flag==TRUE)
			tempans+=lt*rf+lf*rt+lt*rt;
			
			else
			tempans+=lf*rf;
			
		}
		else if(str[k]=='^')
		{
			if(flag==TRUE)
			tempans+=lf*rt+lt*rf;
			
			else
			tempans+=lf*rf+lt*rt;
			
		}	
	}
	
	return (t[i][j][v]=tempans);
}

int main()
{
	//char str[] = "T|T&F^T";
    char str[] = "T^F&T";
	int i,j,n=strlen(str);
	memset(t,-1,sizeof(t));
	printf("%d\n",solve(str,0,n-1,TRUE));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",t[i][j][0]);
		
		printf("\n");
	}
	
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",t[i][j][1]);
		
		printf("\n");
	}
	return 0; 
}