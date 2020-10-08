//Feito por Bryan Dias e Hugo Esteves
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define baixo 80
#define cima 72
#define enter 13
#define esc 13

void gotoxy(int x,int y) {
	// x máximo = 120
	//y máximo = 30
	HANDLE hCon;
    COORD dwPos;

    dwPos.X = x-1;
    dwPos.Y = y-1;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void carregamento() {
	setlocale(LC_ALL, "C");
	int i, j;
   system ("cls");
   gotoxy(15,8);printf ("\n\nCarregando: \n\n");          
   for (i = 0; i <= 100; i++) {
      printf ("  %d%%\r", i);
      fflush (stdout);                      
      for (j = 0; j < i; j++) {
         if (!j)
           printf ("  ");
         printf ("%c", 219);
         Sleep(0.9999999999999995);
      }
   }
   printf ("\n\nAguarde...");
   Sleep (1000);
   gotoxy(15,17);printf ("APERTE QUALQUE TECLA PARA CONTINUAR\n\n\n");
   getch();
   fflush (stdin);
   fflush (stdout);
   setlocale(LC_ALL, "Portuguese");
}

void quadradoJogo() {
	setlocale(LC_ALL, "C");
	int pX, pY;
	for (pX=4, pY=4; pY<=27;pY++) {
		gotoxy(pX,pY); printf ("%c", 219);
	}
	for (pX=117, pY=4; pY<=27; pY++) {
		gotoxy(pX,pY); printf ("%c", 219);
	}
	for (pX=4, pY=4;pX<=117;pX++) {
		gotoxy(pX,pY); printf ("%c", 219);
	}
	for (pX=4, pY=27;pX<=117;pX++) {
		gotoxy(pX,pY); printf ("%c", 219);
	}
}

int pontosJogo(pontos) {
	return pontos;
}

void jogoRodando() {
	system("cls");
	int setaBaixo = 0, setaCima = 0, setaEsquerda = 0, setaDireita = 0, captaTecla, posX[400]={5,116}, posY[400]={5,26}, y, opcao = 1;
	int vPontos=100, vCobra=1, pontosCorridos=0, nivelJogador = 1, sorteiaX, sorteiaY, var, tamanhoJogador=1, reiniciar = 1;
	char tecla=0;
	quadradoJogo();
	captaTecla = 3;
	srand(time(NULL));
	sorteiaX=(rand()%111) +5;
	sorteiaY=(rand()%21) +5;
	vPontos = 100;
	while (tecla!=esc) {
		setlocale(LC_ALL, "C");
		while (tecla!=esc&&!(tecla=kbhit())) {
			fflush (stdin);
   			fflush (stdout);
			for (var=tamanhoJogador;var>0;var--) {
				posX[var]=posX[var-1];
				posY[var]=posY[var-1];
			}
			if (captaTecla==0) {
				posX[0]--;
			}
			if (captaTecla==1) {
				posY[0]--;
			}
			if (captaTecla==2) {
				posX[0]++;
			}
			if (captaTecla==3) {
				posY[0]++;
			}
			gotoxy (posX[tamanhoJogador],posY[tamanhoJogador]);
			printf (" ");
			if (sorteiaX==posX[0] && sorteiaY==posY[0]) { 
				tamanhoJogador++;
				pontosCorridos++;
				sorteiaX=(rand()%111) +5;
				sorteiaY=(rand()%21) +5;
				vPontos-=2;
				vCobra+=2;
			}
			gotoxy(posX[0],posY[0]);
			printf("%c",219);
			gotoxy(sorteiaX,sorteiaY);
			printf("%c",254);
			setlocale(LC_ALL, "Portuguese");
			gotoxy(1,1);
			printf ("Pontuação: %d", pontosJogo(pontosCorridos));
			setlocale(LC_ALL, "C");
			gotoxy(1,2);
			printf("Velocidade atual: %d",vCobra);
			Sleep(vPontos);
			for(var=1;var<tamanhoJogador;var++) {
				if(posX[0]==posX[var]&&posY[0]==posY[var]) {
					tecla=esc;
				}
			}
			if(posY[0]==4 || posY[0]==27 || posX[0]==4 || posX[0]==117) {
				tecla=esc;
			}
		}
		if(tecla!=esc) {
			tecla=getch();
		}
		if(tecla=='K' || tecla=='A' || tecla =='a') {
			captaTecla=0;
		}
		if(tecla=='H' || tecla=='w' || tecla=='W') {
			captaTecla=1;
		}
		if(tecla=='M' || tecla=='D' || tecla=='d') {
			captaTecla=2;
		}
		if(tecla=='P' || tecla=='S' || tecla=='s') {
			captaTecla=3;
		}
		if(posY[0]==4 || posY[0]==27 || posX[0]==4 || posX[0]==117) {
			tecla=esc;
		}
	}
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	system("pause");
	system("cls");
	printf("Você perdeu :(\n");
	printf("Você fez %d ponto(s) nessa rodada!\n\n\n", pontosJogo(pontosCorridos));
	system("pause");
	system("cls");
}

void menuPrincipal() {
	int sair = 1, y = 7, opcao = 1;
	setlocale(LC_ALL, "C");
	gotoxy(18,5); printf("Menu Principal");
    gotoxy(18,7); printf("->");
    while(sair){
    	setlocale(LC_ALL, "Portuguese");
    	gotoxy(18,5);  printf("Menu Principal");
        gotoxy(20,7);  printf("JOGAR");
        gotoxy(20,8);  printf("SAIR");
        gotoxy(20,13); printf("Esse é o clássico jogo da cobrinha, apenas se movimente pelo mapa para ficar grande\n                   e tente não ser eliminado.\n                   Você pode se mover com as setinhas ou com o WASD. Boa sorte!");
        setlocale(LC_ALL, "C");
        system("pause>nul");
		if(GetAsyncKeyState(VK_DOWN) && y != 8) {
            gotoxy(18,y); printf("  ");
            y++;
            gotoxy(18,y); printf("->");
            opcao++;
            _beep(400,200);
            continue;
        }
		if(GetAsyncKeyState(VK_UP) && y != 7){
            gotoxy(18,y); printf("  ");
            y--;
            gotoxy(18,y); printf("->");
            opcao--;
            _beep(400,200);
            continue;
        }
		if(GetAsyncKeyState(VK_RETURN)){
            if (opcao == 1) {
            	carregamento();
            	jogoRodando();
            	}
            if (opcao == 2) {
            	break;
            }
    	}
    }
    setlocale(LC_ALL, "C");
}

int main() {
	system("color F0");
	fflush (stdin);
   	fflush (stdout);
	menuPrincipal();
}
