#include "graphics/OpenGL/GLModel.h"
#include "graphics/OpenGL/GLIndexBuffer.h"

namespace GE
{

	using Builder = GLModel::ModelBuilder;

	// Model class

	GLModel::GLModel(GLVertexBuffer&& vertexBuffer,
	                 GLIndexBuffer&& indexBuffer,
	                 GLTextureBuffer&& textureBuffer)
	{
		m_vao.bind();

		m_vertexBuffer  = std::move(vertexBuffer);
		m_indexBuffer   = std::move(indexBuffer);
		m_textureBuffer = std::move(textureBuffer);

		m_vao.unbind();
	}

	void GLModel::draw() const
	{
		m_vao.bind();

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glDrawElements(GL_TRIANGLES, m_indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		m_vao.unbind();
	}

	// ModelBuilder class

	Builder & Builder::addVertexBuffer(GLVertexBuffer&& vertexBuffer)
	{
		m_vertexBuffer = std::move(vertexBuffer);

		return *this;
	}

	Builder & Builder::addIndexBuffer(GLIndexBuffer&& indexBuffer)
	{
		m_indexBuffer = std::move(indexBuffer);

		return *this;
	}

	Builder & Builder::addTextureBuffer(GLTextureBuffer&& textureBuffer)
	{
		m_textureBuffer = std::move(textureBuffer);

		return *this;
	}

	Unique<GLModel> Builder::build()
	{
		return createUnique<GLModel>(
			std::move(m_vertexBuffer),
			std::move(m_indexBuffer),
			std::move(m_textureBuffer));
	}

} // GE
