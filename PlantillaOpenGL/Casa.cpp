#include "stdafx.h"
#include "Casa.h"


void Casa::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

void Casa::avanzar() {

	coordenadas.z += 0.01f;
	actualizarMatrizModelo();

}

Casa::Casa() {


	//=============================== C A S A ========================================== //

	//Techo
	vertices.push_back({ vec4(-0.5f, 0.8f, -0.7f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.8f, -0.7f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.8f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.8f, -2.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.8f, -2.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.8f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.8f, -2.0f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.5f, -2.0f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.8f, -2.0f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.8f, 0.5f, -2.0f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.8f, 0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.8f, -0.7f, 1.0f), vec4(0.7f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.8f, -2.0f, 1.0f), vec4(0.7f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.8f, -2.0f, 1.0f), vec4(0.7f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.8f, -0.7f, 1.0f), vec4(0.7f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.8f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.8f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f) });



	//base
	vertices.push_back({ vec4(-0.5f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -0.7f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.7f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -2.0f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -2.0f, 1.0f), vec4(1.0f, 0.7f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -2.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.7f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, -0.7f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -2.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -2.0f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -0.7f, 1.0f), vec4(1.0f, 0.5f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, -0.5f, -0.7f, 1.0f), vec4(1.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -2.0f, 1.0f), vec4(1.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -2.0f, 1.0f), vec4(1.0f, 0.3f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.7f, 1.0f), vec4(1.0f, 0.3f, 0.0f, 1.0f) });



}