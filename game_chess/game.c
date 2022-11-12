#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu1()
{
	puts("******************************");
	puts("*********1.��ʼ��Ϸ**********");
	puts("*********2.�˳���Ϸ**********");
	puts("******************************");
}
void menu2()
{
	puts("******************************");
	puts("*********1.������Ϸ**********");
	puts("*********2.�˳���Ϸ**********");
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
	puts("���������ֽ�ɫ1.��ң�2.����");
	scanf("%d", &input);
	getchar();
	return input;
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	puts("�����->");
	while (1)
	{
		printf("��������������꣺");
		scanf("%d %d", &i, &j);
		getchar();
		//�ж���������Ϸ���
		if (i <= row && i >= 1 && j <= col && j >= 1)
		{
			//�ж������Ƿ�ռ��
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				puts("���걻ռ�ã�����������");
			}
		}
		else
		{
			puts("��������������������롣");
		}
	}
}

void CompuerMove(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	puts("������->");
	while (1)
	{
		i = (int)rand() % row;
		j = (int)(rand() * col / (RAND_MAX + 1));
		//�ж�ռ��
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
	//�ж���
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
	//�ж���
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
	//�ж϶Խ���
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
	//�ж϶Խ���
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
	//�ж������Ƿ�������������ƽ��
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
	//�����������ݵĶ�ά����
	char board[ROW][COL];
	//��ʼ������,��ʼ���ո�
	InitBoard(board, ROW, COL);
	//��ӡ���̣������Ǵ�ӡ���������
	Display(board, ROW, COL);
	//ѡ���������ֽ�ɫ
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
				//�������
				PlayerMove(board, ROW, COL);
				//��ӡһ������
				Display(board, ROW, COL);
				//���ݷ���ֵ�ж���Ӯ
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
				//��������
				CompuerMove(board, ROW, COL);
				//��ӡ����
				Display(board, ROW, COL);
				//���ݷ���ֵ�ж���Ӯ
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
			}
			//�ж���Ϸ���
			if (result == '*')
			{
				puts("���Ӯ����Ϸ!");
			}
			else
				if (result == '#')
				{
					puts("����Ӯ����Ϸ!");
				}
				else
					{
						puts("ƽ��!");
					}
			Display(board, ROW, COL);
			break;
		case 2:
			while (1)
			{
				//��������
				CompuerMove(board, ROW, COL);
				//��ӡһ������
				Display(board, ROW, COL);
				//�ж���Ӯ
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
				//�������
				PlayerMove(board, ROW, COL);
				//��ӡ����
				Display(board, ROW, COL);
				//�ж���Ӯ
				result = IsWin(board, ROW, COL);
				if (result != 'C')
					break;
			}
			//�ж���Ϸ���
			if (result == '*')
			{
				puts("���Ӯ����Ϸ!");
			}
			else
				if (result == '#')
				{
					puts("����Ӯ����Ϸ!");
				}
				else
					{
						puts("ƽ��!");
					}
			Display(board, ROW, COL);
			break;
		default:
			puts("ѡ�����������ѡ��");
			break;
		}
	} while (num1 != 1 && num1 != 2);
}

