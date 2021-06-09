#pragma once

#include <glm/glm.hpp>

#include "core/Memory.h"
#include "graphics/IDrawable.h"
#include "graphics/OpenGL/GLTexturedModel.h"
#include "graphics/IShader.h"
#include "graphics/Camera.h"

namespace GE
{

	using vec3 = glm::vec3;
	using mat4 = glm::mat4;

	class Entity : public IDrawable
	{
		public:
			Entity() = default;
			~Entity() = default;

			Entity(Shared<GLTexturedModel> texturedModel,
			       Shared<IShader> shader);

			Entity(Shared<GLTexturedModel> texturedModel,
			       Shared<IShader> shader,
			       const vec3 & position,
			       const vec3 & rotation,
			       const vec3 & scaling);

			Entity(const Entity & other) = delete;
			Entity(Entity && other) noexcept;
			Entity & operator=(const Entity & other) = delete;
			Entity & operator=(Entity && other) noexcept;

			// Actions
			void rotate(const vec3 & rotation) noexcept;
			void scale(const vec3 & scale) noexcept;
			void move(const vec3 & move) noexcept;
			void draw() const override;

			// Setters
			void setShader(Shared<IShader> shader);
			void setPosition(const vec3 & position) noexcept;
			void setRotation(const vec3 & rotation) noexcept;
			void setScalingFactor(const vec3 & scalingFactor) noexcept;

			// Getters
			Shared<GLTexturedModel> getTexturedModel() const;
			Shared<IShader> getShader() const;
			const vec3 & getPosition()      const noexcept;
			const vec3 & getRotation()      const noexcept;
			const vec3 & getScalingFactor() const noexcept;

		private:
			Shared<GLTexturedModel> m_texturedModel { nullptr };
			Shared<IShader> m_shader { nullptr };

			vec3 m_position { 0.f };
			vec3 m_rotation { 0.f };
			vec3 m_scaling  { 1.f };
	};

} // GE
