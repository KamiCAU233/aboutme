import java.util.Scanner;

public class AssignmentCount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt();
        int N = scanner.nextInt();
        int result = partition(M, N);
        System.out.println(result);
    }
    // M items in total, dividing into N parts at most
    private static int partition(int M, int N) {
        if (M == 1 || M == 0) return 1;
        if (M < 0 || N <= 0) return 0;
        return partition(M, N - 1) + partition(M - N, N);
    }
}
