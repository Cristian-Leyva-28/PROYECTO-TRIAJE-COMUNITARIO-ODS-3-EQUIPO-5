#include <stdio.h>
#include "funciones.h"

/* EQUIPO NUMERO 5 DEL 1-K FORMADO POR:

	1. RAMIREZ LEYVA CRISTIAN
	2. MIGUEL ANGEL GIRON GARCIA
	3. KIMBERLY RAMIREZ MENDEZ
	4. YUSBELIN LOPEZ VIATORO
	5. AYARI LIZBETH VILLARREAL RAMIREZ

*/
// TRIAJE COMUNITARIO: PRIORIZACION Y TIEMPOS OBJETIVO (ODS 3: SALUD Y BIENESTAR)

//
//=================================================== INICIO DE LA FUNCION INT MAIN ==============================================================================
int main()
{ // INICIO DEL MAIN

	// VARIABLES DE LA FUNCION MAIN :

	int opcion; // VARIABLE USADA PARA OPCION DE MENU

	do // DO WHILE PARA REPETIR MENU
	{  // INICIO DEL CICLO DO WHILE PARA MENU

		printf("=========================================================================== MENU PRINCIPAL ============================================================================");

		umbralEmergencia(); // LLAMAR LA FUNCION DE UMBRAL DE EMERGENCIA

		printf("\n\n\n\t\t\t\t\t\t  === ADMINISTRADOR DE CASOS COMUNITARIOS ODS 3 SALUD Y BIENESTAR ===");								 // NOMBRE DEL PROGRAMA
		printf("\n\n\n\t\t\t\t\t\t   <<< BIENVENIDO AL ADMINISTRADOR DE CASOS COMUNITARIOS ODS 3 >>>");									 // BIENVENIDA PARA EL USUARIO
		printf("\n\t\t\t\t <<<< A CONTINUACION SE TE MOSTRARAN LAS OPCIONES DISPONIBLES, ESCRIBE EL NUMERO DE OPCION QUE DESEAS >>>\n"); // MOSTRA OPCIONES

		printf("\n\n\t\t\t\t\t\t\t [1] REGISTRAR NUEVO CASO COMUNITARIO ");					  // OPCION 1
		printf("\n\n\t\t\t\t\t\t\t [2] MOSTRAR TABLA DE LOS CASOS COMUNITARIOS Y SUS HORAS"); // OPCION 2
		printf("\n\n\t\t\t\t\t\t\t [3] MOSTRAR ESTADISTICAS DE CASOS COMUNITARIOS");		  // OPCION 3
		printf("\n\n\t\t\t\t\t\t\t [4] RECOMENDACIONES");									  // OPCION 4
		printf("\n\n\t\t\t\t\t\t\t [5] RESETAR CASOS COMUNITARIOS");						  // OPCION 5
		printf("\n\n\t\t\t\t\t\t\t [6] BORRAR CASO COMUNITARIO");							  // OPCION 6
		printf("\n\n\t\t\t\t\t\t\t [7] SALIR DEL PROGRAMA");								  // OPCION 7

		printf("\n\n\n\t\t\t\t\t\t <<< POR FAVOR ESCRIBA EL NUMERO DE OPCION QUE DESEAS >>>:  "); // ESCRIBIR RESPUESTA
		resultado = scanf("%d", &opcion);

		if (resultado != 1) // Si el usuario no escribió un número
		{
			printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
			limpiarBuffer(); // Limpiamos el buffer del teclado
			continue;		 // Regresamos al inicio del ciclo
		}
		// ENVIAR RESPUESTA A LA VARIABLE OPCION

		switch (opcion) // SWITCH PARA POSIBLES RESPUESTAS
		{
		case 1:
			agregarCaso(); // LLAMAR FUNCION PARA AGREGAR CASO
			break;
		case 2:
			mostrarTabla(); // LLAMAR FUNCION PARA MOSTRAR TABLA DE CASOS X HORA
			break;
		case 3:
			mostrarEstadisticas(); // LLAMAR FUNCION PARA MOSTRAR ESTADISTICAS
			break;
		case 4:
			recomendaciones(); // LLAMAR FUNCION PARA MOSTRAR RECOMENDACIONES
			break;
		case 5:
			resetearDatos(); // LLAMAR FUNCION PARA RESETEAR DATOS
			break;
		case 6:
			borrarCaso(); // LLAMAR FUNCION PARA BORRAR DATOS
			break;
		case 7:
			printf("\n\n\t\t\t\t\t\t\t ------- GRACIAS POR USAR EL PROGRAMA :) ------- \n\n\n "); // SI EL USUARIO SE SALE DEL PROGRAMA
			break;
		default:
			printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, INTENTA DE NUEVO -------\n\n\n\n\n"); // SI EL USUARIO PONE UN NUMERO QUE NO ES VALIDO
		}

	} while (opcion != 7); // FIN DEL CICLO DO WHILE PARA MENU. SOLO SALDRA DEL CICLO Y SELECCIONAS EL NUMERO 5

	//=================================================== FIN DE LA FUNCION INT MAIN ==============================================================================

	return 0;
}
