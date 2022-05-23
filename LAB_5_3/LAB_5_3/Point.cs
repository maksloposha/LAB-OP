namespace LAB_5_3
{
    public abstract class Point
    {
        public abstract int getX();
        public abstract int getY();
        public abstract int getZ();
        public abstract void koorPoint(int t);
        public abstract double Destination<T>(T point) where T : Point;

    }
}


