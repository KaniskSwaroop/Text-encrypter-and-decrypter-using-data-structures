#include<bits/stdc++.h>
using namespace std;
class LinkedList              //----------Linked List class---------------//
{
	public:
		long data;
		LinkedList * next;
};
int main()
{
	vector<long long> c;
	int i;
	long long x=0;
	cout<<"Enter the data to be decrypted. Press enter after you input each number . Also enter 1 after all the inputs are entered"<<endl;
	while(x!=1)
	{
		long long val;
		cin>>val;
		c.push_back(val);
		x=val;
	}
	int s=c.size();
	int n=s-1;
	
	long long key;
	cout<<"Enter the key you were given by the encrypter"<<endl;
	cin>>key;
	while(key<10000000)
	{
		cout<<"Please enter a valid key provided by the encrypter";
		cin>>key;
	}
	vector<long long> res(n);          //--------------------output vector-------------------//
	if(n%2==0)
	{
		vector<long long> v1(n/2);
		vector<long long> v2(n/2);
		int k=0;
		for(i=0;i<n/2;i++)
		{
			v1[i]=c[i];
		}
		for(i=n/2;i<n;i++)
		{
			v2[k]=c[i];
			k++;
		}
		//vector<long long> res(n);
		res[0]=v1[0];
		int p=1,q=0;
		for(i=1;i<n;i++)
		{
			if(i%2!=0)
			{
				res[i]=v2[q];
				q++;
			}
			else
			{
				res[i]=v1[p];
				p++;
			}
		}
	}
	else if(n%2!=0)
	{
		vector<long long> v1((n/2)+1);
		vector<long long> v2(n/2);
		int k=0;
		for(i=0;i<(n/2)+1;i++)
		{
			v1[i]=c[i];
		}
		for(i=(n/2)+1;i<n;i++)
		{
			v2[k]=c[i];
			k++;
		}
		
		res[0]=v1[0];
		int p=1,q=0;
		for(i=1;i<n;i++)
		{
			if(i%2!=0)
			{
				res[i]=v2[q];
				q++;
			}
			else
			{
				res[i]=v1[p];
				p++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		res[i]=res[i]-key%1000000007;
	}
	
	string str="";
	for(i=0;i<n;i++)
	{
		str=str+(char)res[i];
	}
	cout<<str;
	return 0;
}
