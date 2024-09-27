#ifndef OPENGL_BUFFER
#define OPENGL_BUFFER

#include<glad/glad.h>
#include "GLFW/glfw3.h"


class Buffer {
public:
	GLuint VAO, VBO, EBO;
	Buffer();
	void Set_Data_Vertex_Buffer_Object(float* Verts, size_t vert_size);

	void UnBind_VAO();

	void Bind_VAO();

	void Set_Data_Element_Object(int* indices, size_t indices_size);

	void LinkAttrib(GLuint index, GLuint size, GLenum type, GLsizei stride, GLvoid* offset);

	

};

#endif