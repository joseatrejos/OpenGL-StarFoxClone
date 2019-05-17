#include "stdafx.h"
#include "NaveStarFox.h"


void NaveStarFox::actualizarMatrizModelo() {

	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

void NaveStarFox::avanzar() {

	coordenadas.z += 0.01f;
	actualizarMatrizModelo();

}


NaveStarFox::NaveStarFox() {

	// x, y, z, opacidad

	//abajo izq
	//arriba izq
	//arriba der
	//abajo der


	//=============================== N A V E  S T A R  F O X ===============================
	
	//Parte Atras
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.6f, 0.4f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });




	//Parte media 1
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, -0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.6f, 0.4f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });




	//Parte media 2
	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });


	vertices.push_back({ vec4(0.5f, -0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });


	vertices.push_back({ vec4(0.2f, 0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, -0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.2f, 0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.3f, 0.2f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.2f, -0.4f, 0.3f, 1.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) });




	//Punta
	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.1f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.0f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.1f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, -0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, -0.2f, 1.0f),vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 0.3f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.1f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.1f, 0.2f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });




	//Cabina
	vertices.push_back({ vec4(-0.6f, 0.9f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.0f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.0f, 0.4f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.3f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });




	//Cuadro Detras De la cabina Grande
	vertices.push_back({ vec4(-0.7f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });


	vertices.push_back({ vec4(-0.7f, 0.9f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.9f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.2f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });




	//Cuadro Detras De la cabina Pequeño
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.8f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, -0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });


	vertices.push_back({ vec4(-0.8f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.8f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.6f, 0.1f, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f) });




	//pata
	vertices.push_back({ vec4(-0.6f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, -0.5f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, -0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.7f, 0.05f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });




	//Pata abajo
	vertices.push_back({ vec4(-0.7f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.4f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.5f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.4f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, -0.7f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, -0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.4f, -0.7f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.8f, 0.05f, 1.0f), vec4(0.1f, 0.1f, 0.1f, 1.0f) });




	//Triangulo 1
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.6f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, -0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });




	//Triangulo 2
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.6f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.6f,  -0.5f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.6f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, 0.9f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-0.8f, 0.9f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.5f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.6f,  -0.6f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.8f, -0.8f, 0.7f, 1.0f), vec4(0.5f, 0.0f, 0.0f, 1.0f) });




	//cuadrado
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });




	//Cuadrito 1
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, -0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, -1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, -1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });




	//Cuadrito 2
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.2f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.6f, 0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.1f, 0.8f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	vertices.push_back({ vec4(-0.7f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, 0.05f, 1.2f, 1.0f), vec4(0.0f, 0.5f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.6f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });
	vertices.push_back({ vec4(-0.7f, -0.05f, 1.2f, 1.0f), vec4(0.0f, 0.2f, 0.8f, 1.0f) });

	

}