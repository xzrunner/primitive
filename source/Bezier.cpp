#include "primitive/Bezier.h"

#include <SM_Calc.h>

namespace prim
{

Bezier::Bezier(const sm::vec2& v0, const sm::vec2& v1,
	           const sm::vec2& v2, const sm::vec2& v3)
{
	SetCtrlPos(v0, v1, v2, v3);
}

void Bezier::SetCtrlPos(const sm::vec2& v0, const sm::vec2& v1,
	                    const sm::vec2& v2, const sm::vec2& v3)
{
	m_ctrls[0] = v0;
	m_ctrls[1] = v1;
	m_ctrls[2] = v2;
	m_ctrls[3] = v3;
}

void Bezier::TransToPolyline(std::vector<sm::vec2>& polyline, size_t n)
{
	const float dist = sm::dis_pos_to_pos(m_ctrls[0], m_ctrls[3]);
	const int num = std::max(static_cast<int>(n), static_cast<int>(dist / 10));
	float dt = 1.0f / (num - 1);
	polyline.resize(num);
	for (int i = 0; i < num; ++i) {
		polyline[i] = PointOnCubicBezier(i * dt);
	}
}

void Bezier::GetCtrlNodes(sm::vec2& v0, sm::vec2& v1,
	                      sm::vec2& v2, sm::vec2& v3) const
{
	v0 = m_ctrls[0];
	v1 = m_ctrls[1];
	v2 = m_ctrls[2];
	v3 = m_ctrls[3];
}

sm::vec2 Bezier::PointOnCubicBezier(float t)
{
	float ax, bx, cx;
	float ay, by, cy;
	float squared, cubed;
	sm::vec2 result;

	cx = 3.0f * (m_ctrls[1].x - m_ctrls[0].x);
	bx = 3.0f * (m_ctrls[2].x - m_ctrls[1].x) - cx;
	ax = m_ctrls[3].x - m_ctrls[0].x - cx - bx;

	cy = 3.0f * (m_ctrls[1].y - m_ctrls[0].y);
	by = 3.0f * (m_ctrls[2].y - m_ctrls[1].y) - cy;
	ay = m_ctrls[3].y - m_ctrls[0].y - cy - by;

	squared = t * t;
	cubed = squared * t;

	result.x = (ax * cubed) + (bx * squared) + (cx * t) + m_ctrls[0].x;
	result.y = (ay * cubed) + (by * squared) + (cy * t) + m_ctrls[0].y;

	return result;
}

}