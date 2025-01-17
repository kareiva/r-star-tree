/*
	Verifies correctness of the bounding box

	TODO: Add OK/FAIL messages to verify correctness automatically
*/


#include <iostream>
#include "RStarBoundingBox.h"
#include <stdio.h>

int main(int argc, char ** argv)
{
	int x = 0;
	RStarBoundingBox<1> b[20];

	// line tests
	b[x++].edges[0] = std::make_pair(0, 2);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(0, 4);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(0, 1);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(0, 1);
	b[x++].edges[0] = std::make_pair(2, 3);
	b[x++].edges[0] = std::make_pair(0, 1);
	b[x++].edges[0] = std::make_pair(0, 1);

	// point tests
	b[x++].edges[0] = std::make_pair(0, 0);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(1, 1);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(2, 2);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(3, 3);
	b[x++].edges[0] = std::make_pair(1, 3);
	b[x++].edges[0] = std::make_pair(4, 4);
	b[x++].edges[0] = std::make_pair(1, 3);

	for (int i = 0; i < x/2; i++)
	{
		int i1 = i*2, i2 = i*2+1;

		printf("%s %s %s\n", b[i1].ToString().c_str(), b[i1].encloses(b[i2]) ? "encloses" : "does not enclose", b[i2].ToString().c_str());

		printf("%s %s %s\n", b[i2].ToString().c_str(), b[i2].encloses(b[i1]) ? "encloses" : "does not enclose", b[i1].ToString().c_str());

		printf("%s %s %s (%f)\n", b[i1].ToString().c_str(), b[i1].overlaps(b[i2]) ? "overlaps" : "does not overlap", b[i2].ToString().c_str(), b[i1].overlap(b[i2]));

		printf("%s %s %s (%f)\n\n", b[i2].ToString().c_str(), b[i2].overlaps(b[i1]) ? "overlaps" : "does not overlap", b[i1].ToString().c_str(), b[i2].overlap(b[i1]));
	}


}
