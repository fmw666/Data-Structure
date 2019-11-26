BOARD_SZ = 8
tile = 1
Board = [[0 for i in range(BOARD_SZ)] for i in range(BOARD_SZ)]

def chess_board(tr, tc, dr, dc, size):
    if size == 1:
        return
    global Board
    global tile
    # 覆盖点增加
    t = tile
    tile += 1
    # 分割棋盘
    s = size // 2

    '''覆盖左上角子棋盘'''
    # 特殊方格在此棋盘中
    if dr<tr+s and dc<tc+s:
        chess_board(tr, tc, dr, dc, s)
    # 特殊方格不在此棋盘中
    else:
        # 用t号L型骨牌覆盖右下角
        Board[tr+s-1][tc+s-1] = t
        # 覆盖其余方格
        chess_board(tr, tc, tr+s-1, tc+s-1, s)
    
    '''覆盖右上角子棋盘'''
    # 特殊方格在此棋盘中
    if dr<tr+s and dc>=tc+s:
        chess_board(tr, tc+s, dr, dc, s)
    # 特殊方格不在此棋盘中
    else:
        # 用t号L型骨牌覆盖左下角
        Board[tr+s-1][tc+s] = t
        # 覆盖其余方格
        chess_board(tr, tc+s, tr+s-1, tc+s, s)

    '''覆盖左下角子棋盘'''
    # 特殊方格在此棋盘中
    if dr>=tr+s and dc<tc+s:
        chess_board(tr+s, tc, dr, dc, s)
    # 特殊方格不在此棋盘中
    else:
        # 用t号L型骨牌覆盖右上角
        Board[tr+s][tc+s-1] = t
        # 覆盖其余方格
        chess_board(tr+s, tc, tr+s, tc+s-1, s)
    
    '''覆盖右下角子棋盘'''
    # 特殊方格在此棋盘中
    if dr>=tr+s and dc>=tc+s:
        chess_board(tr+s, tc+s, dr, dc, s)
    # 特殊方格不在此棋盘中
    else:
        # 用t号L型骨牌覆盖左上角
        Board[tr+s][tc+s] = t
        # 覆盖其余方格
        chess_board(tr+s, tc+s, tr+s, tc+s, s)

def print_chess_board():
    for i in range(BOARD_SZ):
        for j in range(BOARD_SZ):
            global Board
            print(str(Board[i][j]) + ' ', end="")
        print()

chess_board(0, 0, 3, 4, BOARD_SZ)
print_chess_board()