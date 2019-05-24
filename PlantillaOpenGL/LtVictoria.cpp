#include "stdafx.h"
#include "LtVictoria.h"


void LtVictoria::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = scale(modelo, vec3(30.0f, 30.0f, 20.0f));
	modelo = rotate(modelo, 3.14159f, vec3(0.0f, 1.0f, 0.0f));
}



LtVictoria::LtVictoria() {

	// x, y, z, opacidad

	//abajo izq
	//arriba izq
	//arriba der
	//abajo der

	//================================ Y O U  W I N ======================================

	//Y
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.45f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.3f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.45f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//O
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.1f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.1f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//U
	vertices.push_back({ vec4(0.2f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//W
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.45f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.3f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.15f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.15f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//I
	vertices.push_back({ vec4(0.1f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });


	//N
	vertices.push_back({ vec4(0.2f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });



}