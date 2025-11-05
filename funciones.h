#include <stdio.h>
#include <stdlib.h>


// VARIABLES GLOBALES
int casos[4][24] = {0};
int tipo = 0;
int hora = 0;
int emergenciasUmbral = 0;
int cantidadReportes = 0;
int resultado;
int indice1 = 0;
int indice2 = 0;

//=================================================== INICIO DE LA FUNCION UMBRAL DE EMERGENCIA ==================================================================
// FUNCION 1 universal limpiarBuffer
void limpiarBuffer()
{
	fflush(stdin); // LIMPIAR EL BUFFER
}

// FUNCION 2
void umbralEmergencia() // UTILIZADO PARA MOSTRAR EN PANTALLA LA CANTIDAD DE REPORTES DE EMERGENCIA Y EMITIR ALERTA SI SUPERA LOS 10 CASOS
{						// INCIO DE LA FUNCION UMBRAL

	if (emergenciasUmbral <= 9)
	{ // INICIO DE IF 1, SOLO SE EJECUTA SI LOS CASOS DE EMERGENCIA SON MENORES O IGUALES A 9

		printf("\n\n\n\t\t\t\t <<< TOTAL DE CASOS DE EMERGENCIAS %d >>> \n", emergenciasUmbral);

	} // FIN DE IF 1

	else
	{ // INICO DE ELSE 1, SE EJECUTA SI SE SUPERAN LOS 9 CASOS, ES PARA EMITIR ALERTAS

		printf("\n\n\n\t\t\t\t <<< UMBRAL DE EMERGENCIA SUPERADA (MAS DE 10 CASOS) REVISAR ZONA >>>\n");

	} // FIN DE ELSE 1

	tipo = 0; // IGUALAMOS A 0 A LA VARIABLE "TIPO" PARA EVITAR ERRORES CON LOS CICLOS

} // FIN DE LA FUNCION UMBRAL

//=================================================== FIN DE LA FUNCION UMBRAL DE EMERGENCIA =====================================================================

//=================================================== INICIO DE LA FUNCION AGREGAR CASOS =====================================================================

// FUNCION 3
void agregarCaso() // FUNCION PARA AGREGAR CASOS
{				   // INICIO DE LA FUNCION AGREGAR CASO

	do // DO WHILE 1 USADO PARA REPETIR PREGUNTA DE PRIORIDAD SI EL USUSARIO PONE UNA PRIORIDAD INVALIDA
	{  // INICIO DEL DO WHILE 1

		printf("\n\n======================================================================== AGREGAR CASO COMUNITARIO ======================================================================");

		umbralEmergencia(); // LLAMAR FUNCION PARA MOSTRAR UMBRAL

		printf("\n\n\t\t\t\t\t ===<<< POR FAVOR ELIGE EL NUMERO CORRESPONDIENTE AL TIPO DE PRIORIDAD DEL CASO >>>==="); // MOSTRAR OPCIONES
		printf("\n\n\t\t\t\t\t\t\t [1] EMERGENCIA [2] URGENCIA [3] NO URGENTE [4] CONTROL");							// OPCIONES DE PRIORIDAD
		printf("\n\n\n\t\t\t\t\t\t ===<<< EL TIPO DE PRIORIDAD ELEGIDA FUE LA NUMERO >>>===:  ");
		resultado = scanf("%d", &tipo);

		if (resultado != 1) // Si el usuario no escribe un numero
		{
			printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
			limpiarBuffer(); // Limpiamos el buffer del teclado
			continue;		 // Regresamos al inicio del ciclo
		}

		if (tipo < 1 || tipo > 4)
		{ // INICIO DEL IF 1 SE EJECUTA SI EL USUARIO ELIGE UNA PRIORIDAD INVALIDA

			printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION INCORRECTA, INTENTA DE NUEVO >>>==="); // RESPUESTA SI EL USUARIO PUSO UNA PRIORIDAD INVALIDA

		} // FINAL DEL IF 1

		else
		{ // INICIO DEL ELSE 1 SI EL USUARIO PUSO UNA PRIORIDAD VALIDA

			printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION GUARDADA CORRECTAMENTE >>>=== \n\n "); // RESPUESTA SI EL USUARIO USO UNA PRIORIDAD VALIDA

			// PREGUNTAR CUANTOS REPORTES DESEA HACER

			do
			{ // INICIO DEL CICLO DO WHILE 2 USADO SI EL USUARIO PIDE MAS DE 5 REPORTES
				
			 do // INICIO DE DO WHILE ESPECIAL PARA EVITAR BUGS
			 {
			 	
				printf("\n\n ===<<< ESCRIBE LA CANTIDAD DE CASOS QUE DESEAS REPORTAR DE ESTA PRIORIDAD (SOLO PUEDES REPORTAR 5 CASOS, SI DESEAS INGRESAR MAS CASOS TENDRAS QUE REPETIR TODO) >>>===");
				printf("\n\n\t\t\t\t\t\t\t ===<<< LA CANTIDAD DE REPORTES ELEGIDA FUE DE >>>===:  ");
				resultado = scanf(" %d", &cantidadReportes);

				if (resultado != 1) // Si el usuario no escribe un numero
				{
					printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
					limpiarBuffer(); // Limpiamos el buffer del teclado
					continue;		 // Regresamos al inicio del ciclo
				}
				
		     }while (resultado != 1); // FIN DEL WHILE ESPECIAL PARA EVITAR BUGS
			  
				// CONDICION SI EL USUARIO SE PASA DEL LIMITE PARA REPORTAR (5 CASOS)
				if (cantidadReportes > 5 || cantidadReportes < 1)
				{ // INICIO DE IF 2 SI SUPERA EL LIMITE DE 5 CASOS

					printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION INVALIDA, INTENTA DE NUEVO >>>=== \n\n"); // RESPUESTA SI EL USUARIO PUSO MAS DE 5 CASOS O MENOS DE 1 CASO

				} // FIN DEL IF 2
				else
				{ // INICIO DEL ELSE 2

					printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION GUARDADA CORRECTAMENTE >>>=== \n\n "); // RESPUESTA SI EL USUARIO PUSO UNA CANTIDAD ADECUADA

				} // FIN DEL ELSE 2

			} while (cantidadReportes > 5 || cantidadReportes < 1); // FIN DEL CICLO DO WHILE 2

			do
			{ // INICIO DE CICLO DO WHILE 3 SI EL USUARIO PONE HORA INVALIDA
			  
			  
			  do // INICIO DEL DO WHILE ESPECIAL PARA ARREGLAR BUGS
			  {
			  
				printf("\n\n\t\t\t\t\t ======<<< POR FAVOR ESCRIBE LA HORA DEL CASO (RECUERDA QUE USAMOS EL FORMATO DE 24 HRS) >>>======"); // PREGUNTAR HORA
				printf("\n\n\t\t\t\t\t ====<<< SOLO PUEDES INGRESAR LA HORA DEL CASO (NO INGRESES MINUTOS) (00-23 HRS) >>>====:  ");
				printf("\n\n\t\t\t\t\t ===<<< EN CASO DE QUE INGRESO MINUTOS SOLO SE GUARDARAN LAS HORAS  >>>===:  ");
				resultado = scanf(" %d", &hora); // GUARDAR RESPUESTA

				if (resultado != 1) // Si el usuario no escribe un numero
				{
					printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
					limpiarBuffer(); // Limpiamos el buffer del teclado
					continue;		 // Regresamos al inicio del ciclo
				}
				limpiarBuffer(); // Limpiamos el buffer del teclado
				
			  }while (resultado != 1); // FIN DEL DO WHILE ESPECIAL PARA ARREGLAR BUGS
			  
				if (hora < 00 || hora > 23)
				{ // INICIO DEL IF 3, SE EJECUTA SI EL USUARIO PONE UNA HORA INVALIDA

					printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION INVALIDA, INTENTA DE NUEVO >>>=== \n\n"); // RESPUESTA SI LA HORA ES INVALIDA

				} // FIN DEL IF 3

				else // ELSE 3 SI EL USUARIO PONE UNA HORA VALIDA
				{

					printf("\n\n\t\t\t\t\t\t\t\t ===<<< OPCION GUARDADO CORRECTAMENTE >>>=== \n\n"); // RESPUESTA SI EL USUARIO PUSO HORA VALIDA

				} // FIN DEL ELSE 3

			} while (hora < 00 || hora > 23); // FIN DEL CICLO DO WHILE 3, SOLO SE REPITE EL CICLO SI EL USUARIO PONE UNA HORA INVALIDA

		} // FIN DEL ELSE 1 DE PRIORIDAD VALIDA

	} while (tipo < 1 || tipo > 4); // FIN DEL CICLO DO WHILE 1, SOLO SE REPITE SI EL USUARIO PONE UNA PRIORIDAD INVALIDA

	// MOSTRAR EN PANTALLA LAS DECISIONES QUE EL USUARIO ELIGIO
	printf("\n\n\t\t\t ===<<< LA CANTIDAD DE REPORTES DE LA PRIORIDAD %d A LAS %02d : 00 HRS FUERON DE: %d CASO(S) ", tipo, hora, cantidadReportes);
	// MOSTRAR TIEMPO DE ESPERA, DEPENDERA DEL TIPO DE PRIORIDAD
	if (tipo == 1) // OPCION 1
	{
		printf("ATENDER DE MANERA INMEDIATA >>>=== \n\n\n"); // TIEMPO DE ESPERA SI ES UN CASO EMERGENTE
	}
	else if (tipo == 2) // OPCION 2
	{
		printf("EL TIEMPO DE ESPERA ESTIMADA ES DE 5 MIN >>>===\n\n\n"); // TIEMPO DE ESPERA SI EL CASO ES URGENTE
	}
	else if (tipo == 3) // OPCION 3
	{
		printf("EL TIEMPO DE ESPERA ESTIMADA ES DE 10 MIN >>>=== \n\n\n"); // TIEMPO DE ESPERA SI EL CASO ES NO URGENTE
	}
	else // OPCION 4
	{
		printf("EL TIEMPO DE ESPERA ESTIMADA ES DE 20 MIN >>>=== \n\n\n"); // TIEMPO DE ESPERA SI EL CASO ES CONTROL
	}

	// GUARDAR EL CASO EN EL ARREGLO BIDIMENSIONAL LLAMADO CASOS
	tipo = tipo - 1;										  // LA VARIABLE TIPO SE USARA COMO INDICE PARA EL ARREGLO, SE LE RESTA -1 PARA QUE COINCIDA CON EL ARREGLO
	casos[tipo][hora] = casos[tipo][hora] + cantidadReportes; // LE AUMENTAMOS LA CANTIDAD DE REPORTES A ESA CASILLA (HORA Y PRIORIDAD)
	tipo = tipo + 1;										  // DEVOLVEMOS A SU VALOR ORIGINAL LA VARIABLE TIPO, ESTO SIRVE PARA QUE EL UMBRAL PUEDA ACTUALIZAR SUS DATOS

	if (tipo == 1)
	{ // INICIO IF 1, SOLO SE EJECUTA SI LA OPCION ELEGIDA ES LA NUMERO 1

		emergenciasUmbral = emergenciasUmbral + cantidadReportes; // ACUMULADOR DE CASOS

	} // FIN DE IF 1
	
	printf("\n\n\t\t\t ====== PRESIONA DOBLE ENTER PARA CONTINUAR Y DEVOLVERTE AL MENU ... ======\n\n\n");
	getchar(); // LIMPIAR EL BUFFER (LIMPIA EL ESPACIO QUE SOBRA DEL SCANF)
	getchar(); // ESPERA A QUE AÑADAS UN ESPACIO Y CUANDO LO AÑADAS TE MANDA AL MENU

} // FIN DE LA FUNCION AGREGAR CASO

//=================================================== FIN DE LA FUNCION AGREGAR CASOS =====================================================================

//=================================================== INICIO DE LA FUNCION MOSTRAR TABLA DE CASOS =====================================================================

// FUNCION 4
void mostrarTabla() // FUNCION QUE SERVIRA PARA MOSTRAR LA TABLA DE CASOS (PRIORIDADES Y HORAS)
{					// INICIO DE LA FUNCION MOSTRAR LA TABLA

	printf("\n\n====================================================================== MOSTRAR TABLA DE CASOS X HORA ===================================================================");

	umbralEmergencia(); // LLAMAR LA FUNCION DE UMBRAL

	printf("\n\n\t\t\t\t\t\t ===||| TABLA DE TODOS LOS CASOS REGISTRADOS EN LAS ULTIMAS 24 HORAS |||=== \n\n"); // NOMBRE DE LA OPCION

	printf("\n\t\t\t\t\t\t|| HORA ||   EMERGENCIA   ||   URGENTE   ||   NO URGENTE   ||   CONTROL   ||\n"); // TODOS LOS APARTADOS DE LA TABLA
	for (hora = 0; hora < 24; hora++)
	{

		printf("\n\t\t\t\t\t\t    %02d  ", hora); // PRIMERO IMPRIMIRA LA HORA

		for (tipo = 0; tipo < 4; tipo++)
		{
			printf("\t  %d \t ", casos[tipo][hora]); // IMPRIMIRA LOS CASOS
		}
	}
	printf("\n\n\n");
	/* SE USA DOBLE FOR, EL PRIMIERO IMPRIME LA PRIMERA HORA (O LA PRIMERA CASILLA DE LAS COLUMNAS ) DESPUES EL SEGUNDO FOR IMPRIME
	   LOS VALORES DE LAS 4 PRIORIDADES ( O CASILLAS ) Y DESPUES DE IMPRIMIR TODO ESO EL PRIMER FOR IMPRIME LA SEGUNDA HORA Y EL SEGUNDO FOR IMPRIME LOS
	   VALORES QUE HAY EN ELLA
	*/
	
	printf("\n\n\t\t\t ====== PRESIONA ENTER PARA CONTINUAR Y DEVOLVERTE AL MENU ... ======\n\n\n");
	getchar();// LIMPIAR EL BUFFER (LIMPIA EL ESPACIO QUE SOBRA DEL SCANF)
	getchar();// ESPERA A QUE AÑADAS UN ESPACIO Y CUANDO LO AÑADAS TE MANDA AL MENU

} // FIN DE LA FUNCION MOSTRAR TABLA

//=================================================== FIN DE LA FUNCION MOSTRAR TABLA DE CASOS =====================================================================

//============================================= INICIO DE LA FUNCION MOSTRAR ESTADISTICAS DE CASOS COMUNITARIOS ==============================================

// FUNCION 5
void mostrarEstadisticas() // FUNCION PARA HACER ESTADISTICAS SOBRE LOS CASOS
{						   // INICIO DE LA FUNCION DE ESTADISTICAS

	int emergenciaTotal = 0;
	int urgenteTotal = 0;
	int noUrgTotal = 0;
	int controlTotal = 0;
	
	float emerPorcentaje=0;
	float urgPorcentaje=0;
	float noUrgPorcentaje=0;
	float controlPorcentaje=0;
	

	int maxEmer = 0;
	int maxUrg = 0;
	int maxNoUrg = 0;
	int maxControl = 0;

	int casosTotal = 0;
	float porcentajeTotal = 0;

	printf("\n\n=============================================================== MOSTRAR ESTADISTICAS DE CASOS X HORA ===================================================================");

	// CONTAR TODOS LOS CASOS DE CADA PRIORIDAD

	umbralEmergencia();

	for (indice1 = 0; indice1 < 24; indice1++)
	{ // INICIO DEL FOR 1 PARA CALCULAR LOS CASOS TOTALES DE CADA PRIORIDAD
		emergenciaTotal = emergenciaTotal + casos[0][indice1];

		urgenteTotal = urgenteTotal + casos[1][indice1];

		noUrgTotal = noUrgTotal + casos[2][indice1];

		controlTotal = controlTotal + casos[3][indice1];
	} // FIN DEL FOR 1

	// MOSTRAR LA CANTIDAD TOTAL DE CADA PRIORIDAD

	if (emergenciaTotal == 0)
	{ // INICIO DEL IF 1, SIRVE PARA SABER SI NO HAY NINGUN CASO REGISTRADO

		printf("\n\n\t\t\t\t\t\t ===||| NO HUBO CASOS DE EMERGENCIAS REGISTRADOS DURANTE EL DIA |||=== "); // RESPUESTA SI EN LA PRIORIDAD DE EMERGENCIA NO HAY CASOS

	} // FIN DEL IF 1

	else
	{ // INICIO DEL ELSE 1 QUE SIRVE PARA SABER CUANTOS CASOS TOTALES HUBO EN LA PRIORIDAD DE EMERGENCIA

		printf("\n\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE EMERGENCIA QUE HUBIERON DURANTE EL DIA FUERON: %d CASO(S) |||===", emergenciaTotal); // RESPUESTA
		
		emerPorcentaje = (emergenciaTotal * 100) / 4; // MULTIPLICAMOS LA CANTIDAD DE CASOS TOTALES DE ESTA PRIORIDAD POR 100 Y DIVIDIMOS POR LOS 4 TIPOS DE PRIORIDAD
		// LA SUMA DE TODOS LOS PORCENTAJES DEBE DAR 100%
		
		printf("\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE EMERGENCIA REPRESENTADO EN PORCENTAJE ES: %.2f%% |||===", emerPorcentaje); 

	} // FIN DEL ELSE 1

	if (urgenteTotal == 0)
	{ // INICIO DEL IF 2, SIRVE PARA SABER SI NO HAY NINGUN CASO REGISTRADO

		printf("\n\n\t\t\t\t\t\t ===||| NO HUBO CASOS DE URGENCIA REGISTRADOS DURANTE EL DIA |||=== "); // RESPUESTA SI EN LA PRIORIDAD DE URGENTE NO HAY CASOS

	} // FIN DEL IF 2

	else
	{ // INICIO DEL ELSE 2 QUE SIRVE PARA SABER CUANTOS CASOS TOTALES HUBO EN LA PRIORIDAD DE URGENCIAS

		printf("\n\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE URGENCIA QUE HUBIERON DURANTE EL DIA FUERON: %d CASO(S) |||===", urgenteTotal); // RESPUESTA
		
		urgPorcentaje = (urgenteTotal * 100) / 4; // MULTIPLICAMOS LA CANTIDAD DE CASOS TOTALES DE ESTA PRIORIDAD POR 100 Y DIVIDIMOS POR LOS 4 TIPOS DE PRIORIDAD
		// LA SUMA DE TODOS LOS PORCENTAJES DEBE DAR 100%
		
		printf("\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE URGENCIA REPRESENTADO EN PORCENTAJE ES: %.2f%% |||===", urgPorcentaje); 
		
	} // FIN EL ELSE 2

	if (noUrgTotal == 0)
	{ // INICIO DEL IF 3, SIRVE PARA SABER SI NO HAY NINGUN CASO REGISTRADO

		printf("\n\n\t\t\t\t\t\t ===||| NO HUBO CASOS DE NO URGENTE REGISTRADOS DURANTE EL DIA |||=== "); // RESPUESTA SI EN LA PRIORIDAD DE NO URGENTE NO HAY CASOS

	} // FIN DEL IF 3

	else // INICIO DEL ELSE 3 QUE SIRVE PARA SABER CUANTOS CASOS TOTALES HUBO EN LA PRIORIDAD DE NO URGENTE
	{
		printf("\n\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE NO URGENTE QUE HUBIERON DURANTE EL DIA FUERON: %d CASO(S) |||===", noUrgTotal); // RESPUESTA
	
		noUrgPorcentaje = (noUrgTotal * 100) / 4; // MULTIPLICAMOS LA CANTIDAD DE CASOS TOTALES DE ESTA PRIORIDAD POR 100 Y DIVIDIMOS POR LOS 4 TIPOS DE PRIORIDAD
		// LA SUMA DE TODOS LOS PORCENTAJES DEBE DAR 100%
		
		printf("\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE NO URGENCIA REPRESENTADO EN PORCENTAJE ES: %.2f%% |||===", noUrgPorcentaje); 
		
	} // FIN DEL ELSE 3

	if (controlTotal == 0)
	{ // INICIO DEL IF 4,  SIRVE PARA SABER SI NO HAY NINGUN CASO REGISTRADO

		printf("\n\n\t\t\t\t\t\t ===||| NO HUBO CASOS DE CONTROL REGISTRADOS DURANTE EL DIA |||=== "); // RESPUESTA SI EN LA PRIORIDAD DE CONTROL NO HAY CASOS

	} // FIN DEL IF 4

	else
	{ // INICIO DEL ELSE 4 QUE SIRVE PARA SABER CUANTOS CASOS TOTALES HUBO EN LA PRIORIDAD DE CONTROL

		printf("\n\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE CONTROL QUE HUBIERON DURANTE EL DIA FUERON: %d CASO(S) |||=== ", controlTotal); // RESPUESTA
		
		controlPorcentaje = (controlTotal * 100) / 4; // MULTIPLICAMOS LA CANTIDAD DE CASOS TOTALES DE ESTA PRIORIDAD POR 100 Y DIVIDIMOS POR LOS 4 TIPOS DE PRIORIDAD
		// LA SUMA DE TODOS LOS PORCENTAJES DEBE DAR 100%
		
		printf("\n\t\t\t\t\t ===||| EL TOTAL DE CASOS DE CONTROL REPRESENTADO EN PORCENTAJE ES: %.2f%% |||===", controlPorcentaje); 
		
	} // FIN DEL ELSE 4

	/* AHORA VAMOS A CALCULAR CUAL ES LA HORA O CUALES SON LAS HORAS CON MAYOR NUMERO DE CASOS, PARA ESTO PRIMERO DEBEMOS COMPARAR EL NUMERO DE CASOS
	   PARA ESTO DEBEMOS USAR UNA VARIABLE Y ESTAR COMPARANDO CUAL ES EL NUMERO MAS GRANDE TODOS Y DE CADA PRIORIDAD Y DESPUES ESO CON UN FOR
	   VAMOS A COMPARAR LAS HORAS Y PODER DECIR CUALES FUERON LAS HORAS O LA HORA CON MAS CASOS
	*/

	printf("\n\n\n\n\t\t\t\t\t\t\t ===||| HORA CON MAS CASOS DE CADA PRIORIDAD |||=== "); // CALCULAR Y COMPARAR CASOS X HORA

	for (indice2 = 0; indice2 < 24; indice2++)
	{ // INICIO DEL FOR 2 PARA COMPARAR CUAL FUE LA HORA CON MAS CASOS

		if (casos[0][indice2] > maxEmer)
		{ // INICIO DEL IF 5

			maxEmer = casos[0][indice2];

		} // FIN DEL IF 5

		if (casos[1][indice2] > maxUrg)
		{ // INICIO DEL IF 6

			maxUrg = casos[1][indice2];

		} // FIN DEL IF 6

		if (casos[2][indice2] > maxNoUrg)
		{ // INICIO DEL IF 7

			maxNoUrg = casos[2][indice2];

		} // FIN DEL IF 7

		if (casos[3][indice2] > maxControl)
		{ // INICIO DEL IF 8

			maxControl = casos[3][indice2];

		} // FIN DEL IF 8

	} // FIN DEL FOR 2

	// AHORA VAMOS A COMPARAR Y MOSTRAR EN PANTALLA CUALES SON LOS CASOS CON MAS HORAS

	if (maxEmer == 0)
	{ // INICIO DEL IF 9 SI NO HAY CASOS REGISTRADOS

		printf("\n\n\t\t\t\t\t\t\t\t ===||| NO SE REGISTRARON CASOS |||=== "); // RESPUESTA

	} // FIN DEL IF 9

	else
	{ // INICIO DEL ELSE 5

		printf("\n\n\t\t\t\t\t\t ===||| HORA CON MAS CASOS DE EMERGENCIAS (%d CASOS) |||=== : ", maxEmer); // RESPUESTA PARA MOSTRAR LA HORA CON MAS CASOS

		for (indice2 = 0; indice2 < 24; indice2++)
		{ // INICIO DEL FOR 3

			if (casos[0][indice2] == maxEmer)
			{ // INICIO DEL IF 10

				printf("%02d:00 HRS ", indice2);

			} // FIN DEL IF 10
		}
	}

	if (maxUrg == 0)
	{ // INICIO DEL IF 11 SI NO HAY CASOS REGISTRADOS

		printf("\n\n\t\t\t\t\t\t\t\t ===||| NO SE REGISTRARON CASOS |||=== "); // RESPUESTA

	} // FIN DEL IF 11

	else
	{ // INICIO DEL ELSE 6

		printf("\n\n\t\t\t\t\t\t ===||| HORA CON MAS CASOS DE URGENCIAS (%d CASOS) |||===: ", maxUrg); // MOSTRAR HORA CON MAS CASOS

		for (indice2 = 0; indice2 < 24; indice2++)
		{ // INICIO DEL FOR 4

			if (casos[1][indice2] == maxUrg)
			{ // INICIO DEL IF 12

				printf("%02d:00 HRS ", indice2); // MOSTRAR HORA CON MAS CASOS

			} // INICIO DEL IF 12

		} // FIN DEL FOR 4

	} // FIN DEL ELSE 6

	if (maxNoUrg == 0)
	{ // INICIO DEL IF 13 SI NO HAY CASOS REGISTRADOS

		printf("\n\n\t\t\t\t\t\t\t\t ===||| NO SE REGISTRARON CASOS |||==="); // RESPUESTA

	} // FIN DEL IF 13

	else
	{ // INICIO DEL ELSE 7

		printf("\n\n\t\t\t\t\t\t  ===||| HORA CON MAS CASOS DE NO URGENTE (%d CASOS) |||===: ", maxNoUrg); // RESPUESTA

		for (indice2 = 0; indice2 < 24; indice2++)
		{ // INICIO DEL FOR 5

			if (casos[2][indice2] == maxNoUrg)
			{ // INICIO DEL IF 14

				printf("%02d:00 HRS ", indice2); // MOSTRAR HORA EN PANTALLA

			} // FIN DEL IF 14

		} // FIN DEL FOR 5

	} // FIN DEL ELSE 7

	if (maxControl == 0)
	{ // INICIO DEL IF 15 SI NO HAY CASOS REGISTRADOS

		printf("\n\n\t\t\t\t\t\t\t\t ===||| NO SE REGISTRARON CASOS |||=== \n\n\n "); // RESPUESTA

	} // FIN DEL IF 15

	else
	{ // INICIO DEL ELSE 8

		printf("\n\n\t\t\t\t\t\t ===||| HORA CON MAS CASOS DE CONTROL (%d CASOS) |||=== :  ", maxControl); // RESPUESTA

		for (indice2 = 0; indice2 < 24; indice2++)
		{ // INICIO DEL FOR 6

			if (casos[3][indice2] == maxControl)
			{ // INICIO DEL IF 16

				printf("%02d:00 HRS ", indice2); // MOSTRAR HORA

			} // FIN DEL IF 16

		} // FIN DEL FOR 6

	} // FIN DEL ELSE 8

	// AHORA VAMOS A CALCULAR TODOS LOS CASOS DE TODAS LAS PRIORIDADES DE TODO EL DIA

	for (indice1 = 0; indice1 < 4; indice1++)
	{ // INICIO DEL FOR 7

		for (indice2 = 0; indice2 < 24; indice2++)
		{ // INICIO DEL FOR 8

			casosTotal = casosTotal + casos[indice1][indice2]; // ACUMULADOR

		} // FIN DEL FOR 8

	} // FIN DEL FOR 7

	// MOSTRAR LOS CASOS TOTALES
	printf("\n\n\n\n\t\t\t\t\t ===||| LOS CASOS TOTALES DE TODAS LAS PRIORIDADES QUE HUBIERON EN EL DIA FUERON: %d |||===\n ", casosTotal);

	// SACAR PORCENTAJE
    //eso es 
	porcentajeTotal = casosTotal;
    porcentajeTotal = (porcentajeTotal * 24) / 100;
    // porcentaje del urgencia = urgenciatotal * 100 / casostotal 
    // porcentaje del no urgente = noUrgTotal * 100 / casostotal 
    // porcentaje del control = controlTotal * 100 / casostotal 
    //porcentaje del emergencia = emergenciaTotal * 100 / casostotal 

	// MOSTRAR PORCENTAJE
	printf("\n\n\t\t\t\t\t\t\t ===||| EL PORCENTAJE DE CASOS QUE HUBO FUE DEL %.2f%% |||=== \n\n\n\n ", porcentajeTotal);
	
	printf("\n\n\t\t\t ====== PRESIONA ENTER PARA CONTINUAR Y DEVOLVERTE AL MENU ... ======\n\n\n");
	getchar();// LIMPIAR EL BUFFER (LIMPIA EL ESPACIO QUE SOBRA DEL SCANF)
	getchar();// ESPERA A QUE AÑADAS UN ESPACIO Y CUANDO LO AÑADAS TE MANDA AL MENU

} // FIN DE LA FUNCION ESTADISTICAS

//=================================================== FIN DE LA FUNCION MOSTRAR ESTADISTICAS DE CASOS COMUNITARIOS =================================================

//=================================================== INICIO DE LA FUNCION MOSTRAR RECOMENDACIONES =================================================

// FUNCION 6
void recomendaciones()
{ // INICIO DE LA FUNCION RECOMENDACIONES

	printf("\n\n======================================================================== RECOMENDACIONES ==============================================================================");

	umbralEmergencia();

	printf("\n\n\n\t\t\t ESTE PROGRAMA FUE CREADO PARA ADMINISTRAR LOS CASOS QUE OCURRAN EN LA COMUNIDAD, \n\t\t\t A CONTINUACION SE TE DARA UNA EXPLICACION DE CADA FUNCION DEL PROGRAMA ");
	printf("\n\n\t\t\t 1. CAPTURAR DATOS: ");
	printf("\n\n\t\t\t CAPTURA LOS CASOS QUE OCURRAN DURANTE LAS 24 HORAS DEL DIA, CADA CASO SE DIVIDE POR PRIORIDADES");
	printf("\n\t\t\t (EMERGENCIA, URGENTE, NO URGENTE Y CONTROL) CADA CASO CUENTA CON UN TIEMPO DE ESPERA: ");
	printf("\n\t\t\t EMERGENCIA : INMEDIATO, URGENTE : 5 MIN, NO URGENTE : 10 MIN, CONTROL : 20 MINS.");
	printf("\n\t\t\t ESCRIBE LA CANTIDAD DE CASOS QUE DESEAS HACER, NO PUEDES HACER MAS DE 5 O MENOS DE 1 ");
	printf("\n\t\t\t CADA CASO QUE GUARDES LE Aï¿½ADIRAS LA HORA EN LA QUE OCURRIO, RECUERDA QUE SE USA EL FORMATO DE 24 HRS");
	printf("\n\t\t\t INGRESA LA PRIORIDAD Y LA HORA (EN FORMATO 24 HRS) Y TU CASO SE HABRA GUARDADO CON EXITO");

	printf("\n\n\n\t\t\t 2. MOSTRAR TABLA: ");
	printf("\n\n\t\t\t CON ESTA OPCION PODRAS VER EL TOTAL DE CASOS QUE HAY REGISTRADOS EN LAS ULTIMAS 24 HRS");

	printf("\n\n\t\t\t 3. MOSTRAR ESTADISTICAS");
	printf("\n\n\t\t\t PODRAS VER EL TOTAL DE CASOS QUE HAY EN CADA PRIORIDAD DURANTE ULTIMAS HRS");
	printf("\n\t\t\t PODRAS VER HORA EN LA QUE HUBO MAS CASOS DE CADA PRIORIDAD");
	printf("\n\t\t\t PODRAS VER EL TOTAL DE CASOS QUE HUBIERON EN TODO EL DIA, SE REPRESENTARA EN DECIMAL Y EN PORCENTAJE");

	printf("\n\n\t\t\t 5. RESETEAR CASOS COMUNITARIOS: ");
	printf("\n\n\t\t\t UTILIZALO CUANDO ACABE TU JORNADADE 24 HRS PARA RESETEAR LOS CASOS QUE HUBIERON EN LAS ULTIMAS 24 HRS");

	printf("\n\n\t\t\t 6. BORRAR CASOS COMUNITARIOS");
	printf("\n\n\t\t\t SI TE EQUIVOCASTE Y AGREGASTE DE MAS UN CASO ENTONCES PODRAS BORRARLO");
	printf("\n\t\t\t FUNCIONA DE LA MISMA MANERA QUE CUANDO AGREGAS UN CASO PERO CON LA DIFERENCIA DE QUE ");
	printf("\n\t\t\t SI INTENTAS BORRAR UNA CANTIDAD MAS GRANDE DE LO QUE HAY GUARDADO EL PROGRAMA TE MANDARA ");
	printf("\n\t\t\t DIRECTO AL MENU Y NO SE BORRARA NADA... NO QUEREMOS CASOS NEGATIVOS");

	printf("\n\n\t\t\t 7. SALIR: ");
	printf("\n\n\t\t\t CIERRE DEL PROGRAMA \n\n\n");
	
	printf("\n\n\t\t\t ====== PRESIONA ENTER PARA CONTINUAR Y DEVOLVERTE AL MENU ... ======\n\n\n");
	getchar();// LIMPIAR EL BUFFER (LIMPIA EL ESPACIO QUE SOBRA DEL SCANF)
	getchar();// ESPERA A QUE AÑADAS UN ESPACIO Y CUANDO LO AÑADAS TE MANDA AL MENU
	
} // FIN DE LA FUNCION RECOMENDACIONES

//=================================================== FIN DE LA FUNCION MOSTRAR RECOMENDACIONES =================================================

//=================================================== INICIO DE LA FUNCION RESETEAR CASOS =================================================

// FUNCION 7
void resetearDatos()
{ // INICIO DE LA FUNCION 6 PARA RESETEAR LOS DATOS

	char decision;

	printf("\n\n========================================================================== RESETEAR DATOS ==============================================================================");

	umbralEmergencia();

	printf("\n\n\n\t\t\t ===||| ESTAS SEGURO DE RESETEAR LOS DATOS CAPTURADOS? ESTA FUNCION SOLO SE USA CUANDO HAYAN TRANSCURRIDO LAS 24 HRS |||=== ");
	printf("\n\t\t\t\t\t\t ===||| ESCRIBE 'S' PARA CONTINUAR O PRESIONA OTRA TECLA PARA SALIR |||=== :  ");
	scanf(" %c", &decision);

	if (decision == 'S' || decision == 's')
	{ // INICIO DEL IF


		for (indice1 = 0; indice1 < 4; indice1++)
		{ // INICIO DEL FOR 1

			for (indice2 = 0; indice2 < 24; indice2++)
			{ // INICIO DEL FOR 2

				casos[indice1][indice2] = 0;

			} // FIN DEL FOR 2

		} // FIN DEL FOR 1

		emergenciasUmbral = 0;

		printf("\n\n\t\t\t\t\t ===||| EL TURNO DE 24 HRS HA ACABADO, LOS DATOS HAN SIDO RESETEADOS CORRECTAMENTE |||=== \n\n\n ");

	} // FIN DEL IF

	else
	{ // INICIO DEL ELSE
		printf("\n\n\t\t\t ===||| REGRESANDO AL MENU PRINCIPAL... |||=== \n\n\n ");
	} // FIN DEL ELSE

} // FIN DE LA FUNCION 6

//=================================================== FIN DE LA FUNCION RESETEAR CASOS =========================================================================

//=================================================== INICIO DE LA FUNCION BORRAR CASOS COMUNIATRIOS ============================================================

// FUNCION 8
void borrarCaso() // FUNCION PARA AGREGAR CASOS
{				  // INICIO DE LA FUNCION AGREGAR CASO

	int ejecutarFuncion=0;
	
		for (indice1 = 0; indice1 < 4; indice1++)
		{ // INICIO DEL FOR 1

			for (indice2 = 0; indice2 < 24; indice2++)
			{ // INICIO DEL FOR 2

				if(casos[indice1][indice2] != 0)
				{
					ejecutarFuncion++;
					break;
				}

			} // FIN DEL FOR 2

		} // FIN DEL FOR 1

	if(ejecutarFuncion != 0)
	{
	
	do // DO WHILE 1 USADO PARA REPETIR PREGUNTA DE PRIORIDAD SI EL USUSARIO PONE UNA PRIORIDAD INVALIDA
	{  // INICIO DEL DO WHILE 1

		printf("\n\n======================================================================== BORRAR CASO COMUNITARIO ======================================================================");

		umbralEmergencia(); // LLAMAR FUNCION PARA MOSTRAR UMBRAL

		printf("\n\n\t\t\t\t\t ===<<< POR FAVOR ELIGE EL NUMERO DEL TIPO DE PRIORIDAD DEL CASO QUE DESEAS BORRAR >>>==="); // MOSTRAR OPCIONES
		printf("\n\n\t\t\t\t\t\t\t [1] EMERGENCIA [2] URGENCIA [3] NO URGENTE [4] CONTROL");							   // OPCIONES DE PRIORIDAD
		printf("\n\n\n\t\t\t\t\t\t ===<<< EL TIPO DE PRIORIDAD ELEGIDA FUE LA NUMERO >>>===:  ");
		resultado = scanf(" %d", &tipo);
		if (resultado != 1) // Si el usuario no escribiÃ³ un nÃºmero
		{
			printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
			limpiarBuffer(); // Limpiamos el buffer del teclado
			continue;		 // Regresamos al inicio del ciclo
		}

		if (tipo < 1 || tipo > 4)
		{ // INICIO DEL IF 1 SE EJECUTA SI EL USUARIO ELIGE UNA PRIORIDAD INVALIDA

			printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION INCORRECTA, INTENTA DE NUEVO >>>==="); // RESPUESTA SI EL USUARIO PUSO UNA PRIORIDAD INVALIDA

		} // FINAL DEL IF 1

		else
		{ // INICIO DEL ELSE 1 SI EL USUARIO PUSO UNA PRIORIDAD VALIDA

			printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION GUARDADA CORRECTAMENTE >>>=== \n\n "); // RESPUESTA SI EL USUARIO USO UNA PRIORIDAD VALIDA

			// PREGUNTAR CUANTOS REPORTES DESEA HACER

			do
			{ // INICIO DEL CICLO DO WHILE 2 USADO SI EL USUARIO PIDE MAS DE 5 REPORTES
			
			  do
			  {
			  
			
				printf("\n\n ===<<< ESCRIBE LA CANTIDAD DE CASOS QUE DESEAS BORRAR DE ESTA PRIORIDAD (SOLO PUEDES BORRAR 5 CASOS, SI DESEAS BORRAR MAS CASOS TENDRAS QUE REPETIR TODO) >>>===");
				printf("\n\n\t\t\t\t\t\t\t ===<<< LA CANTIDAD DE REPORTES PARA BORRAR FUE DE >>>===:  ");
				resultado = scanf(" %d", &cantidadReportes);
				if (resultado != 1) // Si el usuario no escribiÃ³ un nÃºmero
				{
					printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
					limpiarBuffer(); // Limpiamos el buffer del teclado
					continue;		 // Regresamos al inicio del ciclo
				}
			
			  }while(resultado != 1);
			
				// CONDICION SI EL USUARIO SE PASA DEL LIMITE PARA REPORTAR (5 CASOS)
				if (cantidadReportes > 5 || cantidadReportes < 1)
				{ // INICIO DE IF 2 SI SUPERA EL LIMITE DE 5 CASOS

					printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION INVALIDA, INTENTA DE NUEVO >>>=== \n\n"); // RESPUESTA SI EL USUARIO PUSO MAS DE 5 CASOS O MENOS DE 1 CASO

				} // FIN DEL IF 2
				else
				{ // INICIO DEL ELSE 2

					printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION GUARDADA CORRECTAMENTE >>>=== \n\n "); // RESPUESTA SI EL USUARIO PUSO UNA CANTIDAD ADECUADA

				} // FIN DEL ELSE 2

			} while (cantidadReportes > 5 || cantidadReportes < 1); // FIN DEL CICLO DO WHILE 2

			do
			{ // INICIO DE CICLO DO WHILE 3 SI EL USUARIO PONE HORA INVALIDA
			
			  do
			  {
			
				printf("\n\n\t\t\t\t\t =====<<< POR FAVOR ESCRIBE LA HORA DEL CASO (RECUERDA QUE USAMOS EL FORMATO DE 24 HRS) >>>====="); // PREGUNTAR HORA
				printf("\n\n\t\t\t\t\t\ ===<<< SOLO PUEDES INGRESAR LA HORA DEL CASO (NO INGRESES MINUTOS) (00-23 HRS) >>>===:  ");
				resultado = scanf(" %d", &hora); // GUARDAR RESPUESTA
				if (resultado != 1)				 // Si el usuario no escribiÃ³ un nÃºmero
				{
					printf("\n\n\t\t\t\t\t\t\t ------- OPCION INVALIDA, SOLO SE ACEPTAN NUMEROS -------\n\n");
					limpiarBuffer(); // Limpiamos el buffer del teclado
					continue;		 // Regresamos al inicio del ciclo
				}

			  }while(resultado != 1);

				if (hora < 00 || hora > 23)
				{ // INICIO DEL IF 3, SE EJECUTA SI EL USUARIO PONE UNA HORA INVALIDA

					printf("\n\n\t\t\t\t\t\t\t ===<<< OPCION INVALIDA, INTENTA DE NUEVO >>>=== \n\n"); // RESPUESTA SI LA HORA ES INVALIDA

				} // FIN DEL IF 3

				else // ELSE 3 SI EL USUARIO PONE UNA HORA VALIDA
				{

					printf("\n\n\t\t\t\t\t\t\t\t ===<<< OPCION GUARDADO CORRECTAMENTE >>>=== \n\n"); // RESPUESTA SI EL USUARIO PUSO HORA VALIDA

				} // FIN DEL ELSE 3

			} while (hora < 00 || hora > 23); // FIN DEL CICLO DO WHILE 3, SOLO SE REPITE EL CICLO SI EL USUARIO PONE UNA HORA INVALIDA

		} // FIN DEL ELSE 1 DE PRIORIDAD VALIDA

	} while (tipo < 1 || tipo > 4); // FIN DEL CICLO DO WHILE 1, SOLO SE REPITE SI EL USUARIO PONE UNA PRIORIDAD INVALIDA

	// MOSTRAR EN PANTALLA LAS DECISIONES QUE EL USUARIO ELIGIO
	printf("\n\n\t\t\t ===<<< EL CASO QUE DESEAS BORRAR ES DE LA PRIORIDAD %d A LAS %02d : 00 HRS, LA CANTIDAD DE CASOS QUE BORRARAS ES DE : %d CASO(S) >>>=== \n\n\n ", tipo, hora, cantidadReportes);
	// MOSTRAR TIEMPO DE ESPERA, DEPENDERA DEL TIPO DE PRIORIDAD

	tipo = tipo - 1; // LA VARIABLE TIPO SE USARA COMO INDICE PARA EL ARREGLO, SE LE RESTA -1 PARA QUE COINCIDA CON EL ARREGLO

	if (cantidadReportes > casos[tipo][hora])
	{ // INICIO DEL IF 1, SI EL USUARIO INTENTA BORRAR UNA CANTIDAD MAYOR DE LO QUE HAY GUARDADO

		printf("\n\n\t\t\t ===<<< NO SE PUEDE BORRAR ESA CANTIDAD DE CASOS, LO QUE SOLICITAS BORRAR ES MAS GRANDE QUE LO QUE HAY GUARDADO >>>=== \n\n\n");
		/* EL PROPROSITO DE ESTO ES QUE EL USUARIO NO BORRE CANTIDADES MUY GRANDES Y PROVOQUE CASOS NEGATIVOS
		*/
		
	} // FIN DEL IF 1

	else
	{ // INICIO DEL ELSE 1

		// BORRAR EL CASO EN EL ARREGLO BIDIMENSIONAL LLAMADO CASOS

		casos[tipo][hora] = casos[tipo][hora] - cantidadReportes; // LE AUMENTAMOS LA CANTIDAD DE REPORTES A ESA CASILLA (HORA Y PRIORIDAD)

		tipo = tipo + 1; // DEVOLVEMOS A SU VALOR ORIGINAL LA VARIABLE TIPO, ESTO SIRVE PARA QUE EL UMBRAL PUEDA ACTUALIZAR SUS DATOS

		if (tipo == 1)
		{ // INICIO IF 2, SOLO SE EJECUTA SI LA OPCION ELEGIDA ES LA NUMERO 1

			emergenciasUmbral = emergenciasUmbral - cantidadReportes; // ACUMULADOR DE CASOS

		} // FIN DE IF 2

		printf("\n\n\t\t\t\t\t\t\t\t ===<<< CASO BORRADO CON EXITO  >>>=== \n\n\n");

	} // FIN DEL ELSE 1
	
	
	}
	else
	{
		printf("\n\n\t\t\t\t ===<<< NO PUEDES EJECUTAR ESTA ACCION YA QUE NO HAS REGISTRADO NINGUN CASO...>>>===");
	}
		printf("\n\n\t\t\t ====== PRESIONA ENTER PARA CONTINUAR Y DEVOLVERTE AL MENU ... ======\n\n\n");
		getchar();// LIMPIAR EL BUFFER (LIMPIA EL ESPACIO QUE SOBRA DEL SCANF)
		getchar();// ESPERA A QUE AÑADAS UN ESPACIO Y CUANDO LO AÑADAS TE MANDA AL MENU

} // FIN DE LA FUNCION 7 BORRAR CASOS

//=================================================== FIN DE LA FUNCION BORRAR CASOS COMUNITARIOS ==============================================================
