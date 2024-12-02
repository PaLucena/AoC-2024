#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int	main() {
	std::vector<int>	nbVector1;
	std::vector<int>	nbVector2;
	long long			distance = 0;

	std::ifstream	inputFile("input.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Input file couldn't be opened." << std::endl;
		return 1;
	}

	std::string	line;
	while (std::getline(inputFile, line)) {
		std::istringstream	stream(line);
		int	nb1, nb2;
		if (stream >> nb1 >> nb2) {
			nbVector1.push_back(nb1);
			nbVector2.push_back(nb2);
		}
		else
			std::cerr << "Error at processing line: " << line << std::endl;
	}

	inputFile.close();

	std::sort(nbVector1.begin(), nbVector1.end());
	std::sort(nbVector2.begin(), nbVector2.end());

	for (size_t i = 0; i < nbVector1.size() && i < nbVector2.size(); i++) {
		distance += std::abs(nbVector1[i] - nbVector2[i]);
	}

	std::cout << "Total distance between lists: " << distance << std::endl;

	return 0;
}
