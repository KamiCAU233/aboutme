import java.util.Scanner;

public class CollatzConjecture2 {
    public static int getStepCount(int n) {
        int counter = 0;
        while (n != 1) {
            if (n % 2 == 1) {
                n = 3 * n + 1;
            } else {
                n = n / 2;
            }
            counter++;
        }
        return counter;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = 0;
        while (true) {
            if (sc.hasNextInt()) {
                x = sc.nextInt();
                if (x > 0) {
                    break;
                } else {
                    System.out.println(x + " is not a positive int");
                }
            } else {
                String input = sc.next();
                System.out.println(input + " is not a positive int");
            }
        }
        System.out.println(getStepCount(x) + 1);
    }
}
