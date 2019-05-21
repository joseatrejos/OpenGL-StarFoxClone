#include "stdafx.h"
#include "Edificio.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void Edificio::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = scale(modelo, vec3(18.0f, 4.0f, 18.0f));
}

Edificio::Edificio() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//=====================EDIFICIO=========================
	//CUADRADO
	vertices.push_back({ vec4(0.5f, 0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f,  1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f,  1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });

	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.4f, 0.7f,1.0f) });
	//CUADRADO

	//2do Cuadrado
	vertices.push_back({ vec4(-0.45f, 4.5f, 0.8f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.45f, 3.5f,  0.8f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f,  0.8f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f,  0.8f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });

	vertices.push_back({ vec4(0.45f, 3.5f,  0.8f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f,  0.8f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f,  0.2f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 3.5f,  0.2f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });

	vertices.push_back({ vec4(0.45f, 0.5f,  0.8f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f,  0.2f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f,  0.2f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f,  0.8f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });

	vertices.push_back({ vec4(0.45f, 3.5f,  0.8f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 3.5f,  0.2f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 4.5f, 0.2f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 4.5f, 0.8f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.45f, 4.5f, 0.8f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f,  0.8f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f,  0.2f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 4.5f, 0.2f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });

	vertices.push_back({ vec4(-0.45f, 4.5f, 0.2f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });
	vertices.push_back({ vec4(0.45f, 3.5f,  0.2f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f,  0.2f, 1.0f),vec4(0.0f ,0.5f, 0.8f,1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f,  0.2f, 1.0f),vec4(0.0f ,0.6f, 0.9f,1.0f) });

	//2do cuadrado

	vertices.push_back({ vec4(-0.4f, 4.25f, 0.7f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.4f, 4.5f,  0.7f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.5f,  0.7f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f,  0.7f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });

	vertices.push_back({ vec4(0.4f, 4.5f,  0.7f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.5f,  0.7f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.5f,  0.3f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 4.5f,  0.3f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });


	vertices.push_back({ vec4(0.4f, 0.5f,  0.7f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.5f,  0.3f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f,  0.3f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f,  0.7f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });

	vertices.push_back({ vec4(0.4f, 4.5f,  0.7f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 4.5f,  0.3f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 4.25f, 0.3f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 4.25f, 0.7f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });

	vertices.push_back({ vec4(-0.4f, 4.25f, 0.7f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f,  0.7f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f,  0.3f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 4.25f, 0.3f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });

	vertices.push_back({ vec4(-0.4f, 4.25f, 0.3f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });
	vertices.push_back({ vec4(0.4f, 4.5f,  0.3f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(0.4f, 0.5f,  0.3f, 1.0f),vec4(0.0f ,0.4f, 0.6f,1.0f) });
	vertices.push_back({ vec4(-0.4f, 0.5f,  0.3f, 1.0f),vec4(0.0f ,0.5f, 0.7f,1.0f) });

	//hitbox
	//frente
	vertices.push_back({ vec4(-0.5f, 4.5f, 1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, 4.5f,  1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	//atras
	vertices.push_back({ vec4(-0.5f, 4.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, 4.5f,  .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	//lateral der
	vertices.push_back({ vec4(0.5f, 4.5f,  1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, 4.5f,  .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	//lateral izq
	vertices.push_back({ vec4(-0.5f, 4.5f, 1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, 4.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	//arriba
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	//abajo
	vertices.push_back({ vec4(0.5f, 4.5f,  1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.5f, 4.5f,  .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, 4.5f, 1.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.5f, 4.5f, .0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	//hitbox
	//=====================EDIFICIO=========================

	actualizarMatrizModelo();
}