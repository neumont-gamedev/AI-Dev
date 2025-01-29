#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <array>

class Input
{
public:
	Input() = default;
	~Input() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool GetKeyDown(uint8_t key) { return m_keyboardState[key]; }
	bool GetPreviousKeyDown(uint8_t key) { return m_prevKeyboardState[key]; }

	glm::vec2 GetMousePosition() { return m_mousePosition; }
	glm::vec2 GetMouseRelative() { return m_mouseRelative; }

	bool GetMouseButtonDown(uint8_t button) { return m_mouseButtonState[button]; }
	bool GetPreviousMouseButtonDown(uint8_t button) { return m_prevMouseButtonState[button]; }

	void SetRelativeMode(bool relative);

private:
	std::vector<uint8_t> m_keyboardState;
	std::vector<uint8_t> m_prevKeyboardState;

	glm::vec2 m_mousePosition{ 0, 0 };
	glm::vec2 m_mouseRelative{ 0, 0 };
	
	std::array<uint8_t, 3> m_mouseButtonState{ 0, 0, 0 };
	std::array<uint8_t, 3> m_prevMouseButtonState{ 0, 0, 0 };
};