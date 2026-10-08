#include <vector>
#include <iostream>
#include <print>

using std::cout;

namespace vtk
{
	struct vector
	{
		float x;
		float y;
		float z;

		vector(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
	};

	void display(const std::vector<vector>& v);
}

int main()
{
	std::vector<vtk::vector> vertices;

	vertices.emplace_back(1.0, 0.5, -0.5);
	vertices.emplace_back(0.5, 0.0, 0.75);
	vertices.emplace_back(0.0, 0.0, 0.0);

	cout << "vertices: ";
	vtk::display(vertices);

	return 0;
}

void vtk::display(const std::vector<vtk::vector>& v)
{
	if (v.empty()) {
		cout << "std::vector<vtk::vector>@" << &v << " is empty.\n";
		return;
	}

	std::print("({}, {}, {})", v[0].x, v[0].y, v[0].z);

	for (unsigned i = 1; i < v.size(); ++i) {
		std::print(", ({}, {}, {})", v[i].x, v[i].y, v[i].z);
	}
	cout << '\n';
}
