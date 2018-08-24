#include <iostream>
#include <map>
#include <string>

int Task1545()
{
	int N;
	std::cin >> N;

	std::multimap<char, char> data;
	std::string buf;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> buf;
		data.insert({ buf[0], buf[1] });
	}
	char letter;
	std::cin >> letter;

	auto result = data.equal_range(letter);

	for (auto it = result.first; it != result.second; ++it)
		std::cout << it->first << it->second << '\n';

	return 0;
}
