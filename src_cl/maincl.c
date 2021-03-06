/*! \file maincl.c
    \brief Main Cliente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "funciones.h"

int main(int argc, char **argv){	
 
	ini_var *variables = malloc (sizeof (ini_var));	

	variablescliente *varcliente = malloc (sizeof (variablescliente));

	auxpartida *auxpar = malloc (sizeof (auxpartida));

	frameExplosion *fE = malloc (sizeof (frameExplosion));

	frameMonedita *fM = malloc (sizeof (frameMonedita));
	
		
	Inicializar (&variables, &auxpar, &fE, &fM);

	Niveles (&auxpar);
	
	GameLoop (&variables, &varcliente, &auxpar, &fE, &fM);
	
	Liberar (&variables, &varcliente, &auxpar, &fE, &fM);				// Libera memoria
	
	return 0;
}

//fprintf (stderr, "hasta aca anda \n");
