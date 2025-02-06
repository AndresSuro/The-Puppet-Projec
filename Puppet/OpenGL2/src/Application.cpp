#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include<stack>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>


#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
Camera camera;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

float headAngle = 0.0f;
float gradtorzo = 0.0f;
float gradbrazoder = 0.0f;
float gradbrazoizq = 0.0f;
float gradantebrader = 0.0f;
float gradantebraizq = 0.0f;
float gradpiernader = 0.0f;
float gradpiernaizq = 0.0f;
float gradrodider = 0.0f;
float gradrodizq = 0.0f;
float gradpieizq = 0.0f;
float gradpieder = 0.0f;
float gradcadera = 0.0f;
float gradmanoder = 0.0f;
float gradmanoizq = 0.0f;

float sumabrazoder = 0.03f;
float sumabrazoizq = 0.03f;
float sumaantebrader = 0.03f;
float sumaantebraizq = 0.03f;
float sumapiernader = 0.03f;
float sumapiernaizq = 0.03f;
float sumarodider = 0.03f;
float sumarodizq = 0.03f;
float sumahead = 0.03f;
float sumapieizq = 0.03;
float sumapieder = 0.03;
float sumacadera = 0.03;
float sumamanoder = 0.03;
float sumamanoizq = 0.03;




// Vertex Shader
static const char* vShader = "Shaders/shader.vert";

// Fragment Shader
static const char* fShader = "Shaders/shader.frag";

void CreateObjects()
{
	unsigned int indices[] = { // definimos el cubo unitario
		7, 4, 5,
		7, 6, 5,
		3, 0, 1,
		3, 2, 1,
		6, 5, 1,
		6, 2, 1,
		7, 4, 0,
		7, 3, 0,
		3, 7, 6,
		3, 2, 6,
		0, 4, 5,
		0, 1, 5
	};

	GLfloat vertices[] = {
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f 
	};

	Mesh* obj1 = new Mesh();// cabeza
	obj1->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();// torzo
	obj2->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();// brazo der
	obj3->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();// brazo izq
	obj4->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj4);
	
	Mesh* obj5 = new Mesh();// pierna izq
	obj5->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj5);
	
	Mesh* obj6 = new Mesh();// pierna derecha
	obj6->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj6);

	Mesh* obj7 = new Mesh();// muneca izquierda
	obj7->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj7);

	Mesh* obj8 = new Mesh();// muneca derecha
	obj8->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj8);

	Mesh* obj9 = new Mesh();// nariz
	obj9->CreateMesh(vertices, indices, 36, 36);
	meshList.push_back(obj9);

	
}

void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f);

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);

	// Loop until window closed
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime(); // SDL_GetPerformanceCounter();
		deltaTime = now - lastTime; // (now - lastTime)*1000/SDL_GetPerformanceFrequency();
		lastTime = now;

		// Get + Handle User Input
		glfwPollEvents();

		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();

		bool* keys_angles = mainWindow.getsKeys();
		//headAngle += 0.01f;
		//float sum = 0.03;
		if (keys_angles[GLFW_KEY_O])
		{
			gradtorzo += 0.03;
			//headAngle += sumahead;
		}
		 //headAngle = 20.0f;
	

		 
		if (keys_angles[GLFW_KEY_P])
		{
			// Angulos de rotación 
			// cabeza
			headAngle += sumahead;
			if (headAngle >= 45.0f) {
				sumahead = -0.03f;
			}
			if (headAngle <= -45.0f) {
				sumahead = 0.03f;
			}
			
			// brazo derecho
			gradbrazoder -= sumabrazoder;
			if (gradbrazoder <= -90.0f) {
				sumabrazoder = -0.03f;
			}
			if (gradbrazoder >= 0) {
				sumabrazoder = 0.03;
			}

			// brazo izquierdo
			gradbrazoizq -= sumabrazoizq;
			if (gradbrazoizq <= -90.0f) {
				sumabrazoizq = -0.03f;
			}
			if (gradbrazoizq >= 0.0f) {
				sumabrazoizq = 0.03f;
			}

			// antebrazo derecho
			gradantebrader -= sumaantebrader;
			if (gradantebrader <= -75.0f) {
				sumaantebrader = -0.03f;
			}
			if (gradantebrader >= 0.0f) {
				sumaantebrader = 0.03;
			}

			// antebrazo izquierdo
			gradantebraizq -= sumaantebraizq;
			if (gradantebraizq <= -45.0f) {
				sumaantebraizq = -0.03f;
			}
			if (gradantebraizq >= 0.0f) {
				sumaantebraizq = 0.03f;
			}
			
			// pierna derecha
			gradpiernader -= sumapiernader;
			if (gradpiernader <= -35.0f) {
				sumapiernader = -0.03f;
			}
			if (gradpiernader >= 0.0f) {
				sumapiernader = 0.03f;
			}

			// pierna izquierda
			gradpiernaizq -= sumapiernaizq;
			if (gradpiernaizq <= -45.0f) {
				sumapiernaizq = -0.03f;
			}
			if (gradpiernaizq >= 0.0f) {
				sumapiernaizq = 0.03f;
			}

			// rodilla derecha
			gradrodider += sumarodider;
			if (gradrodider >= 35.0f) {
				sumarodider = -0.03f;
			}
			if (gradrodider <= 0.0f) {
				sumarodider = 0.03;
			}

			// rodilla izquierda
			gradrodizq += sumarodizq;
			if (gradrodizq >= 25.0f) {
				sumarodizq = -0.03f;
			}
			if (gradrodizq <= 0.0f) {
				sumarodizq = 0.03f;
			}
			 
			// pie derecho
			gradpieder += sumapieder;
			if (gradpieder >= 15.0f) {
				sumapieder = -0.03f;
			}
			if (gradpieder <= -15.0f) {
				sumapieder = 0.03f;
			}

			// pie izquierdo
			gradpieizq += sumapieizq;
			if (gradpieizq >= 15.0f) {
				sumapieizq = -0.03f;
			}
			if (gradpieizq <= -15.0f) {
				sumapieizq = 0.03f;
			}

			// cadera
			gradcadera += sumacadera;
			if (gradcadera >= 10.0f) {
				sumacadera = -0.03f;
			}
			if (gradcadera <= -10.0f) {
				sumacadera = 0.03f;
			}

			// mano derecha
			gradmanoder += sumamanoder;
			if (gradmanoder >= 35.0f) {
				sumamanoder = -0.03f;
			}
			if (gradmanoder <= -35.0f) {
				sumamanoder = 0.03f;
			}

			// mano izquierda
			gradmanoizq += sumamanoizq;
			if (gradmanoizq >= 35.0f) {
				sumamanoizq = -0.03f;
			}
			if (gradmanoizq <= -35.0f) {
				sumamanoizq = 0.03f;
			}
		}
		//brazo derecho stack

		glm::mat4 model_brazoder(1.0f); // matriz brazo der
		glm::mat4 model_brazoizq(1.0f); // matriz brazo izq
		glm::mat4 model_piernader(1.0f); // matriz pierna der
		glm::mat4 model_piernaizq(1.0f); // matriz pierna izq
		glm::mat4 model_head(1.0f); // matriz cabeza

		//brazo derecho stack

		std::stack<glm::mat4> THBder; // torso_hombro_brazo_derecho

		std::stack<glm::mat4> THBizq; // torso_hombro_brazo_izquierdo

		std::stack<glm::mat4> TPder; // torso_pierna_der

		std::stack<glm::mat4> TPizq;// torso_pierna_der

		std::stack<glm::mat4> THC;//torso_hombro_cabeza

		// brazos
		THBder.push(model_brazoder);
		THBder.push(model_brazoizq);

		//piernas
		TPder.push(model_piernader);
		TPizq.push(model_piernaizq);

		//Cabeza
		THC.push(model_head);

		// TORZO
		model_brazoder = glm::translate(model_brazoder, glm::vec3(2.5, 0, 1.5));
		model_brazoder = glm::rotate(model_brazoder, gradtorzo * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_brazoder = glm::translate(model_brazoder, glm::vec3(-2.5, 0, -1.5));

		//padre de los nodos de el resto del cuerpo
		model_brazoizq = model_brazoder;
		model_piernader = model_brazoder;
		model_piernaizq = model_brazoder;
		model_head = model_brazoder;
		// 
		//Iniciamos los stacks
		THBder.push(model_brazoder);
		THBizq.push(model_brazoizq);
		TPder.push(model_piernader);
		TPizq.push(model_piernaizq);
		THC.push(model_head);


		//final TORZO

		//Cadera

		model_piernader = glm::translate(model_piernader, glm::vec3(2.5, 0.0f, 1.5));
		model_piernader = glm::rotate(model_piernader, gradcadera * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_piernader = glm::translate(model_piernader, glm::vec3(-2.5, -1.5, -1.5));

		model_piernaizq = model_piernader;

		TPder.push(model_piernader);
		TPizq.push(model_piernaizq);
		

		// PIERNAS

		//Pierna Derecha
		model_piernader = glm::translate(model_piernader, glm::vec3(1.25f, 0.0f, 1.5f));
		model_piernader = glm::rotate(model_piernader, gradpiernader * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model_piernader = glm::translate(model_piernader, glm::vec3(-1.25f,-5.0f , -1.5));
		TPder.push(model_piernader);
		//model_brazoizq = model_brazoder;

		

		//Rodilla derecha
		model_piernader = glm::translate(model_piernader, glm::vec3(1.25f, 0.0f, 1.5f));
		model_piernader = glm::rotate(model_piernader, gradrodider * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model_piernader = glm::translate(model_piernader, glm::vec3(-1.0f, -4.5f, -1.5f));
		TPder.push(model_piernader);

		//Pie derecho
		model_piernader = glm::translate(model_piernader, glm::vec3(1.0f, 0.0f, 1.5f));
		model_piernader = glm::rotate(model_piernader, gradpieder * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_piernader = glm::translate(model_piernader, glm::vec3(-1.0f, -1.0f, -1.5f));
		TPder.push(model_piernader);


		//Pierna Izquierda
		model_piernaizq = glm::translate(model_piernaizq, glm::vec3(3.75f, 0.0f, 1.5f));
		model_piernaizq = glm::rotate(model_piernaizq, gradpiernaizq * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model_piernaizq = glm::translate(model_piernaizq, glm::vec3(-1.25f, -5.0f, -1.5));
		TPizq.push(model_piernaizq);
		//model_brazoizq = model_brazoder;


		//Rodilla izquierda
		model_piernaizq = glm::translate(model_piernaizq, glm::vec3(1.25f, 0.0f, 1.5f));
		model_piernaizq = glm::rotate(model_piernaizq, gradrodizq * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model_piernaizq = glm::translate(model_piernaizq, glm::vec3(-1.0f, -4.5f, -1.5f));
		TPizq.push(model_piernaizq);

		//Pie izquierdo
		model_piernaizq = glm::translate(model_piernaizq, glm::vec3(1.0f, 0.0f, 1.5f));
		model_piernaizq = glm::rotate(model_piernaizq, gradpieizq * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_piernaizq = glm::translate(model_piernaizq, glm::vec3(-1.0f, -1.0f, -1.5f));
		TPizq.push(model_piernaizq);

		//THBizq.push(model_brazoizq);


		//FINAL PIERNAS
		// .......
		// IMPRIMIR PIERNAS
		
		// pie derecho
		glm::mat4 modelpieder(1.0f);
		modelpieder = glm::scale(TPder.top(), glm::vec3(2.0f, 1.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelpieder));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPder.pop();

		// Rodilla derecha
		glm::mat4 modelrodillader(1.0f);
		modelrodillader = glm::scale(TPder.top(), glm::vec3(2.0f, 4.5f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelrodillader));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPder.pop();

		// Pierna derecha
		glm::mat4 modelpiernader(1.0f);
		modelpiernader = glm::scale(TPder.top(), glm::vec3(2.5f, 5.0f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelpiernader));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPder.pop();

		// pie izquierdo
		glm::mat4 modelpieizq(1.0f);
		modelpieizq = glm::scale(TPizq.top(), glm::vec3(2.0f, 1.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelpieizq));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPizq.pop();

		// Rodilla izquierda
		glm::mat4 modelrodillaizq(1.0f);
		modelrodillaizq = glm::scale(TPizq.top(), glm::vec3(2.0f, 4.5f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelrodillaizq));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPizq.pop();

		// Pierna izquierda
		glm::mat4 modelpiernaizq(1.0f);
		modelpiernaizq = glm::scale(TPizq.top(), glm::vec3(2.5f, 5.0f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelpiernaizq));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPizq.pop();

		// Cadera
		glm::mat4 modelcadera(1.0f);
		modelcadera = glm::scale(TPder.top(), glm::vec3(5.0f, 1.5f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelcadera));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		TPder.pop();
	
		// ----
		// HOMBROS

		model_brazoder = glm::translate(model_brazoder, glm::vec3(2.5f, 7.0f, 1.5f));
		//model_brazoder = glm::rotate(model_brazoder, 0.0f * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_brazoder = glm::translate(model_brazoder, glm::vec3(-5.0f, 0.0f, -1.5f));

		model_brazoizq = model_brazoder;
		model_head = model_brazoder;

		THBder.push(model_brazoder);
		THBizq.push(model_brazoizq);
		THC.push(model_head);

		//final HOMBROS

		//CABEZA

		//Neck
		model_head = glm::translate(model_head, glm::vec3(5.0f, 2.0f, 1.5f));
		model_head = glm::rotate(model_head, headAngle * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_head = glm::translate(model_head, glm::vec3(-0.75f, 0.0f, -0.75));
		THC.push(model_head);

		//Head
		model_head = glm::translate(model_head, glm::vec3(0.75f, 1.8f, 0.75f));
		model_head = glm::rotate(model_head, 0.0f * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_head = glm::translate(model_head, glm::vec3(-1.75f, 0.0f, -1.75));
		THC.push(model_head);

		//Nariz
		model_head = glm::translate(model_head, glm::vec3(1.75f, 1.0f, 3.5f));
		model_head = glm::rotate(model_head, 0.0f * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model_head = glm::translate(model_head, glm::vec3(-0.25f, -0.25f, 0.0f));
		THC.push(model_head);


		//FINAL CABEZA
		// .......
		// IMPRIMIR CABEZA
		// Imprimir Nariz
		glm::mat4 modelnose(1.0f);
		modelnose = glm::scale(THC.top(), glm::vec3(0.5f, 0.5f, .25f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelnose));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THC.pop();


		// Imprimir Head
		glm::mat4 modelhead(1.0f);
		modelhead = glm::scale(THC.top(), glm::vec3(3.5f, 4.0f, 3.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelhead));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THC.pop();

		// Imprimir Neck
		glm::mat4 modelneck(1.0f);
		modelneck = glm::scale(THC.top(), glm::vec3(1.5f, 1.8f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelneck));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THC.pop();

		//BRAZOS
		// 
		// Brazo der
		model_brazoder = glm::translate(model_brazoder, glm::vec3(1.25f, 0.0f, 1.5f));
		model_brazoder = glm::rotate(model_brazoder, gradbrazoder * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model_brazoder = glm::translate(model_brazoder, glm::vec3(-1.25f, -3.5, -1.5));
		THBder.push(model_brazoder);

		// AnteBrazo der
		model_brazoder = glm::translate(model_brazoder, glm::vec3(1.25f, 0.0f, 1.5f));
		model_brazoder = glm::rotate(model_brazoder, gradantebrader * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model_brazoder = glm::translate(model_brazoder, glm::vec3(-1.0f, -4.0, -1.2));
		THBder.push(model_brazoder);

		// Mano Derecha
		model_brazoder = glm::translate(model_brazoder, glm::vec3(1.0f, 0.0f, 1.2f));
		model_brazoder = glm::rotate(model_brazoder, gradmanoder * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model_brazoder = glm::translate(model_brazoder, glm::vec3(-0.5f, -1.0, -0.5));
		THBder.push(model_brazoder);

		// Brazo izq
		model_brazoizq = glm::translate(model_brazoizq, glm::vec3(8.75f, 0.0f, 1.5f));
		model_brazoizq = glm::rotate(model_brazoizq, gradbrazoizq * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model_brazoizq = glm::translate(model_brazoizq, glm::vec3(-1.25f, -3.5, -1.5));
		THBizq.push(model_brazoizq);

		// AnteBrazo izq
		model_brazoizq = glm::translate(model_brazoizq, glm::vec3(1.25f, 0.0f, 1.5f));
		model_brazoizq = glm::rotate(model_brazoizq, gradantebraizq * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model_brazoizq = glm::translate(model_brazoizq, glm::vec3(-1.0f, -4.0, -1.2));
		THBizq.push(model_brazoizq);

		// Mano izquierda
		model_brazoizq = glm::translate(model_brazoizq, glm::vec3(1.0f, 0.0f, 1.2f));
		model_brazoizq = glm::rotate(model_brazoizq, gradmanoizq * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model_brazoizq = glm::translate(model_brazoizq, glm::vec3(-0.5f, -1.0, -0.5));
		THBizq.push(model_brazoizq);


		//IMPRIMIR BRAZOS

		//imprimir mano izq
		glm::mat4 modelmanoizq(1.0f);
		modelmanoizq = glm::scale(THBizq.top(), glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelmanoizq));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBizq.pop();

		//imprimir antebrazo IZQ
		glm::mat4 modelantebrazoizq(1.0f);
		modelantebrazoizq = glm::scale(THBizq.top(), glm::vec3(2.0f, 4.0f, 2.4f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelantebrazoizq));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBizq.pop();


		//imprimir brazo IZQ
		glm::mat4 modelbrazoizq(1.0f);
		modelbrazoizq = glm::scale(THBizq.top(), glm::vec3(2.5f, 3.5f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelbrazoizq));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBizq.pop();


		//imprimir mano der
		glm::mat4 modelmanoder(1.0f);
		modelmanoder = glm::scale(THBder.top(), glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelmanoder));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBder.pop();

		//imprimir antebrazo der
		glm::mat4 modelantebrazoder(1.0f);
		modelantebrazoder = glm::scale(THBder.top(), glm::vec3(2.0f, 4.0f, 2.4f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelantebrazoder));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBder.pop();


		//imprimir brazo der
		glm::mat4 modelbrazoder(1.0f);
		modelbrazoder = glm::scale(THBder.top(), glm::vec3(2.5f, 3.5f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelbrazoder));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBder.pop();

		// imprimir hombro
		glm::mat4 modelhombro(1.0f);
		modelhombro = glm::scale(THBder.top(), glm::vec3(10.0f, 2.0f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelhombro));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();
		THBder.pop();
		// imprimir torzo
		glm::mat4 modeltorso(1.0f);
		modeltorso = glm::scale(THBder.top(), glm::vec3(5.0f, 7.0f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modeltorso));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();

		THBder.pop();



		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}