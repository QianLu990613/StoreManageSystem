#include <stdio.h>
#include "info.h"
void card_outlink(){
	FILE *w;
	w = fopen("会员卡信息.txt", "w");
	if (w == NULL) {
		printf ("文件打开失败");
	}
	int number_card;
	float money_in_card;
	do{
		printf("请输入会员卡号:    ");
		scanf("%d",&number_card);
		if (number_card == 0){
			break;
		}
		printf("请输入会员卡余额：  ");
		scanf("%f",&money_in_card);
		fprintf(w, "会员卡号:  %d \n", number_card);
		fprintf(w, "会员卡余额:  %.2f 元\n", money_in_card);
		fprintf(w, "\n\n");
		printf("录入成功\n");
	}while (number_card != 0);

	fclose(w);
}



//
// Created by 钱辂 on 2017/12/24.
//

