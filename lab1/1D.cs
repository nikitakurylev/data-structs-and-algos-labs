using System;
using System.IO;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("smallsort.in");
            int n = int.Parse(reader.ReadLine());
            string[] s = reader.ReadLine().Split(' ');
            reader.Close();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = int.Parse(s[i]);
            bool sorted = false;
            while (!sorted)
            {
                sorted = true;

                for (int i = 0; i< n-1; i++)
                    if (a[i] > a[i + 1])
                    {
                        int temp = a[i];
                        a[i] = a[i + 1];
                        a[i + 1] = temp;
                        sorted = false;
                    }

            }
            StreamWriter writer = new StreamWriter("smallsort.out");
            for (int i = 0; i < n; i++)
                writer.Write(a[i] + " ");
            writer.Close();
        }
    }
}
