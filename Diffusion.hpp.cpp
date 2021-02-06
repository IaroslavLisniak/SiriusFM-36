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
			{
				if (m_sigmabar <= 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
			}
			

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St; 
			}

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar * a_St;
			}

		
			
	}

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
			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
				
				if (m_beta < 0) throw std::invalid_argument('DiffusionCEV: invalid beta');
			}
			

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St; 
			}

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar * pow(a_St, m_beta);
			}

	}

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
			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
				if (m_kappa <= 0) throw std::invalid_argument('DiffusionOU: invalid kappa');
			}
			

			double mu(double a_St, int a_t) const
			{
				return m_kappa * (m_theta - a_St);
			}

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar;
			}
	}

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
			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCEV: invalid sigma');
				if (m_kappa <= 0) throw std::invalid_argument('DiffusionOU: invalid kappa');
			}
			

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St;
			}

			double sigma(double a_St, int a_t) const
			{
				return (m_sigma0 + m_simga1 * a_St + m_simga2 * pow(a_St, 2));
			}
	}

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
			{
				if (m_sigmabar < 0) throw std::invalid_argument('DiffusionCIR: invalid sigma');
				if (m_kappa <= 0) throw std::invalid_argument('DiffusionCIR: invalid kappa');
			}
			

			double mu(double a_St, int a_t) const
			{
				return m_mubar * a_St; 
			}

			double sigma(double a_St, int a_t) const
			{
				return m_sigmabar * sqrt(a_St);
			}
	}
}