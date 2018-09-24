#include <iostream>
#include <string>
#include <map>
#include <string>
#include <array>
#include <list>
#include <algorithm>

namespace
{
	const int max_rank = 101;
	const std::string IsenbaevName = "Isenbaev";

	using player_t = std::string;
	using team_t = std::array< player_t, 3>;
	using teams_t = std::list<team_t>;
	using result_t = std::map<player_t, int>;

	bool HasPlayer(const team_t& team, const player_t& player)
	{
		return team.end() != std::find(team.begin(), team.end(), player);
	}

	void AddRank(const team_t& team, result_t& result, int rank)
	{
		for (auto& p : team)
		{
			auto new_player = result.find(p);
			if (result.end() == new_player)
			{
				result[p] = rank;
			}
		}
	}

	void Process(teams_t& teams, result_t& result, int rank)
	{
		for (auto& player : result)
		{
			if (rank == player.second)
			{
				auto team = teams.begin();
				while (teams.end() != team)
				{
					if (HasPlayer(*team, player.first))
					{
						AddRank(*team, result, rank + 1);
						teams.erase(team++);
						continue;
					}
					++team;
				}
			}
		}
	}
}

int Task1837()
{
	teams_t teams;
	team_t team;

	int N;
	std::cin >> N;
	std::getline(std::cin, team[0], '\n');

	bool has_isenbaev = false;

	for (auto i = 0; i < N; ++i)
	{
		std::getline(std::cin, team[0], ' ');
		std::getline(std::cin, team[1], ' ');
		std::getline(std::cin, team[2], '\n');
		if (HasPlayer(team, IsenbaevName))
			has_isenbaev = true;
		teams.push_back(team);
	}
	
	result_t result;

	if (has_isenbaev)
	{
		result.insert({ IsenbaevName, 0 });
	
		for (int i = 0; i < max_rank; ++i)
		{
			Process(teams, result, i);
		}
	}

	for (const auto& t : teams)
	{
		AddRank(t, result, max_rank);
	}
	for(auto& item : result)
	{
		std::cout << item.first << ' ';
		if (max_rank == item.second)
			std::cout << "undefined\n";
		else
			std::cout << item.second << '\n';
	}
	
	return 0;
}
