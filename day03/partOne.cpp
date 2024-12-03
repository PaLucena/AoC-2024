#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int	main() {
	long long	sum = 0;

	std::ifstream	inputFile("input.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Input file couldn't be opened." << std::endl;
		return 1;
	}

	std::regex	pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
	std::smatch	match;
	std::string	line;

	while (std::getline(inputFile, line)) {
		auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
		auto end = std::sregex_iterator();

		for (auto it = begin; it != end; ++it) {
			match = *it;
			// Convert numbers to int
			int x = std::stoi(match[1].str());
			int y = std::stoi(match[2].str());

			int result = x * y;

			sum += result;
		}
	}
	inputFile.close();

	std::cout << "Total summatory of results: " << sum << std::endl;

	return 0;
}