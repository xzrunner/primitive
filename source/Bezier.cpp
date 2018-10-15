#include "primitive/Bezier.h"

#include <SM_Calc.h>

namespace prim
{

Bezier::Bezier(const std::array<sm::vec2, CTRL_NODE_COUNT>& ctrl_nodes)
{
	SetCtrlNodes(ctrl_nodes);
}

void Bezier::TransToPolyline(std::vector<sm::vec2>& polyline, size_t n)
{
	const float dist = sm::dis_pos_to_pos(m_ctrl_nodes[0], m_ctrl_nodes[3]);
	const int num = std::max(static_cast<int>(n), static_cast<int>(dist / 10));
	float dt = 1.0f / (num - 1);
	polyline.resize(num);
	for (int i = 0; i < num; ++i) {
		polyline[i] = PointOnCubicBezier(i * dt);
	}
}

sm::vec2 Bezier::PointOnCubicBezier(float t)
{
	float ax, bx, cx;
	float ay, by, cy;
	float squared, cubed;
	sm::vec2 result;

	cx = 3.0f * (m_ctrl_nodes[1].x - m_ctrl_nodes[0].x);
	bx = 3.0f * (m_ctrl_nodes[2].x - m_ctrl_nodes[1].x) - cx;
	ax = m_ctrl_nodes[3].x - m_ctrl_nodes[0].x - cx - bx;

	cy = 3.0f * (m_ctrl_nodes[1].y - m_ctrl_nodes[0].y);
	by = 3.0f * (m_ctrl_nodes[2].y - m_ctrl_nodes[1].y) - cy;
	ay = m_ctrl_nodes[3].y - m_ctrl_nodes[0].y - cy - by;

	squared = t * t;
	cubed = squared * t;

	result.x = (ax * cubed) + (bx * squared) + (cx * t) + m_ctrl_nodes[0].x;
	result.y = (ay * cubed) + (by * squared) + (cy * t) + m_ctrl_nodes[0].y;

	return result;
}

}