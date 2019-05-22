#include "stdafx.h"
#include "NaveStarFox.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void NaveStarFox::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, -1.5708f, vec3(0.0f, 1.0f, 0.0f));
	modelo = scale(modelo, vec3(0.9f, 0.65f, 0.9f));
}

vec3 NaveStarFox::getCoordenadas() {
	return coordenadas;
}

void NaveStarFox::avanzar(double tiempoDiferencial) {
	coordenadas.z += 5.0 * tiempoDiferencial;
	actualizarMatrizModelo();
}

void NaveStarFox::rapidez(double tiempoDiferencial) {
	coordenadas.z += 50.0 * tiempoDiferencial;
	actualizarMatrizModelo();
}

void NaveStarFox::rotar() {
	modelo = rotate(modelo, -1.5708f, vec3(1.0f, 0.0f, 0.0f));
	rotando = true;
}

void NaveStarFox::moverIzquierda(double tiempoDiferencial) {
	if (coordenadas.x <= 10.0f)
	{
		coordenadas.x += 4.0 * tiempoDiferencial;
		actualizarMatrizModelo();
		modelo = rotate(modelo, -.57f, vec3(1.0f, 0.0f, 0.0f));
		modelo = rotate(modelo, .57f, vec3(0.0f, 1.0f, 0.0f));
	}
}

void NaveStarFox::moverDerecha(double tiempoDiferencial) {
	if (coordenadas.x >= -10.0f)
	{
		coordenadas.x -= 4.0 * tiempoDiferencial;
		actualizarMatrizModelo();
		modelo = rotate(modelo, .57f, vec3(1.0f, 0.0f, 0.0f));
		modelo = rotate(modelo, -.57f, vec3(0.0f, 1.0f, 0.0f));
	}
}

void NaveStarFox::subir(double tiempoDiferencial) {
	if (coordenadas.y <= 5.0f)
	{
		coordenadas.y += 4.0 * tiempoDiferencial;
		actualizarMatrizModelo();
		modelo = rotate(modelo, 0.385f, vec3(0.0f, 0.0f, 1.0f));
	}
}

void NaveStarFox::bajar(double tiempoDiferencial) {
	if (coordenadas.y >= -2.5f)
	{
		coordenadas.y -= 5.0 * tiempoDiferencial;
		actualizarMatrizModelo();
		modelo = rotate(modelo, 0.385f, vec3(0.0f, 0.0f, -1.0f));
	}
}

void NaveStarFox::retroceder(double tiempoDiferencial) {
	coordenadas.z -= 10.0 * tiempoDiferencial;
	actualizarMatrizModelo();
}

NaveStarFox::NaveStarFox() {
	//=============================== N A V E  S T A R  F O X ===============================
	//Parte Atras
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	//Parte media 1
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Parte media 2
	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, -0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Punta
	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.1f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.0f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.1f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, -0.2f, 1.0f),vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	//Cabina
	vertices.push_back({ vec4(-0.6f, 0.9f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	//Cuadro Detras De la cabina Grande
	vertices.push_back({ vec4(-0.7f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	//Cuadro Detras De la cabina Pequeño
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	//pata
	vertices.push_back({ vec4(-0.6f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	//Pata abajo
	vertices.push_back({ vec4(-0.7f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.4f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.4f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	//Triangulo 1
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.6f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	//Triangulo 2
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.6f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	//cuadrado
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	//Cuadrito 1
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	//Cuadrito 2
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	/*hit box
	//parte izquierda
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//parte derecha
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//parte arriba
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//parte abajo
	vertices.push_back({ vec4(-0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//parte atras
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//parte enfrente
	vertices.push_back({ vec4(0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });*/

	actualizarMatrizModelo();
}