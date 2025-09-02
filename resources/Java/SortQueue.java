import java.util.Arrays;
import java.util.Scanner;

public class SortQueue {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int[] list = new int[num];
        for (int i = 0; i < num; i++) {
            list[i] = sc.nextInt();
        }
        Arrays.sort(list);
        System.out.print("Up: ");
        for (int i = 0; i < num; i++) {
            System.out.print(list[i] + " ");
        }
        System.out.print("\nDown: ");
        for (int i = num - 1; i >= 0; i--) {
            System.out.print(list[i] + " ");
        }
    }
}
