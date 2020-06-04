#include<bits/stdc++.h>

using namespace std;

#define ll long long
void KMP_table(char st[],ll n,ll table[])
{
	table[0]=0;
	ll len=0;
	ll i=1;
	while(i<n)
	{
		if(st[len]==st[i])
		{
			len++;
			table[i]=len;
			i++;
		}
		else 
		{
			if(len!=0)
				len=table[len-1];
			else
			{
				table[i]=0;
				i++;
			}
		}
	}
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll a[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&a[i]);
		char st[1000001];
		scanf("%s",st);
		ll len=strlen(st);
		ll table[len];
		memset(table,0,sizeof(table));
		KMP_table(st,len,table);
		bool result=false;
		ll i=1;
		ll j=0;
		while(i<n && j<len)

	{
			if(st[j]=='G')
			{
				if(a[i]>a[i-1])
				{
					i++;
					j++;
				}
				else
				{
					if(j!=0)
						j=table[j-1];
					else
						i++;
				}
			}
			else if(st[j]=='L')
			{
				if(a[i]<a[i-1])
				{
					i++;
					j++;
				}
				else
				{
					if(j!=0)
						j=table[j-1];
					else
						i++;
				}
			}
			else
			{
				if(a[i]==a[i-1])
				{
					i++;
					j++;
				}
				else
				{
					if(j!=0)
						j=table[j-1];
					else
						i++;
				}
			}
			if(j==len)
			{
				result=true;
				break;
			}
		}
		if(result){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}