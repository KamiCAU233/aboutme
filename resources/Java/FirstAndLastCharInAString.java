import java.util.Scanner;

public class FirstAndLastCharInAString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int length = s.length();
        char first_char = s.charAt(0);
        char last_char = s.charAt(length - 1);
        System.out.printf("%d %c %c", length, first_char, last_char);
    }
}
