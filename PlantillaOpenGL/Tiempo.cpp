#include "stdafx.h"

class Tiempo {
private:
	double tiempoAnterior, tiempoActual, tiempoAnteriorColision, tiempoDiferencial, tiempoDiferencialColision;

public:
	Tiempo(double TiempoDiferencial, double TiempoDiferencialColision) //, double TiempoActual, double TiempoAnterior, double TiempoAnteriorColision)
	{
		/*tiempoAnterior = TiempoAnterior;
		tiempoActual = TiempoActual;
		tiempoAnteriorColision = TiempoAnteriorColision;*/
		tiempoDiferencial = TiempoDiferencial;
		tiempoDiferencialColision = TiempoDiferencialColision;
	}

	double getTiempoDiferencial()
	{
		return tiempoDiferencial;
	}

	double getTiempoDiferencialColision()
	{
		return tiempoDiferencialColision;
	}
};