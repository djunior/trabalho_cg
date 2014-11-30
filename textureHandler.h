#ifndef __TEXTURE_HANDLER_H__
#define __TEXTURE_HANDLER_H__

#include <iostream>
#include <map>
#include <GL/glut.h>

class TextureHandler{
private:
	GLuint loadTexture(const char*);

	std::map<std::string, GLuint> textureMap;
	bool enabled;

public:
	TextureHandler();
	~TextureHandler();

	GLuint getTextureId(std::string);
	void enable();
	void disable();
	bool isEnabled();
	void glTexCoord2f(float,float);
};

#endif