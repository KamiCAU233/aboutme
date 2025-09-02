import java.util.Scanner;

public class MagicSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] matrix = new int[N][N];
        // Dealing with the first number
        int first_index = (N - 1) / 2;
        int current_num = 1;
        matrix[0][first_index] = current_num;
        current_num = 2;
        int now_row = 0;
        int now_column = first_index;
        while (current_num != N * N + 1) {
            // If in the upright corner
            if (now_row == 0 && now_column == N - 1) {
                now_row += 1;
            }
            // If in the first line
            else if (now_row == 0) {
                now_row = N - 1;
                now_column += 1;
            }
            // If in the rightmost column
            else if (now_column == N - 1) {
                now_column = 0;
                now_row -= 1;
            }
            // If already occupied by some number
            else if (matrix[now_row - 1][now_column + 1] != 0) {
                now_row += 1;
            }
            // Not satisfying conditions above
            else {
                now_row -= 1;
                now_column += 1;
            }
            matrix[now_row][now_column] = current_num;
            current_num++;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
