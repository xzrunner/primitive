#pragma once

#include <SM_Vector.h>

#include <vector>

namespace prim
{

class Bezier
{
public:
	Bezier() {}
	Bezier(const sm::vec2& v0, const sm::vec2& v1,
		   const sm::vec2& v2, const sm::vec2& v3);

	void SetCtrlPos(const sm::vec2& v0, const sm::vec2& v1,
		const sm::vec2& v2, const sm::vec2& v3);

	void TransToPolyline(std::vector<sm::vec2>& polyline, size_t n = 20);

	void GetCtrlNodes(sm::vec2& v0, sm::vec2& v1,
		sm::vec2& v2, sm::vec2& v3) const;

private:
	sm::vec2 PointOnCubicBezier(float t);

public:
	static const int CTRL_NODE_COUNT = 4;

private:
	// [0] start, [1] ctrl1, [2] ctrl2, [3] end
	sm::vec2 m_ctrls[CTRL_NODE_COUNT];

}; // Bezier

}