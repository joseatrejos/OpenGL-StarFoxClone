#include "stdafx.h"
#include "NaveEnemiga.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void NaveEnemiga::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, 1.5708f, vec3(0.0f, 1.0f, 0.0f));
	modelo = scale(modelo, vec3(1.0f, 1.0f, 1.0f));
}

void NaveEnemiga::avanzar() {
	coordenadas.z += 0.01f;
	actualizarMatrizModelo();
}

vec3 NaveEnemiga::getCoordenadas()
{
	return coordenadas;
}

NaveEnemiga::NaveEnemiga() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//================================================NAVE ENEMIGA=============================================================

	//Capsula
	vertices.push_back({ vec4(-0.6f, 0.5f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.1f, -0.1f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.4f, -0.1f, -0.1f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(0.4f, 0.1f, -0.1f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.4f, -0.1f, -0.1f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.4f, -0.1f, 0.1f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.1f, 0.1f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.4f, -0.1f, -0.1f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.4f, -0.1f, 0.1f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.8f,1.0f) });

	vertices.push_back({ vec4(0.4f, 0.1f, -0.1f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.1f, 0.1f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.5f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.5f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.8f,1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.5f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.5f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.5f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.1f, 0.1f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.4f, -0.1f, 0.1f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	//Ala 1
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.8f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, -0.4f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, -0.4f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, -0.8f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.1f, 0.9f, -0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, -0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(0.1f, 0.0f, -0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, -0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, -0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(0.1f, 0.9f, -0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, -0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.9f, -0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, -0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, -0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, -0.5f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, -0.5f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, -0.9f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });

	//Ala 2
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.8f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, 0.4f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, 0.4f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, 0.8f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.1f, 0.9f, 0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, 0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(0.1f, 0.0f, 0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, 0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, 0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(0.1f, 0.9f, 0.4f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, 0.5f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.9f, 0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, 0.8f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, 0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4(0.0f ,0.2f, 0.4f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.9f, 0.5f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f, 0.5f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.8f, 0.9f, 1.0f),vec4(0.2f ,0.0f, 0.0f,1.0f) });


	//Cuadrado grande cañon
	vertices.push_back({ vec4(-0.1f, 0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(0.3f, -0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, 0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, -0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, 0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(-0.3f, 0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.1f, -0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	//Cuadrado grande cañon 2
	vertices.push_back({ vec4(-0.1f, 0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(0.3f, -0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, 0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.1f, 0.24f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, 0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	vertices.push_back({ vec4(-0.3f, 0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });
	vertices.push_back({ vec4(-0.3f, -0.1f, 0.34f, 1.0f),vec4(0.2f ,0.2f, 0.2f,1.0f) });

	//Cuadrado pequeño cañon
	vertices.push_back({ vec4(0.3f, 0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.5f, -0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, -0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, -0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	//Cuadrado pequeño cañon 2
	vertices.push_back({ vec4(0.3f, 0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.5f, -0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, 0.32f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, 0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	vertices.push_back({ vec4(0.3f, 0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });
	vertices.push_back({ vec4(0.3f, -0.05f, 0.26f, 1.0f),vec4(0.1f ,0.1f, 0.1f,1.0f) });

	//Cuadreado que sostiene entre la capsula y el ala
	vertices.push_back({ vec4(-0.2f, 0.2f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.2f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.2f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.5f, -0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.1f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.4f, -0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.2f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.5f, -0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.5f, -0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.2f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.2f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.4f, -0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.5f, -0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.5f, -0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.5f, -0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.4f, -0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	//Cuadreado que sostiene entre la capsula y el ala
	vertices.push_back({ vec4(-0.2f, 0.2f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.2f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.2f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.1f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.5f, 0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.1f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.4f, 0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.2f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.5f, 0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.5f, 0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.2f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.2f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.3f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.4f, 0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.5f, 0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.1f, 0.5f, 0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.5f, 0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.45f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.4f, 0.55f, 1.0f),vec4(0.1f ,0.2f, 0.9f,1.0f) });

	/*hit box
	//parte izquierda
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	//parte derecha
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	//parte arriba
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	//parte abajo
	vertices.push_back({ vec4(-0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	//parte atras
	vertices.push_back({ vec4(-0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	//parte enfrente
	vertices.push_back({ vec4(0.9f, 0.9f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, 0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f, -0.9f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,0.0f) });*/
	
	actualizarMatrizModelo();
}