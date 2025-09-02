import java.util.Scanner;

public class MatrixMultiplication {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[][] matrix1 = new int[m][n];
        int[][] matrix2 = new int[n][t];
        int[][] result = new int[m][t];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix1[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < t; j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < t; j++) {
                for (int p = 0; p < n; p++) {
                    result[i][j] += matrix1[i][p] * matrix2[p][j];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < t; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.print("\n");
        }

    }
}
