#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

COORD cord = {0,0};
int flag=0, state = 1, random, fruitX, fruitY; // 1 - dir | 2 - esq | 3 - cima | 4 - baixo

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

        if(flag == 1){
            if(c == 'w'){
                state = 3;
            }else if(c == 's'){
                state = 4;
            }else if(c == 'd'){
                state = 1;
            }else if(c == 'a'){
                state = 2;
            }
            flag = 0;
        }

        switch(state){

            case 1:
                while(1){
                    if(_kbhit()){
                        c = _getch();
                        if(c != 'd'){
                            flag=1;
                            break;
                        }
                    }
                    if(cord.X == fruitX && cord.Y == fruitY){
                         return 0;
                    }
                    printf("#");
                    gotoxy(cord.X, cord.Y);
                    Sleep(50);
                    printf("%c", 32);
                    gotoxy(cord.X+1, cord.Y);
                }break;
            
            case 2:
                while(1){
                    if(_kbhit()){
                        c = _getch();
                        if(c != 'a'){
                            flag = 1;
                            break;
                        }
                    }
                    if(cord.X == fruitX && cord.Y == fruitY){
                         return 0;
                    }
                    printf("#");
                    gotoxy(cord.X, cord.Y);
                    Sleep(50);
                    printf("%c", 32);
                    gotoxy(cord.X-1, cord.Y);
                }break;

            case 3:
                while(1){
                    if(_kbhit()){
                        c = _getch();
                        if(c != 'w'){
                            flag = 1;
                            break;
                        }
                    }
                    if(cord.X == fruitX && cord.Y == fruitY){
                         return 0;
                    }
                    printf("#");
                    gotoxy(cord.X, cord.Y);
                    Sleep(100);
                    printf("%c", 32);
                    gotoxy(cord.X, cord.Y-1);
                }break;

            case 4:
                while(1){
                    if(_kbhit()){
                        c = _getch();
                        if(c != 's'){
                            flag = 1;
                            break;
                        }
                    }
                    if(cord.X == fruitX && cord.Y == fruitY){
                         return 0;
                    }
                    printf("#");
                    gotoxy(cord.X, cord.Y);
                    Sleep(100);
                    printf("%c", 32);
                    gotoxy(cord.X, cord.Y+1);
                }break;
            }

        if(cord.X == 80 || cord.Y == 25){
            return 0;
        }
        if(cord.X == fruitX && cord.Y == fruitY){
            return 0;
        }

    }

    return 0;
}