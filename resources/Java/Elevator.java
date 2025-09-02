import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Elevator {
    public static int distance(int f1, int f2) {
        Integer[] fs = new Integer[]{-2, -1, 1, 2, 3, 4, 5, 6, 7};
        List<Integer> floor = Arrays.asList(fs);
        return Math.abs(floor.indexOf(f1) - floor.indexOf(f2));
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = sc.nextInt();
        int[] a = new int[count]; // Current floor
        int[] b = new int[count]; // Destination floor
        for (int i = 0; i < count; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        int current_left = 3;
        int current_right = 3;
        for (int i = 0; i < count; i++) {
            if (b[i] < 0 || a[i] < 0) {
                // the left goes to pick the guest up.
                current_left = a[i];
                // the left goes to the destination.
                current_left = b[i];
            } else if (distance(a[i], current_left) < distance(a[i], current_right)) {
                // the left goes to pick the guest up.
                current_left = a[i];
                // the left goes to the destination.
                current_left = b[i];
            } else if (distance(a[i], current_right) < distance(a[i], current_left)) {
                // the right goes to pick the guest up.
                current_right = a[i];
                // the right goes to the destination
                current_right = b[i];
            } else {
                // the left goes to pick the guest up.
                current_left = a[i];
                // the left goes to the destination.
                current_left = b[i];
            }
        }
        System.out.println(current_left + " " + current_right);
    }
}
