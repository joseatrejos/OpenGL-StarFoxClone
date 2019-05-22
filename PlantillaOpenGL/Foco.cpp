#include "stdafx.h"
#include "Foco.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void Foco::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = scale(modelo, vec3(0.4f, 0.4f, 0.4f));
}

void Foco::avanzar() {
	coordenadas.z += 0.01f;
	actualizarMatrizModelo();
}

Foco::Foco() {
	//============================ F O C O ====================================
	vertices.push_back({ vec4(-0.5f, 0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.5f, -2.0f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -2.0f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -2.0f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -2.0f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, -2.0f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -2.0f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -2.0f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -2.0f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 1.0f,1.0f) });

	vertices.push_back({ vec4(-0.5f, 0.5f, -0.7f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, -2.0f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -2.0f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, -0.7f, 1.0f),vec4(0.6f ,1.0f, 1.0f,1.0f) });

	vertices.push_back({ vec4(0.5f, -0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, -2.0f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -2.0f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.7f, 1.0f),vec4(1.0f ,1.0f, 0.6f,1.0f) });

	//Sostenedor
	vertices.push_back({ vec4(-0.2f, -0.5f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.5f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.9f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.9f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.5f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.5f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.9f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.9f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.5f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.5f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.9f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.9f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.2f, -0.5f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.5f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.9f, -1.7f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.2f, -0.9f, -1.0f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	//Palito
	vertices.push_back({ vec4(-0.5f, -0.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -2.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -2.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -2.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -2.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -2.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -2.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });

	vertices.push_back({ vec4(0.5f, -0.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -2.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -2.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.5f, -2.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.84f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -2.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -2.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -2.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.9f, -1.8f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.9f, -0.9f, 1.0f),vec4(0.1f ,0.1f, 0.4f,1.0f) });

	actualizarMatrizModelo();
}
