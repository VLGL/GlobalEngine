#pragma once

#include <vector>
#include <filesystem>
#include <fstream>
#include <exception>
#include <string>
#include <iostream>
#include <sstream>

#include <boost/algorithm/string.hpp>

#include "graphics/Model.h"

namespace GE
{

	using path = std::filesystem::path;
	using VertexCoordinates = std::tuple<float, float, float>;
	using Normals = std::tuple<float, float, float>;
	using TextureUV = std::pair<float, float>;
	using Indexes = unsigned;

	class OBJParser final
	{
		public:
			static Unique<Model> parseObj(const path & objPath);

		private:
			static Unique<Model> parseObjImpl(const path & objPath);
			static void processVertex(const std::string& vertexLine,
			                          const std::vector<VertexCoordinates>& vertexCoordsVec,
			                          const std::vector<TextureUV>& texturesVec,
			                          GLfloat* vertexCoordsArray,
			                          GLfloat* texturesArray,
			                          GLuint*  indexesArray);
	};

} // GE
