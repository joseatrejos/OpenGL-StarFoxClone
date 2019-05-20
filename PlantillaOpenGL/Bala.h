#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Bala : public Modelo {

public:
	Bala();
	void aparecer();
	void avanzar();

private:
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
};