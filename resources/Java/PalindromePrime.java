import java.util.Scanner;

public class PalindromePrime {
    public static boolean isPrime(int x) {
        for (int i = 2; i <= Math.sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static boolean isPalinDrome(int x) {
        String str = Integer.toString(x);
        String reversed = new StringBuilder(str).reverse().toString();
        return str.equals(reversed);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        if (isPrime(x) && isPalinDrome(x)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}
