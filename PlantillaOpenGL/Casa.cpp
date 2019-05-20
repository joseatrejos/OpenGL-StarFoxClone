#include "stdafx.h"
#include "Casa.h"


void Casa::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, -1.5708f, vec3(0.0f, -0.10f, 0.0f));
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



	//izquierda
	vertices.push_back({ vec4(-0.8f, 0.8f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, 0.8f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, -0.5f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, -0.5f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	//derecha
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, 0.8f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, -0.5f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, -0.5f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	//arriba
	vertices.push_back({ vec4(-0.8f, 0.8f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, 0.8f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, 0.8f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	//abajo
	vertices.push_back({ vec4(-0.8f, -0.5f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, -0.5f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, -0.5f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, -0.5f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	//atras
	vertices.push_back({ vec4(-0.8f, 0.8f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, -0.5f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(-0.8f, -0.5f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	//enfrente
	vertices.push_back({ vec4(0.8f, 0.8f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, 0.8f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, -0.5f, -0.7f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });
	vertices.push_back({ vec4(0.8f, -0.5f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100, 0.0f) });




	actualizarMatrizModelo();
}