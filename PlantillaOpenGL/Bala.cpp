#include "stdafx.h"
#include "Bala.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void Bala::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, -1.5708f, vec3(0.0f, 1.0f, 0.0f));
}

void Bala::aparecer(vec3 coordenadasNaveStarFox) {
	balaDisparada = true;
	distanciaRecorrida = 0;
	coordenadas = coordenadasNaveStarFox + vec3(0.17f, -0.05f, 1.4f);
	actualizarMatrizModelo();
}

void Bala::avanzar(double tiempoDiferencial) {
	coordenadas.z += 75.0f * (float)tiempoDiferencial;
	actualizarMatrizModelo();

	distanciaRecorrida += 75.0 * tiempoDiferencial;
	// Al exceder la distancia máxima, la desaparecemos y reiniciamos la distancia
	if (distanciaRecorrida >= 40)
	{
		distanciaRecorrida = 0;
		balaDisparada = false;
		renderearBala = true;
	}
}

Bala::Bala() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//=============================== B A L A ============================================
	//Cuadro Fondo
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Delante
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.3f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Izquierda
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Cuadro Derecha
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Base
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Tapa
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.3f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//hit box
	//izquierda
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(0.9f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	//derecha
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(0.9f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	//arriba
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(0.9f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(0.9f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	//abajo
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	//atrtas
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 0.0f) });
	//enfrente 
	vertices.push_back({ vec4(0.9f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 0.0f) });

	actualizarMatrizModelo();
}