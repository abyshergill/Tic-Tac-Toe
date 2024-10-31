#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

char array[] = "0123456789";

void arch();
int user_input(int player_turn);
int cardboard(int position_location, int loop_turn); 
int win_check();
int game_continue();
int chartoascii(int user_input);

int main(void){
	int test=1;
	arch();
	while(test<=10){

// check_user_exist check wheather the user want to quit the game or not if user want to quit user_input(test) will give 10 as return
// if user want to exist the game	
	int check_user_exit = user_input(test);
	if (check_user_exit >= 10){
		int value = 10;
		test = test + value;
	}

// if the user want to continue the game.	
	else{
		int value = cardboard(check_user_exit, test);
		test = test + value;
	}

// This whenever this condition will trigger it will ask you want to continue the game or not	
	if(test >= 10){
		int continue_value;
		continue_value = game_continue();
		if(continue_value == 1){
			system("a.exe");
		}
		else{
			test = 11;
		}
	}
	}
	return 0;
}


int cardboard(int position_location, int loop_turn){
	int loop_value = 0;
// ==============================Player 1====================================================	
/* Loop_turn is related to the player 1 turn | Logic : loop_turn%2 !=0 for all odd number */
	
	if((loop_turn%2)!=0){
		
/* This condition verify wheather that location is fill X or not */
		
		if( (array[position_location])== 'X' ){
					arch();
					printf("\n\t\tThis location Location is already fill by You  \n");
					loop_value = 0;
			}	
		
/* This condition verify wheather that location is not fill with x but if fill with O */
		
		if( (array[position_location]) != 'X'){
			if( (array[position_location])== 'O' ){
					arch();
					printf("\n\t\tThis location Location is already fill by player 2  \n");
					loop_value = 0;
			}
		}
		
/*This condition will check the blank condtion of that particular location */
		
		if( (array[position_location]) != 'X'){
			if( (array[position_location])!= 'O' ){
					array[position_location] = 'X';
					arch();
					loop_value = 1;					
			}
		}
	}

//================================Player 2===================================================	
/* Loop_turn is related to the player 2 turn | Logic : loop_turn%2 =0 for all Even number */
				
	if((loop_turn%2)==0){
		
/* This condition verify wheather that location is fill O or not */
		
		if( (array[position_location])== 'O' ){
					arch();
					printf("\n\t\tThis location Location is already fill by You  \n");
					loop_value = 0;
		}	
		
/* This condition verify wheather that location is not fill with O but if fill with X */
		
		if( (array[position_location]) != 'O'){
			if( (array[position_location])== 'X' ){
					arch();
					printf("\n\t\tThis location is already fill by player 1  \n");
					loop_value = 0;
			}
		}
		
/*This condition will check the blank condtion of that particular location */
			
		if( (array[position_location]) != 'O'){
			if( (array[position_location])!= 'X' ){
					array[position_location] = 'O';
					arch();
					loop_value = 1;
			}
		}	
	}
	if(win_check() == 31)
	 loop_value = 9;
	if(loop_turn == 9)
		{
			if (win_check() == 31){
				loop_value = 9;
			}
			else{
				printf("\t\tThis match is draw between Player 1 and Player 2\n");
				loop_value = 10;
			}
		} 

	return loop_value;
	} 

int user_input(int player_turn){
		char user_input;

//This will use operate while loop which check input is greather than 1 and less than 9.		
		bool check_user_input = true;

//If Divide by 2 is not equal to zero means player number 1
		
		if((player_turn%2)!=0){
				do{
				fflush(stdin);
				printf("\n\t\tPlayer 1 : Enter your selection in table : \n\t\t");
				scanf("%c", &user_input);

// 49 to 57 us ASCII number from 1 to 9 It will make sure press key is between 1 to 9
		
					if(user_input >= 49 && user_input <= 57){ 
							user_input = chartoascii(user_input); // This will convert ASCII to number.
							check_user_input = false;
							break;
						}
					else if(user_input == 81 || user_input == 113){
						user_input = chartoascii(user_input); // This will convert ASCII to number.
						check_user_input = false;
					}
					else{
						printf("\t\tInvalid Choice | Try again \n");
					}
				fflush(stdin);
				}while(check_user_input);
			}

//If Divide by 2 is equal to zero means player number 2


		else {
				do{
				fflush(stdin);
				printf("\n\t\tPlayer 2 : Enter your selection in table : \n\t\t");
				scanf("%c", &user_input);

// 49 to 57 us ASCII number from 1 to 9 It will make sure press key is between 1 to 9
					if(user_input >= 49 && user_input <= 57){
							user_input = chartoascii(user_input);
							check_user_input = false;
						}
					else if(user_input == 81 || user_input == 113){
						user_input = chartoascii(user_input); // This will convert ASCII to number.
						check_user_input = false;
					}
					else{
						printf("\t\tInvalid Choice | Try again \n");
					}
				fflush(stdin);
				}while(check_user_input);
			}
	return user_input;
	}	

void arch(){
	system("cls");
	printf("=============================Welcome to TIC TAC TOE=============================\n");
	printf("\t\t           |           |           \n");
	printf("\t\t    %c      |     %c     |     %c             | Player 1: 'X'  | Player 2: 'O'\n", array[1],array[2],array[3]);
	printf("\t\t           |           |           \n");
	printf("\t\t___________|___________|___________        | Quit the game Press 'Q'\n");
	printf("\t\t           |           |           \n");
	printf("\t\t     %c     |     %c     |     %c     \n", array[4],array[5],array[6]);
	printf("\t\t           |           |           \n");
	printf("\t\t___________|___________|___________\n");
	printf("\t\t           |           |           \n");
	printf("\t\t     %c     |     %c     |     %c     \n", array[7],array[8],array[9]);
	printf("\t\t           |           |           \n");
	printf("\t\t___________|___________|___________\n");
}


int game_continue(){
		int game_continue_value=0;  // This is use to terminate the while loop
		int user_decision; // This is use to check the user decision wheather he want to play or not
		char c;
		fflush(stdin);
		while(game_continue_value != 1){
				printf("\t\tDo you want to continue  Press | Y : Yes | N: No\n");
				printf("\t\tEnter your choice : ");
				c = getc(stdin);
				fflush(stdin);
			if(c == 'Y' || c == 'y'){ // check if yes
				system("cls"); 
				printf("\n\t\t ===Welcome Back===\n\n\n");	
				
				game_continue_value = 1;
				user_decision = 1;
			}
			else if(c == 'N' || c == 'n'){ // check if no
				printf("\nThanks for using this game\n");	
				game_continue_value = 1;
				user_decision = 0;
			}
			else if(game_continue_value == 0 ){ // if neither yes nor no
				printf("\t\tInvalid Choice | Try Again \n ");
			}	
		}
		return user_decision;
}

int win_check(){
	
	int win_set = 93;
/* Check Player 1 winning Combinations */	
	// Horizontal winning
	
	if(array[1] == 'X' && array[2] == 'X' && array[3] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	if(array[4] == 'X' && array[5] == 'X' && array[6] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	if(array[7] == 'X' && array[8] == 'X' && array[9] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	
	// Vertical winning
	
	if(array[1] == 'X' && array[4] == 'X' && array[7] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	if(array[2] == 'X' && array[5] == 'X' && array[8] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	if(array[3] == 'X' && array[6] == 'X' && array[9] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	// Cross winning
	
	if(array[1] == 'X' && array[5] == 'X' && array[9] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	if(array[7] == 'X' && array[5] == 'X' && array[3] == 'X'){
		printf("\t\tPlayer 1 is winner\n\n");
		win_set = 31;
	}
	
/* Check Player 2 winning Combinations */	
	// Horizontal winning
	
	if(array[1] == 'O' && array[2] == 'O' && array[3] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	if(array[4] == 'O' && array[5] == 'O' && array[6] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	if(array[7] == 'O' && array[8] == 'O' && array[9] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	
	// Vertical winning
	
	if(array[1] == 'O' && array[4] == 'O' && array[7] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	if(array[2] == 'O' && array[5] == 'O' && array[8] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	if(array[3] == 'O' && array[6] == 'O' && array[9] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	// Cross winning
	
	if(array[1] == 'O' && array[5] == 'O' && array[9] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	if(array[7] == 'O' && array[5] == 'O' && array[3] == 'O'){
		printf("\t\tPlayer 2 is winner\n\n");
		win_set = 31;
	}
	return win_set;
}

// This function will conver userinput ascii character number to real number
int chartoascii(int user_input){
	if ( user_input == 49 ) return 1;
	else if (user_input == 50) return 2;
	else if (user_input == 51) return 3;
	else if (user_input == 52) return 4;
	else if (user_input == 53) return 5;
	else if (user_input == 54) return 6;
	else if (user_input == 55) return 7;
	else if (user_input == 56) return 8;
	else if (user_input == 57) return 9;
	else if (user_input == 81) return 10; // for Q
	else if (user_input == 113) return 10; // for q
	else {
		return user_input;
	}
}
