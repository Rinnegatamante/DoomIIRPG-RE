#ifndef __SDLGL_H__
#define __SDLGL_H__

#include <SDL.h>
#ifdef __vita__
#include <vitaGL.h>
#else
#include <SDL_opengl.h>
#include <SDL_opengles2.h>
#include <GL/gl.h>
#endif

typedef struct SDLResVidModes_s {
	int width, height;
} SDLResVidModes;
extern SDLResVidModes sdlResVideoModes[18];

class SDLGL
{
private:
	bool initialized;
	SDL_GLContext glcontext;

public:
	SDL_Window* window;
	int resolutionIndex;
	int oldResolutionIndex;
	int winVidWidth, winVidHeight;
	int vidWidth, vidHeight;
	int windowMode, oldWindowMode;
	bool vSync, oldVSync;

	SDLGL();
	// Destructor
	~SDLGL();
	bool Initialize();
	void Error(const char* fmt, ...);

	void transformCoord2f(float* x, float* y);
	void centerMouse(int x, int y);
	void updateWinVid(int w, int h);
	void updateVideo();
	void restore();
};

#endif