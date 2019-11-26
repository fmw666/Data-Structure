#include <stdio.h>

#define BOARD_SZ  8
static int tile = 1;
static int Board[BOARD_SZ][BOARD_SZ] = {0};

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    if(size == 1)
        return;
    // 覆盖点增加
    int t = tile++;
    // 分割棋盘
    int s = size / 2;

    /* 覆盖左上角子棋盘 */
    // 特殊方格在此棋盘中
    if((dr<tr+s) && (dc<tc+s))
        ChessBoard(tr, tc, dr, dc, s);
    // 特殊方格不在此棋盘中
    else
    {
        // 用t号L型骨牌覆盖右下角
        Board[tr+s-1][tc+s-1] = t;
        // 覆盖其余方格
        ChessBoard(tr, tc, tr+s-1, tc+s-1, s);
    }

    /* 覆盖右上角棋盘 */
    // 特殊方格在此棋盘中
    if((dr<tr+s) && (dc>=tc+s))
        ChessBoard(tr, tc+s, dr, dc, s);
    // 特殊方格不在此棋盘中
    else
    {
        // 用t号L型骨牌覆盖左下角
        Board[tr+s-1][tc+s] = t;
        // 覆盖其余方格
        ChessBoard(tr, tc+s, tr+s-1, tc+s, s);
    }

    /* 覆盖左下角棋盘 */
    // 特殊方格在此棋盘中
    if((dr>=tr+s) && (dc<tc+s))
        ChessBoard(tr+s, tc, dr, dc, s);
    // 特殊方格不在此棋盘中
    else
    {
        // 用t号L型骨牌覆盖右上角
        Board[tr+s][tc+s-1] = t;
        // 覆盖其余方格
        ChessBoard(tr+s, tc, tr+s, tc+s-1, s);
    }

    /* 覆盖右下角棋盘 */
    // 特殊方格在此棋盘中
    if((dr>=tr+s) && (dc>=tc+s))
        ChessBoard(tr+s, tc+s, dr, dc, s);
    // 特殊方格不在此棋盘中
    else
    {
        // 用t号L型骨牌覆盖左上角
        Board[tr+s][tc+s] = t;
        // 覆盖其余方格
        ChessBoard(tr+s, tc+s, tr+s, tc+s, s);
    }
}

void PrintChessBoard()
{
    for(int i=0; i<BOARD_SZ; i++)
    {
        for(int j=0; j<BOARD_SZ; j++)
        {
            printf("%d ", Board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    ChessBoard(0, 0, 3, 4, BOARD_SZ);
    PrintChessBoard();

    return 0;
}