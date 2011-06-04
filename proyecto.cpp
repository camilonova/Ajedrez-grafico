#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "tablero.h"

void llenar_tablero(void);       					 	//Funcion del primer requisito
int validar_casilla(int, int);         				//Funcion del segundo requisito
bool validar_movimiento(int, int, int, int);       //Funcion del tercer requisito
void mover_pieza(int, int, int, int); 					//Funcion del cuarto requisito
int turno(void);		 										//Funcion del quinto requisito
void pintar_tablero(void);									//Funcion del sexto requisito
void imprimir_comidas(void);			  					//Funcion del septimo requisito

char *fichas_comidas[2][16] = {{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},  //Negras
 									    {"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}}; //Blancas
char *elemento_tablero[8][8] = {{"-4","-2","-3","-5","-6","-3","-2","-4"},
	/*Tablero de juego*/	  	     {"-1","-1","-1","-1","-1","-1","-1","-1"},
      				              { "0", "0", "0", "0", "0", "0", "0", "0"},
         	      			     { "0", "0", "0", "0", "0", "0", "0", "0"},
			            	        { "0", "0", "0", "0", "0", "0", "0", "0"},
         			      	     { "0", "0", "0", "0", "0", "0", "0", "0"},
                  				  { "1", "1", "1", "1", "1", "1", "1", "1"},
                 				     { "4", "2", "3", "5", "6", "3", "2", "4"}};

int posicion_tablero[64][2] = {{160, 36},{201, 36},{242, 36},{283, 36},{324, 36},{365, 36},{406, 36},{447, 36},
    /*Posiciones del tablero*/ {160, 77},{201, 77},{242, 77},{283, 77},{324, 77},{365, 77},{406, 77},{447, 77},
                               {160,118},{201,118},{242,118},{283,118},{324,118},{365,118},{406,118},{447,118},
                               {160,159},{201,159},{242,159},{283,159},{324,159},{365,159},{406,159},{447,159},
                               {160,200},{201,200},{242,200},{283,200},{324,200},{365,200},{406,200},{447,200},
                               {160,241},{201,241},{242,241},{283,241},{324,241},{365,241},{406,241},{447,241},
                               {160,282},{201,282},{242,282},{283,282},{324,282},{365,282},{406,282},{447,282},
                               {160,323},{201,323},{242,323},{283,323},{324,323},{365,323},{406,323},{447,323}};

int Rturno = 1;
int i_negras = 0;
int i_blancas = 0;


void main(){
	char eleccion, movi_x, movi_y;
   int x_i, y_i, x_f, y_f;
	bool flag = true;
   bool jugar = true;
   char *temp[8][8] = {{"-4","-2","-3","-5","-6","-3","-2","-4"},
  				 	  	     {"-1","-1","-1","-1","-1","-1","-1","-1"},
      		           { "0", "0", "0", "0", "0", "0", "0", "0"},
         	  		     { "0", "0", "0", "0", "0", "0", "0", "0"},
			        	     { "0", "0", "0", "0", "0", "0", "0", "0"},
         	      	  { "0", "0", "0", "0", "0", "0", "0", "0"},
              			  { "1", "1", "1", "1", "1", "1", "1", "1"},
             			  { "4", "2", "3", "5", "6", "3", "2", "4"}};

   pintar_tablero();
   llenar_tablero();
	do{
		gotoxy(12,25);
		printf("Presione el numero de su eleccion:\n");
		printf("\t1. Realizar Jugada.\n");
		printf("\t2. Imprimir lista de fichas comidas.\n");
		printf("\t3. Reiniciar tablero.\n");
		printf("\t4. Salir.\n");
		eleccion = getch();
		switch(eleccion){
			case '1':
   	      	jugar = true;
	            setfillstyle(0,0);
            	bar(0,350,getmaxx(),getmaxy());
         		gotoxy(9,25);
      	      printf("Casilla de la Pieza a mover:");

					do{
	            	movi_x=getch();
            	}while(movi_x!='1' && movi_x!='2' && movi_x!='3' && movi_x!='4' &&  movi_x!='5'&& movi_x!='6' &&  movi_x!='7' && movi_x!='8');

      	      printf("%c,",movi_x);

   	         do{
	            	movi_y=getch();
	  				}while(movi_y!='1' && movi_y!='2' && movi_y!='3' && movi_y!='4' &&  movi_y!='5'&& movi_y!='6' &&  movi_y!='7' && movi_y!='8');

      	      printf("%c\n",movi_y);

   	         x_i = movi_x - 48;
	            y_i = movi_y - 48;

            	gotoxy(20,28);
         	   printf("\tCasilla a mover la Pieza:");
      	      do{
   	         	movi_x=getch();
	            }while(movi_x!='1' && movi_x!='2' && movi_x!='3' && movi_x!='4' &&  movi_x!='5'&& movi_x!='6' &&  movi_x!='7' && movi_x!='8');
	            printf("%c,",movi_x);

      	      do{
   	         	movi_y=getch();
	            }while(movi_y!='1' && movi_y!='2' && movi_y!='3' && movi_y!='4' &&  movi_y!='5'&& movi_y!='6' &&  movi_y!='7' && movi_y!='8');

   	         printf("%c\n",movi_y);

					x_f=movi_x-48;
         	   y_f=movi_y-48;

			 	 	if(turno() == 1){ 				//Juegan las blancas
                  if(validar_movimiento(x_i, y_i, x_f, y_f)){
                     mover_pieza(x_i, y_i, x_f, y_f);
                     Rturno = -1;
                 		printf("\tAhora, Juegan las Negras\n");
                     getch();
                     setfillstyle(0,0);
			           	bar(0,350,getmaxx(),getmaxy());
                     break;
     		         }
  	               else{
                  	printf("\tNo se puede hacer el movimiento.\n");
                     Rturno = 1;
                     printf("\tContinuan Jugando las Blancas\n");
                     getch();
                     setfillstyle(0,0);
      		   	  	bar(0,350,getmaxx(),getmaxy());
                     break;
                  }
               }
           	   if(turno() == -1){           //Juegan las negras
                  if(validar_movimiento(x_i,y_i,x_f,y_f)){
                  	mover_pieza(x_i, y_i, x_f, y_f);
                     Rturno = 1;
                     printf("\tAhora, Juegan las Blancas\n");
                     getch();
                     setfillstyle(0,0);
			           	bar(0,350,getmaxx(),getmaxy());
                     break;
                  }
                  else{
                  	printf("\tNo se puede hacer el movimiento.\n");
                     Rturno = -1;
                     printf("\tContinuan Jugando las Negras\n");
                     getch();
                     setfillstyle(0,0);
			           	bar(0,350,getmaxx(),getmaxy());
                     break;
                  }
     	         }

 			   break;
			case '2':
         	imprimir_comidas();
			   break;
			case '3':
         	for(x_i=0; x_i<16; x_i++){
            	fichas_comidas[0][x_i] = "0";
               fichas_comidas[1][x_i] = "0";
            }
            for(x_i=0; x_i<8; x_i++){
            	for(x_f=0; x_f<8; x_f++){
               	elemento_tablero[x_i][x_f] = temp[x_i][x_f];
               }
            }
            Rturno = 1;
            i_negras = 0;
            i_blancas = 0;

				pintar_tablero();
         	llenar_tablero();
			   break;
			case '4':
			   gotoxy(12,25);
            setfillstyle(0,0);
            bar(0,0,800,600);
			   printf("Gracias por jugar...\n\t\tPresione una tecla para continuar.");
				flag = false;
			   getch();
            break;
         default:
         	printf("Esa no es una opcion valida, escoja una opcion valida");
            break;
		}
	} while(flag);
   closegraph();
}

/*--------------------------------------------------------------------------------------------*/

void llenar_tablero(void){
    int k = 0;
    settextstyle(0,0,2);
    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
      	if(strcmp(elemento_tablero[i][j], "0") != 0){
         	outtextxy(posicion_tablero[k][0],posicion_tablero[k][1],elemento_tablero[i][j]);
         }
         k++;
      }
    }
}

/*---------------------------------------------------------------------------------------------*/

int validar_casilla(int x, int y){

	if(strcmp(elemento_tablero[x][y], "-1") == 0){
      return -1;
   }
   if(strcmp(elemento_tablero[x][y], "-2") == 0){
      return -1;
   }
   if(strcmp(elemento_tablero[x][y], "-3") == 0){
      return -1;
   }
   if(strcmp(elemento_tablero[x][y], "-4") == 0){
      return -1;
   }
   if(strcmp(elemento_tablero[x][y], "-5") == 0){
      return -1;
   }
   if(strcmp(elemento_tablero[x][y], "-6") == 0){
      return -1;
   }
   if(strcmp(elemento_tablero[x][y], "0") == 0){
      return 0;
   }
	if(strcmp(elemento_tablero[x][y], "1") == 0){
      return 1;
   }
   if(strcmp(elemento_tablero[x][y], "2") == 0){
      return 1;
   }
   if(strcmp(elemento_tablero[x][y], "3") == 0){
      return 1;
   }
   if(strcmp(elemento_tablero[x][y], "4") == 0){
      return 1;
   }
   if(strcmp(elemento_tablero[x][y], "5") == 0){
      return 1;
   }
   if(strcmp(elemento_tablero[x][y], "6") == 0){
      return 1;
   }
}

/*----------------------------------------------------------------------------------------------*/

bool validar_movimiento(int x_i, int y_i, int x_f, int y_f){
   int xi, yi, xf, yf;

   xi = (x_i - 1);
   yi = (y_i - 1);
   xf = (x_f - 1);
   yf = (y_f - 1);

   if(Rturno == 1 && validar_casilla(xi, yi) == 1){       //Si la figura que quiere mover es blanca
		if(validar_casilla(xf, yf) == 0 || validar_casilla(xf, yf) == -1){		//O no hay nada o hay una del otro color
            switch(atoi(elemento_tablero[xi][yi])){
			     	case 6:
			        	//Rey Blanco: solo puede avanzar una posicion en todas las direcciones
         			if(xi == xf+1 && yi == yf){
			         	//up
                     return true;
			         }
			         if(xi == xf+1 && yi+1 == yf){
			         	//up-der
                     return true;
			         }
			         if(xi == xf && yi == yf+1){
		         		//der
                     return true;
			         }
			         if(xi == xf+1 && yi == yf+1){
			         	//down-der
                     return true;
			         }
			         if(xi+1 == xf && yi == yf){
			         	//down
                     return true;
			         }
			         if(xi+1 == xf && yi-1 == yf){
			         	//down-izq
                     return true;
			         }
			         if(xi == xf && yi-1 ==yf){
			         	//izq
                     return true;
			         }
			         if(xi-1 == xf && yi-1 == yf){
			         	//up-izq
                     return true;
			         }
			         else{				//Movimiento no valido
                     return false;
                  }
			      case 5:
			        	//Reina Blanca: puede avanzar geometricamente en todos los sentidos varias posiciones
                  if(xi > xf && yi == yf){
                  	//up
                     return true;
                  }
                  if(xi == xf && yi < yf){
                  	//der
                     return true;
                  }
                  if(xi < xf && yi == yf){
                  	//down
                     return true;
                  }
                  if(xi == xf && yi > yf){
                  	//izq
                     return true;
                  }
                  if((xf-xi)/(yf-yi) == 1 || (xf-xi)/(yf-yi) == -1){
                  	//Diagonales
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case 4:
       				//Torre Blanca: solo puede avanzar horizontal y vertical varias posiciones
                  if(xi > xf && yi == yf){
                  	//up
                     return true;
                  }
                  if(xi == xf && yi < yf){
                  	//der
                     return true;
                  }
                  if(xi < xf && yi == yf){
                  	//down
                     return true;
                  }
                  if(xi == xf && yi > yf){
                  	//izq
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case 3:
        				//Arfil Blanco: solo puede avanzar diagonalmente varias posiciones
                  if((xf-xi)/(yf-yi) == 1 || (xf-xi)/(yf-yi) == -1){
                  	//Diagonales
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case 2:
       				//Caballo Blanco: solo puede avanzar en L tres posiciones
                  if(xi-2 == xf && yi-1 == yf){
                  	//up-izq
                     return true;
                  }
                  if(xi-2 == xf && yi+1 == yf){
                  	//up-der
                     return true;
                  }
                  if(xi-1 == xf && yi+2 == yf){
                  	//der-up
                     return true;
                  }
                  if(xi+1 == xf && yi+2 == yf){
                  	//der-down
                     return true;
                  }
                  if(xi+2 == xf && yi+1 == yf){
                  	//down-der
                     return true;
                  }
                  if(xi+2 == xf && yi-1 == yf){
                  	//down-izq
                     return true;
                  }
                  if(xi+1 == xf && yi-2 == yf){
                  	//izq-down
                     return true;
                  }
                  if(xi-1 == xf && yi-2 == yf){
                  	//izq-up
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case 1:
        				//Peon Blanco: solo puede avazar hacia delante una posicion, (Movimiento especial)
                  if(xi-1 == xf && yi == yf){
                  	//up
                     return true;
                  }
                  if(xi-1 == xf && yi+1 == yf && validar_casilla(xf,yf) == -1){
                  	//up-der-blanca
                     return true;
                  }
                  if(xi-1 == xf && yi-1 == yf && validar_casilla(xf,yf) == -1){
                  	//up-izq-blanca
                     return true;
                  }
                  if(xi == 6 && xf == 4 && yi == yf){
                  	//Movimiento especial up
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
	        }
      }
      else{
       	return false;
      }
   }

   if(Rturno == -1 && validar_casilla(xi, yi) == -1){       //Si la figura que quiere mover es negra
		if(validar_casilla(xf, yf) == 0 || validar_casilla(xf, yf) == 1){		//O no hay nada o hay una del otro color
            switch(atoi(elemento_tablero[xi][yi])){
			     	case -6:
			        	//Rey Negro: solo puede avanzar una posicion en todas las direcciones
         			if(xi == xf+1 && yi == yf){
			         	//up
                     return true;
			         }
			         if(xi == xf+1 && yi+1 == yf){
			         	//up-der
                     return true;
			         }
			         if(xi == xf && yi == yf+1){
		         		//der
                     return true;
			         }
			         if(xi == xf+1 && yi == yf+1){
			         	//down-der
                     return true;
			         }
			         if(xi+1 == xf && yi == yf){
			         	//down
                     return true;
			         }
			         if(xi+1 == xf && yi-1 == yf){
			         	//down-izq
                     return true;
			         }
			         if(xi == xf && yi-1 ==yf){
			         	//izq
                     return true;
			         }
			         if(xi-1 == xf && yi-1 == yf){
			         	//up-izq
                     return true;
			         }
			         else{				//Movimiento no valido
                     return false;
                  }
			      case -5:
			        	//Reina Negra: puede avanzar geometricamente en todos los sentidos varias posiciones
                  if(xi > xf && yi == yf){
                  	//up
                     return true;
                  }
                  if(xi == xf && yi < yf){
                  	//der
                     return true;
                  }
                  if(xi < xf && yi == yf){
                  	//down
                     return true;
                  }
                  if(xi == xf && yi > yf){
                  	//izq
                     return true;
                  }
                  if((xf-xi)/(yf-yi) == 1 || (xf-xi)/(yf-yi) == -1){
                  	//Diagonales
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case -4:
       				//Torre Negra: solo puede avanzar horizontal y vertical varias posiciones
                  if(xi > xf && yi == yf){
                  	//up
                     return true;
                  }
                  if(xi == xf && yi < yf){
                  	//der
                     return true;
                  }
                  if(xi < xf && yi == yf){
                  	//down
                     return true;
                  }
                  if(xi == xf && yi > yf){
                  	//izq
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case -3:
        				//Arfil Negro: solo puede avanzar diagonalmente varias posiciones
                  if((xf-xi)/(yf-yi) == 1 || (xf-xi)/(yf-yi) == -1){
                  	//Diagonales
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }

			      case -2:
       				//Caballo Negro: solo puede avanzar en L tres posiciones
                  if(xi-2 == xf && yi-1 == yf){
                  	//up-izq
                     return true;
                  }
                  if(xi-2 == xf && yi+1 == yf){
                  	//up-der
                     return true;
                  }
                  if(xi-1 == xf && yi+2 == yf){
                  	//der-up
                     return true;
                  }
                  if(xi+1 == xf && yi+2 == yf){
                  	//der-down
                     return true;
                  }
                  if(xi+2 == xf && yi+1 == yf){
                  	//down-der
                     return true;
                  }
                  if(xi+2 == xf && yi-1 == yf){
                  	//down-izq
                     return true;
                  }
                  if(xi+1 == xf && yi-2 == yf){
                  	//izq-down
                     return true;
                  }
                  if(xi-1 == xf && yi-2 == yf){
                  	//izq-up
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
			      case -1:
        				//Peon Negro: solo puede avazar hacia delante una posicion, (Movimiento especial)
                  if(xi+1 == xf && yi == yf){
                  	//down
                     return true;
                  }
                  if(xi+1 == xf && yi+1 == yf && validar_casilla(xf,yf) == 1){
                  	//down-der-blanca
                     return true;
                  }
                  if(xi+1 == xf && yi-1 == yf && validar_casilla(xf,yf) == 1){
                  	//down-izq-blanca
                     return true;
                  }
                  if(xi == 1 && xf == 3 && yi == yf){
                  	//Movimiento especial down
                     return true;
                  }
                  else{				//Movimiento no valido
                  	return false;
                  }
	        }
      }
      else{
       	return false;
      }
   }

   else{
     	return false;
   }
}

/*------------------------------------------------------------------------------------------------------*/

void mover_pieza(int x_i, int y_i, int x_f, int y_f){
   int xi, yi, xf, yf;

   xi = (x_i - 1);
   yi = (y_i - 1);
   xf = (x_f - 1);
   yf = (y_f - 1);

   if(Rturno == -1 && strcmp(elemento_tablero[xf][yf], "0") != 0){
   	fichas_comidas[0][i_negras] = elemento_tablero[xf][yf];
      i_negras++;
   }
   if(Rturno == 1 && strcmp(elemento_tablero[xf][yf], "0") != 0){
   	fichas_comidas[1][i_blancas] = elemento_tablero[xf][yf];
      i_blancas++;
   }

	if(strcmp(elemento_tablero[xi][yi], "-1") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "-1";
   	printf("\tSe ha jugado: Peon Negro\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "-2") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "-2";
   	printf("\tSe ha jugado: Caballo Negro\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "-3") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "-3";
   	printf("\tSe ha jugado: Arfil Negro\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "-4") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "-4";
   	printf("\tSe ha jugado: Torre Negra\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "-5") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "-5";
   	printf("\tSe ha jugado: Reina Negra\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "-6") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "-6";
   	printf("\tSe ha jugado: Rey Negro\n");
   }
	if(strcmp(elemento_tablero[xi][yi], "1") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "1";
   	printf("\tSe ha jugado: Peon Blanco\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "2") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "2";
   	printf("\tSe ha jugado: Caballo Blanco\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "3") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "3";
   	printf("\tSe ha jugado: Arfil Blanco\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "4") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "4";
   	printf("\tSe ha jugado: Torre Blanca\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "5") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "5";
   	printf("\tSe ha jugado: Reina Blanca\n");
   }
   if(strcmp(elemento_tablero[xi][yi], "6") == 0){
	   elemento_tablero[xi][yi] = "0";
	   elemento_tablero[xf][yf] = "6";
   	printf("\tSe ha jugado: Rey Blanco\n");
   }
   getch();

   pintar_tablero();
   llenar_tablero();
   gotoxy(9,25);
}

/*------------------------------------------------------------------------------------------------------*/

int turno(void){             /* 1 las Blancas juegan, -1 juegan las Negras*/
   return Rturno;
}

/*------------------------------------------------------------------------------------------------------*/

void pintar_tablero(){
   int aux;
   int x,y;
	gra();						//Funcion para cargar los graficos desde la libreria
	tablero();              //Funcion para pintar el tablero desde la libreria

   /*Diagonal 1*/
	x=157;
	y=308;
	for(aux=0;aux<1;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
	}
	/*Diagonal 3*/
	x=157;
	y=226;
	for(aux=0;aux<3;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
	}
	/*Diagonal 5*/
	x=157;
	y=144;
	for(aux=0;aux<5;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
   }
	/*Diagonal 7*/
	x=157;
	y=62;
	for(aux=0;aux<7;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
	}
	/*Diagonal 9*/
	x=198;
	y=21;
	for(aux=0;aux<7;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
   }
	/*Diagonal 11*/
	x=280;
	y=21;
	for(aux=0;aux<5;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
	}
	/*Diagonal 13*/
	x=362;
	y=21;
	for(aux=0;aux<3;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
	}
	/*Diagonal 15*/
	x=444;
	y=21;
	for(aux=0;aux<1;aux++){
		setfillstyle(6,7);
		bar(x,y,x+39,y+39);
		x=x+41;
		y=y+41;
	}
}
/*------------------------------------------------------------------------------------------------*/
void imprimir_comidas(void){
   setfillstyle(0,0);
  	bar(0,350,getmaxx(),getmaxy());
	gotoxy(9,25);

  	printf("Jugador en turno: ");

	if(turno() == 1){
     	printf("Juegan las Blancas\n");
   }
	if(turno() == -1){
     	printf("Juegan las Negras\n");
   }

   printf("\tListado De Fichas Comidas:\n");
   printf("\tJugador Blanco: ");
   for(int i=0; i<16; i++){
     	if(strcmp(fichas_comidas[1][i], "0") != 0){
       	printf(fichas_comidas[1][i]);
         printf(", ");
      }
   }
	printf("\n\tJugador Negro: ");
   for(int i=0; i<16; i++){
     	if(strcmp(fichas_comidas[0][i], "0") != 0){
       	printf(fichas_comidas[0][i]);
         printf(", ");
      }
   }

   getch();
   setfillstyle(0,0);
  	bar(0,350,getmaxx(),getmaxy());
	gotoxy(9,25);
}

