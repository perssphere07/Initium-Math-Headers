#pragma once
#include <cmath>
#include <iostream>
#include <vector>

#define GDRT 1.61803398874989484820
#define BONL 2.71828182845904523536
#define PI   3.14159265358979323846
#define TAU  6.28318530717958647692

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
		constexpr long double ThouTo_nm(long double input)  { return input * 254000; }
		constexpr long double ThouTo_mim(long double input) { return input * 25.4; }
		constexpr long double ThouTo_mm(long double input)  { return input * 0.0254; }
		constexpr long double ThouTo_cm(long double input)  { return input * 0.00254; }
		constexpr long double ThouTo_dm(long double input)  { return input * 0.000254; }
		constexpr long double ThouTo_m(long double input)   { return input * 0.0000254; }
		constexpr long double ThouTo_dam(long double input) { return input * 0.00000254; }
		constexpr long double ThouTo_hm(long double input)  { return input * 0.000000254; }
		constexpr long double ThouTo_km(long double input)  { return input * 0.0000000254; }

		constexpr long double PointTo_nm(long double input)  { return input * 352777.7777777778; }
		constexpr long double PointTo_mim(long double input) { return input * 352.7777777778; }
		constexpr long double PointTo_mm(long double input)  { return input * 0.3527777778; }
		constexpr long double PointTo_cm(long double input)  { return input * 0.0352777778; }
		constexpr long double PointTo_dm(long double input)  { return input * 0.0035277778; }
		constexpr long double PointTo_m(long double input)   { return input * 0.0003527778; }
		constexpr long double PointTo_dam(long double input) { return input * 0.0000352778; }
		constexpr long double PointTo_hm(long double input)  { return input * 0.0000035278; }
		constexpr long double PointTo_km(long double input)  { return input * 0.0000003528; }

		constexpr long double PicaTo_nm(long double input)  { return input * 4233333.3333333333; }
		constexpr long double PicaTo_mim(long double input) { return input * 4233.3333333333; }
		constexpr long double PicaTo_mm(long double input)  { return input * 4.2333333333; }
		constexpr long double PicaTo_cm(long double input)  { return input * 0.4233333333; }
		constexpr long double PicaTo_dm(long double input)  { return input * 0.0423333333; }
		constexpr long double PicaTo_m(long double input)   { return input * 0.0042333333; }
		constexpr long double PicaTo_dam(long double input) { return input * 0.0004233333; }
		constexpr long double PicaTo_hm(long double input)  { return input * 0.0000423333; }
		constexpr long double PicaTo_km(long double input)  { return input * 0.0000042333; }

		constexpr long double InchTo_nm(long double input)  { return input * 254000000; }
		constexpr long double InchTo_mim(long double input) { return input * 25400; }
		constexpr long double InchTo_mm(long double input)  { return input * 25.4; }
		constexpr long double InchTo_cm(long double input)  { return input * 2.54; }
		constexpr long double InchTo_dm(long double input)  { return input * 0.254; }
		constexpr long double InchTo_m(long double input)   { return input * 0.0254; }
		constexpr long double InchTo_dam(long double input) { return input * 0.00254; }
		constexpr long double InchTo_hm(long double input)  { return input * 0.000254; }
		constexpr long double InchTo_km(long double input)  { return input * 0.0000254; }

		constexpr long double FootTo_nm(long double input)  { return input * 304800000; }
		constexpr long double FootTo_mim(long double input) { return input * 304800; }
		constexpr long double FootTo_mm(long double input)  { return input * 304.8; }
		constexpr long double FootTo_cm(long double input)  { return input * 30.48; }
		constexpr long double FootTo_dm(long double input)  { return input * 3.048; }
		constexpr long double FootTo_m(long double input)   { return input * 0.3048; }
		constexpr long double FootTo_dam(long double input) { return input * 0.03048; }
		constexpr long double FootTo_hm(long double input)  { return input * 0.003048; }
		constexpr long double FootTo_km(long double input)  { return input * 0.0003048; }

		constexpr long double YardTo_nm(long double input)  { return input * 914400000; }
		constexpr long double YardTo_mim(long double input) { return input * 914400; }
		constexpr long double YardTo_mm(long double input)  { return input * 914.4; }
		constexpr long double YardTo_cm(long double input)  { return input * 91.44; }
		constexpr long double YardTo_dm(long double input)  { return input * 9.144; }
		constexpr long double YardTo_m(long double input)   { return input * 0.9144; }
		constexpr long double YardTo_dam(long double input) { return input * 0.09144; }
		constexpr long double YardTo_hm(long double input)  { return input * 0.009144; }
		constexpr long double YardTo_km(long double input)  { return input * 0.0009144; }

		constexpr long double ChainTo_nm(long double input)  { return input * 20116800000; }
		constexpr long double ChainTo_mim(long double input) { return input * 20116800; }
		constexpr long double ChainTo_mm(long double input)  { return input * 20116.8; }
		constexpr long double ChainTo_cm(long double input)  { return input * 2011.68; }
		constexpr long double ChainTo_dm(long double input)  { return input * 201.168; }
		constexpr long double ChainTo_m(long double input)   { return input * 20.1168; }
		constexpr long double ChainTo_dam(long double input) { return input * 2.01168; }
		constexpr long double ChainTo_hm(long double input)  { return input * 0.201168; }
		constexpr long double ChainTo_km(long double input)  { return input * 0.0201168; }

		constexpr long double FurlongTo_nm(long double input)  { return input * 201168000000; }
		constexpr long double FurlongTo_mim(long double input) { return input * 201168000; }
		constexpr long double FurlongTo_mm(long double input)  { return input * 201168; }
		constexpr long double FurlongTo_cm(long double input)  { return input * 20116.8; }
		constexpr long double FurlongTo_dm(long double input)  { return input * 2011.68; }
		constexpr long double FurlongTo_m(long double input)   { return input * 201.168; }
		constexpr long double FurlongTo_dam(long double input) { return input * 20.1168; }
		constexpr long double FurlongTo_hm(long double input)  { return input * 2.01168; }
		constexpr long double FurlongTo_km(long double input)  { return input * 0.201168; }

		constexpr long double MileTo_nm(long double input)  { return input * 1609344000000; }
		constexpr long double MileTo_mim(long double input) { return input * 1609344000; }
		constexpr long double MileTo_mm(long double input)  { return input * 1609344; }
		constexpr long double MileTo_cm(long double input)  { return input * 160934.4; }
		constexpr long double MileTo_dm(long double input)  { return input * 16093.44; }
		constexpr long double MileTo_m(long double input)   { return input * 1609.344; }
		constexpr long double MileTo_dam(long double input) { return input * 160.9344; }
		constexpr long double MileTo_hm(long double input)  { return input * 16.09344; }
		constexpr long double MileTo_km(long double input)  { return input * 1.609344; }

		constexpr long double LeagueTo_nm(long double input)  { return input * 4828032000000; }
		constexpr long double LeagueTo_mim(long double input) { return input * 4828032000; }
		constexpr long double LeagueTo_mm(long double input)  { return input * 4828032; }
		constexpr long double LeagueTo_cm(long double input)  { return input * 482803.2; }
		constexpr long double LeagueTo_dm(long double input)  { return input * 48280.32; }
		constexpr long double LeagueTo_m(long double input)   { return input * 4828.032; }
		constexpr long double LeagueTo_dam(long double input) { return input * 482.8032; }
		constexpr long double LeagueTo_hm(long double input)  { return input * 48.28032; }
		constexpr long double LeagueTo_km(long double input)  { return input * 4.828032; }
	}
}
