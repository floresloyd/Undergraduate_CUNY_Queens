#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

enum CellState { EMPTY, CROSS, CIRCLE, FULL };
enum GameMode {RANDOM, COMPUTER};

///---------------------------------------------------
/// Prints the board on the screen
/// 
void PrintBoard(vector<vector<CellState>>& board) {
	printf("\n    1   2   3\n");
	printf("  +---+---+---+\n");
	for (int i = 0; i < 3; i++) {
		printf("%d |", i + 1);
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == CellState::EMPTY)
				printf("   |");
			else if (board[i][j] == CellState::CROSS)
				printf(" x |");
			else
				printf(" o |");
		} // end-for
		printf("\n");
		printf("  +---+---+---+\n");
	} // end-for
} // end-PrintBoard

///---------------------------------------------------
/// Evaluates the state of the board and returns true if
/// a player has won. If no player has won yet, returns 
/// 
CellState Evaluate(vector<vector<CellState>>& board) {
	// Check rows
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == CellState::EMPTY) continue;
		if (board[i][1] == board[i][0] and board[i][2] == board[i][0])
			return board[i][0];
	} // end-for

	// Check columns
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == CellState::EMPTY) continue;
		if (board[1][j] == board[0][j] and board[2][j] == board[0][j])
			return board[0][j];
	} // end-for

	// Check diagonals
	if (board[1][1] != CellState::EMPTY) {
		if (board[0][0] == board[1][1] and board[2][2] == board[1][1])
			return board[1][1];
		if (board[0][2] == board[1][1] and board[2][0] == board[1][1])
			return board[1][1];
	} // end-if

	// If all cells are full, it is a draw!
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == CellState::EMPTY)
				return CellState::EMPTY;

	return CellState::FULL;
} // end-Evaluate

///---------------------------------------------------
tuple<int, int, int> Move(vector<vector<CellState>>& board, int depth) {
	// If we are at a leaf node, then return the current value
	int ret = Evaluate(board);
	if (ret == CellState::CROSS) return make_tuple(-1, 0, 0); // Opponent wins
	else if (ret == CellState::CIRCLE) return make_tuple(1, 0, 0); // I win
	else if (ret == CellState::FULL) return make_tuple(0, 0, 0); // Draw

	// We are at an internal node. Continue expanding the game tree		

	if (depth % 2 == 0) {
		// Compute all possible board states and take the max. value
		int maxVal = INT_MIN;
		int r, c;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == CellState::EMPTY) {
					board[i][j] = CellState::CIRCLE;
					auto t = Move(board, depth + 1);
					board[i][j] = CellState::EMPTY;

					int val = get<0>(t);
					if (val > maxVal) {
						maxVal = val;
						r = i;
						c = j;
					} // end-if
				} // end-if
			} // end-for
		} // end-for
		return make_tuple(maxVal, r, c);

	}
	else {
		// This is where the opponent is playing
		// Compute all possible board states and take the min. value
		int minVal = INT_MAX;
		int r, c;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == CellState::EMPTY) {
					board[i][j] = CellState::CROSS;
					auto t = Move(board, depth + 1);
					board[i][j] = CellState::EMPTY;

					int val = get<0>(t);
					if (val < minVal) {
						minVal = val;
						r = i;
						c = j;
					} // end-if
				} // end-if
			} // end-for
		} // end-for
		return make_tuple(minVal, r, c);
	} // end-else
} // end-Move

///---------------------------------------------------
/// Prints the board on the screen
/// 
void MakeMove(vector<vector<CellState>>& board, GameMode mode) {
	if (mode == RANDOM){
		// Make a move randomly
		while (true) {
			int r = rand() % 3;
			int c = rand() % 3;

			if (board[r][c] == CellState::EMPTY) {
				board[r][c] = CellState::CIRCLE;
				break;
			} // end-if
		} // end-while
	} else {
		// Create a minimax game tree and make the optimal move
		// In this mode, the compute never loses :-)
		auto t = Move(board, 0);
		int r = get<1>(t);
		int c = get<2>(t);
		board[r][c] = CellState::CIRCLE;
	} // end-else
} // end-MakeMove

///---------------------------------------------------
/// Main function
/// 
int main() {
	GameMode gameMode = RANDOM;
	int choice;
	printf("Default game mode is random move.\n");
	printf("Enter 1 to play against computer or 0 to continue: ");
	cin >> choice;
	if (choice != 0) gameMode = COMPUTER;

	srand((uint32_t)time(NULL));

	vector<vector<CellState>> board(3, vector<CellState>(3, EMPTY));
	while (true) {
		PrintBoard(board);
		printf("--->Make your move (row, col): ");
		int r, c;
		scanf_s("%d %d", &r, &c);
		if (r <= 0 or r > 3) {
			printf("Invalid row! %d\n", r);
			continue;
		} // end-if

		if (c <= 0 or c > 3) {
			printf("Invalid column! %d\n", c);
			continue;
		} // end-if
		r--, c--;

		if (board[r][c] != CellState::EMPTY) {
			printf("board[%d][%d] is already full!\n", r, c);
			continue;
		} // end-if
		board[r][c] = CellState::CROSS;

		CellState ret = Evaluate(board);
		if (ret == CellState::CROSS) {
			PrintBoard(board);
			printf("===> Congratulations, you won!\n");
			break;
		}
		else if (ret == CellState::FULL) {
			PrintBoard(board);
			printf("===> We have a Draw!\n");
			break;
		} // end-if

		printf("I am making my move now...\n");
		MakeMove(board, gameMode);

		if (Evaluate(board) == CellState::CIRCLE) {
			PrintBoard(board);
			printf("===> Too bad. I won :-)\n");
			break;
		} // end-if
	} // end-while
} // end-main
