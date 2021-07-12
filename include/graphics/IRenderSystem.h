#pragma once

#include <glm/glm.hpp>

#include "core/Memory.h"

namespace GE
{
	class GameScene;
	class Camera;

	enum class RendererAPI : int8_t
	{
		UNDEFINED = -1,
		OpenGL    =  0
	};

	class IRenderSystem
	{
		public:
			virtual ~IRenderSystem() = default;

			virtual void render(const GameScene & gameScene,
			                    const Camera    & camera) = 0;
			virtual glm::mat4 createModelMatrix(const glm::vec3 & translation,
			                                    const glm::vec3 & rotation,
			                                    const glm::vec3 & scaling) = 0;
			virtual glm::mat4 createProjectionMatrix() = 0;
			virtual glm::mat4 createViewMatrix(const Camera & camera)  = 0;
			virtual void prepareGameScene(const GameScene & gameScene) = 0;
			static RendererAPI getRendererAPI() { return m_api; };

		protected:
			const static RendererAPI m_api { RendererAPI::OpenGL };
	};

} // GE
