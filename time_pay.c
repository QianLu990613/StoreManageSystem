#include <stdio.h>
#include <time.h>
#include "info.h"
void time_payment(struct addition *head){
	struct addition *p1 = head;
	int year_need1,month_need1,day_need1,hour_need1,minute_need1;
	int year_need2,month_need2,day_need2,hour_need2,minute_need2;
	printf("请输入你需要查询的时间段------开始时间(最低精度为分):\n");
	printf("年：   ");
	scanf("%d",&year_need1);
	printf("      月：   ");
	scanf("%d",&month_need1);
	printf("      日：   ");
	scanf("%d",&day_need1);
	printf("      时（24小时制）：   ");
	scanf("%d",&hour_need1);
	printf("      分:     ");
	scanf("%d",&minute_need1);
	printf("请输入你需要查询的时间段------结束时间:\n");
	printf("年：   ");
	scanf("%d",&year_need2);
	printf("      月：   ");
	scanf("%d",&month_need2);
	printf("      日：   ");
	scanf("%d",&day_need2);
	printf("      时（24小时制）：   ");
	scanf("%d",&hour_need2);
	printf("      分:     ");
	scanf("%d",&minute_need2);
	do {
		if (year_need1 <= p1->year && p1->year <= year_need2 ||
		    month_need1 <= p1->month && p1->month <= month_need2 ||
		    day_need1 <= p1->day && p1->day <= day_need2 ||
		    hour_need1 <= p1->hour && p1->hour <= hour_need2 ||
		    minute_need1 <= p1->minute && p1->minute <= minute_need2){
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
			p1 = (struct addition *) p1->next;
		} else
			continue;
	}while(p1 != NULL);
}






//
// Created by 钱辂 on 2017/12/20.
//



