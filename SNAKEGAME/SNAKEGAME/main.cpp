#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

typedef struct {
    int direction;
    int posx;
    int posy;
} block;

COORD cord = {0,0};
block snakeBody[2000];
int flag=0, state = 1, random, fruitX, fruitY, n=1; // 1 - dir | 2 - esq | 3 - cima | 4 - baixo
int holdHeadX, holdHeadY;

void gotoxy(int x, int y){
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

void placeFruit(){
    int holdX, holdY;
    holdX = cord.X;
    holdY = cord.Y;
    fruitX = rand() % 80;
    fruitY = rand() % 25;

    gotoxy(fruitX, fruitY);
    printf("0");

    cord.X = holdX;
    cord.Y = holdY;
    gotoxy(cord.X, cord.Y);
}

void updateFrame(){

    for(int i=0; i<n;i++){
        if(snakeBody[i].direction == 1){
            gotoxy(snakeBody[i].posx+1, snakeBody[i].posy);
            printf("#");

            if(n > 1){
                snakeBody[i-1].posx = snakeBody[i].posx;
                snakeBody[i-1].posy = snakeBody[i].posy;
                snakeBody[i-1].direction = snakeBody[i].direction;
            }
            snakeBody[i].posx++;
        }
        if(snakeBody[i].direction == 2){
            gotoxy(snakeBody[i].posx-1, snakeBody[i].posy);
            printf("#");

            if(n > 1){
                snakeBody[i-1].posx = snakeBody[i].posx;
                snakeBody[i-1].posy = snakeBody[i].posy;
                snakeBody[i-1].direction = snakeBody[i].direction;
            }
            snakeBody[i].posx--;
        }
        if(snakeBody[i].direction == 3){
            gotoxy(snakeBody[i].posx, snakeBody[i].posy+1);
            printf("#");

            if(n > 1){
                snakeBody[i-1].posx = snakeBody[i].posx;
                snakeBody[i-1].posy = snakeBody[i].posy;
                snakeBody[i-1].direction = snakeBody[i].direction;
            }
            snakeBody[i].posy++;;
        }
        if(snakeBody[i].direction == 4){
            gotoxy(snakeBody[i].posx, snakeBody[i].posy-1);
            printf("#");

            if(n > 1){
                snakeBody[i-1].posx = snakeBody[i].posx;
                snakeBody[i-1].posy = snakeBody[i].posy;
                snakeBody[i-1].direction = snakeBody[i].direction;
            }
            snakeBody[i].posy--;
        }
    }

    gotoxy(snakeBody[n-1].posx, snakeBody[n-1].posy);
    printf("%c", 32);
    gotoxy(snakeBody[0].posx, snakeBody[0].posy);
    Sleep(100);

}

int main(){
    char c;
    gotoxy(40, 12);
    srand( (unsigned)time(NULL) );
    placeFruit();

    //play
    while(1){
        /* printf("%c", 219);
        gotoxy(cord.X, cord.Y);
        Sleep(100);
        printf("%c", 32);
        gotoxy(cord.X+1, cord.Y); */ 

        updateFrame();


        if(cord.X == 80 || cord.Y == 25){
            return 0;
        }
        if(cord.X == fruitX && cord.Y == fruitY){
            return 0;
        }

    }

    return 0;
}