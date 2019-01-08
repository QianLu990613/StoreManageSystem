#include <stdio.h>
#include "info.h"
void search_print_card(struct addition *head){
	struct addition *b = head;
	int L;
	printf("请输入你所需要查找的会员的的会员卡号:     ");
	scanf("%d",&L);
		if (b->m2.number == L) {
			printf("\n\n");
			printf("支付方式: 会员卡支付\n");
			printf("会员卡号:  %d ",b->m2.number);
			printf("支付前会员卡余额:  %.2f \n",b->m2.money_before);
			printf("支付后会员卡余额:   %.2f\n",(b->m2.money_before)-(b->total_price));
			printf("\n\n");
		} else {
			b = (struct addition *) b->next;
		}
	}
//
// Created by 钱辂 on 2017/12/20.
//

