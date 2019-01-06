#include <stdio.h>
#include "info.h"
void big_payment(struct addition *head){
	struct addition *p1;
	p1 = head;
	float max;
	float min;
	printf("请输入最低价格:   ");
	scanf("%f",&min);
	printf("请输入最高价格:   ");
	scanf("%f",&max);
	while (head != NULL) {
		if (p1->total_price >= min && p1->total_price <= max) {
			printf("序号为:%d\n",p1->num);
			printf("购买时间:%d.%d.%d %d:%d:%d\n",p1->year,p1->month,p1->day,p1->hour,p1->minute,p1->second);
			printf("水果：");
			if (p1->kinds_of_fruit == 1) {
				printf("苹果\n");
			}
			else if (p1->kinds_of_fruit == 2){
				printf("香蕉\n");
			}
			else if (p1->kinds_of_fruit == 3){
				printf("梨\n");
			}
			else if (p1->kinds_of_fruit == 4){
				printf("西瓜\n");
			}
			else if (p1->kinds_of_fruit == 5){
				printf("桃子\n");
			}
			printf("单价(元/kg): %.2f  \n",p1->unit_price);
			printf("卖出的公斤数(kg):  %.2f \n",p1->quantity);
			printf("总价(元):   %.2f元\n",(p1->quantity)*(p1->unit_price));
			if (p1->k == 1) {
				printf("支付方式: 现金支付\n");
				printf("支付金额: %.2f  \n",p1->m1.payment);
				printf("找零金额:   %.2f元\n",(p1->m1.payment)-(p1->total_price));
			}
			else if(p1->k == 2){
				printf("支付方式: 会员卡支付\n");
				printf("会员卡号:  %d ",p1->m2.number);
				printf("支付前会员卡余额:  %.2f \n",p1->m2.money_before);
				printf("支付后会员卡余额:   %.2f\n",(p1->m2.money_before)-(p1->total_price));
			}
			printf("\n\n");
		}
		else
			continue;
	}
}//
// Created by 钱辂 on 2017/12/20.
//

