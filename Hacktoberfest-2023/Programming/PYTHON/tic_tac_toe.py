def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_win(board, player):
    for row in board:
        if all([cell == player for cell in row]):
            return True

    for col in range(3):
        if all([board[row][col] == player for row in range(3)]):
            return True

    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):
        return True

    return False

def is_board_full(board):
    for row in board:
        if " " in row:
            return False
    return True

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    player = "X"

    print("Welcome to Tic-Tac-Toe!")

    while True:
        print_board(board)
        try:
            position = int(input(f"Player {player}, enter your move (0-8): "))
            if position < 0 or position > 8:
                print("Invalid move. Try again.")
                continue

            row, col = divmod(position, 3)
            
            if board[row][col] != " ":
                print("That position is already taken. Try again.")
                continue

            board[row][col] = player

            if check_win(board, player):
                print_board(board)
                print(f"Player {player} wins!")
                break
            elif is_board_full(board):
                print_board(board)
                print("It's a draw!")
                break

            player = "O" if player == "X" else "X"
        except ValueError:
            print("Invalid input. Please enter a number between 0 and 8.")

if __name__ == "__main__":
    main()
