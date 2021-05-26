#pragma once

#include <vector>

#include <GL/glew.h>

#include "core/Memory.h"
#include "graphics/IDrawable.h"
#include "graphics/OpenGL/GLVertexArrayObject.h"

namespace GE
{
	// Preferable way of creation is via Builder
	class Model : public IDrawable
	{
		public:
			class ModelBuilder;

			Model() = delete;
			~Model();
			Model(const float * vertexPositions,
			      const unsigned vertexCount,
			      const unsigned * indexesData,
			      const unsigned indexesCount,
			      const float * textureCoordinates,
			      const unsigned textCoordsCount);

			void draw() const override;

		private:
			void storeDataToVBO(const unsigned attribIndex,
			                    const unsigned size,
			                    const float * data,
			                    const unsigned dataCount);
			void storeDataToIndexBuffer(const unsigned * indexesData,
			                            const unsigned   indexesCount);


		private:
			std::vector<GLuint> m_vbos;
			GLVertexArrayObject m_vao;
			unsigned m_indexesCount { 0 };
	};

	class Model::ModelBuilder
	{
		public:
			ModelBuilder & addVertexBuffer(float * vertexPositions,
			                               const unsigned vertexCount);
			ModelBuilder & addIndexBuffer(unsigned * indexesData,
			                              const unsigned indexesCount);
			ModelBuilder & addTextureData(float * textureCoordinates,
			                              const unsigned textCoordsCount);
			[[nodiscard]] Unique<Model> build();

		private:
			float * m_vertexPositions    = nullptr;
			float * m_textureCoordinates = nullptr;
			unsigned * m_indexesData     = nullptr;
			unsigned m_vertexCount     { 0 };
			unsigned m_indexesCount    { 0 };
			unsigned m_textCoordsCount { 0 };
	};

} // GE
