#include "stdafx.h"
#include "Meta.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

void Meta::actualizarMatrizModelo() {
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	modelo = scale(modelo, vec3(2.5f, 2.45f, 15.0f));
}

void Meta::avanzar() {
	coordenadas.z += 0.01f;
	actualizarMatrizModelo();
}

Meta::Meta() {
	//=============================== M E T A =============================================
	
	//PILAR IZQUIERDO
	//Pilar izquierdo rectangulo centro abajo
	vertices.push_back({ vec4(-0.45f, 0.0f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.0f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Pilar izquierdo rectangulo centro encima
	vertices.push_back({ vec4(-0.45f, 0.0f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.0f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Pilar izquierdo rectangulo izq
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.0f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.0f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Pilar izquierdo rectangulo der
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.0f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.0f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });


	//PILAR DERECHO
	//Pilar derecho rectangulo centro abajo ()
	vertices.push_back({ vec4(0.45f, 0.0f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.0f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Pilar derecho rectangulo centro encima ()
	vertices.push_back({ vec4(0.45f, 0.0f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.0f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Pilar derecho rectangulo izq ()
	vertices.push_back({ vec4(0.45f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.0f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.0f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Pilar derecho rectangulo der ()
	vertices.push_back({ vec4(0.25f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.0f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.0f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });


	//CUADRITO ESQUINA IZQUIERDA
	//Cuadro esquina izquierda centro fondo
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Cuadro esquina izquierda centro fondo
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Cuadro esquina izquierda cuadro izq
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.45f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Cuadro esquina izquierda cuadro der
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });


	//CUADRITO ESQUINA DERECHA
	//Cuadro esquina derecha centro fondo
	vertices.push_back({ vec4(0.45f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Cuadro esquina derecha centro fondo
	vertices.push_back({ vec4(0.45f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Cuadro esquina derecha cuadro izq
	vertices.push_back({ vec4(0.45f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.45f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Cuadro esquina derecha cuadro der
	vertices.push_back({ vec4(0.15f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.25f, 0.4f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });


	//RECTANGULO ARRIBA
	//Rectangulo arriba centro fondo
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.0f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Rectangulo arriba centro encima
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//Rectangulo arriba abajo base
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.15f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.15f, 0.5f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	//Rectangulo arriba arriba techo
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.6f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.0f, 0.5f, 1.0f) });

	actualizarMatrizModelo();
}