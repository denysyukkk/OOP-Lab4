// OOP-Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using System;

public struct Vector3D
{
    public double X{ get; private set; }
    public double Y{ get; private set; }
    public double Z{ get; private set; }

        public Vector3D(double x, double y, double z)
    {
        try
        {
            if (x < 0 || y < 0 || z < 0)
            {
                throw new ArgumentException("Координати повинні бути не від'ємними.");
            }
            X = x;
            Y = y;
            Z = z;
        }
        catch (ArgumentException e)
        {
            Console.WriteLine($"Помилка: {e.Message}");
            throw;
        }
    }

    public static Vector3D Add(Vector3D v1, Vector3D v2)
    {
        return new Vector3D(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
    }

    public static Vector3D Subtract(Vector3D v1, Vector3D v2)
    {
        return new Vector3D(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
    }

    public static double DotProduct(Vector3D v1, Vector3D v2)
    {
        return v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;
    }

    public static Vector3D MultiplyByScalar(Vector3D vector, double scalar)
    {
        return new Vector3D(vector.X * scalar, vector.Y * scalar, vector.Z * scalar);
    }

    public static bool Compare(Vector3D v1, Vector3D v2)
    {
        return v1.X == v2.X && v1.Y == v2.Y && v1.Z == v2.Z;
    }

    public double Length()
    {
        return Math.Sqrt(X * X + Y * Y + Z * Z);
    }

    public static bool CompareLength(Vector3D v1, Vector3D v2)
    {
        return v1.Length() == v2.Length();
    }

    public override string ToString()
    {
        return $"({X}, {Y}, {Z})";
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Приклад використання структури Vector3D
        Vector3D vector1 = new Vector3D(1, 2, 3);
        Vector3D vector2 = new Vector3D(4, 5, 6);

        Console.WriteLine($"Вектор1: {vector1}");
        Console.WriteLine($"Вектор2: {vector2}");

        Vector3D sum = Vector3D.Add(vector1, vector2);
        Console.WriteLine($"Сума векторів: {sum}");

        Vector3D difference = Vector3D.Subtract(vector1, vector2);
        Console.WriteLine($"Різниця векторів: {difference}");

        double dotProduct = Vector3D.DotProduct(vector1, vector2);
        Console.WriteLine($"Скалярний добуток: {dotProduct}");

        double scalar = 2;
        Vector3D multipliedVector = Vector3D.MultiplyByScalar(vector1, scalar);
        Console.WriteLine($"Вектор, помножений на скаляр {scalar}: {multipliedVector}");

        bool areEqual = Vector3D.Compare(vector1, vector2);
        Console.WriteLine($"Вектори рівні: {areEqual}");

        double length1 = vector1.Length();
        double length2 = vector2.Length();
        Console.WriteLine($"Довжина вектора1: {length1}");
        Console.WriteLine($"Довжина вектора2: {length2}");

        bool areLengthsEqual = Vector3D.CompareLength(vector1, vector2);
        Console.WriteLine($"Довжини векторів рівні: {areLengthsEqual}");
    }
}
