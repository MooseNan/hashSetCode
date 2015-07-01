#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MaxSize  30    
#define set_len  17    

typedef struct node
{
	char *key;  
	struct node *next;

}HasNode;


void insertHashSet(HasNode *head[], char *str, int len)
{
	int adr = len % set_len;
	HasNode *pnode = NULL;

	pnode = (HasNode*)malloc(sizeof(HasNode));
	memset(pnode, 0, sizeof(HasNode));
	pnode->key = str;

	if(head[adr] == NULL)
	{
		head[adr] = pnode;
	}
	else  
	{
		pnode->next = head[adr];
		head[adr] = pnode;
	}
}

void initHashSet(HasNode *head[], int size, char* data[])
{
    int i;  

    for(i = 0; i < MaxSize; i++)   
		head[i] = NULL;

	for(i = 0; i < size; i++)
		insertHashSet(head, data[i], strlen(data[i]));
}


void printHashSet(HasNode *h[])
{
	int i, temp;
	HasNode *pnode = NULL;

	for(i = 0; i < MaxSize; i++) 
	{
		temp = 1;
		pnode = h[i];
		if(pnode == NULL)
			printf("%d  ", i);
		while(pnode != NULL)
		{
			if(temp != 1)
				printf("   %s",pnode->key);
			else
				printf("%d  %s", i, pnode->key);

			pnode = pnode->next;
			temp++;
		}
		printf("\n");
	}
}

void searchHashSet(HasNode *h[], char *str)
{
	int i, temp, pos = 0;
	HasNode *pnode = NULL;
	char *m[MaxSize];

	for(i = 0; i < MaxSize; i++)
	{
		temp = 0;
		pnode = h[i];
		while(pnode != NULL)
		{	
			m[pos++] = pnode->key;

			if(strcmp(pnode->key, str) == 0)
			{
				temp++;
				break;
			}
			pnode = pnode->next;
		}
		if(temp)
			break;
	}

	if(temp != 0)
	{
		printf("%s  search succeed\n",str);
		for(i = 0;i < pos-1; i++)
		{
			if(i != pos-2)
				printf(" %s", m[i]);
			else
				printf(" %s\n", m[i]);
		}	
	}
	else
		printf("%s search failed\n",str);

	getchar();
	
}

int main(void)
{
	HasNode *head[MaxSize];

	char* data[] = {"zhangsan","kangsi","paoyu", "lisi", "zhangting","linan", "xiaoer", "dongs", "zwc", "meme", "wangyu","tianliang","tainxin","intel"};
	int size = sizeof(data)/sizeof(data[0]);

	initHashSet(head, size, data);

	printHashSet(head);  
	
	searchHashSet(head, "zhangsan");

	return 0;
}