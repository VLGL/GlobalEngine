#include "TestApplication.h"

TestApplication::TestApplication(Unique<GlobalEngine> globalEngine) :
	GameApplication(std::move(globalEngine))
{
	 init();
}

void TestApplication::init()
{
	Shared<IShader> shader =
		ShaderCreator::createShader("examples/TestApplication/shaders/vertexShader.glsl",
		                            "examples/TestApplication/shaders/fragmentShader.glsl");

	float vertices[] =
	{
		-0.75f, -0.75f, 0.0f, // Left Bot  0
		-0.75f,  0.75f, 0.0f, // Left Top  1
		 0.75f, -0.75f, 0.0f, // Right Bot 2
		 0.75f,  0.75f, 0.0f  // Right Top 3
	};

	uint indexes[] =
	{
		2, 3, 0, 0, 1, 3
	};

	float textCoords[] =
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	/*
	Shared<GLModel> cubeModel = GLModel::ModelBuilder()
		.addVertexBuffer(GLVertexBuffer(vertices, std::size(vertices)))
		.addIndexBuffer(GLIndexBuffer(indexes, std::size(indexes)))
		.addTextureBuffer(GLTextureBuffer(textCoords, std::size(textCoords)))
		.build();
	*/
	auto wallTexture = createShared<GLTexture>("examples/TestApplication/res/wall.jpg");

	auto cubeTexturedModel =
		createShared<GLTexturedModel>(cubeModel, wallTexture);

	auto cubeEntity =
		createShared<Entity>(cubeTexturedModel,
		                     shader,
		                     glm::vec3(0.0f, 0.0f, -1.5f),
		                     glm::vec3(0.f),
		                     glm::vec3(1.f));

	auto gameScene = createShared<GameScene>();
	gameScene->addGameObject(cubeEntity);

	m_globalEngine->setGameScene(gameScene);

	auto camera = createShared<Camera>(glm::vec3(0.0f, 0.0f, 0.001f));

	m_globalEngine->setCamera(camera);
}

void TestApplication::startGameLoop()
{
	m_globalEngine->startGameLoop();
}
