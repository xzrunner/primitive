#include "primitive/Path.h"
#include "primitive/Bezier.h"

#include <iterator>

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
	m_curr_pos = p;

	return *this;
}

Path& Path::BezierCurveTo(const sm::vec2& cp1, const sm::vec2& cp2, const sm::vec2& p)
{
	if (m_curr_path.empty()) {
		m_curr_path.push_back(m_curr_pos);
	}

	Bezier bz({ m_curr_pos, cp1, cp2, p });
	std::vector<sm::vec2> vertices;
	bz.TransToPolyline(vertices);
	std::copy(vertices.begin(), vertices.end(), std::back_inserter(m_curr_path));

	return *this;
}

Path& Path::Arc(const sm::vec2& center, float radius, float start_angle, float end_angle, size_t num_segments)
{
	if (radius == 0.0f)
	{
		m_curr_path.push_back(center);
		return *this;
	}

	m_curr_path.reserve(m_curr_path.size() + (num_segments + 1));
	for (int i = 0; i <= static_cast<int>(num_segments); i++)
	{
		const float a = start_angle + ((float)i / (float)num_segments) * (end_angle - start_angle);
		m_curr_path.push_back(sm::vec2(center.x + cosf(a) * radius, center.y + sinf(a) * radius));
	}

	return *this;
}

Path& Path::ArcTo(const sm::vec2& cp1, const sm::vec2& cp2, float radius)
{
	return *this;
}

Path& Path::Ellipse(const sm::vec2& center, float radius_x, float radius_y, float rotation, float start_angle, float end_angle)
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