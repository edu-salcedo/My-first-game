#include "alarma.h"

Alarma::Alarma()
{
    cont=0;
}

bool Alarma::timer(int secons)
{

	if(secons == 0){
		return false;
	}

	if(cont >= secons){
		cont = 0;
		return true;
	}

	cont++;

	return false;
}
