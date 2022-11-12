#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


int main()
{
	int input=0,sum1=0;
	srand(time(0));
	do
	{
		if (sum1 > 0)
			menu2();
		else
		menu1();
		printf("请选择->");
		scanf("%d", &input);
		getchar();
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:puts("游戏退出");
			break;
		default:
			puts("选择错误，请重新选择");
			break;
		}
		if (input == 1)
			sum1++;
	} while (input!=2);
	return 0;
}