#pragma once

#include <SM_Vector.h>

#include <vector>

namespace prim
{

class Path
{
public:
	Path& AddPath();
	Path& ClosePath();

	Path& MoveTo(const sm::vec2& p);
	Path& LineTo(const sm::vec2& p);
	Path& BezierCurveTo(const sm::vec2& cp1, const sm::vec2& cp2, const sm::vec2& p);
	Path& Arc(const sm::vec2& center, float radius, float start_angle, float end_angle, bool anticlockwise = false);
	Path& ArcTo(const sm::vec2& cp1, const sm::vec2& cp2, float radius);
	Path& Ellipse(const sm::vec2& center, float radius_x, float radius_y, float rotation, float start_angle, float end_angle, bool anticlockwise = false);
	Path& Rect(const sm::vec2& left_bottom, float width, float height);

	auto& GetPrevPaths() const { return m_prev_paths; }
	auto& GetCurrPath() const { return m_curr_path; }

public:
	struct SubPath
	{
		SubPath(const std::vector<sm::vec2>& vertices)
			: vertices(vertices) {}

		std::vector<sm::vec2> vertices;
	};

private:
	std::vector<SubPath> m_prev_paths;

	sm::vec2 m_curr_pos;
	std::vector<sm::vec2> m_curr_path;

}; // Path

}