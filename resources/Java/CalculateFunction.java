import java.util.Scanner;

public class CalculateFunction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        double result = Math.exp(x - 1) * Math.cos(Math.PI / x);
        System.out.printf("%d", (int)result);
    }
}
