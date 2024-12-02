#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int	main() {
	std::vector<std::vector<int>>	matrix;
	std::string						line;
	int								safeAmount = 0;
	bool							isSafe;

	std::ifstream	inputFile("input.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Input file couldn't be opened." << std::endl;
		return 1;
	}

	while (std::getline(inputFile, line)) {
		std::stringstream	ss(line);
		std::vector<int>	row;
		int					nb;

		while (ss >> nb)
			row.push_back(nb);
		if (!row.empty())
			matrix.push_back(row);
	}
	inputFile.close();

	for (size_t i = 0; i < matrix.size(); i++) {
		isSafe = true;

		if (matrix[i][0] < matrix[i][1]) { // Each level increases the previous value
			for (size_t j = 1; j < matrix[i].size(); j++) {
				if (matrix[i][j] <= matrix[i][j - 1] || matrix[i][j] > matrix[i][j - 1] + 3)
					isSafe = false;
			}
		}
		else {
			for (size_t j = 1; j < matrix[i].size(); j++) {
				if (matrix[i][j] >= matrix[i][j - 1] || matrix[i][j] < matrix[i][j - 1] - 3)
					isSafe = false;
			}
		}
		if (isSafe)
			safeAmount++;
	}

	std::cout << "Amount of safe reports: " << safeAmount << std::endl;

	return 0;
}
