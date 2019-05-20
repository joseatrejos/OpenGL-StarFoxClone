#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
class NaveStarFox : public Modelo {
public:

	NaveStarFox();
	void avanzar();
	void rotar();
	void moverIzquierda();
	void moverDerecha();
	void retroceder();
	vec3  getCoordenadas();

private:
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
};
