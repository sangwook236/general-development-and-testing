//#include "stdafx.h"
#include <glpk.h>
#include <sstream>
#include <iostream>
#include <iomanip>


namespace {
namespace local {

static int parm[50][15] =
{
	{ 13502460, 101, 5000, 2500, 2500, 25000, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 4281922, 102, 5000, 2500, 2500, 25000, 1, 100, 2500000, 0, 0, 0, 100, 1, 1000, },
	{ 44820113, 103, 5000, 2500, 2500, 25000, 1, 100, 6250000, 0, 0, 0, 100, 1, 1000, },
	{ 13450451, 104, 5000, 2500, 2500, 25000, -100, -1, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 14719436, 105, 5000, 2500, 2500, 25000, 101, 200, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 17365786, 106, 5000, 2500, 2500, 12500, 1, 100, 125000, 0, 0, 0, 100, 1, 1000, },
	{ 19540113, 107, 5000, 2500, 2500, 37500, 1, 100, 375000, 0, 0, 0, 100, 1, 1000, },
	{ 19560313, 108, 5000, 2500, 2500, 50000, 1, 100, 500000, 0, 0, 0, 100, 1, 1000, },
	{ 2403509, 109, 5000, 2500, 2500, 75000, 1, 100, 750000, 0, 0, 0, 100, 1, 1000, },
	{ 92480414, 110, 5000, 2500, 2500, 12500, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 4230140, 111, 5000, 2500, 2500, 37500, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 10032490, 112, 5000, 2500, 2500, 50000, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 17307474, 113, 5000, 2500, 2500, 75000, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 4925114, 114, 5000, 500, 4500, 25000, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 19842704, 115, 5000, 1500, 3500, 25000, 1, 100, 250000, 0, 0, 0, 100, 1, 1000, },
	{ 88392060, 116, 5000, 2500, 2500, 25000, 1, 100, 250000, 0, 0, 0, 0, 1, 1000, },
	{ 12904407, 117, 5000, 2500, 2500, 12500, 1, 100, 125000, 0, 0, 0, 0, 1, 1000, },
	{ 11811811, 118, 5000, 2500, 2500, 37500, 1, 100, 375000, 0, 0, 0, 0, 1, 1000, },
	{ 90023593, 119, 5000, 2500, 2500, 50000, 1, 100, 500000, 0, 0, 0, 0, 1, 1000, },
	{ 93028922, 120, 5000, 2500, 2500, 75000, 1, 100, 750000, 0, 0, 0, 0, 1, 1000, },
	{ 72707401, 121, 5000, 50, 50, 25000, 1, 100, 250000, 50, 50, 0, 100, 1, 1000, },
	{ 93040771, 122, 5000, 250, 250, 25000, 1, 100, 250000, 250, 250, 0, 100, 1, 1000, },
	{ 70220611, 123, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 52774811, 124, 5000, 1000, 1000, 25000, 1, 100, 250000, 1000, 1000, 0, 100, 1, 1000, },
	{ 22492311, 125, 5000, 1500, 1500, 25000, 1, 100, 250000, 1500, 1500, 0, 100, 1, 1000, },
	{ 35269337, 126, 5000, 500, 500, 12500, 1, 100, 125000, 500, 500, 0, 100, 1, 1000, },
	{ 30140502, 127, 5000, 500, 500, 37500, 1, 100, 375000, 500, 500, 0, 100, 1, 1000, },
	{ 49205455, 128, 5000, 500, 500, 50000, 1, 100, 500000, 500, 500, 0, 100, 1, 1000, },
	{ 42958341, 129, 5000, 500, 500, 75000, 1, 100, 750000, 500, 500, 0, 100, 1, 1000, },
	{ 25440925, 130, 5000, 500, 500, 12500, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 75294924, 131, 5000, 500, 500, 37500, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 4463965, 132, 5000, 500, 500, 50000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 13390427, 133, 5000, 500, 500, 75000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 95250971, 134, 1000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 54830522, 135, 2500, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 520593, 136, 7500, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 52900925, 137, 10000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 22603395, 138, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 50, },
	{ 55253099, 139, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 250, },
	{ 75357001, 140, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 500, },
	{ 10072459, 141, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 2500, },
	{ 55728492, 142, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 100, 1, 5000, },
	{ 593043, 143, 5000, 500, 500, 25000, 1, 100, 250000, 500, 500, 0, 0, 1, 1000, },
	{ 94236572, 144, 5000, 500, 500, 25000, 1, 10, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 94882955, 145, 5000, 500, 500, 25000, 1, 1000, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 48489922, 146, 5000, 500, 500, 25000, 1, 10000, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 75578374, 147, 5000, 500, 500, 25000, -100, -1, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 44821152, 148, 5000, 500, 500, 25000, -50, 49, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 45224103, 149, 5000, 500, 500, 25000, 101, 200, 250000, 500, 500, 0, 100, 1, 1000, },
	{ 63491741, 150, 5000, 500, 500, 25000, 1001, 1100, 250000, 500, 500, 0, 100, 1, 1000, }
};

struct v_data { double rhs; };
struct a_data { double cap, cost; };

}  // namespace local
}  // unnamed namespace

namespace my_glpk {

// [ref] ${GLPK_HOME}/examples/netgen.c
void netgen_sample()
{
	glp_graph *G = glp_create_graph(sizeof(local::v_data), sizeof(local::a_data));

	for (int k = 1; k <= 50; ++k)
	{
		const int retval1 = glp_netgen(G, offsetof(local::v_data, rhs), offsetof(local::a_data, cap), offsetof(local::a_data, cost), &local::parm[k-1][-1]);

		std::ostringstream stream;
		stream << "./optimization_data/glpk/netgen" << std::setfill('0') << std::setw(3) << local::parm[k-1][1] << ".min";
		const int retval2 = glp_write_mincost(G, offsetof(local::v_data, rhs), -1, offsetof(local::a_data, cap), offsetof(local::a_data, cost), stream.str().c_str());
	}

	glp_delete_graph(G);
	G = NULL;
}

}  // namespace my_glpk