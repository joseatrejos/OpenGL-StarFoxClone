#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include "Carro.h"
#include "NaveStarFox.h"
#include "Misil.h"
#include "Bala.h"
#include "Meta.h"
#include "Meteorito.h"
#include "NaveEnemiga.h"
#include "Casa.h"
#include "Foco.h"
#include "Modelo.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

using namespace std;

void establecerVista();







Shader* shader;
GLuint posicionID;
GLuint colorID;
GLuint modeloID;
GLuint vistaID;
GLuint proyeccionID;

mat4 vista;
mat4 proyeccion;

Carro* carro;
NaveStarFox* naveStarFox;
Misil* misil;
Bala* bala;
Meta* meta;
Meteorito* meteorito;
NaveEnemiga* naveEnemiga;
Casa* casa;
Foco* foco;

//Declaramos apuntador de ventana
GLFWwindow* window;

GLfloat ancho = 1024.0f;
GLfloat alto = 768.0f;

vec3 posicionCamara = vec3(3.0f, 1.5f, 7.0f);

bool rotado = false;

int renderBala = 0;

void establecerVista() {

	vec3 posicionCamara = naveStarFox->getCoordenadas();
	posicionCamara.z -= 3.2;
	posicionCamara.y += 1.5	;

	vista = lookAt(
		posicionCamara,  //Posicion de la camara
		naveStarFox->getCoordenadas(),    //Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f)     //Vector hacia arriba
	);

	if (naveStarFox != NULL) {
		naveStarFox->vista = vista;
	}
	if (casa != NULL) {
		casa->vista = vista;
	}
	if (misil != NULL) {
		misil->vista = vista;
	}
	if (bala != NULL) {
		bala->vista = vista;
	}
	if (meta != NULL) {
		meta->vista = vista;
	}
	if (meteorito != NULL) {
		meteorito->vista = vista;
	}
	if (naveEnemiga != NULL) {
		naveEnemiga->vista = vista;
	}
	if (foco != NULL) {
		foco->vista = vista;
	}

}




void establecerProyeccion() {

	proyeccion = perspective(
		90.0f,       //Campo de vision (FoV)
		ancho / alto,  //Relación de aspecto (Aspect Ratio)
		0.1f,        //Near clipping (Desde donde renderea)
		150.0f       //Far clipping (Hasta donde renderea)
	);

}

void dibujar() {

	//carro->dibujar(GL_QUADS);
	casa->dibujar(GL_QUADS);
	naveStarFox->dibujar(GL_QUADS);
	naveEnemiga->dibujar(GL_QUADS);
	/*misil->dibujar(GL_QUADS);
	meta->dibujar(GL_QUADS);
	meteorito->dibujar(GL_QUADS);
	
	foco->dibujar(GL_QUADS);
	*/
}

void actualizar() {
	naveEnemiga->avanzar();
	naveStarFox->avanzar();
	establecerVista();

	int estadoEspacio = glfwGetKey(window, GLFW_KEY_SPACE);
	if (estadoEspacio == GLFW_PRESS) {
		naveStarFox->rotar();
	}

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		naveStarFox->moverIzquierda();
	}

	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		naveStarFox->moverDerecha();
	}

	int estadoAtras = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAtras == GLFW_PRESS) {
		naveStarFox->retroceder();
	}

	int estadoDisparar = glfwGetKey(window, GLFW_KEY_Z);
	if(estadoDisparar == GLFW_PRESS)
	{
		renderBala = 0;
		
	}

	if (renderBala == 0)
	{
		for (int x = 0; x < 52000; x++)
		{
			bala->dibujar(GL_QUADS);
		}
		renderBala = 1;
	}
}

void inicializarModelos()
{
	/*//Inicializar modelo y establecer shader
	carro = new Carro();
	carro->vista = vista;
	carro->proyeccion = proyeccion;
	carro->shader = shader;
	carro->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);*/

	//inicializacion casa
	casa = new Casa();
	casa->vista = vista;
	casa->proyeccion = proyeccion;
	casa->shader = shader;
	casa->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion nave
	naveStarFox = new NaveStarFox();

	naveStarFox->proyeccion = proyeccion;
	naveStarFox->shader = shader;
	naveStarFox->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	establecerVista();
	naveStarFox->vista = vista;
	establecerVista();
	naveStarFox->vista = vista;

	//inicializacion misil
	misil = new Misil();
	misil->vista = vista;
	misil->proyeccion = proyeccion;
	misil->shader = shader;
	misil->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion bala
	bala = new Bala();
	bala->vista = vista;
	bala->proyeccion = proyeccion;
	bala->shader = shader;
	bala->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meta
	meta = new Meta();
	meta->vista = vista;
	meta->proyeccion = proyeccion;
	meta->shader = shader;
	meta->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meteorito
	meteorito = new Meteorito();
	meteorito->vista = vista;
	meteorito->proyeccion = proyeccion;
	meteorito->shader = shader;
	meteorito->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializar nave enemiga
	naveEnemiga = new NaveEnemiga();
	naveEnemiga->vista = vista;
	naveEnemiga->proyeccion = proyeccion;
	naveEnemiga->shader = shader;
	naveEnemiga->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco
	foco = new Foco();
	foco->vista = vista;
	foco->proyeccion = proyeccion;
	foco->shader = shader;
	foco->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

int main()
{

	//Si no se pudo iniciar glfw
	//terminamos ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido  el contexto
	//Activamos funciones modernas
	glewExperimental = true;

	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;


	const char* rutaVertex = "VertexShader.shader";
	const char* rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	modeloID = glGetUniformLocation(shader->getID(), "modelo");
	vistaID = glGetUniformLocation(shader->getID(), "vista");
	proyeccionID = glGetUniformLocation(shader->getID(), "proyeccion");

	//Desenlazar el shader
	shader->desenlazar();


	establecerProyeccion();

	inicializarModelos();

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Esablecer region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(1, 0.2, 0.5, 1);

		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}


