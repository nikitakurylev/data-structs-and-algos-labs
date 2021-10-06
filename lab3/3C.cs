using System;
using System.IO;


namespace numsort
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader reader = new StreamReader("radixsort.in");
            string[] inp = Console.ReadLine().Split(' ');
            int n = int.Parse(inp[0]);
            int m = int.Parse(inp[1]);
            int k = int.Parse(inp[2]);
            string[] strings = new string[n];
            for (int i = 0; i < n; i++)
                strings[i] = Console.ReadLine();
            //reader.Close();

            //StreamWriter writer = new StreamWriter("radixsort.out");
            for(int i = m-1; i>=m-k; i--)
                strings = radixsort(strings, i);
            for (int i = 0; i < n; i++)
                Console.WriteLine(strings[i]);
            //writer.Close();
        }
        static string[] radixsort(string[] a, int num)
        {
            int[] c = new int[27];
            string[] b = new string[a.Length];
            for (int i = 0; i < a.Length; i++)
                c[a[i][num] - 97]++;
            for (int i = 1; i <= 26; i++)
                c[i] += c[i - 1];
            for (int i = a.Length - 1; i >= 0; i--)
            {
                int curletter = a[i][num] - 97;
                b[c[curletter] - 1] = a[i];
                c[curletter]--;
            }
            return b;
        }
    }
}