#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Foco : public Modelo {

public:

	Foco();

	void avanzar();
	
private:

	void actualizarMatrizModelo();

	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);

};