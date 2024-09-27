#include "Buffer.h"

Buffer::Buffer() 
{
	glGenVertexArrays(1, &VAO);  
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);  
	glGenBuffers(1, &EBO);  

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void Buffer::Set_Data_Vertex_Buffer_Object(float* Verts, size_t vert_size)
{
	glBufferData(GL_ARRAY_BUFFER, vert_size, Verts, GL_STATIC_DRAW);
}

void Buffer::UnBind_VAO() {
	glBindVertexArray(0);
}void Buffer::Bind_VAO() {
	glBindVertexArray(VAO);
}


void Buffer::Set_Data_Element_Object(int* indices, size_t indices_size)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size, indices, GL_STATIC_DRAW);
}

void Buffer::LinkAttrib(GLuint index, GLuint size, GLenum type, GLsizei stride, GLvoid* offset) 
{
	glVertexAttribPointer(index, size, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(index);
}

