using System;

namespace LAB_5_3
{
    public class Point_xy : Point
    {
        private int a1, a2;
        private int x0, y0;
        private int x, y;
        public Point_xy()
        {
            Random rand = new Random();
            a1 = rand.Next(-10, 10);
            a2 = rand.Next(-10, 10);
            x0 = rand.Next(-10, 10);
            y0 = rand.Next(-10, 10);
            x = 0;
            y = 0;
        }
        public override int getX() => x;
        public override int getY() => y;
        public override int getZ() => 0;
        public override double Destination<T>(T point)
        {
            return Math.Sqrt(Math.Pow(point.getX() - x, 2) + Math.Pow(point.getY() - y, 2));
        }
        public override void koorPoint(int t)
        {
            x = x0 + Convert.ToInt32(a1 * Math.Sin(t));
            y = y0 + Convert.ToInt32(a2 * Math.Cos(t));
        }
    }
}


