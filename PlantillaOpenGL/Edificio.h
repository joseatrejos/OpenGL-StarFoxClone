#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Edificio : public Modelo {

public:
	Edificio();
	vec3 coordenadas = vec3(0.0f, -2.0f, 2.0f);
	void actualizarMatrizModelo();
	vec3 getCoordenadas();

private:

}; 
