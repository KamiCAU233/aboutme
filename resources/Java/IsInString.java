import java.util.Scanner;

public class IsInString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        if (s1.contains(s2)) {
            System.out.println('y');
        } else {
            System.out.println('n');
        }
    }
}
