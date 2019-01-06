#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "info.h"

void addition_continue(struct addition *head) {
	struct addition *p1;
	p1 = head;
	struct addition *p2;
	while (p1->next != NULL) {
		p1 = (struct addition *) p1->next;
	}
	do {
		p2 = (struct addition *) malloc(sizeof(struct addition));
		time_t tmpcal_ptr;
		struct tm *tmp_ptr = NULL;
		time(&tmpcal_ptr);
		tmp_ptr = localtime(&tmpcal_ptr);
		printf("输入程序启动，请自行按照提示进行输入(购物时间默认为当前时间)\n");
		printf("请输入序号：  ");
		scanf("%d",&(p1->num));
		while (isalpha(p1->num) || (p1->num)<1000 || (p1->num) > 9999){
			if (p1->num == 0){
				break;
			}
			else {
				printf("输入内容不合法，请重新输入!\n");
				scanf("%d", &(p1->num));
			}
		}
		p2->year = (1900 + tmp_ptr->tm_year);
		p2->month = (1 + tmp_ptr->tm_mon);
		p2->day = (tmp_ptr->tm_mday);
		p2->hour = (tmp_ptr->tm_hour);
		p2->minute = (tmp_ptr->tm_min);
		p2->second = (tmp_ptr->tm_sec);
		printf("购买时间:%d.%d.%d %d:%d:%d\n", 1900 + tmp_ptr->tm_year, 1 + tmp_ptr->tm_mon, tmp_ptr->tm_mday,
		       tmp_ptr->tm_hour, tmp_ptr->tm_min, tmp_ptr->tm_sec);
		printf("请输入水果种类所对应序号：1.苹果  2.香蕉  3.梨  4.西瓜  5.桃子\n");
		scanf("%d", &(p2->kinds_of_fruit));
		printf("请输入单价(元/kg):   \n");
		scanf("%f", &(p2->unit_price));
		printf("请输入卖出的公斤数(kg):   \n");
		scanf("%f", &(p2->quantity));
		printf("总价(元):   %.2f元\n", (p2->quantity) * (p2->unit_price));
		(p2->total_price) = (p2->quantity) * (p2->unit_price);
		printf("请输入支付信息对应编号:1.现金支付  2.会员卡支付\n");
		scanf("%d", &(p2->k));
		if (p2->k == 1) {
			printf("请输入支付金额:   ");
			scanf("%f", &(p2->m1.payment));
			printf("找零金额:   %.2f元\n", (p2->m1.payment) - (p2->total_price));
			(p2->m1.change) = (p2->m1.payment) - (p2->total_price);
		} else if (p2->k == 2) {
			printf("请输入会员卡号:   ");
			scanf("%d", &(p2->m2.number));
			printf("请输入支付前会员卡余额:   ");
			scanf("%f", &(p2->m2.money_before));
			printf("请输入支付后会员卡余额:   %.2f\n", (p2->m2.money_before) - (p2->total_price));
			(p2->m2.money_after) = (p2->m2.money_before) - (p2->total_price);
		} else {
			printf("输入错误！");
		}
	}while (p2->next != 0);
	p2->next = NULL;
	p1->next = p2;
}





//
// Created by 钱辂 on 2017/12/20.
//

