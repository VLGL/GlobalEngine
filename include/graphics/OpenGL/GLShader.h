#pragma once

#include <string>
#include <fstream>
#include <filesystem>

#include <GL/glew.h>

#include "graphics/IShader.h"
#include "core/Memory.h"

namespace GE
{

	class GLShader final : public IShader
	{
		public:
			GLShader(const GLuint id);
			~GLShader();

			void bind()   const override;
			void unbind() const override;
			GLuint getId() const noexcept;

		private:
			const GLuint m_id;
	};

	class GLShaderFactory final : public IShaderFactory
	{
		public:
			Shared<IShader> createShader(Path vertex,
			                             Path fragment) override;

		private:
			std::string createSourceStringFromFile(std::ifstream & file);
			void compile(const GLuint id, const char* source);
			void validate(const GLuint id, const GLenum validationPoint);
	};

} // GE
