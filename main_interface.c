#import <stdio.h>
int main_interface(){
	int selection_parameter;               /* 针对选择返回相应的整数值 */
	printf("******************************************************\n");
	printf("*************     水果超市信息管理系统     **************\n");
	printf("******************************************************\n");
	printf("***** 1.增加  2.继续添加   3.修改   4.删除   5.查询  *****\n");
	printf("***** 6.统计       7.查询会员信息     8.大额购物信息  *****\n");
	printf("***** 9.时间段内购物信息  10.存储  11.打印当前信息    ******\n");
	printf("***** 12.录入会员信息        13.退出程序           ******\n");
	printf("                请输入所需操作的序号:   ");
	scanf("%d",&selection_parameter);
	return selection_parameter;
}




//
// Created by 钱辂 on 2017/12/19.
//

