#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class NaveEnemiga : public Modelo {

public:
	NaveEnemiga();
	void avanzar();
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
	vec3 getCoordenadas();

private:

};