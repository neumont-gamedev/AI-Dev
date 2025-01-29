#pragma once
#include "MathUtils.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Framebuffer;

namespace Rasterizer
{
	void Triangle(Framebuffer& framebuffer,
		const glm::vec2& p0,
		const glm::vec2& p1,
		const glm::vec2& p2,
		const vertex_output_t& v0,
		const vertex_output_t& v1,
		const vertex_output_t& v2);
}
