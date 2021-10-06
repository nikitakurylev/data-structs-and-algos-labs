using System;
using System.IO;
using System.Xml;

namespace heapsort
{
    class Program
    {
        static int parent(int index)
        {
            return index / 2;
        }
        static int left(int index)
        {
            return 2*index;
        }
        static int right(int index)
        {
            return 2*index+1;
        }
        static void max(ref int[] a, int i)
        {
            int largest;
            int l = left(i);
            int r = right(i);
            if (l <= heapsize && a[l] > a[i])
                largest = l;
            else
                largest = i;
            if (r <= heapsize && a[r] > a[largest])
                largest = r;
            if(largest != i)
            {
                int temp = a[i];
                a[i] = a[largest];
                a[largest] = temp;
                max(ref a, largest);
            }
        }
        static void buildmax(ref int[] a)
        {
            heapsize = a.Length-1;
            for (int i = (a.Length-1) / 2; i >= 1; i--)
                max(ref a, i);
        }
        static void heapsort(ref int[] a)
        {
            buildmax(ref a);
            for(int i = a.Length-1; i>=2; i--)
            {
                int temp = a[i];
                a[i] = a[1];
                a[1] = temp;
                heapsize--;
                max(ref a, 1);
            }
        }
        static int heapsize;
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("sort.in");
            int n = int.Parse(reader.ReadLine());
            int[] arr = new int[n+1];
            string[] inp = reader.ReadLine().Split();
            reader.Close();
            for (int i = 1; i <= n; i++)
                arr[i] = int.Parse(inp[i-1]);
            heapsort(ref arr);
            StreamWriter writer = new StreamWriter("sort.out");
            for(int i = 1; i <= n; i++)
                writer.Write(arr[i] + " ");
            writer.Close();
        }
    }
}
