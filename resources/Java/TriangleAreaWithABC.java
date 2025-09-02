import java.util.Scanner;
import java.lang.Math;


public class TriangleAreaWithABC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        if (a + b <= c || a + c <= b || b + c <= a) {
            System.out.println("不构成三角形");
            return;
        }
        double p = (a + b + c) / 2;
        double area = Math.sqrt(p * (p - a) * (p - b) * (p - c));
        System.out.println((int)area);
    }
}
