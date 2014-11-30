#include "textureHandler.h"

TextureHandler::TextureHandler(){

}

TextureHandler::~TextureHandler(){

}

GLuint TextureHandler::getTextureId(std::string s){
	std::map<std::string,GLuint>::iterator it;

	it = textureMap.find(s);

	if (it == textureMap.end())	{
		GLuint tId = loadTexture(s.c_str());
		textureMap.insert(std::pair<std::string,GLuint>(s,tId));
		return tId;
	}

	return it->second;
}

GLuint TextureHandler::loadTexture( const char * filename )
{

    GLuint texture;

    int width, height;

    unsigned char * data;

    FILE * file;

    file = fopen( filename, "rb" );

    if ( file == NULL ) return 0;
    width = 1024;
    height = 512;
    data = (unsigned char *)malloc( width * height * 3 );
    //int size = fseek(file,);
    fread( data, width * height * 3, 1, file );
    fclose( file );

    for(int i = 0; i < width * height ; ++i)
    {
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;

    }

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
    free( data );

    return texture;
}

void TextureHandler::enable(){
	enabled = true;
}

void TextureHandler::disable(){
	enabled = false;
}

bool TextureHandler::isEnabled(){
	return enabled;
}

void TextureHandler::glTexCoord2f(float s, float t){
	if (enabled)
		glTexCoord2f(s,t);
}


