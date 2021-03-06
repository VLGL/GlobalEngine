#pragma once

#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <filesystem>

#include <GL/glew.h>

#include "core/Memory.h"
#include "graphics/ValidationDefaultStrategy.h"

namespace GE
{

	namespace fs = std::filesystem;
	using path = std::filesystem::path;

	enum class ShaderType : GLenum
	{
		Undefined      = 0,
		VertexShader   = GL_VERTEX_SHADER,
		FragmentShader = GL_FRAGMENT_SHADER
	};

	class Shader
	{
		public:
			class ShaderBuilder;

			Shader() = delete;
			Shader(const path & shaderPath,
			       Shared<IValidationStrategy> validationStrategy,
			       const ShaderType & shaderType);
			virtual ~Shader() = default;

			// Forbid copy semantics
			Shader(const Shader &)             = delete;
			Shader & operator=(const Shader &) = delete;

			// Getters
			[[nodiscard]] uint getId() const;
			[[nodiscard]] ShaderType getShaderType() const;

		private:
			void validate() const;
			void compile()  const;
			void createSourceStringFromFile(std::ifstream & file);

		private:
			std::string m_source;
			ShaderType m_shaderType;
			Shared<IValidationStrategy> m_validationStrategy;
			uint m_id { 0 };
	};

	class Shader::ShaderBuilder
	{
		public:
			ShaderBuilder & setSource(const path & shaderPath);
			ShaderBuilder & setValidationStrategy(Shared<IValidationStrategy> validationStrategy);
			ShaderBuilder & setShaderType(const ShaderType & shaderType);
			[[nodiscard]] Unique<Shader> build();

		private:
			path m_shaderPath;
			Shared<IValidationStrategy> m_validationStrategy = nullptr;
			ShaderType m_shaderType { ShaderType::Undefined };
	};

} // GE
