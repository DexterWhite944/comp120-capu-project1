
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_board(char board[9]) {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void display_board(char board[9]) {
    char c[9];

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            c[i] = '0' + i;
        } else {
            c[i] = board[i];
        }
    }

    printf("\n %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", c[6], c[7], c[8]);
}

bool is_winner(char board[9], char player) {
    int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[lines[i][0]] == player &&
            board[lines[i][1]] == player &&
            board[lines[i][2]] == player) {
            return true;
        }
    }

    return false;
}

char other_player(char player) {
    if (player == 'O') {
        return 'X';
    }
    return 'O';
}

int get_human_move(char board[9]) {
    int move;
    bool valid = false;

    while (!valid) {
        printf("Your turn (O). Enter a square number (0-8): ");

        if (scanf("%d", &move) != 1) {
            printf("Please enter a number from 0 to 8.\n");
            scanf("%*[^\n]");
            getchar();
        } else if (move < 0 || move > 8) {
            printf("That number is outside 0 to 8. Try again.\n");
        } else if (board[move] != ' ') {
            printf("That square is already taken. Choose an empty one.\n");
        } else {
            valid = true;
        }
    }

    return move;
}

int get_computer_move(char board[9]) {
    int move;

    do {
        move = rand() % 9;
    } while (board[move] != ' ');

    return move;
}

void take_turn(char board[9], char player) {
    int move;

    if (player == 'O') {
        move = get_human_move(board);
    } else {
        printf("Computer (X) is thinking...\n");
        move = get_computer_move(board);
        printf("Computer (X) chose square %d. Your move next!\n", move);
    }

    board[move] = player;
}

void play_game(void) {
    char board[9];
    char player = 'O';
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++) {
        take_turn(board, player);
        display_board(board);

        if (is_winner(board, player)) {
            if (player == 'O') {
                printf("You won!\n");
            } else {
                printf("Computer won!\n");
            }
            game_over = true;
        } else if (turn == 8) {
            printf("It's a draw!\n");
            game_over = true;
        } else {
            player = other_player(player);
        }
    }
}

bool play_again(void) {
    char answer;
    bool valid = false;

    while (!valid) {
        printf("Play again? (y to play, q to quit): ");

        if (scanf(" %c", &answer) != 1) {
            return false;
        }

        if (answer == 'y' || answer == 'q') {
            valid = true;
        } else {
            printf("Please enter y or q.\n");
        }
    }

    return answer == 'y';
}

int main(void) {
    srand(1);

    printf("=====================================\n");
    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");
    printf("On your turn, type the number of an empty square:\n");

    do {
        play_game();
    } while (play_again());

    printf("Thanks for playing!\n");

    return 0;
}