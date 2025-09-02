import java.util.Scanner;

public class WallisPI {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double result = 1;
        for (int i = 1; i <= n; i++) {
            result *= ((4.0 * i * i) / ((2 * i - 1) * (2 * i + 1)));
        }
        result *= 2;
        System.out.printf("%.5f", result);
    }
}
