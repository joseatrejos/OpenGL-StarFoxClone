#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Casa : public Modelo {

public:
	Casa();
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, -2.0f, 2.0f);
private:
	
};