#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Meta : public Modelo {

public:

	Meta();

	void avanzar();

	void actualizarMatrizModelo();

	vec3 coordenadas = vec3(0.0f, 2.5f, 2.0f);

private:


};