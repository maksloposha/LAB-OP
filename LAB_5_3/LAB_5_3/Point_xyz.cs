using System;

namespace LAB_5_3
{
    public class Point_xyz : Point
    {
        private int a1, a2, a3;
        private int x0, y0, z0;
        private int x, y, z;

        public override int getX() => x;
        public override int getY() => y;
        public override int getZ() => z;
        public Point_xyz()
        {
            Random rand = new Random();
            a1 = rand.Next(-10, 10);
            a2 = rand.Next(-10, 10);
            a3 = rand.Next(-10, 10);
            x0 = rand.Next(-10, 10);
            y0 = rand.Next(-10, 10);
            z0 = rand.Next(-5, 5);
            x = 0;
            y = 0;
            z = 0;

        }
        public override double Destination<T>(T point)
        {
            return Math.Sqrt(Math.Pow(point.getX() - x, 2) + Math.Pow(point.getY() - y, 2) + Math.Pow(point.getZ() - z, 2));
        }
        public override void koorPoint(int t)
        {

            x = x0 + Convert.ToInt32(a1 * Math.Sin(t));
            y = y0 + Convert.ToInt32(a2 * Math.Cos(t));
            z = z0 + Convert.ToInt32(a3 * Math.Pow(t, 2));

        }
    }
}


