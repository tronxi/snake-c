#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define M 10
void rellenaSnake (int [M][M]);
void imprimeSnakeC (int [M][M], int, char);
void limpiaSnake (int [M][M], int);
int snakePantalla(int snake[M][M]);
int comprobarAleatorio(int[M][M],int);
void aleatorio(int[M][M],int);
void imprimeSnakeN (int snake[M][M],int, char);
void color(int X);
void main()
{
    int snake[M][M];
    char posicion,ant,jugar;
    int i,j,tam,seguir,limpiar,puntuacion,velocidad;
    srand(time(NULL));

    do{
        i = 5;
        j = 5;
        tam = 2;
        seguir = 1;
        limpiar = 2; //
        puntuacion = 0;
        velocidad = 100;
        posicion = 'w';
        ant = 'w';
        rellenaSnake(snake);
        printf("pulsa cualquier tecla para jugar");
        do{

            posicion = getch();

            while ( !kbhit())
            {
                if (posicion == 'w' && ant!='s')
                {
                    ant = 'w';
                    i--;
                }

                else if (posicion == 's' && ant!='w')
                {
                    ant = 's';
                    i++;
                }
                else if (posicion == 'a' && ant!='d')
                {
                    ant = 'a';
                    j--;
                }
                else if (posicion == 'd' && ant!='a')
                {
                    ant = 'd';
                    j++;
                }
                else if(posicion == '0')
                {
                    seguir = 0;
                }
                else
                {
                    if(posicion = 'w' && ant == 's')
                        i++;
                    else if(posicion = 's' && ant == 'w')
                        i--;
                    else if(posicion = 'a' && ant == 'd')
                        j++;
                    else if(posicion = 'd' && ant == 'a')
                        j--;
                }
                if (i >= M || i < 0 || j >= M || j < 0)
                {
                    seguir = 0;
                    i = -2;
                    j = -2;
                }
                snake[i][j] = tam;
                Sleep(velocidad);
                system("cls");
                imprimeSnakeC(snake,tam,ant);
                tam++;
                if (tam > 6)
                {
                    limpiaSnake(snake,limpiar);
                    limpiar++;
                    if (tam - limpiar != snakePantalla(snake))
                        seguir = 0;
                    if (!comprobarAleatorio(snake,0))
                    {
                        aleatorio(snake,0);
                        limpiar--;
                        puntuacion++;
                        if (puntuacion % 5 == 0)
                        {
                            velocidad -= 20;
                        }
                    }
                }
                color(9);printf("\npuntuacion:%d\n",puntuacion);color(7);
                if (!seguir) break;
            }
        }while(posicion != '0' && seguir);
        do{
            printf("quieres volver a jugar(y/n):");
            fflush(stdin);
            scanf("%c",&jugar);
        } while (jugar !='n' && jugar !='y');
    }while (jugar == 'y');
}

void rellenaSnake (int snake[M][M])
{
    int i,j;
    for(i=0; i<M; i++)
    {
        for (j=0; j<M; j++)
            snake[i][j]=1;
    }
}

void imprimeSnakeC (int snake[M][M], int tam, char ant)
{
    int i,j;
    for (i=0; i<M; i++) printf("___"); printf("_");
    printf("\n");
    for (i=0; i<M; i++)
    {
        printf("|");
        for (j=0; j<M; j++)
        {
            if (snake[i][j]==1)
            {
                printf("   ");
            }
            else if (snake[i][j] == tam)
            {
                color(2);
                if (ant == 'w') printf (" v ");
                else if (ant == 's') printf(" ^ ");
                else if (ant == 'a') printf(" > ");
                else if (ant == 'd') printf(" < ");
                color(7);
            }
            else if (snake[i][j] == 0)
            {
                color(4);
                printf (" %c ",190);
                color(7);
            }
            else
            {
                color(2);
                printf(" %c ",254);
                color(7);
            }
        }
        printf("|\n");
    }
    for (i=0; i<M; i++) printf("___"); printf("_");
}

void limpiaSnake(int snake[M][M], int limpiar)
{
    int i,j;
    for (i=0; i<M; i++)
    {
        for (j=0; j<M; j++)
        {
            if (snake[i][j] == limpiar)
                snake[i][j] = 1;
        }
    }
}

int snakePantalla(int snake[M][M])
{
	int i, j, total = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (snake[i][j] >= 2)
				total++;
		}
	}
	return total;
}

int comprobarAleatorio(int snake[M][M],int ale)
{
	int i, j, encontrado = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (snake[i][j] == ale)
			{
				i = M;
				j = M;
				encontrado = 1;
			}
		}
	}
	return encontrado;

}

void aleatorio(int snake[M][M], int aleat)
{
	int i, j, k, valido;
	do
	{
		i = rand() % M + 1;
		j = rand() % M + 1;

		if (snake[i - 1][j - 1] == 1)
		{
			snake[i - 1][j - 1] = aleat;
			valido = 1;
		}
		else
			valido = 0;
	}
	while (!valido);
}

void imprimeSnakeN (int snake[M][M],int tam, char c)
{
    int i,j;
    for(i=0; i<M; i++)
    {
        for (j=0; j<M; j++)
            printf(" %d ",snake[i][j]);
        printf("\n");
    }
}

void color(int X) { SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); }

/* Gama de colores:
0 = Negro
1 = Azul
2 = Verde
3 = Aguamarina
4 = Rojo
5 = Purpura
6 = Amarillo
7 = Blanco
8 = Gris
9 = Azul claro
A = Verde claro
B = Aguamarina claro
C = Rojo claro
D = Purpura claro
E = Amarillo claro
F = Blanco brillante
*/
