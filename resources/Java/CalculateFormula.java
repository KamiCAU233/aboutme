import java.util.Scanner;

public class CalculateFormula {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        double result = 0;
        for (int i = 1; i <= 4; i++) {
            result += 1.0 / Math.pow(x, i);
        }
        System.out.println(result);
    }
}
