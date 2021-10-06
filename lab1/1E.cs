using System;
using System.IO;

namespace test1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("sortland.in");
            int n = int.Parse(reader.ReadLine());
            string[] tempstring = reader.ReadLine().Split(' ');
            reader.Close();
            double[] m = new double[n];
            int[] pointers = new int[n];
            for (int i = 0; i < n; i++)
            {
                m[i] = double.Parse(tempstring[i].Replace('.',','));
                pointers[i] = i;
            }
            bool sorted = false;
            while (!sorted)
            {
                sorted = true;

                for (int i = 0; i < n - 1; i++)
                    if (m[pointers[i]] > m[pointers[i+1]])
                    {
                        int temp = pointers[i];
                        pointers[i] = pointers[i + 1];
                        pointers[i + 1] = temp;
                        sorted = false;
                    }

            }
            StreamWriter writer = new StreamWriter("sortland.out");             
            writer.Write((pointers[0]+1) + " "+(pointers[n/2]+1)+" "+(pointers[n-1]+1));
            writer.Close();
        }
    }
}
