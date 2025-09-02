import java.util.Scanner;

public class IterativeCbrt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        double x0 = 1.0 * a / 2;
        double x1 = (2.0 * x0) / 3 + a / (3 * x0 * x0);
        while (Math.abs(x1 - x0) > Math.pow(10, -5)) {
            x0 = x1;
            x1 = (2.0 * x0) / 3 + a / (3 * x0 * x0);
        }
        System.out.printf("%.5f", x1);
    }
}
