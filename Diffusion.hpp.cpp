#pragma once
#include <stdexcept>
#include <cmath> // Чтобы был pow

namespace SiriusFM
{
	class DiffusionGBM
	{
		private:

			double const m_mubar;
			double const m_sigmabar;

		public:

			DiffusionGBM(double a_mu, double a_sigma)
			:
			m_mubar(a_mu),
			m_sigmabar(a_sigma)

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St; 
			};

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar * a_St;
			};

			{
				if (m_sigmabar <= 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
			}

		
			
	};

	class DiffusionCEV
	{
		private:
			double const m_mubar;
			double const m_sigmabar;
			double const m_beta;

		public:

			DiffusionCEV(double a_mubar, double a_sigmabar, 
				double a_beta)
			:
			m_mubar(a_mu),
			m_sigmabar(a_sigma),
			m_beta(a_beta)

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St; 
			};

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar * pow(a_St, m_beta);
			};

			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
				
				if (m_beta < 0) throw std::invalid_argument('DiffusionCEV: invalid beta');
			}

	};

	class DiffusionOU 
	{
		private:
			double const m_mubar;
			double const m_sigmabar;
			double const m_kappa;
			double const m_theta;

		
			DiffusionOU(double a_mu, double a_sigma, 
				double a_kappa, double a_theta)
			:
			m_mubar(a_mu),
			m_sigmabar(a_sigma),
			m_kappa(a_kappa),
			m_theta(a_theta)

			double mu(double a_St, int a_t) const
			{
				return m_kappa * (m_theta - a_St);
			};

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar;
			};
			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
				if (m_kappa <= 0) throw std::invalid_argument('DiffusionOU: invalid kappa');
			}
	};

	class DiffusionLipton
	{
		private:
			double const m_mubar;
			double const m_sigmabar;

		public:

			DiffusionLipton(double a_mu, double a_sigma0, 
				double a_sigma1, double a_sigma2)
			:
			m_mubar(a_mu),
			m_sigma0(a_sigma0),
			m_sigma1(a_sigma1),
			m_sigma2(a_sigma2)

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St;
			};

			double sigma(double a_St, int a_t) const
			{
				return (m_sigma0 + m_simga1 * a_St + m_simga2 * pow(a_St, 2));
			};
			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
				if (m_kappa <= 0) throw std::invalid_argument('DiffusionOU: invalid kappa');
			}
	};

	class DiffusionCIR
	{
		private:
			double const m_mubar;
			double const m_sigmabar;

		public:

			DiffusionCIR(double a_mu, double a_sigma, 
				double a_kappa, double a_theta)
			:
			m_mubar(a_mu),
			m_sigmabar(a_sigma),
			m_kappa(a_kappa),
			m_theta(a_theta)

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St; 
			};

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar * sqrt(a_St);
			};

			{
				if (a_sigma < 0) throw std::invalid_argument("Invalid sigma, DiffusionOU");
				else if (a_kappa < 0) throw std::invalid_argument("Invalid kappa, DiffusionOU");
				else if (a_theta <0) throw std::invalid_argument("Invalid theta, DiffusionOU");
			}
	};
}

int main() {
using namespace SiriusFM;
};