import java.util.Arrays;
import java.util.Scanner;

public class AnnoyingAlgorithm {
    public static int getHighest(int n) {
        while (n >= 10) {
            n /= 10;
        }
        return n;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int start = sc.nextInt();
        int end = sc.nextInt();
        int[] result = new int[40];
        int item = start - getHighest(start);
        result[0] = item;
        int index = 1;
        while (item > end) {
            item = item - getHighest(item);
            result[index] = item;
            index++;
        }
        Arrays.sort(result);
        int count = 0;
        for (int i = 40 - index; i < 40; i++) {
            System.out.print(result[i] + " ");
            count++;
        }
        System.out.println();
        System.out.println(count);
    }
}
