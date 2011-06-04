void gra(void){
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();
/* an error occurred */
if (errorcode != grOk)
{
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
}
}

//*******************************************************************

void tablero(void){
	int aux=0;
	int x,y;
	x=156;
	y=20;
	/*lineas horizontales*/
	while(aux!=9){
		line(x,y,x+328,y);
		y=y+41;
		aux++;
	}
	/*lineas verticales*/
	aux=0;
	x=156;
	y=20;
	while(aux!=9){
		line(x,y,x,y+328);
		x=x+41;
		aux++;
	}
	/*numeros laterales*/
	gotoxy(19,3);
	printf("1");
	gotoxy(19,5);
	printf("2");
	gotoxy(19,8);
	printf("3");
	gotoxy(19,10);
	printf("4");
	gotoxy(19,13);
	printf("5");
	gotoxy(19,16);
	printf("6");
	gotoxy(19,18);
	printf("7");
	gotoxy(19,21);
	printf("8");
	/*numeros superiores*/
	gotoxy(24,1);
	printf("1");
	gotoxy(29,1);
	printf("2");
	gotoxy(34,1);
	printf("3");
	gotoxy(39,1);
	printf("4");
	gotoxy(44,1);
	printf("5");
	gotoxy(49,1);
	printf("6");
	gotoxy(54,1);
	printf("7");
	gotoxy(59,1);
	printf("8");
}
