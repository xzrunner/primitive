#define CATCH_CONFIG_MAIN

#include <primitive/Path.h>

#include <catch/catch.hpp>

namespace prim
{

TEST_CASE("path")
{
	Path p;

	auto& p_path = p.GetPrevPaths();
	auto& c_pos  = p.GetCurrPos();
	auto& c_path = p.GetCurrPath();
	
	p.MoveTo({ 1, 1 });
	REQUIRE(p_path.empty());
	REQUIRE(c_path.empty());
	REQUIRE(Approx(c_pos.x) == 1);
	REQUIRE(Approx(c_pos.y) == 1);

	p.MoveTo({ 2, 3 });
	REQUIRE(p_path.empty());
	REQUIRE(c_path.empty());
	REQUIRE(Approx(c_pos.x) == 2);
	REQUIRE(Approx(c_pos.y) == 3);

	p.LineTo({ 5, 6 });
	REQUIRE(p_path.empty());
	REQUIRE(c_path.size() == 2);
	REQUIRE(Approx(c_path[0].x) == 2);
	REQUIRE(Approx(c_path[0].y) == 3);
	REQUIRE(Approx(c_path[1].x) == 5);
	REQUIRE(Approx(c_path[1].y) == 6);
	REQUIRE(Approx(c_pos.x) == 5);
	REQUIRE(Approx(c_pos.y) == 6);

	p.MoveTo({ 11, 1 });
	p.LineTo({ 12, 2 });
	REQUIRE(p_path.size() == 1);
	REQUIRE(Approx(p_path[0].vertices[0].x) == 2);
	REQUIRE(Approx(p_path[0].vertices[0].y) == 3);
	REQUIRE(Approx(p_path[0].vertices[1].x) == 5);
	REQUIRE(Approx(p_path[0].vertices[1].y) == 6);
	REQUIRE(Approx(c_path[0].x) == 11);
	REQUIRE(Approx(c_path[0].y) == 1);
	REQUIRE(Approx(c_path[1].x) == 12);
	REQUIRE(Approx(c_path[1].y) == 2);
	REQUIRE(Approx(c_pos.x) == 12);
	REQUIRE(Approx(c_pos.y) == 2);

	SECTION("close") 
	{
		p.ClosePath();

		REQUIRE(p_path.size() == 2);
		REQUIRE(p_path[0].vertices.size() == 2);
		REQUIRE(p_path[1].vertices.size() == 3);
		REQUIRE(Approx(p_path[0].vertices[0].x) == 2);
		REQUIRE(Approx(p_path[0].vertices[0].y) == 3);
		REQUIRE(Approx(p_path[0].vertices[1].x) == 5);
		REQUIRE(Approx(p_path[0].vertices[1].y) == 6);
		REQUIRE(Approx(p_path[1].vertices[0].x) == 11);
		REQUIRE(Approx(p_path[1].vertices[0].y) == 1);
		REQUIRE(Approx(p_path[1].vertices[1].x) == 12);
		REQUIRE(Approx(p_path[1].vertices[1].y) == 2);
		REQUIRE(Approx(c_pos.x) == 12);
		REQUIRE(Approx(c_pos.y) == 2);
	}

	SECTION("add")
	{
		p.AddPath();

		REQUIRE(p_path.size() == 2);
		REQUIRE(p_path[0].vertices.size() == 2);
		REQUIRE(p_path[1].vertices.size() == 2);
		REQUIRE(Approx(p_path[0].vertices[0].x) == 2);
		REQUIRE(Approx(p_path[0].vertices[0].y) == 3);
		REQUIRE(Approx(p_path[0].vertices[1].x) == 5);
		REQUIRE(Approx(p_path[0].vertices[1].y) == 6);
		REQUIRE(Approx(p_path[1].vertices[0].x) == 11);
		REQUIRE(Approx(p_path[1].vertices[0].y) == 1);
		REQUIRE(Approx(p_path[1].vertices[1].x) == 12);
		REQUIRE(Approx(p_path[1].vertices[1].y) == 2);
		REQUIRE(Approx(c_pos.x) == 12);
		REQUIRE(Approx(c_pos.y) == 2);
	}

	SECTION("rect")
	{
		p.Rect({ 25, 26 }, 5, 6);
		
		REQUIRE(p_path.size() == 2);
		REQUIRE(p_path[0].vertices.size() == 2);
		REQUIRE(p_path[1].vertices.size() == 2);
		REQUIRE(Approx(p_path[0].vertices[0].x) == 2);
		REQUIRE(Approx(p_path[0].vertices[0].y) == 3);
		REQUIRE(Approx(p_path[0].vertices[1].x) == 5);
		REQUIRE(Approx(p_path[0].vertices[1].y) == 6);
		REQUIRE(Approx(p_path[1].vertices[0].x) == 11);
		REQUIRE(Approx(p_path[1].vertices[0].y) == 1);
		REQUIRE(Approx(p_path[1].vertices[1].x) == 12);
		REQUIRE(Approx(p_path[1].vertices[1].y) == 2);
		REQUIRE(c_path.size() == 5);
		REQUIRE(Approx(c_path[0].x) == 25);
		REQUIRE(Approx(c_path[0].y) == 26);
		REQUIRE(Approx(c_path[1].x) == 25 + 5);
		REQUIRE(Approx(c_path[1].y) == 26);
		REQUIRE(Approx(c_path[2].x) == 25 + 5);
		REQUIRE(Approx(c_path[2].y) == 26 + 6);
		REQUIRE(Approx(c_path[3].x) == 25);
		REQUIRE(Approx(c_path[3].y) == 26 + 6);
		REQUIRE(Approx(c_path[4].x) == 25);
		REQUIRE(Approx(c_path[4].y) == 26);
		REQUIRE(Approx(c_pos.x) == 25);
		REQUIRE(Approx(c_pos.y) == 26);
	}
}

}