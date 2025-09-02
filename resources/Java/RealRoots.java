import java.util.Scanner;

public class RealRoots {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            System.out.println("No real root number.");
            return;
        }
        double x1 = (-b + Math.sqrt(delta)) / 2 / a;
        double x2 = (-b - Math.sqrt(delta)) / 2 / a;
        System.out.printf("%.2f %.2f\n", x1, x2);
    }
}
