//James Harris
//TicTacToe Game

#include <iostream>

int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int playerTurn = 0;
enum WinStatus { notWon, horizontal, vertical, diagonal };

void printBoard();
void printGameWon();
bool turn(int player);
WinStatus checkWin(int tempBoard[3][3]);
bool canWin(int player);
bool checkTie();


int main(){
	
	std::cout << "The Game has Begun!" << std::endl;
	
	while((checkWin(board) == notWon) && !checkTie()){
		if(turn(playerTurn%2+1)){
			playerTurn++;
		}
	}
	std::cout << std::endl << std::endl << std:: endl << std::endl;
	if(checkTie()){
		printBoard();
		std::cout << std::endl  << "Tie Game! Everyone Loses!" << std::endl;
	}
	else{
		printGameWon();
		printBoard();
		std::cout << std::endl << std::endl << "Congratulations! Player ";
		std::cout << (playerTurn-1)%2+1 << " has won ";
		switch(checkWin(board)){
			case horizontal: std::cout << "horizontal";
							 break;
		 	case vertical:	std::cout << "vertical";
		 					break;
			case diagonal: std::cout << "diagonal";
							break;
		}
		std::cout << "ly!!" << std::endl;
		
	}
}

void printGameWon(){
	std::cout << "░██████╗░░█████╗░███╗░░░███╗███████╗  ░██╗░░░░░░░██╗░█████╗░███╗░░██╗" << std::endl;
	std::cout << "██╔════╝░██╔══██╗████╗░████║██╔════╝  ░██║░░██╗░░██║██╔══██╗████╗░██║" << std::endl;
	std::cout << "██║░░██╗░███████║██╔████╔██║█████╗░░  ░╚██╗████╗██╔╝██║░░██║██╔██╗██║" << std::endl;
	std::cout << "██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ░░████╔═████║░██║░░██║██║╚████║" << std::endl;
	std::cout << "╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ░░╚██╔╝░╚██╔╝░╚█████╔╝██║░╚███║" << std::endl;
	std::cout << "░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚══╝" << std::endl;
}

void printBoard(){
	std::cout << "   A   B   C" << std::endl;
	for(int i=0; i<=2; i++){
		std::cout << i+1 << "  ";
		for(int j =0; j<=2; j++){
			switch(board[i][j]){
				case 0: std::cout << " ";
						break;
				case 1: std::cout << "X";
						break;
				case 2: std::cout << "O";
						break;
			}
			if(j!=2){
				std::cout << " | ";
			}
		}
		
		std::cout << std::endl;
		if(i!=2){
				std::cout << "   ---------" << std::endl;
			}
		 
	}
}

WinStatus checkWin(int tempBoard[3][3]){
	//check for horizontal win
	int horizCounter1 = 0;
	int horizCounter2 = 0;
	for(int i=0; i<=2; i++){
		for(int j =0; j<=2; j++){
			if(tempBoard[i][j] == 1){
				horizCounter1++;
			}
			else if(tempBoard[i][j] == 2){
				horizCounter2++;
			}
		}
		if(horizCounter1 == 3 || horizCounter2 == 3){
			return horizontal;
		}
		else{
			horizCounter1 = 0;
			horizCounter2 = 0;
		}	 
	}
	
	//check for vertical win
	int vertCounter1 = 0;
	int vertCounter2 = 0;
	for(int j=0; j<=2; j++){
		for(int i =0; i<=2; i++){
			if(tempBoard[i][j] == 1){
				vertCounter1++;
			}
			else if(tempBoard[i][j] == 2){
				vertCounter2++;
			}
		}
		if(vertCounter1 == 3 || vertCounter2 == 3){
			return vertical;
		}
		else{
			vertCounter1 = 0;
			vertCounter2 = 0;
		}	 
	}
	
	//check for diagonal win
	if(((tempBoard[0][0] != 0) && (tempBoard[0][0] == tempBoard[1][1]) && (tempBoard[0][0] == tempBoard[2][2])) || ((tempBoard[2][0] != 0) && (tempBoard[2][0]==tempBoard[1][1]) && (tempBoard[2][0] == tempBoard[0][2]))){
		return diagonal;
	}
	
	//not won
	return notWon;
}

bool turn(int player){
	char rowInput;
	char columnInput;
	printBoard();
	std::cout << "It is player " << player << "'s turn!" << std::endl;
	std::cout << "Where would player " << player << " like to move?" << std::endl;
	
	do{
		std::cout << "Enter Row(1, 2, or 3) and then Column(A, B, or C): ";
		std::cin >> rowInput;
	}while((rowInput != '1') && (rowInput != '2') && (rowInput != '3'));
	std::cin >> columnInput;
	while((columnInput != 'A') && (columnInput != 'B') && (columnInput != 'C')){
		std::cout << "Enter Column(A, B, or C): ";
		std::cin >> columnInput;
	}
	std::cout << std::endl << std::endl;
	if(board[rowInput-49][columnInput-65] == 0){
		board[rowInput-49][columnInput-65] = player;
		std::cout << std::endl;
		return true;
	}
	else{
		std::cout<<std::endl << "Space already occupied" << std::endl << std::endl;
		return false;
	}
}

bool checkTie(){
	int emptySpaces = 0;
	for(int i=0; i<=2; i++){
		for(int j =0; j<=2; j++){
			if(board[i][j] == 0){
				emptySpaces++;
			}
		}	 
	}
	
	if(emptySpaces == 1 && canWin(1) && playerTurn%2+1 == 2){
		return true;
	}
	else if(emptySpaces == 1 && canWin(2) && playerTurn%2+1 == 1){
		return true;
	}
	return false;
	
}

bool canWin(int player){
	int tempBoard[3][3];
	for(int i=0; i<=2; i++){
		for(int j =0; j<=2; j++){
			//fill empty spaces with player's value
			if(board[i][j] == 0){
				tempBoard[i][j] = player;
			}
			else{
				tempBoard[i][j] = board[i][j];
			}
		}	 
	}
	
	if(checkWin(tempBoard) == notWon){
		return false;
	}
	//If we reach this point, this player cannot win.
	return true;
}
