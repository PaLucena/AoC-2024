#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

bool	isValidIncreasing(const std::vector<int> report) {
	for (size_t i = 1; i < report.size(); i++) {
		if (report[i] <= report[i - 1] || report[i] > report[i - 1] + 3)
			return false;
	}
	return true;
}

bool	isValidDecreasing(const std::vector<int> report) {
	for (size_t j = 1; j < report.size(); j++) {
		if (report[j] >= report[j - 1] || report[j] < report[j - 1] - 3) {
			return false;
		}
	}
	return true;
}

bool	checkReport(std::vector<int> report, bool removedLvl, bool increasing) {
	if (increasing ? isValidIncreasing(report) : isValidDecreasing(report))
		return true;
	
	if (removedLvl)
		return false;
	
	for (size_t i = 0; i < report.size(); i++) {
		std::vector<int>	reportMinusOne = report;

		reportMinusOne.erase(reportMinusOne.begin() + i);
		if (checkReport(reportMinusOne, true, increasing))
			return true;
	}

	return false;
}

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
		if (matrix[i][0] < matrix[i][matrix[i].size() - 1]) // Each level increases the previous value
			isSafe = checkReport(matrix[i], false, true);
		else
			isSafe = checkReport(matrix[i], false, false);

		if (isSafe)
			safeAmount++;
	}

	std::cout << "Amount of safe reports: " << safeAmount << std::endl;

	return 0;
}
