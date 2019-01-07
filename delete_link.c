#include <stdio.h>
#include <stdlib.h>
#include "info.h"
void deleteByName(struct addition * head)
{
	struct addition *p,*q;
	int number;

	if(head==NULL)
	{
		printf("链表为空。\n");
		return;
	}

	printf("请输入要删除的序号：");
	scanf("%d",&number);
	for(p= (struct addition *) head->next, q=head; p != NULL; p= (struct addition *) p->next, q= (struct addition *) q->next)
	{
		if((p->num) == number)
		{
			q->next=p->next;
		}
	}
	free(p);
}


//
// Created by 钱辂 on 2017/12/19.
//

