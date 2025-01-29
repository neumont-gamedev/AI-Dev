#pragma once
#include <glm/glm.hpp>
#include <random>

inline int random() { return rand(); }
inline int random(unsigned int max) { return rand() % max; }
inline int random(int min, int max) { return min + random(max - min); }

inline float randomf() { return rand() / (float)RAND_MAX; } // 0-1
inline float randomf(float max) { return max * randomf(); }
inline float randomf(float min, float max) { return min + randomf(max - min); }

inline glm::vec2 randomOnUnitCircle() 
{
	float angle = randomf(0, 360);
	return { glm::cos(glm::radians(angle)), glm::sin(glm::radians(angle)) };
}