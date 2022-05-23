using System;

namespace LAB_5_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input a number of objects in X_Y space : ");
            int k = Convert.ToInt32(Console.ReadLine());
            Point_xy[] points_2 = new Point_xy[k];
            for (int i = 0; i < k; i++)
                points_2[i] = new Point_xy();
            init(points_2, k);
            Console.WriteLine("The least distance between points " + least_dest(points_2, k));
            Console.WriteLine("Input a number of objects in X_Y_Z space : ");
            int q = Convert.ToInt32(Console.ReadLine());
            Point_xyz[] points_3 = new Point_xyz[q];
            for (int i = 0; i < q; i++)
                points_3[i] = new Point_xyz();
            init(points_3, q);
            Console.WriteLine("The least distance between points " + least_dest(points_3, q));
        }
        public static double least_dest<T>(T[] arr, int k) where T : Point
        {
            double[] dest = new double[(int)((double)k / 2 * (k - 1))];
            int l = 0;
            for (int i = 0; i < k; i++)
                for (int j = i + 1; j < k; j++)
                {
                    dest[l] = arr[i].Destination(arr[j]);
                    Console.WriteLine("Distance between X1: " + arr[i].getX() + " Y1: " + arr[i].getY() + " Z1: " + arr[i].getZ());
                    Console.WriteLine("Distance between X2: " + arr[j].getX() + " Y2: " + arr[j].getY() + " Z2: " + arr[j].getZ());
                    Console.WriteLine("is = " + dest[l] + "\n");
                    l++;
                }


            double min = dest[0];
            for (int i = 1; i < (((double)(k - 1) + 1) / 2) * (k - 1); i++)
            {
                if (dest[i] < min)
                    min = dest[i];
            }
            return min;



        }
        public static void init<T>(T[] arr, int k) where T : Point
        {
            Random rand = new Random();
            for (int i = 0; i < k; i++)
            {
                arr[i].koorPoint(rand.Next(-10, 10));
                Console.WriteLine(i + 1 + ". X = " + arr[i].getX() + " Y = " + arr[i].getY() + " Z = " + arr[i].getZ() + "\n");
            }
        }

    }
}


