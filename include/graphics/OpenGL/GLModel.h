#pragma once

#include <vector>

#include <GL/glew.h>

#include "core/Memory.h"
#include "graphics/IModel.h"
#include "graphics/OpenGL/GLVertexArrayObject.h"
#include "graphics/OpenGL/GLIndexBuffer.h"
#include "graphics/OpenGL/GLTextureBuffer.h"
#include "graphics/OpenGL/GLVertexBuffer.h"

namespace GE
{

	// Preferable way of creation is via Builder
	class GLModel final : public IModel
	{
		public:
			class ModelBuilder;

			GLModel() = delete;
			GLModel(GLVertexBuffer&& vertexBuffer,
					GLIndexBuffer&& indexBuffer,
			        GLTextureBuffer&& textureBuffer);

			void draw() const override;

		private:
			GLVertexArrayObject m_vao;
			GLIndexBuffer       m_indexBuffer;
			GLTextureBuffer     m_textureBuffer;
			GLVertexBuffer      m_vertexBuffer;
	};

	class GLModel::ModelBuilder final
	{
		public:
			ModelBuilder & addVertexBuffer(GLVertexBuffer&& vertexBuffer);
			ModelBuilder & addIndexBuffer(GLIndexBuffer&& indexBuffer);
			ModelBuilder & addTextureBuffer(GLTextureBuffer&& textureBuffer);
			[[nodiscard]] Unique<GLModel> build();

		private:
			GLIndexBuffer   m_indexBuffer;
			GLTextureBuffer m_textureBuffer;
			GLVertexBuffer  m_vertexBuffer;
	};

} // GE
