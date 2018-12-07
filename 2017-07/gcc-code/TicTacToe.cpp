#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class TicTacToe {
private:
  char board [3][3];
  char player;
  bool gameover;
  int input[2];
  int movestaken;

  void display() {
    cout << "  1 " << "2 " << "3 " << " " << endl;
    cout << "  ------" << endl;

  	for (int row = 0; row < 3;row++) {
      cout << row + 1 << "| ";
      for (int column = 0;  column < 3; column++) {
  		  cout << board[row][column] << " ";
  	  }
  	  cout << endl;
  	}
  }

  void getuserinput()
  {
    // Reinitialize these variables so we know if new input was accepted or not
    string inputstring = "";
    input[0] = 5;
    input[1] = 5;

    cout << "Player " << player << " enter a pair of coordinates in row,column format (ex: '1,1'): ";
    cin >> inputstring;

    while(!validinput(inputstring)) {
      cout << "Input is invalid, please enter a digit followed by a comma, then another digit, try again: ";
      cin >> inputstring;
    }
  }

  bool validinput(string inputstring) {
    if(inputstring.length() != 3) {
      return false;
    }

    if(inputstring[0] == '1') {
      input[0] = 1;
    } else if(inputstring[0] == '2') {
      input[0] = 2;
    } else if(inputstring[0] == '3' ) {
      input[0] = 3;
    } else {
      return false;
    }

    if(inputstring[2] == '1') {
      input[1] = 1;
    } else if(inputstring[2] == '2') {
      input[1] = 2;
    } else if(inputstring[2] == '3' ) {
      input[1] = 3;
    } else {
      return false;
    }

    if(board[input[0]-1][input[1]-1] != '*') {
      return false;
    }

    return true;
  }

  void makemove() {
    board[input[0]-1][input[1]-1] = player;
    movestaken++;

    if(isplayerwinner()) {
      cout << endl << "Player " << player << " has won!" << endl;
      gameover = true;
    } else if(isdraw()) {
      cout << endl << "The game is a tie!" << endl;
      gameover = true;
    }

    if(player == 'x') {
      player = 'o';
    } else {
      player = 'x';
    }
  }

  bool isdraw() {
    if(movestaken == 9) {
      return true;
    }

    return false;
  }

  bool isplayerwinner() {
  	// check winner horizonatlly
  	if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
  		return true;
  	if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
  		return true;
  	if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
  		return true;
  	//check winner vertically
  	if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
  		return true;
  	if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
  		return true;
  	if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
  		return true;
  	//check winner diagonally
  	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  		return true;
  	if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
  		return true;

  	return false;
  }

public:
  TicTacToe() {
    gameover = false;
    player = 'x';
    movestaken = 0;

    for(int row = 0; row < 3; row++) {
      for(int column = 0; column < 3; column++) {
        board[row][column] = '*';
      }
    }
  }

  void run() {
    cout << "Let's play Tic Tac Toe!" << endl;

    while(!gameover) {
      display();
      getuserinput();
      makemove();
    }

    display();
  }
};

int main() {

  TicTacToe game;
  game.run();

	return 0;
}
