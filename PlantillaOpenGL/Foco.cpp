#include "stdafx.h"
#include "Foco.h"


void Foco::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

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


}
