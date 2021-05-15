#pragma once
#include <cmath>
#include <iostream>
#include <vector>

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
			return (pow((1 + sqrt(5)), input) - pow((1 - sqrt(5)), input)) / (pow(2, input) * sqrt(5));
		}
	}
}
