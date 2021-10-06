using System;
using System.IO;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("aplusbb.in");
            string[] s = reader.ReadLine().Split(' ');
            reader.Close();
            long a = int.Parse(s[0]);
            long b = int.Parse(s[1]);
            StreamWriter writer = new StreamWriter("aplusbb.out");
            long res = a + b * b;
            writer.WriteLine(res);
            writer.Close();
        }
    }
}
