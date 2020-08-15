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
	//string str;

	
		//---------------------------------------------TEXT ENCRYPTER------------------------------------------//
	
		cout<<"Enter the text to be encrypted"<<endl;
		string str;
		getline(cin,str);
		long long key;
		cout<<"Enter a  key of length 8 for encrytpion"<<endl;
		cin >> key;
		while(key>99999999)           //-----------------key validation-----------------------//
		{
			cout<<"Please enter a key of length 8 "<<endl;
			cin>>key;
		}
		int n=str.length(),i;
		vector<long> v(n);
		for(i=0;i<n;i++)             //-----------------getting ASCII values-------------------//
		{
			v[i]=str[i];
		}
		for(i=0;i<n;i++)            //------------------encrytpion stage 1---------------------//
		{
			v[i]=v[i]+key%(1000000007);
		}
	
		LinkedList * head=new LinkedList();
		head->data=v[0];
		head->next=NULL;
		LinkedList* head1=head;
	
		for(i=1;i<n;i++)             //-------------linked list creation----------------------//
		{
			LinkedList* node=new LinkedList();
			node->data=v[i];
			node->next=NULL;
			head->next=node;
			head=head->next;
		}
		LinkedList *odd=head1;
		LinkedList *even=head1->next;
		LinkedList *curr=head1;
		LinkedList *prev=head1;
		i=1;
//	LinkedList * checker=head1;                  //----------------checker look if needed-------------//
	
	
/*	while(checker!=NULL)             
	{
		cout<<checker->data<<" ";
		checker=checker->next;
	}
	cout<<endl;*/
	
	
		while(i<n && curr->next!=NULL && prev->next!=NULL)  //-------------------encryption begins------------------//
		{
			if(i%2==0)
			{
				prev->next=curr->next;
				prev=prev->next;
				if(prev->next!=NULL)
					curr->next=prev->next;
			}
			else
			{
				curr=curr->next;
			}
			i++;
		}
		prev->next=NULL;
		curr->next=NULL;

	
		LinkedList * oddhead=odd;
		LinkedList * evenhead=even;
		int count=0;
		while(odd->next!=NULL)
		{
			odd=odd->next;
			count++;
		}
		odd->next=even;
	cout<<count<<endl;
		cout<<"Your encrypted data is: "<<endl;
		//vector<char> c(n);
		//int k=0;
		while(oddhead!=NULL)
		{
			cout<<oddhead->data<<" ";
			
			oddhead=oddhead->next;
		
		}
	
	
	return 0;
}
