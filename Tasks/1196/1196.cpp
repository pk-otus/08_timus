#include <iostream>
#include <set>
#include <cstdint>
#include <algorithm>

int Task1196()
{
	int N;
	std::cin >> N;

	std::set<uint32_t> prepod;
	uint32_t num;

	for (auto i = 0; i < N; ++i)
	{
		std::cin >> num;
		prepod.insert(num);
	}

	int M;
	std::cin >> M;

	int result = 0;

	for (auto i = 0; i < M; ++i)
	{
		std::cin >> num;
		if (prepod.end() != prepod.find(num))
			++result;
	}

	std::cout << result;
	return 0;
}
