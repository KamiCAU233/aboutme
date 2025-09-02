import java.util.*;

public class CollatzConjecture {
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
        int n = sc.nextInt();
        System.out.println(getStepCount(n));
    }
}
