// pSaurabh

#include <bits/stdc++.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
// #include<ncurses.h>

using namespace std;

char shadow[11][11];

void build(){
	int start = 5;
	int cnt = 1;

	for(int i = 0; i < 11; ++i){
		for(int j = 0; j < 11; ++j){
			shadow[i][j] = ' ';
		}
	}

	shadow[5][2] = 'L';
	shadow[5][3] = 'O';
	shadow[5][4] = 'A';
	shadow[5][5] = 'D';
	shadow[5][6] = 'I';
	shadow[5][7] = 'N';
	shadow[5][8] = 'G';

	for(int i = 0; i < 5; ++i){
		int j = 0;
		for(; j < start; ++j){
		}

		for(; j < start + cnt; ++j){
			shadow[i][j] = '*';
		}

		start -= 1;
		cnt += 2;
	}

	for(int i = 0; i < 11; ++i){
		shadow[5][i] = '*';
	}

	start++;
	cnt -= 2;


	for(int i = 6; i < 11; ++i){
		int j = 0;
		for(; j < start; ++j){
		}

		for(; j < start + cnt; ++j){
			shadow[i][j] = '*';
		}

		start += 1;
		cnt -= 2;
	}

	for(int i = 0; i < 11; ++i){
		for(int j = 0; j < 11; ++j){
			cout << shadow[i][j];
		}
		cout << "\n";
	}
}

void hold(){
	for(int i = 0; i < 35000000; ++i){
	}
}

void loading(){

	char ch = '@';
	int x = 0;
	int itr = 0;

	while(itr < 50){

		for(int j = 0; j < 11; ++j){
			if(shadow[x][j] != ' '){
				shadow[x][j] = ch;
			}
		}

		++x;

		if(x == 11){
			x = 0;
			 if(ch == '@') ch = '*';
			 else ch = '@';
		}

		shadow[5][2] = 'L';
		shadow[5][3] = 'O';
		shadow[5][4] = 'A';
		shadow[5][5] = 'D';
		shadow[5][6] = 'I';
		shadow[5][7] = 'N';
		shadow[5][8] = 'G';

		for(int i = 0; i < 11; ++i){
			for(int j = 0; j < 11; ++j){
				cout << shadow[i][j] << " ";
			}
			cout << "\n";
		}

		hold();
		system("clear");

		++itr;

	}
}

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

bool onFood = 0;
int tt = 1;

void board(deque <pair <int, int>> &pos, pair <int, int> &food, int score, char movement){

	cout << "Score : " << score << "    Moves : " << tt << "\n";
	cout << "______________________\n";

	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 20; ++j){

			pair <int, int> match = {i, j};

			bool ok = 0;

			for(int k = 0; k < pos.size(); ++k){
				if(pos[k] == match){
					ok = 1;
					break;
				}
			}

			if(j == 0){
				cout << "|";
			}

			if(food == match){
				cout << "F";
			}
			else if(ok){
				if(pos[0] == match){
					if(onFood){
						if(movement == 'u'){
							cout << '/';
						}
						else if(movement == 'd'){
							cout << '^';
						}
						else if(movement == 'l'){
							cout << '>';
						}
						else{
							cout << "<";
						}
						onFood = 0;
					}
					else{
						if(movement == 'u' || movement == 'd'){
							cout << "|";
						}
						else{
							cout << "-";
						}
					}
				}
				else cout << "*";
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

	srand(time(0));

	deque <pair <int, int>> pos;
	pos.push_back({0, 4});
	pos.push_back({0, 2});
	pos.push_back({0, 0});

	pair <int, int> food = {6, 6};

	int score = 0;
	char movement = 'l';

	while(1){

		pair <int, int> newHead = pos[0];

		if(pos[0].first != food.first){
			if(pos[0].first < food.first){
				++newHead.first;
				movement = 'd';
			}
			else{
				--newHead.first;
				movement = 'u';
			}
		}
		else if(pos[0].second != food.second){
			if(pos[0].second < food.second){
				newHead.second += 2;
				movement = 'r';
			}
			else{
				newHead.second -= 2;
				movement = 'l';
			}
		}

		pair <int, int> tmp = pos[pos.size() - 1];
		pos.pop_back();
		pos.push_front(newHead);

		system("clear");

		if(newHead == food){
			onFood = 1;
			bool cantcreate = 0;
			if(pos.size() < 15) pos.push_back(tmp);

			int g = 0;
			while(g < 10){

				int row = rand() % 10;
				int col = rand() % 10;
				col *= 2;

				food = {row, col};

				for(int j = 0; j < pos.size(); ++j){

					if(pos[j] == food){
						cantcreate = 1;
						break;
					}
				}

				++g;
				if(!cantcreate){
					break;
				}
			}

			score += 1;
		}

		board(pos, food, score, movement);
	}
}

void mainmenu(){

	build();
	loading();

	cout << "\n\n\n\t1. Simulate\n\t2. Quit\n";

	char x = getch();

	if(x == '1'){
		game();
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
