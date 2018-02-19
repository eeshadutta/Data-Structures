/*This programme has the following linkedlist functions-read,print,insert,delete,search,swap,sort,reverse*/

#include <stdio.h>
#include <stdlib.h>
typedef struct list {
	int val;
	struct list * link;
}LIST;

LIST *head;

void read(int n)
{
	if (n==0)
		return;

	LIST *temp;
	temp=(LIST*)malloc(sizeof(LIST));
	scanf ("%d",&temp->val);

	if (head==NULL)
	{
		head=temp;
		head->link=NULL;
	}
	else
	{
		LIST *temp2=head;
		while (temp2->link!=NULL)
		{
			temp2=temp2->link;
		}
		temp2->link=temp;
	}
	read(n-1);
	return;
}

void print ()
{
	LIST *temp=head;
	while (temp!=NULL)
	{
		printf ("%d ", temp->val);
		temp=temp->link;
	}
	return;
}

LIST *search(int k)
{
	LIST *temp=head;
	if (head->val == k)
		return NULL;
	while(temp->link!=NULL)
	{
		if (temp->link->val==k)
			break;
		temp=temp->link;
	}
	return temp;
}

int insert (LIST *pre,int k,int n)
{
	LIST *temp;
	temp=(LIST *)malloc(sizeof(LIST));
	temp->val=k;
	if (pre==NULL)
	{
		temp->link=head;
		head=temp;
	}
	else
	{
		temp->link=pre->link;
		pre->link=temp;
	}
	n++;
	return n;
}

int delete (LIST *pre, int n)
{
	LIST * curr;
	if (pre==NULL)
	{
		curr=head;
		head=curr->link;
	}
	else 
	{
		curr=pre->link;
		pre->link=curr->link;
	}
	n--;
	free(curr);
	return n;
}

void swap (LIST* pk, LIST* pl)
{
	LIST *k,*l,*nk,*nl;
	if (pk==NULL)
		k=head;
	else
		k=pk->link;
	if (pl==NULL)
		l=head;
	else
		l=pl->link;
	nk=k->link;
	nl=l->link;
	if (k==l)
		return;

	if (pk==NULL)
		head=l;
	else
		pk->link=l;

	if (nk==l)
		l->link=k;	
	else
	{
		l->link=nk;
		pl->link=k;
	}
	k->link=nl;
	return;
}

void sort()
{
	LIST *temp,*pk,*pl;
	int flag=1;
	while(flag==1)
	{
		flag=0;
		temp=head;
		while(temp!=NULL && temp->link!=NULL)
		{
			if (temp->val > temp->link->val)
			{
				flag=1;
				pk=search(temp->val);
				pl=search(temp->link->val);
				swap(pk,pl);
			}
			else
				temp=temp->link;
		}
	}
	return;
}

void reverse(LIST* pre, LIST* curr)
{
	if (curr->link==NULL)
	{
		head=curr;
		head->link=pre;
		return;
	}
	reverse(curr,curr->link);
	curr->link=pre;
	return;
}

int main ()
{
	int n;
	scanf ("%d", &n);
	read(n);
	print();
	printf ("\n");

	int k,l;
	LIST* pre;
	LIST* curr;

	printf ("Node after which to be inserted and value of the new node:");
	scanf ("%d %d", &k, &l);
	pre=search(k);
	pre=pre->link;
	n=insert(pre,l,n);
	print();
	printf ("\n");

	printf ("Node to be deleted:");
	scanf ("%d", &k);
	pre=search(k);
	n=delete(pre,n);
	print();
	printf ("\n");

	printf ("Nodes to be swapped:");
	scanf ("%d %d", &k, &l);
	LIST* pk;
	LIST* pl;
	pk=search(k);
	pl=search(l);
	swap(pk,pl);
	print();
	printf ("\n");
	
	printf ("Sorted Linkedlist:");
	sort();
	print();
	printf("\n");
	
	printf ("Reversed Linkedlist:");
	reverse(NULL,head);
	print();
	printf("\n");

	return 0;
}
