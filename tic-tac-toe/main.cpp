#include <iostream>

void show_playField(char a[][3]) {
    std::cout<<"The play field:"<<std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            std::cout << a[i][j];
        std::cout << std::endl;
    }
}

void find_winner(char a[][3], bool& endOfGame) {
    char winner;
    for (int i = 0; i < 3; i++) {
        bool found = true;
        int firstElement1 = a[i][0], firstElement2 = a[0][i];
        for (int j = 1; j < 3; j++)
            if (a[i][j] != firstElement1 || firstElement1 == ' ') {
                found = false;
                break;
            }
            else
                winner = a[i][j];
        if (!found) {
            found = true;
            for (int j = 1; j < 3; j++)
                if (a[j][i] != firstElement2 || firstElement2 == ' ') {
                    found = false;
                    break;
                } else
                    winner = a[j][i];
        }
        if (found) {
            std::cout << winner << " won";
            endOfGame = true;
            break;
        }
    }
}

int main() {
    char playField[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    bool endOfGame = false;
    int move = 1;                              //номер шага
    while (endOfGame==false) {
        int x,y;
        if (move%2==1)
            std::cout<<"X move:"<<std::endl;
        else
            std::cout<<"O move:"<<std::endl;
        std::cout<<"Enter x and y coordinates of a cell ranging from 0 to 2:"<<std::endl;
        std::cin>>x>>y;
        while (x<0 || x>2 || y<0 || y>2) {
            std::cout<<"Wrong input! Try again."<<std::endl;
            std::cin>>x>>y;
        }
        while (playField[y][x]!=' ') {
            std::cout<<"This cell is occupied, try again:"<<std::endl;
            std::cin>>x>>y;
        }
        if (move%2==1)
            playField[y][x]='X';
        else
            playField[y][x]='O';
        move++;
        show_playField(playField);              //выводим поле
        find_winner(playField,endOfGame);    //ищем победителя
        if (!endOfGame && move==10) {           //если это 9-й ход и победителя нет, объявляем ничью
            std::cout << "It's a tie!";
            endOfGame=true;
        }
    }
    return 0;
}
