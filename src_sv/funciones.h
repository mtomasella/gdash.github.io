#include "datos.h"

int	Inicializar (ini_var **, auxpartida **, frameExplosion **, frameMonedita **);
int inicializar_sv (variablesservidor *);

int Niveles (niveles **);

int	GameLoop (ini_var **, variablesservidor *, auxpartida **, frameExplosion **, frameMonedita **);
int partida (ini_var **, posicion *, auxpartida *, frameExplosion *, frameMonedita *);
int fin (ini_var **, auxpartida *, variablesservidor *);	
int wait_cx (variablesservidor *);
int receive_data (ini_var **, variablesservidor *, posicion *, auxpartida *);
