#pragma once

#include <glm/glm.hpp>

#include "core/Memory.h"

namespace GE
{

	class GameScene;
	class Camera;

	class IRenderSystem
	{
		public:
			virtual ~IRenderSystem() = default;

			virtual void render(Shared<GameScene> gameScene,
			                    Shared<Camera>    camera) = 0;
			virtual glm::mat4 createModelMatrix(const glm::vec3 & translation,
			                                    const glm::vec3 & rotation,
			                                    const glm::vec3 & scaling) = 0;
			virtual glm::mat4 createProjectionMatrix() = 0;
			virtual glm::mat4 createViewMatrix(const Shared<Camera> & camera) = 0;
			virtual void prepareGameScene(Shared<GameScene> gameScene) = 0;
	};

} // GE
