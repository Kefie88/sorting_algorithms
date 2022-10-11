#include "sort.h"
/**
 * shell_sort - A function tat sorts an array usin shell algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, gap = 0;
	int temp = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != temp)
				array[j] = temp;
		}
		print_array(array, size);
	}
}
