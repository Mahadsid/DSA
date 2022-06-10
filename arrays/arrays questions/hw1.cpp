
#include<iostream>
using namespace std;

void input(int arr[],int s)
{
	for(int i=0; i<s;i++)
		{
			cin>>arr[i];
		}
}

void check(int arr[],int s)
{
	int z=0, x=0, count=1;
	int b[100];
	for(int i=0; i<s;i++)
	{
		for(int a=0;a<=z;a++)
		{
			if(i==b[a])
			i++;
		}
		for(int j=i+1; j<s;j++)
		{
			if(arr[i]==arr[j])
			{
				b[z]=i;
				z++;
				count++;
			}
		}
		x=x^count;
	}

	if(x==0)
	cout<<"False\n";
	else
	cout<<"True\n";
}


int main()
{
	int n,size,a[100];
	cout<<"no. of times : ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter size of array : ";
		cin>>size;
		input(a,size);
		check(a,size);
	}
}