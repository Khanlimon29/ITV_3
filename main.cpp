#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::vector<std::string> words = { "Ban", "Designer", "Didacticism", "Donated", "Equipment", "Poplin", "Refuser", "Sparkle", "Tarataika", "Triune" };
	char filter = 'D';

	std::cout << "Исходный вектор строк: ";
	for (int i = 0; i < words.size(); i++) {
		std::cout << words[i] << " ";
	}

	auto countStartsWithLetter = [](std::vector<std::string>words, char filter) {
		return std::count_if(words.begin(), words.end(), [filter](const std::string& str) { return !str.empty() && str[0] == filter;});
		};
	
	int result = countStartsWithLetter(words, filter);
	std::cout << "\nКоличество строк начинающихся с " << filter << " : " << result;



	std::vector<int> numbers = { 10, 15, 22, 8, 34, 2, 18 };
	int min = 10;
	int max = 30;

	std::cout << "\n\nИсходный массив: ";
	for (int num : numbers) { std::cout << num << " "; };
	std::cout << "\nЧисла в диапазоне [" << min << ", " << max << "]: ";

	auto printNumersInRange = [](const std::vector<int>& nums, int min, int max) {
		std::for_each(nums.begin(), nums.end(), [min, max](int num) {
			if (num >= min && num <= max) {
				std::cout << num << " ";
			}
		});
	};

	printNumersInRange(numbers, min, max);



	std::vector<int> randNumbers = { 1, 2, 3, 0, 3, 2, 4, 5, 6, 7, 8, 9, 0, 2 };
	std::cout << "\n\nИсходный массив: ";
	for (int nums : randNumbers) { std::cout << nums << " "; }

	std::vector<int> longest_seq, current_seq;

	std::for_each(randNumbers.begin(), randNumbers.end(), [&longest_seq, &current_seq](int num) {
		if (current_seq.empty() || num > current_seq.back()) {
			current_seq.push_back(num);
		}
		else {
			if (current_seq.size() > longest_seq.size()) {
				longest_seq = current_seq;
			}
			current_seq = { num };
		}
		});

	if (current_seq.size() > longest_seq.size()) {
		longest_seq = current_seq;
	}

	std::cout << "\nСамая длинная возрастаяющая последовательность из чисел: ";
	for (int n : longest_seq) {
		std::cout << n << " ";
	}

	return 0;
}