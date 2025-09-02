import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CollatzConjecture3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        List<Integer> arr = new ArrayList<>();
        while (arr.indexOf(n) == -1) {
            arr.add(n);
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + d;
            }
        }
        int length_of_circle = arr.size() - arr.indexOf(n);
        System.out.println(length_of_circle);
    }
}
