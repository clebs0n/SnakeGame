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
int holdHeadX, holdHeadY, lower=1;

void gotoxy(int x, int y){
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

void checkColision(){
    if(cord.X == 79 || cord.X == 0 || cord.Y == 25 || cord.Y == 0){
        exit(0);
    }
}

int checkFruit(){
    if(cord.X == fruitX && cord.Y == fruitY){
        return 1;
    }
    return 0;
}

void placeFruit(){
    int holdX, holdY;
    holdX = cord.X;
    holdY = cord.Y;

    fruitX = (rand() % (78 - lower + 1)) + lower;
    fruitY = (rand() % (23 - lower + 1)) + lower;

    gotoxy(fruitX, fruitY);
    printf("0");

    cord.X = holdX;
    cord.Y = holdY;
    gotoxy(cord.X, cord.Y);
}

void updateDirection(char c){
    if(c == 'w'){
        snakeBody[0].direction = 3;
    }else if(c == 's'){
        snakeBody[0].direction = 4;
    }else if(c == 'd'){
        snakeBody[0].direction = 1;
    }else if(c == 'a'){
        snakeBody[0].direction = 2;
    }
}

void drawCanva(){
    for(int i=0; i < 80; i++){
        printf(".");
    }
    gotoxy(0, 25);
    for(int i=0; i < 80; i++){
        printf(".");
    }
    gotoxy(0,0);
    for(int i=0; i < 25; i++){
        printf(".\n");
    }
    gotoxy(79, 0);
    for(int i=0; i < 26; i++){
        printf(".");
        gotoxy(79, i);
    }
}

void updateHead(){

    if(n > 1){
        for(int i=n; i > 1; i--){
            snakeBody[i-1].posx = snakeBody[i-2].posx;
            snakeBody[i-1].posy = snakeBody[i-2].posy;
        }
    }

    if(snakeBody[0].direction == 1){
        snakeBody[0].posx++;
        gotoxy(snakeBody[0].posx, snakeBody[0].posy);
        printf("#");
    }else if(snakeBody[0].direction == 2){
        snakeBody[0].posx--;
        gotoxy(snakeBody[0].posx, snakeBody[0].posy);
        printf("#");
    }else if(snakeBody[0].direction == 3){
        snakeBody[0].posy--;
        gotoxy(snakeBody[0].posx, snakeBody[0].posy );
        printf("#");
    }else if(snakeBody[0].direction == 4){
        snakeBody[0].posy++;;
        gotoxy(snakeBody[0].posx, snakeBody[0].posy);
        printf("#");
    }

    Sleep(70);
    gotoxy(snakeBody[n-1].posx, snakeBody[n-1].posy);
    printf("%c", 32);

    gotoxy(snakeBody[0].posx, snakeBody[0].posy);

}

void play(){
    char c;
    drawCanva();
    placeFruit();
    snakeBody[0].posx = 40; snakeBody[0].posy = 12;

    //play
    while(1){

        updateHead();

        if(_kbhit()){
            c = _getch();
            updateDirection(c);
        }

        checkColision();
        if(checkFruit()){
            n++;
            placeFruit();
        }

    }
}

void drawMenu()
{

    int option=0, key, posx=10, flag=0, charr = 175;
    gotoxy(35, 10);
    cout << "PLAY";
    gotoxy(35,12);
    cout << "HELP";
    gotoxy(35, 14);
    cout << "CREDITS";
    gotoxy(32, posx);
    printf("%c", charr);

    while(option != 13)
    {

        if(_kbhit() && flag == 0)
        {
            key = _getch();
            option = key;
            flag = 1;

            if(key == 115)
            {
                if((posx + 2) > 14)
                {
                    gotoxy(32, 14);
                    printf("%c", 32);
                    gotoxy(32, 10);
                    posx= 10;
                    printf("%c", charr);
                }
                else
                {
                    gotoxy(32, posx);
                    printf("%c", 32);
                    gotoxy(32, posx+=2);
                    printf("%c", charr);
                }

            }
            else if(key == 119)
            {
                if((posx - 2) < 10)
                {
                    gotoxy(32, 10);
                    printf("%c", 32);
                    gotoxy(32, 14);
                    posx = 14;
                    printf("%c", charr);
                }
                else
                {
                    gotoxy(32, posx);
                    printf("%c", 32);
                    gotoxy(32, posx-=2);
                    printf("%c", charr);
                }
            }
        }
        if(flag == 1)
        {
            Sleep(100);
            flag = 0;
        }
    }
    if(posx == 10)
    {
        system("cls");
        play();
    }
    else if(posx == 14)
    {
        system("cls");
        printf("Desenvolvido por : JOSE CLEBON DE SOUZA OLIVEIRA\nAluno do Centro de Informática da UFPE");
        while(1)
        {
            if(_kbhit())
            {
                key = _getch();
                if(key == 27)
                {
                    system("cls");
                    drawMenu();
                }
                else
                {
                    return;
                }
            }
        }
    }
}


int main(){
    srand((unsigned)time(NULL));
    drawMenu();

    return 0;
}
