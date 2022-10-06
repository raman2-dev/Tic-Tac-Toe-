#include<iostream>

using namespace std;


void game_instructions()
{
	cout << "Game instructions:\n\n 1. The below grid shows the numbers which user can input to write to that particular cell" << endl;
	cout << "  1  |  2  |  3  \n  4  |  5  |  6  \n  7  |  8  |  9  " << endl << endl;
}
void player_sign_input(unsigned int *user_sign, char *user_symbol)
{
	cout << " Player 1 please select your symbol\n Select\n 0 - O \n 1 - X" << endl;
	while (user_sign[0] > 2)
	{
		cin >> user_sign[0];
		if (user_sign[0] > 2)
			cout << "enter correct sign" << endl;
	}
	if (user_sign[0] == 0)
	{
		user_sign[1] = 1;
		user_symbol[0] = 'O';
		user_symbol[1] = 'X';
		cout << "Player 1 Sign : O" << endl;
		cout << "Player 2 Sign : X" << endl << endl;
	}
	else
	{
		user_sign[1] = 0;
		user_symbol[0] = 'X';
		user_symbol[1] = 'O';
		cout << "Player 1 Sign : X" << endl;
		cout << "Player 2 Sign : O" << endl << endl;
	}
}

void print_currect_grid(char* grid_symbol)
{
	cout << "CURRENT GRID" << endl;
	printf("  %c  |  %c  |  %c  \n  %c  |  %c  |  %c  \n  %c  |  %c  |  %c  \n\n", grid_symbol[0], grid_symbol[1], grid_symbol[2], grid_symbol[3], grid_symbol[4], grid_symbol[5], grid_symbol[6], grid_symbol[7], grid_symbol[8]);
}

void print_grid(int grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool win_check(int grid[3][3], int input, int sign)
{ 
	int r = (input - 1) / 3;
	int c = (input - 1) % 3;
	
	if (grid[r][(c + 1) % 3] == sign && grid[r][(c + 2) % 3] == sign) // check horizontal
	{
		cout << "Win by Horizontal" << endl;
		return true;
	}
	else if (grid[(r + 1) % 3][c] == sign && grid[(r + 2) % 3][c] == sign) // check vertical
	{
		cout << "Win by Vertical" << endl;
		return true;
	}
	else if (grid[0][0] == sign && grid[1][1] == sign && grid[2][2] == sign) // check forward daigonal
	{
		cout << "Win by Forward Daigonal" << endl;
		return true;
	}
	else if (grid[2][0] == sign && grid[1][1] == sign && grid[0][2] == sign) // check backward daigonal
	{
		cout << "Win by Backward Daigonal" << endl;
		return true;
	}
	else
	{
		cout << "returning false" << endl;
		return false;
	}
	
}

int player_grid_input(int current_player, char *user_symbol, char *grid_symbol)
{
	int input=20;
	int flag = true;
	while (flag)
	{
		cout << "Player " << current_player + 1 << "(" << user_symbol[current_player] << ")" << " turn" << endl;
		cin >> input;
		if (input > 10 || input < 0 || grid_symbol[input - 1] != ' ')
		{
			cout << "Please enter correct input" << endl;
			continue;
		}
		flag = false;
	}
	return input;
}

int main()
{
	//Variables Initialization
	unsigned int user_sign[2] = {5,5};
	char user_symbol[2];
	int grid[3][3] = { {9,9,9},{9,9,9},{9,9,9} };
	int grid_count = 9;
	int game_state=0;
	int player_input[2];
	int current_player = 0;
	char grid_symbol[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	player_sign_input(user_sign, user_symbol);

	//Game instructions
	game_instructions();

	// Game options

	while (game_state!= 3)
	{
		cout << "Press 3 to start the game" << endl;
		cin >> game_state;
	}

	while (grid_count)
	{
		system("cls");
		print_currect_grid(grid_symbol);
		player_input[current_player]=player_grid_input(current_player,user_symbol,grid_symbol);
		grid_symbol[player_input[current_player] - 1] = user_symbol[current_player];
		grid[(player_input[current_player] - 1) / 3][(player_input[current_player] - 1) % 3] = user_sign[current_player];
		if (win_check(grid , player_input[current_player], user_sign[current_player]) == true)
		{
			//system("cls");
			print_currect_grid(grid_symbol);
			//print_grid(grid);
			cout << "Player " << current_player+1 << " Wins" << endl;
			system("pause>0");
			cout << "Game Ends Thank you for playing" << endl;
			return 0;
		}
		current_player = (current_player+1) % 2;
		grid_count--;
	}
	system("cls");
	print_currect_grid(grid_symbol);
	cout << "Game ended in a DRAW" << endl;
	system("pause>0");
}