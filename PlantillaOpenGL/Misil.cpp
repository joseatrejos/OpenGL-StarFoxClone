#include "stdafx.h"
#include "Misil.h"


void Misil::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

void Misil::avanzar() {

	coordenadas.z += 0.01f;
	actualizarMatrizModelo();

}

Misil::Misil() {

	// x, y, z, opacidad

	//abajo izq
	//arriba izq
	//arriba der
	//abajo der

	//=============================== M I S I L ==========================================
	
	//Parte delantera cuadro de fondo
	vertices.push_back({ vec4(0.2f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Parte delantera cuadro de encima
	vertices.push_back({ vec4(0.2f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.05f, 0.3f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Parte delantera cuadro izquierda
	vertices.push_back({ vec4(0.2f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Parte delantera cuadro derecha
	vertices.push_back({ vec4(1.0f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.05f, 0.3f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Parte delantera cuadro Base
	vertices.push_back({ vec4(0.2f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, -0.05f, 0.3f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, -0.05f, 0.1f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Parte delantera cuadro Tapa
	vertices.push_back({ vec4(0.2f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.05f, 0.3f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.05f, 0.1f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });





	//Union cuadro fondo
	vertices.push_back({ vec4(0.0f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });

	//Union cuadro encima
	vertices.push_back({ vec4(0.0f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });

	//Union cuadro izquierda
	vertices.push_back({ vec4(0.0f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });

	//Union cuadro Base
	vertices.push_back({ vec4(0.0f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });

	//Union cuadro Tapa
	vertices.push_back({ vec4(0.0f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.2f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.2f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 0.0f, 1.0f) });




	//Rectangulo grande Fondo
	vertices.push_back({ vec4(-0.9f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });

	//Rectangulo grande Fondo
	vertices.push_back({ vec4(-0.9f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });

	//Rectangulo grande Izq
	vertices.push_back({ vec4(-0.9f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });

	//Rectangulo grande Der
	vertices.push_back({ vec4(0.0f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });

	//Rectangulo grande Base
	vertices.push_back({ vec4(-0.9f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });

	//Rectangulo grande Tapa
	vertices.push_back({ vec4(-0.9f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.3f, 0.0f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.3f, 0.4f, 1.0f), vec4(0.0f, 0.3f, 1.0f, 1.0f) });





	//Rectangulo Cola Fondo
	vertices.push_back({ vec4(-1.0f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Rectangulo Cola Encima
	vertices.push_back({ vec4(-1.0f, -0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Rectangulo Cola Izq
	vertices.push_back({ vec4(-1.0f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, -0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Rectangulo Cola Der
	vertices.push_back({ vec4(-0.9f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Rectangulo Cola Tapa
	vertices.push_back({ vec4(-1.0f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	//Rectangulo Cola Tapa
	vertices.push_back({ vec4(-1.0f, -0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.4f, 0.0f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.4f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.0f, 1.0f) });

	

}
