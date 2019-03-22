# Título del trabajo

Programar una ruleta de treinta y siete numeros. El programa indica cual es el numero ganador. El programa permitirá a los usuarios elegir el tipo de apuesta que quieren realizar y la cantidad que quieren apostar. Ademas permitirá  los usuarios ver que cantidad han ganado y han perdido durante el tiempo que llevan jugando. 

## Integrantes del equipo

1. David Ledesma González. Usuario: dledesma11.
2. Héctor Domínguez Mora. Usuario: heeeectorito. 
3. Fernando Casillas Juan. Usuario: FernandoCasillas. 

## Objetivos del trabajo

1. Realizar un programa de juego de ruleta que se asemeje a las ruletas reales. 
2. Permitir al usuario varias opciones para jugar, como el tipo de apuesta, cuanto pueden apostar o ver el dinero que les queda. 

## Menu juego de la ruleta
//Ruleta


#include <stdio.h>
int main ()
{
int option;
	
	printf("BIENVENIDO AL JUEGO DE LA RULETA.");
	printf("OPCIONES DEL MENU DE LA APLICACION:\n");
	printf("\n");
	
	do 
	{
		printf("\n");
		printf("1.Hacer apuesta y jugar\n");
		printf("2.Gestionar dinero de las apuestas\n");
		printf("3.Ver ranking de jugadores\n");
		printf("4.Salir del programa\n");
		printf("\n");
		printf("Introduzca una opcion:");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1: printf("Ha entrado en el juego de la ruleta:");
			        printf("Introduzca un nuevo usuario:");
			    break;
			case 2: printf("Ha introducido la opcion de gestionar el dinero de las apuestas");
		        break;
		    case 3: printf("Ha introducido la opcion de ver ranking de jugadores.");
		        break;
		    case 4: printf("Ha introducido la opcion de salir del programa.");
		        break;
		    default:
		        printf("Opcion incorrecta.");
		}
	}
	while(opcion !=4);	
	}
