#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Background : public Modelo {

public:
	Background();
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 2.5f, 2.0f);
	vec3 getCoordenadas();

private:

};