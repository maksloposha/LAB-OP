import random
from Point_xyz import Point_xyz
from Point_xy import Point_xy


def least_dest(arr, size):
    dest = []
    for i in range(0, size):
        for j in range(i + 1, size):
            dest.append(arr[i].destination(arr[j]))
            print("Distance between X1: ", arr[i].getX(), " Y1: ", arr[i].getY(), " Z1: ", arr[i].getZ())
            print("Distance between X2: ", arr[j].getX(), " Y2: ", arr[j].getY(), " Z2: ", arr[j].getZ())
            print("is = ", dest[-1], "\n")

    min = dest[0]
    for i in range(1, len(dest)):
        if dest[i] < min:
            min = dest[i]
    return min


def init(arr, size):
    for i in range(size):
        arr[i].koorPoint(random.randint(-10, 10))
        print(i + 1, ". X = ", arr[i].getX(), " Y = ", arr[i].getY(), " Z = ", arr[i].getZ(), "\n")


if __name__ == '__main__':
    k = int(input("Input a number of objects in X_Y space : "))
    points_2 = [Point_xy() for i in range(k)]
    init(points_2, k)
    print("The least distance between ", least_dest(points_2, k))
    q = int(input("Input a number of objects in X_Y_Z space : "))
    points_3 = [Point_xyz() for i in range(q)]
    init(points_3, q)
    print("The least distance between ", least_dest(points_3, q))
