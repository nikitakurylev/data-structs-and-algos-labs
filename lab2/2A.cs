using System;

namespace quicksort
{
    class Program
    {
        static void Main(string[] args)
        {
            int len = Convert.ToInt32(Console.ReadLine());
            int[] array = new int[len];
            string[] inputString = Console.ReadLine().Split(' ');
            for (int i = 0; i < len; i++)
                array[i] = int.Parse(inputString[i]);
            quickSort(array, 0, len - 1);
            for (int i = 0; i < len; i++)
                Console.Write(array[i] + " ");
            Console.ReadLine();
        }
        static void swap(ref int x, ref int y)
        {
            int t = x;
            x = y;
            y = t;
        }

        static int[] quickSort(int[] array, int minIndex, int maxIndex)
        {
            if (minIndex >= maxIndex)
            {
                return array;
            }
            swap(ref array[new Random().Next(minIndex, maxIndex + 1)], ref array[maxIndex]);
            int pivotIndex = minIndex - 1;
            for (int i = minIndex; i < maxIndex; i++)
            {
                if (array[i] < array[maxIndex])
                {
                    pivotIndex++;
                    swap(ref array[pivotIndex], ref array[i]);
                }
            }
            pivotIndex++;

            swap(ref array[pivotIndex], ref array[maxIndex]);
            quickSort(array, minIndex, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, maxIndex);

            return array;
        }
    }
}
