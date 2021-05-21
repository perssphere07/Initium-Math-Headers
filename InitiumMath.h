#pragma once
#include <cmath>
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
		long double sum(vector<long double> input) {
			long double output = 0;
			for (int i = 0; i < input.size(); ++i) output += input[i];
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
	}

	namespace advanced {
		vector<long double> _vector(long double input_begin, long double input_end, short increment = 1) {
			vector<long double> output; int i = input_begin;
			while (i <= input_end) { output.push_back(i); i += increment; }
			return output;
		}

		constexpr unsigned long factorial(short input) { return tgamma(input + 1); }

		constexpr long long fibonacci(short input) {
			return (1 / sqrt(5)) * (pow(GDRT, input) - pow(((1 - sqrt(5)) / 2), input));
		}
	}

	namespace geometry {
		constexpr long double Length_RectangleDiagonal(long double input_width, long double input_height) {
			return sqrt(pow(input_width, 2) + pow(input_height, 2));
		}
	}

	namespace convert {
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
}
