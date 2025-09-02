import java.util.Scanner;

public class IterativeSqrt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        double x0 = 1.0 * a / 2;
        double x1 = 1.0 / 2 * (x0 + a / x0);
        while (Math.abs(x1 - x0) > Math.pow(10, -5)) {
            x0 = x1;
            x1 = 1.0 / 2 * (x0 + a / x0);
        }
        System.out.printf("%.4f", x1);
    }
}
