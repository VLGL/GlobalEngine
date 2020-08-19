#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <string>
#include <memory>
#include <iostream>

#include <graphics/model.h>
#include <graphics/openglwindow.h>
#include <graphics/gamescene.h>

enum class EngineAPI: int8_t
{
	OpenGL_API = 0,
	Vulkan_API = 1,
};

class GlobalEngine final
{
	private:
		std::unique_ptr<IWindow> m_window;
		std::shared_ptr<GameScene> m_game_scene;

	private:
		void initGLFW() const;
		void initGLEW() const;
		void render(const Model& model) const;

	public:
		explicit GlobalEngine(EngineAPI api,
		                      std::string title,
		                      unsigned int width,
		                      unsigned int height);
		~GlobalEngine();
		void pollEvents() const;
		void gameLoop() const;
		void setGameScene(GameScene * gameScene);
		void addGameObject(Model * gameObject);
};
