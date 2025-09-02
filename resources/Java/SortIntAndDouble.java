import java.util.*;

public class SortIntAndDouble {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double[] array_to_sort = new double[6];
        for (int i = 0; i < 6; i++) {
            array_to_sort[i] = sc.nextDouble();
        }
        Arrays.sort(array_to_sort);
        for (int i = 5; i >= 0; i--) {
            if (isInteger(array_to_sort[i])) {
                System.out.printf("%d ", (int)array_to_sort[i]);
            } else {
                System.out.printf("%.1f ", array_to_sort[i]);
            }
        }
    }

    public static boolean isInteger(double x) {
        return (x == (int)x);
    }
}
