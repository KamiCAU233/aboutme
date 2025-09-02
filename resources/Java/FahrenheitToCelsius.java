import java.util.Scanner;

public class FahrenheitToCelsius {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int f = sc.nextInt();
        double c = 5.0 / 9 * (f - 32);
        System.out.println((int)c);
    }
}
