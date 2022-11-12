#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//�������з��ŵĶ���
#define ROW 3
#define COL 3

//��ӡ�˵���
void menu1();
void menu2();

//ʵ������Ϸ����
void game();

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void Display(char board[ROW][COL], int row, int col);

//ѡ���������ֽ�ɫ
int first();

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

//��������
void CompuerMove(char board[ROW][COL], int row, int col);

//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);