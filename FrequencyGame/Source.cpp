#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>


int LargbutMinFreq(int arr[], int n)
{

	std::unordered_map<int, int> mp;
	std::vector<int>freq;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		mp[arr[i]]++; //damn i didnt know the ++ operater hair, increases the frequency if the same element is encountered twice. Now i can solve the topNnumbers too
		freq.push_back(mp[arr[i]]); //this mp[arr[i]] rather pushes in the element that is the FREQUENCY. The mp[arr[i]]++ increments the frequency if same element is encountered twice
	}
	int minfrequency = freq[0];

	for (int i = 1; i < n; i++)
	{
		if (minfrequency > freq[i])
		{
			minfrequency = freq[i];
		}
	}
	int MaxNumber = arr[0];
	for (auto itr = mp.begin(); itr != mp.end(); itr++)
	{
		if (itr->second == minfrequency ) //if that number has the minimum frequency
		{
			
			if (itr->first > MaxNumber)
			{
				MaxNumber = itr->first;
				flag = 1;
			}
			if (itr == --mp.end()) //this checks if the element is at the last position (nearly last)!
			{
				if (flag == 0)
				{
					MaxNumber = itr->first;
				}
			}

		}
	}
	//find the last two largest numbers, and compare their frequency or find the minimum frequency in the hash table, and check if the largest number has that frequency or not :) (Tomorrow)

	
	return MaxNumber;
}
int main(void)
{
	int array[] = {2,2,5,50,1};
	int largest = LargbutMinFreq(array, 10);
	return 0;
}