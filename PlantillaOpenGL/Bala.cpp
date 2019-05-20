#include "stdafx.h"
#include "Bala.h"
#include "NaveStarFox.h"


void Bala::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = rotate(modelo, -1.5708f, vec3(0.0f, 1.0f, 0.0f));
	modelo = translate(modelo, coordenadas);
	//modelo = scale();
}

void Bala::aparecer(vec3 coordenadasNaveStarFox) {
	modelo = translate(modelo, coordenadasNaveStarFox);
}

void Bala::tiempovida() {
	double tiempo = glfwGetTime();
	if (tiempo <= 5)
	{
		tiempo = glfwGetTime();
	}
}

void Bala::avanzar() {
	coordenadas.z += 0.04f;
	actualizarMatrizModelo();
}

Bala::Bala() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// x, y, z, opacidad

	//abajo izq
	//arriba izq
	//arriba der
	//abajo der


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

