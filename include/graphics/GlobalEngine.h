#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <string>
#include <memory>
#include <iostream>

#include <graphics/GameObject.h>
#include <graphics/OpenGLWindow.h>
#include <graphics/GameScene.h>

enum class EngineAPI: int8_t
{
	OpenGL_API = 0,
	Vulkan_API = 1,
};

class GlobalEngine final
{
	public:
		GlobalEngine(EngineAPI api,
		             std::string title,
		             unsigned int width,
		             unsigned int height);
		~GlobalEngine();
		void pollEvents() const;
		void gameLoop() const;
		void addGameObject(std::unique_ptr<GameObject> game_object);

	private:
		void initGLFW() const;
		void initGLEW() const;
		void render() const;

	private:
		std::unique_ptr<Window> m_window;
		std::unique_ptr<GameScene> m_game_scene;
};
