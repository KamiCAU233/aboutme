import java.util.Arrays;
import java.util.Scanner;

public class FormTriangle {
    public static boolean formTriangle(int[] arr) {
        boolean qualification = (arr[0] + arr[1] > arr[2]) && (arr[1] + arr[2] > arr[0]) && (arr[0] + arr[2] > arr[1]);
        return qualification;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        for (int i = 0; i < 5; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int result = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    int[] sides = new int[]{arr[i], arr[j], arr[k]};
                    if (formTriangle(sides)) {
                        result++;
                    }
                }
            }
        }
        System.out.println(result);
    }
}
