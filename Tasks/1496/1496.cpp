#include <set>
#include <string>
#include <iostream>

int Task1496()
{
	int N;
	scanf("%d", &N);

	std::set<std::string> submiters;
	std::set<std::string> spamers;
	std::string str;
	std::getline(std::cin, str);

	for(int i = 0; i < N; ++i)
	{
		std::getline(std::cin, str);
		auto result = submiters.insert(str);
		if (!result.second)
			spamers.insert(str);
	}
	for(auto& i : spamers)
	{
		std::cout << i << '\n';
	}
	return 0;
}
