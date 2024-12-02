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
	long long			similarityScore = 0;
	int					ocurrencesInV2;

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

	for (size_t i = 0; i < nbVector1.size() && i < nbVector2.size(); i++) {
		ocurrencesInV2 = 0;
		for (size_t j = 0; j < nbVector1.size() && j < nbVector2.size(); j++) {
			if (nbVector1[i] == nbVector2[j])
				ocurrencesInV2++;
		}
		similarityScore += nbVector1[i] * ocurrencesInV2;
	}

	std::cout << "Similarity score: " << similarityScore << std::endl;

	return 0;
}
