#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Bala : public Modelo {

public:
	Bala();
	void aparecer(vec3 coordenadasNaveStarFox);
	void avanzar();
	void tiempovida();
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);

private:

};