#include <exception>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "graphics/OpenGL/GLShader.h"

namespace GE
{

	Shared<IShader> GLShaderFactory::createShader(Path vertex,
	                                              Path fragment)
	{
		namespace fs = std::filesystem;

		if (!fs::exists(vertex))
			throw std::runtime_error("Shader path " + vertex.native() + " does not exist.\n");

		if (!fs::exists(fragment))
			throw std::runtime_error("Shader path " + fragment.native() + " does not exist.\n");

		GLuint m_id_vertex = glCreateShader(GL_VERTEX_SHADER);

		std::ifstream file1(vertex.native());
		std::string vertex_string = createSourceStringFromFile(file1);

		compile(m_id_vertex, vertex_string.c_str());
		validate(m_id_vertex, GL_COMPILE_STATUS);

		GLuint m_id_fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::ifstream file2(fragment.native());
		std::string fragment_string = createSourceStringFromFile(file2);

		compile(m_id_fragment, fragment_string.c_str());
		validate(m_id_fragment, GL_COMPILE_STATUS);

		GLuint shader_id = glCreateProgram();
		glLinkProgram(shader_id);
		validate(shader_id, GL_LINK_STATUS);

		// glDetachShader(shader_id, m_id_vertex);
		// glDetachShader(shader_id, m_id_fragment);
		return createShared<GLShader>(shader_id);
	}

	std::string GLShaderFactory::createSourceStringFromFile(std::ifstream & file)
	{
		/* Ensures ifstream objects can throw exceptions */
		file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		assert(file.is_open());

		/* Read shader source from file */
		std::stringstream stream;
		stream << file.rdbuf();

		return stream.str();
	}

	void GLShaderFactory::compile(const GLuint id, const char* source)
	{
		glShaderSource(id, 1, &source, nullptr);
		glCompileShader(id);
	}

	void GLShaderFactory::validate(const GLuint id, const GLenum validationPoint)
	{
		GLint operationSuccessful;

		glGetProgramiv(id, validationPoint, &operationSuccessful);

		if (operationSuccessful == GL_FALSE)
		{
			// Figure out the maximum size of buffer
			GLint maxLength = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

			// Pull the error message
			std::vector<GLchar> infoLog;
			infoLog.reserve(maxLength);
			glGetProgramInfoLog(id, maxLength, &maxLength, &infoLog[0]);

			// Print information about error
			std::copy(std::begin(infoLog), std::end(infoLog), std::ostream_iterator<GLchar>(std::cerr));
		}
	}

	GLShader::GLShader(const GLuint id) : m_id { id }
	{}

	GLShader::~GLShader()
	{
		// ??? Detach shaders prviously?
		unbind();
		glDeleteProgram(m_id);
	}

	void GLShader::bind() const
	{
		glUseProgram(m_id);
	}

	void GLShader::unbind() const
	{
		glUseProgram(0);
	}

	GLuint GLShader::getId() const noexcept
	{
		return m_id;
	}

} // GE