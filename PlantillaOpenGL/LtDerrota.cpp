#include "stdafx.h"
#include "LtDerrota.h"

void LtDerrota::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, 3.14159f, vec3(0.0f, 1.0f, 0.0f));
	modelo = scale(modelo, vec3(2.0f, 2.0f, 2.0f));
}

LtDerrota::LtDerrota() {
	//============================= G A M E  O V E R ======================================
	//G
	vertices.push_back({ vec4(-0.5f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//A
	vertices.push_back({ vec4(-0.4f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.25f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.32f, 0.3f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.15f, 0.3f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//M
	vertices.push_back({ vec4(0.0f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.15f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.3f, 0.15f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.3f, 0.15f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.45f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//E
	vertices.push_back({ vec4(0.7f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.7f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.7f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.7f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.85f, 0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.7f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.9f, 0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//O
	vertices.push_back({ vec4(-0.8f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//V
	vertices.push_back({ vec4(-0.4f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.25f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//E
	vertices.push_back({ vec4(0.0f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.15f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//R
	vertices.push_back({ vec4(0.3f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.3f, -0.6f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.3f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f, -0.1f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.3f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.3f, -0.35f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f, -0.60f, 0.2f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	actualizarMatrizModelo();
}