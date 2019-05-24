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
	void detenerse(double tiempoDiferencial);
	vec3 getCoordenadas();
	vec3 coordenadas = vec3(0.0f, 3.0f, -70.0f);
	int vida = 2;
	bool rotando = false;
	double tiempoAcumulado = 0;
	bool descanso = 0;

private:
	void actualizarMatrizModelo();
};
