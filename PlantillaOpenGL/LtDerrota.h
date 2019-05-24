#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class LtDerrota : public Modelo {

public:

	LtDerrota();

	void actualizarMatrizModelo();

	vec3 coordenadas = vec3(70.0f, 99.0f, 99.0f);

private:

};