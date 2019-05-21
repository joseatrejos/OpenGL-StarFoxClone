#pragma once

#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
class NaveStarFox : public Modelo {
public:
	NaveStarFox();
	void avanzar(double tiempoDiferencial);
	void rotar();
	void moverIzquierda(double tiempoDiferencial);
	void moverDerecha(double tiempoDiferencial);
	void subir(double tiempoDiferencial);
	void bajar(double tiempoDiferencial);
	void rapidez(double tiempoDiferencial);
	void retroceder(double tiempoDiferencial);
	vec3 getCoordenadas();

private:
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, -150.0f);
};
