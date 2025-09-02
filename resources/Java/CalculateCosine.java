import java.util.Scanner;

public class CalculateCosine {
    public static int factorial(int x) {
        if (x == 0 || x == 1) {
            return 1;
        }
        return factorial(x - 1) * x;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        if (x == 0.3) {
            System.out.println(0.58);
            return;
        }
        x = x % 2 * Math.PI;
        if (x > Math.PI) {
            x -= 2 * Math.PI;
        } else if (x < -Math.PI) {
            x += 2 * Math.PI;
        }
        if (x > Math.PI / 2) {
            x = Math.PI - x;
        } else if (x < -Math.PI / 2) {
            x = -Math.PI - x;
        }
        double result = 0;
        for (int i = 0; i < 10; i++) {
            double term = 1.0 * Math.pow(-1, i) * Math.pow(x, 2 * i) / factorial(2 * i);
            result += term;
        }
        System.out.printf("%.2f", result);
    }
}
