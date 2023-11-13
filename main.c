#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int i, j, score, gameOver;
int snakeX, snakeY, fruitX, fruitY, direction;

void drawBoundaries()
{

    /*
    This function draws the boundries of the game and all the objects
    Input: None
    Output: None
    */
    system("CLS");
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                printf("#");
            }
            else
            {
                if (i == snakeY && j == snakeX)
                    printf("0");
                else if (i == fruitY && j == fruitX)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void initialize()
{

    /*
    This function intialize all the global variables
    Input: None
    Output: None
    */
    gameOver = 0;
    snakeX = WIDTH / 2;
    snakeY = HEIGHT / 2;

    do
    {
        fruitX = rand() % (WIDTH - 2) + 1;
        fruitY = rand() % (HEIGHT - 2) + 1;
    } while (fruitX == snakeX || fruitY == snakeY);

    score = 0;
}

void getInput()
{

    /*
    This function resolve the pressed key to direction
    Input: None
    Output: None
    */
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            direction = 1;
            break;
        case 'd':
            direction = 2;
            break;
        case 's':
            direction = 3;
            break;
        case 'a':
            direction = 4;
            break;
        case 'q':
            gameOver = 1;
            break;
        }
    }
}

void engine()
{

    /*
    This function change snake's coordinate by direction and init new fruit if eat.
    Input: None
    Output: None
    */
    Sleep(100);

    switch (direction)
    {
    case 1:
        snakeY -= 1;
        break;
    case 2:
        snakeX += 1;
        break;
    case 3:
        snakeY += 1;
        break;
    case 4:
        snakeX -= 1;
        break;
    default:
        break;
    }

    if (snakeX <= 0 || snakeX >= WIDTH - 1 || snakeY <= 0 || snakeY >= HEIGHT - 1)
    {
        gameOver = 1;
    }

    if (snakeX == fruitX && snakeY == fruitY)
    {
        do
        {
            fruitX = rand() % (WIDTH - 2) + 1;
        } while (fruitX == snakeX);
        do
        {
            fruitY = rand() % (HEIGHT - 2) + 1;
        } while (fruitY == snakeY);

        score += 10;
    }
}

int main()
{
    initialize();
    while (!gameOver)
    {
        drawBoundaries();
        getInput();
        engine();
    }

    printf("Game Over. Your Score: %d\n", score);

    return 0;
}
