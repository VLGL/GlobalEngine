#pragma once

#include <filesystem>
#include <exception>

#include "graphics/OpenGL/GLShader.h"

namespace GE
{

	class ShaderCreator
	{
		public:
			static Shared<IShader> createShader(Path vertex, Path fragment)
			{
				static Unique<IShaderFactory> factory =
					selectFactory(IRenderSystem::getRendererAPI());

				return factory->createShader(vertex, fragment);
			}

		private:
			static Unique<IShaderFactory> selectFactory(RendererAPI api)
			{
				Unique<IShaderFactory> factory { nullptr };

				switch (api)
				{
					case RendererAPI::OpenGL:
						factory = createUnique<GLShaderFactory>();
						break;

					case RendererAPI::UNDEFINED:
						//std::cerr << "Error\n";
						// Use exception instead
						break;

					default:
						//std::cerr << "Error\n";
						// Use exception instead
						break;
				}

				return factory;
			}
	};

}
