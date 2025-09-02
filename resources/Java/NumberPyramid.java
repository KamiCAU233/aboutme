public class NumberPyramid {
    public static void main(String[] args) {
        for (int i = 0; i < 7; i++) {
            int spaces = 6 - i;
            int numbers = i + 1;
            int starting_from = i + 1;
            for (int j = 0; j < spaces; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < numbers; j++) {
                int current_number = starting_from - j;
                System.out.print(current_number);
            }
            for (int j = 0; j < numbers - 1; j++) {
                System.out.print(j + 2);
            }
            System.out.printf("\n");
        }
    }
}
