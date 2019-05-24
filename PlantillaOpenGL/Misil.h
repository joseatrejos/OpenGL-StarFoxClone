#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Misil : public Modelo {

public:
	Misil();
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
	void aparecer(vec3 coordenadasNaveEnemiga);
	void desaparecer();
	void avanzar(double tiempoDiferencial);
	void time(double tiempoDiferencial);
	double tiempoAcumulado = 0.0;
	bool renderearBala = true;
	bool renderearBalaEnemiga = false;
	bool balaEnemigaDisparada = false;
	bool balaEnemigaColisionada = false;

private:

};