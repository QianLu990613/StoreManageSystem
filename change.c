#include <stdio.h>
#include "info.h"
void change_link(struct addition *head){
	struct addition *b = head;
	int L;
	printf("请输入你所需要修改信息的客户的序号:     ");
	scanf("%d",&L);
		if (b->num == L) {
			printf("序号为:%d\n",b->num);
			printf("购买时间:%d.%d.%d %d:%d:%d\n",b->year,b->month,b->day,b->hour,b->minute,b->second);
			printf("购买水果修改为：1.苹果  2.香蕉  3.梨  4.西瓜  5.桃子");
			scanf("%d",&b->kinds_of_fruit);
			printf("单价修改为(元/kg):");
			scanf("%f",&b->unit_price);
			printf("卖出的公斤数(kg): ");
			scanf("%f",&b->quantity);
			printf("总价(元):   %.2f元\n",(b->quantity)*(b->unit_price));
			printf("支付方式修改为: 1.现金支付   2.会员卡支付");
			scanf("%d",&b->k);
			if (b->k == 1) {
				printf("支付方式: 现金支付\n");
				printf("支付金额修改为: ");
				scanf("%f",&b->m1.payment);
				printf("找零金额:   %.2f元\n",(b->m1.payment)-(b->total_price));
			}
			else if(b->k == 2){
				printf("支付方式: 会员卡支付\n");
				printf("会员卡号修改为: ");
				scanf("%d",&b->m2.number);
				printf("支付前会员卡余额修改为:  ");
				scanf("%f",&b->m2.money_before);
				printf("支付后会员卡余额:   %.2f\n",(b->m2.money_before)-(b->total_price));
			}
			printf("\n\n");
		} else {
			b = (struct addition *) b->next;
		}
	}



//
// Created by 钱辂 on 2017/12/20.
//

