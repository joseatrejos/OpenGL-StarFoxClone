#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class LtVictoria : public Modelo {

public:

	LtVictoria();
	void actualizarMatrizModelo();
	void avanzar(double tiempoDiferencial);
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
	void aparecer(vec3 coordenadasNaveStarFox);

private:

};