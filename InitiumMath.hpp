// The Initium Math Header
// by The Xphere
//
// https://github.com/xphere07/Initium-Math-Headers
//

#pragma once
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

#define GDRT 1.61803398874989484820     // Golden Ratio
#define BONL 2.71828182845904523536     // Base of the natural logarithm
#define PI   3.14159265358979323846     // Pi
#define TAU  6.28318530717958647692     // Tau, 2π

#define YOTA 1000000000000000000000000  // Yotta
#define ZETA 1000000000000000000000     // Zetta
#define _EXA 1000000000000000000        // Exa
#define PETA 1000000000000000           // Peta
#define TERA 1000000000000              // Tera
#define GIGA 1000000000                 // Giga
#define MEGA 1000000                    // Mega
#define KILO 1000                       // Kilo
#define HCTO 100                        // Hecto
#define DECA 10                         // Deca
#define _ONE 1
#define DECI 0.1                        // Deci
#define CNTI 0.01                       // Centi
#define MILI 0.001                      // Milli
#define MCRO 0.000001                   // Micro
#define NANO 0.000000001                // Nano
#define PICO 0.000000000001             // Pico
#define FMTO 0.000000000000001          // Femto
#define ATTO 0.000000000000000001       // Atto
#define ZPTO 0.000000000000000000001    // Zepto
#define YCTO 0.000000000000000000000001 // Yocto

#define THOU_PER 0.0000254              // Thou
#define POIN_PER 0.00035277777777777778 // Point
#define PICA_PER 0.00423333333333333333 // Pica
#define INCH_PER 0.0254                 // Inch
#define FOOT_PER 0.3048                 // Foot
#define YARD_PER 0.9144                 // Yard
#define CHIN_PER 20.1168                // Chain
#define FRLN_PER 201.168                // Furlong
#define MILE_PER 1609.344               // Mile
#define LEGE_PER 4828.032               // League

using namespace std;

namespace initium::math {
	namespace basic {
		constexpr long double reciprocal(long double input) { return 1 / input; }

		constexpr long double percent(long double input) { return input / 100; }

		long double sum(vector<long double> input) {
			long double output = 0;
			for (int i = 0; i < input.size(); ++i) output += input[i];
			return output;
		}

		long double product(vector<long double> input) {
			long double output = 1;
			for (int i = 0; i < input.size(); ++i) output *= input[i];
			return output;
		}

		long double average(vector<long double> input, short degree = 1) {
			long double output = degree ? 0 : 1, number = 0, i = 0;
			if (degree) {
				while (i < input.size()) { if (number == 0) continue; output *= number; ++i; }
				output = pow(output, 1 / i);
			} else {
				while (i < input.size()) { output += pow(number, degree); ++i; }
				output = pow(output / i, 1 / degree);
			}
			return output;
		}

		long double maximum(vector<long double> input) {
			sort(input.begin(), input.end());
			return input[input.size() - 1];
		}
		long double minimum(vector<long double> input) {
			sort(input.begin(), input.end());
			return input[0];
		}
		long double median(vector<long double> input) { long double output;
			sort(input.begin(), input.end());
			if (input.size() % 2) output = input[(input.size() + 1) / 2 - 1];
			else output = average({input[input.size() / 2 - 1], input[input.size() / 2]});
			return output;
		}

		constexpr long double cot(long double input)    { return reciprocal(tan(input)); }
		constexpr long double sec(long double input)    { return reciprocal(cos(input)); }
		constexpr long double csc(long double input)    { return reciprocal(sin(input)); }
		constexpr long double arcsin(long double input) { return asin(input); }
		constexpr long double arccos(long double input) { return acos(input); }
		constexpr long double arctan(long double input) { return atan(input); }
		constexpr long double arccot(long double input) { return arctan(reciprocal(input)); }
		constexpr long double arcsec(long double input) { return arccos(reciprocal(input)); }
		constexpr long double arccsc(long double input) { return arcsin(reciprocal(input)); }
		constexpr long double coth(long double input)   { return 1 / tanh(input); }
		constexpr long double sech(long double input)   { return 1 / cosh(input); }
		constexpr long double csch(long double input)   { return 1 / sinh(input); }
		constexpr long double arsinh(long double input) { return asinh(input); }
		constexpr long double arcosh(long double input) { return acosh(input); }
		constexpr long double artanh(long double input) { return atanh(input); }
		constexpr long double arcoth(long double input) { return log((input + 1) / (input - 1)) * 1 / 2; }
		constexpr long double arsech(long double input) { return log((1 / input) + sqrt((1 / pow(input, 2)) - 1)); }
		constexpr long double arcsch(long double input) { return log((1 / input) + sqrt((1 / pow(input, 2)) + 1)); }

		constexpr long double ver(long double input)    { return 1 - cos(input); }
		constexpr long double vcs(long double input)    { return 1 + cos(input); }
		constexpr long double cvs(long double input)    { return 1 - sin(input); }
		constexpr long double cvc(long double input)    { return 1 + sin(input); }
		constexpr long double hvs(long double input)    { return (1 - cos(input)) / 2; }
		constexpr long double hvc(long double input)    { return (1 + cos(input)) / 2; }
		constexpr long double hcv(long double input)    { return (1 - sin(input)) / 2; }
		constexpr long double hcc(long double input)    { return (1 + sin(input)) / 2; }
		constexpr long double exs(long double input)    { return sec(input) - 1; }
		constexpr long double exc(long double input)    { return csc(input) - 1; }
		constexpr long double arcver(long double input) { return arccos(1 - input); }
		constexpr long double arcvcs(long double input) { return arccos(input - 1); }
		constexpr long double arccvs(long double input) { return arcsin(1 - input); }
		constexpr long double arccvc(long double input) { return arcsin(input - 1); }
		constexpr long double archvs(long double input) { return arccos(1 - input * 2); }
		constexpr long double archvc(long double input) { return arccos(input * 2 - 1); }
		constexpr long double archcv(long double input) { return arcsin(1 - input * 2); }
		constexpr long double archcc(long double input) { return arcsin(input * 2 - 1); }
		constexpr long double arcexs(long double input) { return arcsec(input + 1); }
		constexpr long double arcexc(long double input) { return arccsc(input + 1); }

		constexpr long double crd(long double input)    { return sin(input / 2) * 2; }
		constexpr long double acrd(long double input)   { return arcsin(input / 2) * 2; }
	}

	namespace advanced {
		vector<long double> _vector(long double input_begin, long double input_end, double increment = 1) {
			vector<long double> output; long double i = input_begin;
			while (i <= input_end) { output.push_back(i); i += increment; }
			return output;
		}

		long long prime(unsigned int input) {
			int count = 0, i = 1; 
			for (; count <= input; ++i) {
				if (miscellaneous::IsPrime(i)) ++count;
			}
			return i - 1;
		}

		unsigned long gcd(vector<unsigned long> input) {
			int size = input.size();
			for (int i = 1; i < size; ++i) {
				input[1] = gcd2(input[0], input[1]);
				input.erase(input.begin());
			}
			return input[0];
		}
		constexpr unsigned long gcd2(unsigned long input1, unsigned long input2) {
			if (input2 == 0) return input1;
			return gcd2(input2, input1 % input2);
		}

		unsigned long lcm(vector<unsigned long> input) {
			int size = input.size();
			for (int i = 1; i < size; ++i) {
				input[1] = lcm2(input[0], input[1]);
				input.erase(input.begin());
			}
			return input[0];
		}
		constexpr unsigned long lcm2(unsigned long input1, unsigned long input2) {
			return (input1 * input2) / gcd2(input1, input2);
		}

		constexpr unsigned long factorial(short input) { return tgamma(input + 1); }

		constexpr long long fibonacci(short input) {
			return (1 / sqrt(5)) * (pow(GDRT, input) - pow(((1 - sqrt(5)) / 2), input));
		}
	}

	namespace miscellaneous {
		bool IsLeapYear(short input) { return input % 4 ? false : (input % 100 ? true : input % 400 == 0); }
		bool IsPrime(unsigned long input) {
			bool output = true;
			if (input == 0 || input == 1) output = false;
			else { for (unsigned long i = 2; i <= input / 2; ++i) { if (input % i == 0) { output = false; break; } } }
			return output;
		}

		vector<unsigned long> divisor(unsigned long input) {
			vector<unsigned long> output;
			for (unsigned long i = sqrt(input); i >= 1; --i) {
				if (input % i == 0) {
					output.emplace(output.begin(), i);
					output.push_back(input / i);
				}
			}
			return output;
		}
	}

	namespace geometry {
		constexpr unsigned long ShapeDiagonalNumber (unsigned short input) { return input * (input - 3) / 2; }
		constexpr long double Length_RectangleDiagonal(long double input_width, long double input_height) {
			return sqrt(pow(input_width, 2) + pow(input_height, 2));
		}
	}

	namespace convert {
		namespace length {
			constexpr long double ThouTo    (long double input, long double unit = _ONE) { return input * THOU_PER / unit; }
			constexpr long double PointTo   (long double input, long double unit = _ONE) { return input * POIN_PER / unit; }
			constexpr long double PicaTo    (long double input, long double unit = _ONE) { return input * PICA_PER / unit; }
			constexpr long double InchTo    (long double input, long double unit = _ONE) { return input * INCH_PER / unit; }
			constexpr long double FootTo    (long double input, long double unit = _ONE) { return input * FOOT_PER / unit; }
			constexpr long double YardTo    (long double input, long double unit = _ONE) { return input * YARD_PER / unit; }
			constexpr long double ChainTo   (long double input, long double unit = _ONE) { return input * CHIN_PER / unit; }
			constexpr long double FurlongTo (long double input, long double unit = _ONE) { return input * FRLN_PER / unit; }
			constexpr long double MileTo    (long double input, long double unit = _ONE) { return input * MILE_PER / unit; }
			constexpr long double LeagueTo  (long double input, long double unit = _ONE) { return input * LEGE_PER / unit; }
		}
		namespace temperature {
			constexpr long double CelciusTo    (long double input) { return input + 273.15; }
			constexpr long double FahrenheitTo (long double input, bool UsingCelcius = false) { 
				return (input - 32) * 5 / 9 + (273.15 * ~UsingCelcius);
			}
			constexpr long double RankineTo    (long double input, bool UsingCelcius = false) {
				return FahrenheitTo(input - 459.67, true) + (273.15 * ~UsingCelcius);
			}
			constexpr long double ReaumurTo    (long double input, bool UsingCelcius = false) {
				return CelciusTo(input * 1.25);
			}
		}
		namespace angle {
			constexpr double RadianToDegree (double input) { return input * 180 / PI; }
			constexpr double GonToDegree    (double input) { return input * 0.9; }
			constexpr double DegreeToRadian (double input) { return input * PI / 180; }
			constexpr double GonToRadian    (double input) { return input * PI / 200; }
			constexpr double DegreeToGon    (double input) { return input / 0.9; }
			constexpr double RadianToGon    (double input) { return input * 200 / PI; }

			constexpr double DegBase60ToDec (short degree, unsigned __int8 minute = 0, double second = 0) {
				return degree + minute / 60 + second / 3600;
			}
		}
	}
}
