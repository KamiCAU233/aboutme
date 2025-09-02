import java.util.Scanner;

public class OneOverFactorial {
    public static int factorial(int x) {
        int result = 1;
        for (int i = 1; i <= x; i++) {
            result *= i;
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        double result = 0;
        for (int i = 1; i <= x; i++) {
            result += 1.0 / factorial(i);
        }
        System.out.printf("%.1f\n", result);
    }
}
