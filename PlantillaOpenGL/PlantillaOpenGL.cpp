#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "Shader.h"
#include "Vertice.h"

#include "Edificio.h"
#include "NaveStarFox.h"
#include "Misil.h"
#include "Bala.h"
#include "Meta.h"
#include "Meteorito.h"
#include "NaveEnemiga.h"
#include "Casa.h"
#include "Foco.h"
#include "Background.h"
#include "Modelo.h"

#include "LtDerrota.h"
#include "LtVictoria.h"

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#include <windows.h>

#include <glm/irrKlang.h>
#pragma comment(lib, "irrKlang.lib")

using namespace std;

// ============================================= Prototipos =============================================
void dibujar(), actualizar(), establecerVista(), establecerProyeccion(), inicializarModelos(), botones(),
disparar(), destruirObstaculos(), destruirNaveStarFox(), victoriaDerrota(),
teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// Inicialización de Modelos
void inicializarNaveStarFox(), inicializarNavesEnemigas(), inicializarCasas(), inicializarEdificios(),
inicializarFocos(), inicializarMeteoritos(), inicializarMisilBalaMeta(), inicializarBackground(),inicializarLetreros();

// Establecimiento de Vista de Modelos
void vistaNaveStarFox(), vistaNavesEnemigas(), vistaCasas(), vistaEdificios(), vistaFocos(),
vistaMeteoritos(), vistaMisilBalaMeta(), vistaBackground(), vistaLetreros();

// Dibujado de Modelos
void dibujarNaveStarFox(), dibujarNavesEnemigas(), dibujarCasas(), dibujarEdificios(), dibujarFocos(),
dibujarMeteoritos(), dibujarMeta(), dibujarBackground();

// ============================================= Variables =============================================
Shader* shader;
GLuint posicionID, colorID, modeloID;
GLuint vistaID, proyeccionID;
GLfloat ancho = 1024.0f, alto = 768.0f;
vec3 posicionCamara = vec3(3.0f, 1.5f, 7.0f);
mat4 vista, proyeccion;

bool rotado = false;
//bool sonidoAcelerado = false;
int cancion = 1; 
bool cancionEstado = false;
bool cancionFinalEstado = false;
double tiempoAnterior = 0.0f, tiempoActual = 0.0f, tiempoDiferencial = 0.0f;
double tiempoAcumulado = 0.0f;

// Objetos
NaveStarFox* naveStarFox; Meta* meta; Misil* misil; Bala* bala;
NaveEnemiga* naveEnemigaAbajoDerecha; NaveEnemiga* naveEnemigaMedioDerecha; NaveEnemiga* naveEnemigaArribaIzquierda;
Casa* casaAbajoDerecha; Casa* casaArribaIzquierda; Casa* casaArribaDerecha; Casa* casaAbajoIzquierda;
Foco* foco; Foco* foco2; Foco* foco3; Foco* foco4; Foco* foco5; Foco* foco6; Foco* foco7; Foco* foco8; Foco* foco9; Foco* foco10; 
Foco* foco11; Foco* foco12;
Edificio* edificioAbajoDerecha; Edificio* edificioAbajoIzquierda; Edificio* edificioArribaIzquierda; Edificio* edificioArribaDerecha; 
Meteorito* meteorito1; Meteorito* meteorito2; Meteorito* meteorito3; Meteorito* meteorito4; Meteorito* meteorito5; Meteorito* meteorito6;
Background* suelo;
LtVictoria* ltVictoria;
LtDerrota* ltDerrota;

// Start the sound engine with default parameters
irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
// Puntero para reproducir y modificar volumen y demás valores. Parametros: 1. Loop; 2. StartPaused; 3. Track
irrklang::ISound* snd = engine->play2D("..\\Music\\musicaFondo.wav", true, false, true);

// Declaramos apuntador de ventana
GLFWwindow* window;

// =========================================== Main Source Code ===========================================
int main()
{
	cancionEstado = true;
	if (snd)
	{
		snd->setVolume(0.09f);
	}

	// Si no se pudo iniciar glfw, terminamos ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// Si se pudo iniciar GLFW, entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "StarFox Clone", NULL, NULL);

	// Si no podemos iniciar la ventana, entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Establecemos el contexto
	glfwMakeContextCurrent(window);

	// Una vez establecido  el contexto, activamos funciones modernas
	glewExperimental = true;

	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	glfwSetKeyCallback(window, teclado_callback);

	const char* rutaVertex = "VertexShader.shader";
	const char* rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	// Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	modeloID = glGetUniformLocation(shader->getID(), "modelo");
	vistaID = glGetUniformLocation(shader->getID(), "vista");
	proyeccionID = glGetUniformLocation(shader->getID(), "proyeccion");

	// Desenlazar el shader
	shader->desenlazar();

	establecerProyeccion();
	inicializarModelos();

	tiempoAnterior = glfwGetTime();

	// Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		// Establecer region de dibujo
		glViewport(0, 0, 1024, 768);

		// Establece el color de borrado
		glClearColor(0.6, 1.0, 1.0, 1);

		// Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Rutina de dibujo
		dibujar();
		actualizar();

		// Cambiar los buffers
		glfwSwapBuffers(window);

		// Reconocer si hay entradas
		glfwPollEvents();
	}

	engine->drop(); // Delete engine

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void dibujar() {
	dibujarNaveStarFox();
	dibujarNavesEnemigas();
	dibujarCasas();
	dibujarEdificios();
	dibujarFocos();
	dibujarMeteoritos();
	dibujarMeta();
	dibujarBackground();
}

void actualizar() {
	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;
 
	if (cancion % 2 == 1 && !cancionEstado && !cancionFinalEstado)
	{
		engine->removeAllSoundSources();
		// Parametros: 1. Loop; 2. StartPaused; 3. Track
		irrklang::ISound* snd = engine->play2D("..\\Music\\musicaFondo.wav", true, false, true);
		if (snd)
		{
			snd->setVolume(0.09f);
		}
		cancionEstado = true;
	}
	else if (cancion % 2 == 0 && !cancionEstado && !cancionFinalEstado)
	{
		engine->removeAllSoundSources();
		// Parametros: 1. Loop; 2. StartPaused; 3. Track
		irrklang::ISound* snd = engine->play2D("..\\Music\\musicaFondo2.wav", true, false, true);
		if (snd)
		{
			snd->setVolume(0.09f);
		}
		cancionEstado = true;
	}

	if(naveStarFox->vida > 0)
	{ 
		naveStarFox->avanzar(tiempoDiferencial);
		disparar();
	}
	destruirObstaculos();
	destruirNaveStarFox();
	victoriaDerrota();

	establecerVista();

	botones();
	tiempoAnterior = tiempoActual;
}

// Key Callbacks
void botones()
{
	int estadoEspacio = glfwGetKey(window, GLFW_KEY_SPACE);
	if (estadoEspacio == GLFW_PRESS) {
		naveStarFox->rotar();
	}else
		naveStarFox->rotando = false;

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS && naveStarFox->vida == 2) {
		naveStarFox->moverIzquierda(tiempoDiferencial);
	}

	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS && naveStarFox->vida == 2) {
		naveStarFox->moverDerecha(tiempoDiferencial);
	}
	/*
	int estadoRetrocer = glfwGetKey(window, GLFW_KEY_O);
	if (estadoRetrocer == GLFW_PRESS && naveStarFox->vida == 2) {
		naveStarFox->retroceder(tiempoDiferencial);
	}*/

	int estadoFrente = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoFrente == GLFW_PRESS && naveStarFox->vida == 2) {
		naveStarFox->subir(tiempoDiferencial);
	}

	int estadoAtras = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAtras == GLFW_PRESS && naveStarFox->vida == 2) {
		naveStarFox->bajar(tiempoDiferencial);
	}

	int estadoP = glfwGetKey(window, GLFW_KEY_P);
	if (estadoP == GLFW_PRESS && naveStarFox->vida == 2) {
		naveStarFox->rapidez(tiempoDiferencial);
	}


	int estadoDisparoActual = glfwGetKey(window, GLFW_KEY_Z);
	if (estadoDisparoActual == GLFW_PRESS)
	{
		// Al poner false este booleano, ya no se podrá usar la función disparar() hasta que la bala desaparezca
		bala->renderearBala = false;
	}
}

// MVP (Funciones de Modelos, Vista y Proyección)
void inicializarModelos()
{
	inicializarNaveStarFox();
	inicializarNavesEnemigas();
	inicializarCasas();
	inicializarEdificios();
	inicializarFocos();
	inicializarMeteoritos();
	inicializarMisilBalaMeta();
	inicializarBackground();
	inicializarLetreros();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}
void establecerVista() {
	vec3 posicionCamara = naveStarFox->getCoordenadas();
	posicionCamara.z -= 2.5;
	posicionCamara.y += 1.0;

	vista = lookAt(
		posicionCamara,						//Posicion de la camara
		naveStarFox->getCoordenadas(),		//Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f)				//Vector hacia arriba
	);
	vistaNaveStarFox();
	vistaNavesEnemigas();
	vistaCasas();
	vistaEdificios();
	vistaFocos();
	vistaMeteoritos();
	vistaMisilBalaMeta();
	vistaBackground();
	vistaLetreros();

}
void establecerProyeccion() {
	proyeccion = perspective(
		1.83259416667f,					//Campo de vision (FoV)
		ancho / alto,					//Relación de aspecto (Aspect Ratio)
		0.1f,							//Near clipping (Desde donde renderea)
		100.0f							//Far clipping (Hasta donde renderea)
	);
}

// Inicializaciones
void inicializarNaveStarFox()
{
	naveStarFox = new NaveStarFox();
	naveStarFox->proyeccion = proyeccion;
	naveStarFox->shader = shader;
	naveStarFox->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	establecerVista();
	naveStarFox->vista = vista;
	establecerVista();
	naveStarFox->vista = vista;
}
void inicializarNavesEnemigas()
{
	//inicializar nave enemiga 1
	naveEnemigaAbajoDerecha = new NaveEnemiga();
	naveEnemigaAbajoDerecha->vista = vista;
	naveEnemigaAbajoDerecha->proyeccion = proyeccion;
	naveEnemigaAbajoDerecha->shader = shader;
	naveEnemigaAbajoDerecha->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializar nave enemiga 2
	naveEnemigaMedioDerecha = new NaveEnemiga();
	naveEnemigaMedioDerecha->vista = vista;
	naveEnemigaMedioDerecha->proyeccion = proyeccion;
	naveEnemigaMedioDerecha->shader = shader;
	naveEnemigaMedioDerecha->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializar nave enemiga 3
	naveEnemigaArribaIzquierda = new NaveEnemiga();
	naveEnemigaArribaIzquierda->vista = vista;
	naveEnemigaArribaIzquierda->proyeccion = proyeccion;
	naveEnemigaArribaIzquierda->shader = shader;
	naveEnemigaArribaIzquierda->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);
}
void inicializarCasas()
{
	//inicializacion casa 1
	casaAbajoDerecha = new Casa();
	casaAbajoDerecha->vista = vista;
	casaAbajoDerecha->proyeccion = proyeccion;
	casaAbajoDerecha->shader = shader;
	casaAbajoDerecha->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion casa 2
	casaArribaIzquierda = new Casa();
	casaArribaIzquierda->vista = vista;
	casaArribaIzquierda->proyeccion = proyeccion;
	casaArribaIzquierda->shader = shader;
	casaArribaIzquierda->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion casa 3
	casaArribaDerecha = new Casa();
	casaArribaDerecha->vista = vista;
	casaArribaDerecha->proyeccion = proyeccion;
	casaArribaDerecha->shader = shader;
	casaArribaDerecha->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion casa 4
	casaAbajoIzquierda = new Casa();
	casaAbajoIzquierda->vista = vista;
	casaAbajoIzquierda->proyeccion = proyeccion;
	casaAbajoIzquierda->shader = shader;
	casaAbajoIzquierda->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);
}
void inicializarEdificios()
{
	//inicializarEdificio 1
	edificioAbajoDerecha = new Edificio();
	edificioAbajoDerecha->vista = vista;
	edificioAbajoDerecha->proyeccion = proyeccion;
	edificioAbajoDerecha->shader = shader;
	edificioAbajoDerecha->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarEdificio 2
	edificioAbajoIzquierda = new Edificio();
	edificioAbajoIzquierda->vista = vista;
	edificioAbajoIzquierda->proyeccion = proyeccion;
	edificioAbajoIzquierda->shader = shader;
	edificioAbajoIzquierda->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarEdificio 3
	edificioArribaIzquierda = new Edificio();
	edificioArribaIzquierda->vista = vista;
	edificioArribaIzquierda->proyeccion = proyeccion;
	edificioArribaIzquierda->shader = shader;
	edificioArribaIzquierda->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarEdificio 4
	edificioArribaDerecha = new Edificio();
	edificioArribaDerecha->vista = vista;
	edificioArribaDerecha->proyeccion = proyeccion;
	edificioArribaDerecha->shader = shader;
	edificioArribaDerecha->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);
}
void inicializarFocos()
{
	//inicializarFoco 1
	foco = new Foco();
	foco->vista = vista;
	foco->proyeccion = proyeccion;
	foco->shader = shader;
	foco->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 2
	foco2 = new Foco();
	foco2->vista = vista;
	foco2->proyeccion = proyeccion;
	foco2->shader = shader;
	foco2->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 3
	foco3 = new Foco();
	foco3->vista = vista;
	foco3->proyeccion = proyeccion;
	foco3->shader = shader;
	foco3->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 4
	foco4 = new Foco();
	foco4->vista = vista;
	foco4->proyeccion = proyeccion;
	foco4->shader = shader;
	foco4->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 5
	foco5 = new Foco();
	foco5->vista = vista;
	foco5->proyeccion = proyeccion;
	foco5->shader = shader;
	foco5->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 6
	foco6 = new Foco();
	foco6->vista = vista;
	foco6->proyeccion = proyeccion;
	foco6->shader = shader;
	foco6->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 7
	foco7 = new Foco();
	foco7->vista = vista;
	foco7->proyeccion = proyeccion;
	foco7->shader = shader;
	foco7->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 8
	foco8 = new Foco();
	foco8->vista = vista;
	foco8->proyeccion = proyeccion;
	foco8->shader = shader;
	foco8->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 9
	foco9 = new Foco();
	foco9->vista = vista;
	foco9->proyeccion = proyeccion;
	foco9->shader = shader;
	foco9->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 10
	foco10 = new Foco();
	foco10->vista = vista;
	foco10->proyeccion = proyeccion;
	foco10->shader = shader;
	foco10->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 11
	foco11 = new Foco();
	foco11->vista = vista;
	foco11->proyeccion = proyeccion;
	foco11->shader = shader;
	foco11->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializarFoco 12
	foco12 = new Foco();
	foco12->vista = vista;
	foco12->proyeccion = proyeccion;
	foco12->shader = shader;
	foco12->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);
}
void inicializarMeteoritos()
{
	//inicializacion meteorito 1
	meteorito1 = new Meteorito();
	meteorito1->vista = vista;
	meteorito1->proyeccion = proyeccion;
	meteorito1->shader = shader;
	meteorito1->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meteorito 2
	meteorito2 = new Meteorito();
	meteorito2->vista = vista;
	meteorito2->proyeccion = proyeccion;
	meteorito2->shader = shader;
	meteorito2->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meteorito 3
	meteorito3 = new Meteorito();
	meteorito3->vista = vista;
	meteorito3->proyeccion = proyeccion;
	meteorito3->shader = shader;
	meteorito3->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meteorito 4
	meteorito4 = new Meteorito();
	meteorito4->vista = vista;
	meteorito4->proyeccion = proyeccion;
	meteorito4->shader = shader;
	meteorito4->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meteorito 5
	meteorito5 = new Meteorito();
	meteorito5->vista = vista;
	meteorito5->proyeccion = proyeccion;
	meteorito5->shader = shader;
	meteorito5->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	//inicializacion meteorito 6
	meteorito6 = new Meteorito();
	meteorito6->vista = vista;
	meteorito6->proyeccion = proyeccion;
	meteorito6->shader = shader;
	meteorito6->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);
}
void inicializarMisilBalaMeta()
{
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
}
void inicializarBackground()
{
	//inicializacion suelo
	suelo = new Background();
	suelo->vista = vista;
	suelo->proyeccion = proyeccion;
	suelo->shader = shader;
	suelo->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);
}
void inicializarLetreros(){

	ltVictoria = new LtVictoria();
	ltVictoria->vista = vista;
	ltVictoria->proyeccion = proyeccion;
	ltVictoria->shader = shader;
	ltVictoria->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	ltDerrota = new LtDerrota();
	ltDerrota->vista = vista;
	ltDerrota->proyeccion = proyeccion;
	ltDerrota->shader = shader;
	ltDerrota->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

}
// Establecimiento de Vistas
void vistaNaveStarFox()
{
	if (naveStarFox != NULL) {
		naveStarFox->vista = vista;
	}
}
void vistaNavesEnemigas()
{
	if (naveEnemigaAbajoDerecha != NULL) {
		naveEnemigaAbajoDerecha->vista = vista;
	}
	if (naveEnemigaMedioDerecha != NULL) {
		naveEnemigaMedioDerecha->vista = vista;
	}
	if (naveEnemigaArribaIzquierda != NULL) {
		naveEnemigaArribaIzquierda->vista = vista;
	}
}
void vistaCasas()
{
	if (casaAbajoDerecha != NULL) {
		casaAbajoDerecha->vista = vista;
	}
	if (casaArribaIzquierda != NULL) {
		casaArribaIzquierda->vista = vista;
	}
	if (casaArribaDerecha != NULL) {
		casaArribaDerecha->vista = vista;
	}
	if (casaAbajoIzquierda != NULL) {
		casaAbajoIzquierda->vista = vista;
	}
}
void vistaEdificios()
{
	if (edificioAbajoDerecha != NULL) {
		edificioAbajoDerecha->vista = vista;
	}
	if (edificioAbajoIzquierda != NULL) {
		edificioAbajoIzquierda->vista = vista;
	}
	if (edificioArribaIzquierda != NULL) {
		edificioArribaIzquierda->vista = vista;
	}
	if (edificioArribaDerecha != NULL) {
		edificioArribaDerecha->vista = vista;
	}
}
void vistaFocos()
{
	if (foco != NULL) {
		foco->vista = vista;
	}
	if (foco2 != NULL) {
		foco2->vista = vista;
	}
	if (foco3 != NULL) {
		foco3->vista = vista;
	}
	if (foco4 != NULL) {
		foco4->vista = vista;
	}
	if (foco5 != NULL) {
		foco5->vista = vista;
	}
	if (foco6 != NULL) {
		foco6->vista = vista;
	}
	if (foco7 != NULL) {
		foco7->vista = vista;
	}
	if (foco8 != NULL) {
		foco8->vista = vista;
	}
	if (foco9 != NULL) {
		foco9->vista = vista;
	}
	if (foco10 != NULL) {
		foco10->vista = vista;
	}
	if (foco11 != NULL) {
		foco11->vista = vista;
	}
	if (foco12 != NULL) {
		foco12->vista = vista;
	}
}
void vistaMeteoritos()
{
	if (meteorito1 != NULL) {
		meteorito1->vista = vista;
	}
	if (meteorito2 != NULL) {
		meteorito2->vista = vista;
	}
	if (meteorito3 != NULL) {
		meteorito3->vista = vista;
	}
	if (meteorito4 != NULL) {
		meteorito4->vista = vista;
	}
	if (meteorito5 != NULL) {
		meteorito5->vista = vista;
	}
	if (meteorito6 != NULL) {
		meteorito6->vista = vista;
	}
}
void vistaMisilBalaMeta()
{
	if (misil != NULL) {
		misil->vista = vista;
	}
	if (bala != NULL) {
		bala->vista = vista;
	}
	if (meta != NULL) {
		meta->vista = vista;
	}
}
void vistaBackground()
{
	if (suelo != NULL) {
		suelo->vista = vista;
	}
}
void vistaLetreros()
{
	if (ltVictoria != NULL) {
		ltVictoria->vista = vista;
	}
	if (ltDerrota != NULL) {
		ltDerrota->vista = vista;
	}
}

// Dibujado
void dibujarNaveStarFox()
{
	if (naveStarFox->vida != 0)
	{
		naveStarFox->dibujar(GL_QUADS);
	}
}
void dibujarNavesEnemigas()
{
	if(naveEnemigaAbajoDerecha->vida)
	{
		naveEnemigaAbajoDerecha->dibujar(GL_QUADS);
		naveEnemigaAbajoDerecha->coordenadas = vec3(-5.0f, 3.0f, -27.0f);
		naveEnemigaAbajoDerecha->actualizarMatrizModelo();
	}

	if (naveEnemigaMedioDerecha->vida)
	{
		naveEnemigaMedioDerecha->dibujar(GL_QUADS);
		naveEnemigaMedioDerecha->coordenadas = vec3(-3.0f, 2.5f, -18.0f);
		naveEnemigaMedioDerecha->actualizarMatrizModelo();
	}
	
	if (naveEnemigaArribaIzquierda->vida)
	{
		naveEnemigaArribaIzquierda->dibujar(GL_QUADS);
		naveEnemigaArribaIzquierda->coordenadas = vec3(2.0f, 3.9f, -10.0f);
		naveEnemigaArribaIzquierda->actualizarMatrizModelo();
	}
}
void dibujarCasas()
{
	//casa der abajo
	casaAbajoDerecha->dibujar(GL_QUADS);
	casaAbajoDerecha->coordenadas = vec3(-10.0f, -2.0f, 10.0f);
	casaAbajoDerecha->actualizarMatrizModelo();

	//casa derecha arriba
	casaArribaIzquierda->dibujar(GL_QUADS);
	casaArribaIzquierda->coordenadas = vec3(25.0f, -2.0f, 70.0f);
	casaArribaIzquierda->actualizarMatrizModelo();

	//casa izq abajo
	casaArribaDerecha->dibujar(GL_QUADS);
	casaArribaDerecha->coordenadas = vec3(-10.0f, -2.0f, 70.0f);
	casaArribaDerecha->actualizarMatrizModelo();

	//casa izq abajo
	casaAbajoIzquierda->dibujar(GL_QUADS);
	casaAbajoIzquierda->coordenadas = vec3(25.0f, -2.0f, 10.0f);
	casaAbajoIzquierda->actualizarMatrizModelo();
}
void dibujarEdificios()
{
	//Edificio izq abajo
	edificioAbajoDerecha->dibujar(GL_QUADS);
	edificioAbajoDerecha->coordenadas = vec3(-8.0f, -2.0f, -60.0f);
	edificioAbajoDerecha->actualizarMatrizModelo();

	//Edificio derecha abaj
	edificioAbajoIzquierda->dibujar(GL_QUADS);
	edificioAbajoIzquierda->coordenadas = vec3(7.0f, -2.0f, -40.0f);
	edificioAbajoIzquierda->actualizarMatrizModelo();

	//Edificio derecha arriba
	edificioArribaIzquierda->dibujar(GL_QUADS);
	edificioArribaIzquierda->coordenadas = vec3(8.0f, -2.0f, 40.0f);
	edificioArribaIzquierda->actualizarMatrizModelo();

	//Edificio izq arriba
	edificioArribaDerecha->dibujar(GL_QUADS);
	edificioArribaDerecha->coordenadas = vec3(-8.0f, -2.0f, 40.0f);
	edificioArribaDerecha->actualizarMatrizModelo();
}
void dibujarFocos()
{
	foco->dibujar(GL_QUADS);
	foco->coordenadas = vec3(-10.0f,-3.25f, -60.0f);
	foco->actualizarMatrizModelo();

	foco2->dibujar(GL_QUADS);
	foco2->coordenadas = vec3(10.0f, -3.25f, -60.0f);
	foco2->actualizarMatrizModelo();

	foco3->dibujar(GL_QUADS);
	foco3->coordenadas = vec3(-10.0f, -3.25f, -40.0f);
	foco3->actualizarMatrizModelo();

	foco4->dibujar(GL_QUADS);
	foco4->coordenadas = vec3(10.0f, -3.25f, -40.0f);
	foco4->actualizarMatrizModelo();

	foco5->dibujar(GL_QUADS);
	foco5->coordenadas = vec3(-10.0f, -3.25f, -20.0f);
	foco5->actualizarMatrizModelo();

	foco6->dibujar(GL_QUADS);
	foco6->coordenadas = vec3(10.0f, -3.25f, -20.0f);
	foco6->actualizarMatrizModelo();

	foco7->dibujar(GL_QUADS);
	foco7->coordenadas = vec3(-10.0f, -3.25f, 0.0f);
	foco7->actualizarMatrizModelo();

	foco8->dibujar(GL_QUADS);
	foco8->coordenadas = vec3(10.0f, -3.25f, 0.0f);
	foco8->actualizarMatrizModelo();

	foco9->dibujar(GL_QUADS);
	foco9->coordenadas = vec3(-10.0f, -3.25f, 20.0f);
	foco9->actualizarMatrizModelo();

	foco10->dibujar(GL_QUADS);
	foco10->coordenadas = vec3(10.0f, -3.25f, 20.0f);
	foco10->actualizarMatrizModelo();

	foco11->dibujar(GL_QUADS);
	foco11->coordenadas = vec3(-10.0f, -3.25f, 40.0f);
	foco11->actualizarMatrizModelo();

	foco12->dibujar(GL_QUADS);
	foco12->coordenadas = vec3(10.0f, -3.25f, 40.0f);
	foco12->actualizarMatrizModelo();
}
void dibujarMeteoritos()
{
	if (meteorito1->vida == true)
	{
		//Meteorito medio
		meteorito1->dibujar(GL_QUADS);
		meteorito1->coordenadas = vec3(3.0f, 3.0f, -40.0f);
		meteorito1->actualizarMatrizModelo();
	}

	if (meteorito2->vida == true)
	{
		//Meteorito izq abajo
		meteorito2->dibujar(GL_QUADS);
		meteorito2->coordenadas = vec3(-7.0f, 3.0f, 0.0f);
		meteorito2->actualizarMatrizModelo();
	}

	if (meteorito3->vida == true)
	{
		//Meteorito derecha abajo
		meteorito3->dibujar(GL_QUADS);
		meteorito3->coordenadas = vec3(6.0f, 1.0f, 10.0f);
		meteorito3->actualizarMatrizModelo();
	}

	if (meteorito4->vida == true)
	{
		//Meteorito izq medioo
		meteorito4->dibujar(GL_QUADS);
		meteorito4->coordenadas = vec3(-2.0f, 2.0f, 20.0f);
		meteorito4->actualizarMatrizModelo();
	}

	if (meteorito5->vida == true)
	{
		//Meteorito derecha arriba
		meteorito5->dibujar(GL_QUADS);
		meteorito5->coordenadas = vec3(4.0f, 0.0f, 30.0f);
		meteorito5->actualizarMatrizModelo();
	}

	if (meteorito6->vida == true)
	{
		//Meteorito izq arriba
		meteorito6->dibujar(GL_QUADS);
		meteorito6->coordenadas = vec3(0.0f, 3.0f, 40.0f);
		meteorito6->actualizarMatrizModelo();
	}
}
void dibujarMeta() {
	meta->dibujar(GL_QUADS);
	meta->coordenadas = vec3(0.0f, -4.5f, 90.0f);
	meta->actualizarMatrizModelo();
}
void dibujarBackground() {
	suelo->dibujar(GL_QUADS);
	suelo->coordenadas = vec3(0.0f, -2.5f, 0.0);
	suelo->actualizarMatrizModelo();
}

// Funciones de colisiones
void disparar() {
	if (bala->renderearBala == false)
	{
		// Bala 1
		if (bala->balaDisparada == true && bala->distanciaRecorrida <= 40)
		{
			bala->dibujar(GL_QUADS);
			bala->avanzar(tiempoDiferencial);
		}
		else if (bala->balaDisparada == false && bala->balaColisionada == false)
		{
			bala->aparecer(naveStarFox->getCoordenadas());
			bala->dibujar(GL_QUADS);
			bala->avanzar(tiempoDiferencial);
			engine->play2D("..\\Music\\disparo.wav", false, false, true);
		}
		else if (bala->balaDisparada == false && bala->balaColisionada == true)
		{
			bala->renderearBala = true;
			bala->balaDisparada = false;
			bala->balaColisionada = false;
		}
	}
}
void destruirObstaculos() {
	// Meteorito 1
	if (bala->coordenadas.x - 0.2f < meteorito1->coordenadas.x + 2.7f &&
		bala->coordenadas.x + 0.2f > meteorito1->coordenadas.x - 2.7f &&
		bala->coordenadas.y - 0.2f < meteorito1->coordenadas.y + 2.5f &&
		bala->coordenadas.y + 0.2f > meteorito1->coordenadas.y - 2.5f &&
		bala->coordenadas.z - 0.8f < meteorito1->coordenadas.z + 1.35f &&
		bala->coordenadas.z + 0.8f > meteorito1->coordenadas.z - 1.35f && meteorito1->vida != false)
	{
		meteorito1->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Meteorito 2
	if (bala->coordenadas.x - 0.2f < meteorito2->coordenadas.x + 2.7f &&
		bala->coordenadas.x + 0.2f > meteorito2->coordenadas.x - 2.7f &&
		bala->coordenadas.y - 0.2f < meteorito2->coordenadas.y + 2.5f &&
		bala->coordenadas.y + 0.2f > meteorito2->coordenadas.y - 2.5f &&
		bala->coordenadas.z - 0.8f < meteorito2->coordenadas.z + 1.35f &&
		bala->coordenadas.z + 0.8f > meteorito2->coordenadas.z - 1.35f && meteorito2->vida != false)
	{
		meteorito2->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Meteorito 3
	if (bala->coordenadas.x - 0.2f < meteorito3->coordenadas.x + 2.7f &&
		bala->coordenadas.x + 0.2f > meteorito3->coordenadas.x - 2.7f &&
		bala->coordenadas.y - 0.2f < meteorito3->coordenadas.y + 2.5f &&
		bala->coordenadas.y + 0.2f > meteorito3->coordenadas.y - 2.5f &&
		bala->coordenadas.z - 0.8f < meteorito3->coordenadas.z + 1.35f &&
		bala->coordenadas.z + 0.8f > meteorito3->coordenadas.z - 1.35f && meteorito3->vida != false)
	{
		meteorito3->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Meteorito 4
	if (bala->coordenadas.x - 0.2f < meteorito4->coordenadas.x + 2.7f &&
		bala->coordenadas.x + 0.2f > meteorito4->coordenadas.x - 2.7f &&
		bala->coordenadas.y - 0.2f < meteorito4->coordenadas.y + 2.5f &&
		bala->coordenadas.y + 0.2f > meteorito4->coordenadas.y - 2.5f &&
		bala->coordenadas.z - 0.8f < meteorito4->coordenadas.z + 1.35f &&
		bala->coordenadas.z + 0.8f > meteorito4->coordenadas.z - 1.35f && meteorito4->vida != false)
	{
		meteorito4->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Meteorito 5
	if (bala->coordenadas.x - 0.2f < meteorito5->coordenadas.x + 2.7f &&
		bala->coordenadas.x + 0.2f > meteorito5->coordenadas.x - 2.7f &&
		bala->coordenadas.y - 0.2f < meteorito5->coordenadas.y + 2.5f &&
		bala->coordenadas.y + 0.2f > meteorito5->coordenadas.y - 2.5f &&
		bala->coordenadas.z - 0.8f < meteorito5->coordenadas.z + 1.35f &&
		bala->coordenadas.z + 0.8f > meteorito5->coordenadas.z - 1.35f && meteorito5->vida != false)
	{
		meteorito5->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Meteorito 6
	if (bala->coordenadas.x - 0.2f < meteorito6->coordenadas.x + 2.7f &&
		bala->coordenadas.x + 0.2f > meteorito6->coordenadas.x - 2.7f &&
		bala->coordenadas.y - 0.2f < meteorito6->coordenadas.y + 2.5f &&
		bala->coordenadas.y + 0.2f > meteorito6->coordenadas.y - 2.5f &&
		bala->coordenadas.z - 0.8f < meteorito6->coordenadas.z + 1.35f &&
		bala->coordenadas.z + 0.8f > meteorito6->coordenadas.z - 1.35f && meteorito6->vida != false)
	{
		meteorito6->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}

	// Nave Enemiga 1
	if (bala->coordenadas.x - 0.2f < naveEnemigaAbajoDerecha->coordenadas.x + 0.9f &&
		bala->coordenadas.x + 0.2f > naveEnemigaAbajoDerecha->coordenadas.x - 0.9f &&
		bala->coordenadas.y - 0.2f < naveEnemigaAbajoDerecha->coordenadas.y + 0.7f &&
		bala->coordenadas.y + 0.2f > naveEnemigaAbajoDerecha->coordenadas.y - 0.7f &&
		bala->coordenadas.z - 0.8f < naveEnemigaAbajoDerecha->coordenadas.z + 0.9f &&
		bala->coordenadas.z + 0.8f > naveEnemigaAbajoDerecha->coordenadas.z - 0.9f && naveEnemigaAbajoDerecha->vida != false)
	{
		naveEnemigaAbajoDerecha->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Nave Enemiga 2
	if (bala->coordenadas.x - 0.2f < naveEnemigaMedioDerecha->coordenadas.x + 0.9f &&
		bala->coordenadas.x + 0.2f > naveEnemigaMedioDerecha->coordenadas.x - 0.9f &&
		bala->coordenadas.y - 0.2f < naveEnemigaMedioDerecha->coordenadas.y + 0.7f &&
		bala->coordenadas.y + 0.2f > naveEnemigaMedioDerecha->coordenadas.y - 0.7f &&
		bala->coordenadas.z - 0.8f < naveEnemigaMedioDerecha->coordenadas.z + 0.9f &&
		bala->coordenadas.z + 0.8f > naveEnemigaMedioDerecha->coordenadas.z - 0.9f && naveEnemigaMedioDerecha->vida != false)
	{
		naveEnemigaMedioDerecha->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
	// Nave Enemiga 3
	if (bala->coordenadas.x - 0.2f < naveEnemigaArribaIzquierda->coordenadas.x + 0.9f &&
		bala->coordenadas.x + 0.2f > naveEnemigaArribaIzquierda->coordenadas.x - 0.9f &&
		bala->coordenadas.y - 0.2f < naveEnemigaArribaIzquierda->coordenadas.y + 0.7f &&
		bala->coordenadas.y + 0.2f > naveEnemigaArribaIzquierda->coordenadas.y - 0.7f &&
		bala->coordenadas.z - 0.8f < naveEnemigaArribaIzquierda->coordenadas.z + 0.9f &&
		bala->coordenadas.z + 0.8f > naveEnemigaArribaIzquierda->coordenadas.z - 0.9f && naveEnemigaArribaIzquierda->vida != false)
	{
		naveEnemigaArribaIzquierda->vida = false;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
	}
}
void destruirNaveStarFox()
{
 	// Edificio Abajo Derecha
	if (naveStarFox->coordenadas.x - 0.5f < edificioAbajoDerecha->coordenadas.x + 6.8f &&
		naveStarFox->coordenadas.x + 0.5f > edificioAbajoDerecha->coordenadas.x - 6.8f &&
		naveStarFox->coordenadas.y - 0.5f < edificioAbajoDerecha->coordenadas.y + 7.0f &&
		naveStarFox->coordenadas.y + 0.5f > edificioAbajoDerecha->coordenadas.y - 7.0f &&
		naveStarFox->coordenadas.z - 0.81f < edificioAbajoDerecha->coordenadas.z + 12.0f &&
		naveStarFox->coordenadas.z + 0.81f > edificioAbajoDerecha->coordenadas.z + 1.25f)
	{
		naveStarFox->vida = 0;
	}
 	// Edificio 2
	if (naveStarFox->coordenadas.x - 0.5f < edificioAbajoIzquierda->coordenadas.x + 6.8f &&
		naveStarFox->coordenadas.x + 0.5f > edificioAbajoIzquierda->coordenadas.x - 6.8f &&
		naveStarFox->coordenadas.y - 0.5f < edificioAbajoIzquierda->coordenadas.y + 7.0f &&
		naveStarFox->coordenadas.y + 0.5f > edificioAbajoIzquierda->coordenadas.y - 7.0f &&
		naveStarFox->coordenadas.z - 0.81f < edificioAbajoIzquierda->coordenadas.z + 12.0f &&
		naveStarFox->coordenadas.z + 0.81f > edificioAbajoIzquierda->coordenadas.z + 1.25f)
	{
		naveStarFox->vida = 0;
	}
 	// Edificio 3
	if (naveStarFox->rotando == false)
	{
		if (naveStarFox->coordenadas.x - 0.7225f < edificioArribaIzquierda->coordenadas.x + 7.2f &&
		naveStarFox->coordenadas.x + 0.7225f > edificioArribaIzquierda->coordenadas.x - 7.2f &&
		naveStarFox->coordenadas.y - 0.5f < edificioArribaIzquierda->coordenadas.y + 7.0f &&
		naveStarFox->coordenadas.y + 0.5f > edificioArribaIzquierda->coordenadas.y - 7.0f &&
		naveStarFox->coordenadas.z - 0.81f < edificioArribaIzquierda->coordenadas.z + 12.0f &&
		naveStarFox->coordenadas.z + 0.81f > edificioArribaIzquierda->coordenadas.z + 1.25f)
		{
			naveStarFox->vida = 0;
		}
	}
	else if (naveStarFox->coordenadas.x - 0.55f < edificioArribaIzquierda->coordenadas.x + 7.2f &&
		naveStarFox->coordenadas.x + 0.55f > edificioArribaIzquierda->coordenadas.x - 7.2f &&
		naveStarFox->coordenadas.y - 0.5f < edificioArribaIzquierda->coordenadas.y + 7.0f &&
		naveStarFox->coordenadas.y + 0.5f > edificioArribaIzquierda->coordenadas.y - 7.0f &&
		naveStarFox->coordenadas.z - 0.81f < edificioArribaIzquierda->coordenadas.z + 12.0f &&
		naveStarFox->coordenadas.z + 0.81f > edificioArribaIzquierda->coordenadas.z + 1.25f)
		 {
			 naveStarFox->vida = 0;
		 }
 	// Edificio 4
	if (naveStarFox->rotando == false)
	{
		if(naveStarFox->coordenadas.x - 0.7225f < edificioArribaDerecha->coordenadas.x + 7.2f &&
		naveStarFox->coordenadas.x + 0.7225f > edificioArribaDerecha->coordenadas.x - 7.2f &&
		naveStarFox->coordenadas.y - 0.5f < edificioArribaDerecha->coordenadas.y + 7.0f &&
		naveStarFox->coordenadas.y + 0.5f > edificioArribaDerecha->coordenadas.y - 7.0f &&
		naveStarFox->coordenadas.z - 0.81f < edificioArribaDerecha->coordenadas.z + 12.0f &&
		naveStarFox->coordenadas.z + 0.81f > edificioArribaDerecha->coordenadas.z + 1.25f)
		{
			naveStarFox->vida = 0;
		}
	}
	else if (naveStarFox->coordenadas.x - 0.55f < edificioArribaDerecha->coordenadas.x + 7.2f &&
		naveStarFox->coordenadas.x + 0.55f > edificioArribaDerecha->coordenadas.x - 7.2f &&
		naveStarFox->coordenadas.y - 0.5f < edificioArribaDerecha->coordenadas.y + 7.0f &&
		naveStarFox->coordenadas.y + 0.5f > edificioArribaDerecha->coordenadas.y - 7.0f &&
		naveStarFox->coordenadas.z - 0.81f < edificioArribaDerecha->coordenadas.z + 12.0f &&
		naveStarFox->coordenadas.z + 0.81f > edificioArribaDerecha->coordenadas.z + 1.25f)
		 {
			 naveStarFox->vida = 0;
		 }

	// Meteorito 1
	if (naveStarFox->coordenadas.x - 0.5f < meteorito1->coordenadas.x + 2.7f &&
		naveStarFox->coordenadas.x + 0.5f > meteorito1->coordenadas.x - 2.7f &&
		naveStarFox->coordenadas.y - 0.5f < meteorito1->coordenadas.y + 2.5f &&
		naveStarFox->coordenadas.y + 0.5f > meteorito1->coordenadas.y - 2.5f &&
		naveStarFox->coordenadas.z - 0.8f < meteorito1->coordenadas.z + 1.35f &&
		naveStarFox->coordenadas.z + 0.8f > meteorito1->coordenadas.z - 1.35f && meteorito1->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// Meteorito 2
	if (naveStarFox->coordenadas.x - 0.5f < meteorito2->coordenadas.x + 2.7f &&
		naveStarFox->coordenadas.x + 0.5f > meteorito2->coordenadas.x - 2.7f &&
		naveStarFox->coordenadas.y - 0.5f < meteorito2->coordenadas.y + 2.5f &&
		naveStarFox->coordenadas.y + 0.5f > meteorito2->coordenadas.y - 2.5f &&
		naveStarFox->coordenadas.z - 0.8f < meteorito2->coordenadas.z + 1.35f &&
		naveStarFox->coordenadas.z + 0.8f > meteorito2->coordenadas.z - 1.35f && meteorito2->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// Meteorito 3
	if (naveStarFox->coordenadas.x - 0.5f < meteorito3->coordenadas.x + 2.7f &&
		naveStarFox->coordenadas.x + 0.5f > meteorito3->coordenadas.x - 2.7f &&
		naveStarFox->coordenadas.y - 0.5f < meteorito3->coordenadas.y + 2.5f &&
		naveStarFox->coordenadas.y + 0.5f > meteorito3->coordenadas.y - 2.5f &&
		naveStarFox->coordenadas.z - 0.8f < meteorito3->coordenadas.z + 1.35f &&
		naveStarFox->coordenadas.z + 0.8f > meteorito3->coordenadas.z - 1.35f && meteorito3->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// Meteorito 4
	if (naveStarFox->coordenadas.x - 0.5f < meteorito4->coordenadas.x + 2.7f &&
		naveStarFox->coordenadas.x + 0.5f > meteorito4->coordenadas.x - 2.7f &&
		naveStarFox->coordenadas.y - 0.5f < meteorito4->coordenadas.y + 2.5f &&
		naveStarFox->coordenadas.y + 0.5f > meteorito4->coordenadas.y - 2.5f &&
		naveStarFox->coordenadas.z - 0.8f < meteorito4->coordenadas.z + 1.35f &&
		naveStarFox->coordenadas.z + 0.8f > meteorito4->coordenadas.z - 1.35f && meteorito4->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// Meteorito 5
	if (naveStarFox->coordenadas.x - 0.5f < meteorito5->coordenadas.x + 2.7f &&
		naveStarFox->coordenadas.x + 0.5f > meteorito5->coordenadas.x - 2.7f &&
		naveStarFox->coordenadas.y - 0.5f < meteorito5->coordenadas.y + 1.8f &&
		naveStarFox->coordenadas.y + 0.5f > meteorito5->coordenadas.y - 1.8f &&
		naveStarFox->coordenadas.z - 0.8f < meteorito5->coordenadas.z + 1.35f &&
		naveStarFox->coordenadas.z + 0.8f > meteorito5->coordenadas.z - 1.35f && meteorito5->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// Meteorito 6
	if (naveStarFox->coordenadas.x - 0.5f < meteorito6->coordenadas.x + 2.7f &&
		naveStarFox->coordenadas.x + 0.5f > meteorito6->coordenadas.x - 2.7f&&
		naveStarFox->coordenadas.y - 0.5f < meteorito6->coordenadas.y + 1.8f &&
		naveStarFox->coordenadas.y + 0.5f > meteorito6->coordenadas.y - 1.8f &&
		naveStarFox->coordenadas.z - 0.8f < meteorito6->coordenadas.z + 1.35f &&
		naveStarFox->coordenadas.z + 0.8f > meteorito6->coordenadas.z - 1.35f && meteorito6->vida != false)
	{
		naveStarFox->vida = 0;
	}

	// naveEnemigaArribaIzquierda
	if (naveStarFox->coordenadas.x - 0.5f < naveEnemigaArribaIzquierda->coordenadas.x + 0.9f &&
		naveStarFox->coordenadas.x + 0.5f > naveEnemigaArribaIzquierda->coordenadas.x - 0.9f &&
		naveStarFox->coordenadas.y - 0.5f < naveEnemigaArribaIzquierda->coordenadas.y + 0.7f &&
		naveStarFox->coordenadas.y + 0.5f > naveEnemigaArribaIzquierda->coordenadas.y - 0.7f &&
		naveStarFox->coordenadas.z - 0.8f < naveEnemigaArribaIzquierda->coordenadas.z + 0.9f &&
		naveStarFox->coordenadas.z + 0.8f > naveEnemigaArribaIzquierda->coordenadas.z - 0.9f && naveEnemigaArribaIzquierda->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// naveEnemigaAbajoDerecha
	if (naveStarFox->coordenadas.x - 0.5f < naveEnemigaAbajoDerecha->coordenadas.x + 0.9f &&
		naveStarFox->coordenadas.x + 0.5f > naveEnemigaAbajoDerecha->coordenadas.x - 0.9f &&
		naveStarFox->coordenadas.y - 0.5f < naveEnemigaAbajoDerecha->coordenadas.y + 0.7f &&
		naveStarFox->coordenadas.y + 0.5f > naveEnemigaAbajoDerecha->coordenadas.y - 0.7f &&
		naveStarFox->coordenadas.z - 0.8f < naveEnemigaAbajoDerecha->coordenadas.z + 0.9f &&
		naveStarFox->coordenadas.z + 0.8f > naveEnemigaAbajoDerecha->coordenadas.z - 0.9f && naveEnemigaAbajoDerecha->vida != false)
	{
		naveStarFox->vida = 0;
	}
	// naveEnemigaMedioDerecha
	if (naveStarFox->coordenadas.x - 0.5f < naveEnemigaMedioDerecha->coordenadas.x + 0.9f &&
		naveStarFox->coordenadas.x + 0.5f > naveEnemigaMedioDerecha->coordenadas.x - 0.9f &&
		naveStarFox->coordenadas.y - 0.5f < naveEnemigaMedioDerecha->coordenadas.y + 0.7f &&
		naveStarFox->coordenadas.y + 0.5f > naveEnemigaMedioDerecha->coordenadas.y - 0.7f &&
		naveStarFox->coordenadas.z - 0.8f < naveEnemigaMedioDerecha->coordenadas.z + 0.9f &&
		naveStarFox->coordenadas.z + 0.8f > naveEnemigaMedioDerecha->coordenadas.z - 0.9f && naveEnemigaMedioDerecha->vida != false)
	{
		naveStarFox->vida = 0;
	}
}
void victoriaDerrota()
{
	if (naveStarFox->coordenadas.z - 0.81f < meta->coordenadas.z + .30f &&
		naveStarFox->coordenadas.z + 0.81f > meta->coordenadas.z + .30f)
	{
		ltVictoria->dibujar(GL_LINES);
		ltVictoria->coordenadas = vec3(0.0f, 15.0f, 150.0f);
		ltVictoria->actualizarMatrizModelo();

		naveStarFox->detenerse(tiempoDiferencial);
		naveStarFox->vida = 1;

		if (cancionEstado == true && cancionFinalEstado == false)
		{
			engine->removeAllSoundSources();
			// Parametros: 1. Loop; 2. StartPaused; 3. Track
			irrklang::ISound* snd = engine->play2D("..\\Music\\victoria.wav", true, false, true);
			if (snd)
			{
				snd->setVolume(0.2f);
			}
			cancionEstado = false;
			cancionFinalEstado = true;
		}
	}

	if (naveStarFox->vida <= 0)
	{
		ltDerrota->dibujar(GL_LINES);

		naveStarFox->detenerse(tiempoDiferencial);
		naveStarFox->coordenadas = vec3(70.0f, 99.0f, 99.0f);

		if (cancionEstado == true && cancionFinalEstado == false)
		{
			engine->removeAllSoundSources();
			// Parametros: 1. Loop; 2. StartPaused; 3. Track
			irrklang::ISound* snd = engine->play2D("..\\Music\\muerte.wav", true, false, true);
			if (snd)
			{
				snd->setVolume(0.2f);
			}
			cancionEstado = false;
			cancionFinalEstado = true;
		}
	}
}

// Cerrado del juego al presionar escape
void teclado_callback(GLFWwindow* window, int key, int scncode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		meteorito1->vida = true;
		meteorito2->vida = true;
		meteorito3->vida = true;
		meteorito4->vida = true;
		meteorito5->vida = true;
		meteorito6->vida = true;
		naveEnemigaAbajoDerecha->vida = true;
		naveEnemigaArribaIzquierda->vida = true;
		naveEnemigaMedioDerecha->vida = true;
		bala->balaDisparada = false;
		bala->balaColisionada = true;
		bala->renderearBala = false;
		bala->coordenadas = vec3(99.0f, 99.0f, 99.0f);
		naveStarFox->coordenadas = vec3(0.0f, 3.0f, -70.0f);
		naveStarFox->vida = 2; 
		cancion++;
		cancionEstado = false;
		cancionFinalEstado = false;
		if (snd)
		{
			snd->drop();
			snd = 0;
		}
	}
}