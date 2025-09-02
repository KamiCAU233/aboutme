import java.util.Scanner;

public class FindPrime {
    public static boolean isPrime(int x) {
        for (int i = 2; i <= Math.sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        for (int i = 2; i <= x; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }
}

