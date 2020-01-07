#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


using std::cout;
using std::cin;
using std::endl;
using std::string;

void DrawBoard();
void DisplayMainMenu();
void CheckGameOver();
void SwitchPlayer();
void ResetBoard();
void PlayGame();
string PlacePiece();


string board[9][3] =
    {
        {"     ", "|     |", "     "}, // 0
        {"     ", "|     |", "     "}, // 1
        {"_____", "|_____|", "_____"}, // 2
        {"     ", "|     |", "     "}, // 3
        {"     ", "|     |", "     "}, // 4
        {"_____", "|_____|", "_____"}, // 5
        {"     ", "|     |", "     "}, // 6
        {"     ", "|     |", "     "}, // 7
        {"     ", "|     |", "     "}  // 8
    };
/*
    Display main menu
    Get Player names
    Determine starting player
    Get player's choice
    Determine if valid move
    Check Game Over
    Switch turns
*/

string first_player_name {};
string second_player_name {};

bool is_player_one_turn;
bool is_gameover {false};

int main()
{
    bool should_exit = false;
    do
    {
        system("clear");

        DisplayMainMenu();
        cout << "Please select an option: ";
        string menu_input {};
        getline(cin, menu_input);

        if(menu_input == "1")
        {
            PlayGame();
        }
        else if(menu_input == "2")
        {
            return 0;
        }
        else
        {
            cout << "Entered invalid option, please try again." << endl;
            string temp;
            getline(cin, temp);
            continue;   
        }
    }while(should_exit == false);
}

void DrawBoard()
{
    for(size_t i {0}; i < 9; i++)
        {
            for(size_t m {0}; m < 3; m++)
            {
                cout << board[i][m];
            }
            cout << endl;
        }
}

void DisplayMainMenu()
{
        cout << "\t\t\tWelcome to Tic Tac Toe\n\n" << endl;
        DrawBoard();
        cout << "\n\n\n";
        cout << "[1] Play a game!" << endl;
        cout << "[2] Quit!" << endl;        
}

void PlayGame()
{
    srand(time(NULL));

    system("clear");
    cout << "Please enter player one's name: ";
    getline(cin, first_player_name);
    cout << "Thank you!" << endl;
    cout << "Please enter player two's name: ";
    getline(cin, second_player_name);

    system("clear");

    int random_starting_player { rand() % 30};

    is_player_one_turn = random_starting_player % 2 == 0 ? true : false;

    do
    {
        system("clear");
        DrawBoard();
        int input {};
        if(is_player_one_turn)
        {
            cout << first_player_name;        
        }
        else
        {
            cout << second_player_name;
        }

        cout << " Enter a tile to place your piece [1-9]: ";
        cin >> input;

        if(input == 1 && board[1][0] == "     ")
        {
            board[1][0] = PlacePiece();
        }
        else if(input == 2 && board[1][1] == "|     |")
        {
            board[1][1] = "|" + PlacePiece() + "|";
        }
        else if(input == 3 && board[1][2] == "     ")
        {
            board[1][2] = PlacePiece();
        }
        else if(input == 4 && board[4][0] == "     ")
        {
            board[4][0] = PlacePiece();
        }
        else if(input == 5 && board[4][1] == "|     |")
        {
            board[4][1] = "|" + PlacePiece() + "|";
        }
        else if(input == 6 && board[4][2] == "     ")
        {
            board[4][2] = PlacePiece();
        }
        else if(input == 7 && board[7][0] == "     ")
        {
            board[7][0] = PlacePiece();
        }
        else if(input == 8 && board[7][1] == "|     |")
        {
            board[7][1] = "|" + PlacePiece() + "|";
        }
        else if(input == 9 && board[7][2] == "     ")
        {
            board[7][2] = PlacePiece();
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }


        
    }while(is_gameover == false);

}

void ResetBoard()
{
    board[1][0] = "     ";
    board[1][1] = "|     |";
    board[1][2] = "     ";
    board[4][0] = "     ";
    board[4][1] = "|     |";
    board[4][2] = "     ";
    board[7][0] = "     ";
    board[7][1] = "|     |";
    board[7][2] = "     ";
}

string PlacePiece()
{
    if(is_player_one_turn)
    {
        return "  X  ";
    }
    else 
    {
        return "  O  ";
    }
}