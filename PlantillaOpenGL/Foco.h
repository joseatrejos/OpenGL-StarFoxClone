#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Foco : public Modelo {

public:
	Foco();
	void avanzar();
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.4f, 2.0f);

private:

};