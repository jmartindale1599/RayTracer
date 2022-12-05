#pragma once

#include"Renderer/Canvas.h"

#include "Math/Ray.h"

#include "Objects/Objects.h"

#include<SDL.h>

class Renderer{

public:

	Renderer() = default;

	bool Initialize();

	void Shutdown();

	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);

	void Render(Canvas& canvas, Object* object);

	void Present();

	friend class Canvas;

private:

	color3 GetBackgroundFromRay(const Ray& ray);

	SDL_Renderer* m_renderer{ nullptr };

	SDL_Window* m_window{ nullptr };

};
