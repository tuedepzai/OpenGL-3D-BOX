#pragma once
#include "glad/glad.h"
#include "stb_image.h"

class Texture {
public:
	int widthImg, heightImg, numColCh;
	GLuint texture;
	Texture(const char* textureLocation);
	void BindTexture();
};