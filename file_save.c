#include <stdio.h>
#include "info.h"
void outlink(struct addition *head){
	struct addition *p = head;
	FILE *w;
	w = fopen("购物信息.txt", "w");
	if (w == NULL) {
		printf ("文件打开失败");
	}
	while (p) {
		fprintf(w,"序号:%d\n",p->num);
		fprintf(w,"购买时间:%d.%d.%d %d:%d:%d\n",p->year,p->month,p->day,p->hour,p->minute,p->second);
		if (p->kinds_of_fruit == 1) {
			fprintf(w, "水果种类:苹果\n");
		}
		else if (p->kinds_of_fruit == 2){
			fprintf(w, "水果种类:香蕉\n");
		}
		else if (p->kinds_of_fruit == 3){
			fprintf(w, "水果种类:梨\n");
		}
		else if (p->kinds_of_fruit == 4){
			fprintf(w, "水果种类:西瓜\n");
		}
		else if (p->kinds_of_fruit == 5){
			fprintf(w, "水果种类:桃子\n");
		}
		fprintf(w,"单价:%.2f 元/kg \n",p->unit_price);
		fprintf(w,"卖出的公斤数:%.2f 元/kg \n",p->quantity);
		fprintf(w,"总价:%.2f\n 元",(p->quantity)*(p->unit_price));
		if (p->k == 1) {
			fprintf(w,"支付方式: 现金支付\n");
			fprintf(w,"支付金额: %.2f  元\n",p->m1.payment);
			fprintf(w,"找零金额:   %.2f元\n",(p->m1.payment)-(p->total_price));
		}
		else if(p->k == 2){
			fprintf(w,"支付方式: 会员卡支付\n");
			fprintf(w,"会员卡号:  %d ",p->m2.number);
			fprintf(w,"支付前会员卡余额:  %.2f 元\n",p->m2.money_before);
			fprintf(w,"支付后会员卡余额:   %.2f 元\n",(p->m2.money_before)-(p->total_price));
		}
		fprintf(w,"\n\n");
		printf("录入成功\n");
		p = p->next;
	}
	fclose(w);
}

//
// Created by 钱辂 on 2017/12/19.
//

