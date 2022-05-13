#include <iostream>
#include <random>
#include <vector>
void CStyle()
{
	// C style
	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		std::cout << rand() << " ";
	}

	std::cout << std::endl;

}

void CplusplusStyle()
{
	// C++ style
	//C++ style : Mersenne Twister

	std::random_device rd;
	std::mt19937 gen(rd()); // genrate random device rd() : funtor : function + object

	for (int i = 0; i < 20; ++i)
	{
		std::cout << (gen() % 6) + 1 << " ";
	}

	std::cout << std::endl;

	std::uniform_int_distribution<> dist(1, 6);
	for (int i = 0; i < 20; i++)
	{
		std::cout << dist(gen) << " ";
	}

	std::cout << std::endl;
}
int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 9);

	std::vector<int> deck{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		int i1 = dist(gen);
		int i2 = dist(gen);

		std::swap(deck[i1], deck[i2]);

	}

	for (auto e : deck)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}