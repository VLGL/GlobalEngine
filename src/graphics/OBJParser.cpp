#include "graphics/OBJParser.h"

namespace GE
{

	Unique<Model> OBJParser::parseObj(const path & objPath)
	{
		if (!std::filesystem::exists(objPath))
			throw std::runtime_error("The .obj filepath \"" + objPath.native() + "\" does not exist!");

		return parseObjImpl(objPath);
	}

	Unique<Model> OBJParser::parseObjImpl(const path & objPath)
	{
		std::ifstream file(objPath.native());

		if (!file.is_open())
			throw std::runtime_error(".obj file isn't open!");

		std::vector<VertexCoordinates> vertexCoordsVec;
		std::vector<TextureUV> texturesVec;
		std::vector<Normals> normalsVec;
		std::stringstream sstream;
		std::string line, temp;
		float x, y, z, u, v;

		GLfloat* vertexCoordsArray = nullptr;
		GLfloat* texturesArray     = nullptr;
		GLuint*  indexesArray      = nullptr;

		while (std::getline(file, line))
		{
			if (line.empty()) continue;
			sstream.str(line);

			sstream >> temp;
			if (temp == "v")
			{
				sstream >> x;
				sstream >> y;
				sstream >> z;
				vertexCoordsVec.emplace_back(std::make_tuple(x, y, z));
			}
			else if (temp == "vt")
			{
				sstream >> u;
				sstream >> v;
				texturesVec.emplace_back(std::make_pair(u, v));
			}
			else if (temp == "vn")
			{
				sstream >> x;
				sstream >> y;
				sstream >> z;
				normalsVec.emplace_back(std::make_tuple(x, y, z));
			}
			else if (temp == "f")
			{
				vertexCoordsArray = new GLfloat[vertexCoordsVec.size() * 3];
				texturesArray = new GLfloat[texturesVec.size() * 2];
				indexesArray  = new GLuint[texturesVec.size()];

				processVertex(line, vertexCoordsVec, texturesVec, vertexCoordsArray, texturesArray, indexesArray);
				goto skip;
			}
		}

		skip:
		while (std::getline(file, line))
			processVertex(line, vertexCoordsVec, texturesVec, vertexCoordsArray, texturesArray, indexesArray);

		return Model::ModelBuilder()
		       .addVertexBuffer(vertexCoordsArray, vertexCoordsVec.size() * 3)
		       .addTextureData(texturesArray, texturesVec.size() * 2)
		       .addIndexBuffer(indexesArray, vertexCoordsVec.size())
		       .build();
	}

	void OBJParser::processVertex(const std::string& vertexLine,
	                              const std::vector<VertexCoordinates>& vertexCoordsVec,
	                              const std::vector<TextureUV>& texturesVec,
	                              GLfloat* vertexCoordsArray,
	                              GLfloat* texturesArray,
	                              GLuint*  indexesArray)
	{
		static unsigned offset;

		std::vector<std::string> vertex;
		std::vector<std::string> values;
		boost::split(vertex, vertexLine, boost::is_any_of(" "), boost::algorithm::token_compress_on);

		for (int i = 1; i <= 3; ++i)
		{
			boost::split(values, vertex[i], boost::is_any_of("/"), boost::algorithm::token_compress_on);

			auto vertexCoordIndex = static_cast<unsigned>(std::stoi(values[0])) - 1;

			indexesArray[offset] = vertexCoordIndex;
			auto [x, y, z] = vertexCoordsVec[vertexCoordIndex];

			vertexCoordsArray[offset * 3] = x;
			vertexCoordsArray[offset * 3 + 1] = y;
			vertexCoordsArray[offset * 3 + 2] = z;

			auto textureIndex = static_cast<unsigned>(std::stoi(values[1])) - 1;
			auto [u, v] = texturesVec[textureIndex];

			texturesArray[offset * 2] = u;
			texturesArray[offset * 2 + 1] = 1 - v;

			++offset;
		}
	}

} // GE
