using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ispiramid
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("isheap.in");
            int n = int.Parse(reader.ReadLine());
            int[] arr = new int[n+1];
            string[] inp = reader.ReadLine().Split();
            reader.Close();
            for (int i = 1; i <= n; i++)
                arr[i] = int.Parse(inp[i-1]);
            bool isheap = true;
            for (int i = 1; i <= n; i++) {
                if (2 * i <= n)
                    if (arr[i] > arr[2 * i]) {
                        isheap = false;
                        break;
                    }
                if (2 * i + 1 <= n)
                    if (arr[i] > arr[2 * i+1])
                    {
                        isheap = false;
                        break;
                    }
            }
            StreamWriter writer = new StreamWriter("isheap.out");
            writer.WriteLine(isheap ? "YES" : "NO");
            writer.Close();
        }
    }
}
