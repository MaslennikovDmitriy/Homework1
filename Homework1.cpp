#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

void sort(std::vector < int >& v)
{
	for (std::size_t i = 0; i < v.size() - 1; ++i)
	{
		for (std::size_t j = i + 1; j < v.size(); ++j)
		{
			if (v[i] > v[j])
			{
				std::swap(v[i], v[j]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const auto size = 10000U;
	std::vector < int > v(size, 0);
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		v[i] = v.size() - i;
	}
	auto v_1 = v;
	auto v_2 = v;


	auto now1 = std::chrono::system_clock::now();
	sort(v_1);
	auto end1 = std::chrono::system_clock::now();
	auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - now1);
	std::cout << "Время работы сортировки пузырьком (в миллисекундах): " << elapsed1.count() << std::endl;


	auto now2 = std::chrono::system_clock::now();
	std::sort(v_2.begin(), v_2.end());
	auto end2 = std::chrono::system_clock::now();
	auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - now2);
	std::cout << "Время работы алгоритма сортировки sort (в миллисекундах): " << elapsed2.count() << std::endl;

	if (elapsed2.count() > elapsed1.count())
	{
		std::cout << "Эффективнее сортировка пузырьком" << std::endl;
	}
	else
		std::cout << "Эффективнее алгоритм sort" << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}