#include "stdafx.h"
#include "Background.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void Background::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = scale(modelo, vec3(3.5f, 2.45f, 15.0f));
}

vec3 Background::getCoordenadas() {
	return coordenadas;
}

Background::Background() {

	vertices.push_back({ vec4(-70.0f, -0.75f, -70.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(70.0f, -0.75f, -70.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(70.0f, -0.75f, 70.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-70.0f, -0.75f, 70.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) });

	actualizarMatrizModelo();
}