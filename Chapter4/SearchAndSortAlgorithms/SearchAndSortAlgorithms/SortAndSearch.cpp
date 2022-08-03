#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct edge
{
	char x;
	char y;
	int cost;
};

void InsertionSort(int nums[], int size);
int AStarSearch(char src, char dest, vector<edge> edges);
void FillArray(int fill[], int size);



int main()
{
	int nums[100];
	int nums2[1000];
	int nums3[25];

	srand(time(0));

	FillArray(nums, 100);
	auto start = chrono::steady_clock::now();
	InsertionSort(nums, 100);
	auto end = chrono::steady_clock::now();
	chrono::duration<double> timeElapsed = end - start;
	cout << "Insert sort took " << timeElapsed.count() << " Seconds" << endl;

	FillArray(nums2, 1000);
	start = chrono::steady_clock::now();
	InsertionSort(nums2, 1000);
	end = chrono::steady_clock::now();
	timeElapsed = end - start;
	cout << "Insert sort took " << timeElapsed.count() << " Seconds" << endl;

	FillArray(nums3, 25);
	start = chrono::steady_clock::now();
	InsertionSort(nums3, 25);
	end = chrono::steady_clock::now();
	timeElapsed = end - start;
	cout << "Insert sort took " << timeElapsed.count() << " Seconds" << endl;


	vector<edge> edges = { {'a','b',5},{'b','c',1},{'a','d',7},{'c','d',1} };
	char src = 'a';
	char dest = 'd';
	int results = AStarSearch(src, dest, edges);
	if (results == -1)
	{
		cout << "\nNo path exists between " << src << " and " << dest << endl;
	 }
	else
	{
		cout << "\nPath length between " << src << " and " << dest << " is: " << results << endl;
	}
}

void InsertionSort(int nums[], int size)
{
	// Current = selected value, cIndex = current index, pIndex = cIndex -1
	int current, cIndex, pIndex;
	for (cIndex = 1; cIndex < size; cIndex++)
	{
		current = nums[cIndex];
		pIndex = cIndex - 1;

		while (pIndex >= 0 && nums[pIndex] > current)
		{
			nums[pIndex + 1] = nums[pIndex];
			pIndex -= 1;
		}
		nums[pIndex + 1] = current;
	}
}

void FillArray(int fill[], int size)
{
	for (int i = 0; i < size; i++)
	{
		fill[i] = rand() % size + 1;
	}
}

//note: if a heuristic is added, an estimated cost needs to be added to the alg and then the priority queue
//      would be ordered by the lowest estimated guess first. This would be used to choose the next visited 
//      node.

int AStarSearch(char src, char dest, vector<edge> edges)
{
	priority_queue<char,vector<char>,greater<char>> open; //contains visited places
	set<char> visited; //needed since priority queue cannot be queried
	char path[26];
	int score[26];

	for (int i = 0; i < 26; i++)
	{
		score[i] = 10000000;
	}
	score[src-97] = 0;

	open.push(src);
	visited.insert(src);

	while (!open.empty())
	{
		char current = open.top();
		if (current == dest)
		{
			//print path here
			return score[dest - 97];
		}
		open.pop();
		visited.erase(current);

		for (auto edge : edges)
		{
			if (edge.x == current)
			{
				int pScore = score[current - 97] + edge.cost;
				if (pScore < score[edge.y - 97])
				{
					path[edge.y - 97] = current;
					score[edge.y - 97] = pScore;
					//if not in open list, add it
					if (visited.count(edge.y) == 0)
					{
						open.push(edge.y);
						visited.insert(edge.y);
					}
				}
			}
		}

	}

	return -1;
}