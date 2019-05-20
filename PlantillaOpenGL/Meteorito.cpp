#include "stdafx.h"
#include "Meteorito.h"


void Meteorito::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

void Meteorito::avanzar() {

	coordenadas.z += 0.01f;
	actualizarMatrizModelo();

}

Meteorito::Meteorito() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//===========================================================METEORITO========================================================================
	
	//PARTE ALTA ARRIBA
	vertices.push_back({ vec4(0.25f, 0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, 0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, 0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.25f, 0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, 0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	//PARTE ALTA ARRIBA



	//PARTE MEDIA ARRIBA
	vertices.push_back({ vec4(0.35f, 0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, 0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, 0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.35f, 0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, 0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });



	//PARTE MEDIA ARRIBA



	//CUADRADO
	vertices.push_back({ vec4(0.5f, 0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f,  1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f,  1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.5f, -0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 1.0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, .0f, 1.0f),vec4(0.2f ,0.1f, 0.0f,1.0f) });
	//CUADRADO

	//CUADRADO Lateral derecho ultimo
	vertices.push_back({ vec4(0.9f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.9f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.25f, .6, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.9f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.9f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.9f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.9f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	//CUADRADO Lateral derecho ultimo


	//CUADRADO Lateral izq ultimo
	vertices.push_back({ vec4(-0.9f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.25f, .6, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.9f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, 0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.9f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.25f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.9f, -0.25f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	//CUADRADO Lateral izq ultimo

	//CUADRADO Lateral derecho
	vertices.push_back({ vec4(0.7f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.7f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.7f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.7f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.7f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.5f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.7f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	//CUADRADO Lateral derecho



	//CUADRADO Lateral izquierda
	vertices.push_back({ vec4(-0.7f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.7f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.35f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.35f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	//CUADRADO Lateral izquierda



	//CUADRADO INTERIOR ENFRENTE
	vertices.push_back({ vec4(0.35f, 0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, 0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.35f, -0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, 0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, 0.35f,  1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, -0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.35f,  1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.35f, 1.15f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.35f, 1.0f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	//CUADRADO INTERIOR ENFRENTE

	//CUADRADO INTERIOR ENFRENTE ENFRENTE
	vertices.push_back({ vec4(0.25f, 0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, -0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.25f, -0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, 0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, 0.25f,  1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, 0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, -0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.25f,  1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.25f, 1.25f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.25f, 1.15f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	//CUADRADO INTERIOR ENFRENTE ENFRENTE

	//PARTE MEDIA ARRIBA
	vertices.push_back({ vec4(0.35f, -0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, -0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, -0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.35f, -0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.5f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.5f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.35f, -0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.7f, .2f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.35f, -0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.35f, -0.7f, .8f, 1.0f),vec4(0.3f ,0.2f, 0.0f,1.0f) });

	//PARTE MEDIA Abajo



	//PARTE ALTA abajo
	vertices.push_back({ vec4(0.25f, -0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, -0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, -0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(-0.25f, -0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.7f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.7f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	vertices.push_back({ vec4(0.25f, -0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.9f, .4f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(-0.25f, -0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });
	vertices.push_back({ vec4(0.25f, -0.9f, .6f, 1.0f),vec4(0.4f ,0.3f, 0.0f,1.0f) });

	//PARTE ALTA Abajo
	
	//===========================================================METEORITO========================================================================
	//HITBOX
	//enfrente
	vertices.push_back({ vec4(-0.9f, 0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });

	//atras
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });

	//lateral der
	vertices.push_back({ vec4(0.9f, 0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });

	//lateral izq
	vertices.push_back({ vec4(-0.9f, 0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });

	//abajo
	vertices.push_back({ vec4(0.9f, -0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, -0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });

	//arriba
	vertices.push_back({ vec4(0.9f, 0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(0.9f, 0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 0.0f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });
	vertices.push_back({ vec4(-0.9f, 0.9f, 1.25f, 1.0f),vec4(0.0f ,0.0f, 0.0f,0.0f) });



	actualizarMatrizModelo();




}