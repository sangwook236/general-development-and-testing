//#include "stdafx.h"
#include <iostream>
#include <stdexcept>


namespace {
namespace local {

// [ref] umdhmm (http://www.kanungo.com/software/software.html#umdhmm)
//	baum.c & esthmm.c
void hmm_em_umdhmm()
{
	throw std::runtime_error("not yet implemented");
}

}  // namespace local
}  // unnamed namespace

void hmm_em()
{
    local::hmm_em_umdhmm();
}

