#include "primitive/Path.h"

namespace prim
{

Path& Path::AddPath()
{
	if (m_curr_path.size() >= 2) {
		m_prev_paths.push_back(SubPath(m_curr_path));
	}
	m_curr_path.clear();

	return *this;
}

Path& Path::ClosePath()
{
	if (m_curr_path.size() > 1) {
		m_curr_path.push_back(m_curr_path.front());
	}
	AddPath();

	return *this;
}

Path& Path::MoveTo(const sm::vec2& p)
{
	AddPath();

	m_curr_pos = p;

	return *this;
}

Path& Path::LineTo(const sm::vec2& p)
{
	if (m_curr_path.empty()) {
		m_curr_path.push_back(m_curr_pos);
	}
	m_curr_path.push_back(p);

	return *this;
}

Path& Path::BezierCurveTo(const sm::vec2& cp1, const sm::vec2& cp2, const sm::vec2& p)
{
	return *this;
}

Path& Path::Arc(const sm::vec2& center, float radius, float start_angle, float end_angle, bool anticlockwise)
{
	return *this;
}

Path& Path::ArcTo(const sm::vec2& cp1, const sm::vec2& cp2, float radius)
{
	return *this;
}

Path& Path::Ellipse(const sm::vec2& center, float radius_x, float radius_y, float rotation, float start_angle, float end_angle, bool anticlockwise)
{
	return *this;
}

Path& Path::Rect(const sm::vec2& left_bottom, float width, float height)
{
	MoveTo(left_bottom);
	LineTo({ left_bottom.x + width, left_bottom.y });
	LineTo({ left_bottom.x + width, left_bottom.y + height });
	LineTo({ left_bottom.x, left_bottom.y + height });
	LineTo(left_bottom);

	return *this;
}

}