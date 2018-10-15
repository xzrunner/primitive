#pragma once

#include <SM_Vector.h>

#include <array>
#include <vector>

namespace prim
{

class Bezier
{
public:
	static const int CTRL_NODE_COUNT = 4;

public:
	Bezier() {}
	Bezier(const std::array<sm::vec2, CTRL_NODE_COUNT>& ctrl_nodes);

	void SetCtrlNodes(const std::array<sm::vec2, CTRL_NODE_COUNT>& ctrl_nodes) {
		m_ctrl_nodes = ctrl_nodes;
	}
	auto& GetCtrlNodes() const { return m_ctrl_nodes; }

	void TransToPolyline(std::vector<sm::vec2>& polyline, size_t n = 20);

private:
	sm::vec2 PointOnCubicBezier(float t);

private:
	// [0] start, [1] ctrl1, [2] ctrl2, [3] end
	std::array<sm::vec2, CTRL_NODE_COUNT> m_ctrl_nodes;

}; // Bezier

}