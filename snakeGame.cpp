// pSaurabh

#include <bits/stdc++.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
// #include<ncurses.h>

using namespace std;

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

int tt = 1;

void board(pair <int, int> &pos, pair <int, int> &food, int score){

	cout << "Score : " << score << "    Moves : " << tt << "\n";
	cout << "______________________\n";

	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 20; ++j){

			if(j == 0){
				cout << "|";
			}

			pair <int, int> match = {i, j};

			if(pos == match){
				cout << "*";
			}
			else if(food == match){
				cout << "F";
			}
			else{
				cout << " ";
			}

			if(j == 19){
				cout << "|";
			}
		}
		cout << "\n";
	}

	cout << "|____________________|\n";
	tt++;

	int x = 0;
	while(x < 200000000){
		++x;
	}
}

void game(){

	pair <int, int> pos = {0, 0};
	pair <int, int> food = {6, 6}; 
	int score = 0;

	while(1){

		if(pos.first != food.first){
			if(pos.first < food.first){
				++pos.first;
			}
			else{
				--pos.first;
			}
		}
		else if(pos.second != food.second){
			if(pos.second < food.second){
				pos.second += 2;
			}
			else{
				pos.second -= 2;
			}
		}

		system("clear");

		if(pos == food){

			int row = rand() % 10;
			int col = rand() % 10;
			col *= 2;

			food = {row, col};
			score += 1;
		}

		board(pos, food, score);
	}
}

void mainmenu(){

	cout << "1. Play\n2. Rules\n3. Quit\n";

	int x;
	cin >> x;

	if(x == 1){
		game();
	}
	else if(x == 2){
		cout << "Under Counstruction\n";

		int x;
		cin >> x;

		mainmenu();
	}
	else{
		return;
	}

}

int main(){
	// fast();

	mainmenu();

	

	return 0;	
}
