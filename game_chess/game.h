#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//棋盘行列符号的定义
#define ROW 3
#define COL 3

//打印菜单栏
void menu1();
void menu2();

//实现玩游戏功能
void game();

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void Display(char board[ROW][COL], int row, int col);

//选择下棋先手角色
int first();

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//判断输赢
char IsWin(char board[ROW][COL], int row, int col);

//电脑下棋
void CompuerMove(char board[ROW][COL], int row, int col);

//判断棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col);