#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/glm.hpp"

//--//
#include "config.h"
#include "ShaderClass.h"
#include "Buffer.h"
#include "Texture.h"


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	
	GLFWwindow* window = glfwCreateWindow(conf::WIDTH, conf::HEIGHT, "spiningbox", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	

	Shader ShaderProgram("Shaders/default.vert", "Shaders/default.frag");

	Buffer* buffer = new Buffer();
	buffer->Set_Data_Vertex_Buffer_Object(conf::vertices, sizeof(conf::vertices));
	buffer->Set_Data_Element_Object(conf::indicies, sizeof(conf::indicies));
	buffer->LinkAttrib(0, 3, GL_FLOAT, 8 * sizeof(float), (GLvoid*)0);
	buffer->LinkAttrib(1, 3, GL_FLOAT, 8 * sizeof(float), (GLvoid*) (3 * sizeof(float)));
	buffer->LinkAttrib(2, 2, GL_FLOAT, 8 * sizeof(float), (GLvoid*) (6 * sizeof(float)));
	buffer->UnBind_VAO();
	
	Texture* texture = new Texture("box.jpg");

	ShaderProgram.Activate();
	GLuint tex0Uniform = glGetUniformLocation(ShaderProgram.ID, "tex");
	glUniform1i(tex0Uniform, 0);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));


	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float) conf::WIDTH / conf::HEIGHT, 0.1f, 100.0f);
	
	GLuint modelUniform = glGetUniformLocation(ShaderProgram.ID, "model");
	GLuint viewUniform = glGetUniformLocation(ShaderProgram.ID, "view");
	GLuint projectionUniform = glGetUniformLocation(ShaderProgram.ID, "projection");

	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewUniform, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, glm::value_ptr(projection));

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(1.56f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(1.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, conf::WIDTH, conf::HEIGHT);
	while (!glfwWindowShouldClose(window)) {
		glClearColor(conf::BG_R / 225, conf::BG_B / 225, conf::BG_G / 225, conf::BG_A);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ShaderProgram.Activate();
		buffer->Bind_VAO();
		texture->BindTexture();

		for (int i = 0; i < 10; i++) {
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			glUniformMatrix4fv(modelUniform, 1, GL_FALSE, glm::value_ptr(model));
			glDrawElements(GL_TRIANGLES, sizeof(conf::indicies) / sizeof(int), GL_UNSIGNED_INT, 0);
		}

		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	delete buffer;
	delete texture;
	ShaderProgram.Delete();

	return 0;
}
