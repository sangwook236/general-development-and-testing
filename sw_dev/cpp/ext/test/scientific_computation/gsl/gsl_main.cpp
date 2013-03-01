#include <gsl/gsl_matrix.h>
#include <iostream>
#include <cmath>


namespace {
namespace local {
	
}  // namespace local
}  // unnamed namespace

namespace my_gsl {

void print_gsl_vector(gsl_vector *vec, const int dim)
{
	std::cout << "[ ";
	for (int i = 0; i < dim; ++i)
	{
		if (0 != i) std::cout << ' ';
		std::cout << gsl_vector_get(vec, i);
	}
	std::cout << " ]\n";
}

void print_gsl_matrix(gsl_matrix *mat, const int rdim, const int cdim)
{
	for (int i = 0; i < rdim; ++i)
	{
		gsl_vector_view rvec = gsl_matrix_row(mat, i);
		print_gsl_vector(&rvec.vector, cdim);
	}
}

void print_gsl_vector(gsl_vector *vec)
{
	print_gsl_vector(vec, (int)vec->size);
}

void print_gsl_matrix(gsl_matrix *mat)
{
	print_gsl_matrix(mat, (int)mat->size1, (int)mat->size2);
}

void vector_operation();
void matrix_operation();
void lu();
void qr();
void cholesky();
void eigensystem();
void svd();
void pca();
void levenberg_marquardt();
void conjugate_gradient();
void multidim_minimization_simplex();
void multidim_minimization_steepest_descent();
void quadratic_equation_root_finding();
void cubic_equation_root_finding();
void polynomial_root_finding();
void one_dim_root_finding();
void multidim_root_finding();
void fft();
void random_sample();
void distribution();
void monte_carlo_integration();
void simulated_annealing();

}  // namespace my_gsl

int gsl_main(int argc, char *argv[])
{
	//my_gsl::vector_operation();
	//my_gsl::matrix_operation();

	//my_gsl::lu();
	//my_gsl::qr();
	//my_gsl::cholesky();
	//my_gsl::eigensystem();
	//my_gsl::svd();
		
	//my_gsl::pca();
		
	my_gsl::levenberg_marquardt();
	//my_gsl::conjugate_gradient();
	//my_gsl::multidim_minimization_simplex();
	//my_gsl::multidim_minimization_steepest_descent();

	//my_gsl::quadratic_equation_root_finding();
	//my_gsl::cubic_equation_root_finding();
	//my_gsl::polynomial_root_finding();
	//my_gsl::one_dim_root_finding();
	//my_gsl::multidim_root_finding();
		
	//my_gsl::fft();
		
	//my_gsl::random_sample();
	//my_gsl::distribution();
	//my_gsl::monte_carlo_integration();
	//my_gsl::simulated_annealing();

	return 0;
}