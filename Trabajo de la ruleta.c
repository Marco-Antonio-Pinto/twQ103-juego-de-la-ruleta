#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_JUGADORES 100

int Continuar();
void Continuar2();
void MenuOpciones();
void Banner();
void MenuApuestas();

struct menu
{
	float dinero;
	int apuesta;
	float dineroApuesta;
};


struct usuario
{
	char nombre[31];
	struct menu apuestas;
};

struct fichero
{
	char nombre[31];
	float dinero;	
};

void main()
{
	FILE*RankingHistorico;
    int i,j,opcion1,opcion2,numeroUsu,numeroRand,contApuesta,apuestaG,numRanking,bandera,auxiliar,comp,menu,longiN;
    char auxiliarN[31];
    struct usuario jugadores[MAX_JUGADORES];
    struct fichero fichero[MAX_JUGADORES];
    srand(time(NULL));
    
    RankingHistorico=fopen("ranking.txt","r");
    fflush(stdout);
    if(RankingHistorico==NULL)
	{
		printf("Error al abrir el Ranking Historico\n");
		return -1;
	}
	i=0;
	numRanking=0;
	do
	{
		fscanf(RankingHistorico,"%s %g",fichero[i].nombre,&fichero[i].dinero);
		i++;
		numRanking++;
	}
	while(fscanf(RankingHistorico, "%s %g",fichero[i].nombre,&fichero[i].dinero)!=EOF);
	fclose(RankingHistorico);
	
	Banner();
    printf("Introduzca un numero de usuarios para jugar:");
	scanf("%d", &numeroUsu);
	for(i=0;i<numeroUsu;i++)
	{
		do
		{
			printf("\t");
		    printf("Apodo del usuario %d (30 caracteres como maximo):",i+1); 
		    scanf("%s", jugadores[i].nombre);
		    longiN=strlen(jugadores[i].nombre);
		}while(longiN>30);
		jugadores[i].apuestas.dinero=20.0f;
	}
	
	printf("\nCada jugador recibe 20 euros iniciales.\n");

    do 
    {
		MenuOpciones();
	    printf("Introduzca el numero de la opcion:");
	    scanf("%d", &opcion1);
	    
	    system("cls");
		
	
	    switch(opcion1)
	    {
		    case 1: do
			        {
				        MenuApuestas();
		            
					    for(i=0;i<numeroUsu;i++)
					    {
						    if(jugadores[i].apuestas.dinero<=0)
						    {
							    printf("\t%s, no te queda dinero para seguir jugando.\n",jugadores[i].nombre);
						    }
						    else
						    {
							    printf("\t%s, introduce el numero de la opcion a la que quieres apostar:",jugadores[i].nombre);
							    scanf("%d",&opcion2);
							
							    switch(opcion2)
							    {
								    case 1: jugadores[i].apuestas.apuesta=1;
										    contApuesta=1;
								        break;
								    case 2: jugadores[i].apuestas.apuesta=2;
								            contApuesta=2;
								        break;
								    case 3: jugadores[i].apuestas.apuesta=3;
								            contApuesta=3;
								        break;
								    case 4: jugadores[i].apuestas.apuesta=4;
								            contApuesta=4;
								        break;
								    default:
									    printf("\tOpcion de apuesta incorrecta, vuelva a introducir una opcion.\n");	
							    }
							    do 
							    {
								    printf("\tIntroduce una cantidad valida a apostar:");
							        scanf("%f",&jugadores[i].apuestas.dineroApuesta);
							    }
							    while(jugadores[i].apuestas.dineroApuesta>jugadores[i].apuestas.dinero);	
						    }
					    }
		            
					    numeroRand= rand() %37;
					
		                printf("\nEL NUMERO GANADOR ES EL %d!!!\n", numeroRand);
		            
		                if(numeroRand==22||numeroRand==18||numeroRand==29||numeroRand==7||numeroRand==28||numeroRand==12||numeroRand==35||numeroRand==3||numeroRand==26||numeroRand==0||numeroRand==32||numeroRand==15||numeroRand==19||numeroRand==4||numeroRand==21||numeroRand==2||numeroRand==25)
					    {
						    apuestaG=1;
					    }
					    if(numeroRand==1||numeroRand==20||numeroRand==14||numeroRand==31||numeroRand==9)
					    {
						    apuestaG=2;
					    }
					    if(numeroRand==27||numeroRand==13||numeroRand==36||numeroRand==11||numeroRand==30||numeroRand==8||numeroRand==23||numeroRand==10||numeroRand==5||numeroRand==24||numeroRand==16||numeroRand==33)
					    {
						    apuestaG=3;
					    }
		                if(numeroRand==17||numeroRand==34||numeroRand==6)
					    {
						    apuestaG=4;
					    }
					
					
		                for(i=0;i<numeroUsu;i++)
					    {
						
						    if(jugadores[i].apuestas.apuesta==apuestaG)
						    {
							    printf("\nENHORABUENA %s, HAS GANADO!!!\n",jugadores[i].nombre);
							    if(contApuesta==1)
							    {
								    jugadores[i].apuestas.dineroApuesta=jugadores[i].apuestas.dineroApuesta*3;
							        jugadores[i].apuestas.dinero=jugadores[i].apuestas.dinero+jugadores[i].apuestas.dineroApuesta;
							    }
							    else if(contApuesta==2)
							    {
								    jugadores[i].apuestas.dineroApuesta=jugadores[i].apuestas.dineroApuesta*7;
							        jugadores[i].apuestas.dinero=jugadores[i].apuestas.dinero+jugadores[i].apuestas.dineroApuesta;
							    }
							    else if(contApuesta==3)
							    {
								    jugadores[i].apuestas.dineroApuesta=jugadores[i].apuestas.dineroApuesta*4;
							        jugadores[i].apuestas.dinero=jugadores[i].apuestas.dinero+jugadores[i].apuestas.dineroApuesta;
							    }
							    else if(contApuesta==4)
							    {
								    jugadores[i].apuestas.dineroApuesta=jugadores[i].apuestas.dineroApuesta*9;
							        jugadores[i].apuestas.dinero=jugadores[i].apuestas.dinero+jugadores[i].apuestas.dineroApuesta;
						 	    }	
						    }
						    else
						    {
								jugadores[i].apuestas.dinero=jugadores[i].apuestas.dinero-jugadores[i].apuestas.dineroApuesta;
							}
					    }
						menu=Continuar();
						system("cls");
					}while(menu==1);	
			    break;
		    case 2: printf("DINERO DE CADA JUGADOR:\n");
		            for(i=0;i<numeroUsu;i++)
					{
						printf("\t");
						printf("%s te quedan %g euros.",jugadores[i].nombre,jugadores[i].apuestas.dinero);
						if(jugadores[i].apuestas.dinero<=0)
						printf(" (No podras seguir jugando)");
						printf("\n");
					}
					Continuar2();
	            break;
	        case 3: RankingHistorico=fopen("ranking.txt","w");
	                printf("RANKING HISTORICO DE LA APLICACION (POR CANTIDAD DE DINERO GANADA):\n");
	                printf("Aqui se muestran las MEJORES puntuaciones de todos los jugadores que han jugado anteriormente.\n");
	                printf("NOTA: Si eres un nuevo jugador tendras que esperar a que acabe la partida para entrar en el ranking.\n");
	                for(i=0;i<numRanking;i++)
					{
						printf("%s %g\n",fichero[i].nombre,fichero[i].dinero);
					}
					Continuar2();
	            break;
	        case 4: printf("HA SALIDO DEL PROGRAMA.");
	            break;
	        default:
	            printf("Opcion incorrecta, vuelva a introducir una opcion.\n");
	    }
	}while(opcion1 !=4);	
    
    
    for(i=0;i<numeroUsu;i++)
	{
		bandera=0;
		for(j=0;j<numRanking;j++)
		{
			comp=strcmp(jugadores[i].nombre,fichero[j].nombre);
			if(comp==0)
			{
				bandera=1;
				if(jugadores[i].apuestas.dinero>fichero[j].dinero)
				{
					fichero[j].dinero=jugadores[i].apuestas.dinero;
				}
			} 
		}
		if(bandera==0)
		{
			strcpy(fichero[numRanking].nombre, jugadores[i].nombre);
			fichero[numRanking].dinero=jugadores[i].apuestas.dinero;
			numRanking++;
	    }
		
	}
	
	for (i=1;i<=numRanking-1;i++) 
            for (j=0;j<=numRanking-2;j++)
                if (fichero[j].dinero>fichero[j+1].dinero) 
                {
                    auxiliar=fichero[j].dinero; 
                    strcpy(auxiliarN, fichero[j].nombre);
                    fichero[j].dinero=fichero[j+1].dinero; 
                    strcpy(fichero[j].nombre,fichero[j+1].nombre);
                    fichero[j+1].dinero=auxiliar;
                    strcpy(fichero[j+1].nombre,auxiliarN);
                }
    
    RankingHistorico=fopen("ranking.txt","w");
    for(i=0;i<numRanking;i++)
	{
		fprintf(RankingHistorico,"%s %g\n",fichero[i].nombre,fichero[i].dinero);
	}
	fclose(RankingHistorico);
}

int Continuar()
{
	int respuesta;
    do
	{
	printf("\nQuiere seguir apostando y no volver al menu?\n 0-NO 1-SI\n");
    scanf("%d",&respuesta);
    printf("\n");
    
    if(respuesta==1)
        return 1;
    if(respuesta==0)
        return 0;
    }while(respuesta!=0 && respuesta!=1);
}

void Continuar2()
{
	system("Pause");
	system("cls");
}

void MenuOpciones()
{
	printf("\n");
	printf("MENU DE OPCIONES:\n");
	printf("1.Hacer apuesta y jugar\n");
	printf("2.Gestionar dinero de las apuestas\n");
	printf("3.Ver ranking de jugadores\n");
	printf("4.Salir del programa\n");
	printf("\n");
}

void Banner()
{
	printf("BIENVENIDO A:\n");
	system("Pause");
	system("cls");
	printf("EL TOCON, EL DE LA SUERTE!!\n");
	printf("LA RULETA VIRTUAL\n\n");
}

void MenuApuestas()
{
	printf("\n");
	printf("     |7 |28|12|35|3 |26|  0  |32|15|19|4 |21|2 |\n");
	printf("    |29|                                     |25|\n");
	printf("   |18|                                       |17|\n");
	printf("  |22|                LA RULETA                |34|\n");
	printf("   |9 |                                       |6 |\n");
	printf("    |31|                                     |27|\n");
    printf("     |14|20|1 |33|16|24|5 |10|23|8 |30|11|36|13|\n");
	printf("\n");	
	printf("MENU DE APUESTAS:\n");
	printf("1.Gran Serie:22,18,29,7,28,12,35,3,26,0,32,15,19,4,21,2,25 (si ganas se multiplica lo apostado por el triple)\n");
	printf("2.Huerfanos a caballo:9,31,14,20,1 (si ganas se multiplica lo apostado por siete)\n");
	printf("3.Tres octavos:33,16,24,5,10,23,8,30,11,36,13,27 (si ganas se multiplica lo apostado por cuatro)\n");
	printf("4.Huerfanos a pleno:17,34,6 (si ganas se multiplica lo apostado por nueve)\n");
	system("Pause");
	printf("\nHAGAN SUS APUESTAS...\n");    
}
