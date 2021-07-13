#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "core/Memory.h"
#include "core/GameApplication.h"
#include "core/EngineArgs.h"
#include "core/GlobalEngine.h"

#include "graphics/Entity.h"
#include "graphics/IModel.h"
#include "graphics/Camera.h"
#include "graphics/IShader.h"
#include "graphics/ShaderCreator.h"
#include "graphics/GameScene.h"

#include "graphics/OpenGL/GLModel.h"
#include "graphics/OpenGL/GLTexture.h"
#include "graphics/OpenGL/GLTexturedModel.h"
#include "graphics/OpenGL/GLVertexBuffer.h"
#include "graphics/OpenGL/GLTextureBuffer.h"
#include "graphics/OpenGL/GLIndexBuffer.h"

using namespace GE;

class TestApplication : public GameApplication
{
	public:
		explicit TestApplication(Unique<GlobalEngine> globalEngine);

		// Actions
		void startGameLoop() override;

	protected:
		void init() override;
};
