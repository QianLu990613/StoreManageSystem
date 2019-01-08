#include <stdio.h>
#include "info.h"
void search_print(struct addition *head){
	struct addition *b = head;
	int L;
	printf("请输入你所需要查找的客户的序号:     ");
	scanf("%d",&L);
	while (b != NULL) {
		if (b->num == L) {
			printf("序号为:%d\n",b->num);
			printf("购买时间:%d.%d.%d %d:%d:%d\n",b->year,b->month,b->day,b->hour,b->minute,b->second);
			printf("水果：");
			if (b->kinds_of_fruit == 1) {
				printf("苹果\n");
			}
			else if (b->kinds_of_fruit == 2){
				printf("香蕉\n");
			}
			else if (b->kinds_of_fruit == 3){
				printf("梨\n");
			}
			else if (b->kinds_of_fruit == 4){
				printf("西瓜\n");
			}
			else if (b->kinds_of_fruit == 5){
				printf("桃子\n");
			}
			printf("单价(元/kg): %.2f  \n",b->unit_price);
			printf("卖出的公斤数(kg):  %.2f \n",b->quantity);
			printf("总价(元):   %.2f元\n",(b->quantity)*(b->unit_price));
			if (b->k == 1) {
				printf("支付方式: 现金支付\n");
				printf("支付金额: %.2f  \n",b->m1.payment);
				printf("找零金额:   %.2f元\n",(b->m1.payment)-(b->total_price));
			}
			else if(b->k == 2){
				printf("支付方式: 会员卡支付\n");
				printf("会员卡号:  %d ",b->m2.number);
				printf("支付前会员卡余额:  %.2f \n",b->m2.money_before);
				printf("支付后会员卡余额:   %.2f\n",(b->m2.money_before)-(b->total_price));
			}
			printf("\n\n");
		} else {
			b = (struct addition *) b->next;
		}
	}
}//
// Created by 钱辂 on 2017/12/19.
//

