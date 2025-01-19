#ifndef __IMAGE_H__
#define __IMAGE_H__

#ifdef __vita__
#include <vitaGL.h>
#else
#include <SDL_opengl.h>
#endif

class IDIB;

class Image
{
private:

public:
	uint32_t index;
	IDIB* piDIB;
	int width;
	int height;
	int depth;
	bool isTransparentMask;
	int texWidth;
	int texHeight;
	GLuint texture;

	// Constructor
	Image();
	// Destructor
	~Image();

	void CreateTexture(uint16_t* data, uint32_t width, uint32_t height);
	void DrawTexture(int texX, int texY, int texW, int texH, int posX, int posY, int rotateMode, int renderMode);
	void setRenderMode(int renderMode);
};

#endif