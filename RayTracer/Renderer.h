#pragma once

#include"Renderer/Canvas.h"

#include<SDL.h>

class Renderer{

public:

	Renderer() = default;

	bool Initialize();

	void Shutdown();

	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);

	void Present();

	friend class Canvas;

private:

	SDL_Renderer* m_renderer{ nullptr };

	SDL_Window* m_window{ nullptr };

};
