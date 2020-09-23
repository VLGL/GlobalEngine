#include <graphics/Model.h>

using Builder = Model::ModelBuilder;

Model::Model()
{
	createVAO();
	createVBO();
}

Builder::ModelBuilder()
{
	m_model = std::make_shared<Model>();
}

Model::~Model()
{
	glDeleteVertexArrays(1, &m_vao_id);
	glDeleteBuffers(2, m_vbos);
}

void Model::createVAO()
{
	glGenVertexArrays(1, &m_vao_id);
}

void Model::createVBO()
{
	glGenBuffers(2, m_vbos);
}

void Builder::dataToVBO(const float data[])
{
	glBindBuffer(GL_ARRAY_BUFFER, m_model->m_vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, m_model->m_vertex_count * sizeof(float), data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Builder & Builder::addVertexBuffer(const float positions[],
                                   const unsigned int vertex_count)
{
	m_model->m_vertex_count = vertex_count;
	glBindVertexArray(m_model->m_vao_id);
	dataToVBO(positions);
	glBindVertexArray(0);

	return *this;
}

Builder & Builder::addIndexBuffer(const unsigned int indexes[],
                                  const unsigned int indexes_count)
{
	m_model->m_indexes_count = indexes_count;
	glBindVertexArray(m_model->m_vao_id);
	dataToInd(indexes);
	glBindVertexArray(0);

	return *this;
}

void Builder::dataToInd(const unsigned int data[])
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_model->m_vbos[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_model->m_indexes_count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

void Model::draw() const
{
	glBindVertexArray(m_vao_id);
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, m_indexes_count, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

std::shared_ptr<Model> Builder::create()
{
	return m_model;
}
