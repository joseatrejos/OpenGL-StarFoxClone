#include "stdafx.h"
#include "Bala.h"


void Bala::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, -1.5708f, vec3(0.0f, 1.0f, 0.0f));
}

void Bala::aparecer() {
	/*coordenadas.x += ;
	coordenadas.z += */;
}

void Bala::avanzar() {
	coordenadas.z += 0.01f;
	actualizarMatrizModelo();
}

Bala::Bala() {
	// x, y, z, opacidad

	//abajo izq
	//arriba izq
	//arriba der
	//abajo der


	//=============================== B A L A ============================================
	
	//Cuadro Fondo
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Delante
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Izquierda
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Cuadro Derecha
	vertices.push_back({ vec4(0.9f, 0.05f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Base
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, -0.05f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	//Cuadro Tapa
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.05f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f) });

	actualizarMatrizModelo();
	aparecer();
}

