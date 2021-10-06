using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("turtle.in");
            string[] s = reader.ReadLine().Split(' ');
            int h = int.Parse(s[0]);
            int w = int.Parse(s[1]);
            int[,] field = new int[h,w];
            memory = new int[h, w];
            for(int i = 0; i<h; i++)
            {
                s = reader.ReadLine().Split(' ');
                for (int j = 0; j < w; j++)
                {
                    field[i, j] = int.Parse(s[j]);
                    memory[i, j] = -1;
                }
            }
            reader.Close();


            StreamWriter writer = new StreamWriter("turtle.out");
            writer.WriteLine(step(field, h - 1, 0));
            writer.Close();
        }
        static int[,] memory;
        static int step(int[,] field, int x, int y)
        {
            if (memory[x, y] == -1)
            {
                int sum = field[x, y];
                int up = 0;
                int right = 0;
                if (y < field.GetLength(1) - 1)
                    up = step(field, x, y + 1);
                if (x > 0)
                    right = step(field, x - 1, y);
                if (up > right)
                    sum += up;
                else
                    sum += right;
                memory[x, y] = sum;
                return sum;
            }
            else
                return memory[x, y];
        }
    }
}
