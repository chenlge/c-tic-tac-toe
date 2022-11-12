#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu1()
{
	puts("******************************");
	puts("*********1.开始游戏**********");
	puts("*********2.退出游戏**********");
	puts("******************************");
}
void menu2()
{
	puts("******************************");
	puts("*********1.继续游戏**********");
	puts("*********2.退出游戏**********");
	puts("******************************");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	int j = 0, k = 0;
	for (j = 0; j < row; j++)
	{
		for (k = 0; k < col; k++)
		{
			board[j][k] = ' ';
		}
	}
}
void Display(char board[ROW][COL], int row, int col)
{
	int i = 0, k = 0;
	for (i = 0; i < row; i++)
	{
		for (k = 0; k < col; k++)
		{
			printf(" %c ", board[i][k]);
			if (k != col - 1)
				printf("|");
		}
		printf("\n");
		if (i != row - 1)
		{
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k != col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

int first()
{
	int input;
	puts("请输入先手角色1.玩家，2.电脑");
	scanf("%d", &input);
	getchar();
	return input;
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	puts("玩家走->");
	while (1)
	{
		printf("请输入下棋的坐标：");
		scanf("%d %d", &i, &j);
		getchar();
		//判断下棋坐标合法性
		if (i <= row && i >= 1 && j <= col && j >= 1)
		{
			//判断坐标是否被占用
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				puts("坐标被占用，请重新输入");
			}
		}
		else
		{
			puts("输入坐标错误，请重新输入。");
		}
	}
}

void CompuerMove(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	puts("电脑走->");
	while (1)
	{
		i = (int)rand() % row;
		j = (int)(rand() * col / (RAND_MAX + 1));
		//判断占用
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0, sum2 = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		sum2 = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
			{
				sum2++;
			}
			if (sum2 == col - 1)
			{
				return board[i][j];
			}
		}
	}
	//判断列
	for (j = 0; j < col; j++)
	{
		sum2 = 0;
		for (i = 0; i < row - 1; i++)
		{
			if (board[i][j] == board[i + 1][j] && board[i][j] != ' ')
			{
				sum2++;
			}
			if (sum2 == row - 1)
			{
				return board[i][j];
			}
		}
	}
	//判断对角线
	sum2 = 0;
	for (i = 0; i < row - 1; i++)
	{
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] != ' ')
		{
			sum2++;
		}
		if (sum2 == row - 1)
		{
			return board[i][i];
		}
	}
	//判断对角线
	sum2 = 0;
	for (i = 0; i < col - 1; i++)
	{
		if (board[i][col - 1 - i] == board[i + 1][col - 2 - i] && board[i][col - 1 - i] != ' ')
		{
			sum2++;
		}
		if (sum2 == col - 1)
		{
			return board[i][col - 1 - i];
		}
	}
	//判断棋盘是否下满，下满则平局
	sum2 = IsFull(board, ROW, COL);
	if (sum2)
		return 'D';
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

void game()
{
	//创建存入数据的二维数组
	char board[ROW][COL];
	//初始化棋盘,初始化空格
	InitBoard(board, ROW, COL);
	//打印棋盘，本质是打印数组的内容
	Display(board, ROW, COL);
	//选择下棋先手角色
	int num1 = 0;
	char result;
	do
	{
		num1 = first();
		switch (num1)
		{
		case 1:
			while (1)
			{
				//玩家下棋
				PlayerMove(board, ROW, COL);
				//打印一下棋盘
				Display(board, ROW, COL);
				//根据返回值判断输赢
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
				//电脑下棋
				CompuerMove(board, ROW, COL);
				//打印棋盘
				Display(board, ROW, COL);
				//根据返回值判断输赢
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
			}
			//判断游戏结果
			if (result == '*')
			{
				puts("玩家赢得游戏!");
			}
			else
				if (result == '#')
				{
					puts("电脑赢得游戏!");
				}
				else
					{
						puts("平局!");
					}
			Display(board, ROW, COL);
			break;
		case 2:
			while (1)
			{
				//电脑下棋
				CompuerMove(board, ROW, COL);
				//打印一下棋盘
				Display(board, ROW, COL);
				//判断输赢
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
				//玩家下棋
				PlayerMove(board, ROW, COL);
				//打印棋盘
				Display(board, ROW, COL);
				//判断输赢
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
			}
			//判断游戏结果
			if (result == '*')
			{
				puts("玩家赢得游戏!");
			}
			else
				if (result == '#')
				{
					puts("电脑赢得游戏!");
				}
				else
					{
						puts("平局!");
					}
			Display(board, ROW, COL);
			break;
		default:
			puts("选择错误，请重新选择");
			break;
		}
	} while (num1 != 1 && num1 != 2);
}

